import time
from infinite_monkey_theorem import initialize, run



if __name__ == "__main__" :
    
    population_size=100
    mutationRate = 0.05
    target_phrase = "Don't talk about my moms yo!."
    target_phrase = "Just remember ALL CAPS when you spell the man name..."
    init_score = 0.15
    population = initialize(population_size=population_size, 
                            mutationRate=mutationRate, 
                            target=target_phrase, 
                            init_score= init_score)
    epoch = 5000
    start = time.time()
    for i in range(epoch) :
        run(population, i)    
        if population.finished :
            end = time.time()
            print(f"elapse time : {end - start}")
            break
