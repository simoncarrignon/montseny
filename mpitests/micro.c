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

    MPI_Comm  world, intercomm, microcomm; 
    MPI_Status status;

    world = MPI_COMM_WORLD;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(world, &size);
    MPI_Comm_rank(world, &rank);

    if(rank != 1 || size > 2)
	return 1;

    color = MICRO;

    MPI_Comm_split(world, color, 0, &microcomm);
    MPI_Comm_size(microcomm, &size);
    MPI_Comm_rank(microcomm, &rank_n);

    //    printf("world rank %d and new rank %d I belong to %s\n",rank,rank_n,(color==0)?"MACRO":"MICRO");

    MPI_Intercomm_create(microcomm, 0, world, 0, 0, &intercomm);
    // local_comm, local_leader, peer_comm, remote_leader, tag, *newintercomm

    MPI_Comm_test_inter(intercomm, &flag);
    MPI_Comm_remote_size(intercomm, &size);

    printf("world rank = %d intercomm flag = %d size = %d\n",rank,flag,size);

    int       nval = 6;
    double    values[] = { 0.0 ,0.0, 0.0, 0.0, 0.0, 0.0};

    MPI_Comm_size(intercomm, &size);
    MPI_Comm_rank(intercomm, &rank);

    printf("micro rank %d of %d i call from %s\n values %lf %lf %lf %lf %lf %lf \n",rank,size,"solve_micro",values[0],values[1],values[2],values[3],values[4],values[5]);

    if(rank==0)
	MPI_Recv(values,nval,MPI_DOUBLE,0,0,intercomm,&status);

    printf("micro rank %d of %d i call from %s\n values %lf %lf %lf %lf %lf %lf \n",rank,size,"solve_micro",values[0],values[1],values[2],values[3],values[4],values[5]);

    MPI_Finalize();

    return 0;
}
