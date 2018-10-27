#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>

void testSmithyCard()
{
    int choice1 = 0;
    int choice2 = 0;
    int choice3 = 0;
    int handPos = 0;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
    int bonus = 0;
    struct gameState *g;
    int victoryCountBefore, kingdomCountBefore, victoryCountAfter, kingdomCountAfter;
    
    g = newGame();

    initializeGame(2, k, 10, g);

    victoryCountBefore = supplyCount(estate, g) + supplyCount(duchy, g) + supplyCount(province, g);
    kingdomCountBefore = supplyCount(adventurer, g) + supplyCount(council_room, g) + supplyCount(feast, g) + supplyCount(gardens, g) + supplyCount(mine, g) + supplyCount(remodel, g) + supplyCount(smithy, g) + supplyCount(village, g);


    if (g == NULL)
    {
        printf("Critical failure, gameState struct is empty!  Exiting before we destroy something\n");
        exit(0);
    }

    printf("Number of cards in player 1 hand before Smithy: %d, expected: 5", numHandCards(g));

    if (numHandCards(g) == 5)
        printf(" - PASS\n");
    else
        printf(" - FAIL\n");

    printf("Testing g->deckCount[0]: %d\n", g->deckCount[0]);

    choice1 = 1;
    cardEffect(smithy, choice1, choice2, choice3, g, handPos, &bonus);

    printf("Number of cards in player 1 hand after Smithy: %d, expected: 7", numHandCards(g));

    if (numHandCards(g) == 7)
        printf(" - PASS\n");
    else
        printf(" - FAIL\n");

    printf("Number of smithy cards after play: %d, expected 9", supplyCount(smithy, g));

    if (supplyCount(smithy, g) == 9)
        printf(" - PASS\n");
    else
        printf(" - FAIL\n");

    printf("Number of cards in player 1 pile: %d, expected 2", g->deckCount[0]);

    if (g->deckCount[0] == 2)
        printf(" - PASS\n");
    else
        printf(" - FAIL\n");

    victoryCountAfter = supplyCount(estate, g) + supplyCount(duchy, g) + supplyCount(province, g);

    printf("Number of Victory cards left: %d, expected %d", victoryCountAfter, victoryCountBefore);

    if (victoryCountAfter == victoryCountBefore)
        printf(" - PASS\n");
    else
        printf(" - FAIL\n");

    kingdomCountAfter = supplyCount(adventurer, g) + supplyCount(council_room, g) + supplyCount(feast, g) + supplyCount(gardens, g) + supplyCount(mine, g) + supplyCount(remodel, g) + supplyCount(smithy, g) + supplyCount(village, g);

    printf("Number of Kingdom cards left: %d, expected %d", kingdomCountAfter, kingdomCountBefore);

    if (kingdomCountBefore == kingdomCountAfter)
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
    testSmithyCard();
    return 0;
}