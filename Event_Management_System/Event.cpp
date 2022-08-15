#include"Event.h"

void gotoxy(int x, int y)
{
	// For Slide of the managemnet system at the console
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

Event::Event() :eventname(""), event_date(0, 0, 0), eventoption(0)
{}

Event::Event(string Eventname, date D, Costumer C) : eventname(Eventname), event_date(D), costumerinfo(C)
{}

//--------------- Makes an string and returns that string -----------

string Event::getDateString(int day, int month, int year, int timechoice)
{
	string checkfordateexistence;
	string stringday = to_string(day);//converting to string 
	string stringmonth = to_string(month);//converting to month
	string stringyear = to_string(year);//converting to year
	checkfordateexistence.append(stringday);// adding to sring from end
	checkfordateexistence.append("/");
	checkfordateexistence.append(stringmonth);
	checkfordateexistence.append("/");
	checkfordateexistence.append(stringyear);
	checkfordateexistence.append("\t\t");
	if (timechoice == 1)
	{
		checkfordateexistence.append(timeSlot1);
	}
	else if (timechoice == 2)
	{
		checkfordateexistence.append(timeSlot2);
	}
	else if (timechoice == 3)
	{
		checkfordateexistence.append(timeSlot3);
	}
	return checkfordateexistence;
}

//------------ Occurence Check of Date is already set or not ---------------

bool Event::validitycheck(string tocheck)
{
	ifstream Checkdate("Info.txt", ios::in);//variable of ifstream to read a file for check
	string savefile;//string to save file in it

	while (!Checkdate.eof())
	{
		while (getline(Checkdate, savefile))
		{
			size_t found = savefile.find(tocheck);

			if (found != std::string::npos)
			{
				return true;
			}
		}
	}
	Checkdate.close();
	return false;

}

//----------------- Shows the Costumer the Schedule of entered event ------------------
void Event::scheduleofevent()
{

	string user_option2;
	cin.ignore();
	cout << "Please enter the event Type : " << endl;
	cout << "Event Type : ";
	getline(cin, user_option2);

	ifstream ifs("Info.txt", ios::in);
	string line;
	int counter = 0;

	while (getline(ifs, line))
	{
		size_t pos = line.find(user_option2);
		if (pos != string::npos)
		{
			cout << line << endl;
			counter++;
		}
	}
	if (counter == 0)
	{
		cout << "This Type of Event is not registered " << endl;
	}

	ifs.close();
}

//----------------- Taking from user the options ------------

void Event::options(string Managementsystemname)
{
	char Continue;
	ofstream temp("Info.txt", ios::app);
	ifstream reader("Info.txt", ios::ate); // std::ios::ate means open at end
	if (reader.tellg() == 0)
	{
		ofstream Info("Info.txt", ios::app);
		Info << "ID \tEventType \tCostumerName \t\tDate \t\t\tTime" << endl;
		Info.close();
	}
	temp.close();
	reader.close();

	for (int i = 0; i <= 30; i++)
	{
		Sleep(5);
		system("CLS");
		gotoxy(i, 2);
		cout << "Welcome to " << Managementsystemname << " Event Management" << endl;
	}
	ofstream Eventoptions("Option.txt", ios::out);//writing in the file
	Eventoptions << "1- Add Event \n2- Edit Event \n3- List of Events \n4- Schedule Of Events \n5- Exit" << endl;
	string Eventopts;//string for copying written file

	do {
		ifstream Event_Options("Option.txt", ios::in);//reading from the file
		//// Use a while loop together with the getline() function to read the file line by line
		while (getline(Event_Options, Eventopts)) {
			//	// Output the text from the file
			cout << Eventopts << "\n";
		}
		cout << "\nYour choice : ";
		cin >> eventoption;//user choice choosing event option
		system("CLS");

		if (eventoption == 1)
		{
			addevent();
			system("CLS");

		}
		else if (eventoption == 2)
		{
			editevent();
		}
		else if (eventoption == 3)
		{
			ifstream ListOfcostumers("Info.txt", ios::in);//to show listed costumers
			string List;
			while (getline(ListOfcostumers, List))//for showing list of costumer who are registered
			{
				cout << List << "\n";
			}
			ListOfcostumers.close();

		}
		else if (eventoption == 4)
		{
			scheduleofevent();
		}
		else if (eventoption == 5)
		{
			break;
		}
		cout << "\nDo You want to continue ? ";
		cin >> Continue;
		system("CLS");
		Event_Options.close();
	} while (Continue == 'Y' || Continue == 'y');
	Eventoptions.close();

}

//-----------  Add new Event ------------------------
void Event::addevent()
{
	int day = 32, month = 13, year = 2020;
	system("CLS");
	ifstream Checkdate("Info.txt", ios::in);//variable of ifstream to read a file for check
	string checkfordateexistence;
	string savefile;//string to save file in it
	ofstream writeTiming("Time.txt", ios::out);//writing in the file
	writeTiming << "Select Event Timing \n1- 9:00 - 11:00 \n2- 12:00 - 14:00 \n3- 15:00 - 17:00" << endl;
	ifstream Readtiming("Time.txt", ios::in);//reading from the file
	string copytime;//string for copying written file
	int timechoice;

	/*eventname = "";*/

	writeTiming.close();
	if (eventname == "" && event_date.Getday() == NULL && event_date.Getmonth() == NULL && event_date.Getyear() == NULL)
	{
		cin.ignore();
		cout << "//Avoid Spacing Plz" << endl;
		cout << "Event Type : ";
		getline(cin, eventname);
		while (day >= 32) {
			system("CLS");
			cout << "Enter Date PLZ " << endl;
			cout << "Enter Day (1 - 31): ";
			cin >> day;
		}while (month >= 13) {
			cout << "Enter month (1 - 12) : ";
			cin >> month;
		} while (year < 2021) {
			cout << "Enter year : ";
			cin >> year;
		}
		event_date = { day,month,year };
	}
	else
	{
		day = event_date.Getday();
		month = event_date.Getmonth();
		year = event_date.Getyear();
	}
	system("CLS");
	cout << "Event Date Entered " << endl;
	event_date.display();
	cout << endl;
	while (getline(Readtiming, copytime)) {
		// Output the text from the file
		cout << copytime << "\n";//\n is used bcoz getline is used just for one line reading
	}
	cout << "\nYour Slot choice : ";
	cin >> timechoice;//user choice of time slot

	checkfordateexistence = getDateString(day, month, year, timechoice);

	bool check = validitycheck(checkfordateexistence);

	if (check == true)
	{
		system("CLS");
		cout << "The date is already setted PLZ enter again " << endl;
		cout << "Event Date Entered " << endl;
		event_date.display();
		cout << "Enter Day (1 - 31) : ";
		cin >> day;
		cout << "Enter month (1 - 12) : ";
		cin >> month;
		cout << "Enter year : ";
		cin >> year;
		system("CLS");

		while (getline(Readtiming, copytime)) {
			// Output the text from the file
			cout << copytime << "\n";//\n is used bcoz getline is used just for one line reading
		}
		cout << "\nYour Slot choice : ";
		cin >> timechoice;//user choice of time slot
	}

	Readtiming.close();

	cout << endl;
	event_date = { day,month,year };//setting date 
	system("CLS");
	if (costumerinfo.GetC_FName() == "" || costumerinfo.GetC_LName() == "" || costumerinfo.GetC_Email() == "" || costumerinfo.GetC_Number() == "")
	{
		cout << "//Avoid Spacing Plz" << endl;
		cout << "Enter Your First Name : ";
		cin >> C_FName;//costumer first name
		cout << "Enter Your Last Name : ";
		cin >> C_LName;//costumer last name
		cout << "Enter Your Email : ";
		cin >> C_Email;//costumer email
		cout << "Enter Number : ";
		cin >> C_Number;//costumer number
		costumerinfo = { C_FName,C_LName,C_Email,C_Number };
	}
	else
	{
		C_FName = costumerinfo.GetC_FName();
		C_LName = costumerinfo.GetC_LName();
		C_Email = costumerinfo.GetC_Email();
		C_Number = costumerinfo.GetC_Number();
	}
	system("CLS");


	srand(time(0));
	id = 10 + rand() % 89;//generating random numbers for assigning registration number

	ofstream SavingInfo("Info.txt", ios::app);//saving info of customers in file

	switch (timechoice)
	{
	case 1:
		SavingInfo << id << "\t" << eventname << "\t" << C_FName << C_LName << "\t\t" << event_date.Getday() << "/" << event_date.Getmonth() << "/" << event_date.Getyear() << "\t\t" << timeSlot1 << endl;
		break;
	case 2:
		SavingInfo << id << "\t" << eventname << "\t" << C_FName << C_LName << "\t\t" << event_date.Getday() << "/" << event_date.Getmonth() << "/" << event_date.Getyear() << "\t\t" << timeSlot2 << endl;
		break;
	case 3:
		SavingInfo << id << "\t" << eventname << "\t" << C_FName << C_LName << "\t\t" << event_date.Getday() << "/" << event_date.Getmonth() << "/" << event_date.Getyear() << "\t\t" << timeSlot3 << endl;
		break;
	}
	SavingInfo.close();
	//read complete list -> id 1,2,3,4,5 

	cout << "Your Registration number is  " << id << endl << endl;
	cout << "Event Booked Successfully..............." << endl;
	system("pause");
	system("CLS");
}

//----------------- To edit the costumer event plan ---------------------
void Event::editevent()
{
	int day = 32, month = 13, year = 2020;//previous date which has to be changed
	ifstream Temp("Info.txt", ios::in);//temporary for editing
	string temp;//temp string to copy
	string Time;//string to copy time
	int regnumb;//taking registration
	bool isfound = false;//to check whether the user input is present in file or not 

	while (getline(Temp, temp))//to show user the info file 
	{
		cout << temp << "\n";//for reading each line
	}
	Temp.close();
	cout << "\nWhat is your registration number : ";
	cin >> regnumb;

	string stringregistration = to_string(regnumb);//converting registration number into string 
	ifstream InfoFileToEdit("Info.txt", ios::in);//temporary for editing
	ofstream infotemp("TempInfo.txt", ios::ate);//creating new file for temperory transfer 

	while (!InfoFileToEdit.eof())
	{
		getline(InfoFileToEdit, temp);//saving in temp
		string check;
		check = temp.substr(0, 2);//taking first digits coz our registration number is two digit number

		if (check == stringregistration)
		{
			system("CLS");
			cin.ignore();
			cout << "Your Registration is found" << endl;
			cout << "//Avoid Spacing Plz" << endl;
			cout << "Event Type : ";
			getline(cin, eventname);
			while (day >= 32) {
				system("CLS");
				cout << "Enter Date PLZ " << endl;
				cout << "Enter Day (1 - 31) : ";
				cin >> day;
			}while (month >= 13) {
				cout << "Enter month (1 - 12) : ";
				cin >> month;
			} while (year < 2021) {
				cout << "Enter year : ";
				cin >> year;
			}
			event_date = { day,month,year };

			system("CLS");

			string changinginfo;//string to check whether it is in the file or not
			int newtimechoice;//new choice for user input for time
			ifstream newreadtime("Time.txt", ios::in);
			string copynewtime;//to store the time file for display
			string newinfo;//to store the info file for display
			cout << "Event Date Entered " << endl;
			event_date.display();
			while (getline(newreadtime, copynewtime)) {
				// Output the text from the file
				cout << copynewtime << "\n";//\n is used bcoz getline is used just for one line reading
			}
			cout << "\nYour Slot choice : ";
			cin >> newtimechoice;//user choice of time slot
			changinginfo = getDateString(day, month, year, newtimechoice);//function to make an string 
			bool check = validitycheck(changinginfo);//function called for checking the validity
			if (check == true)
			{
				system("CLS");
				cout << "The date is already setted PLZ enter again " << endl;
				cout << "Event Date Entered " << endl;
				event_date.display();
				cout << "Enter Day (1 - 31) : ";
				cin >> day;
				cout << "Enter month (1 - 12) : ";
				cin >> month;
				cout << "Enter year : ";
				cin >> year;
				system("CLS");

				while (getline(newreadtime, copynewtime)) {
					// Output the text from the file
					cout << copynewtime << "\n";//\n is used bcoz getline is used just for one line reading
				}
				cout << "\nYour Slot choice : ";
				cin >> newtimechoice;//user choice of time slot
			}

			system("CLS");
			cout << "Event Date Entered " << endl;
			event_date.display();
			cout << "//Avoid Spacing Plz" << endl;
			cout << "Enter Your First Name : ";
			cin >> C_FName;//costumer first name
			cout << "Enter Your Last Name : ";
			cin >> C_LName;//costumer last name
			cout << "Enter Your Email : ";
			cin >> C_Email;//costumer email
			cout << "Enter Number : ";
			cin >> C_Number;//costumer number
			system("CLS");

			changinginfo = "";
			changinginfo.append(stringregistration);
			changinginfo.append("\t");
			changinginfo.append(eventname);
			changinginfo.append("\t");
			changinginfo.append(C_FName);
			changinginfo.append(C_LName);
			changinginfo.append("\t\t");
			changinginfo.append(getDateString(day, month, year, newtimechoice));
			infotemp << changinginfo << endl;//writing in the file
			newreadtime.close();//closing file

		}
		else {
			infotemp << temp << endl;
		}
	}
	InfoFileToEdit.close();//closing file
	infotemp.close();//closing file

	remove("Info.txt");//deleting prvious file
	int value = rename("TempInfo.txt", "Info.txt");//renaming the new file as a previous file
	if (value == 0)
	{
		cout << "Event date Changed" << endl;
	}
	else
	{
		cout << "Evetn Cannot be changed" << endl;
	}
}
