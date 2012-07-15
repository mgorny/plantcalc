/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_DEVICES_CONDENSER_HXX
#define _PLANTCALC_DEVICES_CONDENSER_HXX 1

#include "common/condensingheatexchanger.hxx"

class Condenser : public CondensingHeatExchanger
{
public:
	Condenser();
};

#endif /*_PLANTCALC_DEVICES_CONDENSER_HXX*/
