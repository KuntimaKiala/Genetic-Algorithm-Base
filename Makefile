

Compiler = "g++"
Projet   = run
Source   = main.cpp


$(Projet):$(Source)
	$(Compiler) $(Source) -o $(Projet) 

