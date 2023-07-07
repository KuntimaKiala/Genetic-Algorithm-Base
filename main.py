import time
from infinite_monkey_theorem import initialize, run



if __name__ == "__main__" :
    
    population_size=100
    mutationRate = 0.03 
    
    target_phrase_0 = "Don't talk about my moms yo!."
    target_phrase_1  = 'Kuntima Kiala Miguel'
    target_phrase_2 = "Don't talk about my moms yo and remember ALL CAPS when you spell the man name..."
    target_phrase_3 = "So nasty that it's probably somewhat of a travesty having me; Daily told the people; You can call me Your Majesty! ;Keep your battery charged"
    target_phrase_4 = "Just remember ALL CAPS when you spell the man name... - MADVILLAIN"
    target_phrase_5 = "I pull up at your concert, be like let me take your mic, I am that nice leave sleep."
    target_phrases  = [target_phrase_0, target_phrase_1, target_phrase_2,target_phrase_3,target_phrase_4, target_phrase_5]
    
    init_score = 0.15
    population = initialize(population_size=population_size, 
                            mutationRate=mutationRate, 
                            target=target_phrases[0], 
                            init_score= init_score)
    epoch = 50000
    start = time.time()
    for i in range(epoch) :
        run(population, i)    
        if population.finished :
            end = time.time()
            print(f"elapse time : {end - start}")
            break
