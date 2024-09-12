#include <iostream>

using namespace std;

// Function to initialize the game board
void initializeBoard(char board[3][3]) 
{
    for (int i = 0; i < 3; ++i) 
    {
        for (int j = 0; j < 3; ++j) 
        {
            board[i][j] = ' ';
        }
    }
}

// Function to display the game board
void displayBoard( char board[3][3]) 
{
    cout<<"_____________________"<<endl;
    cout<<"     "<<"TIC TAC TOE"<<endl;

    cout<<"_____________________"<<endl<<endl;
    cout<<"    "<<"================="<<endl;
    
    cout << "   "<<" || " << board[0][0] << " || " << board[0][1] << " || " << board[0][2] <<" || "<< endl;
    cout <<"    "<<"||===||===||===||" << endl;
    cout << "   "<<" || " << board[1][0] << " || " << board[1][1] << " || " << board[1][2] <<" || "<< endl;// I used space for good readibility and
                                                                                            //aqxsnd code beautiness
    cout <<"    "<<"||===||===||===||" << endl;
    cout << "   "<<" || " << board[2][0] << " || " << board[2][1] << " || " << board[2][2] <<" || " << endl;
    
    cout<<"    "<<"================="<<endl;
}// i make a 9 box for better readibility

// Function to check for a win condition
bool checkWin(char board[3][3], char player)
 {
    // Check rows and columns
    for (int i = 0; i < 3; ++i)
     {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) 
        {
        return true;
    }
    return false;
}

// Function to check for a draw condition
bool checkDraw( char board[3][3]) 
{
    for (int i = 0; i < 3; ++i) 
    {
        for (int j = 0; j < 3; ++j) 
        {
            if (board[i][j] == ' ')//' '----->space
             {
                return false;
            }
        }
    }
    return true;
}

// Function to handle a player's move
bool makeMove(char board[3][3], int row, int col, char player)
 {
    if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ')
     {
        cout << "Invalid move then Try again"<< endl;
        return false;
    }
    board[row - 1][col - 1] = player;//(0 to 2)-1, (0 to 2)-1;
    return true;
}

// Function to play the game and manage results and replay
void playGame()
 {
    char board[3][3];
    char currentPlayer = 'X';
    //char currentPlayer = 'O';
    char playAgain = 'y';// if player'X' want to play again then enter 'y'
    //char playgain = 'Y';
    while (playAgain == 'y' || playAgain == 'Y')
     {
        initializeBoard(board);
        bool gameWon = false;
        bool gameOngoing = true;

 /* if (playAgain == 'y') 
    {
            currentPlayer = 'X';  // Player 'X' starts if enter 'y'
    } 
    else if (playAgain == 'Y') 
          {
            currentPlayer = 'O';  // Player 'O' starts if enter 'Y'
          }*/
         

        while (gameOngoing) 
        {
            displayBoard(board);
            int row, col;
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;

            if (makeMove(board, row, col, currentPlayer)) 
            {
                if (checkWin(board, currentPlayer)) 
                {
                    displayBoard(board);
                    cout << "Player " << currentPlayer << " wins"<<endl;
                    gameWon = true;
                    gameOngoing = false;
                } else if (checkDraw(board))
                 {
                    displayBoard(board);
                    cout << "The game is a draw"<<endl;
                    gameWon = true;
                    gameOngoing = false;
                } 
                else 
                {
                    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // tertiary operator apply for switching a turn
                }
            }
        }
 //if someone can won or ended with draw then Ask if they want to play again
             cout << "Do you want to play again? (y/n or Y/N): ";
            cin >> playAgain;
        // Reset the current player for a new game
           currentPlayer = 'O';
           // currentPlayer = 'X';
    }

    cout << "Thanks for playing"<<endl;
}

// Main function
int main() 
{
    playGame();
    return 0;
}
