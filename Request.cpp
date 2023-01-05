/**
 * @file
 * @brief Request class implementation
 * 
 * * All comments written by ChatGPT
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <chrono>
#include <random>
using namespace std;

/**
 * @class Request
 * @brief Request class
 *
 * This class represents a request that needs to be processed by a web server.
 */
class Request {
public:
    std::string ip_in;  ///< IP address of the incoming request
    std::string ip_out;  ///< IP address of the outgoing response
    int num_clock_cycles;  ///< number of clock cycles required to process the request

    /**
     * @brief Constructor
     * @param maxSize Maximum size of the requests
     *
     * Creates a new Request object with random IP addresses for the incoming request and outgoing response,
     * and a random number of clock cycles required to process the request within the specified maximum size.
     * 
     * This constructor was written by ChatGPT.
     * 
     * @code
     * Request(int maxSize) {
        std::random_device rd; ///< random device to generate seed data for the random number engine
        std::mt19937 mt(rd()); ///< use the Mersenne Twister pseudo-random number generator engine with the seed data from the random device
        std::uniform_int_distribution<int> dist(0, 255); ///< create a uniform integer distribution to generate random numbers between 0 and 255 (inclusive)
        std::uniform_int_distribution<int> clock_cycles_dist(2, maxSize); ///< create a uniform integer distribution to generate random numbers between 2 and maxSize (inclusive)

        ip_in = std::to_string(dist(mt)) + "." + std::to_string(dist(mt)) + "." + std::to_string(dist(mt)) + "." + std::to_string(dist(mt));
        ip_out = std::to_string(dist(mt)) + "." + std::to_string(dist(mt)) + "." + std::to_string(dist(mt)) + "." + std::to_string(dist(mt));
        num_clock_cycles = clock_cycles_dist(mt);
    }
     * @endcode
     * 
     */
    Request(int maxSize) {
        std::random_device rd; ///< random device to generate seed data for the random number engine
        std::mt19937 mt(rd()); ///< use the Mersenne Twister pseudo-random number generator engine with the seed data from the random device
        std::uniform_int_distribution<int> dist(0, 255); ///< create a uniform integer distribution to generate random numbers between 0 and 255 (inclusive)
        std::uniform_int_distribution<int> clock_cycles_dist(2, maxSize); ///< create a uniform integer distribution to generate random numbers between 2 and maxSize (inclusive)

        ip_in = std::to_string(dist(mt)) + "." + std::to_string(dist(mt)) + "." + std::to_string(dist(mt)) + "." + std::to_string(dist(mt));
        ip_out = std::to_string(dist(mt)) + "." + std::to_string(dist(mt)) + "." + std::to_string(dist(mt)) + "." + std::to_string(dist(mt));
        num_clock_cycles = clock_cycles_dist(mt);
    }
};
