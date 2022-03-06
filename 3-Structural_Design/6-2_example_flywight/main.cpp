#include <iostream>
#include <string>
#include <map>
using namespace std;
class Robot {
public:
    virtual void print()=0;
};

class SmallRobot : public Robot {
public:
    virtual void print () {
        cout<<"SmallRobot"<<endl;
    }
};


class LargeRobot : public Robot {
public:
    virtual void print() {
        cout<<"SmallRobot"<<endl;
    }
};

class RobotFactory {
private:
    Robot *r;
    map<string ,Robot *> mapes;
public:
    Robot * get_robot(string n) {
        auto it=mapes.find(n);
        if(it!= mapes.end()) {
            return it->second;
        }
             else {
                 if(n=="small") {
                     r=new SmallRobot;
                     mapes.insert(make_pair(n,r));
                     cout<<"small robot has been created and stored in map"<<endl;
                     cout<<endl;
                 }else if(n=="large" ){
                     r= new LargeRobot;
                     mapes.insert(make_pair(n,r));
                    cout<<"large robot has been created and stored in map"<<endl;
                 }else 
                     return NULL;
             }
             return r;
    }
};


int main()
{
	 RobotFactory  f;
     Robot *r;
     for(int i=0 ; i<3 ; i++) {
         r= f.get_robot("small");
         r->print();
     }
}
