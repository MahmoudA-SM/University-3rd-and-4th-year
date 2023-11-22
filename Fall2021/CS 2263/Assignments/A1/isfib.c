/*
This program checks if a given number is in the Fibonacci Sequence
 @author Mahmoud Moustafa; ID:3648276
*/
//if number is in the Fibonacci sequence return 1, otherwise 0
int isFib(int i) {
	int m = 0;
	int n = 1;
	int o = m + n;
	if (i == 0 || i == 1) // 0 and 1 exist in the Fibonacci sequence
	{
		return 1;
	}
	else
	{
		while (o <= i) //as long as o < input, check if they are equal, if not increment accordingly
					  // until they are == or o>i and output accordingly
		{
			if (o == i)
			{
				return 1;
			}
			m = n;
			n = o;
			o = m + n;
		}
		return 0;
	}
}
