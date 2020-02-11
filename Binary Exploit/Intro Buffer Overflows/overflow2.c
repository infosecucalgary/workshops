#include <stdio.h>
#include <stdlib.h>

void printMe(){
	printf("Well done! You overflowed the buffer!\n");
	}

void totallySafe(){
	char buffer[40];
	gets(buffer);
}

int main(){
	printf("Enter input: ");
	totallySafe();

	return 0;
	}




