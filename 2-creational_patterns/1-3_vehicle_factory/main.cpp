#include <iostream>
#include <string>
using namespace std;

class vehicle{
public:
    virtual void get_design(string color)  =0;
    virtual ~vehicle()=default;
};

class car : public vehicle {
public:
    virtual void get_design(string color) {
        cout<<"color of car is "<<color<<endl;
    }
    virtual ~car()=default;
};
class truck : public vehicle {
public:
    virtual void get_design(string color) {
        cout<<"color of truck is "<<color<<endl;
    }
    virtual ~truck()=default;
};

class factory {
   public:
   vehicle * v;
    vehicle * get_vehicle(string name) {
            if(name=="car")
              return  v=new car;
                else if(name=="truck")
                 return   v=new truck;
                    else 
                        return NULL;
   }
};
int main()
{
	 vehicle * v;
     factory f;
     string name;
     string color;
     cout<<"enter the name"<<endl;
     cin >> name;
     cout<<"enter the color"<<endl;
     cin>>color;
     v=f.get_vehicle(name);
     v->get_design(color);
   
     
}
