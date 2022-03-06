#include <iostream>
#include <vector>
#include <string>
using namespace std;
//builder is about if the object takes a lot of methods to be created do not do thet in the clinet
//do it in method and call it in the client

class product {
protected:
    vector<string> parts;
public:
      void add(string part) {
            parts.push_back(part);
        }
       void show(){
        cout<<"products components are >>"<<endl;
        for(auto p : parts)
            cout<<p<<endl;
    }
};

class ibuilder {
public:
   // the consentraction of car is here
    virtual void set_up_operations()=0;
    virtual void build_body()=0;
    virtual void insert_wheels()=0;
    virtual void add_head_lights()=0;
    virtual void end_operations()=0;
    virtual product * get_car_object()  =0;
};
class car : public ibuilder {
private:
    product  * p = new product;
    string brand;
public:
    car(string n) : brand{n} {}
    virtual void set_up_operations() override {
        p->add("car model is " + brand);
    }
    virtual void build_body()override{
        p->add("bulid the all body");
    }
    virtual void insert_wheels(){
        p->add("insert the wheels");
    }
    virtual void add_head_lights()override {
        p->add("add the head light");
    }
    virtual void end_operations()override {
        p->add("end operations");
    }
    virtual product  * get_car_object() override {
        return p;
    }
 
}; 

class director {
private:
    ibuilder * ib;
public:
       director(ibuilder * b) :ib(b)  {
        ib->set_up_operations();
        ib->build_body();
        ib->insert_wheels();
        ib->add_head_lights();
        ib->end_operations();
    }
};



int main()
{
 	 ibuilder * car_builder = new car("ferrari");
     director b(car_builder);
     product  * car_product = car_builder->get_car_object();
     car_product->show();
     
}
