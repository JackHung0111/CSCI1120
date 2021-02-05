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
#include "DiamondCustomer.h"

using namespace std;

/* Constructors*/
DiamondCustomer::DiamondCustomer(string id, double d, double p) :GoldCustomer(id, d) {
	setPremium(p);
}

/* Returns the rebate premium of the diamond customer.*/
double DiamondCustomer::getPremium() const {
	return premium;
}

/* Sets the premium of the diamond customer to the parameter p or 1.1, whichever is higher.*/
void DiamondCustomer::setPremium(double p) {
	premium = max(p, 1.1);
}

/* This member function overrides the one in its superclass. 
   It returns the rebate of the purchase of the diamond customer, 
   which is that of a gold customer multiplied by the premium.*/
double DiamondCustomer::rebate() const {
	return GoldCustomer::rebate() * premium;
}

/* This member function overrides the one in its superclass. 
   It returns the shipping fee of the purchase of the diamond customer, 
   which is that of a gold customer but with a $30 markdown. 
   However, if the fee becomes negative after markdown, 
   then the member function simply returns 0.0.*/
double DiamondCustomer::shippingFee() const {
	return (GoldCustomer::shippingFee() < 30.0) ? 0.0 : GoldCustomer::shippingFee() - 30;
}
