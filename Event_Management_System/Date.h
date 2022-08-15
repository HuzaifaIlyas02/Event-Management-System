#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include<stdio.h>
#include<cstdio>
#include<Windows.h>


using namespace std;

class date {
private:
	int day, month, year;
public:
	date();
	date(int, int, int);
	void Setday(int);
	void Setmonth(int);
	void Setyear(int);
	int Getday();
	int Getmonth();
	int Getyear();
	void display();
};

