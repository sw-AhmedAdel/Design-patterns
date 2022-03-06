#include <iostream>
using namespace std;

class machine {
public:
    virtual void display() const =0;
};
class coffe : public machine {
public:
    virtual void display() const override {
        cout<<"order my coffe"<<endl;
    }
};
class espresso : public machine {
    virtual void display() const override {
        cout<<"order my espresso"<<endl;
    }
};
class moka :  public machine {
public:
    virtual void display() const override {
        cout<<"order my moka"<<endl;
    }
};

class orders {
public:
    void make_the_order(machine * m) {
    m->display();
    }
     
};

int main()
{
     int  ord_num;
     orders ord;
      machine * c= new coffe;
      machine * e=new espresso;
      machine * m = new moka;
	 do {
         cout<<"1- coffe"<<endl;
         cout<<"2- espresso"<<endl;
         cout<<"3- moka"<<endl;
         cout<<"4 exit"<<endl;
         cin >> ord_num;
         switch(ord_num) {
             case 1 :
             ord.make_the_order(c);
             break;
             case 2 :
             ord.make_the_order(e);
             break;
             case 3 :

             ord.make_the_order(m);
             break;
             case 4 :
             cout<<"exit"<<endl;
             break;
             default:
             cout<<"wrong orders"<<endl;
             cin >> ord_num;
         }
     }while(ord_num != 4);
}
