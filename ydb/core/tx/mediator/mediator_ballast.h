#pragma once
#include "defs.h"

#include <memory>

namespace NKikimr {
namespace NTxMediator {

// A chunk of useless memory a mediator holds on to, so that a tablet with an
// otherwise tiny footprint may be used to emulate a heavy one.
//
// Merely allocating the memory is not enough: freshly mapped anonymous pages
// are copy-on-write references to the shared zero page, so nothing is really
// committed until something writes to them. TouchSome() does the writing, in
// bounded portions, so that a multi-gigabyte ballast doesn't stall the tablet's
// mailbox in a single go.
class TBallast {
public:
    ui64 GetSize() const {
        return Size;
    }

    ui64 GetTouchedSize() const {
        return Touched;
    }

    bool IsFullyTouched() const {
        return Touched >= Size;
    }

    // Drops the previous ballast and reserves `size` bytes of untouched memory.
    // Returns false when the memory could not be reserved, leaving the ballast
    // empty: a bogus size read back from the local database must not make the
    // tablet die on every boot.
    bool Reset(ui64 size);

    // Writes into at most `maxBytes` of the not yet touched memory, committing
    // the pages behind it. Returns the number of bytes taken.
    ui64 TouchSome(ui64 maxBytes);

private:
    std::unique_ptr<char[]> Data;
    ui64 Size = 0;
    ui64 Touched = 0;
};

}
}
