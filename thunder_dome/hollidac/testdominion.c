#include "dominion.h"
#include "util.h"
#include <stdlib.h>
#include <stdio.h>
#include <termios.h>

char getch() {
	char buf = 0;
	struct termios old = {0};
	if (tcgetattr(0, &old) < 0)
		perror("tcsetattr()");
	old.c_lflag &= ~ICANON;
	old.c_lflag &= ~ECHO;
	old.c_cc[VMIN] = 1;
	old.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &old) < 0)
		perror("tcsetattr ICANON");
	if (read(0, &buf, 1) < 0)
		perror ("read()");
	old.c_lflag |= ICANON;
	old.c_lflag |= ECHO;
	if (tcsetattr(0, TCSADRAIN, &old) < 0)
		perror ("tcsetattr ~ICANON");
	return (buf);
}

void printGame(struct gameState *game){
	int i, j;
	printf("Full Game State:\n");
	printf("Number of players: %d\n", game->numPlayers);
	printf("Supplies:\n");
	for(i = 0; i < treasure_map+1; i++){
		printf("\tSupply: %d\tCount: %d\tEmbargo tokens: %d\n", i, game->supplyCount[i], game->embargoTokens[i]);;
	}
	printf("Outpost played: %d\tOutpost Turn: %d\n", game->outpostPlayed, game->outpostTurn);
	printf("Phase: %d\tNumber of actions: %d\t Coins: %d\tNumber of buys: %d\n", game->phase, game->numActions, game->coins, game->numBuys);

	for(i = 0; i < game->numPlayers; i++){
		printf("Player %d:\n\tHand Count: %d\n\t\t", i+1, game->handCount[i]);
		for(j = 0; j < game->handCount[i]; j++){
			printf("%d ", game->hand[i][j]);
		}
		printf("\n\tDeck Count: %d\n\t\t", game->deckCount[i]);
		for(j = 0; j < game->deckCount[i]; j++){
			printf("%d ", game->deck[i][j]);
		}
		printf("\n\tNum Discard: %d\n\t\t", game->discardCount[i]);
		for(j = 0; j < game->discardCount[i]; j++){
			printf("%d ", game->discard[i][j]);
		}
		puts("");
	}

	printf("\nPlayed Cards: %d\n\t", game->playedCardCount);
	for(i = 0; i < game->playedCardCount; i++)
		printf("%d ", game->playedCards[i]);
	puts("");
	fflush(stdout);
}


int main(int argc, char *argv[]){
	int seed, king[10], i,j,k;
	int players[MAX_PLAYERS];
	int numPlayers, handCount;

	struct gameState *game = newGame();

	//====================SETUP=SPAGHETTI=============================
	if(!allint(argv, argc, 2)){
		return 0;
	}
	seed = atoi(argv[1]);
	srand(seed);

	for(i = 0; i < 10; i++){
		king[i] = rand()%(treasure_map - adventurer + 1) + adventurer;
		for(j = 0; j < i; j++){
			if(king[i] == king[j]){
				i--;
			}
		}
	}

	numPlayers = rand()%2 + 3;

	initializeGame(numPlayers, king, seed, game);
	//================================================================

	while(!isGameOver(game)){
		handCount = game->handCount[game->whoseTurn];
		printGame(game);
		//getch();
		for(k = 0; k < game->numActions; k++){
			printf("Player %d actions: \n", game->whoseTurn+1);
			for(i = 0; i < handCount; i++){
				if(game->hand[game->whoseTurn][i] > 6){

					//if the random choices mess up and make playcard return -1, then try and play again with
					//different choices. If there's really no way, then quit out after 500 plays
					for(j = 0; playCard(i, rand()%handCount, rand()%handCount, rand()%handCount, game) && j < 10; j++){}

					//If it's really having trouble, then move onto the next card
					if(j >= 10) {
						continue;
					}
					printf("Card %d played by player %d!\n", game->hand[game->whoseTurn][i], game->whoseTurn+1);

					break;
				} 
			}
			printGame(game);
		}


		for(k = 0; k < game->numBuys; k++){
			do{
				i = rand()%(treasure_map + 1);
				if(getCost(i) - game->coins < 3)
					j = buyCard(i, game);
			}while(j);
			printf("Player %d bought card %d\n", game->whoseTurn+1, i);
			printGame(game);
		}

		endTurn(game);
		printGame(game);
	}
	getWinners(players, game);	

	for(i = 0; i < MAX_PLAYERS; i++){
		if(players[i])
			printf("Player %d won!\n", i+1);
		else
			printf("Player %d did not win!\n", i+1);
	}

	return 0;
}
