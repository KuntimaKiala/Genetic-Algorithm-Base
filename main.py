import time
from infinite_monkey_theorem import initialize, run



if __name__ == "__main__" :
    
    population_size=100
    mutationRate = 0.03 
    
    target_phrase = "Don't talk about my moms yo!."
    target_phrase  = 'Kuntima Kiala Miguel'
    target_phrase = "Don't talk about my moms yo and remember ALL CAPS when you spell the man name..."
    target_phrase = "So nasty that it's probably somewhat of a travesty having me; Daily told the people; You can call me Your Majesty! ;Keep your battery charged"
    target_phrase = "Just remember ALL CAPS when you spell the man name... - MADVILLAIN"
    target_phrase = "I pull up at your concert, be like let me take your mic, I am that nice leave sleep."
    init_score = 0.15
    population = initialize(population_size=population_size, 
                            mutationRate=mutationRate, 
                            target=target_phrase, 
                            init_score= init_score)
    epoch = 50000
    start = time.time()
    for i in range(epoch) :
        run(population, i)    
        if population.finished :
            end = time.time()
            print(f"elapse time : {end - start}")
            break
