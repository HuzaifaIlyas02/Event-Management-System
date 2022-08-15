#pragma once
#include"Date.h"

class Costumer {
protected:
	string C_FName;//costumer first name
	string C_LName;//costumer last name
	string C_Number;//costumer number
	string C_Email;//costumer email

public:
	Costumer();
	Costumer(string, string, string, string);
	void SetC_FName(string);
	void SetC_LName(string);
	void SetC_Number(string);
	void SetC_Email(string);
	string GetC_FName();
	string GetC_LName();
	string GetC_Number();
	string GetC_Email();
};