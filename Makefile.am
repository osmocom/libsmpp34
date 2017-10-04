SUBDIRS = binaries def_frame def_list

if HAVE_LIBXML2
SUBDIRS += test_apps
endif

BUILT_SOURCES = $(top_srcdir)/.version
$(top_srcdir)/.version:
	echo $(VERSION) > $@-t && mv $@-t $@
dist-hook:
	echo $(VERSION) > $(distdir)/.tarball-version

EXTRA_DIST = src/Makefile.am\
             test_pdu/Makefile.am\
             test_apps/Makefile.am \
             test_apps/pack_and_send.inc\
             test_apps/esme.xml\
             test_apps/sendwp.xml\
             test_apps/recv_and_unpack.inc \
             README.md \
             .version

@RELMAKE@

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = libsmpp34.pc
