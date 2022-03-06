#include <iostream>
using namespace std;

class food{
public:
    virtual string typefood()=0;
};

class fruits : public food {
public:
    virtual string typefood(){
        return "fruits";
    }
};

class meat: public food{
public:
    virtual string typefood(){
        return "meat";
    }
};

class larvae : public food{
public:
    virtual string typefood(){
        return "larvae ";
    }
};


class animal {
protected:
    food * f;
public:
    animal(food* ff) : f{ff} {}
    virtual void eat()=0;
};

class tiger:public animal {
public:
    tiger(food *ff):animal{ff} {}
    virtual void eat(){
        cout<<"tiger eats " <<f->typefood()<<endl;
    }
};
class monkey:public animal {
public:
    monkey(food *ff):animal{ff} {}
    virtual void eat(){
        cout<< "monkey eats "<<f->typefood()<<endl;
    }
};

class fish:public animal {
public:
    fish(food *ff):animal{ff} {}
    virtual void eat(){
        cout<<"fish eats "<<f->typefood()<<endl;
    }
};


int main(){
    food * m=new meat;
    animal * t=new tiger(m);
    t->eat();
    cout<<"_______________"<<endl;
    food * f=new fruits;
    animal* mon = new monkey(f);
    mon->eat();
    cout<<"____________"<<endl;
    food * l =new larvae;
    animal * fi=new fish(l);
    fi->eat();
}
 