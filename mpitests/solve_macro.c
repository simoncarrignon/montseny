#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int solve_macro(MPI_Comm macroworld, MPI_Comm intercomm)
{

    int       rank;
    int       size;

    int       nval = 6;
    double    values[6] = { 0.1 ,0.2, 0.4, 0.0, -1.0, 6.0};

    MPI_Comm_size(macroworld, &size);
    MPI_Comm_rank(macroworld, &rank);

    MPI_Send(values,nval,MPI_DOUBLE,0,0,intercomm);

    printf("I am rank %d of %d i call from %s\n",rank,size,"solve_macro");

    return 0;
}
