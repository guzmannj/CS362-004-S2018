#include "test_utils.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main ()
{
	int i, j;
	int adventurerPos, whoseTurn, numTreasureCards, treasurePos1,
	    treasurePos2, treasure1, treasure2, preHandCount, postHandCount;
	int card;
	int numTests = 1000;
	struct gameState preG, postG;

	srand(time(NULL));

	for ( i = 0; i < numTests; ++i )
	{
		printf("------------------\n");
		printf( "TEST %d\n", (i+1) );
		printf("------------------\n");

		/* Generate random game state */
		randomizeGame( &preG );

		/* Place adventurer card into random position in hand. This
		 * guarantees the random game state has at least one
		 * adventurer card in hand. */
		adventurerPos = rand() % preG.handCount[preG.whoseTurn];
		preG.hand[preG.whoseTurn][adventurerPos] = adventurer;

		/* Store state of game */
		memcpy( &postG, &preG, sizeof( preG ) );

		/* Play card */
		cardEffect ( adventurer, -1, -1, -1, &postG, adventurerPos, NULL );

		/**
		  * Get some data for oracle
		  */

		whoseTurn = preG.whoseTurn;
		preHandCount = preG.handCount[whoseTurn];
		postHandCount = postG.handCount[whoseTurn];
		
		/* Determine if there were any treasure cards in deck and, if
		 * so, their position and what they were. */
		numTreasureCards = 0;
		treasurePos1 = -1;
		treasurePos2 = -1;
		treasure1 = -1;
		treasure2 = -1;
		for ( j = 0; j < preG.deckCount[whoseTurn] && numTreasureCards < 2; j++ )
		{
			card = preG.deck[preG.whoseTurn][j];

			if ( card == copper || card == silver || card == gold )
			{
				if ( treasurePos1 == -1 )
				{
					treasurePos1 = j;
					treasure1 = card;
				}
				else if ( treasurePos2 == -1 )
				{
					treasurePos2 = j;
					treasure2 = card;
				}
				numTreasureCards++;
			}
		}

		/* Confirm these treasure cards are now in player hand */
		asserttrue( "Hand count",
		            postHandCount == preHandCount + numTreasureCards );
		if ( numTreasureCards == 2 )
		{
			asserttrue( "First treasure",
					postG.hand[whoseTurn][postHandCount-1]
					== treasure2 );
			asserttrue( "Second treasure",
					postG.hand[whoseTurn][postHandCount-2]
					== treasure1 );
		}
		else if ( numTreasureCards == 1 )
		{
			asserttrue ( "First treasure",
					postG.hand[whoseTurn][postHandCount-1]
					== treasure1 );
		}
	}

	return 0;
}