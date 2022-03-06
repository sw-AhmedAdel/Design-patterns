#include <iostream>
#include <string>
using namespace std;

// using interface to seperate the projects and do not forced user does something not related to his needs
// so interface using by making the all functions pure by make it = 0
// virtual makes the child class inhertes the function from the parent and use it with anotuer contaents 

#include <iostream>
using namespace  std;

 
class coffee  {
public:
      virtual void drinks_coffe() =0;
};
 
class espresso  {
      public:
      virtual void drinks_espresso() =0;
};

 

class mulk_1  {
      public:
      virtual void spon_mulks_1()=0;
};
class mulk_2 {
      public:
      virtual void spons_mulks_2()=0;
};
 

class sugar_1 {
public:
    virtual void spons_sugar_1()=0;
};

class sugar_2{
public:
    virtual void spons_sugar_2()=0;
};

class espresso_2_sugar_2_mulik : public espresso , public sugar_2 , public mulk_2 {
    public:
           virtual void drinks_espresso(){
               cout<<"order espresso"<<endl;
           }
            virtual void spons_mulks_2(){
                     cout<<"add 2 spons mulk"<<endl;
                 }
               virtual void spons_sugar_2(){
                   cout<<"add 2 spns sugar"<<endl;
               }

};


class coffee_2_sugars: public coffee , public sugar_2  {
    public:
           virtual void drinks_coffe(){
               cout<<"order espresso"<<endl;
           }
               virtual void spons_sugar_2(){
                   cout<<"add 2 spns sugar"<<endl;
               }

};
 
int main(){
  espresso_2_sugar_2_mulik e;
  e.drinks_espresso();
  e.spons_mulks_2();
  e.spons_sugar_2();
  cout<<"__________"<<endl;
   coffee_2_sugars c;
   c.drinks_coffe();
   c.spons_sugar_2();
  
}
//not the same content in the parent 
/*
class i_cash {
public:
    virtual void pay_cash () const =0;
};

class i_online {
public:
    virtual void pay_online () const =0;
};

class i_credit {
public:
    virtual void pay_credit() const =0;
};
///////////////////////////

class paycash : public i_cash {
public:
        virtual void pay_cash () const override {
            cout<<"pay in cash"<<endl;
        }
};


class payonline : public i_online {
public:
        virtual void pay_online () const override {
            cout<<"pay in pay online"<<endl;
        }
};


class payoncredit : public i_credit {
public:
        virtual void pay_credit () const override {
            cout<<"pay in pay credit"<<endl;
        }
};
 
class paid_in_shop :public i_cash , public i_credit {
public:
        virtual void pay_cash () const override {
            cout<<"pay in paid_in_shop"<<endl;
        }
        virtual void pay_credit () const override {
            cout<<"pay in pay paid_in_shop"<<endl;
        }
};

int main(){
    paid_in_shop p;
    p.pay_cash();
    p.pay_credit();
    cout<<"_____________"<<endl;
    paycash c;
    c.pay_cash();
}

   


class doucument {
    string name;
    int salary;
    public:
    doucument(string name, int salary) : name{name}, salary{salary}{};
    string get_name() {
        return name;
    }
    int get_salary() {
        return salary;
    }
};

class printer {
    public:
    void print(doucument d) {
        cout<<"________print_________"<<endl;
        cout<<d.get_name()<<":"<<d.get_salary()<<endl;
    }
};


class email {
public:
    void send_emails(doucument d) {
        cout<<"sending emals "<<d.get_name()<<":"<<d.get_salary()<<endl;
    }
};
class Iprinter : public printer ,public email  {
public:
    void fax(doucument d) {
            cout<<"________Iprinter_________"<<endl;
        cout <<"fax  "<< d.get_name()<<":"<<d.get_salary()<<endl;
    }
    void scan(doucument d) {
            cout<<"________Iprinter_________"<<endl;
        cout<<"sacn "<<d.get_name()<<":"<<d.get_salary()<<endl;
    }
    
};

int main()
{
	doucument d("ahmed", 1500000);
    printer p;
    p.print(d);
    Iprinter ip;
    ip.print(d);
    ip.fax(d);
    ip.scan(d);
    ip.send_emails(d);
}
*/