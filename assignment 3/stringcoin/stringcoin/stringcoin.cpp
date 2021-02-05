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
 * Date         : 8/10/2018
 * Email		: 1155108381@link.cuhk.edu.hk
 */

#include <iostream>
#include <string>
using namespace std;

// Function prototypes
bool stringStatus(long long network, int pos);
void displayNetwork(long long network);
int playerScore(long long network, int p);
bool checkIsolatedCoin(long long network, int i);
int countIsolatedCoins(long long network);
void updateNetwork(long long &network, int pos, int p);
void cutString(long long &network, int pos);
int inputMove(long long network, int currentPlayer);


/* Returns true if position pos of the game network still has a string; 
   returns false otherwise */
bool stringStatus(long long network, int pos) {
	network /= 100;
	for (int i = 0; i < 12 - pos; i++)
		network /= 10;
	return (network % 10 != 0);
}

/* Prints the network to the screen */
void displayNetwork(long long network) {
	int p1, p2;
	string s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12;

	p1 = network / 10 % 10;    // Player 1 score
	p2 = network % 10;         // Player 2 score

	s1 = stringStatus(network, 1) ? "|" : " ";
	s2 = stringStatus(network, 2) ? "|" : " ";
	s3 = stringStatus(network, 3) ? "--" : "  ";
	s4 = stringStatus(network, 4) ? "--" : "  ";
	s5 = stringStatus(network, 5) ? "--" : "  ";
	s6 = stringStatus(network, 6) ? "|" : " ";
	s7 = stringStatus(network, 7) ? "|" : " ";
	s8 = stringStatus(network, 8) ? "--" : "  ";
	s9 = stringStatus(network, 9) ? "--" : "  ";
	s10 = stringStatus(network, 10) ? "--" : "  ";
	s11 = stringStatus(network, 11) ? "|" : " ";
	s12 = stringStatus(network, 12) ? "|" : " ";

	cout << "##########\n";
	cout << "#  " << s1 << "  " << s2 << "  #\n";
	cout << "#" << s3 << "$" << s4 << "$" << s5 << "#\n";
	cout << "#  " << s6 << "  " << s7 << "  #\n";
	cout << "#" << s8 << "$" << s9 << "$" << s10 << "#\n";
	cout << "#  " << s11 << "  " << s12 << "  # Player 1 score: " << p1 << "\n";
	cout << "########## Player 2 score: " << p2 << "\n";
}

/* Returns the score of Player p in network */
int playerScore(long long network, int p) {
	int s = 0;
	s = (p == 1) ? network % 100 / 10 : network % 10;
	return s;
}

/* Checks whether the coin is isolated*/
bool checkIsolatedCoin(long long network, int i) {
	/* i is
	   1 for representing upper-left coin
	   2 for representing upper-right coin
	   3 for representing bottom-left coin
	   4 for representing bottom-right coin
	 */
	// Return true if the coin is isolated, else return false
	if (i == 1)
		return ((stringStatus(network, 1) || stringStatus(network, 3) || 
			stringStatus(network, 4) || stringStatus(network, 6)) == false) ? true : false;
	if (i == 2)
		return ((stringStatus(network, 2) || stringStatus(network, 4) || 
			stringStatus(network, 5) || stringStatus(network, 7)) == false) ? true : false;
	if (i == 3)
		return ((stringStatus(network, 6) || stringStatus(network, 8) || 
			stringStatus(network, 9) || stringStatus(network, 11)) == false) ? true : false;
	if (i == 4)
		return ((stringStatus(network, 7) || stringStatus(network, 9) || 
			stringStatus(network, 10) || stringStatus(network, 12)) == false) ? true : false;
}

/* Counts the number of isolated coins*/
int countIsolatedCoins(long long network) {
	int count = 0;
	for (int i = 1; i <= 4; i++)
		if (checkIsolatedCoin(network, i) == true)
			count++;
	return count;
}

/* Cuts the corresponding string*/
void cutString(long long &network, int pos) {
	long long valueChange = 100;
	for (int i = 1; i <= 12 - pos; i++)
		valueChange *= 10;
	network -= valueChange;
}

/* Performs the task of Player p cutting a string in position pos of network.
   The reference parameter network should get updated, and if any coins are
   disconnected, the score of Player p should be incremented, to reflect the
   new network configuration */
void updateNetwork(long long &network, int pos, int p) {
	int isolatedBegin = countIsolatedCoins(network);
	cutString(network, pos);
	int isolatedEnd = countIsolatedCoins(network);
	if (isolatedEnd != isolatedBegin) 
		network += (p == 1) ? (isolatedEnd - isolatedBegin) * 10 : (isolatedEnd - isolatedBegin);
}

/* Inputs a valid number for the cutted string*/
int inputMove(long long network, int currentPlayer) {
	int move;
	do {
		cout << "Player " << currentPlayer << ", make your move (1-12): ";
		cin >> move;
		if (move < 1 || move > 12 || stringStatus(network, move) == false)
			cout << "Invalid. Try again!\n";
	} while (move < 1 || move > 12 || stringStatus(network, move) == false);
	return move;
}

int main() {
	long long network = 11111111111100; //initial network
	int currentPlayer = 1;
	while (countIsolatedCoins(network) != 4) {
		int initialPlayerScore = playerScore(network, currentPlayer);
		displayNetwork(network);
		int pos = inputMove(network, currentPlayer);
		updateNetwork(network, pos, currentPlayer);
		if (countIsolatedCoins(network) == 4) {
			displayNetwork(network);
			if (playerScore(network, 1) > playerScore(network, 2))
				cout << "Player 1 wins!\n";
			else if (playerScore(network, 1) < playerScore(network, 2))
				cout << "Player 2 wins!\n";
			else
				cout << "Draw game!\n";
		}
		else {
			if (initialPlayerScore == playerScore(network, currentPlayer))
				currentPlayer = 3 - currentPlayer; // Changes player
			else
				cout << "Player " << currentPlayer << " scores! Gets another turn.\n"; // Keeps the player for the next turn
		}
	}
	system("pause");
	return 0;
}
