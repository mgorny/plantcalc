/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "feedwaterheater2.hxx"

FeedwaterHeater2::FeedwaterHeater2(const char* name)
	: CondensingHeatExchanger2(name),
	_DeltaTL(_device_id, "DeltaTL"),
	_DeltaTL_equation(1.0, _sec_out.T(),
			1.0, _DeltaTL,
			-1.0, _out.T())
{
}

FeedwaterHeater2::FeedwaterHeater2(const char* name, double DeltaTL)
	: CondensingHeatExchanger2(name),
	_DeltaTL(_device_id, "DeltaTL", DeltaTL),
	_DeltaTL_equation(1.0, _sec_out.T(),
			1.0, _DeltaTL,
			-1.0, _out.T())
{
}

FeedwaterHeater2::variable_list_type FeedwaterHeater2::variables()
{
	variable_list_type ret;

	ret.push_back(&_DeltaTL);

	return ret;
}

Variable& FeedwaterHeater2::DeltaTL()
{
	return _DeltaTL;
}

EquationSystem FeedwaterHeater2::equations()
{
	EquationSystem ret = CondensingHeatExchanger2::equations();

	ret.push_back(&_DeltaTL_equation);

	return ret;
}
