#include <iostream>
using namespace std;

class Airport;

class ATC {//mediator 
protected:
    Airport *f;
    Airport *r;
    bool avalible;
public:
    
  virtual void setAilabilityRunwayStauts(bool status)=0;
  virtual bool is_avilable()=0;
};

class Air_Traffic_Controller : public ATC {
public:
 
  virtual void setAilabilityRunwayStauts(bool status){
      avalible=status;
  }
  virtual bool is_avilable() {
      if(avalible==true)
          return true;
          else 
              return false;
  }
};

class Airport {
protected:
    ATC * controller;

public:
    Airport(ATC *a) : controller{a} {}
    virtual void land()=0;
};

class runWay: public Airport { 
public:
    runWay(ATC*a):Airport{a} {}
    virtual void land() {
       cout<<"run way is avilable for landind"<<endl;
       controller->setAilabilityRunwayStauts(true);
    }
};


class Flight: public Airport { 
    string name;
public:
    Flight(ATC*a):Airport{a} {}
    virtual void land() {
        if(controller->is_avilable() == true) {
            cout<<name <<" landind right now,"<<endl;
            cout<<"ATC is going to send message that the runway is not avilable"<<endl;
            controller->setAilabilityRunwayStauts(false);
        }else 
            cout<<name<<" there is fligt is landing, waiting for runway"<<endl;
                
    }
    void readytoland() {
        cout<<name<< "  initiated landing"<<endl;
    }
    void parked(){
        cout<<"flight is parked runway is avilable for another flight"<<endl;
        controller->setAilabilityRunwayStauts(true);
    }
    void set_name(string name) {
        this->name=name;
    }
    string flightname(){
        return name;
    }
};

int main()
{
    ATC * controller=new Air_Traffic_Controller;
    runWay r(controller);
    Flight f1(controller);
    Flight f2(controller);
    f1.set_name("flight252");
    f2.set_name("flight356");
    Flight f3(controller);
    f3.set_name("flight 250");
 
    f1.readytoland();
    f2.readytoland();
    f3.readytoland();
    cout<<"___________"<<endl;
    r.land();
    f1.land();
    f2.land();
    f1.parked();
    f2.land();
    f3.land();
    f2.parked();
    f3.land();
    
     
     
}
