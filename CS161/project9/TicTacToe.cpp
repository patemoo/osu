/**
 * Author: Patrick Moore
 * Date:
 * Description: This file has the method implementation of the TicTacToe class
 *              as well as a main function that creates a new game and calls play on it.
 **/

 #include "TicTacToe.hpp"
 #include "Board.cpp"

 using std::cin;
 using std::toupper;
 using std::tolower;

/**
 * Description: main creates new TicTacToe instance and calls play on it.
 **/
int main()
{
  TicTacToe newGame('O');

  newGame.play();

  return 0;
}

/**
 * Description: Takes in a char for which player will make the first move.
 **/
TicTacToe::TicTacToe(char player1)
{ 
  activePlayer = tolower(player1);
}


/**
 * Description: play includes a loop that manages the flow of the game 
 *              and a switch statement that prints the results
 **/
void TicTacToe::play()
{ 
  State currentState;

  // Continue looping while game is UNFINISHED.
  do 
  {
    int x;
    int y;

    // Show board so user knows their options.
    gameBoard.print();

    // Prompt player to make a move.
    char player = toupper(activePlayer);
    cout << "Player " << player << ": please enter your move." << endl;
    cin >> x >> y;

    // evaluate players move. Have player try agin if square is already taken.
    if (gameBoard.makeMove(x, y, activePlayer))
    {
      activePlayer = switchActivePlayer(activePlayer);
    } else {
      cout << "\nThat square is already taken." << endl;
    }
    
    // Store current state so we know if we need to loop through again.
    currentState = gameBoard.gameState();

  } while (currentState == UNFINISHED);

  // game over!
  switch (currentState)
  {
    case X_WON: 
      cout << "\nPlayer X wins!\n";
      break;
    case O_WON:
      cout << "\nPlayer O wins!\n";
      break;
    case DRAW:
      cout << "\nTie Game!\n";
      break;
  }

  // Show end game board.
  gameBoard.print();
}


/**
 * Description: This function toggles between players.
 **/
char TicTacToe::switchActivePlayer(char player)
{
  if (player == 'o')
  {
    return 'x';
  } else
  {
    return 'o';
  }
}