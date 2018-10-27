#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>

void testEmbargoCard()
{
    int choice1 = 0;
    int choice2 = 0;
    int choice3 = 0;
    int handPos = 0;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
    int bonus = 0;
    struct gameState *g;

    g = newGame();

    initializeGame(2, k, 10, g);

    int correctCoins = g->coins + 2;
    int tokenCount = g->embargoTokens[choice1] + 1;

    if (g == NULL)
    {
        printf("Critical failure, gameState struct is empty!  Exiting before we destroy something\n");
        exit(0);
    }

    printf("Number of cards in player 1 hand before Embargo: %d, expected: 5", numHandCards(g));

    if (numHandCards(g) == 5)
        printf(" - PASS\n");
    else
        printf(" - FAIL\n");

    choice1 = 1;
    cardEffect(embargo, choice1, choice2, choice3, g, handPos, &bonus);

    printf("Number of cards in player 1 hand after Embargo: %d, expected: 4", numHandCards(g));

    if (numHandCards(g) == 4)
        printf(" - PASS\n");
    else
        printf(" - FAIL\n");

    printf("Number of coins after embargo play: %d, expected %d", g->coins, correctCoins);

    if (g->coins == correctCoins)
        printf(" - PASS\n");
    else
        printf(" - FAIL\n");

    printf("Number of embargo tokens after play: %d, expected %d", g->embargoTokens[choice1], tokenCount);

    if (g->embargoTokens[choice1] == tokenCount)
        printf(" - PASS\n");
    else
        printf(" - FAIL\n");

    endTurn(g);

    printf("Number of cards in player 2 hand: %d, expected: 5", numHandCards(g));

    if (numHandCards(g) == 5)
        printf(" - PASS\n");
    else
        printf(" - FAIL\n");
}

int main()
{
    testEmbargoCard();
    return 0;
}