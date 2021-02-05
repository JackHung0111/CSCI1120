/*
 * I declare that the assignment here submitted is original
 * except for source material explicitly acknowledged,
 * and that the same or closely related material has not been
 * previously submitted for another course.
 * I also acknowledge that I am aware of University policy and
 * regulations on honesty in academic work, and of the disciplinary
 * guidelines and procedures applicable to breaches of such
 * policy and regulations, as contained in the website.
 *
 * University Guideline on Academic Honesty:
 *   http://www.cuhk.edu.hk/policy/academichonesty/
 *
 * Student Name : Hung Yiu Pan
 * Student ID   : 1155108381
 * Class/Section: CSCI1120
 * Date         : 26/10/2018
 * Email		: 1155108381@link.cuhk.edu.hk
 */

#include<iostream>
using namespace std;

const int SIZE = 12; // Size of the board

// Function Prototypes
void initialization(char board[][SIZE]);
void displayBoard(char board[][SIZE]);
bool checkGameOver(char board[][SIZE]);
bool checkValidMove(char board[][SIZE], int row, int col);
void inputMove(char board[][SIZE], int &row, int &col);
void addVertical(char board[][SIZE], int col);
void addHorizontal(char board[][SIZE], int row);
void diagonalUp(char board[][SIZE], int row, int col);
void diagonalDown(char board[][SIZE], int row, int col);
void updateBoard(char board[][SIZE], int row, int col);

/* To initialize the board with all '.' characters*/
void initialization(char board[][SIZE]) {
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			board[i][j] = '.';
}

/* To display the board*/
void displayBoard(char board[][SIZE]) {
	cout << "  ";
	for (char i = 65; i < SIZE + 65; i++)
		cout << ' ' << i;
	cout << endl;
	for (int i = 0; i < SIZE; i++) {
		if (i < 10)
			cout << ' ';
		cout << i;
		for (int j = 0; j < SIZE; j++)
			cout << ' ' << board[i][j];
		cout << endl;
	}
}

/* To check whether the game is over*/
bool checkGameOver(char board[][SIZE]) {
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			if (board[i][j] == '.')
				return false;
	return true;
}

/* To check whether the move is vaild*/
bool checkValidMove(char board[][SIZE], int row, int col) {
	if ((row < 0 || row >= SIZE) || (col < 0 || col >= SIZE) || (board[row][col] != '.'))
		return false;
	return true;
}

/* To input the valid move*/
void inputMove(char board[][SIZE], int &row, int &col) {
	do {
		char colInput;
		cout << "Put a piece (col row): ";
		cin >> colInput >> row;
		col = colInput - 'A'; // Translate A to Z into 0 to 25
		if (!checkValidMove(board, row, col))
			cout << "Invalid. Try again!" << endl;
	} while (!checkValidMove(board, row, col));
}

/* To add necessary = signs vertically*/
void addVertical(char board[][SIZE], int col) {
	int count = 0;
	// To count number of pieces in row i
	for (int i = 0; i < SIZE; i++)
		if (board[i][col] == '@')
			count++;
	if (count == 2) {
		for (int i = 0; i < SIZE; i++)
			if (board[i][col] == '.')
				board[i][col] = '=';
	}
}

/* To add necessary = signs horizontally*/
void addHorizontal(char board[][SIZE], int row) {
	int count = 0;
	// To count number of pieces in column i
	for (int i = 0; i < SIZE; i++)
		if (board[row][i] == '@')
			count++;
	if (count == 2) {
		for (int i = 0; i < SIZE; i++)
			if (board[row][i] == '.')
				board[row][i] = '=';
	}
}

/* To add necessary = signs in diagonal up way*/
void diagonalUp(char board[][SIZE], int row, int col) {
	int count = 0;
	int startRow = row, startCol = col; // The starting row and column
	int length = (row + col < SIZE) ? row + col + 1 : SIZE * 2 - row - col - 1; // Length of the diagonal
	if (col <= SIZE - row - 1) {
		startRow += col;
		startCol -= col;
	}
	else {
		startRow += SIZE - row - 1;
		startCol -= SIZE - row - 1;
	}
	// To count number of pieces in the diagonal
	for (int i = 0; i < length; i++)
		if (board[startRow - i][startCol + i] == '@')
			count++;
	if (count == 2) {
		for (int i = 0; i < length; i++)
			if (board[startRow - i][startCol + i] == '.')
				board[startRow - i][startCol + i] = '=';
	}
}

/* To add necessary = signs in diagonally down way*/
void diagonalDown(char board[][SIZE], int row, int col) {
	int count = 0;
	int startRow = row, startCol = col; // The starting row and column
	int length = (row > col) ? SIZE - row + col : row + SIZE - col; // Length of the diagonal
	if (row >= col) {
		startRow -= col;
		startCol -= col;
	}
	else {
		startRow -= row;
		startCol -= row;
	}
	// To count number of pieces in the diagonal
	for (int i = 0; i < length; i++)
		if (board[startRow + i][startCol + i] == '@')
			count++;
	if (count == 2) {
		for (int i = 0; i < length; i++)
			if (board[startRow + i][startCol + i] == '.')
				board[startRow + i][startCol + i] = '=';
	}
}

/* To update the board*/
void updateBoard(char board[][SIZE], int row, int col) {
	// Update the corresponding square
	board[row][col] = '@';
	// Update the related square
	addVertical(board, col);
	addHorizontal(board, row);
	diagonalUp(board, row, col);
	diagonalDown(board, row, col);
}

/* To count the number of pieces*/
int countPieces(char board[][SIZE]) {
	int count = 0;
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			if (board[i][j] == '@')
				count++;
	return count;
}

int main() {
	char board[SIZE][SIZE];
	int row, col;
	initialization(board);
	displayBoard(board);
	while (!checkGameOver(board)) { // While the game is not over
		inputMove(board, row, col);
		updateBoard(board, row, col);
		displayBoard(board);
	}
	// The game is now over
	cout << "Num of pieces: " << countPieces(board) << endl; // Prints out number of pieces
	system("pause");
	return 0;
}