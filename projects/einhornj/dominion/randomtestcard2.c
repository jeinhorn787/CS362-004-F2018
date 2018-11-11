#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cardExists(int card, int k[], int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        if (k[i] == card)
            return 1;
    }

    return 0;
}

void randomTestSmithy()
{
    int iterations = 1;

    while (iterations <= 50)
    {
        printf("iteration #%d\n", iterations);
        
        int choice1 = 0;
        int choice2 = 0;
        int choice3 = 0;
        int k[10];
        int bonus = 0;
        struct gameState *g;
        int i, j, size = 0;
        int victoryCountBefore, kingdomCountBefore, victoryCountAfter, kingdomCountAfter;

        g = newGame();

        int numPlayers = (rand() % 3) + 2;

        k[0] = smithy;
        size++;

        for (i = 1; i < 10; i++)
        {
            int card;

            do
            {
                card = rand() % (treasure_map + 1);
            } while (cardExists(card, k, size));

            k[i] = card;
            size++;
        }

        initializeGame(numPlayers, k, 10, g);

        victoryCountBefore = supplyCount(estate, g) + supplyCount(duchy, g) + supplyCount(province, g);
        kingdomCountBefore = supplyCount(adventurer, g) + supplyCount(council_room, g) + supplyCount(feast, g) + supplyCount(gardens, g) + supplyCount(mine, g) + supplyCount(remodel, g) + supplyCount(smithy, g) + supplyCount(village, g);


        for (i = 0; i < numPlayers; i++)
        {
            for (j = 0; j < 10; j++)
            {
                g->deck[i][j] = k[rand() % 10];
                g->deckCount[i]++;
                g->discard[i][j] = k[rand() % 10];
                g->discardCount[i]++;
                g->hand[i][j] = k[rand() % 10];
                g->handCount[i]++;
            }
        }

        g->outpostPlayed = 0;
        g->phase = 0;
        g->numActions = 1;
        g->numBuys = 1;
        g->playedCardCount = 0;
        g->whoseTurn = 0;
        g->handCount[g->whoseTurn] = 0;

        for (i = 0; i < 5; i++)
            drawCard(g->whoseTurn, g);

        int handPos = rand() % (g->handCount[g->whoseTurn] + 1);

        printf("Number of cards in player 1 hand before Smithy: %d, expected: 5", numHandCards(g));

        if (numHandCards(g) == 5)
            printf(" - PASS\n");
        else
            printf(" - FAIL\n");

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

        printf("\n");

        iterations++;
    }
}

int main()
{
    srand(time(NULL));
    randomTestSmithy();
    return 0;
}