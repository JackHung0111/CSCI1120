#ifndef DIAMOND_H
#define DIAMOND_H

#include <string>
#include "GoldCustomer.h"
using namespace std;

class DiamondCustomer : public GoldCustomer {
public:
    DiamondCustomer(string id = "0000000000", double d = 0.1,
                                              double p = 1.1);
    double getPremium() const;
    void setPremium(double p);
    virtual double rebate() const;
    virtual double shippingFee() const;
private:
    double premium;
};

#endif // DIAMOND_H
