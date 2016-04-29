#include <assert.h>
#include "dominion.h"

#define NUM_PLAYERS 4
#define SEED 5

int main(){
	int *kingdom = kingdomCards(7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	struct gameState state;
	int i, player;
	
	initializeGame(NUM_PLAYERS, kingdom, SEED, &state);

	player = whoseTurn(&state);

	state.hand[player][state.handCount[player]] = smithy;
	state.handCount[player]++;

	assert(cardEffect(smithy, 0, 0, 0, &state, state.handCount[player] - 1, 0) == 0);
	
	assert(state.handCount[player] == 8);

	
	free(kingdom);

	return 0;
}
