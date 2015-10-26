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

	// attributes for exploration process
	bool visited; // true if it has been visited
	bool seen; // true if it is in U of the LES
	bool in_gabage; // true if it is removed to the gabage
	int  in_C; // = 0 if not in C in exploration algorithm, 1 in reverse
	bool disable; //true if it is disable (in D)
public:
	Event(Transition t, Config c);
	void addToHistory(Event *);
	void setState(const Marking & m);
	Marking getState(){return state;}

	// functions necessary for exploration
	bool getVisited(){return visited;}
	bool getSeen(){return seen;}
	bool getDisable(){return disable;}
	Transition getLabel(){return lbl;}
	void setDisable(){disable=true;}
	void setVisited(bool v){ visited = v; }
	void moveToGabage(){in_gabage = true;}
	bool is_im_cfl(Event); //check if two events is immediately conflict
	bool is_cfl(Event); // check if two events is conflict or not
	bool is_in_gabage(){return in_gabage;} // removed for U to G
	bool is_in_config(){return in_C;} // return true if it is in C in exploration process
	bool is_depend(Transition & t); // return true if current event is dependent with t

};// end of Event class
} // end of namespace
