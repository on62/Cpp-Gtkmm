
#include <iostream>
//#include <gtkmm.h>

using namespace std;
using namespace Gtk;

class Message
{
public:
	static string dialog_box(string msg, string title);
	static string warning(string title);
	static string print_menu(string text, string title);
	static string print_ticket(int i);
};

class Employee
{
public:
	static string access_emp();
	static string enter_Info();
	static string check_status();
	static string print_status();

};

class Technician
{
public:
	static string access_tech();
	static string view_ticket();
};
