/*  TIC TAC TOE GAME
    - Game is played on a 3x3 grid, the game is played by 2 players
    - You should create an array to represent the board
        + Can be of type char and consist of 10 elements (do not use zero)
        + each element represents a coordinate on the board that the user can select
    - some function that you should probable create
        + checkForWin - checks to see if a player has won or the game is a draw
        + drawboard - redraws the board for each player turn
        + markBoard - sets the char array with a selection and check for an invalid selection
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char board[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int choice, player, turn, gameStatus;
char mark;

int checkForWin();
void drawBoard();
void markBoard(char mark);


int main()
{
    turn = 1;

    do
    {
        drawBoard();
        player = (turn % 2)? 1:2;
        mark = (player == 1)? 'X':'O';
        printf("Player %d, it's your turn!\n", player);
        printf("Enter a number to mark the board: ");
        scanf("%d", &choice);
        markBoard(mark);
        gameStatus = checkForWin();
        turn++;
    } while (gameStatus == -1);

    if (gameStatus == 1)
        printf("==>\aPlayer %d win ", player);

    else (gameStatus == 0);
        printf("==>\aGame draw");

    return 0;

}

int checkForWin()
{
    int gameStatus = 0;
    if (    ( (board[1] == board[2]) && (board[2] == board[3]) )    ||
            ( (board[4] == board[5]) && (board[5] == board[6]) )    ||
            ( (board[7] == board[8]) && (board[8] == board[9]) )    ||
            ( (board[1] == board[4]) && (board[4] == board[7]) )    ||
            ( (board[2] == board[5]) && (board[5] == board[8]) )    ||
            ( (board[3] == board[6]) && (board[6] == board[9]) )    ||
            ( (board[1] == board[5]) && (board[5] == board[9]) )    ||
            ( (board[3] == board[5]) && (board[5] == board[7]) ))
            gameStatus = 1;
            else if (   board[1] != '1' && board[2] != '2' && board[3] != '3' &&
                        board[4] != '4' && board[5] != '5' && board[6] != '6' &&
                        board[7] != '7' && board[8] != '8' && board[9] != '9')
            {
            gameStatus = 0;
            }
            else gameStatus = -1;

    return gameStatus;
}

void drawBoard()
{
    system("cls");

    printf("|       |       |       |\n");
    printf("|   %c   |   %c   |   %c   |\n", board[1], board[2], board[3]);
    printf("|_______|_______|_______|\n");
    printf("|       |       |       |\n");
    printf("|   %c   |   %c   |   %c   |\n", board[4], board[5], board[6]);
    printf("|_______|_______|_______|\n");
    printf("|       |       |       |\n");
    printf("|   %c   |   %c   |   %c   |\n", board[7], board[8], board[9]);
    printf("|       |       |       |\n");
}

void markBoard(char mark)
{

    if (choice == 1 && board[1] == '1')
        board[1] = mark;
    else if (choice == 2 && board[2] == '2')
        board[2] = mark;

    else if (choice == 3 && board[3] == '3')
        board[3] = mark;

    else if (choice == 4 && board[4] == '4')
        board[4] = mark;

    else if (choice == 5 && board[5] == '5')
        board[5] = mark;

    else if (choice == 6 && board[6] == '6')
        board[6] = mark;

    else if (choice == 7 && board[7] == '7')
        board[7] = mark;

    else if (choice == 8 && board[8] == '8')
        board[8] = mark;

    else if (choice == 9 && board[9] == '9')
        board[9] = mark;
        else
    {
        printf("PLease enter a number: ");

        turn--;
        getch();
    }


}

