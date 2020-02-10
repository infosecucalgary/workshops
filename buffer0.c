#include <stdio.h>
#include <stdlib.h>

int main(){
	char buffer[44];
	printf("Enter your name:\n");
	gets(buffer);
	printf("Your name is: %s\n", buffer);

	return 0;
}
