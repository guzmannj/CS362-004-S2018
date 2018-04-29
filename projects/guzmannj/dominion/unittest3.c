/*
   Name: Jorge Guzman Nader
   Date: 4/29/18
   CS 362 
 
   This test validates the fullDeckCount function.
 */

#include "test_utils.h"
#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define CARD_1 ambassador
#define CARD_2 adventurer
#define CARD_3 smithy
#define NUM_CARD_1 3
#define NUM_CARD_2 3
#define NUM_CARD_3 0
#define PLAYER 0

int main()
{
    int i,j, testVal;
    struct gameState preG = {0};
    struct gameState postG = {0};
    
    /*
     * Place game in sane state.
     */
    preG.numPlayers = 2;
    memset ( &preG.supplyCount, 25,
             ( ( treasure_map + 1 ) * sizeof ( preG.supplyCount[0] ) ) );
    memset ( &preG.embargoTokens, 0,
             ( ( treasure_map + 1 ) * sizeof ( preG.embargoTokens[0] ) ) );
    preG.whoseTurn = PLAYER;
    preG.numActions = 1;
    preG.numBuys = 1;

    printf ( "--------------------\n" );
    printf ( "Start fullDeckCount() Test\n" );
    printf ( "--------------------\n" );

    /*
     * Test 1: Test game state is unchanged.
     */
    memcpy ( &postG, &preG, sizeof ( struct gameState ) );
    fullDeckCount(PLAYER, CARD_1, &postG);
    asserttrue("Game state unchanged",
		    memcmp(&preG, &postG, sizeof(struct gameState)) == 0);
    
    /*
     * Test 2: CARD_1 in deck only.
     */
    printf("Test 2: Card in deck only.\n");
    for ( i = 0; i < preG.numPlayers; ++i )
    {
        for ( j = 0; j < ( NUM_CARD_1 + NUM_CARD_2 ); ++j )
        {
		if (j % 2 == 0)
		{
			preG.deck[i][j] = CARD_1;
		}
		else
		{
			preG.deck[i][j] = CARD_2;
		}
		preG.deckCount[i]++;
        }
    }
    testVal = fullDeckCount(PLAYER, CARD_1, &preG);
    printf("Expected result: %d; Actual result: %d\n", NUM_CARD_1, testVal);
    asserttrue("",
		    testVal == NUM_CARD_1);
    
    /*
     * Test 3: CARD_1 in hand only.
     */
    printf("Test 3: Card in hand only.\n");
    memset(&preG, 0, sizeof(struct gameState));
    preG.numPlayers = 2;
    memset ( &preG.supplyCount, 25,
             ( ( treasure_map + 1 ) * sizeof ( preG.supplyCount[0] ) ) );
    memset ( &preG.embargoTokens, 0,
             ( ( treasure_map + 1 ) * sizeof ( preG.embargoTokens[0] ) ) );
    preG.whoseTurn = PLAYER;
    preG.numActions = 1;
    preG.numBuys = 1;
    for ( i = 0; i < preG.numPlayers; ++i )
    {
        for ( j = 0; j < ( NUM_CARD_1 + NUM_CARD_2 ); ++j )
        {
		if (j % 2 == 0)
		{
			preG.hand[i][j] = CARD_1;
		}
		else
		{
			preG.hand[i][j] = CARD_2;
		}
		preG.handCount[i]++;
        }
    }
    testVal = fullDeckCount(PLAYER, CARD_1, &preG);
    printf("Expected result: %d; Actual result: %d\n", NUM_CARD_1, testVal);
    asserttrue("", testVal == NUM_CARD_1);
    
    /*
     * Test 4: CARD_1 in discard only.
     */
    printf("Test 4: Card in discard only.\n");
    memset(&preG, 0, sizeof(struct gameState));
    preG.numPlayers = 2;
    memset ( &preG.supplyCount, 25,
             ( ( treasure_map + 1 ) * sizeof ( preG.supplyCount[0] ) ) );
    memset ( &preG.embargoTokens, 0,
             ( ( treasure_map + 1 ) * sizeof ( preG.embargoTokens[0] ) ) );
    preG.whoseTurn = PLAYER;
    preG.numActions = 1;
    preG.numBuys = 1;
    for ( i = 0; i < preG.numPlayers; ++i )
    {
        for ( j = 0; j < ( NUM_CARD_1 + NUM_CARD_2 ); ++j )
        {
		if (j % 2 == 0)
		{
			preG.discard[i][j] = CARD_1;
		}
		else
		{
			preG.discard[i][j] = CARD_2;
		}
		preG.discardCount[i]++;
        }
    }
    testVal = fullDeckCount(PLAYER, CARD_1, &preG);
    printf("Expected result: %d; Actual result: %d\n", NUM_CARD_1, testVal);
    asserttrue("", testVal == NUM_CARD_1);
    
    /*
     * Test 5: CARD_1 in hand, deck, and discard.
     */
    printf("Test 5: Card in hand, deck, and discard.\n");
    memset(&preG, 0, sizeof(struct gameState));
    preG.numPlayers = 2;
    memset ( &preG.supplyCount, 25,
             ( ( treasure_map + 1 ) * sizeof ( preG.supplyCount[0] ) ) );
    memset ( &preG.embargoTokens, 0,
             ( ( treasure_map + 1 ) * sizeof ( preG.embargoTokens[0] ) ) );
    preG.whoseTurn = PLAYER;
    preG.numActions = 1;
    preG.numBuys = 1;
    for ( i = 0; i < preG.numPlayers; ++i )
    {
        for ( j = 0; j < ( NUM_CARD_1 + NUM_CARD_2 ); ++j )
        {
		if (j % 2 == 0)
		{
			preG.hand[i][j] = CARD_1;
			preG.deck[i][j] = CARD_1;
			preG.discard[i][j] = CARD_1;
		}
		else
		{
			preG.hand[i][j] = CARD_2;
			preG.deck[i][j] = CARD_2;
			preG.discard[i][j] = CARD_2;
		}
		preG.handCount[i]++;
		preG.deckCount[i]++;
		preG.discardCount[i]++;
        }
    }
    testVal = fullDeckCount(PLAYER, CARD_1, &preG);
    printf("Expected result: %d; Actual result: %d\n", 
	   (NUM_CARD_1 * 3), testVal);
    asserttrue("",testVal == (NUM_CARD_1 * 3));
    
    /*
     * Test 6: CARD_3 does not exist in hand, deck, or discard.
     */
    printf("Test 6: Test non-existant card.\n");
    testVal = fullDeckCount(PLAYER, CARD_3, &preG);
    printf("Expected result: %d; Actual result: %d\n", 0, testVal);
    asserttrue("",testVal == 0);
    
    
    printf ( "--------------------\n" );
    printf ( "End fullDeckCount() Test\n" );
    printf ( "--------------------\n" );

    return 0;
}