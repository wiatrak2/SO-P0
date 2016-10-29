// Wojciech Pratkowiecki II UWr SO - P0
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

static const int countdown = 1;

void thread_func()
{
    printf("child thread id: \t");
    std::cout << std::this_thread::get_id() << "\n";
    std::cout.flush();
}

int main(int argc, const char * argv[]) {

    std::thread::id main_thread_id = std::this_thread::get_id();
    
    std::chrono::steady_clock::time_point tend = std::chrono::steady_clock::now( ) + std::chrono::milliseconds(countdown);
    
    std::vector < std::thread > thread_vec;
    unsigned int thread_counter = 0;
    
    while (std::chrono::steady_clock::now() < tend)
    {
        thread_vec.push_back(std::thread(thread_func));
        ++ thread_counter;
    }
    
    for (auto& t : thread_vec)
    {
        t.join();
    }
    
    printf("you run %d child threads in just %d millisecond(s)! this is main thread with id = ", thread_counter, countdown);
    std::cout << main_thread_id << "\n";
    std::cout.flush();
    return 0;
}
