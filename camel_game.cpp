/*
Author: Becca Hamman
Created: 04/28/2017
Class: ITSY 2421 - Object Oriented Programming
Instructor: Prof  Welch
Problem description: Camel Game

Todo - Summary of Modifications:
04/28/2017 - Analyze and design

Lessons learned:


*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
using namespace std;

void printInstructions();

int main()
{
    bool done = false;

    printInstructions();

    do
    {
        cout << endl;
        switch(toupper(showMenu()))
        {
            case 'A':
            break;
            case 'B':
            break;
            case 'C':
            break;
            case 'D':
            break;
            case 'E': 
            break;
            case 'Q': cout << "Goodbye!" << endl;
                      done = true;
            break;
            default: cout << "Choice invalid! Try again: " << endl;
        }

    return 0;
}
/***************************Functions********************************/
void printInstructions()
{
    cout << "Welcome to the Camel Game!" << endl;
    cout << "You have stolen a camel to make your";
    cout <<  " way across the great Mobi desert" << endl;
    cout << "The natives want the camel back and are chasing you down!";
    cout << " Survive your desert trek and out run the natives." << endl;

    return;
}// end void printInstructions()
