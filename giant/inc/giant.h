/*
   giant external lybraries
*/

#include "petscksp.h"

/*
   giant global variables 
*/

PetscErrorCode ierr;
PetscBool      couple_fl; //  couple flag = 0|1 (o:not coupled, 1:coupled)

/*
   giant function definitions
*/

// gia_main.c 
int main(int argc, char **args);

// gia_mesh.c
int gia_rmsh(char *mesh_n, char *mesh_f);
