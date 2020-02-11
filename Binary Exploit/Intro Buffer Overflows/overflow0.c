#include <stdio.h>
#include <string.h>

void pourItOnDoc(char * str){
	char buffer[4];
	strcpy(buffer, str);
}


int main(){
	char letters[128];
	int i;
	for(i=0; i<128; ++i) letters[i] = 'a';
	pourItOnDoc(letters);
	return 0;
}
