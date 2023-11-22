/*
This program checks if a given number is in a prime number
@author Mahmoud Moustafa; ID:3648276
*/
int isPrime(int i) {
	int lCounter = 3;
	if (i < 2) { //0 & 1 are not prime numbers
		return 0;
	}

	if (i == 2) //2 is a prime number
	{
		return 1;
	}

	while (lCounter < i){ // as long as counter < input check if there is a remainder and output accordingly
		if(i % lCounter == 0){
			return 0;
		}
		lCounter++;
	}
	return 1;
}
