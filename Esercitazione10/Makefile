FILE_NAME_TEST=test_esercizio
FILE_NAME_ESERCIZIO=esercizio
FILE_NAME_CORRETTORE=correttore_esercizio

all: $(FILE_NAME_TEST)

$(FILE_NAME_TEST): $(FILE_NAME_TEST).o $(FILE_NAME_ESERCIZIO).o $(FILE_NAME_CORRETTORE).o
	g++ -o $(FILE_NAME_TEST) $(FILE_NAME_TEST).o $(FILE_NAME_ESERCIZIO).o $(FILE_NAME_CORRETTORE).o

$(FILE_NAME_TEST).o: $(FILE_NAME_TEST).c $(FILE_NAME_ESERCIZIO).h 
	g++ -c $(FILE_NAME_TEST).c

$(FILE_NAME_ESERCIZIO).o: $(FILE_NAME_ESERCIZIO).c $(FILE_NAME_ESERCIZIO).h 
	g++ -c $(FILE_NAME_ESERCIZIO).c -lm

clean:
	rm -rf $(FILE_NAME_TEST).o $(FILE_NAME_TEST) $(FILE_NAME_ESERCIZIO).o *~
