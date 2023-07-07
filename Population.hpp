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
#include <list>

class Population {
public:

    Population();
    ~Population();
   Population(std::string target_t, float mutationRate_m, int population_p, float threshold_score_ts = 0.09);
    
    void set_POP_MAX(int num);
    int get_POP_MAX() ;
    /*void calcFitness() ;
    std::list <DNA> matingPool ;*/
protected:
 int population_max;
 
};

#endif