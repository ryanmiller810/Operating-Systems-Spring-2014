//=================================================================
//
//  Author: Ryan Miller
//  Date: 03/21/2014
//  Course: CS433
//  Assignment 3
//  Assumptions: **
//  Special Instructions: **
//
//=================================================================

#include "event.h"

using namespace std;

//=================================================================

int main()
{

	cout << "\n" << endl;
	cout << "*** Ryan Miller ***" << endl;
	cout << "*** CS 433 Operating Systems ***" << endl;
	cout << "*** Assignment 3 ***" << endl;
	cout << "\n" << endl;

	event e1; // create an event
	int num;
	int proc;
	
	cout << "Please enter the number corresponding to the job scheduling algorithm you wish to perform." 		     << endl;
	cout << "Enter a (1) if you'd like to perform FCFS algorithm" << endl;
	cout << "Enter a (2) if you'd like to perform SJF algorithm" << endl;
	cin >> num;
	cout << "\n" << endl;

	switch(num)
	{
	
		case 1:

		e1.insertProcessesFCFS(proc);
		e1.calcAnalysis();
		e1.runProcesses();
		break;
	
		case 2:
	
		e1.insertProcessesSJF(proc);
		e1.calcAnalysis();
		e1.runProcesses();
		break;
	
		default:
	
		cout << "You have selected an invalid option!" << endl;
	
	}
	
} // end of main

//=================================================================
