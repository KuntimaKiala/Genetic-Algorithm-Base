#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include "DNA.cpp"



int main(){

    std::string target = "KuntimaT";

    
    DNA d(8);
    std::cout << "\n" ;
    d.fitness(target);
    std::cout << "\n"<< d.fitness_score << std::endl;
    
    
    
    return 0;
}
