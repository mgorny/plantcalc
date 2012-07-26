/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_CONNECTION_HXX
#define _PLANTCALC_CONNECTION_HXX 1

#include "equationsystem.hxx"
#include "pin.hxx"
#include "substance.hxx"

/**
 * A logical connection between two pins (devices).
 *
 * The Connection class establishes a logical linking between two pins,
 * and effectively the devices owning them.
 *
 * The endpoints of a connection can be obtained using from() and to()
 * methods. In the base Connection class, these are upcasted to the Pin
 * class. In the derived classes, a more specific return types are used.
 *
 * The properties of the medium in the connection can be obtained using
 * the variables in the source pin (from() method). This ensures that
 * the flux value will be positive if the flow is directed forward.
 *
 * Each connection provides a number of equations, expressing
 * the correlations between particular source and destination pin
 * variables. In particular, connection usually expresses the equality
 * of the properties on both endpoints, and correlations between them.
 * The equations can be obtained using the equations() method.
 *
 * A particular connection type may support specifying substances.
 * In that case, the substance() method can be used to obtain
 * a pointer to the particular Substance instance used
 * by the connection, or bind it to one.
 *
 * If the connection supports substance, it has an additional equation
 * representing substance state parameter correlations. If the substance
 * is set, it is used to solve that equation. Otherwise, the equation is
 * removed without solving (and relevant state parameters need to be
 * determined another way).
 *
 * It is required that in all interlinked connections the substance is
 * set consistently or not set at all; that can be enforced using
 * System::set_substances() method.
 *
 * Setting any substance on a connection type not supporting substances
 * is not allowed.
 */
class Connection
{
public:
	virtual ~Connection();

	/**
	 * Obtain the source pin the connections is bound to.
	 */
	virtual Pin& from() = 0;
	/**
	 * Obtain the destination pin the connections is bound to.
	 */
	virtual Pin& to() = 0;

	/**
	 * Obtain the current Substance instance for the connection.
	 *
	 * @returns A pointer to Substance instance, or @c NULL if none.
	 */
	virtual Substance* substance();
	/**
	 * Set (or unset) the Substance instance for the connection.
	 *
	 * Note that the Connection will not own the class pointed by
	 * @a new_subst. The caller should own it, and ensure its
	 * destruction.
	 *
	 * @param[in] new_subst A pointer to new Substance instance,
	 * or @c NULL to unset.
	 */
	virtual void substance(Substance* new_subst);

	/**
	 * Obtain the equations expressing the correlations between
	 * properties of the interlinked pins.
	 *
	 * The equations referenced in the returned system are owned
	 * by the Connection class and must not be freed. The variables
	 * referenced in them are similarly owned by the respective pins
	 * or are statically allocated, and must not be freed.
	 *
	 * The returned connection list may differ depending on the current
	 * substance. Other than that, any successive call to equations()
	 * must return the same equation set. The list will not contain
	 * any @c NULL pointers.
	 */
	virtual EquationSystem equations() = 0;
};

#endif /*_PLANTCALC_CONNECTION_HXX*/
