unsigned long sum( int max_number )
{
	unsigned long sum_value = 0;

	for ( int cnt = 0; cnt < max_number; cnt++ )
	{
		sum_value = sum_value + cnt;
	}
	return sum_value;
}
