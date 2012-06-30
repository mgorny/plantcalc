ACLOCAL_AMFLAGS = -I m4

lib_LTLIBRARIES = libplantcalc.la

libplantcalc_la_SOURCES = \
	src/connection.cxx src/connection.hxx \
	src/connections/mediumconnection.cxx src/connections/mediumconnection.hxx \
	src/connections/medium/waterconnection.cxx src/connections/medium/waterconnection.hxx \
	\
	src/pin.cxx src/pin.hxx \
	src/pins/mediumpin.cxx src/pins/mediumpin.hxx \
	\
	src/device.cxx src/device.hxx \
	src/devices/boiler.cxx src/devices/boiler.hxx \
	src/devices/condenser.cxx src/devices/condenser.hxx \
	\
	src/variable.cxx src/variable.hxx \
	src/util/posorunsetdouble.cxx src/util/posorunsetdouble.hxx
libplantcalc_la_LDFLAGS = -version-info 0:0:0

noinst_PROGRAMS = test

test_SOURCES = test.cxx
test_LDADD = libplantcalc.la

EXTRA_DIST = NEWS
NEWS: configure.ac Makefile.am
	git for-each-ref refs/tags --sort '-*committerdate' \
		--format '# %(tag) (%(*committerdate:short))%0a%(contents:body)' \
		> NEWS
