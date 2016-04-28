// ==========================================
// Filename: Assignment3Solution.cpp
// Author: Matt Bubernak and Rhonda Hoenigman
// Date: 1/29/2015, 1/31/2016
// Description: Linked List Fun
// ==========================================

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include "CommunicationNetwork.h"

using namespace std;

void displayMenu();
//void sendMessagesFromFile(city * sender, city * receiver);

// main expects 1 argument, filename
int main(int argc, char* argv[])
{
    // indicates the user is ready to leave the program
    int counter = 0;
    bool quit = false;
    int input = 0;
    CommunicationNetwork cn;

    // loop until the user quits
    while (quit != true)
    {
        displayMenu();
        cin >> input;

        // used for user input
        string cityNew;
        string cityPrevious;
        string message;
        string city1;
        string city2;
        string cityStar;
        string cityEn;
        string messageIn;
        string messageAB;

        //clear out cin
        cin.clear();
        cin.ignore(10000,'\n');

        switch (input)
        {
            // print all nodes
            case 1:
                //rebuild network
                cn.buildNetwork();
                cn.printNetwork();
                //head = loadDefaultSetup(head);
                //printPath(head);
                break;
            case 2:
                cn.printNetwork();
                //printPath(head);
                break;
            case 3:
                //transmit message is read in word from file
                //send first word through all cities
                //using transmitMsg function to pass between two cities
                //when message reaches the last city, read next word from file and repeat
                //all of this should happen in the transmitMsg function
                cout<<"Message: "<<endl;
                getline(cin, messageIn);
                cn.transmitMsg(messageIn);

                //transmitMsg(head);
                break;

            case 4:
                //transmit from A to B

                cout << "Enter starting city: " << endl;
                getline(cin,cityStar);
                cout << "Enter final city: " << endl;
                getline(cin,cityEn);
                cout<<"Message: "<<endl;
                getline(cin, messageAB);
            cn.transmitAB(cityStar,cityEn, messageAB);
            break;

            case 5:
                cn.countMessages();
                break;

            case 6:
                //delete message
                cn.deleteMessage();
                break;

            case 7:
                cout << "Enter a city name: " << endl;
                getline(cin,cityNew);
                cout << "Enter a previous city name: " << endl;
                getline(cin,cityPrevious);
                // add the new node
                cn.addCity(cityPrevious, cityNew);
                //head = addCity(head,tmp,city1, false);
                break;

            // delete city
            case 8:
                cout << "Enter a city name: " << endl;
                getline(cin,city1);
                cn.deleteCity(city1);
                break;

            //distance between cities
            case 9:

                cout << "Enter first city " << endl;
                getline(cin,city1);
                cout << "Enter second city: " << endl;
                getline(cin,city2);
                cn.cityDistance(city1,city2);
            break;




            // delete network
            case 10:

                cn.deleteNetwork();
                //cout << "Deleted network" << endl;
                break;
            // quit
            case 11:
                cout << "Goodbye!" << endl;
                quit = true;
                break;

            // invalid input
            default:
                cout << "Invalid Input" << endl;
                cin.clear();
                cin.ignore(10000,'\n');
                break;
        }
    }

    // cleanup list before return.
//    deleteEntireNetwork(head);
    return 0;

}

/*displays a menu with options: add city, delete city, transmit coast-coast,
clear network, quit*/
void displayMenu()
{
    cout << "======Main Menu======" << endl;
    cout << "1. Build Network" << endl;
    cout << "2. Print Network Path" << endl;
    cout << "3. Transmit Message Coast-To-Coast-To-Coast" << endl;
    cout << "4. Transmit Message from City A to City B" << endl;
    cout << "5. Total Number of Words Transmitted" << endl;
    cout << "6. Delete Message" << endl;
    cout << "7. Add City" << endl;
    cout << "8. Delete City" << endl;
    cout << "9. Distance Between Cities" << endl;
    cout << "10. Clear Network" << endl;
    cout << "11. Quit" << endl;
    return;
}




