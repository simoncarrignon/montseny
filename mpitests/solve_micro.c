#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int solve_micro(MPI_Comm microworld, MPI_Comm intercomm)
{

    int       rank;
    int       size;

    MPI_Comm_size(microworld, &size);
    MPI_Comm_rank(microworld, &rank);

    printf("I am rank %d of %d i call from %s\n",rank,size,"solve_micro");

    return 0;
}
