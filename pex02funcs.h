/** pex02funcs.h
 * ===========================================================
 * Name: Isaac Abramovitz
 * Section: M3/4
 * Project: PEX02
 * Purpose: This program lets the user play the dice game Pig!
 * By calling specific functions to run the game.
 * =========================================================== */

#ifndef PEX02FUNCS_H
#define PEX02FUNCS_H

/**
 * @brief checks to see if the character entered is a char.
 * @param No argument
 * @return returns the character if it's "safe" and good to go!
 * @pre No limits this is a safety function for safe coding.
 * @post If the input was not good it will terminate the function in a "rude" way as Dr. B describes
 * it.
 */
char getCharSafe();

/**
 * @brief pretends to roll a dice!
 * @param No parameters needed!
 * @return returns a single integer between 1 and 6.
 * @pre no preconditions needed for this function to work.
 * @post as a result of the function call, the takeTurn function will work!
 */
int rollDie();

/**
 * @brief This function is where the user "takes a turn" to see what they roll, and present the user
 * with what they rolled, turn score, and total score.
 * @param A specific player name is passed to the function. This alternates between the two users.
 * @param A specific score will be passed to the function as well. This alternates between the two
 * users.
 * @return The returned value is the overall total score the specific player has.
 * @pre The rollDie function must work properly for this function to excecute.
 * @post As a result of this function the user will get a score and be able to play the game.
 */
int takeTurn(char* playerName, int playerScore);

/**
 * @brief This function displays the player's total scores after each time they are done rolling.
 * @param Player1Name is the name of the first user.
 * @param Player1Score is the score of the first user.
 * @param Player2Name is the name of the second user.
 * @param Player2Score is the score of the second user.
 * @return This returns nothing but does print out to the user, both players scores.
 * @pre The scores must be initialized to 0 as well as two player names must be input.
 * @post As a result of the function call, the two users will know where they stand in terms of
 * score.
 */
void displayGameState(char* player1Name, int player1Score, char* player2Name, int player2Score);

/**
 * @brief This function will check the user scores and stop the game if a user is done with their
 * turn and their score is equal to or greater than 100.
 * @param Player1Score is the first players current score.
 * @param Player2Score is the second players current score.
 * @return This returns an integer to keep the while loop in check to see if the game should end or
 * not yet.
 * @pre Nothing must be true before calling the function.
 * @post If either score is above 100 it will call the displayWinner function to present the correct
 * option given the score conditions.
 */
int winningPlayer(int player1Score, int player2Score);

/**
 * @brief This function displays the correct winner or a tie message if their scores are equal and
 * both above 100.
 * @param Player1Name is the name of the first user.
 * @param Player1Score is the score of the first user.
 * @param Player2Name is the name of the second user.
 * @param Player2Score is the score of the second user.
 * @return This function returns nothing.
 * @pre One of the scores must be above or equal to 100 to change the game state with this function.
 * If that is not true the game will keep on playing!
 * @post As a result of this function, if one score is more than or equal to 100, the game will end
 * it will print who the correct winner is or a tie message if applicable.
 */
void displayWinner(char* player1Name, int player1Score, char* player2Name, int player2Score);

#endif