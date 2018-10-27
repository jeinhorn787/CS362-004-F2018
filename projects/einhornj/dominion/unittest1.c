#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>

void testKingdomCards()
{
    int a = 1;
    int b = 4;
    int c = 3;
    int d = 10;
    int e = 8;
    int f = 17;
    int g = 6;
    int h = 7;
    int i = 11;
    int j = 3;

    int *testResult;

    testResult = kingdomCards(a, b, c, d, e, f, g, h, i, j);

    if (testResult[0] == 1 )
        printf("kingdomCards(): PASS card 1 is 1\n");
    else
        printf("kingdomCards(): FAIL card 1 should have been 1 but got %d instead\n", testResult[0]);

    if (testResult[1] == 4 )
        printf("kingdomCards(): PASS card 2 is 4\n");
    else
        printf("kingdomCards(): FAIL card 2 should have been 4 but got %d instead\n", testResult[1]);

    if (testResult[2] == 3 )
        printf("kingdomCards(): PASS card 3 is 3\n");
    else
        printf("kingdomCards(): FAIL card 3 should have been 3 but got %d instead\n", testResult[2]);

    if (testResult[3] == 10 )
        printf("kingdomCards(): PASS card 4 is 10\n");
    else
        printf("kingdomCards(): FAIL card 4 should have been 10 but got %d instead\n", testResult[3]);

    if (testResult[4] == 8 )
        printf("kingdomCards(): PASS card 5 is 8\n");
    else
        printf("kingdomCards(): FAIL card 5 should have been 8 but got %d instead\n", testResult[4]);

    if (testResult[5] == 17 )
        printf("kingdomCards(): PASS card 6 is 17\n");
    else
        printf("kingdomCards(): FAIL card 6 should have been 17 but got %d instead\n", testResult[5]);

    if (testResult[6] == 6 )
        printf("kingdomCards(): PASS card 7 is 6\n");
    else
        printf("kingdomCards(): FAIL card 7 should have been 6 but got %d instead\n", testResult[6]);

    if (testResult[7] == 7 )
        printf("kingdomCards(): PASS card 8 is 7\n");
    else
        printf("kingdomCards(): FAIL card 8 should have been 7 but got %d instead\n", testResult[7]);

    if (testResult[8] == 11 )
        printf("kingdomCards(): PASS card 9 is 11\n");
    else
        printf("kingdomCards(): FAIL card 9 should have been 11 but got %d instead\n", testResult[8]);

    if (testResult[9] == 3 )
        printf("kingdomCards(): PASS card 10 is 3\n");
    else
        printf("kingdomCards(): FAIL card 10 should have been 3 but got %d instead\n", testResult[9]);
}

int main()
{
    testKingdomCards();
    return 0;
}