
/*
   Giant main function
 */


static char help[] = "Solves an RVE problem.\n\n";


#include "giant.h"


int main(int argc, char **args)
{

    char       mesh_n[16];
    char       mesh_f[16];

    PetscBool  set;
    

    ierr = PetscInitialize(&argc,&args,(char*)0,help);

    /* read options from command line */
    //    
    // couple flag ( 1:coupled 0:not coupled) -> -c 1
    ierr = PetscOptionsGetBool(NULL,NULL,"-c",&couple_fl,&set);CHKERRQ(ierr);
    // mesh file format  -> -mfor gmsh
    ierr = PetscOptionsGetString(NULL,NULL,"-mfor",mesh_f,16,&set);CHKERRQ(ierr);
    // mesh file name    -> -mesh guido.msh
    ierr = PetscOptionsGetString(NULL,NULL,"-mesh",mesh_n,16,&set);CHKERRQ(ierr);
    //

    ierr = gia_rmsh(mesh_n, mesh_f);

    if(couple_fl == PETSC_FALSE)
	ierr = PetscPrintf(PETSC_COMM_WORLD,"STARTING GIANT CODE\n");CHKERRQ(ierr);
	

    ierr = PetscFinalize();

    return 0;
}
