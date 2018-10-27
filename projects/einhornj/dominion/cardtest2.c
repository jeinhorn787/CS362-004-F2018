#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>

void testAdventurerCard()
{
    int choice1 = 0;
    int choice2 = 0;
    int choice3 = 0;
    int handPos = 0;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
    int bonus = 0;
    struct gameState *g;
    int victoryCountBefore, kingdomCountBefore, kingdomCountAfter, victoryCountAfter;

    g = newGame();

    initializeGame(2, k, 10, g);

    victoryCountBefore = supplyCount(estate, g) + supplyCount(duchy, g) + supplyCount(province, g);
    kingdomCountBefore = supplyCount(adventurer, g) + supplyCount(council_room, g) + supplyCount(feast, g) + supplyCount(gardens, g) + supplyCount(mine, g) + supplyCount(remodel, g) + supplyCount(smithy, g) + supplyCount(village, g);


    if (g == NULL)
    {
        printf("Critical failure, gameState struct is empty!  Exiting before we destroy something\n");
        exit(0);
    }

    printf("Number of cards in player 1 hand before Adventurer: %d, expected: 5", numHandCards(g));

    if (numHandCards(g) == 5)
        printf(" - PASS\n");
    else
        printf(" - FAIL\n");

    choice1 = 1;
    cardEffect(adventurer, choice1, choice2, choice3, g, handPos, &bonus);

    printf("Number of cards in player 1 hand after Adventurer: %d, expected: 6", numHandCards(g));

    if (numHandCards(g) == 6)
        printf(" - PASS\n");
    else
        printf(" - FAIL\n");

    printf("Number of adventurer cards after play: %d, expected 9", supplyCount(adventurer, g));

    if (supplyCount(adventurer, g) == 9)
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

    if (kingdomCountAfter == kingdomCountBefore)
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
    testAdventurerCard();
    return 0;
}