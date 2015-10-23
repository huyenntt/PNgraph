/*
 * event.cc
 *
 *  Created on: 12 oct. 2015
 *      Author: tnguyen
 */

#include "event.h"

namespace pngraph
{
/*!
 * check if 2 transitions is commutative or not
 */
bool Event::check_commute(const Transition &, const Transition &)
{
	return false;
}
/*
 * compute the state correspoding to the event
 */
void Event::setState(const Marking & m)
{
	state=m;
}

/*
 * Constructor with 2 arguments
 */
Event::Event(Transition t, Config c)
{
	lbl=t;
	his=c;
}
/*
 * Check if transition labeling an event is independent to another transition
 */
bool Event::is_depend(Transtion & t)
{
	if find(this->lbl,t) in set of independent transitions
}

void Event::addToHistory(Event & e)
{
	his.add(e);
}

} // end of namespace


