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
#include <algorithm>
#include "Customer.h"

using namespace std;

/* Change the supposed ID to the Customers' ID*/
string CID(string id) {
	string cid("");
	for (int i = 0; i < (int)id.length(); i++) 
		if (id.at(i) >= '0' && id.at(i) <= '9')
			cid = cid + id.at(i);
	if ((int)cid.length() < 10)
		for (int i = 0; i <= 10 - (int)cid.length(); i++)
			cid = "0" + cid;
	else if ((int)cid.length() > 10)
		cid.erase(0, cid.length() - 10);
	return cid;
}

/* Constructors*/
Customer::Customer(string id) {
	cid = CID(id);
	setCustomerName("");
	setPurchaseAmount(0.0);
	setWeight(0.5);
}

/* Returns the customer ID of the customer.*/
string Customer::getCustomerID() const {
	return cid;
}

/* Returns the name of the customer.*/
string Customer::getCustomerName() const {
	return name;
}

/* Sets the customer name to the parameter n.*/
void Customer::setCustomerName(string n) {
	name = n;
}

/* Returns the purchase amount of the customer.*/
double Customer::getPurchaseAmount() const {
	return purchase;
}

/* Sets the purchase amount of the customer to the parameter p or 0.0, whichever is higher. 
   (That is, if p is less than 0.0, then set the purchase amount to 0.0 instead.)*/
void Customer::setPurchaseAmount(double p) {
	purchase = max(p, 0.0);
}

/* Returns the shipping weight of the purchase*/
double Customer::getWeight() const {
	return weight;
}

/* Sets the shipping weight to the parameter w or 0.5, whichever is higher.*/
void Customer::setWeight(double w) {
	weight = max(w, 0.5);
}

/* This virtual member function computes and returns the rebate of the customer in this purchase. 
   See the progressive rebate calculation of a standard customer in the Introduction section.*/
double Customer::rebate() const {
	double rebate = 0.0, initialPurchase = purchase;
	if (initialPurchase <= 500)
		rebate = initialPurchase * 0.01;
	else if (initialPurchase <= 1500)
		rebate = 500 * 0.01 + (initialPurchase - 500) *0.015;
	else
		rebate = 500 * 0.01 + 1000 * 0.015 + (initialPurchase - 1500)*0.02;
	return rebate;
}

/* This virtual member function returns the shipping fee of the purchase of the customer. 
   Again, see how the shipping fee of a standard customer purchase is determined in the Introduction section.*/
double Customer::shippingFee() const {
	if (purchase < 400.0)
		return (weight < 8.0) ? 40.0 : 60.0;
	else return (weight < 8.0) ? 0.0 : 40.0;
}