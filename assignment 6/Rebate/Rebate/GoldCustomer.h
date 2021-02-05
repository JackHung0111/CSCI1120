#ifndef GOLD_H
#define GOLD_H

#include <string>
#include "Customer.h"
using namespace std;

class GoldCustomer : public Customer {
public:
    GoldCustomer(string id = "0000000000", double d = 0.1);
    double getShippingDiscount() const;
    void setShippingDiscount(double d);
    virtual double rebate() const;
    virtual double shippingFee() const;
private:
    double shippingDiscount;
};

#endif // GOLD_H
