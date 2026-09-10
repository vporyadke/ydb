#include "mediator_ballast.h"

#include <util/generic/utility.h>

#include <cstring>
#include <new>

namespace NKikimr {
namespace NTxMediator {

namespace {

    // Every page gets pseudo-random content, so that pages differ both from the
    // shared zero page and from each other. Otherwise the kernel (KSM) or a
    // hypervisor might dedup or compress the ballast away behind our back, and
    // the tablet would look much lighter than it was asked to be.
    ui64 NextPattern(ui64 &state) {
        state ^= state << 13;
        state ^= state >> 7;
        state ^= state << 17;
        return state;
    }

}

bool TBallast::Reset(ui64 size) {
    // Release the previous ballast before asking for the new one, so that the
    // two are never held at the same time.
    Data.reset();
    Size = 0;
    Touched = 0;

    if (size == 0) {
        return true;
    }

    Data.reset(new (std::nothrow) char[size]);
    if (!Data) {
        return false;
    }

    Size = size;
    return true;
}

ui64 TBallast::TouchSome(ui64 maxBytes) {
    const ui64 count = Min(Size - Touched, maxBytes);
    char* const begin = Data.get() + Touched;

    // Non-zero seed that varies along the buffer, so the content is stable for
    // a given offset and never repeats between chunks.
    ui64 state = Touched | 1;

    ui64 offset = 0;
    for (; offset + sizeof(ui64) <= count; offset += sizeof(ui64)) {
        const ui64 pattern = NextPattern(state);
        std::memcpy(begin + offset, &pattern, sizeof(pattern));
    }
    for (; offset < count; ++offset) {
        begin[offset] = static_cast<char>(NextPattern(state));
    }

    Touched += count;
    return count;
}

}
}
