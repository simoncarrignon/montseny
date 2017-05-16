
/*
   Giant main function
 */


static char help[] = "Solves an RVE problem.\n\n";


#include "giant.h"


int main(int argc, char **args)
{

    char       mesh_n[64];
    char       mesh_f[4];

    PetscBool  set;
    

    ierr = PetscInitialize(&argc,&args,(char*)0,help);

    // read options from command line 
    //    
    // couple flag ( 1:coupled 0:not coupled) -> -c 1
    //
    ierr = PetscOptionsGetBool(NULL,NULL,"-c",&couple_fl,&set);CHKERRQ(ierr);
    if(set == PETSC_FALSE){
	couple_fl = PETSC_FALSE;
    }
    ierr = PetscPrintf(PETSC_COMM_WORLD,"coupling    : %d\n",couple_fl);CHKERRQ(ierr);
    //
    // mesh file format  -> -mfor gmsh
    //
    ierr = PetscOptionsGetString(NULL,NULL,"-mfor",mesh_f,16,&set);CHKERRQ(ierr);
    if(set == PETSC_FALSE){
	strcpy(mesh_f,"gmsh");
    }
    ierr = PetscPrintf(PETSC_COMM_WORLD,"mesh format : %s\n",mesh_f);CHKERRQ(ierr);
    //
    // mesh file name    -> -mesh rve/cube_unif/cube.msh
    //
    ierr = PetscOptionsGetString(NULL,NULL,"-mesh",mesh_n,16,&set);CHKERRQ(ierr);
    if(set == PETSC_FALSE){
	strcpy(mesh_n,"rve/cube_unif/cube.msh");
    }
    ierr = PetscPrintf(PETSC_COMM_WORLD,"mesh file   : %s\n",mesh_n);CHKERRQ(ierr);
    //

    // read mesh
    //    
    ierr = gia_rmsh(mesh_n, mesh_f);

    ierr = PetscFinalize();

    return 0;
}
