#include <stdlib.h>
#include "util.h"
#include "dominion.h"

int main(int argc, char *argv[]){
	struct gameState game;
	int *kingd = kingdomCards(8, 9, 11, 12, 13, 14, 15, 16, 17, 18);
	int seed;
	if(!allint(argv, argc, 2)){
		return 0;
	}
	seed = atoi(argv[1]);
	return 0;
}
