#include "CommunicationNetwork.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>

using namespace std;

CommunicationNetwork::CommunicationNetwork()
{
    head = NULL;
    tail = NULL;
}

CommunicationNetwork::~CommunicationNetwork()
{
    //dtor
    deleteNetwork();
}
void CommunicationNetwork::addCity(string previousCity, string cityName){
    //add a new node to the network after the previousCity
    // if we are passed an empty list, just create a new head node, and return
    if(previousCity == "First")
    {
        //case where it's a new head city
        City *c = new City(cityName, head, NULL, "", 0);
        head = c;
    }else{
        //create a tmp pointer for moving through list
        City * tmp = head;

        // move until we land on "previous" , or the next node is NULL
        while(tmp->cityName != previousCity && tmp->next != NULL)
        {
            tmp = tmp->next;
        }

        // create a new node, with next equal to city after "previous"
        City * newCity = new City(cityName, tmp->next, tmp, "", 0);

        // point tmp to this new node we inserted.
        tmp->next = newCity;
    }


}
void CommunicationNetwork::deleteCity(string cityNameIn){
    //find city and delete it
    City *delCity = NULL;
    City *searchCity = head;
    bool found = false;
    while(!found and searchCity != NULL){
        if(searchCity->cityName == cityNameIn){
            found = true;
        }else{
            searchCity = searchCity->next;
        }

    }
    if(found == true){
        if(searchCity == head){
            delCity = head;
            head = head->next;
            head->previous = NULL;
            delete delCity;
        }
        else if (searchCity->next == NULL){
            delCity = searchCity;
            searchCity = searchCity->previous;
            searchCity -> next = delCity->next;
            delete delCity;
        }
        else{
            searchCity->previous->next = searchCity->next;
            searchCity->next->previous = searchCity->previous;
            delete searchCity;
        }

    }else{
        cout<<cityNameIn<<" not found"<<endl;
    }

}
void CommunicationNetwork::deleteNetwork(){
//delete entire network
    // tmp is used for deleting nodes
    City * tmp;

    // go through every node
    while (head != NULL)
    {
        // store the node
        tmp = head;
        // move to next node
        head = head->next;
        // delete the stored node
        cout<<"deleting "<<tmp->cityName<<endl;
        delete tmp;
    }
}

void CommunicationNetwork::buildNetwork(){
//build the network with a fixed list of cities.
//can hard code cities in this function and add them in order
    string cityArray[10] = {"Los Angeles", "Phoenix", "Denver", "Dallas", "St. Louis", "Chicago", "Atlanta", "Washington, D.C.", "New York", "Boston"};
    int numCities = 10;
    City *cityAdded;
    City *currentCity;
    for(int i = 0; i < numCities; i++){
        if(head == NULL){
            cityAdded = new City(cityArray[i], NULL, NULL, "NULL", 0);
            currentCity = cityAdded;
            head = currentCity;
        }else{
            cityAdded = new City(cityArray[i], NULL, currentCity, "NULL", 0);
            currentCity->next = cityAdded;
            currentCity = cityAdded;

        }
    }
    tail = currentCity;
}

void CommunicationNetwork::transmitMsg(string message){
//filename is argument to function
//start at head of list and set message for first node to word read from file
    stringstream ss(message);
    string word;
    if(head == NULL){
        cout<<"Empty list"<<endl;
        return;
    }
    City *sender = head;
    // read through every line , transmit message
    //for(int i = 0; i<str.length(); i++)
    while(ss>>word)
    {
        sender->message = word;
        //sender->counter = sender->counter + 1;
        cout<<sender->cityName<<" received "<<sender->message<<endl;
        while(sender->next != NULL){
            sender->next->message = word;
            cout<<sender->next->cityName<<" received "<<sender->next->message<<endl;
            sender->message = "";
        sender->counter = sender->counter + 1;
        //cout<<sender->cityName<< ": "<<sender->counter;
            sender = sender->next;
        }
        sender->counter = sender->counter + 1;
        //cout<<sender->cityName<< ": "<<sender->counter;
        //Rhonda: back the other direction starting here
        sender = tail;

        while(sender->previous != NULL){
            sender->previous->message = word;
            cout<<sender->previous->cityName<<" received "<<sender->previous->message<<endl;
            sender->message="";
            sender = sender->previous;
        }

        sender = head;
    }
    // close the file


}

