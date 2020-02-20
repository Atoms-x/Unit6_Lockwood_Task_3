/*
	Teacher: Dr. Tyson McMillan, Ph.D. COSC 1436 
  STUDENT (McMillanite): Chet Lockwood
  Unit_6_Task_6
  IDE: Repl.it
*/

#include <iostream>  // Provides cout, cin, endl
#include <iomanip>
#include "accounts.h"
#include <fstream>

using namespace std;

void bubbleSort(int array[], int);
void printArray(int array[], int);
void averageTime(double array[], int);

//Main Functions ************************************************************************************************
int main() 
{
  int iterations = 0;
  double times[3]; //Time holding array
  int i = 0;

  while (iterations < 3)
  {
  //Bubble Sort ASC method per Task 2 of Unit 6 Assingment
  bubbleSort(accountBalances, maxAccounts); //call sort function
  printArray(accountBalances, maxAccounts); //print Array

  times[i] = cpuTime();

  i++;  //Iterate the array
  iterations++; //Iterate the while loop
  }
  
  cout << endl << "Time for Run 1: " << times[0] << endl;
  cout << "Time for Run 2: " << times[1] << endl;
  cout << "Time for Run 3: " << times[2] << endl;
  
  averageTime(times, 3); //Average the times

  return 0;
}

void bubbleSort(int array[], int SIZE)
{
  for (int max = SIZE - 1; max > 0; max--)
    {
      for (int index = 0; index < max; index++)
      {
        if (array[index] < array[index + 1])
        {
          swap (array [index], array[index + 1]);
        }
      }
    }
}
//Function Definitions ******************************************************************************************

//Function to print the Array
void printArray(int array[], int SIZE)
{
  ofstream inputFile;
  inputFile.open("Results.txt");

  inputFile << "\nPrinted Values in Array:\n";

  for(int i = 0; i < SIZE; i++)
    {
      inputFile << array[i] << ", ";
      //cout << array[i] << ", ";
    }

  inputFile.close();
}

//Function to calculate the average time to sort
void averageTime(double array[], int SIZE)
{
  double total = 0; //Accumulator
  double average; //Will hold the average

  for(int i = 0; i < SIZE; i++)
    total += array[i];

  average = (total / SIZE);
  
  cout << "\nAverage Time for Bubble Sort DEC: " << average;
}