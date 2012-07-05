ACLOCAL_AMFLAGS = -I m4

lib_LTLIBRARIES = libplantcalc.la

libplantcalc_la_SOURCES = \
	src/connection.cxx src/connection.hxx \
	src/connections/mediumconnection.cxx src/connections/mediumconnection.hxx \
	src/connections/medium/waterconnection.cxx src/connections/medium/waterconnection.hxx \
	\
	src/pin.cxx src/pin.hxx \
	src/pins/mediumpin.cxx src/pins/mediumpin.hxx \
	src/pins/mechanicalenergypin.cxx src/pins/mechanicalenergypin.hxx \
	\
	src/device.cxx src/device.hxx \
	src/devices/mediumflowdevice.cxx src/devices/mediumflowdevice.hxx \
	src/devices/boiler.cxx src/devices/boiler.hxx \
	src/devices/condenser.cxx src/devices/condenser.hxx \
	src/devices/turbine.cxx src/devices/turbine.hxx \
	\
	src/equation.cxx src/equation.hxx \
	src/equations/linearequation.cxx src/equations/linearequation.hxx \
	src/equations/equalityequation.cxx src/equations/equalityequation.hxx \
	src/equations/waterstateequation.cxx src/equations/waterstateequation.hxx \
	\
	src/equationsolver.cxx src/equationsolver.hxx \
	src/equationsolvers/determinateequationsolver.cxx src/equationsolvers/determinateequationsolver.hxx \
	src/equationsolvers/linearequationsolver.cxx src/equationsolvers/linearequationsolver.hxx \
	\
	src/equationsystem.cxx src/equationsystem.hxx \
	src/variable.cxx src/variable.hxx \
	src/util/sequentialnumbersource.cxx src/util/sequentialnumbersource.hxx \
	\
	src/ids/deviceid.cxx src/ids/deviceid.hxx \
	src/ids/pinid.cxx src/ids/pinid.hxx \
	\
	src/exceptions/contradictionerror.cxx src/exceptions/contradictionerror.hxx
libplantcalc_la_LDFLAGS = -version-info 0:0:0
libplantcalc_la_CPPFLAGS = $(LIBH2OXX_CFLAGS) $(EIGEN_CFLAGS)
libplantcalc_la_LIBADD = $(LIBH2OXX_LIBS) $(EIGEN_LIBS)

noinst_PROGRAMS = test

test_SOURCES = test.cxx
test_LDADD = libplantcalc.la

EXTRA_DIST = NEWS
NEWS: configure.ac Makefile.am
	git for-each-ref refs/tags --sort '-*committerdate' \
		--format '# %(tag) (%(*committerdate:short))%0a%(contents:body)' \
		> NEWS
