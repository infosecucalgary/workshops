#include <stdio.h>
#include <string.h>

static char *rand_string(char *str, size_t size)
{
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJK...";
    if (size) {
        --size;
        for (size_t n = 0; n < size; n++) {
            int key = rand() % (int) (sizeof charset - 1);
            str[n] = charset[key];
        }
        str[size] = '\0';
    }
    return str;
}


int verifyPassword(){
	int r;
	char password[16];
	char buffer[16];
	rand_string(password, sizeof(password));
	printf("Please enter your password:\n");
	gets(buffer);
	r = memcmp(password, buffer, sizeof(buffer));
	return !r;
}

void main(){
	if (verifyPassword()){
		printf("Password matches!\n");
	}
	else {
		printf("Incorrect password.  Login attempt reported to administrator.\n");
	}
}
