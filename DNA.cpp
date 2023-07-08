#include <iostream>
#include "DNA.hpp"
#include <random>


DNA::DNA()
{

}

DNA::DNA(int dna_size)
{

    setDNA(dna_size);
    dna_size = getDNA(); 
    for(int i =0; i < dna_size; i++){
        genes[i] = random(32, 127);
    }
    

}
DNA::~DNA()
{
  delete[] genes;
  
}

void DNA:: setDNA(int num) {
      gene_size = num;
    }

char *  DNA:: GENES () {

    return genes ;
}

int DNA::getDNA() {
      return gene_size;
    }

void DNA::fitness(std::string target){
    float score = 0.0;
    for(int i= 0; i < target.length(); i++){
        if (target[i] == genes[i]){
            score++;
           
        }

    }
    
    fitness_score = score / ((float)target.length()) ;
    

}


DNA* DNA::crossover( DNA partner){

int genes_size = getDNA() ; //sizeof(genes)/sizeof(genes[0]) ;
int midpoint = random(gene_size-1) ;
DNA* child = new DNA(genes_size) ;

for (int i = 0; i < gene_size ; i++) {
    std::cout << "ddddbm:"<<genes[i] << " :"<< gene_size <<std::endl;
    if (i > midpoint) {
        child->genes[i] = genes[i] ;
    }
    child->genes[i] = partner.genes[i] ;

    

}

return child;

}

void DNA::mutate(float mutationRate) {
    int genes_size = getDNA() ;//sizeof(genes)/sizeof(genes[0]) ;
    //std::cout << "boom :"<<genes_size << "-->"<< random()<<std::endl;
    for (int i = 0; i < genes_size; i++) {
      if (random() < mutationRate) {
        //genes[i] = random(32,128);
        //std::cout << "boom boom boom :"<<genes[i]<<std::endl;
        //std::cout << "bbmm:"<<genes[i]<<std::endl;
      }
    }
  }

char DNA::random(int min, int max)
{
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 generator(rd()); // seed the generator
    std::uniform_int_distribution<> distr(96, 110); // define the range

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



std::string* DNA::getPhrase() {

    //float* angles = new float[3];
    std::string* _genes = new std::string[gene_size] ;
    for (int i =0; i < gene_size; i++){
        _genes[i] = genes[i];

    }
    return _genes ;
}

