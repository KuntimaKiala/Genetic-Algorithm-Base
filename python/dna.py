import random
import string
from copy import deepcopy

""" 

// Genetic Algorithm, Evolving Shakespeare

// A class to describe a psuedo-DNA, i.e. genotype
//   Here, a virtual organism's DNA is an array of character.
//   Functionality:
//      -- convert DNA into a string
//      -- calculate DNA's "fitness"
//      -- mate DNA with another set of DNA
//      -- mutate DNA


"""


class DNA() :
    
    def __init__(self, genes=[""], fitness_score=0, dna_size=150) -> None:
        
        
        self.fitness_score = fitness_score 
        self.dna_size = dna_size
        self.genes = genes*self.dna_size
        self.alphabet =  list(chr(random.randint(32,127)))
        self.scoring = 0
        #list(string.ascii_lowercase)  + [" "] + ["."] + list(string.ascii_uppercase)
        
    #1- generate random dna       
    def dna(self) :
        for i in range(self.dna_size) :
            self.genes[i] = random.choices(self.alphabet,k=1)[0] 
        
    #2- Fitness function (returns floating point % of "correct" characters)
    def fitness(self, target) :
        self.score = 0
        assert(self.dna_size == len(target) ) 
        for i in range(self.dna_size) :
            if self.genes[i] == target[i] :
                self.score += 1
        
        self.scoring = self.score
        self.fitness_score = self.score / len(target)
        
    #3 crossover
    def crossover(self, dna_partner) :
        
        #3.1 create a child
        child = DNA(dna_size=len(self.genes))
        
        #3.2 pick mid point randomly
        midpoint =  random.choices([i for i in range(len(self.genes))])[0]
        
        #3.3 child is the half from both parent from the midpoint
        for i in range(len(self.genes)) :
            if i > midpoint :
                child.genes[i] = self.genes[i]
            else :
                child.genes[i] = dna_partner.genes[i] 
                
        return child
    
    
    #4 mutate the gene based on mutation rate
    def mutation(self, mutationRate,target) :

        for i in range(len(self.genes)) :
            
            if random.random() < mutationRate : #and self.genes[i] != target[i] :
                self.genes[i] = random.choices(self.alphabet,k=1)[0] 
        
         
    # 5 - get the phrase  
    def getPhrase(self) -> string :
        return ''.join(self.genes)
