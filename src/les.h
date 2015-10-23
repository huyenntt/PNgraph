/*
 * les.h
 *
 *  Created on: 22 oct. 2015
 *      Author: tnguyen
 */
#ifndef LES_H_
#define LES_H_
#include "pnapi.h"
#include "configuration.h"
#include "event.h"

namespace pngraph
{
class LES
{
	PetriNet n_;
	std::set<Event> events;
	std::stack<Event> ext; // set of extendable events in constructing LES process
	std::set<Transition *, Transition *> idt; //set of pairs of independent transitions


public:
	LES();
	void buildRelation(); // set up the independent relation
	void constructUnf();
	std::set< Event *> compute_ex(Config C);
	Config find_alt(const Config & C, const std::set<Event *> & D); // find a possible alternation to D, after C
	void explore(const Config & C,std::set<Event *> A );
	void extend(Event &);
	std::set<Event *> findExtension(const Config & C);
	std::set<Event *> findEnable(const Config & C);
	void remove(Event & e);
	bool check_commute(const Transition &, const Transition &);
	void add(Event);


}; // end of class LES
} // end of namespace pngraph
#endif /* LES_H_ */
