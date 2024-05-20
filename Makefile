scanner: main.c lex.c
	gcc -o scanner -g main.c lex.c

clean:
	rm -f scanner *.o
