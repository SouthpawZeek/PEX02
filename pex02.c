/** pex02.c
 * ===========================================================
 * Name: Isaac Abramovitz
 * Section: M3/4
 * Project: PEX02
 * Purpose: This program lets the user play the dice game Pig!
 * By calling specific functions to run the game.
 * Documentation: On 12-Sep-21 I asked C3C Nathan Starkey about how I should assign my scores to
 * each player as they go along playing. He recommended that I assign my variable in main to my
 * takeTurn function. I implemented this in lines 40 and 45 to successfully get past this roadblock.
 * =========================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "pex02funcs.h"
#define MAX_NAME 100

int player1Score = 0;
int player2Score = 0;
int flag = 4;

int main() {
    srand(time(0));
    char player1Name[MAX_NAME];
    char player2Name[MAX_NAME];

    // Get first players name
    printf("Player one, what is your name: ");
    scanf("%s", player1Name);

    // Get second players name
    printf("Player two, what is your name: ");
    scanf("%s", player2Name);

    // Call score
    displayGameState(player1Name, player1Score, player2Name, player2Score);

    do {
        // Player 1 turn
        player1Score = takeTurn(player1Name, player1Score);

        displayGameState(player1Name, player1Score, player2Name, player2Score);

        // Check if they've won, or tied.
        flag = winningPlayer(player1Score, player2Score);
        if (flag == 1 || flag == 2 || flag == 3) {
            break;
        }

        // Player 2 turn.
        player2Score = takeTurn(player2Name, player2Score);

        displayGameState(player1Name, player1Score, player2Name, player2Score);

        flag = winningPlayer(player1Score, player2Score);
        if (flag == 1 || flag == 2 || flag == 3) {
            break;
        }

        // Keep doing this until someone wins!
    } while (flag == 0);

    // Display the winner or tie message.
    displayWinner(player1Name, player1Score, player2Name, player2Score);

    printf("thanks for playing Pig!\n");
    return 0;
}
