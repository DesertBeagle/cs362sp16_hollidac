#include <string.h>

int isint(char * str){
	int i = 0;
	for(; str[i] != '\0' && str[i] <= '9' && str[i] >= '0'; i++){}
	return (i == strlen(str));
}

int allint(char *argv[], int argc, int expected){
	int i;
	if(argc != expected){
		printf("Please use only %d argument(s)\n", expected);
		return 0;
	}
	for(i = 1; i < expected; i++){
		if(!isint(argv[i])){
			puts("Please use an integer as a command line argument!\n");
			return 0;
		}
	}
	return 1;
}
