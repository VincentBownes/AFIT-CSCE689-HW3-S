#ifndef PCALC_T_H
#define PCALC_T_H

#include "PCalc.h"
#include <vector>
#include <thread> 

// Your implementation of PCalc_T class should go here. 
// Make sure your constructor takes in two parameters:

// PCalc_T::PCalc_T(unsigned int array_size, unsigned int num_threads);

// Call the parent constructor when initializing your constructor and pass in array_size. Then
// use num_threads to cap off how many threads you use to calculate all prime numbers

class PCalc_T : public PCalc 
{
public:
   PCalc_T(unsigned int array_size, unsigned int num_threads);

   void threadMarkNonPrimes(unsigned int startingPoint);
   void threadPoolHelper(std::vector<std::thread>& threads, unsigned int startingPoint);
   void markNonPrimes();
   

private:
    int numOfThreads;

};

#endif
