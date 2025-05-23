# Generated by devtools/yamaker.

LIBRARY()

LICENSE(
    Apache-2.0 AND
    Public-Domain
)

LICENSE_TEXTS(.yandex_meta/licenses.list.txt)

VERSION(20240722.1)

PEERDIR(
    contrib/restricted/abseil-cpp-tstring/y_absl/base
    contrib/restricted/abseil-cpp-tstring/y_absl/numeric
    contrib/restricted/abseil-cpp-tstring/y_absl/strings
)

ADDINCL(
    GLOBAL contrib/restricted/abseil-cpp-tstring
)

IF (OS_DARWIN OR OS_IOS)
    EXTRALIBS("-framework CoreFoundation")
ENDIF()

NO_COMPILER_WARNINGS()

SRCS(
    civil_time.cc
    clock.cc
    duration.cc
    format.cc
    internal/cctz/src/civil_time_detail.cc
    internal/cctz/src/time_zone_fixed.cc
    internal/cctz/src/time_zone_format.cc
    internal/cctz/src/time_zone_if.cc
    internal/cctz/src/time_zone_impl.cc
    internal/cctz/src/time_zone_info.cc
    internal/cctz/src/time_zone_libc.cc
    internal/cctz/src/time_zone_lookup.cc
    internal/cctz/src/time_zone_posix.cc
    internal/cctz/src/zone_info_source.cc
    time.cc
)

END()
