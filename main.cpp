/**
 * @file
 * @brief Main function implementation
 * 
 * * All comments written by ChatGPT
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include "LoadBalancer.cpp"

/**
 * @mainpage CSCE 412 Load Balancer Project
 * Created by: Adam Sulemanji & Nikki Rad
 * 
 * @section Load Balancer Class: 
 * LoadBalancer.LoadBalancer
 * 
 * @section Request Class: 
 * Request.Request
 * 
 * @section Web Server Class: 
 * WebServer.WebServer
 */

/**
 * @brief Main function
 * @return 0 on success, non-zero on error
 *
 * This function is the entry point of the program. It prompts the user to input the number of servers,
 * clock cycle time, and max size of requests, and then creates a LoadBalancer object and runs it.
 */
int main () {
    std::cout << "******** Welcome to the Load Balancer Program! ********" << std::endl;

    std::cout << "Please enter the number of servers: ";
    int numServers; ///< number of servers inputted by user
    std::cin >> numServers;

    std::cout << "Please enter the clock cycle time: ";
    int clockCycleTime; ///< number of clock cycles inputted by user
    std::cin >> clockCycleTime;

    std::cout << "Please enter the max size of the requests: ";
    int maxSize; ///< maximum size of requests inputted by user
    std::cin >> maxSize;

    // Create a LoadBalancer object with the user-specified number of servers, clock cycle time, and max size of requests
    std::cout << "Log located in 'log.txt'" << std::endl;
    freopen("log.txt", "w", stdout);
    LoadBalancer* lb = new LoadBalancer(numServers, clockCycleTime, maxSize);

    return 0;
}
