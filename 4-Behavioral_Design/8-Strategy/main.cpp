#include <iostream>
#include <string>
#include <list>
using namespace std;
//means let the user choose the strategy that he want like make payment there are many ways so let him decide

class paymentStrategy {
public:
    virtual void payment(int amount)=0;
};
class creditCard : public paymentStrategy{
private:
    string name;
    int card_number;
    int security_number;
public:
    creditCard(string n, int c , int s):name{n},card_number{c}, security_number{s} {}
    virtual void payment(int amount) {
        cout<<"amount "<<amount<<" was paid using credit card"<<endl;
    }
};
class payPal : public paymentStrategy{
private:
    string emial;
    int password;
public:
    payPal(string n, int p ):emial{n},password {p} {}
    virtual void payment(int amount) {
        cout<<"amount "<<amount<<" was paid using payPal"<<endl;
    }
};
 

class item {
    string name;
    int price;
public:
    item(string n , int p):name{n}, price{p} {}
    string get_name(){
        return name;
    }
    int get_price(){
        return price;
    }
    
};
class shoppingCart {
private:
    list<item> items;
public:
    void add(item i) {
        items.emplace_back(i);
    }
    int get_total() {
        int sum=0;
        auto it=items.begin();
        while(it!= items.end()) {
            sum+= it->get_price();
            it++;
        }
        return sum;
    }
    void displayproducts() {
        cout<<"_________________"<<endl;
        auto it= items.begin();
        while(it!= items.end()) {
            cout<<"product is "<<it->get_name()<<" : "<<"price is "<<it->get_price()<<endl;
            it++;
        }
    }
    void pay(paymentStrategy * p) {
        int amount=get_total();
        displayproducts();
        p->payment(amount);
    }
};

int main()
{
	 
     shoppingCart cart;
     cart.add(item("tv", 4000));
     cart.add(item("playstation 5", 5000 ));
     paymentStrategy *c=new creditCard("ahmed",204060 ,354);
     cart.pay(c);
     
}
