/**
 * @file
 * @brief WebServer class implementation
 * 
 * * All comments written by ChatGPT
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <chrono>
#include <random>
#include "Request.cpp"
using namespace std;

/**
 * @class WebServer
 * @brief Web server class
 *
 * This class represents a web server that processes incoming requests and sends responses.
 */
class WebServer {

    public:
        float request_time = 0;  ///< request processing time
        Request* request = nullptr; ///< pointer to the current request being processed

        /**
         * @brief Constructor
         *
         * Creates a new WebServer object.
         * 
         * @code
         * WebServer() {}
        @endcode
         */
        WebServer() {}

        /**
         * @brief Updates the request processing time
         * @param request_time Request processing time
         *
         * This function updates the request processing time of the web server.
         * 
         * @code
         * void updateRequestTime(float request_time) {
            this->request_time = request_time;
        }
        @endcode
         */    
        void updateRequestTime(float request_time) {
            this->request_time = request_time;
        }

        /**
         * @brief Check if the web server is available
         * @return True if the web server is available, false otherwise
         *
         * This function returns true if the request processing time is less than or equal to 0,
         * indicating that the web server is available to process a new request. Otherwise, it returns false.
         * 
         * @code
         * bool isAvailable() {
            return request_time <= 0;
        }
         * @endcode
         */
        bool isAvailable() {
            return request_time <= 0;
        }

        /**
         * @brief Prints a message indicating that the web server has processed a request
         * @param time Current clock cycle time
         * @param server_num Web server number
         *
         * This function prints a message indicating that the web server has processed a request at the
         * specified clock cycle time and server number.
         * 
         * @code 
         * void PrintAvailable(int time, int server_num) {
            std::cout << "At clock cycle " << time << " and server number " << server_num << " processed request from " << request->ip_in << " to " << request->ip_out << std::endl;
        }
         * @endcode
         * 
         */
        void PrintAvailable(int time, int server_num) {
            std::cout << "At clock cycle " << time << " and server number " << server_num << " processed request from " << request->ip_in << " to " << request->ip_out << std::endl;
        }

        /**
         * @brief Updates the current request being processed
         * @param request Pointer to the request
         *
         * This function updates the current request being processed by the web server and sets the
         * request processing time to the number of clock cycles required to process the request.
         * 
         * @code
         * void updateRequest(Request* request) {
            this->request = request;
            this->request_time = request->num_clock_cycles;
        }
         * @endcode
         * 
         */
        void updateRequest(Request* request) {
            this->request = request;
            this->request_time = request->num_clock_cycles;
        }

        /**
         * @brief Prints the status of the web server
         *
         * This function prints the request processing time and the incoming and outgoing IP addresses of
         * the current request being processed by the web server.
         * @code
         * void print() {
            std::cout << "Request processing time: " << request_time << std::endl;
            if (request != nullptr) {
                std::cout << "Incoming request IP: " << request->ip_in << std::endl;
                std::cout << "Outgoing response IP: " << request->ip_out << std::endl << std::endl;
            }
        }
         * @endcode
         * 
         */
        void print() {
            std::cout << "Request processing time: " << request_time << std::endl;
            if (request != nullptr) {
                std::cout << "Incoming request IP: " << request->ip_in << std::endl;
                std::cout << "Outgoing response IP: " << request->ip_out << std::endl << std::endl;
            }
        }
};

