#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <chrono>
#include <random>

// include the request class
#include "Request.cpp"

using namespace std;

class WebServer {

    public:
        float request_time = 0;  ///< Request processing time
        Request* request = nullptr;

        WebServer() {
            std::cout << "WebServer created" << std::endl;
        }

    
        void updateRequestTime(float request_time) {
            this->request_time = request_time;
        }

    
        bool isAvailable() {
            return request_time <= 0;
        }

        void PrintAvailable(int time, int server_num) {
            std::cout << "At clock cycle " << time << " and server number " << server_num << " processed request from " << request->ip_in << " to " << request->ip_out << std::endl;
        }

        void updateRequest(Request* request) {
            this->request = request;
            this->request_time = request->num_clock_cycles;
        }

        void print() {
            std::cout << "Request processing time: " << request_time << std::endl;
            if (request != nullptr) {
                std::cout << "Incoming request IP: " << request->ip_in << std::endl;
                std::cout << "Outgoing response IP: " << request->ip_out << std::endl << std::endl;
            }
        }
};

