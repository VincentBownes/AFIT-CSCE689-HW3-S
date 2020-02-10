#include <PCalc_SP.h>
#include <math.h>

PCalc_SP::PCalc_SP(unsigned int array_size) : PCalc{array_size} {

};

void PCalc_SP::markNonPrimes(){
    //0 and 1 are not prime
    this->at(0) = false;
    this->at(1) = false;
    //now loop over the rest
    long unsigned int endPoint = sqrt(this->array_size());
    long unsigned int arraySize = this->array_size();
    for(long unsigned int i = 2; i <= endPoint; i++){
        if(this->at(i) == true){
            for(long unsigned int k = (i*i); k <= arraySize ; k += i){
                this->at(k) = false;
            }
        }
    }
}