#include "pnapi.h"

using namespace pnapi;

namespace pngraph
{
class Marking;
class Event
{
	int ID;
	Transition lbl;
	Config  his; // set of precessors
	std::set<Event *> cfl; // set of conflict events
	Marking state;
	bool visited; // true if it has been visited
	bool seen; // true if it is in U of the LES
	bool in_gabage; // true if it is removed to the gabage
	int  in_config; // = 0 if not in C in exploration algorithm, 1 in reverse
	bool disable; //true if it is disable (in D)
public:
	Event(Transition t, Config c);
	bool check_commute(const Transition &, const Transition &);
	void setVisited(bool v){ visited = v; }
	void moveToGabage(){in_gabage = true;}
	void setState(const Marking & m);
	void setDisable(){disable=true;}
	void addToHistory(Event *);

	Marking getState(){return state;}
	bool getVisited(){return visited;}
	bool getSeen(){return seen;}
	bool getDisable(){return disable;}
	Transition getLabel(){return lbl;}
	bool is_im_cfl(Event); //check if two events is immediately conflict
	bool is_cfl(Event); // check if two events is conflict or not
	bool is_in_gabage(){return in_gabage;}
	bool is_in_config(){return in_config;}
	bool is_depend(Transition & t);

};// end of Event class
}
