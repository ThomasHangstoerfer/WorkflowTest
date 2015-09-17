#include <stdio.h>

/*
   This causes a seg-fault.
   For testing core-handler
*/
void crash()
{
  printf("Bazinga!\n");
  volatile int* a = (int*)(NULL);
  *a = 1;
}

// call another function to have a more interesting callstack in the core-dump
int doSomething()
{
	printf("Now crashing...\n");
	crash();
	//printf("Now sleeping...\n");
	//sleep(4000);
	//printf("done.\n\n");
}

int test(int in)
{
	int res = 5 * in;
	printf("test(%i): %i\n", in, res);
	doSomething();
	return res;
}


int main()
{
	printf("Hello World!\n");
	test(3);
	return 0;
}
