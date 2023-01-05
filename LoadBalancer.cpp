#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <chrono>
#include <random>
#include "WebServer.cpp"

using namespace std;

class LoadBalancer {
private:
    int numServers;  ///< Number of servers
    int clockCycleTime;  ///< Clock cycle time
    int maxSize = 500;  ///< Max size of the requests
    std::queue<Request*> requests;  ///< Queue of requests
    std::vector<WebServer*> servers;  ///< Vector of servers

    int iteration = 0;  ///< Iteration counter

public:
    LoadBalancer(int numServers, int clockCycleTime, int maxSize) {
        std::cout << "LoadBalancer created" << std::endl;
        this->numServers = numServers;
        this->clockCycleTime = clockCycleTime;
        this->maxSize = maxSize;

        // Create the servers
        for (int i = 0; i < numServers; i++) {
            servers.push_back(new WebServer());
        }

        fillQueue();
        cout << endl;

        run();
    }

    
    void fillQueue() {
        for (int i = 0; i < 20 * numServers; i++) {
            requests.push(new Request(maxSize));
        }
    }

    void printServerStatus() {
        for (int i = 0; i < numServers; i++) {
            servers[i]->print();
        }
        std::cout << std::endl;
    }

    
    void run() {
        for (int i = 0; i < clockCycleTime; ++i) {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_real_distribution<> dis(0, 1);
            if (dis(gen) < .2) {
                requests.push(new Request(maxSize));
            }
            
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
                std::cout << endl;
                std::cout << requests.size() << " requests to process" << std::endl;
            }
        }
    }
};