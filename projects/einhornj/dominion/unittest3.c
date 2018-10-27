#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>

void testSupplyCount()
{
    int result;
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

    
    result = supplyCount(4, g);

    if (result == 46)
        printf("supplyCount(): PASS there are 46 copper cards left\n");
    else
        printf("supplyCost(): FAIL when there should be %d copper cards left\n", result);

    result = supplyCount(5, g);

    if (result == 46)
        printf("supplyCount(): PASS there are 40 silver cards left\n");
    else
        printf("supplyCost(): FAIL there should be %d silver cards\n", result);

    result = supplyCount(6, g);

    if (result == 46)
        printf("supplyCount(): PASS there are 30 gold cards left\n");
    else
        printf("supplyCost(): FAIL there should be %d gold cards left\n", result);
}

int main()
{
    testSupplyCount();
    return 0;
}