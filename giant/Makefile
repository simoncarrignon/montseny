
export PETSC_DIR=/home/guido/libs/petsc-3.7.5
export PETSC_ARCH=arch-linux2-c-debug

PWD:= $(shell pwd)

SRC_DIR= ./src
OBJ_DIR= ./obj
DEP_DIR= ./inc                     

CFLAGS=-g -O0 
	
DEPS = ${DEP_DIR}/giant.h                   



OBJ  = ${OBJ_DIR}/gia_main.o  \
       ${OBJ_DIR}/gia_mesh.o

LDFLAG = -L../../../libs/parmetis-4.0.3/build/Linux-x86_64/libparmetis \
         -L../../../libs/parmetis-4.0.3/build/Linux-x86_64/libmetis 

.PHONY: clean_

all: ${OBJ} 
	gcc -o giant $^ ${PETSC_KSP_LIB} -lgsl -lgslcblas -lm

obj/gia_main.o: src/gia_main.c inc/giant.h
	${PETSC_COMPILE} -c ${CFLAGS} -o $@ $< -I./inc

obj/gia_mesh.o: src/gia_mesh.c inc/giant.h ~/libs/parmetis-4.0.3/include/parmetis.h
	${PETSC_COMPILE} -c ${CFLAGS} -o $@ $<       \
	-I../../../libs/parmetis-4.0.3/include       \
	-I../../../libs/parmetis-4.0.3/metis/include

var:
	echo "PWD = " ${PWD}
	echo "PETSC_COMPILE = " ${PETSC_COMPILE}

clean_:	    
	rm -f $(OBJ) giant

include ${PETSC_DIR}/lib/petsc/conf/variables	
include ${PETSC_DIR}/lib/petsc/conf/rules


	
