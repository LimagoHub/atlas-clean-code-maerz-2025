#include <iostream>
#include <climits>
#include <chrono>
#include <vector>
#include <memory>
#include <algorithm>
#include <thread>


int main() {

    /*
     * 1. Aufgabe schreibt eine Klasse mit einer Fabrikmethode (createAndFillVector(size)->shared_ptr<vector>
    *  2. Zeitmessung für die Durchführung mit 1 bis n thread
     */

    const size_t availableProcessors = std::thread::hardware_concurrency();
    std::cout << availableProcessors << std::endl;

    const size_t collection_size = INT32_MAX / 2;

    auto feld = std::make_shared<std::vector<int>>(collection_size);

    std::cout << "Running..." << std::endl;
    auto start_ = std::chrono::high_resolution_clock::now();
    for (int  i = 0; i < collection_size ; ++i) {
        feld->at(i) = rand();
    }
    auto end_ = std::chrono::high_resolution_clock::now();
    std::cout << "Duration: " << std::chrono::duration_cast<std::chrono::milliseconds>(end_-start_).count() << std::endl;

    for(int threadCount = 1; threadCount <= availableProcessors + 1; threadCount++) {

    }

    return 0;
}

