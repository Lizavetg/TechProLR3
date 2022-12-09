#include <chrono>
#include <iostream>
#include <thread>

using namespace std;
using namespace chrono;
using namespace literals;

class profiler {
public:
    steady_clock::time_point start_t_;
    steady_clock::time_point end_t_;

    profiler() {
        steady_clock::time_point start_time_ = steady_clock::now();
        this->start_t_ = start_time_;
    };

    ~profiler() {
        steady_clock::time_point end_time_ = steady_clock::now();
        // cout << "Duration of block" << endl;
        cout << duration_cast<milliseconds>(end_time_ - start_t_).count() << "ms\n";
    }
};

