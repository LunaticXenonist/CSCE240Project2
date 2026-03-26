compiler = g++
flags = -Wall -std=c++17
compile = $(compiler) $(flags) -c
link = $(compiler) $(flags)

program2 : program2.o dynamicarray.o
	$(link) $^ -o $@
	./$@
	rm *.o program2

program2.o : program2.cc dynamicarray.h
	$(compile) $<

dynamicarray.o : dynamicarray.cc dynamicarray.h
	$(compile) $<

clean :
	rm *.o program2
