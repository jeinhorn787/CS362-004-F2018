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

void randomTestAdventurer()
{
    int iterations = 1;

    while (iterations <= 50)
    {
        printf("iteration #%d\n", iterations);
        
        int choice1 = 1;
        int choice2 = 0;
        int choice3 = 0;
        int handPos = 0;
        int k[10];
        int bonus = 0;
        struct gameState *g;
        int i, j, size = 0, victoryCountAfter, victoryCountBefore, kingdomCountAfter, kingdomCountBefore;

        g = newGame();

        int numPlayers = (rand() % 3) + 2;

        k[0] = adventurer;
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

        victoryCountBefore = supplyCount(estate, g) + supplyCount(duchy, g) + supplyCount(province, g);
        kingdomCountBefore = supplyCount(adventurer, g) + supplyCount(council_room, g) + supplyCount(feast, g) + supplyCount(gardens, g) + supplyCount(mine, g) + supplyCount(remodel, g) + supplyCount(smithy, g) + supplyCount(village, g);


        printf("Number of cards in hand before adventurer play: %d, expected 5", numHandCards(g));

        if (numHandCards(g) == 5)
            printf(" - PASS\n");
        else
            printf(" - FAIL\n");

        cardEffect(adventurer, choice1, choice2, choice3, g, handPos, &bonus);

        printf("Numder of cards in hand after adventurer play: %d, expected 6", numHandCards(g));

        if (numHandCards(g) == 6)
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

        printf("\n");

        iterations++;
    }
}

int main()
{
    srand(time(NULL));
    randomTestAdventurer();
    return 0;
}