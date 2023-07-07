#include <iostream>
#include "DNA.hpp"
#include <random>


DNA::DNA()
{

}

DNA::DNA(int dna_size)
{

    setDNA(dna_size);
    
    
    for(int i =0; i < dna_size; i++){
        genes[i] = random(32, 127);
        std::cout << " "<< i << " :"<< genes[i] << " "; // << " : "<< genes[i] << std::endl;
    }
    
    
}

DNA::~DNA()
{
  //delete [] genes ;
}

void DNA:: setDNA(int num) {
      gene_size = num;
    }


int DNA::getDNA() {
      return gene_size;
    }

void DNA::fitness(std::string target){
    
    for(int i= 0; i < target.length(); i++){
        std::cout << i << " --> "<< genes[i] << std::endl;
        if (target[i] == genes[i]){
            fitness_score++;
        }

    }

}


char DNA::random(int min, int max)
{
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 generator(rd()); // seed the generator
    std::uniform_int_distribution<> distr(min, max); // define the range

    return (char) distr(generator);
}

