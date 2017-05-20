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
    int       flag;
    MPI_Comm  world, intercomm, newcomm; 

    world = MPI_COMM_WORLD;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(world, &size);
    MPI_Comm_rank(world, &rank);

    color = (rank % 2 == 0) ? MACRO:MICRO;

    MPI_Comm_split(world, color, 0, &newcomm);
    MPI_Comm_size(newcomm, &size);
    MPI_Comm_rank(newcomm, &rank_n);

    printf("world rank %d and new rank %d I belong to %s\n",rank,rank_n,(color==0)?"MACRO":"MICRO");

    if(color == MACRO){
	MPI_Intercomm_create(newcomm, 0, world, 1, 0, &intercomm);
    }else if(color == MICRO){
	MPI_Intercomm_create(newcomm, 0, world, 0, 0, &intercomm);
    }
    // local_comm, local_leader, peer_comm, remote_leader, tag, *newintercomm

    MPI_Comm_test_inter(intercomm, &flag);
    MPI_Comm_remote_size(intercomm, &size);

    printf("world rank = %d intercomm flag = %d size = %d\n",rank,flag,size);

    if(color == MACRO){
	solve_macro(newcomm, intercomm);
    }else{
	solve_micro(newcomm, intercomm);
    }

    MPI_Finalize();

    return 0;
}
