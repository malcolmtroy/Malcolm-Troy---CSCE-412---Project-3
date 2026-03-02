#include "request.h"

Request::Request() {
    this->ipIn = generateRandomIpAddress();
    this->ipOut = generateRandomIpAddress();
    this->time = generateRandomTime();
    this-> jobType = generateRandomJobType();
}

string Request::generateRandomIpAddress() {
    ostringstream oss;
    oss << (rand() % 256) << "." << (rand() % 256) << "." << (rand() % 256) << "." << (rand() % 256);
    return oss.str();
}

int Request::generateRandomTime() {
    return rand() % 100 + 1;
}

char Request::generateRandomJobType() {
    return (rand() % 2 == 0) ? 'P' : 'S';
}

void Request::setIpIn(string ipInReq) {
    this->ipIn = ipInReq;
}

string Request::getIpIn() {
    return this->ipIn;
}

void Request::setIpOut(string ipOutReq) {
    this->ipOut = ipOutReq;
}

string Request::getIpOut() {
    return this->ipOut;
}

void Request::setTime(int timeReq) {
    this->time = timeReq;
}

int Request::getTime() {
    return this->time;
}

void Request::setJobType(char jobTypeReq) {
    this->jobType = jobTypeReq;
}

char Request::getJobType() {
    return this->jobType;
}