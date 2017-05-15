#export SLEPC_DIR=/home/guido/libs/slepc-3.7.1
#export PETSC_DIR=/home/guido/libs/petsc-3.7.2
#export PETSC_ARCH=arch-linux2-c-opt

PWD:= $(shell pwd)

SRC_DIR=./src
OBJ_DIR=./obj
DEP_DIR=${PWD}/inc

CFLAGS=-g -O0 
	
DEPS = ${DEP_DIR}/giant.h        

OBJ  = ${OBJ_DIR}/gia_main.o               

.PHONY: clean_
	
all: ${OBJ} 
	gcc -o giant $^ ${PETSC_KSP_LIB} -lgsl -lgslcblas -lm
	
${OBJ_DIR}/%.o: ${SRC_DIR}/%.c $(DEPS) 
	${PETSC_COMPILE} -c ${CFLAGS} -o $@ $< -I${DEP_DIR} 

clean_:	    
	rm -f $(OBJ) bathe

include ${PETSC_DIR}/lib/petsc/conf/variables	
include ${PETSC_DIR}/lib/petsc/conf/rules	

#include ${SLEPC_DIR}/lib/slepc/conf/slepc_common



