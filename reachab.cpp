#include <fstream>
#include <iostream>

#include "pnapi/pnapi.h"


using namespace std;
using namespace pnapi;


void test (int argc, char ** argv)
{
   PetriNet n;
   ifstream in;

   assert (argc == 2);
   in.open (argv[1]);

   try
   {
      in >> io::pnml >> n;
   }
   catch (exception::InputError err)
   {
      std::cerr << err << std::endl;
      exit (EXIT_FAILURE);
   }

   std::cout << n.getPlaces().size() << " places, " <<
n.getTransitions().size() << " transitions\n";


   std::cout << "Places:\n";
   std::set<Place*> places = n.getPlaces ();
   for (std::set<Place*>::iterator it = places.begin (); it !=
places.end (); ++it)
   {
      std::cout << "'" << (*it)->getName () << "' tokens " <<
(*it)->getTokenCount () << std::endl;
   }
   /*!
    * PRINT TO DOT FILE

	fstream fs("net.dot",fstream::out);
	Node a;
	fs << "Digraph Petrinet {\n";
	std::set<Arc*> arcs = n.getArcs();
	std::set<Arc*>::iterator ai;
	  for(ai=arcs.begin();ai!=arcs.end();++ai)
	  {
		  fs << (*ai)->getSourceNode().getName() << "->";

		  fs << (*ai)->getTargetNode().getName() << ";\n";
	  }

	fs<< "}";
	fs.close();
 */

   std::cout << "Net loaded, printing:\n";
   std::cout << io::dot << n;
  // output(n);

   std::cout << "Done!:\n";
   return;
}



int main(int argc, char** argv) {

   test (argc, argv);
   return 0;
}
