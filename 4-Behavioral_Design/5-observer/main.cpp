#include <iostream>
#include <string>
#include <list>
using namespace std;
 
// means there is relationship between 1 object to many objects
// like there is 4 objects there are referring to student and there is 1 object which is the course that they are connected to
// so 4 student has relation ship with the course so any update in the course the 4 struduent will be notified about that
 
 
class observer{// will be the many object
public:
    virtual void updata(string messgae)=0;
};
 


class subject { // will be the one object
public:
  virtual void subscribe(observer * obs )=0;
  virtual void unsubscribe(observer * obs )=0;
  virtual void notifySubscribers()=0;  
  virtual void set_avilable(bool avilable) =0;
    
};


class course : public subject {
    string name;
    string avilability;
    list<observer *> lists;// recored the student names put them in the list
public:
    course(string n):name{n} {}
    virtual void subscribe(observer * obs ) {
        lists.emplace_back(obs);
    }
    virtual void unsubscribe(observer * obs ){
        lists.remove(obs);
    }
    virtual void notifySubscribers(){
        for(auto *obs : lists)
            obs->updata(avilability);
    }
    
    void set_avilable(bool avilable) {
        if(avilable==true)
            avilability="avilable";
            else 
                avilability="not avilable";
     notifySubscribers();
    }
};

class student :public observer {
    string name;
public:
    student(string n):name{n} {}
    virtual void updata(string messgae) {
        cout<<name<<": has new notification " +messgae <<endl;
    }

};

int main()
{
	 observer *s1 =new student("ahmed");
     observer* s2 =new student("abdo");
	 observer *s3 = new student("omr");
	 observer* s4= new student ("adel");
     subject * java = new course("java course");
     java->subscribe(s1);
     java->subscribe(s2);
     java->subscribe(s3);
     java->subscribe(s4);
     java->set_avilable(true);
     cout<<"________________"<<endl;
     java->unsubscribe(s3);
     java->set_avilable(true);

     


}
