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

void randomTestEmbargo()
{
    int iterations = 1;

    while (iterations <= 50)
    {
        printf("iteration #%d\n", iterations);
        
        int choice1 = rand() % (treasure_map + 1);
        int choice2 = 0;
        int choice3 = 0;
        int handPos = 0;
        int k[10];
        int bonus = 0;
        struct gameState *g;
        int i, j, size = 0;

        g = newGame();

        int numPlayers = (rand() % 3) + 2;

        k[0] = embargo;
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

        int correctCoins = g->coins + 2;
        int tokenCount = g->embargoTokens[choice1] + 1;

        printf("Number of cards in player 1 hand before Embargo: %d, expected: 5", numHandCards(g));

        if (numHandCards(g) == 5)
            printf(" - PASS\n");
        else
            printf(" - FAIL\n");

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

        printf("\n");

        iterations++;
    }
}

int main()
{
    srand(time(NULL));
    randomTestEmbargo();
    return 0;
}