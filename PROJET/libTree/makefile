libtree.a : libtree.o
	ar -rs $@ $^ 

%: %.c libtree.h
	gcc -Wall -c $@