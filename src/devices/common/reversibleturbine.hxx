/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_DEVICES_REVERSIBLETURBINE_HXX
#define _PLANTCALC_DEVICES_REVERSIBLETURBINE_HXX 1

#include "mediumflowdevice.hxx"
#include "../../pins/mechanicalenergypin.hxx"
#include "../../pins/mediumpin.hxx"
#include "../../equations/additiveinverseequation.hxx"
#include "../../equations/equalityequation.hxx"
#include "../../equations/linearequation.hxx"
#include "../../variables/ownedvariable.hxx"

/**
 * A simple reversible turbine (pump, compressor) model.
 *
 * The ReversibleTurbine provides a base class for devices which convert
 * medium energy into mechanical energy through decompression,
 * or the other way.
 *
 * The following equation describes the heat exchange:
 *
 * @f[
 * D ( h_{in} - h_{out} ) = P \eta_m
 * @f]
 *
 * where @f$ D @f$ is the medium flux, @f$ h_{in} - h_{out} @f$ is
 * the difference between specific enthalpy of inlet and outlet
 * medium, @f$ P @f$ is the mechanical power and @f$ \eta_m @f$
 * is the mechanical efficiency.
 *
 * The mathematical model requires an abstract loop being connected
 * (loop_out() to loop_in()) in order to be able to perform real
 * expansion calculations. The 'ideal' output parameters will be set
 * in the loop.
 *
 * The real output enthalpy is calculated using the following equation:
 *
 * @f[
 * h_{out} = ( 1 - \eta_h ) h_{in} + \eta_h h_{ideal}
 * @f]
 *
 * with @f$ \eta_h @f$ being the isenthropic efficiency,
 * and @f$ h_{ideal} @f$ being the 'ideal' specific enthalpy obtained
 * in the loop.
 */
class ReversibleTurbine : public MediumFlowDevice
{
	OwnedVariable _isenthropic_efficiency;
	OwnedVariable _one_minus_isenthropic_efficiency;

	OwnedVariable _mechanical_efficiency;
	OwnedVariable _mechanical_efficiency_reciprocal;

	MediumPin _loop_in, _loop_out;
	MechanicalEnergyPin _energy_pin;

	LinearEquation _one_minus_isen_eff_eq;
	LinearEquation _mech_eff_reciprocal_eq;

	AdditiveInverseEquation _loop_mass_eq;
	AdditiveInverseEquation _loop_mass_balance_eq;
	EqualityEquation _loop_pressure_eq;
	EqualityEquation _ideal_expansion_eq;
	LinearEquation _real_expansion_eq;
	LinearEquation _energy_balance_eq;

protected:
	/**
	 * Instantiate a new ReversibleTurbine.
	 *
	 * @param[in] name A short name for the device.
	 * @param[in] isenthropic_efficiency Initial isenthropic efficiency
	 * value.
	 * @param[in] mechanical_efficiency Initial mechanical efficiency value.
	 */
	ReversibleTurbine(const char* name,
			double isenthropic_efficiency,
			double mechanical_efficiency);
	/**
	 * Instantiate a new ReversibleTurbine and set the output pressure.
	 *
	 * @param[in] name A short name for the device.
	 * @param[in] isenthropic_efficiency Initial isenthropic efficiency
	 * value.
	 * @param[in] mechanical_efficiency Initial mechanical efficiency value.
	 * @param[in] pout Initial output pressure [MPa].
	 */
	ReversibleTurbine(const char* name,
			double isenthropic_efficiency,
			double mechanical_efficiency,
			double pout);

public:
	/**
	 * The isenthropic efficiency.
	 *
	 * The isenthropic efficiency is used to calculate the real
	 * output parameters.
	 */
	Variable& isenthropic_efficiency();
	/**
	 * The mechanical effiency.
	 *
	 * The mechanical efficiency is used to calculate the amount
	 * of mechanical energy obtained or consumed by the device.
	 */
	Variable& mechanical_efficiency();

	/**
	 * Output pin of the internal loop used to calculate real expansion
	 * parameters.
	 *
	 * Must be connected to loop_in().
	 */
	MediumPin& loop_out();
	/**
	 * Input pin of the internal loop used to calculate real expansion
	 * parameters.
	 *
	 * Must be connected to loop_out().
	 */
	MediumPin& loop_in();

	/**
	 * The energy output pin.
	 */
	MechanicalEnergyPin& energy_pin();

	virtual bool pins_connected(const Pin& lhs, const Pin& rhs) const;
	virtual EquationSystem equations();

	virtual pin_list_type pins();
	virtual variable_list_type variables();
};

#endif /*_PLANTCALC_DEVICES_REVERSIBLETURBINE_HXX*/
