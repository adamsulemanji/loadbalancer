/**
 * @file
 * @brief LoadBalancer class implementation.
 * 
 * * All comments written by ChatGPT.
 * * All code refactored by ChatGPT. 
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <chrono>
#include <random>
#include "WebServer.cpp"
using namespace std;

/**
 * @class LoadBalancer
 * @brief Load balancer class
 *
 * This class represents a load balancer that distributes incoming requests to a
 * group of web servers.
 */
class LoadBalancer {
    private:
        int numServers;  ///< number of servers
        int clockCycleTime;  ///< clock cycle time
        int maxSize = 500;  ///< max size of the requests
        std::queue<Request*> requests;  ///< queue of requests
        std::vector<WebServer*> servers;  ///< vector of servers
        int iteration = 0;  ///< iteration counter

    public:

        /**
         * @brief Constructor
         * @param numServers Number of servers
         * @param clockCycleTime Clock cycle time
         * @param maxSize Max size of the requests
         *
         * Creates a new LoadBalancer object with the specified number of servers,
         * clock cycle time, and max size of requests. It also creates the servers
         * and fills the queue with requests.
         * 
         * @code
         * LoadBalancer(int numServers, int clockCycleTime, int maxSize) {
            std::cout << "LoadBalancer created" << std::endl;
            this->numServers = numServers;
            this->clockCycleTime = clockCycleTime;
            this->maxSize = maxSize;

            // create the servers
            for (int i = 0; i < numServers; i++) {
                servers.push_back(new WebServer());
            }

            fillQueue();
            std::cout << "The queue is filled. All WebServers have been created." << std::endl;
            std::cout << "Queue size: " << requests.size() << std::endl;

            run();
        }
        @endcode
         */
        LoadBalancer(int numServers, int clockCycleTime, int maxSize) {
            std::cout << "A Load Balancer has been created" << std::endl;
            this->numServers = numServers;
            this->clockCycleTime = clockCycleTime;
            this->maxSize = maxSize;

            // create the servers
            for (int i = 0; i < numServers; i++) {
                servers.push_back(new WebServer());
            }

            fillQueue();
            std::cout << "The queue is filled. All WebServers have been created." << std::endl;
            std::cout << "Queue size: " << requests.size() << std::endl;
            std::cout << std::endl;

            run();
        }

        /**
         * @brief Fills the queue with requests
         *
         * This function adds 20 requests for each server to the queue.
         * 
         * @code
         * void fillQueue() {
            for (int i = 0; i < 20 * numServers; i++) {
                requests.push(new Request(maxSize));
            }
        }
        @endcode
         */
        void fillQueue() {
            for (int i = 0; i < 20 * numServers; i++) {
                requests.push(new Request(maxSize));
            }
        }

        /**
         * @brief Prints the status of the servers
         *
         * This function prints the status of each server in the server list.
         * 
         * @code
         * void printServerStatus() {
            for (int i = 0; i < numServers; i++) {
                servers[i]->print();
            }
            std::cout << std::endl;
        }
        @endcode
         */
        void printServerStatus() {
            for (int i = 0; i < numServers; i++) {
                servers[i]->print();
            }
            std::cout << std::endl;
        }

        /**
         * @brief Runs the load balancer
         *
         * This function runs the load balancer for the specified number of clock cycles.
         * It processes requests and updates the status of the servers during each clock cycle.
         * 
         * ChatGPT was used when writing this function.
         * 
         * @code
         * void run() {
            for (int i = 0; i < clockCycleTime; ++i) {
                * Written with ChatGPT *
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_real_distribution<> dis(0, 1);
                if (dis(gen) < .2) {
                    requests.push(new Request(maxSize));
                }
                * End of ChatGPT code*
                for (int j = 0; j < numServers; ++j) {
                    if (requests.empty()) {
                                break;
                    }
                    servers[j]->updateRequestTime(servers[j]->request_time - 1);
                    if (servers[j]->isAvailable()) {
                        if (i != 0) {
                            servers[j]->PrintAvailable(i, j+1);
                        }
                        Request* request = requests.front();
                        requests.pop();
                        servers[j]->updateRequest(request);
                    }
                }

                if (i == 0 || i == clockCycleTime - 1) {
                    std::cout << requests.size() << " requests to process" << std::endl;
                }
            }
        }
         * 
        @endcode
         */
        void run() {
            for (int i = 0; i < clockCycleTime; ++i) {
                /* Written with ChatGPT */
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_real_distribution<> dis(0, 1);
                if (dis(gen) < .2) {
                    requests.push(new Request(maxSize));
                }
                /* End of ChatGPT code */
                for (int j = 0; j < numServers; ++j) {
                    if (requests.empty()) {
                                break;
                    }
                    servers[j]->updateRequestTime(servers[j]->request_time - 1);
                    if (servers[j]->isAvailable()) {
                        if (i != 0) {
                            servers[j]->PrintAvailable(i, j+1);
                        }
                        Request* request = requests.front();
                        requests.pop();
                        servers[j]->updateRequest(request);
                    }
                }

                if (i == 0 || i == clockCycleTime - 1) {
                    std::cout << requests.size() << " requests to process" << std::endl;
                }
            }
        }
};