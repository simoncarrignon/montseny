EXECS=main
MPICC?=mpicc

all: ${EXECS}

main: main.o solve_macro.o solve_micro.o
	${MPICC} -o main -g main.o solve_macro.o solve_micro.o

main.o: main.c
	${MPICC} -o main.o -g -c main.c

solve_macro.o: solve_macro.c
	${MPICC} -o solve_macro.o -g -c solve_macro.c

solve_micro.o: solve_micro.c
	${MPICC} -o solve_micro.o -g -c solve_micro.c

macro: macro.c
	${MPICC} -o macro -g macro.c

micro: micro.c
	${MPICC} -o micro -g micro.c

clean:
	rm -f ${EXECS}
