/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_CONNECTIONS_MEDIUMCONNECTION_HXX
#define _PLANTCALC_CONNECTIONS_MEDIUMCONNECTION_HXX 1

#include "../connection.hxx"

class MediumConnection : public Connection
{
public:
	virtual ~MediumConnection();
};

#endif /*_PLANTCALC_CONNECTIONS_MEDIUMCONNECTION_HXX*/
