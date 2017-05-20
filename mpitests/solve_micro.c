#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int solve_micro(MPI_Comm microworld, MPI_Comm intercomm)
{

    int        rank;
    int        size;

    int        nval=6;
    double     values[] = { 0.0 ,0.0, 0.0, 0.0, 0.0, 0.0};

    MPI_Status status;

    MPI_Comm_size(microworld, &size);
    MPI_Comm_rank(microworld, &rank);

    printf("micro rank %d of %d i call from %s\n values %lf %lf %lf %lf %lf %lf \n",rank,size,"solve_micro",values[0],values[1],values[2],values[3],values[4],values[5]);

    if(rank==0)
	MPI_Recv(values,nval,MPI_DOUBLE,0,0,intercomm,&status);

    printf("micro rank %d of %d i call from %s\n values %lf %lf %lf %lf %lf %lf \n",rank,size,"solve_micro",values[0],values[1],values[2],values[3],values[4],values[5]);

    return 0;
}
