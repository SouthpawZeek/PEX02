/** pex02funcs.c
 * ===========================================================
 * Name: Isaac Abramovitz
 * Section: M3/4
 * Project: PEX02
 * Purpose:  This program lets the user play the dice game Pig!
 * By calling specific functions to run the game.
 * =========================================================== */

#include "pex02funcs.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int player1Score;
int player2Score;

char getCharSafe() {
    char charValue;
    char scanfReturn4 = 0;

    // attempt to read an integer value
    scanfReturn4 = scanf(" %c", &charValue);
    // eliminate any excess input
    fflush(stdin);
    // quit if unsuccessful

    if (scanfReturn4 != 1) {
        fprintf(stderr, "%c is a bad char input - terminating\n", charValue);
        exit(1);
    }
    return charValue;
}

int rollDie() {
    int dieRoll;
    // Get value from dieRoll
    dieRoll = rand() % 6 + 1;
    return dieRoll;
}

int takeTurn(char* playerName, int playerScore) {
    printf("it's your turn, %s\n", playerName);
    char yesOrNo;
    int turnRoll;
    int scoreTurn = 0;

    do {
        turnRoll = rollDie();

        // If they roll a 1 do this. If not go to else statement.
        if (turnRoll == 1 && playerScore == 0) {
            scoreTurn = 0;
            printf("You pigged out! Turn Over.\n");
            return playerScore;
        }

        if (turnRoll == 1 && playerScore > 0) {
            int oldScore = playerScore - scoreTurn;
            scoreTurn = 0;
            printf("You pigged out! Turn Over.\n");
            return oldScore;
        }

        else {
            scoreTurn += turnRoll;
            playerScore += turnRoll;
            printf("You rolled a %i and have a turn score of %i, bringing your total to %i.\n",
                   turnRoll, scoreTurn, playerScore);
            printf("Roll again? ");
            yesOrNo = getCharSafe();
        }

        // Keep doing this until the user types 'n'.
    } while (yesOrNo == 'y' || yesOrNo == 'Y');

    return playerScore;
}

void displayGameState(char* player1Name, int player1Score, char* player2Name, int player2Score) {
    printf("\t Score Players\n");
    printf("\t    %i %s\n", player1Score, player1Name);
    printf("\t    %i %s\n\n", player2Score, player2Name);
}

int winningPlayer(int player1Score, int player2Score) {
    // First two if statemetnts check to see if either player has won yet.
    if (player1Score >= 100) {
        return 1;
    }

    if (player2Score >= 100) {
        return 2;
    }

    // Check for a winning tie.
    if (player1Score == player2Score && player1Score >= 100 && player2Score >= 100) {
        return 3;
    }

    else {
        return 0;
    }
}

void displayWinner(char* player1Name, int player1Score, char* player2Name, int player2Score) {
    if (winningPlayer(player1Score, player2Score) == 1) {
        printf("You won, %s\n", player1Name);
    }

    if (winningPlayer(player1Score, player2Score) == 2) {
        printf("You won, %s\n", player2Name);
    }

    if (winningPlayer(player1Score, player2Score) == 3) {
        printf("You both tied\n");
    }
}
