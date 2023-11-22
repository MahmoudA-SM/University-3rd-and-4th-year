//This program prints out the integer value 65 as %d, %4d, %x, %o, and %c 
//@author Mahmoud Moustafa; ID:3648276
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char * * argv)
{
	printf("65 printed with %%d is %d\n", 65); //65 is printed as a decimal integer
	printf("65 printed with %%4d is %4d\n", 65); //65 is printed as a decimal integer with a width of 4
	printf("65 printed with %%x is %x\n", 65); //65 is printed as a hexadecimal
	printf("65 printed with %%o is %o\n", 65);// 65 is printed as an octal
	printf("65 printed with %%c is %c\n", (char)65);//65 is printed as a char
	
	return EXIT_SUCCESS;
}
