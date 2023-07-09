#ifndef DNA_HPP
#define DNA_HPP

#pragma once
#include <string>
#include <vector>
#include <random>

// Genetic Algorithm, Evolving Shakespeare

// A class to describe a psuedo-DNA, i.e. genotype
//   Here, a virtual organism's DNA is an array of character.
//   Functionality:
//      -- convert DNA into a string
//      -- calculate DNA's "fitness"
//      -- mate DNA with another set of DNA
//      -- mutate DNA


class DNA {
public:

    

    DNA(int dna_size);
    DNA();
    ~DNA();
    void setDNA(int num);
    int getDNA() ;
    void fitness(std::string target);
    std::string getPhrase() ;
    char random(int min, int max);
    int  random(int max);
    float random();
    float fitness_score = 0.0;
    DNA crossover( DNA& partner);
    void mutate(float mutationRate);
    std::string GENES () ;
  
    


protected:
    int gene_size;
    std::string genes;
    int target_size = gene_size ;
    
    
};

#endif