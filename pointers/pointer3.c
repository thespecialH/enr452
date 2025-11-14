#include <stdio.h>

void inches_2_feet(int distance, int *feet, int *inches)
{
	*feet = distance / 12;
	*inches = distance % 12;

}

int main(void) {
	
	int measurement = 71;
	int feet = 0;
	int inches = 0;

	printf("Distance: %d\n", measurement);
	inches_2_feet(measurement, &feet, &inches);
	printf("feet: %d, inches: %d\n", feet, inches);

}
