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
 * Date         : 20-9-2018
 */

#include<iostream>
#include<cmath>
using namespace std;

int check() { //To input a valid integer
	int input;
	do {
		cout << "Enter an integer: ";
		cin >> input;
		if (input <= 0)
			cout << "Invalid. Try again!" << endl;
	} while (input <= 0);
	return input;
}

int calculation(int n, int func) { 
	//If func is 0, calculate the sum of integer n and the individual digits of n
	//If func is 1, Count number of digit of n
	int sum = n, count = 0;
	while (n > 0) {
		sum += n % 10;
		n /= 10;
		count++;
	}
	return (func == 0) ? sum : count;
}

int summation(int n) { //Find the largest found integer if n is not a self number
	for (int i = n - 1; i > 1; i--)
		if (n == calculation(i,0))
			return i;
	return -1;//-1 means that n is a self number
}

void self(int input) { //Output the numbers
	int i = input;
	while (summation(i) != -1) {
		cout << i << " = " << summation(i);
		for (int j = 1; j <= calculation(summation(i),1); j++)
			cout << " + " << (summation(i) / ((int)(pow(10, j - 1)))) % 10;
		cout << endl;
		i++;
	}
	cout << i << " is a self number.\n";
}

int main() {
	int input = check();
	self(input);
	system("pause");
	return 0;
}