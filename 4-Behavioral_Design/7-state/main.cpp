#include <iostream>
using namespace std;

//state means, based on what do u want the state will happen 
//state the mobile is ringing when u asks for silent u change the state of ur phone so the new state will be silent

class mobileAlert{
public:
    virtual void alert()=0;
};

class ringing : public mobileAlert {
public:
    virtual void alert() {
        cout<<"mobile is in ringing state"<<endl;
    }
};
class silent : public mobileAlert {
public:
    virtual void alert() {
        cout<<"mobile is in silet state"<<endl;
    }
};

class vibiration : public mobileAlert {
public:
    virtual void alert() {
        cout<<"mobile is in vibiration state"<<endl;
    }
};


class alertNotification  {
private:
    mobileAlert* mobile;
public:
    alertNotification() {
        mobile=new ringing;
    }
    void setsound(mobileAlert * m) {
        mobile=m;
    }
    
    void notify(){
        mobile->alert();
    }
};

int main()
{
	 alertNotification a;
     a.notify();
     cout<<"__________"<<endl;
     mobileAlert * mobile =new silent;
     a.setsound(mobile);
     a.notify();
     cout<<"_______________"<<endl;
     mobile=new vibiration;
     a.setsound(mobile);
     a.notify();
}
