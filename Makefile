CXX = g++
LD = g++
LIBDIR = $(HOME)/devel/PNgraph/tools/lib
INCDIR = $(HOME)/devel/PNgraph/tools/include

all: reachab

reachab: reachab.o
	$(LD) -o reachab reachab.o -L$(LIBDIR) -lpnapi

reachab.o: reachab.cpp
	$(CXX) -c reachab.cpp -I$(INCDIR)

clean:
	@rm -f reachab reachab.o

run: reachab
	export LD_LIBRARY_PATH=$(LIBDIR):$LD_LIBRARY_PATH ; ./reachab examples/testnet1.pnml
