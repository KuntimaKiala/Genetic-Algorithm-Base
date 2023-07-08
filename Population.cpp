#include <iostream>
#include "Population.hpp"
#include <random>


Population::Population()
{

}


Population::~Population()
{

   population.clear();
   matingPool.clear() ;
   std::cout << "END\n" ;
}

Population::Population(std::string target_t, float mutationRate_m, int population_p, float threshold_score_ts){

    
    set_POP_MAX(population_p);
    set_Target(target_t);
    set_MUTATION_RATE(mutationRate_m);
    set_THRESHOLD_SCORE(threshold_score_ts) ;
    for (int i = 0 ; i < population_max; i++){
        population.push_back(new DNA(target_t.length()));
        population[i]->fitness(target_phrase);

    }
    
    matingPool = std::vector <DNA*>();
    perfectScore = 1 ;
    finished = false;
    generations = 0 ;
} 


 void Population::calcFitness(){

    for (int i = 0 ; i < population_max; i++){
        population[i]->fitness(target_phrase);

    }

 }


void Population::naturalSelection() {
    matingPool.clear();
    float maxFitness = 0.0;
    for (int i = 0; i < population.size(); i++) {
      if (population[i]->fitness_score > maxFitness) {
        maxFitness = population[i]->fitness_score;
      }
    }
    
    // Based on fitness, each member will get added to the mating pool a certain number of times
    // a higher fitness = more entries to mating pool = more likely to be picked as a parent
    // a lower fitness = fewer entries to mating pool = less likely to be picked as a parent
    for (int i = 0; i < population.size(); i++) {
      
       
      float fitness = population[i]->fitness_score/maxFitness ;
      int n = int(fitness * 100);  // Arbitrary multiplier, we can also use monte carlo method
      for (int j = 0; j < n; j++) {              // and pick two random numbers
        if (population[i]->fitness_score > threshold_score) {

            matingPool.push_back(population[i]);
            std::cout << "i :"<< i << " -->" <<population[i]->fitness_score<<std::endl;

        }
        
      }
    }


    if (matingPool.size() == 0) {
        threshold_score = threshold_score - increments*2.5 ;
        naturalSelection() ;

    }
    //std::cout << "D:"<<maxFitness<<std::endl;
    std::cout << "B:"<<matingPool.size()<< " -->" <<threshold_score<<std::endl;
    for (int i = 0; i < matingPool.size(); i++) {
        std::cout << "C:"<<matingPool[i]->GENES() <<std::endl;
        
    }

}

void Population::generate(){
    DNA* child ;
    for (int i = 0; i < population.size(); i++){
        int m = matingPool.size() -1 ;
        int a = random(m);
        int b = random(m);
        std::cout << a << " <--> " << b << " <-->" << m << std::endl;
        DNA* partnerA = matingPool[a];
        DNA* partnerB = matingPool[b] ;

        std::cout << partnerA->GENES() << " == " << partnerB->GENES() << " ==>" << m << std::endl;
        //child = partnerA->crossover(*partnerB) ;
        //child->mutate(mutationRate);
        //population[i] = child;
    }

    generations++ ;
    threshold_score += increments ;


}


 std::string* Population::getBest(){

    int worldrecord = 0 ;
    int index = 0 ;
    for (int i = 0; i < population.size(); i++){
        if(population[i]->fitness_score > worldrecord){
            worldrecord = population[i]->fitness_score;
            index = i;

        }

    }
    if(worldrecord==perfectScore){
        finished = true;

    }


    return population[index]->getPhrase() ;
 }

void Population::set_THRESHOLD_SCORE(float score){
    threshold_score = score;
}
float Population::get_THRESHOLD_SCORE() {

    return threshold_score;
}



void Population::set_POP_MAX(int num){
    population_max = num;

}

int Population::get_POP_MAX() {
    return population_max;

}


void Population::set_Target(std::string phrase){
    target_phrase = phrase;

}
std::string Population::get_Target() {

    return target_phrase;
}




void Population::set_MUTATION_RATE(float mutation_rate){
    mutationRate = mutation_rate ;
}
float Population::get_MUTATION_RATE() {

    return mutationRate ;
}

char Population::random(int min, int max)
{
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 generator(rd()); // seed the generator
    std::uniform_int_distribution<> distr(96, 110); // define the range

    return (char) distr(generator);
}


int Population::random(int max)
{
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 generator(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, max); // define the range

    return distr(generator);
}

float Population::random()
{
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 generator(rd()); // seed the generator
    std::uniform_real_distribution<> distr(0, 1); // define the range

    return (float) distr(generator);
}
