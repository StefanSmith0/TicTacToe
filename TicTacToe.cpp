#include <iostream>

using namespace std;

int board[3][3];
int BLANK = 0;
int X_MOVE = 1;
int O_MOVE = 2;
int X_TURN = 0;
int O_TURN = 1;
int turn = X_TURN;
int X_WINS = 0;
int O_WINS = 0;
char input[3];
char yesNo;

void printBoard();
bool checkWin(int);
bool checkTie();
void clearBoard();
char printChar(int, int);

int main() {
  bool stillPlaying = true;
  while (stillPlaying == true) {
    yesNo = 0;
    while (checkWin(X_MOVE) == false && checkWin(O_MOVE) == false && checkTie() == false) {
      printBoard();
      cout << "Type the coordinates of your move." << endl;
      cin.getline(input, 3);
      cout << input[0] << " " << input[1] << endl;
      //Parsing
      if (input[0] != 'a' && input[0] != 'b' && input[0] != 'c') {
	cout << "Row must be a, b, or c." << endl;
      }	else if (input[1] != '1' && input[1] != '2' && input[1] != '3') {
	cout << "Column must be 1, 2, or 3." << endl;
      } else {
	int row = input[0] - 'a';
	int column = input[1] - '1';
	if (board[row][column] == BLANK) {
	  if (turn == X_TURN) {
	    board[row][column] = X_MOVE;
	    turn = O_TURN;
	  } else {
	    board[row][column] = O_MOVE;
	    turn = X_TURN;
	  }
	} else {
	  cout << "There is already a piece there!" << endl;
	}
      }
      cin.clear();
    }
    //Check for wins, ties
    if (checkWin(X_MOVE) == true) {
      cout << "----X Wins!----" << endl;
      X_WINS++;
    } else if (checkWin(O_MOVE) == true) {
      cout << "----O Wins!----" << endl;
      O_WINS++;
    }
    cout << "X Wins: " << X_WINS << endl;
    cout << "O Wins: " << O_WINS << endl;
    while (yesNo != 'y' && yesNo != 'n') {
      cout << "Continue Playing?" << endl;
      cout << "(y/n): ";
      cin >> yesNo;
    }
    if (yesNo == 'n') {
      stillPlaying = false;
    } else {
      clearBoard();
      turn = X_TURN;
    }
  }
  return 0;
}

// Prints the board in console
void printBoard() {
  char rowLetter;
  cout << "  1 2 3" << endl;
  for (int row = 0; row < 3; row++) {
    rowLetter = 'a' + row;
    cout << rowLetter << " ";
    for (int column = 0; column < 3; column++) {
      cout << printChar(row, column) << ' ';
    }
    cout << endl;
  }
}

//Transforms values from board[][] into chars for printBoard
char printChar(int row, int column) {
  if (board[row][column] == X_MOVE) {
    return 'X';
  } else if (board[row][column] == O_MOVE) {
    return 'O';
  } else {
    return ' ';
  }
}

//Checks if specified player has won
bool checkWin(int player) {
  if (board[0][0] == player && board[0][1] == player && board[0][2] == player) {
    printBoard();
    return true;
  }
  if (board[1][0] == player && board[1][1] == player && board[1][2] == player) {
    printBoard();
    return true;
  }
  if (board[2][0] == player && board[2][1] == player && board[2][2] == player) {
    printBoard();
    return true;
  }
  if (board[0][0] == player && board[1][0] == player && board[2][0] == player) {
    printBoard();
    return true;
  }
  if (board[0][1] == player && board[1][1] == player && board[2][1] == player) {
    printBoard();
    return true;
  }
  if (board[0][2] == player && board[1][2] == player && board[2][2] == player) {
    printBoard();
    return true;
  }
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    printBoard();
    return true;
  }
  if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
    printBoard();
    return true;
  }
  return false;
}

//Checks if the board is full
bool checkTie() {
  for (int column = 0; column < 3; column++) {
    for (int row = 0; row < 3; row++) {
      if (board[row][column] == BLANK) {
	return false;
      }
    }
  }
  printBoard();
  cout << "Tie!" << endl;
  return true;
}

//Clears the board
void clearBoard() {
  for (int column = 0; column < 3; column++) {
    for (int row = 0; row < 3; row++) {
      board[row][column] = BLANK;
    }
  }
}

