#include "test_utils.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <string.h>

int main ()
{
	int i, j, k;
	int greatHallPos, whoseTurn;
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

		/* Place Great Hall card into random position in hand. This
		 * guarantees the random game state has at least one
		 * adventurer card in hand. */
		greatHallPos = rand() % preG.handCount[preG.whoseTurn];
		preG.hand[preG.whoseTurn][greatHallPos] = great_hall;

		/* Store state of game */
		memcpy( &postG, &preG, sizeof( preG ) );

		/* Play card */
		cardEffect ( great_hall, -1, -1, -1, &postG, greatHallPos, NULL );

		/**
		  * Get data for oracle
		  */
		whoseTurn = preG.whoseTurn;

		/* Test player has one more action */
		asserttrue( "Actions increased", postG.numActions ==
				preG.numActions + 1 );

		/* Discard pile contains Great Hall card */
		asserttrue("Player discard count incremented by one",
		            postG.discardCount[whoseTurn]
			    == preG.discardCount[whoseTurn] + 1);
		asserttrue("Player discard pile contains Great Hall card",
		           postG.discard[whoseTurn][postG.discardCount[whoseTurn]-1] == 
				great_hall);

		/* Test that player has one extra card, if deck had >= 1 card.
		 */
		if ( preG.deckCount[whoseTurn] == 0 )
		{
			asserttrue( "Player hand count",
					postG.handCount[whoseTurn] ==
					preG.handCount[whoseTurn] - 1 );
		}
		else if ( preG.deckCount[whoseTurn] >= 1 )
		{
			asserttrue( "Player hand count",
					postG.handCount[whoseTurn] ==
					preG.handCount[whoseTurn] );
		}
	}

	return 0;
}