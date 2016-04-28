#include "dominion.h"
#include <assert.h>
#include <stdio.h>
#define SEED 1

int main(){
	struct gameState state;
	int i, j, estates = 0, coppers = 0, numPlayers = 4;
	int kingdomCards[10] = {7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
	int kingdomCards2[10] = {8, 8, 10, 11, 12, 13, 14, 15, 16, 17};

	assert(initializeGame(numPlayers, kingdomCards2, SEED, &state) == -1);
	assert(initializeGame(numPlayers+1, kingdomCards, SEED, &state) == -1);
	assert(initializeGame(numPlayers, kingdomCards, SEED, &state) == 0);

	assert(state.supplyCount[curse] == 30);
	assert(state.supplyCount[estate] == 12);
	assert(state.supplyCount[duchy] == 12);
	assert(state.supplyCount[province] == 12);
	
	assert(state.supplyCount[copper] ==  60 - (7 * numPlayers) );
	assert(state.supplyCount[silver] == 40);
	assert(state.supplyCount[gold] == 30);
	
	for(i = adventurer; i < adventurer + 10; i++){
		if(kingdomCards[i-7] == great_hall || kingdomCards[i-7] == gardens){
			assert(state.supplyCount[i] == 12);
		}
		else{
			assert(state.supplyCount[i] == 10);
		}
	}

	for(i = 0; i < numPlayers; i++){
		if(i == state.whoseTurn){
			assert(state.deckCount[i] == 5);
			assert(state.handCount[i] == 5);
		}
		else{
			assert(state.deckCount[i] == 10);
			assert(state.handCount[i] == 0);
		}
		for(j = 0; j < state.deckCount[i]; j++){
			if(state.deck[i][j] == estate){
				estates++;
			}
			else{
				coppers++;
			}
		}
		for(j = 0; j < state.handCount[i]; j++){
			if(state.hand[i][j] == estate){
				estates++;
			}
			else{
				coppers++;
			}
		}
		assert(estates == 3);
		assert(coppers == 7);
		estates = 0;
		coppers = 0;
	}
	
	for(i = adventurer; i < treasure_map+1; i++){
		assert(state.embargoTokens[i] == 0);
	}

	assert(state.outpostPlayed == 0);
        assert(state.phase == 0);
        assert(state.numActions == 1);
        assert(state.numBuys == 1);
        assert(state.playedCardCount == 0);
        assert(state.whoseTurn == 0);
        assert(state.handCount[state.whoseTurn] == 5);
	
	coppers = 0;

	for(i = 0; i < state.handCount[state.whoseTurn]; i++){
		if(state.hand[state.whoseTurn][i] == copper){
			coppers++;
		}
	}	
	assert(state.coins == coppers);	
	
	
	return 0;
}
