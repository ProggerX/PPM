#pragma once
#include <chrono>

using namespace std;

class Stopwatch {
private:
    chrono::time_point<chrono::system_clock> start_time;

public:
    void start() {
        start_time = std::chrono::system_clock::now();
    }

    long elapsed_time() {
        return std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::system_clock::now() - start_time).count();
    }
};
