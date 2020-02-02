.RECIPEPREFIX = K
stack: stack.o
K gcc stack.o -o stack
stack.o: stack.c
K gcc -c -Wall -Wextra -Werror stack.c 
clean:
K rm stack stack.o

