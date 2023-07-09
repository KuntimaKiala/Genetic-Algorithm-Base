#ifndef POPULATION_HPP
#define POPULATION_HPP

#pragma once


// Genetic Algorithm, Evolving Shakespeare

// A class to describe a psuedo-DNA, i.e. genotype
//   Here, a virtual organism's DNA is an array of character.
//   Functionality:
//      -- convert DNA into a string
//      -- calculate DNA's "fitness"
//      -- mate DNA with another set of DNA
//      -- mutate DNA


#include "DNA.hpp"
#include <iostream>
#include <vector>
#include <random>

class Population {
public:

    Population();
    ~Population();
   Population(std::string target_t, float mutationRate_m, int population_p, float threshold_score_ts = 0.09);
    
    void set_POP_MAX(int num);
    int get_POP_MAX() ;

    void set_Target(std::string phrase);
    std::string get_Target() ;

    void set_THRESHOLD_SCORE(float score);
    float get_THRESHOLD_SCORE() ;

    void set_MUTATION_RATE(float mutation_rate);
    float get_MUTATION_RATE() ;

    char random(int min, int max);
    int  random(int max);
    float random();
    
    void calcFitness();
    void naturalSelection() ;
    std::string  generate();

    std::string getBest() ;
    
    int generations  ;
    bool finished ;
    int perfectScore;
    std::vector<DNA > population;
    float threshold_score ; 
    int counter = 0 ;

protected:
 int population_max;
 std::vector <DNA> matingPool ;
 int population_size = population_max ;
 std::string target_phrase ;
 
 float increments = 0.005;
 float mutationRate ;
 
};

#endif