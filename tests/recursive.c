#include <stdio.h>

int fipo(int x){
	if (x == 0 || x == 1)
		return x;
	return (fipo(x-2) + fipo(x-1));
}

int main(void)
{
	printf("fipo 90: %d\n", fipo(90));
}
