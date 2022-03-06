#include <iostream>
using namespace std;

class item {
public:
    virtual void prepare()=0;
    virtual int get_cost()=0;
};

class pizza : public item {
public:
  virtual void prepare()=0;
  virtual int get_cost()=0;
};

class superSuprem : public pizza {
public:
  virtual void prepare() {
      cout<<"prepare superSuprem pizza ";
  }
  virtual int get_cost(){
      return 5;
  }
};

class cheikenpizza : public pizza {
public:
  virtual void prepare() {
      cout<<"prepare  cheikenpizza pizza ";
  }
  virtual int get_cost(){
      return 5;
  }
};
class pizzaDecorator : public item {
protected :
    item * piz;
public:
    pizzaDecorator(item * p) :piz{p} {}
    virtual void prepare()=0;
    virtual int get_cost()=0;
};
class dubbleChesse : public pizzaDecorator {
public:
    dubbleChesse(item * p) :pizzaDecorator{p} {}
    virtual void prepare() {
            piz->prepare();
            cout<<" + dubble Chesse";
        }
    virtual int get_cost(){
      return piz->get_cost() +5;
  }
    
};
class spicy : public pizzaDecorator {
public:
    spicy(item * p) :pizzaDecorator{p} {}
    virtual void prepare() {
            piz->prepare();
            cout<<" + spicy ";
        }
     virtual int get_cost(){
      return piz->get_cost() +5;
  }
};

class katchap : public pizzaDecorator {
public:
    katchap(item * p) :pizzaDecorator{p} {}
    virtual void prepare() {
            piz->prepare();
            cout<<" + katchap ";
        }
   virtual int get_cost(){
      return piz->get_cost() +5;
  }
};


int main()
{
	item * order=new dubbleChesse( new spicy( new katchap( new superSuprem())));
    order->prepare();
    cout<<endl;
    cout<<"total price is "<<order->get_cost()<<endl;
    
    
}
