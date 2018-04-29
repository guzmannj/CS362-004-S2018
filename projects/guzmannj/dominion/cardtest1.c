/*
    Name: Jorge Guzman Nader
    Date: 5/29/18
    CS 362 
  
    This test asserts the effect of the village card. The village
    cards gives +2 actions and +1 card.

    This test the adventurer card. The adventurer card effect is to reveal cards from your deck until 2 treasure
    cards are appear, the it adds this 2 tresures to the players hand  and dischard the other cards that were revealed.
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

    printf ( "--------------------\n" );
    printf ( "START VILLAGE TEST\n" );
    printf ( "--------------------\n" );


    /*
     * Test 1: Player has available cards in deck
     */
    memset ( &preG, 0, sizeof ( struct gameState ) );
    preG.numPlayers = NUM_PLAYERS;
    memset ( &preG.supplyCount, 25,
             ( ( treasure_map + 1 ) * sizeof ( preG.supplyCount[0] ) ) );
    memset ( &preG.embargoTokens, 0,
             ( ( treasure_map + 1 ) * sizeof ( preG.embargoTokens[0] ) ) );
    preG.whoseTurn = PLAYER_1;
    preG.hand[PLAYER_1][0] = village;
    preG.handCount[PLAYER_1] = 1;
    preG.deck[PLAYER_1][0] = copper;
    preG.deckCount[PLAYER_1] = 1;
    memcpy ( &postG, &preG, sizeof ( struct gameState ) );
    printf ( "Test 1: Player has available cards in deck.\n" );
    cardEffect ( village, -1, -1, -1, &postG, 0, NULL );
    asserttrue("Player hand count unchanged",
		    postG.handCount[PLAYER_1] == preG.handCount[PLAYER_1]);
    asserttrue("Player hand contians treasure card",
		    postG.hand[PLAYER_1][postG.handCount[PLAYER_1]-1] == copper);
    asserttrue("Player actions incremented by two",
		    postG.numActions == preG.numActions + 2);
    asserttrue("Player discard count incremented by one",
		    postG.discardCount[PLAYER_1] == preG.discardCount[PLAYER_1] + 1);
    asserttrue("Player discard pile contains village card",
		    postG.discard[PLAYER_1][postG.discardCount[PLAYER_1]-1] == 
	            village);

    /*
     * Test 2: Player has no available cards in deck
     */
    memset ( &preG, 0, sizeof ( struct gameState ) );
    preG.numPlayers = NUM_PLAYERS;
    memset ( &preG.supplyCount, 25,
             ( ( treasure_map + 1 ) * sizeof ( preG.supplyCount[0] ) ) );
    memset ( &preG.embargoTokens, 0,
             ( ( treasure_map + 1 ) * sizeof ( preG.embargoTokens[0] ) ) );
    preG.whoseTurn = PLAYER_1;
    preG.hand[PLAYER_1][0] = village;
    preG.handCount[PLAYER_1] = 1;
    memcpy ( &postG, &preG, sizeof ( struct gameState ) );
    printf ( "Test 2: Player has no available cards in deck.\n" );
    cardEffect ( village, -1, -1, -1, &postG, 0, NULL );
    asserttrue("Player hand count decremented by one",
		    postG.handCount[PLAYER_1] == preG.handCount[PLAYER_1] - 1);
    asserttrue("Player actions incremented by two",
		    postG.numActions == preG.numActions + 2);
    asserttrue("Player discard count incremented by one",
		    postG.discardCount[PLAYER_1] == preG.discardCount[PLAYER_1] + 1);
    asserttrue("Player discard pile contains village card",
		    postG.discard[PLAYER_1][postG.discardCount[PLAYER_1]-1] == 
	            village);

    printf ( "--------------------\n" );
    printf ( "END VILLAGE TEST\n" );
    printf ( "--------------------\n" );


}