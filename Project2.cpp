#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include "LoadBalancer.cpp"


int main () {
    std::cout << "******** Welcome to the Load Balancer Program! ********" << std::endl;

    std::cout << "Please enter the number of servers: ";
    int numServers;
    std::cin >> numServers;

    std::cout << "Please enter the clock cycle time: ";
    int clockCycleTime;
    std::cin >> clockCycleTime;

    std::cout << "Please enter the max size of the requests: ";
    int maxSize;
    std::cin >> maxSize;

    LoadBalancer* lb = new LoadBalancer(numServers, clockCycleTime, maxSize);

    return 0;
}
