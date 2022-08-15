#pragma once
#include"Costumer.h"

class Event : public Costumer
{
private:
	string eventname;//event name
	string timeSlot1 = "9:00 - 11:00";//time slot1
	string timeSlot2 = "12:00 - 14:00";//time slot2
	string timeSlot3 = " 15:00 - 17:00";//time slot3
	date event_date;//event date
	Costumer costumerinfo;//object of a class costumer
	int id;//Id of list of costumers added
	int eventoption;//user choice input for events
	void addevent();//for case 1 
	void editevent();//for case 2 where user wants to edit his event date
	void scheduleofevent();//for case 4 where user want to check the schedule of event
	string getDateString(int, int, int, int);//to get string the input(day,month,year) of user to search whether it appears or not
	bool validitycheck(string);//for date validity check
public:
	Event();
	Event(string, date, Costumer);
	void options(string);
};

