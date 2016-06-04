#include <assert.h>
#include "dominion.h"

#define NUM_PLAYERS 4
#define SEED 5

int main(){
	int *kingdom = kingdomCards(7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	struct gameState state;
	int i, player = whoseTurn(&state), c1 = 0, c2 = 0;

	int startCoins;
	
	initializeGame(NUM_PLAYERS, kingdom, SEED, &state);
	assert(cardEffect(baron, 0, 0, 0, &state, 0, 0) == 0);

	assert(fullDeckCount(player, estate, &state) == 4);

	initializeGame(NUM_PLAYERS, kingdom, SEED, &state);

	
	startCoins = state.coins;

	for(i = 0; i < state.handCount[player];	i++){
		if(state.hand[player][i] == estate){
			c1++;
		}
	}
 
	assert(cardEffect(baron, 1, 0, 0, &state, 0, 0) == 0);


	assert(state.numBuys == 2);
	for(i = 0; i < state.handCount[player];	i++){
		if(state.hand[player][i] == estate){
			c2++;
		}
	} 
	printf("%d->%d", c1, c2);
	if(c1 == 0){
		assert(c2 == 1);
	}
	else{
		assert(c2 == c1 - 1);
		assert(state.coins == startCoins + 4);
		assert(state.discardCount[player] == 1);
	}


	free(kingdom);
	return 0;
}
