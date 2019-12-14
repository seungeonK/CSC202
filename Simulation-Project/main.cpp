#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cmath>
#include "simulation.h"

using namespace std;
void runSimulation(int&, int&, int&, int&);

int main() 
{
  int simulationTime, numOfServers, transactionTime, timeBetweenCustomerArrival;
  cout << "Enter the simulation time: ";
  cin >> simulationTime;
  numOfServers = 1;
  cout << "Enter the transaction Time: ";
  cin >> transactionTime;
  cout << "Enter the time between customer arrival: ";
  cin >> timeBetweenCustomerArrival;

  runSimulation(simulationTime, numOfServers, transactionTime, timeBetweenCustomerArrival);
  return 0;
}

void runSimulation(int& sTime, int& numOfServers, int& transactionTime, int& timeBetwCArrival)
{
  
  double prob = exp(-1.0/timeBetwCArrival); //The probability that no event occurs at a given time.

  double totalCustomers = 0;
  int remainingCustomers = 0;
  int completedCustomers = 0;
  int currentTime = 0;
  double totalWaitTime = 0;

  serverListType server;//create one server.
  waitingCustomerQueueType queue;//create a queue


  for (int clock = 1; clock <= sTime; clock++)
  {
    double randomNum; 
    randomNum = (rand() % 100) / 100.0; //a function to generate a randome number based on a seed. any number between 0 to 1.
    server.updateServers(cout);// update the server list to decrement the transaction time of each busy server by one time unit.

    if(!queue.isEmptyQueue())
    {
      queue.updateWaitingQueue();
    }

    if(randomNum > prob)// if the random number is greater,
    {
      customerType customer(totalCustomers, clock);// the customer has arrived.
      queue.addQueue(customer); // make that customer to go in the queue.
      totalCustomers++;
      remainingCustomers++;
      //cout << totalCustomers << endl;
    }
    
    if(server.getFreeServerID() != -1)// if the server is free
    {
     
      if(!queue.isEmptyQueue())
      {
        customerType frontCustomer = queue.front();
        int freeServerId = server.getFreeServerID();
        server.setServerBusy(freeServerId, frontCustomer, transactionTime);
        //make a server busy.
        totalWaitTime += queue.front().getWaitingTime();
        queue.deleteQueue();//delete the front customer
        
        remainingCustomers--;
        completedCustomers++;
      }
    } 
  }


  cout << "The Number of customers left in the queue: " << remainingCustomers << endl;
  cout << "The Number of customers that arrived " << totalCustomers << endl;
  cout << "The number of customers who completed a transaction " << completedCustomers << endl;
  cout << "The average time for customer in the queue " << totalWaitTime/totalCustomers << endl;
}

