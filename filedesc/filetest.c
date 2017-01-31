#include <stdio.h>

int test(char *filename) 
{
FILE *f=NULL;

	f = fopen(filename,"wt");
	return 0;
}


int main() {

	test("hello.txt");

	return 0;
}
