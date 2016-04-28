#include "dominion.h"
#include <assert.h>

int main(){
	int a, b;
	a = b = 6;
	assert(compare(&a, &b) == 0);
	a++;
	assert(compare(&a, &b) == 1);
	a-=2;
	assert(compare(&a, &b) == -1);
	return 0;
}
