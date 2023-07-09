
Compiler = "g++"
Projet   = run
Source   = cpp/main.cpp cpp/DNA.cpp cpp/Population.cpp


$(Projet):$(Source)
	$(Compiler) $(Source) -o $(Projet) 

