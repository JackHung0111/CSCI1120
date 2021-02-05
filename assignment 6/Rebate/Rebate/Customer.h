#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
using namespace std;

class Customer {
public:
    Customer(string id = "0000000000");
    string getCustomerID() const;
    string getCustomerName() const;
    void setCustomerName(string n);
    double getPurchaseAmount() const;
    void setPurchaseAmount(double p);
    double getWeight() const;
    void setWeight(double w);
    virtual double rebate() const;
    virtual double shippingFee() const;
private:
    string cid, name;
    double purchase, weight;
};

#endif // CUSTOMER_H
