#include <iostream>
using namespace std;

class duck {
public:
    virtual void quack()=0;
    virtual void fly_duck()=0;
};

class mallardhuck : public duck {
    virtual void quack(){
        cout<<"duck quack"<<endl;
    }
    virtual void fly_duck(){
        cout<<"duck i am flying"<<endl;
    }
};

class turkey {

public:
    virtual void gobble()=0;
    virtual void fly_turkey()=0;
};

class wildturkey : public turkey {
public:
    virtual void gobble(){
        cout<<"wildturkey gobble gobble"<<endl;
    }
    virtual void fly_turkey(){
        cout<<"wildturkey i am flying short distance"<<endl;
    }
};
//want to adabt trukey to duck means want to let the turkey act like the duck 
class turkey_adapter :public duck {
    //make the turkey act like the duck
    turkey * turk;
public:
    turkey_adapter(turkey * t):turk{t} {}
    virtual void quack() {
        turk->gobble();
    }
    virtual void fly_duck(){
        turk->fly_turkey();
    }
};

int main()
{
	 turkey *t = new wildturkey;
     duck *d= new mallardhuck;
     cout<<"trukey says >> "<<endl;
     t->gobble();
     t->fly_turkey();
     cout<<"duck says >> "<<endl;
     d->quack();
     d->fly_duck();
     cout<<"_______________"<<endl;
     cout<<"the turkey adapter says "<<endl;
     duck * t_adabter =new turkey_adapter(t);
     t_adabter->quack();
     t_adabter->fly_duck();
     
}
