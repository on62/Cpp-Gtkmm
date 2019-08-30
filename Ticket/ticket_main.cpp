#include "ticket.h"
#include <gtkmm.h>


using namespace std;
using namespace Gtk;

int main(int argc,char *argv[])
{
	string text;
	Gtk::Main kit(argc,argv);
	Message::dialog_box("Are you a Employee or a Tech??\nEnter exit on both fields to quit.","Ticket System");
	return 0;
}
