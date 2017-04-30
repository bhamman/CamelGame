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
char showMenu();
void showStatus(int howFar, int drinks, int badGuys);
void nightRest(int &camelRest, int &badGuyDist, string camName);
int randomNumber(int A, int B);
void fullAhead(int &dist, int &hydro, int &camelRest, int &badGuyDist);
void moderateAhead(int &dist, int &hydro, int &camelRest, int &badGuyDist);

int main()
{
    bool done = false;
    int traveled = 0;
    int thirst = 0;
    int camelSleep = 0;
    int nativesDist = -20;
    int canteenDrinks = 2;
    string name;

    printInstructions();
    cout << "Name your camel: ";
    cin >> name;

    printInstructions();

    do
    {
        switch(toupper(showMenu()))
        {
            case 'A':
            break;
            case 'B': moderateAhead(traveled, thirst, camelSleep, nativesDist);
            break;
            case 'C': fullAhead(traveled, thirst, camelSleep, nativesDist);
            break;
            case 'D': nightRest(camelSleep, nativesDist, name);
            break;
            case 'E': showStatus(traveled, canteenDrinks, nativesDist);
            break;
            case 'Q': cout << "Goodbye!" << endl;
                      done = true;
            break;
            default: cout << "Choice invalid! Try again: " << endl;
        }

    }while(!done);

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

char showMenu()
{
    char choice;

    cout << "A. Drink from your canteen." << endl;
    cout << "B. Ahead moderate speed. " << endl;
    cout << "C. Ahead full speed." << endl;
    cout << "D. Stop for the night." << endl;
    cout << "E. Status check." << endl;
    cout << "Q. Quit." << endl;
    cin >> choice;

    return choice;
}// end showMenu()

void showStatus(int howFar, int drinks, int badGuys)
{
    cout << "Drinks left: " << drinks << endl;
    cout << "Miles traveled: " << howFar <<  endl;

    if(badGuys < 0)
    {
        cout << "The natives are " << abs(badGuys) + howFar << " miles behind." << endl;
    }
    else
    {
        cout << "The natives are " << howFar - badGuys << " miles behind." << endl;
    }// end if(badGuys < 0)
    return;
}// end showStatus(int howFar, int drinks, int badGuys)

void nightRest(int &camelRest, int &badGuyDist, string camName)
{
    cout << camName << " the camel is happy!" << endl;
    camelRest = 0;
    badGuyDist += randomNumber(7, 14);

    return;
}// end nightRest(int &camelRest, int &badGuyDist, string camName)

int randomNumber(int A, int B)
{
    int randNum = (rand() % (B - A + 1)) + A;

    return randNum;
}// end randomNumber(int A, int B)

void fullAhead(int &dist, int &hydro, int &camelRest, int &badGuyDist)
{
    int num = randomNumber(10, 20);
    cout << "You traveled " << num << " miles." << endl;
    dist += num;

    hydro++;
    camelRest += randomNumber(1, 3);
    badGuyDist += randomNumber(7, 14);

    return;
}// end fullAhead(int &dist, int &hydro, int &camelRest, int &badGuyDist)

void moderateAhead(int &dist, int &hydro, int &camelRest, int &badGuyDist)
{
    int num = randomNumber(5, 12);
    cout << "You traveled " << num << " miles." << endl;
    dist += num;

    hydro++;
    camelRest++;
    badGuyDist += randomNumber(7, 14);

    return;
}// end moderateAhead(int &dist, int &hydro, int &camelRest, int &badGuyDist)
