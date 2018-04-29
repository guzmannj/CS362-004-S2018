/*
    Name: Jorge Guzman Nader
    Date: 4/29/18
    CS 362 
    Assignment 3
  
    This test evaluates the buyCard function   
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
#define CARD_TO_BUY estate
#define CARD_COST 2

int main()
{
    int i, j, testVal;
    struct gameState preG = {0};
    struct gameState postG = {0};

    printf ( "--------------------\n" );
    printf ( "Start buyCard() Test\n" );
    printf ( "--------------------\n" );

    /*
     * Place game in sane state.
     */
    preG.numPlayers = NUM_PLAYERS;
    memset ( &preG.supplyCount, 25,
             ( ( treasure_map + 1 ) * sizeof ( preG.supplyCount[0] ) ) );
    memset ( &preG.embargoTokens, 0,
             ( ( treasure_map + 1 ) * sizeof ( preG.embargoTokens[0] ) ) );
    preG.whoseTurn = PLAYER_1;


    /*
     * Test 1: Test player cannot buy due to lack of buys.
     * Return value should be -1 and game state should be unchanged.
     */
    printf ( "Test 1: Player has no buys left.\n" );
    preG.numBuys = 0;
    memcpy ( &postG, &preG, sizeof ( struct gameState ) );
    testVal = buyCard ( CARD_TO_BUY, &postG );
    printf ( "Expected return value: %d; Actual return value: %d\n",
             -1, testVal );
    asserttrue ( "Player has no buys, thus cannot buy card", testVal == -1 );
    asserttrue ( "Game state unchanged", memcmp ( &postG, &preG, sizeof ( struct gameState ) ) == 0 );

    /*
     * Test 2: Test player cannot buy due to lack of coins.
     * Return value should be -1 and game state should be unchanged.
     */
    printf ( "Test 2: Player does not have enough coins.\n" );
    preG.numBuys = 1;
    preG.coins = CARD_COST - 1;
    memcpy ( &postG, &preG, sizeof ( struct gameState ) );
    testVal = buyCard ( CARD_TO_BUY, &postG );
    printf ( "Expected return value: %d; Actual return value: %d\n",
             -1, testVal );
    asserttrue ( "Player does not have enough coins, cannot buy card", testVal == -1 );
    asserttrue ( "Game state unchanged", memcmp ( &postG, &preG, sizeof ( struct gameState ) ) == 0 );

    /*
     * Test 3: Test player cannot buy due to lack of supply.
     * Return value should be -1 and game state should be unchanged.
     */
    printf ( "Test 3: Player does not have enough coins.\n" );
    preG.numBuys = 1;
    preG.coins = CARD_COST;
    preG.supplyCount[CARD_TO_BUY] = 0;
    memcpy ( &postG, &preG, sizeof ( struct gameState ) );
    testVal = buyCard ( CARD_TO_BUY, &postG );
    printf ( "Expected return value: %d; Actual return value: %d\n",
             -1, testVal );
    asserttrue ( "No supply of card, player cannot buy card", testVal == -1 );
    asserttrue ( "Game state unchanged", memcmp ( &postG, &preG, sizeof ( struct gameState ) ) == 0 );

    /*
     * Test 4: Player can buy card.  Test that card is in discard, coins is
     * reduced by cost of card, supply of card is reduced by one, and state
     * of game unchanged otherwise.
     */
    printf ( "Test 4: Player purchases card.\n" );
    preG.numBuys = 1;
    preG.coins = CARD_COST;
    preG.supplyCount[CARD_TO_BUY] = 1;
    memcpy ( &postG, &preG, sizeof ( struct gameState ) );
    buyCard ( CARD_TO_BUY, &postG );

    asserttrue(
		    "Discard count incremented by one",
	    postG.discardCount[preG.whoseTurn] 
	    == 
	    preG.discardCount[preG.whoseTurn] + 1);
    
    asserttrue ( 
		    "Card purchased in discard pile",
	    postG.discard[preG.whoseTurn][preG.discardCount[preG.whoseTurn]]
             == 
             CARD_TO_BUY );

    asserttrue ( "Coins reduced by cost of card",
		    postG.coins == ( preG.coins - CARD_COST ) );

    asserttrue ( "Supply of card reduced by one", 
		    postG.supplyCount[CARD_TO_BUY] ==
             ( preG.supplyCount[CARD_TO_BUY] - 1 ) );

    asserttrue ( "Phase is now one", postG.phase == 1 );

    asserttrue ( "Num players unchanged",
		    postG.numPlayers == preG.numPlayers );
    asserttrue ( "Embargo tokens unchanged",
		    memcmp ( postG.embargoTokens, preG.embargoTokens,
                      ( ( treasure_map + 1 ) * sizeof ( int ) ) ) 
	   == 0);
    asserttrue ( "Outpost played unchanged",
		    postG.outpostPlayed == preG.outpostPlayed );
    asserttrue ( "Whose turn unchanged",
		    postG.whoseTurn == preG.whoseTurn );
    asserttrue ( "Num actions unchagned",
		    postG.numActions == preG.numActions );
    for ( i = 0; i < NUM_PLAYERS; ++i )
    {
        asserttrue ( "Hand count unchanged",
			postG.handCount[i] == preG.handCount[i] );
        for ( j = 0; j < preG.handCount[i]; ++j )
        {
            asserttrue ( "Player hand unchanged", postG.hand[i][j] == preG.hand[i][j] );
        }

        asserttrue ( "Player deck count unchanged", 
			postG.deckCount[i] == preG.deckCount[i] );
        for ( j = 0; j < preG.deckCount[i]; ++j )
        {
            asserttrue ( "Player deck unchanged", postG.deck[i][j] == preG.deck[i][j] );
        }
    }
    asserttrue ( "Played card count unchanged", postG.playedCardCount == preG.playedCardCount );
    for ( i = 0; i < preG.playedCardCount; ++i )
    {
        asserttrue ( "Player played cards unchanged",
			postG.playedCards[i] == preG.playedCards[i] );
    }

    printf ( "--------------------\n" );
    printf ( "End buyCard() Test\n" );
    printf ( "--------------------\n" );

}