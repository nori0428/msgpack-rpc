AM_CPPFLAGS   = -I../src
AM_C_CPPFLAGS = -I../src

AM_LDFLAGS = \
                ../src/msgpack/rpc/libmsgpack-rpc.la \
                -lmpio -msgpack

noinst_PROGRAMS = myserver

myserver_SOURCES = myserver.cc
