#include <stdlib.h>
#include "dominion.h"
#include <assert.h>

int main(){
	int *array = kingdomCards(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
	int i;
	for(i = 0; i < 10; i++)
		assert(array[i] ==i+1);
	free(array);
	puts("Unit test 1: pass");
	return 0;
}
