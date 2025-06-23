# This is _NOT_ the library release version, it's an API version.
# Please read Chapter 6 "Library interface versions" of the libtool documentation before making any modification
LIBVERSION=3:1:2

# src/Makefile.am #
lib_LTLIBRARIES = libsmpp34.la

LIBRARY_SOURCE_DIR = $(top_srcdir)/src
libsmpp34_la_SOURCES = \
    $(LIBRARY_SOURCE_DIR)/smpp34.h \
    $(LIBRARY_SOURCE_DIR)/smpp34_dumpBuf.c \
    $(LIBRARY_SOURCE_DIR)/smpp34_dumpPdu.c \
    $(LIBRARY_SOURCE_DIR)/smpp34_heap.c \
    $(LIBRARY_SOURCE_DIR)/smpp34_pack.c \
    $(LIBRARY_SOURCE_DIR)/smpp34_unpack.c \
    $(LIBRARY_SOURCE_DIR)/smpp34_structs.c \
    $(LIBRARY_SOURCE_DIR)/smpp34_structs.h \
    $(LIBRARY_SOURCE_DIR)/smpp34_params.c \
    $(LIBRARY_SOURCE_DIR)/smpp34_params.h

smpp34_version.h: $(LIBRARY_SOURCE_DIR)/smpp34_version.h.tpl
	$(AM_V_GEN)sed \
		-e "s/{{VERSION}}/$$(echo '@VERSION@' | cut -d. -f1-3)/g" \
		-e "s/{{VERSION_MAJOR}}/$$(echo '@VERSION@' | cut -d. -f1)/g" \
		-e "s/{{VERSION_MINOR}}/$$(echo '@VERSION@' | cut -d. -f2)/g" \
		-e "s/{{VERSION_PATCH}}/$$(echo '@VERSION@' | cut -d. -f3)/g" \
		$< > $@

EXTRA_DIST = \
	$(LIBRARY_SOURCE_DIR)/smpp34_version.h.tpl \
	$(NULL)

include_HEADERS = \
    $(LIBRARY_SOURCE_DIR)/smpp34.h \
    $(LIBRARY_SOURCE_DIR)/smpp34_heap.h \
    $(LIBRARY_SOURCE_DIR)/smpp34_structs.h \
    $(LIBRARY_SOURCE_DIR)/smpp34_params.h \
    smpp34_version.h \
    $(NULL)

libsmpp34_la_CFLAGS = @CFLAGS@ -Wall
libsmpp34_la_CFLAGS += -D_REENTRANT -DBSD_COMP -D_POSIX_PTHREAD_SEMANTICS
libsmpp34_la_INCLUDES = -I. -I..
libsmpp34_la_LDFLAGS = @LDFLAGS@ -version-info $(LIBVERSION) -no-undefined
libsmpp34_la_LDFLAGS += -lrt -lpthread
