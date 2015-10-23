/*
 * configuration.h
 *
 *  Created on: 22 oct. 2015
 *      Author: tnguyen
 */
#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_
#include "pnapi/pnapi.h"

namespace pngraph
{
class Event;

class Config
{
	std::vector <Event* > evt;

public:
	Config(){evt.clear();}
	Config(const Config & c);
	Marking computeState();
	bool is_inConfig(Event e); // check if e is in the configuration
	std::vector<Event *> getEvents(){return evt;}
	Config add(Event & e);
	Config & Config::operator=(const Config & m);


};
} // end of namespace pngraph


#endif /* CONFIGURATION_H_ */
