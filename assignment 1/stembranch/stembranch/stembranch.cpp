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
 * Date         : 6/9/2018
 */

#include<iostream>
#include<cmath>
using namespace std;

int year_stem(int year) {
	return ((year - 3) % 10 == 0) ? 10 : (year - 3) % 10;
}

int year_branch(int year) {
	return ((year - 3) % 12 == 0) ? 12 : (year - 3) % 12;
}

int date_cyclic(int flag, int year, int month, int date) { //flag=0 for returning the stem, flag=1 for returning the branch 
	int t = year, r = month, C, a, g, i, z;
	if (month <= 2) {
		t = year - 1;
		r = month + 12;
	}
	C = (int)floor(t / 100.0);
	a = t % 100;
	g = 4 * C + (int)floor(C / 4.0) + 5 * a + (int)floor(a / 4.0) + (int)floor(3.0*(r + 1) / 5.0) + date - 3;
	i = (r % 2 != 0) ? 6 : 0;
	z = 8 * C + (int)floor(C / 4.0) + 5 * a + (int)floor(a / 4.0) + (int)floor(3.0*(r + 1) / 5.0) + date + 1 + i;
	if (flag == 0) {
		return (g % 10 == 0) ? 10 : g % 10;
	}
	else return (z % 12 == 0) ? 12 : z % 12;
}

int main() {
	int date, month, year;
	cout << "Enter a date (D M Y): ";
	cin >> date >> month >> year;
	cout << "Year:  S" << year_stem(year) << "-B" << year_branch(year) << endl;
	cout << "Month: " << month << endl;
	cout << "Day:   S" << date_cyclic(0, year, month, date) << "-B" << date_cyclic(1, year, month, date) << endl;
	system("pause");
	return 0;
}