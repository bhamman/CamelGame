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
void takeDrink(int &hydrate, int &hydro);
void testThirst(int hydro, bool &close);
void testCamel(int camelRest, bool &close, string camName);
void testNatives(int badGuyDist, int dist, bool &close);
void testDistTrav(int dist, bool &close);
void oasis(int &fillCanteen, int &hydrate, int &camelRest);

int main()
{
    srand(time(0));
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
            case 'A': takeDrink(canteenDrinks, thirst);
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

        testThirst(thirst, done);
        testCamel(camelSleep, done, name);
        testNatives(nativesDist, traveled, done);
        testDistTrav(traveled, done);
        oasis(canteenDrinks, thirst, camelSleep);

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

void takeDrink(int &hydrate, int &hydro)
{
    if(hydrate > 0)
    {
        hydrate--;
        hydro = 0;
    }
    else
    {
         cout << "There is no water left in the canteen!" << endl;
    }// end if(hydrate > 0)

    return;
}// end takeDrink(int &hydrate, int &hydro)

void testThirst(int hydro, bool &close)
{
    if(hydro > 4 && hydro <= 6)
    {
        cout << "You are going to die of thirst!!" << endl;
    }// end if(hydro > 4 && hydro <= 6)
    else if(hydro > 6)
    {
        cout << "GAME OVER: You died of thirst." << endl;
        close = true;
    }// end else if(hydro > 6)

    return;
}// end testThirst(int hydro, bool &close)

void testCamel(int camelRest, bool &close, string camName)
{
    if(camelRest > 5 && camelRest <= 8)
    {
        cout << camName << " the camel is tired" << endl;
    }// end if(camelRest > 5 && camelRest <= 8)
    else if(camelRest > 8)
    {
        cout << "GAME OVER: " << camName << " the camel has died" << endl;
        close = true;
    }// end else if(camelRest > 8)

    return;
}// end testCamel(int camelRest, bool &close, string camName)

void testNatives(int badGuyDist, int dist, bool &close)
{
    if(badGuyDist >= dist)
    {
        cout << "GAME OVER: The natives have caught you." << endl;
        close = true;
    }// end if(badGuyDist >= dist)
    else if(dist - badGuyDist < 15)
    {
        cout << "The natives are getting close!" << endl;
    }// end else if(dist - badGuyDist < 15)

    return;
}// end testNatives(int badGuyDist, int dist, bool &close)

void testDistTrav(int dist, bool &close)
{
    if(dist >= 200)
    {
        cout << "Congratulation!! You made it across the desert!" << endl;
        close = true;
    }// end if(dist >= 200)

    return;
}// end testDistTrav(int dist, bool &close)

void oasis(int &fillCanteen, int &hydrate, int &camelRest)
{

    if(randomNumber(1, 20) == 6)
    {
        cout << "You found an oasis! Be sure to fill your canteen..." << endl;
        fillCanteen++;
        hydrate = 0;
        camelRest = 0;
    }// end if(randomNumber(1, 20) == 6)

    return;
}// end oasis(int &fillCanteen, int &hydrate, int &camelRest)
