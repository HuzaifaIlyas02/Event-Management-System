#include"Costumer.h"

Costumer::Costumer() :C_FName(""), C_LName(""), C_Email(""), C_Number("")
{}

Costumer::Costumer(string CFNam, string CLNam, string CEmai, string CNumber) :C_FName(CFNam), C_LName(CLNam), C_Email(CEmai), C_Number(CNumber)
{}

void Costumer::SetC_Email(string E)
{
	C_Email = E;
}

void Costumer::SetC_FName(string FN)
{
	C_FName = FN;
}

void Costumer::SetC_LName(string LN)
{
	C_LName = LN;
}

void Costumer::SetC_Number(string CNumber)
{
	C_Number = CNumber;
}

string Costumer::GetC_Email()
{
	return C_Email;
}

string Costumer::GetC_FName()
{
	return C_FName;
}

string Costumer::GetC_LName()
{
	return C_LName;
}

string Costumer::GetC_Number()
{
	return C_Number;
}
