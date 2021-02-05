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
#include "GoldCustomer.h"

using namespace std;

/* Constructors*/
GoldCustomer::GoldCustomer(string id, double d) : Customer(id) {
	setShippingDiscount(d);
}

/* Returns the shipping discount of the gold customer.*/
double GoldCustomer::getShippingDiscount() const {
	return shippingDiscount;
}

/* Sets the shipping discount of the gold customer to the parameter d. 
   But if d < 0.1, then set the shipping discount to 0.1. 
   Besides, if d > 1.0, then set the shipping discount to 1.0. 
   (That is, shipping discount is at least 10% off and at most 100% off.)*/
void GoldCustomer::setShippingDiscount(double d) {
	shippingDiscount = min(max(0.1, d), 1.0);
}

/* This member function overrides the one in its superclass. 
   It returns the rebate of the purchase of the gold customer.
   See the progressive rebate calculation of a gold customer in the Introduction section.*/
double GoldCustomer::rebate() const {
	double rebate = 0.0, initialPurchase = getPurchaseAmount();
	if (initialPurchase <= 500)
		rebate = initialPurchase * 0.01;
	else if (initialPurchase <= 1500)
		rebate = 500 * 0.01 + (initialPurchase - 500) *0.017;
	else
		rebate = 500 * 0.01 + 1000 * 0.017 + (initialPurchase - 1500)*0.024;
	return rebate;
}

/* This member function overrides the one in its superclass. 
   It returns the shipping fee of the purchase of the gold customer, 
   which is that of a standard customer but with a shipping discount.*/
double GoldCustomer::shippingFee() const {
	return Customer::shippingFee()*(1 - shippingDiscount);
}