#include <iostream>
#include "Population.hpp"
#include <random>


Population::Population()
{

}


Population::~Population()
{
  
  std::cout << "END\n" ;
}

Population::Population(std::string target_t, float mutationRate_m, int population_p, float threshold_score_ts){

    std::cout << target_t << std::endl;


    
   
    set_POP_MAX(population_p);
    DNA* population[population_max] ;

    for (int i = 0 ; i < population_max; i++){
        population[i] =  new DNA(target_t.length());
        std::cout << i << " :" << population[i]->GENES() << " :" << population[i]->fitness_score <<std::endl;
    
    }
    
    
    


} 


/*
void Population::calcFitness() {

    for (int i = 0 ; population_max; i++){
        population[i].fitness(target);

    }
}
*/
void Population::set_POP_MAX(int num){
    population_max = num;

}

int Population::get_POP_MAX() {
    return population_max;

}
