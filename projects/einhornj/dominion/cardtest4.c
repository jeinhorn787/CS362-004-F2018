#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>

void testCouncilRoom()
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

    int correctNumBuys = g->numBuys + 1;

    if (g == NULL)
    {
        printf("Critical failure, gameState struct is empty!  Exiting before we destroy something\n");
        exit(0);
    }

    printf("Number of cards in player 1 hand before Council Room: %d, expected: 5", numHandCards(g));

    if (numHandCards(g) == 5)
        printf(" - PASS\n");
    else
        printf(" - FAIL\n");

    choice1 = 1;
    cardEffect(council_room, choice1, choice2, choice3, g, handPos, &bonus);

    printf("Number of cards in player 1 hand after Council Room: %d, expected: 8", numHandCards(g));

    if (numHandCards(g) == 8)
        printf(" - PASS\n");
    else
        printf(" - FAIL\n");

    printf("Number of buys afer council room play: %d, expected %d", g->numBuys, correctNumBuys);

    if (g->numBuys == correctNumBuys)
        printf(" - PASS\n");
    else
        printf(" - FAIL\n");
    
    endTurn(g);

    printf("Number of cards in player 2 hand: %d, expected: 6", numHandCards(g));

    if (numHandCards(g) == 6)
        printf(" - PASS\n");
    else
        printf(" - FAIL\n");
}

int main()
{
    testCouncilRoom();
    return 0;
}