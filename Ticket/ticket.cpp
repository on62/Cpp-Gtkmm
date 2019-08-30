#include "ticket.h"

using namespace std;
using namespace Gtk;

vector <string> EmployeeName;
vector <int> station_num;
vector <bool> ticket_status;
vector <string > issues;

static string print_vectors()
{
	for(int i=0; i<EmployeeName.size(); i++)
	{
		return (to_string(i+1))+".\t\t"+ issues[i];
	}

}
static string check(bool b)
{
	if (b==true)
	{
		return "open";
	}
	else
	{
		return "closed";
	}
}
string Message::dialog_box(string msg,string title)
{
	Dialog *dialog=new Dialog();
	dialog->set_title(title);
	Label *label=new Label(msg);
	dialog->get_content_area()->pack_start(*label);
	label->show();
	dialog->add_button("Employee",0);
	dialog->add_button("Tech",1);
	dialog->add_button("Exit",2);


	int result=dialog->run();
	dialog -> close();
	while (Main::events_pending())
	{
		Main::iteration();
	}


	delete dialog;
	delete label;

	if(result == 0)
	{
		Employee::access_emp();
	}
	else if (result == 1)
	{
		Technician::access_tech();
	}
	else
	{
		exit(0);
	}
}

string Employee::access_emp()
{
	Dialog *dialog=new Dialog();
	dialog->set_title("Welcome Employee!");

	Label* label=new Label("Enter Password:");
	dialog->get_content_area()->pack_start(*label);


	Entry* entry=new Entry();
	entry->set_text(" ");
	entry->set_max_length(20);

	entry->show();
	dialog->get_vbox()->pack_start(*entry);
	label->show();

	dialog->add_button("OK",0);
	dialog -> add_button ("Cancel", 1);
	int result=dialog->run();
	string text = entry->get_text();
	dialog->close();
	while(Main::events_pending())
	{
		Main::iteration();
	}

	if(text == "1234"&& result ==0)
	{
		Message::print_menu("You're logged in as Employee", "Welcome Employee");;
	}
	else if (result	== 1)
	{
		Message::dialog_box("Are you a Employee or a Tech??\nEnter exit on both fields to quit.","Ticket System");

	}
	else
	{
		Message::warning("Welcome Employee!");

	}

	delete dialog;
	delete label;
	delete entry;

}
string Message::warning(string title)
{
	Dialog *dialog=new Dialog();
	dialog->set_title(title);

	Label* label=new Label("invalid Password\nEnter again");
	dialog->get_content_area()->pack_start(*label);
	label->show();

	dialog->add_button("OK",0);
	dialog -> add_button ("Exit", 1);
	int result=dialog->run();
	dialog->close();
	while(Main::events_pending())
	{
		Main::iteration();
	}
	if(result == 0)
	{
		if(title == "Welcome Employee!")
		{
			Employee::access_emp();
		}
		else
		{
			Technician::access_tech();
		}

	}
	else
	{
		exit (1);
	}
	delete dialog;
	delete label;
}
string Technician::access_tech()
{
	Dialog *dialog=new Dialog();
	dialog->set_title("Welcome Technician!");

	Label* label=new Label("Enter Password:");
	dialog->get_content_area()->pack_start(*label);


	Entry* entry=new Entry();
	entry->set_text(" ");
	entry->set_max_length(20);

	entry->show();
	dialog->get_vbox()->pack_start(*entry);
	label->show();

	dialog->add_button("OK",0);
	dialog -> add_button ("Cancel", 1);
	int result=dialog->run();
	string text = entry->get_text();
	dialog->close();
	while(Main::events_pending())
	{
		Main::iteration();
	}

	if(text == "4321"&& result ==0)
	{
		Message::print_menu("You're logged in as Technician", "Welcome Technician");
	}
	else if (result == 1)
	{
		Message::dialog_box("Are you a Employee or a Tech??\nEnter exit on both fields to quit.","Ticket System");
	}

	else
	{
		Message::warning("Welcome Technician");

	}
	delete dialog;
	delete label;
	delete entry;
}
string Message::print_menu(string text, string title)
{
	Dialog *dialog=new Dialog();
	dialog->set_title(title);
	Label *label=new Label(text);
	dialog->get_content_area()->pack_start(*label);
	label->show();
	if(title=="Welcome Employee")
	{
		dialog->add_button("Create ticket",0);
		dialog->add_button("View ticket",1);
		dialog->add_button("Exit",2);


		int result=dialog->run();
		dialog -> close();
		while (Main::events_pending())
		{
			Main::iteration();
		}


		delete dialog;
		delete label;

		if(result == 0)
		{
			Employee::enter_Info();
		}
		else if (result == 1)
		{
			if(issues.size()==0)
			{
				Dialog *dialog = new Dialog();
				dialog -> set_title("List of Tickets");

				Label *label = new Label("NO TICKETS YET!!!");
				dialog->get_content_area()->pack_start(*label);

				label ->show();

				dialog -> add_button("Back to main", 0);
				dialog -> add_button ("Exit", 1);

				int result = dialog -> run();
				dialog -> close();
				while(Main::events_pending())
				{
					Main::iteration();
				}
				delete dialog;
				delete label;

				if(result==0)
				{
					Message::dialog_box("Are you a Employee or a Tech??\nEnter exit on both fields to quit.","Ticket System");
				}
			}

			else
			{
				Employee::check_status();
			}
		}
		else
		{
			exit(0);
		}
	}
	else
	{
		dialog->add_button("Recieve & Close Ticket",0);
		dialog->add_button("Exit",1);


		int result=dialog->run();
		dialog -> close();
		while (Main::events_pending())
		{
			Main::iteration();
		}


		delete dialog;
		delete label;

		if(result == 0)
		{
			Technician::view_ticket();
		}
		else if (result == 1)
		{
			return "view";
		}
		else
		{
			exit(0);
		}
	}
}
string text1 ="";
int i;
string Employee::enter_Info()
{
	Dialog *dialog=new Dialog();
	dialog->set_title("Ticket Info");
	Label *label_name=new Label("Name");
	dialog->get_content_area()->pack_start(*label_name);
	Entry *entry_name = new Entry();
	entry_name -> set_text(" ");
	entry_name->set_max_length(10);
	entry_name-> show();
	dialog -> get_vbox()->pack_start(*entry_name);


	Label *label_station = new Label("Station #");
	dialog->get_content_area()->pack_start(*label_station);
	Entry *entry_station = new Entry();
	entry_station-> set_text(" ");
	entry_station->set_max_length(10);
	entry_station-> show();
	dialog -> get_vbox()->pack_start(*entry_station);



	Label *label_issue = new Label("Issue(computer, printer, projector)");
	dialog->get_content_area()->pack_start(*label_issue);
	Entry *entry_issue = new Entry();
	entry_issue-> set_text(" ");
	entry_issue->set_max_length(10);
	entry_issue-> show();
	dialog -> get_vbox()->pack_start(*entry_issue);

	label_name->show();
	label_station->show();
	label_issue-> show();

	dialog->add_button("Done", 0);

	int result = dialog->run();
	string text1 = entry_name->get_text();
	EmployeeName.push_back(text1);
	string text2 = entry_station -> get_text();
	station_num.push_back(stoi(text2));
	//string text3 = entry_issue-> get_text();
	issues.push_back(entry_issue-> get_text());
	ticket_status.push_back(true);
	dialog-> close();

	while(Main::events_pending())
	{
		Main:: iteration();
	}

	delete dialog;
	delete label_name;
	delete label_issue;
	delete	label_station;

	delete entry_name;
	delete entry_station;
	delete entry_issue;
	if(result == 0)
	{

		Message::print_ticket(0);

	}
}

