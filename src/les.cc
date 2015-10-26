/*
 * les.cc
 *      Author: tnguyen
 */
#include "les.h"

using namespace pnapi;

namespace pngraph
{

LES::LES()
{
	events.clear();
}

/*!
 *  this function find all pairs of transitions which are independent
 */
void LES::buildRelation()
{

}

/*
 * Construct the unfolding
 */
void LES::constructUnf()
{
	Marking mark(n_,false);
	Config c;
	Event * e;
	if (events.empty()==false)
	{
		e = events.end()-1; //the latest member of the LES
		mark= e->getState();
	}

	std::set<Transition *> trans = n_.getTransitions();
	std::set<Transition *>::iterator it;
	for (it=trans.begin(); it!=trans.end(); ++it)
	{
		if (mark.activates(**it))
		{
			if (e->is_depend(**it)==true)
			{
				mark=mark.getSuccessor(**it);
				Event temp(*it);
				temp.setState(mark);
				temp.addToHistory(e);
				ext.push(temp);
			}
			else
			{
				std::set<Event>::iterator i;
				for (i=events.begin(); i!=events.end(); ++i)
					if (i->getLabel()==**it)
					{
						(i->getState()).;


					}

			}

		}
	}
}

// all functions necessary for exploration algorithm
/*
 * add one extendable event e to set of seen events U
 */
void LES::extend(Event & e)
{
	e.seen = true; // U is virtual set including events whose seen attribute is true
}

/*
 * find all events which can extend from C
 */
std::set<Event *> LES::findExtension(const Config & C)
{
	std::set<Event *> tmp;

	return tmp;

}

/*
 * * find all events which are enabled at state(C)
 */
std::set<Event *> LES::findEnable(const Config & C)
{
	std::set<Event *> tmp;

	return tmp;

}

/*
 * find an alternative to D after C
 */
Config LES::find_alt(const Config & C, const std::set<Event *> & D)
{
	Config J;
	std::set<Event*>::iterator e;
	for (e=events.begin(); e!=events.end(); e++)
	{
		if (e*).getSeen()== true
		{
			std::set<Event*> tmp;
			temp.insert(C.getEvents(),it*);
			if (is_config(temp) && ((it*).is_in(C)==false))
			{
				std::set<Event*>::iterator i;
				for (i=D.begin();i!=D.end();i++)
					if (e*).is_cfl(i*)
					{
						J.add(e*);
						C.add(e*);
						e*.visited=true;
					}
			}
		}
	}
	return J;
} // end of find_alt
/*
 * Remove event e for U to G
 */
void LES::remove(Event & e)
{
	e.moveToGabage();
	//remove all branh conflict with e to the gabage
	std::set<Event>:: iterator i;
	for (i=events.begin(); i!=events.end(); i++)
		if (e.is_cfl(i*))
			(i*).moveToGabage();
}

/*
 * Explore the unfolding with DFS method
 */

void LES::explore(const Config & C,std::set<Event *> A )
{

}

}// end of namespace

