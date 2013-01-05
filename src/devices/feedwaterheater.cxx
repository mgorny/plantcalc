/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "feedwaterheater.hxx"

FeedwaterHeater::FeedwaterHeater(const char* name)
	: CondensingHeatExchanger(name),
	_DeltaTL(_device_id, "DeltaTL"),
	_DeltaTL_equation(1.0, _sec_out.T(),
			1.0, _DeltaTL,
			-1.0, _out.T())
{
}

FeedwaterHeater::FeedwaterHeater(const char* name, double DeltaTL)
	: CondensingHeatExchanger(name),
	_DeltaTL(_device_id, "DeltaTL", DeltaTL),
	_DeltaTL_equation(1.0, _sec_out.T(),
			1.0, _DeltaTL,
			-1.0, _out.T())
{
}

FeedwaterHeater::variable_list_type FeedwaterHeater::variables()
{
	variable_list_type ret;

	ret.push_back(&_DeltaTL);

	return ret;
}

Variable& FeedwaterHeater::DeltaTL()
{
	return _DeltaTL;
}

EquationSystem FeedwaterHeater::equations()
{
	EquationSystem ret = CondensingHeatExchanger::equations();

	ret.push_back(&_DeltaTL_equation);

	return ret;
}
