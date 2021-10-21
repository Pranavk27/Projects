#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Carry(int number1,int number2,int c)
{
	if (number1 == 0 && number2 == 0)
		return 0;
	if (number1 != 0 && number2 == 0)
		c  = (number1&c&1);
	else if (number2 != 0 && number1 == 0)
		c  = (number2&c&1);
	else if (c == 1)
	{
//		printf("Carry-1 %d\n",c);
		int a = number1&1;
		int b = number2&1;
		if (a== 0 && b == 0)
			c = 0;
//		printf("Carry-1 %d\n",c);
	}
	else
		c  = (number1&number2&1);
//	printf("Carry %d\n",c);
	int Result = Carry(number1>>1,number2>>1,c)<<1;
//	printf("Num1 %d Num2 %d Result  %d\n",number1,number2,Result);
	return Result|c;	
}

int Sum(int number1,int number2)
{
	int c  = (number1&number2&1);
//	printf("Carry %d\n",c);
	int r  = Carry(number1>>1,number2>>1,c)<<1;
	c = (r|c)<<1;
//	printf("Result carry %d\n",c);
	int Result = number1 ^ number2 ^ c;
	return Result;
}

int Multiply(int number1, int number2)
{
	int x = number1;
	for(int i=0; i<number2-1; i++)
	{
		x = Sum(x,number1);
//		printf("Result - %d\n",x);
	}
	return x;
}
int main(int argc, char *argv[])
{
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	printf("Multiplication - %d\n",Multiply(a,b));
	struct timespec tstart={0,0}, tend={0,0};
	clock_gettime(CLOCK_MONOTONIC, &tstart);
	for(int i=0 ;i < 10000; i++)
	{
		Multiply(a,i);
	}
	clock_gettime(CLOCK_MONOTONIC, &tend);
	printf("some_long_computation took about %.5f seconds\n",
			((double)tend.tv_sec + 1.0e-9*tend.tv_nsec) -
			((double)tstart.tv_sec + 1.0e-9*tstart.tv_nsec));
	return 0;
}

