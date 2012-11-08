# test_pdu/Makefile.am #

TESTAPPS_SOURCE_DIR = $(top_srcdir)/test_apps
sendwp_SOURCES = \
    $(TESTAPPS_SOURCE_DIR)/tcp.c\
    $(TESTAPPS_SOURCE_DIR)/smpp.c\
    $(TESTAPPS_SOURCE_DIR)/sendwp.h\
    $(TESTAPPS_SOURCE_DIR)/sendwp.c

sendwp_CPPFLAGS = `xml2-config --cflags`
sendwp_LDFLAGS = `xml2-config --libs`

noinst_DATA = \
     $(TESTAPPS_SOURCE_DIR)/sendwp.xml \
     $(TESTAPPS_SOURCE_DIR)/esme.xml

esme_SOURCES = \
    $(TESTAPPS_SOURCE_DIR)/tcp.c\
    $(TESTAPPS_SOURCE_DIR)/smpp.c\
    $(TESTAPPS_SOURCE_DIR)/esme.h\
    $(TESTAPPS_SOURCE_DIR)/esme.c

esme_CPPFLAGS = `xml2-config --cflags`
esme_LDFLAGS = `xml2-config --libs`

analizer_SOURCES = \
    $(TESTAPPS_SOURCE_DIR)/analizer.c

analizer_CPPFLAGS = 
analizer_LDFLAGS = 

smsc_CPPFLAGS = `pkg-config --cflags libosmocore`
smsc_LDFLAGS = `pkg-config --libs libosmocore`
smsc_SOURCES = $(TESTAPPS_SOURCE_DIR)/smpp_smsc.c $(TESTAPPS_SOURCE_DIR)/smsc_main.c
