#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>

void testWhoseTurn()
{
    printf("Testing whoseTurn():\n");

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
    struct gameState *g;
    int player;

    g = newGame();

    initializeGame(2, k, 10, g);

    if (g == NULL)
    {
        printf("Critical failure, gameState struct was empty! Exiting test so we don't blow up the computer\n");
        exit(0);
    }

    g->whoseTurn = 1;

    player = whoseTurn(g);

    if (player == 1)
        printf("whoseTurn() while player 1 is up: PASS Player 1 is the player who is currently up\n");
    else
        printf("whoseTurn() while player 1 is up: FAIL Player 1 should be up but instead player %d is up\n", player);

    g->whoseTurn = 2;

    player = whoseTurn(g);

    if (player == 2)
        printf("whoseTurn() while player 2 is up: PASS Player 2 is the player who is currently up\n");
    else
        printf("whoseTurn() while player 2 is up: FAIL Player 2 should be up but instead player %d is up\n", player);
}

int main()
{
    testWhoseTurn();
    return 0;
}