string Technician::view_ticket()
{
	if(issues.size()!=0)
	{
		Dialog *dialog = new Dialog();
		dialog -> set_title("List of Tickets");

		Label *label = new Label(print_vectors());
		dialog->get_content_area()->pack_start(*label);

		label -> show();

		dialog->add_button("Done", 0);
		int result = dialog->run();
		dialog->close();

		while(Main::events_pending())
		{
			Main::iteration();
		}

		delete dialog;
		delete  label;

		if(result==0)
		{
			Message::dialog_box("Are you a Employee or a Tech??\nEnter exit on both fields to quit.","Ticket System");
		}
	}
	else
	{
		Dialog *dialog = new Dialog();
		dialog -> set_title("List of Tickets");

		Label *label = new Label("NO TICKETS YET!!!");
		dialog->get_content_area()->pack_start(*label);

		label ->show();

		dialog -> add_button("Back to main", 0);
		dialog -> add_button ("Exit", 1);

		int result = dialog -> run();
		dialog -> close();
		while(Main::events_pending())
		{
			Main::iteration();
		}
		delete dialog;
		delete label;

		if(result==0)
		{
			Message::dialog_box("Are you a Employee or a Tech??\nEnter exit on both fields to quit.","Ticket System");
		}
	}
}

string Message::print_ticket(int i)
{

	Dialog *dialog = new Dialog();
	dialog -> set_title("Hello " + text1 );

	Label *label = new Label("Your ticket number is "+to_string(++i));
	dialog->get_content_area()->pack_start(*label);

	label ->show();

	dialog -> add_button("Back to main", 0);

	int result = dialog -> run();
	dialog -> close();
	while(Main::events_pending())
	{
		Main::iteration();
	}
	delete dialog;
	delete label;

	if(result==0)
	{
		Message::dialog_box("Are you a Employee or a Tech??\nEnter exit on both fields to quit.","Ticket System");
	}
}
string temp;
string Employee::check_status()
{

	Dialog *dialog = new Dialog();
	dialog -> set_title("Ticket Status check");

	Label *label = new Label("Enter Your ticket number");
	dialog->get_content_area()->pack_start(*label);
	label ->show();

	Entry *entry = new Entry();
	entry -> set_text("");
	entry->set_max_length(20);
	entry-> show();
	dialog -> get_vbox()->pack_start(*entry);



	dialog -> add_button("OK", 0);
	dialog -> add_button("Cancel", 0);


	int result = dialog -> run();
	string text = entry ->get_text();

	temp = check(ticket_status[stoi(text)-1]);

	dialog -> close();
	while(Main::events_pending())
	{
		Main::iteration();
	}
	delete dialog;
	delete label;
	delete entry;


	if(result==0)
	{
		Employee::print_status();
	}
	else
	{
		Message::dialog_box("Are you a Employee or a Tech??\nEnter exit on both fields to quit.","Ticket System");
	}
}
string Employee::print_status()
{

	Dialog *dialog = new Dialog();
	dialog -> set_title("Ticket Status print");

	Label *label = new Label("Hello " +text1 +". Your ticket status is "+ temp);
	dialog->get_content_area()->pack_start(*label);
	label ->show();

	dialog -> add_button("OK", 0);
	dialog -> add_button("Cancel", 0);


	int result = dialog -> run();
	dialog -> close();
	while(Main::events_pending())
	{
		Main::iteration();
	}
	delete dialog;
	delete label;
}
