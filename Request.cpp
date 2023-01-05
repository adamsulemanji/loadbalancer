#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <chrono>
#include <random>

using namespace std;

class Request {
public:
    std::string ip_in;  ///< IP address of the incoming request
    std::string ip_out;  ///< IP address of the outgoing response
    int num_of_clock_cycles;  ///< Number of clock cycles required to process the request

    Request(int maxSize) {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> dist(0, 255);
        std::uniform_int_distribution<int> clock_cycles_dist(2, maxSize);

        ip_in = std::to_string(dist(mt)) + "." + std::to_string(dist(mt)) + "." + std::to_string(dist(mt)) + "." + std::to_string(dist(mt));
        ip_out = std::to_string(dist(mt)) + "." + std::to_string(dist(mt)) + "." + std::to_string(dist(mt)) + "." + std::to_string(dist(mt));
        num_of_clock_cycles = clock_cycles_dist(mt);

        // cout << "IP IN: " << ip_in << " IP OUT: " << ip_out << " NUM OF CLOCK CYCLES: " << num_of_clock_cycles << endl;
    }
};
