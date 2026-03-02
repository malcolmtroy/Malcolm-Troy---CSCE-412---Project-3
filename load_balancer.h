#ifndef LOAD_BALANCER_H
#define LOAD_BALANCER_H

#include "request.h"
#include "webserver.h"
#include <queue>
#include <vector>
#include <iostream>

/**
 * @class LoadBalancer
 * @brief Manages the server pool and request queue for the simulation.
 */
class LoadBalancer {
private:
    int runtimeRemaining;
    int serversAdded;
    int serversDeleted;
    int totalRequestsProcessed;
    queue<Request> requestQueue;
    vector<Webserver> webservers;

public:
    /**
     * @brief Initializes the LoadBalancer with zeroed counters.
     */
    LoadBalancer();

    /**
     * @brief Adds a Request to the internal queue.
     * @param reqL The Request object to enqueue.
     */
    void enqueueRequest(Request reqL);

    /**
     * @brief Adds a Webserver to the managed vector.
     * @param webL The Webserver instance to add.
     */
    void addServer(Webserver webL);

    /**
     * @brief Runs the simulation for a specified duration.
     * @details Handles randomized request generation, IP filtering, and dynamic scaling.
     * @param clockTime Total cycles to run.
     * @param startServerNum Initial count of servers.
     */
    void run(int clockTime, int startServerNum);
    
    void setRuntimeRemaining(int time);
    int getRuntimeRemaining();
    
    void setServersAdded(int count);
    int getServersAdded();

    void setServersDeleted(int count);
    int getServersDeleted();

    void setTotalRequestsProcessed(int count);
    int getTotalRequestsProcessed();
    
    /** @return Number of requests currently in the queue. */
    int getQueueSize();

    /** @return Current number of active servers. */
    int getServerCount();
};

#endif