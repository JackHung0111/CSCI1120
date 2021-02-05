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
 * Date         : 23/11/2018
 * Email		: 1155108381@link.cuhk.edu.hk
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include "Customer.h"
#include "GoldCustomer.h"
#include "DiamondCustomer.h"

using namespace std;

/* To read the data from the file
   and then create objects and set up the pointers*/
void fileInput(vector<Customer *> &customers, ifstream &fin, int n) {
	string customerType, id, name;
	double purchase, weight, discount, premium;
	for (int i = 0; i < n; i++) {
		fin >> customerType >> id >> name >> purchase >> weight;
		if (customerType == "GC") { // Gold Customers
			fin >> discount;
			customers[i] = new GoldCustomer(id, discount);
		}
		else if (customerType == "DC") { // Diamond Customers
			fin >> discount >> premium;
			customers[i] = new DiamondCustomer(id, discount, premium);
		}
		else // Standard Customers
			customers[i] = new Customer(id);
		customers[i]->setCustomerName(name);
		customers[i]->setPurchaseAmount(purchase);
		customers[i]->setWeight(weight);
	}
}

/* To output the result on the console*/
void outputResult(vector<Customer *> customers, int n) {
	cout << "Process " << n << " customer(s):" << endl;
	for (int i = 0; i < n; i++) { // Output the rebate and shipping fee
		cout << fixed << setprecision(2);
		cout << customers[i]->getCustomerID() << " ";
		cout << customers[i]->rebate() << " ";
		cout << customers[i]->shippingFee() << " " << endl;
	}
}

int main() {
	cout << "Enter file name: ";
	string filename;
	getline(cin, filename);
	ifstream fin(filename.c_str());
	if (fin.fail()) {
		cout << "Cannot open data file. Program exit!\n";
		exit(1); //Terminate the program
	}
	int n; // the total number of customer purchases of the platform in a day’s business
	fin >> n;
	vector<Customer *> customers(n); // Vector of superclass pointers
	fileInput(customers, fin, n);
	fin.close(); // File close
	outputResult(customers, n);
	for (int i = 0; i < n; i++) // Release dynamic memory
		delete customers[i];
	system("pause");
	return 0;
}