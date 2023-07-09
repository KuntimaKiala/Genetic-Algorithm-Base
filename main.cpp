#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include "Population.hpp"
#include "DNA.hpp"
#include <chrono>


void run(Population &population, int i);

int main(){

    std::string target = "Dont't talk about my moms, yo!";


    
    int target_size = target.length();
    float mutationRate = 0.03;
    int population_max = 150 ;
    float threshold_init = 0.15;
    Population pop(target, mutationRate, population_max , threshold_init);

    int i = 1;
    int epoch = 5000 ;
    auto begin = std::chrono::high_resolution_clock::now();
    while (i <= epoch and pop.finished==false)
    {
       
       run(pop, i) ;
       i++;
    }
    auto end =std::chrono::high_resolution_clock::now();
    auto duration =  std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << "Elapsed time in seconds: "
        << (double) duration.count() / 1000.0
        << " sec";
    std::cout << "\n\n" << std::endl ;
    return 0;
}


void run(Population &pop, int epoch){

    std::cout << "score :" << pop.threshold_score <<  std::endl ;
    pop.naturalSelection() ;
    pop.generate();
    pop.calcFitness();
  
    
    
    std::string best = pop.getBest() ;

    std::cout << "\nphrase ("<< epoch <<") :"<< std::endl ;
    for (int i = 0; i < pop.get_Target().size(); i++){
            std::cout <<  best[i] ; 

        }
    //delete best ;
   
std::cout << std::endl ;
}