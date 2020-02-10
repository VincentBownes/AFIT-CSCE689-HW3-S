#include <PCalc_T.h>
#include <mutex>
#include <iostream>
#include <math.h>


PCalc_T::PCalc_T(unsigned int array_size, unsigned int num_threads) : PCalc{array_size} {
    this->numOfThreads = num_threads;
}

void PCalc_T::threadMarkNonPrimes(unsigned int startingPoint){ 
    long unsigned int endPoint = sqrt(this->array_size());
    long unsigned int arraySize = this->array_size();
    for(long unsigned int i = startingPoint; i <= endPoint; i++){ 
        if(*reinterpret_cast<uint8_t*>(&this->at(i)) == 1){    
            *reinterpret_cast<uint8_t*>(&this->at(i)) = 2;         
            for(long unsigned int k = (i*i); k <= arraySize; k += i){
                this->at(k) = false;
            }
        }
        
    } 
}

void PCalc_T::markNonPrimes(){
    //0 and 1 are not prime
    this->at(0) = false;
    this->at(1) = false;
    //now loop over the rest using multiple threads
    std::vector<std::thread> threads;
    for(int i = 0; i < numOfThreads; i++){
        threads.push_back(std::thread(&PCalc_T::threadMarkNonPrimes, this, i+2));
    }

    for (auto& t : threads) t.join();
    
}


















/*void PCalc_T::threadPoolHelper(std::vector<std::thread>& threads, unsigned int startingPoint){
    // find an ended thread
    for(auto&& thread: threads){
        if(thread.joinable()){ continue; }
            thread = std::thread(&PCalc_T::threadMarkNonPrimes, this, startingPoint, startingPoint );
            return;
        }

    // if not wait for one
    for(auto&& thread: threads){
        if(!thread.joinable()){ continue; }

        thread.join();
        thread = std::thread(&PCalc_T::threadMarkNonPrimes, this, startingPoint, startingPoint );
        return;
        }
    }


void PCalc_T::markNonPrimes(){
    //0 and 1 are not prime
    this->at(0) = false;
    this->at(1) = false;
    //now loop over the rest using multiple threads
    unsigned int startingPoint = ceil(sqrt(this->array_size())/this->numOfThreads);
    std::vector<std::thread> threads(this->numOfThreads);
    for(int i = 2; i <= sqrt(this->array_size()); i++){
        if(this->at(i) == true){
           this->threadPoolHelper(threads, i);
        }
    }

    for (auto& t : threads) t.join();
    
}*/