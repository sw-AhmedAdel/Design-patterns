#include <iostream>
#include <vector>

using namespace std;

class MainDish{
    string name;
public:
    MainDish(string name):name{name} {}
    void order(){
        cout<<"Main Dish is "<<name<<" is ordered"<<endl;
    }
     void cancel(){
        cout<<"Main Dish is "<<name<<" is canceled"<<endl;
    }
};

class Desert{
    string name;
public:
    Desert(string name):name{name} {}
    void order(){
        cout<<"Desert is "<<name<<" is ordered"<<endl;
    }
     void cancel(){
        cout<<"Desert is "<<name<<" is canceled"<<endl;
    }
};

// create the command 

class Command {
public:
    virtual void execute()=0;
};

class OrderMainDish : public Command {
private:
    MainDish dish;
public:
    OrderMainDish(MainDish d) :dish{d} {}
    virtual void execute() {
            dish.order();
        }
};

class CancelMainDish : public Command {
private:
    MainDish dish;
public:
    CancelMainDish(MainDish d) :dish{d} {}
    virtual void execute() {
            dish.cancel();
        }
};

class OrdernDesert: public Command {
private:
    Desert dish;
public:
    OrdernDesert(Desert d) :dish{d} {}
    virtual void execute() {
            dish.order();
        }
};

class CancelDesert : public Command {
private:
    Desert dish;
public:
    CancelDesert(Desert d) :dish{d} {}
    virtual void execute() {
            dish.cancel();
        }
};
/*
class waiter{
private:
    Command *s;
public:
    waiter(Command *ss):s{ss} {}
    void set_object(Command *c) {
        s=c;
    }
    void execute() {
        s->execute();
    }
};
int main()
{
	 MainDish dish1("pizza");
     Command *order1= new OrderMainDish(dish1);
     waiter w1(order1);
     w1.execute();
     order1=new CancelMainDish(dish1);
     w1.set_object(order1);
     w1.execute();
}
*/
class waiter{
private:
    vector<Command *> vec;
public:
    void pushOrder(Command *c) {
        vec.push_back(c);
    }
    void execute() {
        for(auto *c: vec)
               c->execute();
        vec.clear();
    }
    
};
int main()
{
	  MainDish d1("pizza");
      MainDish d2("burger king");
      Command *c=new OrderMainDish(d1);
      Command *cc=new OrderMainDish(d2);
      Command *cancel1=new CancelMainDish(d2);
      Desert d ("cake");
      Command * d3=new OrdernDesert(d);
      waiter w;
      w.pushOrder(c);
      w.pushOrder(cc);
      w.pushOrder(cancel1);
      w.pushOrder(d3);
      w.execute();

      
      
}