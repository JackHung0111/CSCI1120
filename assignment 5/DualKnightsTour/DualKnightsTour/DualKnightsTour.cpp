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
 * Date         : 09/11/2018
 * Email		: 1155108381@link.cuhk.edu.hk
 */

#include <iostream>
#include <cmath>
#include "DualKnightsTour.h"

using namespace std;

/*	1. To create a dual-knight’s tour where the knights @ and # are initially positioned at (r1,c1) and (r2,c2) respectively.
	2. To set all array elements of the data member board as ‘.’ (unvisited) except the initial position, 
	   which should be set as ‘A’ for @ and ‘a’ for #.
	3. To set the data members (a) posR1, posC1, posR2, and posC2 using the parameters r1, c1, r2, and c2 respectively, 
						   and (b) all the other data members as 0. */
DualKnightsTour::DualKnightsTour(int r1, int c1, int r2, int c2) {
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++)
			board[i][j] = '.';
	board[r1][c1] = '@';
	board[r2][c2] = '#';
	posR1 = r1;
	posR2 = r2;
	posC1 = c1;
	posC2 = c2;
	steps1 = steps2 = consec1 = consec2 = 0;
}

/* To print the configuration of the dual-knight’s tour. */
void DualKnightsTour::print() const {
	cout << " ";
	for (int i = 0; i < 6; i++)
		cout << ' ' << i;
	cout << endl;
	for (int i = 0; i < 6; i++) {
		cout << i;
		for (int j = 0; j < 6; j++)
				cout << ' ' << board[i][j];
		cout << endl;
	}
}

/* To check if r1,c1 and r2,c2 are in L-shape */
bool checkLShape(int r1, int c1, int r2, int c2) {
	if ((abs(r1 - r2) == 2 && abs(c1 - c2) == 1) || (abs(r1 - r2) == 1 && abs(c1 - c2) == 2))
		return true;
	return false;
}

/* To check whether the parameter knight in the tour can be moved from its current position to the destination at (r,c). 
   The knight is not actually moved in this member function; it just checks if the move is valid or not. */
bool DualKnightsTour::isValid(char knight, int r, int c) const {
	if (r >= 0 && r < 6 && c >= 0 && c < 6)
		if (board[r][c] == '.')
			if (knight == '@' && consec1 < 2)
				return checkLShape(r, c, posR1, posC1);
			else if (knight == '#' && consec2 < 2)
				return checkLShape(r, c, posR2, posC2);
	return false;
}

/* To check whether either knight has more possible moves to make. 
   This member function should return true if at least one knight can make at least one valid move; and should return false otherwise.*/
bool DualKnightsTour::hasMoreMoves() const {
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++)
			if (isValid('@', i, j) || isValid('#', i, j))
				return true;
	return false;
}

/* To move the parameter knight from its current position to the destination at (r,c). 
   A valid move by @ should:  (a) update its move sequence and its current position, 
                              (b) increment steps1 and consec1, 
							  (c) reset consec2 to 0, and 
							  (d) return true.
   If the move is invalid, this member function updates nothing and returns false */
bool DualKnightsTour::move(char knight, int r, int c) {
	if (isValid(knight, r, c)) {
		if (knight == '@') { // if knight is @
			board[posR1][posC1] = steps1 + 'A';
			board[r][c] = '@';
			posR1 = r;
			posC1 = c;
			steps1++;
			consec1++;
			consec2 = 0;
			return true;
		}
		else { // if knight is #
			board[posR2][posC2] = steps2 + 'a';
			board[r][c] = '#';
			posR2 = r;
			posC2 = c;
			steps2++;
			consec2++;
			consec1 = 0;
			return true;
		}
	}
	else return false;
}