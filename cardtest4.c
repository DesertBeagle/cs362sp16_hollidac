#include <assert.h>
#include "dominion.h"

#define NUM_PLAYERS 4
#define SEED 5

int main(){
	int *kingdom = kindgomCards(7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	struct gameState *state;
	int i;
	
	initializeGame(NUM_PLAYERS, kingdom, SEED, &state);

	free(kingdom);
	return 0;
}
