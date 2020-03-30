#include <stdio.h>

int main()
{
	int number1;
	unsigned int number2;

	printf("Enter a number.\n");
	scanf("%d", &number1);
	printf("Enter the same number again.\n");
	scanf("%u", &number2);

	printf("The first number is: %d\n", number1);
	printf("The second number is: %u\n", number2);

	return 0;
}
