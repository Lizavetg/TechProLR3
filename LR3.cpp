#include <chrono>
#include <iostream>
#include <thread>

using namespace std;
using namespace chrono;
using namespace literals;

class profiler {
    public:
        float start_t_;
        float end_t_;
        
        profiler() {   
            steady_clock::time_point start_time_ = steady_clock::now(); 
            // steady_clock::duration end_time_ = steady_clock::now(); 
        };

        ~profiler() {
            cout << "Время выполнения блока" << endl;   
        }
};

int main() {
    cout << "Ожидание 5 сек..."s << endl;
    profiler sleep_guard;
    this_thread::sleep_for(5s);
    cout << "Ожидание завершено"s << endl;
}