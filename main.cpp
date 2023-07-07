#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include "Population.hpp"



int main(){

    std::string target = "kuntima";
    int target_size = target.length();
    
    Population pop(target, 0.01, 5 ,0.05);
    
    
    
    return 0;
}
