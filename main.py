import time
from infinite_monkey_theorem import initialize, run




if __name__ == "__main__" :
    
    
    population_size=5000
    mutationRate = 0.05
    target = "Don't talk about my moms yo!."
    init_score = 0.1
    population = initialize(population_size=population_size, mutationRate=mutationRate, target=target, init_score= init_score)
    epoch = 5000
    start = time.time()
    for i in range(epoch) :
        
        run(population, i)
        
        
            
        if population.finished :
            end = time.time()
            print(f"elapse time : {end - start}")
            break
