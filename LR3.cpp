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
        cout << "Время выполнения блока" << endl;
        cout << duration_cast<milliseconds>(end_time_ - start_t_).count() << "ms\n";
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Ожидание 5 сек..."s << endl;
    profiler sleep_guard;
    this_thread::sleep_for(5s);
    cout << "Ожидание завершено"s << endl;
}