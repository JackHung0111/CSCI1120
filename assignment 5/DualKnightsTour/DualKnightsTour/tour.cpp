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

/* To input the valid starting positions for @ and # */
DualKnightsTour inputStartPosition() {
	int startR1, startR2, startC1, startC2; // starting positions
	bool valid;
	do {
		cout << "Knights' starting positions (row1 col1 row2 col2): ";
		cin >> startR1 >> startC1 >> startR2 >> startC2;
		if (startR1 < 0 || startR1 > 5 || startC1 < 0 || startC1 > 5 || 
			startR2 < 0 || startR2 > 5 || startC2 < 0 || startC2 > 5 ||
			startR1 == startR2 || startC1 == startC2) {
			valid = false;
			cout << "Invalid position(s)!" << endl;
		}
		else valid = true;
	} while (!valid);
	DualKnightsTour tour(startR1, startC1, startR2, startC2);
	return tour;
}

/* To input the move*/
void inputMove(DualKnightsTour &tour) {
	char knight;
	int row, col;
	bool valid;
	do {
		cout << "Move (knight row col): ";
		cin >> knight >> row >> col;
		valid = tour.move(knight, row, col);
		if (!valid)
			cout << "Invalid move!" << endl;
	}while (!valid);
}

int main() {
	DualKnightsTour tour = inputStartPosition();
	do {
		tour.print();
		inputMove(tour);
		if (!tour.hasMoreMoves()) {
			tour.print();
			cout << "No more moves!" << endl;
		}
	} while (tour.hasMoreMoves());
	system("pause");
	return 0;
}