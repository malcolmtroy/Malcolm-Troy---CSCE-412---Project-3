#include "load_balancer.h"

#define MAGENTA "\033[35m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define GREEN "\033[32m"
#define BOLD_WHITE "\033[1;37m"
#define BOLD_RED "\033[1;31m"
#define RESET "\033[0m"

LoadBalancer::LoadBalancer() {
    runtimeRemaining = 0;
    serversAdded = 0;
    serversDeleted = 0;
    totalRequestsProcessed = 0;
}

void LoadBalancer::enqueueRequest(Request reqL) {
    requestQueue.push(reqL);
}

void LoadBalancer::addServer(Webserver webL) {
    webservers.push_back(webL);
    serversAdded++;
}

void LoadBalancer::run(int clockTime, int startServerNum) {
    runtimeRemaining = clockTime;

    int cooldown = 0;
    const int cooldownLimit = 20;

    int clock = 0;

    while (runtimeRemaining > 0) {

        clock++;

        if (rand() % 7 == 0) {
            Request newReq;
            string ip = newReq.getIpIn();

            if (ip.find("1.") == 0) {
                cout << MAGENTA << "[Cycle " << clock << "] BLOCKED | IP: " << ip << RESET << endl;
            }
            else {
                enqueueRequest(newReq);
                cout << YELLOW << "[Cycle " << clock << "] ADDED | IP: " << ip << " | Time: " << newReq.getTime() << " | Type: " << newReq.getJobType() << RESET << endl;
            }
        }

        for (int i = 0; i < webservers.size(); i++) {

            if (webservers[i].getAvailable()
                && !requestQueue.empty()) {

                Request req = requestQueue.front();
                requestQueue.pop();

                webservers[i].recieveRequest(req);

                cout << CYAN << "[Cycle " << clock << "] ASSIGNED | Server " << i << " <- IP: " << req.getIpIn() << RESET << endl;
            }
        }

        for (int i = 0; i < webservers.size(); i++) {
            if (!webservers[i].getAvailable()) {
                webservers[i].processRequest();
                
                if (webservers[i].getAvailable()) {
                    totalRequestsProcessed++;
                    cout << GREEN << "[Cycle " << clock << "] COMPLETED | Server " << i << RESET << endl;
                }
            }
        }

        if (cooldown > 0) {
            cooldown--;
        }
        else {

            int currentServers = webservers.size();
            int queueSize = requestQueue.size();

            if (queueSize > 80 * currentServers) {

                Webserver ws;
                addServer(ws);
                serversAdded++;
                cooldown = cooldownLimit;

                cout << BOLD_WHITE << "[Cycle " << clock << "] SCALING UP | Server Added" << RESET << endl;
            }
            else if (queueSize < 50 * currentServers && currentServers > 1) {
                webservers.pop_back();
                serversDeleted++;
                cooldown = cooldownLimit;
                cout << BOLD_RED << "[Cycle " << clock << "] SCALING DOWN | Server Removed" << RESET << endl;
            }
        }
        runtimeRemaining--;
    }
}

void LoadBalancer::setRuntimeRemaining(int time) {
    runtimeRemaining = time;
}

int LoadBalancer::getRuntimeRemaining() {
    return runtimeRemaining;
}

void LoadBalancer::setServersAdded(int count) {
    serversAdded = count;
}

int LoadBalancer::getServersAdded() {
    return serversAdded;
}

void LoadBalancer::setServersDeleted(int count) {
    serversDeleted = count;
}

int LoadBalancer::getServersDeleted() {
    return serversDeleted;
}

void LoadBalancer::setTotalRequestsProcessed(int count) {
    totalRequestsProcessed = count;
}

int LoadBalancer::getTotalRequestsProcessed() {
    return totalRequestsProcessed;
}

int LoadBalancer::getQueueSize() {
    return requestQueue.size();
}

int LoadBalancer::getServerCount() {
    return webservers.size();
}
