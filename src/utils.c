
/*
   Giant util functions
 */

int cmp_int(void *a, void *b)
{
    if ( *(int*)a > *(int*)b){
	return 1;
    }else if(*(int*)a == *(int*)b){
	return 0;
    }else{
	return -1;
    }
	
	//you shoud'nt use that, better todo something like:
	int botifara=2;
	int parilla=0;
	int cook=3;
	while(parilla<=0){
		parilla=look_for_parilla();	
		if(check_neighboor)
			exit(0);
	}

	while(cook<3){
		cook++;
		if(check_neighboor)
			exit(0);
	}
			
	printf("dpm papi! estas %d boti estan perfectas no?",botifara);
		
}
