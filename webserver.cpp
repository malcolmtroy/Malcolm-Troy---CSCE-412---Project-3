#include "webserver.h"

Webserver::Webserver() {
    this->available = true;
    this->processTimeRemaining = 0;
}

void Webserver::recieveRequest(Request reqW) {
    this->req = reqW;
    available = false;
    processTimeRemaining = reqW.getTime();
}

void Webserver::processRequest() {
    processTimeRemaining--;
    if (processTimeRemaining == 0) {
        available = true;
    }
}

void Webserver::setAvailable(bool availableW) {
    this->available = availableW;
}

bool Webserver::getAvailable() {
    return this->available;
}

void Webserver::setProcessTimeRemaining(int processTimeRemainingW) {
    this->processTimeRemaining = processTimeRemainingW;
}

int Webserver::getProcessTimeRemaining() {
    return this->processTimeRemaining;
}