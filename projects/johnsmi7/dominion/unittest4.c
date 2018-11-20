#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>

void testEndTurn()
{
    printf("Testing endTurn():\n");

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
    struct gameState *g;

    g = newGame();

    initializeGame(2, k, 10, g);

    if (g == NULL)
    {
        printf("Critical failure, gameState struct is empty! Exiting so we don't crash the computer\n");
        exit(0);
    }

    endTurn(g);

    printf("state->outpostPlayed value: %d, expected 0", g->outpostPlayed);

    if (g->outpostPlayed == 0)
        printf(" - PASS\n");
    else
        printf(" - FAIL\n");

    printf("state->phase value: %d, expected 0", g->phase);

    if (g->phase == 0)
        printf(" - PASS\n");
    else
        printf(" - FAIL\n");

    printf("state->numActions value: %d, expected 1", g->numActions);

    if (g->numActions == 1)
        printf(" - PASS\n");
    else
        printf(" - FAIL\n");

    printf("state->coins value: %d, expected 3", g->coins);

    if (g->coins == 3)
        printf(" - PASS\n");
    else
        printf(" - FAIL\n");

    printf("state->numBuys value: %d, expected 1", g->numBuys);

    if (g->numBuys == 1)
        printf(" - PASS\n");
    else
        printf(" - FAIL\n");


    printf("state->playedCardCount value: %d, expected 0", g->playedCardCount);

    if (g->playedCardCount == 0)
        printf(" - PASS\n");
    else
        printf(" - FAIL\n");

    printf("state->outpostPlayed value: %d, expected 0", g->outpostPlayed);

    if (g->outpostPlayed == 0)
        printf(" - PASS\n");
    else
        printf(" - FAIL\n");
}

int main()
{
    testEndTurn();
    return 0;
}