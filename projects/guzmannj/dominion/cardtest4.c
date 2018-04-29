/*
   Name: Jorge Guzman Nader
   Date: 4/29/18
   CS 362
 
   This test checks smithy card and its effects. This card
   gives the playes +3 cards when acctivated.
 */

#include "test_utils.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define NUM_PLAYERS 2
#define PLAYER_1 0
#define PLAYER_2 1

int main()
{
	struct gameState preG = {0};
	struct gameState postG = {0};

	/*
	 * Smithy is position one in player hand.
	 */
	preG.numPlayers = NUM_PLAYERS;
	memset ( &preG.supplyCount, 25,
			( ( treasure_map + 1 ) * sizeof ( preG.supplyCount[0] ) ) );
	memset ( &preG.embargoTokens, 0,
			( ( treasure_map + 1 ) * sizeof ( preG.embargoTokens[0] ) ) );
	preG.whoseTurn = PLAYER_1;
	preG.hand[PLAYER_1][0] = smithy;
	preG.handCount[PLAYER_1] = 1;

	/*
	 * Store state of game before card is being played.
	 */
	memcpy ( &postG, &preG, sizeof ( struct gameState ) );

	cardEffect ( smithy, -1, -1, -1, &postG, 0, NULL );

	printf ( "--------------------\n" );
	printf ( "START SMITHY TESTS\n" );
	printf ( "--------------------\n" );


	/*
	 * Test 1: Check player has three more cards
	 */
	asserttrue("Player has three more cards",
			postG.handCount[PLAYER_1] ==
			preG.handCount[PLAYER_1]);

	/*
	 * Test 2: Check if player has discarded smithy card from hand.
	 */
	asserttrue ("Player hand does not contain smithy",
	       	postG.hand[PLAYER_1][0] != smithy );
	asserttrue ("Player discard count incremented by one",
		       	postG.discardCount[PLAYER_1] ==  preG.discardCount[PLAYER_1] + 1 );
	asserttrue ("Player discard pile contains smithy",
		       	postG.discard[PLAYER_1][postG.discardCount[PLAYER_1]] == smithy );

	printf ( "--------------------\n" );
	printf ( "END SMITHY TESTS\n" );
	printf ( "--------------------\n" );


}