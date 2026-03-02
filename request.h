#ifndef REQUEST_H
#define REQUEST_H

#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

/**
 * @class Request
 * @brief Represents a network request with randomized IP addresses and processing time.
 */
class Request {
private:
    string ipIn;
    string ipOut;
    int time;
    char jobType;

public:
    /**
     * @brief Default constructor that initializes a request with random data.
     */
    Request();

    /**
     * @brief Generates a random IPv4 address.
     * @return A string in the format "XXX.XXX.XXX.XXX".
     */
    string generateRandomIpAddress();

    /**
     * @brief Generates a random integer for processing duration.
     * @return An integer between 1 and 100.
     */
    int generateRandomTime();

    /**
     * @brief Randomly assigns a 'P' or 'S' job type.
     * @return A character representing the job type.
     */
    char generateRandomJobType();

    void setIpIn(string ipInReq);
    string getIpIn();
    
    void setIpOut(string ipOutReq);
    string getIpOut();
    
    void setTime(int timeReq);
    int getTime();
    
    void setJobType(char jobTypeReq);
    char getJobType();
};

#endif