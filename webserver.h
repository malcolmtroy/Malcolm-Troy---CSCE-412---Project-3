#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <string>
#include <cstdlib>
#include <sstream>
#include "request.h"

using namespace std;

/**
 * @class Webserver
 * @brief A worker class that processes Request objects.
 */
class Webserver {
private:
    bool available;
    Request req;
    int processTimeRemaining;

public:
    /**
     * @brief Initializes a webserver to an available state.
     */
    Webserver();
    
    /**
     * @brief Assigns a request to the server and sets the processing timer.
     * @param reqW The Request to be processed.
     */
    void recieveRequest(Request reqW);

    /**
     * @brief Decrements the remaining time and marks the server available if finished.
     */
    void processRequest();

    void setAvailable(bool availableW);
    bool getAvailable();

    void setProcessTimeRemaining(int processTimeRemainingW);
    int getProcessTimeRemaining();
};

#endif