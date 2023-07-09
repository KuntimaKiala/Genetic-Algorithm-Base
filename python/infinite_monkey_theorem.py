from population import Population
import time 
def initialize(population_size=150, mutationRate = 0.01, target = "To be or not to be.", init_score= 0.09) :
    population = Population()
    # create the population randomly
    population.population_init(target, mutationRate, population_size, init_score)
    return population

def run(population,i):
    
    naturalSelection = population.naturalSelection() 
    population.generate(population.target)
    population.calcFitness()
    print(f"epochs : {i}")
    print("phrase :", population.getBest())
    return naturalSelection