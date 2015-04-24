//=========================================================================
//
//  Author: Ryan Miller
//  Date: 03/02/2014
//  Course: CS443 OS
//  Assignment 2
//
//  Summary: The following program prompts a command line and tracks history 
//  Assumptions:
//  Special Instructions:
//
//=========================================================================

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>

#define MAX_ARGS 10
#define MAXLINE 80

int histCount;
char history[10][20]; // array to contain history commands
char *var; // used in runHist function

//========================================================================

//  PURPOSE: To display the command prompt
void shellPrompt()
{

  printf("RM> "); // command line prompt

} 

//========================================================================

//  PURPOSE: To insert null characters into args and also to increment array pointers
int parse(char *input, char **args, int argc)
{
  while(*input != '\0') // while not equal to null
    {
      if(*input == ' ' || *input == '\n') // and if equal to blank char or new line
	*input = '\0'; // set equal to null
        *args = input; // pointer points to input
	printf("ARGS: %s\n", *args);
	*args++;
	while(*input !='\0' && *input != ' ' && *input != '\n') // while not equal to null, blank char, or new line
	  input++;
	  argc++;
    }

  *args = '\0'; // set equal to null

  return argc -1;

}

//========================================================================

//  PURPOSE: To call fork() function and check pids
void runProcess(char **args)
{

  pid_t pid = fork();
  int status; // set status

  if (pid < 0)
    {
      exit(1);
    }

  else if(pid == 0)
    {
      system(args[0]); // system call to args
      exit(1);
    }

  else
    {
      waitpid(-1, &status, 0); // if status is set to &, wait
    }

}

//============================================================================

//  PURPOSE: To keep track of commands entered
void setHist(char arg[])
{

  int i = 0;

  while(history[i][0] != '\0') // while position in history array is not equal to null
    {
      i++;
    }
  strcpy(history[i], arg); // copy arg entered into array position
  histCount++;

}

//===========================================================================

//  PURPOSE: To display history commands that have been entered
void dispHist()
{

  int i = 0;

  while(history[i][0] != '\0') // while position in history array is not equal to null
    {
      printf("%d %s\n", i+1, *(history + i)); // display elements within array slot
      i++;
    }

}

//===========================================================================


//  PURPOSE: When command !! is entered to run previous command and if !(and hist number) is entered
//           to run the selected history command
//void runHist(char arg[])
//{

//char *test = arg;
//char v = arg[1];

//int var2 = v - '0';
//for(int i = 0; i < histCount; i++)
//{
//history[i][0];

//if(i == var2)
//{
//char *var2;

//strcpy(var, history[i]);
//printf("this is what is stored: ");
//printf("%s", var);
//printf("\n");

//}

//system(var);

//}

//}

//===================================================================================

int main(void)
{

  char *args[MAX_ARGS];
  int run = 1, i;
  char s[MAX_ARGS];
  bool wait = true;

  printf("Programmed by: Ryan Miller\n");

  while(run) //while running
    {

      shellPrompt(); // prompt the command line
      fflush(stdout); // standard out
      fgets(s, MAXLINE, stdin); // read in command entered and store in s, make sure characters do not exceed MAXLINE
      setHist(s); // set command to history
      s[strlen(s)-1] = '\0'; // set last char of string equal to null

      for(int j = 0; j < strlen(s); ++j) // until j hits length of string s
	if(j == (strlen(s)-1)) 
	  if(s[j] == '&') // and j's character location of s is equal to &
	    wait = false; // wait for process

      *args = s; // point to s

      if(strcmp(*args, "history") == 0) // if command entered is equal to history
	dispHist(); // call dispHist function to display history

      else 
	{
	  runProcess(args); // call function to fork
	}

    }

      return 0;

}
    
//==================================================================================
