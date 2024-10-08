PY23_LIBRARY()

VERSION(Service-proxy-version)

LICENSE(Public-Domain)

LICENSE_TEXTS(.yandex_meta/licenses.list.txt)

WITHOUT_LICENSE_TEXTS()

SUBSCRIBER(g:yatool)

NO_LINT()

# Minimal set of the files required to support coverage (DEVTOOLS-4095)
PY_SRCS(
    __init__.py
    Coverage.py
    Shadow.py
    Utils.py
)

PEERDIR(
    contrib/python/six
    library/python/resource
)

END()
