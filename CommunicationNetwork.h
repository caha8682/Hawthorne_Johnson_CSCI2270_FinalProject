#ifndef COMMUNICATIONNETWORK_H
#define COMMUNICATIONNETWORK_H
#include <iostream>
struct City{
    std::string cityName;
    std::string message;
    int counter;
    City *next;
    City *previous;

    City(){}; // default constructor

    City(std::string initName, City *initNext, City *initPrevious, std::string initMessage, int initCounter)
    {
        cityName = initName;
        next = initNext;
        previous = initPrevious;
        message = initMessage;
        counter = initCounter;
    }

};

class CommunicationNetwork
{
    public:
        CommunicationNetwork();
        ~CommunicationNetwork();
        void addCity(std::string, std::string);
        void buildNetwork();
        void transmitMsg(char *); //this is like a string
        void printNetwork();
        void deleteCity(std::string);
        void deleteNetwork();
        void countMessages();
        void transmitAB(std::string, std::string);
    protected:
    private:
        City *head;
        City *tail;
};

#endif // COMMUNICATIONNETWORK_H

