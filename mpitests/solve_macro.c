#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int solve_macro(MPI_Comm macroworld, MPI_Comm intercomm)
{

    int       rank;
    int       size;

    MPI_Comm_size(macroworld, &size);
    MPI_Comm_rank(macroworld, &rank);

    printf("I am rank %d of %d i call from %s\n",rank,size,"solve_macro");

    return 0;
}
