#include "dominion.h"
#include <assert.h>
#include <stdio.h>

#define NUM_PLAYERS 4
#define SEED 5

int main(){
	int *kingdom = kingdomCards(7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	struct gameState state;
	int i, c1 = 0, c2 = 0;
	
	initializeGame(NUM_PLAYERS, kingdom, SEED, &state);

	for(i = 0; i < state.handCount[state.whoseTurn]; i++){
		if(state.hand[state.whoseTurn][i] == copper){
			c1++;
		}
	}
	assert(cardEffect(adventurer, 0, 0, 0, &state, 0, 0) == 0);
	
	for(i = 0; i < state.handCount[state.whoseTurn]; i++){
		if(state.hand[state.whoseTurn][i] == copper){
			c2++;
		}
	}


	assert(state.handCount[state.whoseTurn] == 7);
	assert((c2-c1) == 2);
	free(kingdom);
	return 0;
}
