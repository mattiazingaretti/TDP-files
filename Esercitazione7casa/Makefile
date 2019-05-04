#default rules
.phony:	clean all

#make rule
all:	main

#each .o depends on the corresponding .c
%.o:	%.c
	g++ -c -Wall $< -o $@

#main depends on all object files
main: scl_functions.o  main.o
	g++ -Wall -o $@ scl_functions.o  main.o

#polishes
clean:	
	rm -rf scl_functions.o  main.o main *~

