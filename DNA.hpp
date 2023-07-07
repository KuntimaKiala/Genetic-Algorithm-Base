#ifndef DNA_HPP
#define DNA_HPP

#pragma once


// Genetic Algorithm, Evolving Shakespeare

// A class to describe a psuedo-DNA, i.e. genotype
//   Here, a virtual organism's DNA is an array of character.
//   Functionality:
//      -- convert DNA into a string
//      -- calculate DNA's "fitness"
//      -- mate DNA with another set of DNA
//      -- mutate DNA


//#include "Monster.hpp"
class DNA {
public:

    

     DNA();
     DNA(int dna_size);
     ~DNA();
    void setDNA(int num);
    int getDNA() ;
    void fitness(std::string target);
    char random(int min, int max);
    int fitness_score = 0;
    char *genes = new char[gene_size];
    


protected:
    int gene_size;
    
};

#endif