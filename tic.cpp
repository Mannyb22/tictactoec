#include <vector>
#include <iostream>

using namespace std;


/// @brief Draws the provided tic-tac-toe board to the screen
//  @param board is the tic-tac-toe board that should be drawn
void drawBoard(const vector < char >&gameBoard) {
   for (int i = 0; i < 9; i += 3) {
      cout << "  " << gameBoard.at(i) << "  |  " << gameBoard.at(i + 1) << "  |  "
         << gameBoard.at(i + 2) << "  " << endl;
      if (i < 6) {
         cout << "-----|-----|-----" << endl;
      }
   }
   cout << endl;

   return;
}



/// @brief Fills vector with characters starting at lower case a.
///
///     If the vector is size 3 then it will have characters a to c.
///     If the vector is size 5 then it will have characters a to e.
///     If the vector is size 26 then it will have characters a to z.
///
/// @param v the vector to initialize
/// @pre-condition the vector size will never be over 26
void initVector(vector <char> &v) {

   // TODO: implement function
   char let = 'a';
   if (v.size() < 26) {
      for(int i = 0; i < v.size(); i++) {
         v.at(i) = static_cast<char>(let + i);
      }
   }
}


/// @brief Converts a character representing a cell to associated vector index
/// @param the position to be converted to a vector index
/// @return the integer index in the vector, should be 0 to (vector size - 1)
int convertPosition(char boardPosition) {
   // TODO: implement function
   for(int i = static_cast<int>('a'); i <= static_cast<int>('z'); i++) {
      if (i == static_cast<int>(boardPosition)) {
         return i - static_cast<int>('a');
      }
   }
}


/// @brief Predicate function to determine if a spot in board is available.
/// @param board the current tic-tac-toe board
/// @param position is an index into vector to check if available
/// @return true if position's state is available (not marked) AND is in bounds
bool validPlacement(const vector<char>  &gameBoard, int positionIndex) {
   int count = 0;
   if(positionIndex >= gameBoard.size()) {
      return false;
   }
   for(int i = 0; i < gameBoard.size(); i++) {
      if(gameBoard.at(i) != 'X' && gameBoard.at(i) != 'O') {
         count++;
      }
   }
   if(count > 0) {
      if(gameBoard.at(positionIndex) != 'X' && gameBoard.at(positionIndex) != 'O') {
         return true;
      } else {
         return false;
      }
   }
   else {
      return false;
   }


   // TODO: implement function

}

/// @brief Acquires a play from the user as to where to put her mark
///
///     Utilizes convertPosition and validPlacement functions to convert the
///     user input and then determine if the converted input is a valid play.
///     Continues asking for a position until a valid position has been entered.
///
/// @param board the current tic-tac-toe board
/// @return an integer index in board vector of a chosen available board spot
int getPlay(const vector<char> &gameBoard) {

   // TODO: implement function
   char boardPosition;
   cout << "Please choose a position: " << endl;
   cin >> boardPosition;
   int position = convertPosition(boardPosition);
   bool validPos = validPlacement(gameBoard, position);
   while(validPos == false) {
     cout << "Please choose a position: " << endl;
      cin >> boardPosition;
      position = convertPosition(boardPosition);
      validPos = validPlacement(gameBoard, position);
   }

   return position;
}


/// @brief Predicate function to determine if the game has been won
///
///     Winning conditions in tic-tac-toe require three marks from same
///     player in a single row, column or diagonal.
///
/// @param board the current tic-tac-toe board
/// @return true if the game has been won, false otherwise
bool gameWon(const vector<char> &gameBoard) {
   if(gameBoard.at(0) == gameBoard.at(1) && gameBoard.at(0) == gameBoard.at(2)) {
     return true;
   } else if (gameBoard.at(3) == gameBoard.at(4) && gameBoard.at(3) == gameBoard.at(5)) {
     return true;
   } else if (gameBoard.at(6) == gameBoard.at(7) && gameBoard.at(6) == gameBoard.at(8)){
     return true;
   } else if(gameBoard.at(0) == gameBoard.at(3) && gameBoard.at(0) == gameBoard.at(6)) {
     return true;
   } else if (gameBoard.at(2) == gameBoard.at(5) && gameBoard.at(2) == gameBoard.at(8)){
     return true;
   } else if (gameBoard.at(0) == gameBoard.at(4) && gameBoard.at(0) == gameBoard.at(8)) {
     return true;
   } else if (gameBoard.at(2) == gameBoard.at(4) && gameBoard.at(2) == gameBoard.at(6)) {
     return true;
   } else {
     return false;
   }
}


/// @brief Predicate function to determine if the board is full
/// @param board the current tic-tac-toe board
/// @return true iff the board is full (no cell is available)
bool boardFull(const vector<char> &gameBoard) {
  int count  = 0;
   for(int i = 0; i < gameBoard.size(); i++) {
     if (gameBoard.at(i) != 'X' && gameBoard.at(i) != 'O') {
       count++;
     }
   }
   if (count > 0) {
     return false;
   } else {
     return true;
   }
}


// Global constants for player representation
const int PLAYER1 = 0;
const int PLAYER2 = 1;

int main() {
   vector<char> gameBoard(9);
   int curPlay;
   int whosTurn = PLAYER1; // Player 1 always goes first and is 'X'
   char xy;
   bool gameOver = false;
   initVector(gameBoard);
   drawBoard(gameBoard);

   while(gameOver == false) {
     curPlay = getPlay(gameBoard);
     if (whosTurn == 0) {
       xy = 'X';
     } else {
       xy = 'O';
     }
     gameBoard.at(curPlay) = xy;

      if(whosTurn == 0) {
        whosTurn = PLAYER2;
      }  else {
        whosTurn = PLAYER1;
      }

      drawBoard(gameBoard);

      if(gameWon(gameBoard) == true) {
        if(whosTurn == 0) {
          cout << "Player2 Wins!!" << endl;
          gameOver = true;
        } else{
          cout << "Player1 Wins!!" << endl;
          gameOver = true;
        }
      } else if (boardFull(gameBoard) == true) {
        cout << "No one wins" << endl;
        gameOver = true;
      }
    }



   return 0;
}
