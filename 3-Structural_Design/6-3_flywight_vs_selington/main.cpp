#include <iostream>
#include <map>
using namespace std;

// in sleington i can use one object abd make change in this object
//in flywight it is diff i can get the same object and can not change it coz i will use the same info many time
// and i can have same class but get 2 diff kind of obj depends on the key value in map

class RopotInterface {
public:
    virtual void print()=0;
    virtual void set_color(string s)=0;
};

class Robot : public RopotInterface {
private:
    string ropottype;
    string color;
public: 
   Robot(string s) :ropottype{s} {}
    virtual void set_color(string s) {
        color =s;
    }
    virtual void print() {
        cout<<"this is type of robot "<<ropottype<<":"<<"this is color "<<color<<endl;
    }
};

class RobotFactory {
private:
  RopotInterface *r;
  map<string , RopotInterface *> mapes;
public:
     RopotInterface* get_robot(string n) {
         auto it= mapes.find(n);
         if(it!= mapes.end()) {
             return it->second;             
         } 
             else {
                 if(n =="king") {
                     cout<<"creating new king robot"<<endl;
                     r=new Robot("king");
                     mapes.insert(make_pair(n,r));
                     cout<<endl;
                 }
                     else if(n=="queen") {
                     cout<<"creating new queen robot"<<endl;
                     r=new Robot("queen");
                     mapes.insert(make_pair(n,r));
                     cout<<endl;
                     }
                     else 
                         return NULL;
                 }
                 return r;
             }
};

int main()
{ 
    RobotFactory f;
    RopotInterface * r;
    for(int i=0 ; i<3 ;i++) {
        r=f.get_robot("king");
        r->set_color("red");
        r->print();
    }
    RopotInterface * rr;
    rr=f.get_robot("king");
    rr->set_color("red");
    rr->print();
    cout<<endl;
    
    for(int i=0 ; i<3 ;i++) {
        r=f.get_robot("queen");
        r->set_color("blue");
        r->print();
    }
}
