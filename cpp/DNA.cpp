#include <iostream>
#include "DNA.hpp"
#include <random>


DNA::DNA()
{

}

DNA::DNA(int dna_size)
{

    setDNA(dna_size);

    
    for(int i =0; i < gene_size; i++){
        genes.push_back(random(32, 127));
    }
    

}
DNA::~DNA()
{

}

void DNA:: setDNA(int num) {
      gene_size = num;
    }

std::string DNA:: GENES () {

    return genes ;
}

int DNA::getDNA() {
      return gene_size;
    }

void DNA::fitness(std::string target){
    float score = 0.0;
    
    for(int i= 0; i < target.size(); i++){
        if (target[i] == genes[i]){
            score++;
           
        }

    }
    
    fitness_score = score / ((float)target.length()) ;
    

}


DNA DNA::crossover( DNA& partner){

int midpoint = random(gene_size-1) ;
//std::vector<DNA*> child ;
DNA child = DNA(gene_size) ;

for (int i = 0; i < gene_size ; i++) {
   
    if (i > midpoint) {
        child.genes[i] = genes[i] ;
    }
    child.genes[i] = partner.genes[i] ;

    

}

return child;

}

void DNA::mutate(float mutationRate) {
    int genes_size = getDNA() ;//sizeof(genes)/sizeof(genes[0]) ;

    for (int i = 0; i < genes_size; i++) {
      if (random() < mutationRate) {
        genes[i] = random(32,127);
        
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


int DNA::random(int max)
{
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 generator(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, max); // define the range

    return distr(generator);
}

float DNA::random()
{
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 generator(rd()); // seed the generator
    std::uniform_real_distribution<> distr(0, 1); // define the range

    return (float) distr(generator);
}



std::string DNA::getPhrase() {

    //float* angles = new float[3];
    std::string _genes ;

 
    for (int i =0; i < gene_size; i++){
        _genes.push_back(genes[i]);

    }
    return _genes ;
}

