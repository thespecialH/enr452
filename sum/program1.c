#include <stdio.h>

int main( void )
{
	long sum_value = 0;
	unsigned int last_digit=15;

	for ( int cnt = 0; cnt < last_digit; cnt++ )
	{
		sum_value = sum_value + cnt;
	}
	printf( "Hello World, the sum from 0 to %d is %ld\n", last_digit, sum_value );
	return 0;
}
