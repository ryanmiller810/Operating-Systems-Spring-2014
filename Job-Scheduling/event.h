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

#include<deque>
#include<algorithm>
#include<stdlib.h>
#include<iostream>
#include<string>

#include "process.h"
#include "random.h"

using namespace std;

//=================================================================

class event
{

private:

	deque<Process> eventQueue;  // using a deque for DES sim
	int procNum;  // input needed for how many processes to sim 
	float throughput; // used to perform throughput calculation
	float avgWait; // used to perform average wait time calculation
	float avgTurn; // used to perform average turnaround calculation
	
public:

	event(); // constructor
	~event(); // destructor
	
	// PURPOSE: This function inserts processes into the queue
	//	    based on how many processes the user wishes to
	//	    create. Also, the function sorts the processes
	//	    into the FCFS job scheduling algorithm.
	// TO CALL: This passes the parameter procNum which denotes
	//	    how many processes are to be created.
	void insertProcessesFCFS(int procNum);
	
	// PURPOSE: This function inserts processes into the queue
	//	    based on how many processes the user wishes to
	//	    create. Also, the function sorts the processes
	//	    into the SJF job scheduling algorithm.
	// TO CALL: This passes the parameter procNum which denotes
	//	    how many processes are to be created.
	void insertProcessesSJF(int procNum);
	
	// PURPOSE: This function displays the processes based on 
	//	    the scheduling algorithm selected. It also pops
	//	    the processes from the queue.
	// TO CALL: No parameter needed.
	void runProcesses();
	
	// PURPOSE: To perform calculations related to the analysis
	//	    of the event simulation. IE: calculating the 
	//	    throughput of the simulation.
	// TO CALL: No parameter needed.
	void calcAnalysis();
	
}; // end of event

//=================================================================
