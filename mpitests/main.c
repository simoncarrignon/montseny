#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define  MACRO   0
#define  MICRO   1

int solve_macro(MPI_Comm macrocomm, MPI_Comm intercomm);
int solve_micro(MPI_Comm microcomm, MPI_Comm intercomm);

int main(int argc, char **argv)
{

    int       rank;
    int       rank_n;
    int       size;
    int       color;
    MPI_Comm  world, intercomm, newcomm; 

    world = MPI_COMM_WORLD;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(world, &size);
    MPI_Comm_rank(world, &rank);

    color = (rank % 2 == 0) ? MACRO:MICRO;

    if(rank==0) printf("the size of the communicator is %d \n",size);
   
    MPI_Comm_split(world, color, 0, &newcomm);

    MPI_Comm_size(newcomm, &size);
    MPI_Comm_rank(newcomm, &rank_n);

    MPI_Barrier(world);
   
    if(color == MACRO){
	MPI_Intercomm_create(newcomm, 0, world, 1, 0, &intercomm);
    }else if(color == MICRO){
	MPI_Intercomm_create(newcomm, 0, world, 0, 0, &intercomm);
    }

    if(color == MACRO){

	solve_macro(newcomm, intercomm);

    }else{
	
	solve_micro(newcomm, intercomm);

    }

    MPI_Barrier(world);

    MPI_Comm_size(intercomm, &size);
//    if(rank==0) printf("the size of the inter-communicator is %d \n",size);
    printf("my rank is %d and the size of the inter-communicator is %d \n",rank,size);

    MPI_Barrier(world);
    printf("I was rank %d and now I am rank %d I belong to %s\n",rank,rank_n,(color==0)?"MACRO":"MICRO");

    MPI_Finalize();

    return 0;
}
