
export PETSC_DIR=/home/guido/libs/petsc-3.7.5
export PETSC_ARCH=arch-linux2-c-debug

PWD:= $(shell pwd)

SRC_DIR= ./src
OBJ_DIR= ./obj
DEP_DIR= ./inc                     

CFLAGS=-g -O0 
	
DEPS = ${DEP_DIR}/giant.h                   



OBJ  = ${OBJ_DIR}/gia_main.o  \
       ${OBJ_DIR}/gia_mesh.o  \
       ${OBJ_DIR}/list.o  

LDFLAG = -L../../../libs/parmetis-4.0.3/build/Linux-x86_64/libparmetis \
         -L../../../libs/parmetis-4.0.3/build/Linux-x86_64/libmetis 

.PHONY: clean_

##############################
# LINK
all: ${OBJ} 
	gcc -o giant $^ ${PETSC_KSP_LIB} -lgsl -lgslcblas -lm



##############################
# GIA_MAIN.O
obj/gia_main.o: src/gia_main.c inc/giant.h
	${PETSC_COMPILE} -c ${CFLAGS} -o $@ $< -I./inc




##############################
# GIA_MESH.O
obj/gia_mesh.o: src/gia_mesh.c inc/list.h \
                ~/libs/parmetis-4.0.3/include/parmetis.h \
                ~/libs/parmetis-4.0.3/metis/include/metis.h
	${PETSC_COMPILE} -c ${CFLAGS} -o $@ $< 	-I./inc -I../../../libs/parmetis-4.0.3/include -I../../../libs/parmetis-4.0.3/metis/include 

##############################
# GIA_UTIL.O
obj/gia_util.o: src/gia_util.c inc/giant.h 
	${PETSC_COMPILE} -c ${CFLAGS} -o $@ $< 	-I./inc 


##############################
# LIST.O
obj/list.o: src/list.c inc/list.h 
	${PETSC_COMPILE} -c ${CFLAGS} -o $@ $< 	-I./inc



var:
	echo "PWD = " ${PWD}
	echo "PETSC_COMPILE = " ${PETSC_COMPILE}

clean_:	    
	rm -f obj/* giant

include ${PETSC_DIR}/lib/petsc/conf/variables	
include ${PETSC_DIR}/lib/petsc/conf/rules


	
