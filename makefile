run:
	gcc -c delete.c
	gcc delete.o course_fns.o -o delete
	./delete

clean:
	rm delete.o
	rm delete
