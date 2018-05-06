/*
   Name: Jorge Guzman Nader
   Date: 4/29/18
   CS 362
 
   This test the adventurer card. The adventurer card effect is to reveal cards from your deck until 2 treasure
   cards are appear, the it adds this 2 tresures to the players hand  and dischard the other cards that were revealed.

    
   This is a card test that checks the effect of the mine card. The mine card
   effect is to trash a treasure card from your hand and add a treasure card
   costing up to 3 more to your hand.
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
    printf ( "START ADVENTURER TEST\n" );
    printf ( "--------------------\n" );

    /*
     * Test 1: Player has treasure cards in deck.
     */
    memset ( &preG, 0, sizeof ( struct gameState ) );
    preG.numPlayers = NUM_PLAYERS;
    memset ( &preG.supplyCount, 25,
             ( ( treasure_map + 1 ) * sizeof ( preG.supplyCount[0] ) ) );
    memset ( &preG.embargoTokens, 0,
             ( ( treasure_map + 1 ) * sizeof ( preG.embargoTokens[0] ) ) );
    preG.whoseTurn = PLAYER_1;
    preG.hand[PLAYER_1][0] = adventurer;
    preG.handCount[PLAYER_1] = 1;
    preG.deck[PLAYER_1][0] = copper;
    preG.deck[PLAYER_1][1] = duchy;
    preG.deck[PLAYER_1][2] = copper;
    preG.deck[PLAYER_1][3] = duchy;
    preG.deck[PLAYER_1][4] = copper;
    preG.deck[PLAYER_1][5] = duchy;
    preG.deck[PLAYER_1][6] = copper;
    preG.deckCount[PLAYER_1] = 7;
    memcpy ( &postG, &preG, sizeof ( struct gameState ) );
    printf ( "Test 1: Player available treasure cards.\n" );
    cardEffect ( adventurer, -1, -1, -1, &postG, 0, NULL );
    asserttrue ("Player hand count increased by two",
		    postG.handCount[PLAYER_1] == preG.handCount[PLAYER_1] + 2 );
    asserttrue ("Player hand containis first treasure card",
		    postG.hand[PLAYER_1][postG.handCount[PLAYER_1] - 1] == copper );
    asserttrue ("Player hand contains second treasure card",
		    postG.hand[PLAYER_1][postG.handCount[PLAYER_1] - 2] == copper );
    asserttrue ("Player discard pile incremented by one card",
	    postG.discardCount[PLAYER_1] == preG.discardCount[PLAYER_1] + 1 );
    asserttrue("Player discard pile contains duchy",
		    postG.discard[PLAYER_1][preG.discardCount[PLAYER_1]] == duchy );

    printf ( "--------------------\n" );
    printf ( "END ADVENTURER TEST\n" );
    printf ( "--------------------\n" );


}