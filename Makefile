cli_exec:  com2 run
    
run:
	./Progra
    
com2:
	gcc  -Wall test.c -o Progra `pkg-config --cflags --libs gtk+-3.0`  -lm