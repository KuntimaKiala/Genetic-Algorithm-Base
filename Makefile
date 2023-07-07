
Compiler = "g++"
Projet   = run
Source   = main.cpp DNA.cpp Population.cpp


$(Projet):$(Source)
	$(Compiler) $(Source) -o $(Projet) 

