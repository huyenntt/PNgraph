/*
 * configuration.cc
 *
 *  Created on: 22 oct. 2015
 *      Author: tnguyen
 */
#include "event.h"
#include "configuration.h"

using namespace pnapi;

namespace pngraph
{
/*
 * compute the marking corresponding to the configuration
 */
Marking Config::computeState()
{
	Marking st;
	std::vector<Event *>::iterator it;
	st=(*it)->getState();
	for (it=evt.begin()+1; it !=evt.end(); ++it)
	{
		Transition & t = (*it)->getlabel();
		st=st.getSuccessor(t);
	}
	return st;
}

/*
 * add an event to a configuration
 */
Config Config::add(Event & e)
{
	e.setVisited(true); //?????? xem xet
}
/*
 * Copy constructor
 */
Config::Config(const Config & c)
{

}

/*
 * Overlap the assignment operator
 */
Config & Config::operator=(const Config & m)
{
  return *new Config(m);// *new (this) Marking(m);
}


}// end of namespace
