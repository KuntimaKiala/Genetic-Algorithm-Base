from __future__ import division
from dna import DNA
import string
import random


""" 




"""
class Population() :
    
    
    def __init__(self) :
        
        self.population    = []       # the list contain the population
        self.matingPool    = []       # the list that will conatin the mating          
        self.generations   = 0        # the number of generations    
        self.finished      = False    # to check when we are done         
        self.perfectScore  = 0
        self.increments = 0.005
        
    #1 - initilize, the elements of the population are the dna  
    def population_init(self, target, mutationRate, population_size, init_score= 0.09)    :
        
        self.init_score= init_score
        self.target = target
        self.mutationRate = mutationRate
        self.population_size = population_size
        self.population = [""]* self.population_size
        
        for i in range(population_size) :
            self.population[i] = DNA(dna_size=len(self.target))
            self.population[i].dna()
        
        self.calcFitness()    
        self.matingPool    = [] 
        self.generations = 0
        self.finished = False
        self.perfectScore = 1
           
    #2- calculate the fitness
    def calcFitness(self) :
        
        for i in range(len(self.population)) : 
            self.population[i].fitness(self.target)
            
            
    #3- generate the mating pool
    def naturalSelection(self) :
        self.matingPool    = [] 
        
        #3.1 get the maxfitness
        self.maxFitness = 0.0
        for i in range(len(self.population)) :
            if self.population[i].fitness_score > self.maxFitness :
                self.maxFitness = self.population[i].fitness_score
                
    
        #3.1 // Based on fitness, each member will get added to the mating pool a certain number of times
        #    // a higher fitness = more entries to mating pool = more likely to be picked as a parent
        #    // a lower fitness = fewer entries to mating pool = less likely to be picked as a parent
        
        for i in range(len(self.population)) :
            # map fitness between 0 and 1
            
            fitness = self.population[i].fitness_score/self.maxFitness
            
            n = int(fitness * 100)
            for i in range(n) :
                if self.population[i].fitness_score  >= self.init_score :
                    
                    self.matingPool.append(self.population[i])
        
        if not len(self.matingPool) :
            self.init_score = self.init_score - self.increments*2.5
            self.naturalSelection()
    #4- create the new generation
    def generate(self, target)  :
        
        # 4.1 // Refill the population with children from the mating pool
        for i in range(len(self.population)):
         
         
            a = random.randint(0, len(self.matingPool) -1)
            b = random.randint(0, len(self.matingPool) -1)

            partnerA = self.matingPool[a]
            partnerB = self.matingPool[b]
            
         
            #4.2 crossover
            child = partnerA.crossover(partnerB)
            #4.3 mutate
            child.mutation(self.mutationRate, target)
            self.population[i] = child

        self.generations += 1
        
        if self.generations%1==0 :
            self.init_score += self.increments*1.5
        print("score :", self.init_score)
    def getBest(self) -> string:
        
        worldrecord = 0 
        index = 0
        for i in range(len(self.population)) :
            if self.population[i].fitness_score > worldrecord :
                worldrecord = self.population[i].fitness_score
                index = i
                #print("score :", self.population[index].fitness_score, self.population[index].getPhrase())
                
        if worldrecord == self.perfectScore :
            self.finished = True
 
        return self.population[index].getPhrase()
