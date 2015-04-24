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

using namespace std;

//=================================================================

struct Process
{

	int PID;
	int arrivalTime;
	int priority;
	int burstTime;
	int nextBurst;
	int ioBurst;
	int finishTime;
	int waitTime;
	
}; // end of Process

// Overload the operator in order to perfrom a specific comparison
// within the Process struct.
	
inline bool operator<(const Process& a, const Process& b)
{
	return a.priority < b.priority;
}
	
//=================================================================
