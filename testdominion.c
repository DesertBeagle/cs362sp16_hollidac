#include "dominion.h"
#include <stdlib.h>

int main(int argc, char *argv[]){
	int seed, k[10], i,j,k;
	int numPlayers, handCount;

	struct gameState *game = newGame();

	//====================SETUP=SPAGHETTI=============================
	if(allint(argv, argc, 2)){
		return 0;
	}
	seed = atoi(argv[1]);
	srand(seed);

	for(i = 0; i < 10; i++){
		k[i] = rand()%(treasure_map - adventurer + 1) + adventurer;
		for(j = 0; j < i-1; j++){
			if(k[i] == k[j]){
				i--;
			}
		}
	}

	numPlayers = rand()%4 + 1;

	initializeGame(numPlayers, k, seed, game);
	//================================================================

	while(!isGameOver(game)){
		handCount = game->handCount[game->whoseTurn];

		for(k = 0; k < game->numActions; k++){
			for(i = 0; i < handCount; i++){
				if(game->hand[game->whoseTurn][i] > 6){
					//if the random choices mess up and make playcard return -1, then try and play again with
					//different choices. If there's really no way, then quit out after 500 plays
					for(j = 0; playCard(i, rand()%handCount, rand()%handCount, rand()%handCount, game) && j < 100; j++){}

					//If it's really having trouble, then move onto the next card
					if(j >= 100) {
						continue;
					}
					break;
				} 
			}
		}

		for(k = 0; k < game->numBuys; k++){
			while(buyCard(rand()%(treasure_map + 1), game)){}
		}
		endTurn(game);
	}	

	return 0;
}