void CommunicationNetwork::transmitAB(std::string cityStart, std::string cityEnd, std::string messageAB){
/*
when this function is called it transmits the message from A to B to A. Not only from A to B.
You may want to consider changing the function or description as to not be misleading.
*/

//filename is argument to function
//start at head of list and set message for first node to word read from file
    stringstream ss(messageAB);
    string word;
    int counter1 = 0;
    int counter2 = 0;
   // ifstream inStream; // stream for reading in file
   // inStream.open("messageIn.txt");
   // string msg;
    if(head == NULL){
        cout<<"Empty list"<<endl;
        return;
    }
    City *sender = head;
    // read through every line , transmit message
    while (sender->cityName != cityStart){
        counter1++;
        sender = sender->next;
    }
    cout<<counter1<<endl;

    City *starting = sender;
   // cout<<starting->cityName<<endl;
    sender = head;

    while(sender->cityName!= cityEnd){
        counter2++;
        sender = sender->next;
    }
    cout<<counter2<<endl;
    City *ending = sender;
   // cout<<ending->cityName<<endl;
    sender = starting;

while (ss>>word)
    {
        if(counter1 < counter2){
        while(sender != ending){
            sender->message = word;
            cout<<sender->cityName<< " received "<< sender->message<<endl;
            sender->counter = sender->counter + 1;
            sender = sender->next;
        }
        sender->counter = sender->counter + 1;
        sender->message = word;
        cout<<sender->cityName<< " received "<< sender->message<<endl;
        //cout<<sender->cityName<< " received "<< sender->message<<endl;
        sender = sender->previous;

        while(sender != starting){
            sender->message = word;
            cout<<sender->cityName<< " received "<< sender->message<<endl;
            sender = sender->previous;
        }
        sender->message = word;
        cout<<sender->cityName<< " received "<< sender->message<<endl;
        }
        else{
            while(sender != ending){
            sender->message = word;
            sender->counter = sender->counter + 1;
            cout<<sender->cityName<< " received "<< sender->message<<endl;
            sender = sender->previous;

        }
        sender->counter = sender->counter + 1;
        sender->message = word;
        cout<<sender->cityName<< " received "<< sender->message<<endl;
       // cout<<sender->cityName<< " received "<< sender->message<<endl;
        sender = sender->next;

        while(sender != starting){
            sender->message = word;
            cout<<sender->cityName<< " received "<< sender->message<<endl;
            sender = sender->next;
        }
        sender->message = word;
        cout<<sender->cityName<< " received "<< sender->message<<endl;
        }
}
}

void CommunicationNetwork::cityDistance(std::string city1, std::string city2){
    int index1 = 0;
    int index2 = 0;
    City *tmp = head;
    while (tmp->cityName != city1){
        index1++;
        tmp = tmp->next;
    }
    //cout<<"printing: "<<index1<<endl;
    tmp = head;

    while (tmp->cityName != city2){
        index2++;
        tmp = tmp->next;
    }
    //cout<<"printing: "<<index2<<endl;
    int distance =  abs(index1-index2);
    cout<<"There are " << distance << " cities from "<< city1 << " to " << city2<<"."<<endl<<endl;
}


void CommunicationNetwork::countMessages(){
    City *sender = head;
    while (sender != NULL){
        cout<< sender->cityName<< ": "<<sender->counter<<endl;
        sender = sender -> next;
    }
}

void CommunicationNetwork::printNetwork(){
//traverse network, printing name of each city
/*prints the current list nicely*/
    cout << "===CURRENT PATH===" << endl;

    // If the head is NULL
    if (head == NULL)
        cout << "NULL" << endl;

    // Otherwise print each node, and then a NULL
    else
    {
        City *current = head;

        cout<<"NULL <- ";

        while (current->next != NULL)
        {
            cout << current->cityName << " <-> ";
            current = current->next;
        }
        cout << current->cityName << " -> ";
        cout << "NULL" << endl;
    }

    cout << "==================" << endl;
}

void CommunicationNetwork::deleteMessage(){


    City *current = head;
    //cout<<current->message<<endl;
    while (current->message == "NULL"){
            //cout<<current->message<<endl;
        current = current->next;
    }

    while(current->next != NULL){
        current->message = "NULL";
        //cout<<current->message<<endl;
        current = current->next;

    }
    cout<<"Message has been deleted"<<endl;
    
}
