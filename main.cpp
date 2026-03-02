/**
 * @file main.cpp
 * @brief Main execution file for the Load Balancer simulation.
 */
#include <iostream>
#include "request.h"
#include "load_balancer.h"
#include "webserver.h"

using namespace std;

/**
 * @brief Entry point that takes user parameters and starts the simulation.
 * @return 0 on completion.
 */
int main() {
    
    int numServers;
    int runtime;
    bool validInput1 = false;
    bool validInput2 = false;

    while (validInput1 == false || validInput2 == false) {
        cout << "Input the number of serves desired: ";
        cin >> numServers;

        if (cin.fail()) {
            cout << "Invalid Server Input! (Please use numbers only)" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        else {
            validInput1 = true;
        }
        
        cout << "Input the runtime length desired: ";
        cin >> runtime;

        if (cin.fail()) {
            cout << "Invalid Runtime Input! (Please use numbers only)" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        else {
            validInput2 = true;
        }
    }
    
    LoadBalancer lb;

    for (int i = 0; i < numServers; i++) {
        Webserver ws;
        lb.addServer(ws);
    }

     int initialRequests = numServers * 100;

    for (int i = 0; i < initialRequests; i++) {
        Request req;
        lb.enqueueRequest(req);
    }
    cout << "---------------------------------------" << endl;
    cout << "          Starting Simulation          "<< endl;
    cout << "---------------------------------------" << endl;

    lb.run(runtime, numServers);
    
    cout << "---------------------------------------" << endl;
    cout << "          Load Balancer Report         " << endl;
    cout << "---------------------------------------" << endl;
    cout << "Total Servers Started: " << numServers << endl;
    cout << "Starting Requests in Queue: " << initialRequests << endl;
    cout << "Total Servers Currently: " << lb.getServerCount() << endl;
    cout << "Total Requests Processed: " << lb.getTotalRequestsProcessed() << endl;
    cout << "Total Requests In Queue: " << lb.getQueueSize() << endl;
    cout << "Servers Added During Runtime: " << lb.getServersAdded() - numServers << endl;
    cout << "Servers Deleted During Runtime: "<< lb.getServersDeleted() << endl;
    cout << "Total Blocked IP Addresses: " << lb.getAddressesBlocked() << endl;
    cout << "Task Time Minimum: "<< lb.getTaskTimeMin() << endl;
    cout << "Task Time Maximum: " << lb.getTaskTimeMax() << endl;

    return 0;
}