#ifdef HAVE_CONFIG_H
#	include <config.h>
#endif

#include "src/devices/boiler.hxx"
#include "src/devices/condenser.hxx"
#include "src/devices/deaerator.hxx"
#include "src/devices/feedwaterheater.hxx"
#include "src/devices/pump.hxx"
#include "src/devices/turbine.hxx"
#include "src/devices/endpoints/fuelendpoint.hxx"
#include "src/devices/endpoints/mechanicalenergyendpoint.hxx"
#include "src/devices/endpoints/mediumendpoint.hxx"
#include "src/devices/splittingjunctions/fuelsplittingjunction.hxx"
#include "src/devices/splittingjunctions/mediumsplittingjunction.hxx"
#include "src/devices/mixingjunctions/mechanicalenergymixingjunction.hxx"
#include "src/devices/mixingjunctions/approximatemediummixingjunction.hxx"
#include "src/equationsystem.hxx"
#include "src/system.hxx"

#include "src/connections/fuelconnection.hxx"
#include "src/connections/mechanicalenergyconnection.hxx"
#include "src/connections/mediumconnection.hxx"
#include "src/equationsolvers/autoequationsolver.hxx"
#include "src/substances/media/h2omedium.hxx"

#include "src/exceptions/contradictionerror.hxx"

#include <vector>
#include <iostream>
#include <fstream>
#include <stdexcept>

