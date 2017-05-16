
/*
   Giant mesh partition routines
 */


#include "parmetis.h"
#include "gmsh_ops.h"

int gia_part(void)
{

    /*
       Performes the partition of the mesh saved on the mesh structures.
     */

    //  ParMETIS_V32_Mesh2Dual (
    //      idx t *elmdist, idx t *eptr, idx t *eind, idx t *numflag, idx t *ncommonnodes,
    //      idx t **xadj, idx t **adjncy, MPI Comm *comm
    //      )

    return 0;
}

int gia_rmsh(char *mesh_n, char *mesh_f)
{
    /*
       Reads the mesh according to the format specified
     */

    return 0;
}
