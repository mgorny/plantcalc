ACLOCAL_AMFLAGS = -I m4

lib_LTLIBRARIES = \
	libplantcalc-base.la \
	libplantcalc-solvers.la \
	libplantcalc-powerplant.la \
	libplantcalc.la

libplantcalc_base_la_SOURCES = \
	src/connection.cxx src/connection.hxx \
	src/device.cxx src/device.hxx \
	src/pin.cxx src/pin.hxx \
	src/equation.cxx src/equation.hxx \
	src/equationsolver.cxx src/equationsolver.hxx \
	src/equationsystem.cxx src/equationsystem.hxx \
	src/id.cxx src/id.hxx \
	src/substance.cxx src/substance.hxx \
	src/system.cxx src/system.hxx \
	src/variable.cxx src/variable.hxx \
	\
	src/devices/common/endpoint.hxx src/devices/common/endpoint.ixx \
	src/devices/common/mixingjunction.hxx src/devices/common/mixingjunction.ixx \
	src/devices/common/splittingjunction.hxx src/devices/common/splittingjunction.ixx \
	\
	src/equations/linearequation.cxx src/equations/linearequation.hxx \
	src/equations/equalityequation.cxx src/equations/equalityequation.hxx \
	\
	src/ids/deviceid.cxx src/ids/deviceid.hxx \
	src/ids/pinid.cxx src/ids/pinid.hxx \
	src/ids/variableid.cxx src/ids/variableid.hxx \
	\
	src/variables/constant.cxx src/variables/constant.hxx \
	src/variables/ownedvariable.cxx src/variables/ownedvariable.hxx \
	\
	src/exceptions/contradictionerror.cxx src/exceptions/contradictionerror.hxx \
	src/exceptions/nonhomogeneoussubstanceerror.cxx src/exceptions/nonhomogeneoussubstanceerror.hxx
libplantcalc_base_la_LDFLAGS = -version-info 0:0:0

libplantcalc_solvers_la_SOURCES = \
	src/equationsolvers/autoequationsolver.cxx src/equationsolvers/autoequationsolver.hxx \
	src/equationsolvers/linearequationsolver.cxx src/equationsolvers/linearequationsolver.hxx \
	src/equationsolvers/singleequationsolver.cxx src/equationsolvers/singleequationsolver.hxx
libplantcalc_solvers_la_LDFLAGS = -version-info 0:0:0
libplantcalc_solvers_la_CPPFLAGS = $(EIGEN_CFLAGS)
libplantcalc_solvers_la_LIBADD = libplantcalc-base.la $(EIGEN_LIBS)

libplantcalc_powerplant_la_SOURCES = \
	src/connections/fuelconnection.cxx src/connections/fuelconnection.hxx \
	src/connections/mechanicalenergyconnection.cxx src/connections/mechanicalenergyconnection.hxx \
	src/connections/mediumconnection.cxx src/connections/mediumconnection.hxx \
	\
	src/devices/common/condensingheatexchanger.cxx src/devices/common/condensingheatexchanger.hxx \
	src/devices/common/mediumflowdevice.cxx src/devices/common/mediumflowdevice.hxx \
	src/devices/common/reversibleturbine.cxx src/devices/common/reversibleturbine.hxx \
	src/devices/endpoints/fuelendpoint.cxx src/devices/endpoints/fuelendpoint.hxx \
	src/devices/endpoints/mediumendpoint.cxx src/devices/endpoints/mediumendpoint.hxx \
	src/devices/mixingjunctions/approximatemediummixingjunction.cxx src/devices/mixingjunctions/approximatemediummixingjunction.hxx \
	src/devices/mixingjunctions/mechanicalenergymixingjunction.cxx src/devices/mixingjunctions/mechanicalenergymixingjunction.hxx \
	src/devices/splittingjunctions/mediumsplittingjunction.cxx src/devices/splittingjunctions/mediumsplittingjunction.hxx \
	src/devices/boiler.cxx src/devices/boiler.hxx \
	src/devices/condenser.cxx src/devices/condenser.hxx \
	src/devices/feedwaterheater.cxx src/devices/feedwaterheater.hxx \
	src/devices/pump.cxx src/devices/pump.hxx \
	src/devices/turbine.cxx src/devices/turbine.hxx \
	\
	src/equations/mediumstateequation.cxx src/equations/mediumstateequation.hxx \
	\
	src/pins/fuelpin.cxx src/pins/fuelpin.hxx \
	src/pins/mediumpin.cxx src/pins/mediumpin.hxx \
	src/pins/mechanicalenergypin.cxx src/pins/mechanicalenergypin.hxx \
	\
	src/substances/mediumsubstance.cxx src/substances/mediumsubstance.hxx \
	src/substances/media/h2omedium.cxx src/substances/media/h2omedium.hxx
libplantcalc_powerplant_la_LDFLAGS = -version-info 0:0:0
libplantcalc_powerplant_la_CPPFLAGS = $(LIBH2OXX_CFLAGS)
libplantcalc_powerplant_la_LIBADD = libplantcalc-base.la $(LIBH2OXX_LIBS)

libplantcalc_la_SOURCES =
libplantcalc_la_LDFLAGS = -version-info 0:0:0
libplantcalc_la_LIBADD = \
	libplantcalc-base.la \
	libplantcalc-solvers.la \
	libplantcalc-powerplant.la

noinst_PROGRAMS = test

test_SOURCES = test.cxx
test_CPPFLAGS = $(LIBH2OXX_CFLAGS) $(EIGEN_CFLAGS)
test_LDADD = libplantcalc.la

EXTRA_DIST = NEWS
NEWS: configure.ac Makefile.am
	git for-each-ref refs/tags --sort '-*committerdate' \
		--format '# %(tag) (%(*committerdate:short))%0a%(contents:body)' \
		> NEWS