int main()
{
	System plant;

	H2OMedium woda;

	// obieg pierwotny
	Boiler K1(.9, 10.2, 811.15); plant.push_back(K1);
	Boiler K2(.9, 2.35, 811.15); plant.push_back(K2);
	Turbine T11(.9, .99, 2.56); plant.push_back(T11);
	Turbine T12(.9, .99, 2.35); plant.push_back(T12);
	Turbine T21(.9, .99, 1.37); plant.push_back(T21);
	Turbine T22(.9, .99, 0.45); plant.push_back(T22);
	Turbine T23(.9, .99, 0.20); plant.push_back(T23);
	Turbine T24(.9, .99, 0.07); plant.push_back(T24);
	Turbine T25(.9, .99, 0.0035); plant.push_back(T25);
	Condenser Sk(10); plant.push_back(Sk);

	FeedwaterHeater R24(5), R23(5), R21(5), R11(5);
	plant.push_back(R24); plant.push_back(R23);
	plant.push_back(R21); plant.push_back(R11);

	Deaerator R22; plant.push_back(R22);

	Pump PSk(.9, .99), P22(.9, .99);
	plant.push_back(PSk); plant.push_back(P22);

	// połączenia i rozgałęzienia
	MediumConnection K1_T11(K1.out(), T11.in()); plant.push_back(K1_T11);

	MediumSplittingJunction T11r; plant.push_back(T11r);
	MediumConnection T11_T11r(T11.out(), T11r.in()); plant.push_back(T11_T11r);
	MediumConnection T11r_R11(T11r.out2(), R11.in()); plant.push_back(T11r_R11);
	MediumConnection T11r_T12(T11r.out1(), T12.in()); plant.push_back(T11r_T12);

	MediumConnection T12_K2(T12.out(), K2.in()); plant.push_back(T12_K2);
	MediumConnection K2_T21(K2.out(), T21.in()); plant.push_back(K2_T21);

	MediumSplittingJunction T21r; plant.push_back(T21r);
	MediumConnection T21_T21r(T21.out(), T21r.in()); plant.push_back(T21_T21r);
	MediumConnection T21r_R21(T21r.out2(), R21.in()); plant.push_back(T21r_R21);
	MediumConnection T21r_T22(T21r.out1(), T22.in()); plant.push_back(T21r_T22);

	MediumSplittingJunction T22r; plant.push_back(T22r);
	MediumConnection T22_T22r(T22.out(), T22r.in()); plant.push_back(T22_T22r);
	MediumConnection T22r_R22(T22r.out2(), R22.in()); plant.push_back(T22r_R22);
	MediumConnection T22r_T23(T22r.out1(), T23.in()); plant.push_back(T22r_T23);

	MediumSplittingJunction T23r; plant.push_back(T23r);
	MediumConnection T23_T23r(T23.out(), T23r.in()); plant.push_back(T23_T23r);
	MediumConnection T23r_R23(T23r.out2(), R23.in()); plant.push_back(T23r_R23);
	MediumConnection T23r_T24(T23r.out1(), T24.in()); plant.push_back(T23r_T24);

	MediumSplittingJunction T24r; plant.push_back(T24r);
	MediumConnection T24_T24r(T24.out(), T24r.in()); plant.push_back(T24_T24r);
	MediumConnection T24r_R24(T24r.out2(), R24.in()); plant.push_back(T24r_R24);
	MediumConnection T24r_T25(T24r.out1(), T25.in()); plant.push_back(T24r_T25);

	MediumConnection T25_Sk(T25.out(), Sk.in()); plant.push_back(T25_Sk);

	ApproximateMediumMixingJunction Skm; plant.push_back(Skm);
	MediumConnection Sk_Skm(Sk.out(), Skm.in1()); plant.push_back(Sk_Skm);
	MediumConnection Skm_PSk(Skm.out(), PSk.in()); plant.push_back(Skm_PSk);
	MediumConnection PSk_R24(PSk.out(), R24.sec_in()); plant.push_back(PSk_R24);

	ApproximateMediumMixingJunction R24m; plant.push_back(R24m);
	MediumConnection R24_R24m(R24.out(), R24m.in1()); plant.push_back(R24_R24m);
	MediumConnection R23_R24m(R23.out(), R24m.in2()); plant.push_back(R23_R24m);
	MediumConnection R24m_Skm(R24m.out(), Skm.in2()); plant.push_back(R24m_Skm);

	MediumConnection R24_R23(R24.sec_out(), R23.sec_in()); plant.push_back(R24_R23);
	MediumConnection R23_R22(R23.sec_out(), R22.sec_in()); plant.push_back(R23_R22);

	// odgazowywacz
	ApproximateMediumMixingJunction R22m; plant.push_back(R22m);
	MediumConnection R22_R22m(R22.out(), R22m.in1()); plant.push_back(R22_R22m);

	MediumConnection R22m_P22(R22m.out(), P22.in()); plant.push_back(R22m_P22);
	MediumConnection P22_R21(P22.out(), R21.sec_in()); plant.push_back(P22_R21);
	MediumConnection R21_R11(R21.sec_out(), R11.sec_in()); plant.push_back(R21_R11);
	MediumConnection R11_K1(R11.sec_out(), K1.in()); plant.push_back(R11_K1);

	ApproximateMediumMixingJunction R21m; plant.push_back(R21m);
	MediumConnection R21_R21m(R21.out(), R21m.in1()); plant.push_back(R21_R21m);
	MediumConnection R11_R21m(R11.out(), R21m.in2()); plant.push_back(R11_R21m);
	MediumConnection R21m_R22m(R21m.out(), R22m.in2()); plant.push_back(R21m_R22m);

	K1_T11.substance(&woda);

	// obieg wtórny skraplacza
	MediumEndpoint SkI(.1, 283.15), SkII(.1);
	plant.push_back(SkI); plant.push_back(SkII);

	MediumConnection SkIp(SkI, Sk.sec_in()); plant.push_back(SkIp);
	MediumConnection SkIIp(Sk.sec_out(), SkII); plant.push_back(SkIIp);

	SkIp.substance(&woda);

	// zasilanie paliwem
	FuelEndpoint K12p; plant.push_back(K12p);
	FuelSplittingJunction K12; plant.push_back(K12);

	FuelConnection K12p_K12(K12p, K12.in()); plant.push_back(K12p_K12);
	FuelConnection K12_K1(K12.out1(), K1.fuel_in()); plant.push_back(K12_K1);
	FuelConnection K12_K2(K12.out2(), K2.fuel_in()); plant.push_back(K12_K2);

	K12.in().Qw().set_value(22000);

	// wyprowadzenie mocy
	MechanicalEnergyMixingJunction T12e; plant.push_back(T12e);
	MechanicalEnergyConnection T11_T12e(T11.energy_pin(), T12e.in1()); plant.push_back(T11_T12e);
	MechanicalEnergyConnection T12_T12e(T12.energy_pin(), T12e.in2()); plant.push_back(T12_T12e);

	MechanicalEnergyMixingJunction T21e; plant.push_back(T21e);
	MechanicalEnergyConnection T12e_T21e(T12e.out(), T21e.in1()); plant.push_back(T12e_T21e);
	MechanicalEnergyConnection T21_T21e(T21.energy_pin(), T21e.in2()); plant.push_back(T21_T21e);

	MechanicalEnergyMixingJunction T22e; plant.push_back(T22e);
	MechanicalEnergyConnection T21e_T22e(T21e.out(), T22e.in1()); plant.push_back(T21e_T22e);
	MechanicalEnergyConnection T22_T22e(T22.energy_pin(), T22e.in2()); plant.push_back(T22_T22e);

	MechanicalEnergyMixingJunction T23e; plant.push_back(T23e);
	MechanicalEnergyConnection T22e_T23e(T22e.out(), T23e.in1()); plant.push_back(T22e_T23e);
	MechanicalEnergyConnection T23_T23e(T23.energy_pin(), T23e.in2()); plant.push_back(T23_T23e);

	MechanicalEnergyMixingJunction T24e; plant.push_back(T24e);
	MechanicalEnergyConnection T23e_T24e(T23e.out(), T24e.in1()); plant.push_back(T23e_T24e);
	MechanicalEnergyConnection T24_T24e(T24.energy_pin(), T24e.in2()); plant.push_back(T24_T24e);

	MechanicalEnergyMixingJunction T25e; plant.push_back(T25e);
	MechanicalEnergyConnection T24e_T25e(T24e.out(), T25e.in1()); plant.push_back(T24e_T25e);
	MechanicalEnergyConnection T25_T25e(T25.energy_pin(), T25e.in2()); plant.push_back(T25_T25e);

	MechanicalEnergyMixingJunction Pe; plant.push_back(Pe);
	MechanicalEnergyConnection PSk_Pe(PSk.energy_pin(), Pe.in1()); plant.push_back(PSk_Pe);
	MechanicalEnergyConnection P22_Pe(P22.energy_pin(), Pe.in2()); plant.push_back(P22_Pe);

	MechanicalEnergyMixingJunction Gene; plant.push_back(Gene);
	MechanicalEnergyConnection T25e_Gene(T25e.out(), Gene.in1()); plant.push_back(T25e_Gene);
	MechanicalEnergyConnection Pe_Gene(Pe.out(), Gene.in2()); plant.push_back(Pe_Gene);

	MechanicalEnergyEndpoint Gen; plant.push_back(Gen);
	MechanicalEnergyConnection Gene_Gen(Gene.out(), Gen); plant.push_back(Gene_Gen);

	Gene.out().P().set_value(90115);

	plant.flatten();
	plant.set_device_ids();
	plant.set_substances();

	EquationSystem eqs = plant.equations();

	AutoEquationSolver solv(eqs);

	try
	{
		while (solv.iterate())
			std::cout << eqs << std::endl;
	}
	catch (ContradictionError& e)
	{
		std::cout << eqs << std::endl;
		throw;
	}
	catch (std::range_error& e)
	{
		std::cout << eqs << std::endl;
		throw;
	}

	std::cout << eqs << std::endl;

	std::ofstream graph_file("out.dot");
	graph_file << plant.graph();

	std::cout << plant.connections() << std::endl;

	return 0;
}
