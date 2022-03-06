#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class car {
 friend ostream&operator<<(ostream & os , const car & c) ;
protected:
    string model;
    string color;
public:
    car(string model, string color) : model{model} , color {color} {}
    
     virtual void set_color(string c) {
        color =c;
    }
     virtual void print(ostream & os) const=0;
     virtual unique_ptr<car> clone()=0;
     virtual   void display() {
        cout<<model<<":"<<color<<":"<<endl;
    }
};
ostream&operator<<(ostream & os , const car & c) {
    c.print(os);
    return os;
}


class raceCar : public car {
private:
    int maxSpeed;
    public:
    raceCar(string model, string color , int maxSpeed) :car{model , color} , maxSpeed{maxSpeed} {}
    virtual unique_ptr<car> clone() {
        return make_unique<raceCar>(*this);// return unique pointer in the memory that points to the same info int the first
        //object that created but with a diff location in the memory
    }
    virtual void print(ostream & os) const{
        os<<model<<":"<<color<<":"<<maxSpeed<<endl;
    }
};
 

int main()
{
     unique_ptr<car> prototype = make_unique<raceCar>("urus","white " ,320);
     cout<<* prototype;
     unique_ptr<car> red = prototype->clone();
     red->set_color("red");
     cout<<*red;
     unique_ptr<car> black= prototype->clone();
     black->set_color("black");
     cout<<* black;
  //  unique_ptr<car> b =move( black);
    //cout<<*b;
   
}
