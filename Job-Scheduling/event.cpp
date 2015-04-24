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

event::event()
{}

event::~event()
{}

//=================================================================

void event::insertProcessesFCFS(int numProc)
{

	cout << "Please enter the number of processes you would like to test: " << endl;
	cin >> procNum;
	
	for(int i = 0; i < procNum; i++)
	{
	
		Process p1; // Create a new process and set these variables
		p1.PID = rand() % 3000+1000;
		p1.arrivalTime = rand() % 300+1;
		p1.priority = p1.arrivalTime;
		p1.burstTime = rand() % 100+5;
		p1.nextBurst = CPUBurstRandom(p1.burstTime);
		p1.ioBurst = rand() % 100+30;
		p1.finishTime = (p1.burstTime+p1.ioBurst);
		p1.waitTime = ((p1.burstTime + p1.arrivalTime)-p1.finishTime);
		
		eventQueue.push_back(p1); // push the process onto the event queue
		
	}
	
	sort(eventQueue.begin(), eventQueue.end()); // call the std sort function to sort
						    // into FCFS
} // end of insertProcessesFCFS

//=================================================================

void event::insertProcessesSJF(int procNum)
{

	cout << "Please enter the number of processes you would like to test: " << endl;
	cin >> procNum;
	
	for(int i = 0; i < procNum; i++)
	{
	
		Process p1; // Create a new process and set these variables 
		p1.PID = rand() % 3000+1000;
		p1.arrivalTime = rand() % 300+1;
		p1.burstTime = rand() % 100+5;
		p1.nextBurst = CPUBurstRandom(p1.burstTime);
		p1.priority = p1.burstTime;
		p1.ioBurst = rand() % 100+30;
		p1.finishTime = (p1.burstTime+p1.ioBurst);
		p1.waitTime = ((p1.burstTime + p1.arrivalTime)-p1.finishTime);
		
		eventQueue.push_back(p1); // push the process onto the event queue
		
	}
	
	sort(eventQueue.begin(), eventQueue.end()); // call the std sort function
						    // to sort into SJF

} // end of insertProcessesSJF

//=================================================================

void event::runProcesses()
{

	Process tmp; // Create a temporary process
	
	while(!eventQueue.empty()) // While the event queue is not empty
	{
	
		tmp = eventQueue.front(); // Store the front process data into temp process
		eventQueue.pop_front(); // Pop the process from the queue
		cout << "PID: " << tmp.PID << endl; // Output the data from the popped process
		cout << "Arrival Time: " << tmp.arrivalTime << "ms" << endl;
		cout << "Finish Time: " << tmp.finishTime << "ms" << endl;
		cout << "Wait Time: " << tmp.waitTime << "ms" << endl;
		cout << "Actual Burst Time: " << tmp.burstTime << "ms" << endl; 
		cout << "Predicted Burst Time: " << tmp.nextBurst << "ms" << endl;
		cout << "I/O Burst Time: " << tmp.ioBurst << "ms" <<endl;
		cout << "Turnaround Time: " << tmp.finishTime << "ms" << endl;
		cout << "\n" << endl;
		
	}
	
	cout << "\n" << endl;
	cout << "-------------------------------------------------" << endl;
	cout << "Throughput is: " << throughput << endl; // Display the throughput calculation
	cout << "Average wait time is: " << avgWait << endl; // Display the average wait time
	cout << "Average turnaround time is: " << avgTurn << endl; // Display the average turnaround
	cout << "-------------------------------------------------" << endl;
	cout << "\n" << endl;

} // end of runProcesses

//=================================================================

void event::calcAnalysis()
{

	float tTime = 0.0; // create a local variable to hold total time for throughput
	float wTime = 0.0; // create a local variable to hold total time for wait time
	float uTime = 0.0; // create a local variable to hold total time for turnaround

	for(int i = 0; i <= eventQueue.size(); i++) 
	{
		
		tTime = (eventQueue[i].arrivalTime + tTime); // set tTime to equal tTime + current
							     // process time
	}

	throughput = (eventQueue.size()/tTime); // store number of process in queue / time into
					       // throughput variable
	
	for(int j = 0; j <= eventQueue.size(); j++)
	{
		
		wTime = (eventQueue[j].waitTime + wTime); // set wTime to equal wTime + current
							  // process time
	}
	
	avgWait = (wTime/eventQueue.size()); // store wait time / process in queue into average
					     // wait variable
					     
	for(int k = 0; k <= eventQueue.size(); k++)
	{
	
		uTime = (eventQueue[k].finishTime + uTime); // set uTime to equal uTime + current
							    // process time
	}
	
	avgTurn = (uTime/eventQueue.size()); // store turnaround time / process in queue into average
					     // turnaround variable
	
	
} // end of calcAnalysis

//=================================================================
