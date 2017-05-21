/* 

 The idea with this program is to be executed by the first N_M process

 Simulates the macroscopic structure sending strains to an specific microscopic 
 processes and reciving sigmas and cts from these codes.

*/


#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define  MACRO   0
#define  MICRO   1


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

    if(rank != 0 || size > 2)
	return 1;

    color = MACRO;

    MPI_Comm_split(world, color, 0, &newcomm);
    MPI_Comm_size(newcomm, &size);
    MPI_Comm_rank(newcomm, &rank_n);

    //    printf("world rank %d and new rank %d I belong to %s\n",rank,rank_n,(color==0)?"MACRO":"MICRO");

    MPI_Intercomm_create(newcomm, 0, world, 1, 0, &intercomm);
    // local_comm, local_leader, peer_comm, remote_leader, tag, *newintercomm

    MPI_Comm_test_inter(intercomm, &flag);
    MPI_Comm_remote_size(intercomm, &size);

    printf("world rank = %d intercomm flag = %d size = %d\n",rank,flag,size);

    int       nval = 6;
    double    values[6] = { 0.1 ,0.2, 0.4, 0.0, -1.0, 6.0};

    MPI_Send(values,nval,MPI_DOUBLE,0,0,intercomm);

    MPI_Finalize();

    return 0;
}
