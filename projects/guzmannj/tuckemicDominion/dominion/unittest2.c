/*
   Name:Jorge Guzman Nader
   Date: 4/29/18
   CS 362 
 
   This test validates  the function whoseTurn.
 */

#include "test_utils.h"
#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define PLAYER_1 0
#define PLAYER_2 1

int main()
{
    int testVal;
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
    preG.whoseTurn = PLAYER_1;
    preG.numActions = 1;
    preG.numBuys = 1;

    printf ( "--------------------\n" );
    printf ( "Start whoseTurn() Test\n" );
    printf ( "--------------------\n" );

    /*
     * Test 1: Test game state is unchanged.
     */
    printf ( "Test 1: Game state unchanged.\n" );
    memcpy ( &postG, &preG, sizeof ( struct gameState ) );
    whoseTurn ( &postG );
    asserttrue ("Game state unchanged", memcmp ( &preG, &postG, sizeof ( struct gameState ) ) == 0 );

    /*
     * Test 2: Test correct turn for player one (value zero).
     */
    printf ( "Test 2: Correct return value for player one.\n" );
    testVal = whoseTurn ( &preG );
    printf ( "Expected result: %d; Actual result: %d\n", PLAYER_1, testVal );
    asserttrue ("", testVal == PLAYER_1 );

    /*
     * Test 3: Test correct return for player two (non-zero).
     */
    preG.whoseTurn = PLAYER_2;
    printf ( "Test 3: Correct return value for player two.\n" );
    testVal = whoseTurn ( &preG );
    printf ( "Expected result: %d; Actual result: %d\n", PLAYER_2, testVal );
    asserttrue ("", testVal == PLAYER_2 );


    printf ( "--------------------\n" );
    printf ( "ALL TESTS HAVE SUCCEED\n" );
    printf ( "--------------------\n" );

    return 0;
}