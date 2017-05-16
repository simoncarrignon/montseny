
/*
   Giant main function
 */


static char help[] = "Solves an RVE problem.\n\n";


#include "giant.h"


int main(int argc, char **args)
{


    ierr = PetscInitialize(&argc,&args,(char*)0,help);
    ierr = PetscOptionsGetBool(NULL,NULL,"-c",&couple,NULL);CHKERRQ(ierr);


    if(couple == PETSC_FALSE)
	ierr = PetscPrintf(PETSC_COMM_WORLD,"STARTING GIANT CODE\n");CHKERRQ(ierr);

    ierr = PetscFinalize();

    return 0;
}
