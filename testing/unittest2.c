#include "dominion.h"
#include <assert.h>

int main(){
	int numPlayers = 4;
	int i, j;
	struct gameState state;
	//make deck
	for (i = 0; i < numPlayers; i++)
        {
        	state.deckCount[i] = 0;
        	state.handCount[i] = 0;
        	state.discardCount[i] = 0;
                for (j = 0; j < 3; j++)
                {
                	 state.deck[i][j] = estate;
                         state.deckCount[i]++;
                }
		for(j = 0; j < 5; j++){
			state.discard[i][j] = estate;
			state.discardCount[i]++;
		}
		for(j = 0; j < 10; j++){
			state.hand[i][j] = estate;
			state.handCount[i]++;
		}
        }
	//call fullDeckCount(player, card, state)
	for(i = 0; i < numPlayers; i++){
		assert(fullDeckCount(i, estate, &state) == 18);
	}
	puts("Unit test 2: pass");
	return 0;
}
