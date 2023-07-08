#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include "Population.hpp"
#include "DNA.hpp"

void run(Population population);

int main(){

    std::string target = "kuntima";
    int target_size = target.length();
    
    Population pop(target, 0.01, 150 ,0.1);
    run(pop) ;
    std::cout << "\n\n" << std::endl ;
    return 0;
}


void run(Population pop){

    
    pop.naturalSelection() ;
    pop.generate();
    pop.calcFitness();
    for (int i = 0; i < pop.population.size(); i++){
            std::cout << "-->" <<  pop.population[i]->fitness_score ; 

        }
    std::string * v = pop.getBest() ;
    delete[] v ;
    /*
    population.generate();
    population.calcFitness();
    
    std::string* best = population.getBest() ;
    std::cout <<"phrase :" << population.getBest() << std :: endl;
    for (int i = 0; i < sizeof(best)/sizeof(std::string); i++){
            std::cout <<  best[i] ; 

        }*/
std::cout << std::endl;
}