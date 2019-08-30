CXXFLAGS += -std=c++11
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

ex: ticket_main.o ticket.o
		$(CXX) $(CXXFLAGS) -o ticket ticket_main.o ticket.o $(GTKFLAGS)
ticket_main.o: ticket_main.cpp ticket.h
		$(CXX) $(CXXFLAGS) -c ticket_main.cpp $(GTKFLAGS)
ticket.o: ticket.h ticket.cpp
		$(CXX) $(CXXFLAGS) -c ticket.cpp $(GTKFLAGS)
Clean:
	rm -f *.o ticket