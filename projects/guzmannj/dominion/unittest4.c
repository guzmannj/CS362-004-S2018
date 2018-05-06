/*
   Name: Jorge Guzman Nader
   Date: 4/29/18
   CS 362 
 
   This test validates the isGameOver function
 */

#include "test_utils.h"
#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define TRUE 1
#define FALSE 0

int main()
{
    int i,j, testVal;
    struct gameState preG = {0};
    struct gameState postG = {0};

    /*
     * Place the game into a sane state where all supply piles are full.
     */
    preG.numPlayers = 2;
    memset ( preG.supplyCount, 25,
             ( ( treasure_map + 1 ) * sizeof ( int ) ) );
    preG.numActions = 1;
    preG.numBuys = 1;
    for ( i = 0; i < 2; i++ )
    {
        preG.deckCount[i] = 0;
        for ( j = 0; j < 3; j++ )
        {
            preG.deck[i][j] = estate;
            preG.deckCount[i]++;
        }
        for ( j = 3; j < 10; j++ )
        {
            preG.deck[i][j] = copper;
            preG.deckCount[i]++;
        }
    }

    /* Copy state of game into postG which will be handed off to function
     * under test.
     */
    memcpy ( &postG, &preG, sizeof ( struct gameState ) );

    printf ( "--------------------\n" );
    printf ( "Start isGameOver() Test\n" );
    printf ( "--------------------\n" );

    /*
     * Test game state unchanged
     */
    printf ( "Test 1: Ensure game state is not changed by function.\n" );
    isGameOver ( &preG );
    asserttrue ( "Game state unchanged",
		    memcmp ( &preG, &postG, sizeof ( struct gameState ) ) == 0 );

    /*
     * Test full supply pile.
     */
    printf ( "Test 2: All supply piles are full\n" );
    testVal = isGameOver ( &preG );
    printf ( "Expected output: %d; Actual output: %d\n", FALSE, testVal );
    asserttrue ( "Game is not over",
		    testVal == FALSE );

    /*
     * Test empty province piles.
     */
    preG.supplyCount[province] = 0;
    printf ( "Test 3: Province pile is empty.\n" );
    testVal = isGameOver ( &preG );
    printf ( "Expected output: %d; Actual output: %d\n", TRUE, testVal );
    asserttrue ( "Game is over",
		    testVal == TRUE );

    /*
     * Test full province pile and one empty supply pile.
     */
    preG.supplyCount[province] = 25;
    preG.supplyCount[council_room] = 0;
    printf ( "Test 4: Province pile full; one supply pile empty.\n" );
    testVal = isGameOver ( &preG );
    printf ( "Expected out: %d; Actual output: %d\n", FALSE, testVal );
    asserttrue ( "Game is not over",
		    testVal == FALSE );

    /*
     * Test full province pile and two empty supply piles.
     */
    preG.supplyCount[province] = 25;
    preG.supplyCount[council_room] = 0;
    preG.supplyCount[baron] = 0;
    printf ( "Test 4: Province pile full; two supply piles empty.\n" );
    testVal = isGameOver ( &preG );
    printf ( "Expected out: %d; Actual output: %d\n", FALSE, testVal );
    asserttrue ( "Game is not over",
		    testVal == FALSE );

    /*
     * Test full province pile and three empty supply piles.
     */
    preG.supplyCount[province] = 25;
    preG.supplyCount[council_room] = 0;
    preG.supplyCount[baron] = 0;
    preG.supplyCount[cutpurse] = 0;
    printf ( "Test 4: Province pile full; three supply piles empty.\n" );
    testVal = isGameOver ( &preG );
    printf ( "Expected out: %d; Actual output: %d\n", TRUE, testVal );
    asserttrue ( "Game is over",
		    testVal == TRUE );

    printf ( "--------------------\n" );
    printf ( "End isGameOver() Test\n" );
    printf ( "--------------------\n" );

    return 0;
}