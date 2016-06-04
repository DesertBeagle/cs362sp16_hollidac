#include <assert.h>
#include "dominion.h"

#define NUM_PLAYERS 4
#define SEED 5

int main(){
	int *kingdom = kingdomCards(7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	struct gameState state;
	int i, player;
	
	initializeGame(NUM_PLAYERS, kingdom, SEED, &state);
	player = state.whoseTurn;

	state.hand[player][state.handCount[player]] = council_room;
	state.handCount[player]++;

	assert(council_room_card_f(&state, state.handCount[player]-1) == 0);

	assert(state.numBuys == 2);

	assert(state.handCount[player] == 9);

	for( i = 0; i < NUM_PLAYERS; i++){
		if(i != player){
			assert(state.handCount[i] == 1);
		}
	}

	free(kingdom);
	return 0;
}
