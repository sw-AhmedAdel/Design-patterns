#include <iostream>
#include <string>
using namespace std;

//////abstract class to use many products like payment and bank so use one generateing object ////////////////

//////////////////bank ////////
class ibank {
public:
    virtual int deposit(int amount)=0;
    virtual int withdraw(int amount)=0;
    virtual  void bankname()=0;
    virtual ~ ibank()= default;
};
class cairoBank : public ibank {
public:
    virtual int deposit(int amount) {
        return amount;
    }
    virtual int withdraw(int amount) {
        return amount;
    }
        virtual  void bankname(){
            cout<<"cairo bank"<<endl;
        }

    virtual ~ cairoBank()= default;
};

class masrBank  :  public ibank{
public:
    virtual int deposit(int amount) {
        return amount;
    }
    virtual int withdraw(int amount) {
        return amount;
    }
    virtual ~ masrBank()= default;
    virtual  void bankname(){
            cout<<"masr bank"<<endl;
        }

};

////////////////ipayments ///////////////////////
class ipayments {
public:
    virtual void typePayments()=0;
    virtual ~ ipayments()=default;
};

class visa  : public ipayments {
public:
    virtual void typePayments() {
        cout<<"visa"<<endl;
    }
    virtual ~ visa()=default;
};

 class pal  : public ipayments {
public:
    virtual void typePayments() {
        cout<<"paypal"<<endl;
    }
    virtual ~ pal()=default;
};
//////abstract class to use many products like payment and bank so use one generateing object ////////////////
class i_factoryclass {
protected:
    ibank *b;
    virtual ibank * get_object(string banktype)=0;
    virtual ~ i_factoryclass()= default;
    ipayments *i;
    virtual ipayments * get_pay(int conde)=0;

};

class factoryclass  : public i_factoryclass{
 
    public:
    virtual ibank * get_object(string banktype ) {
          if (banktype =="cairo")
             return b=new cairoBank;
              else if(banktype=="masr")
                  return b=new masrBank;
                  else 
                      return NULL;
    }
    
       virtual ipayments * get_pay(int conde) {
           if (conde ==11)
             return i=new visa;
              else if(conde==22)
                  return i=new pal;
                  else 
                      return NULL;
       }

    virtual ~ factoryclass()= default;

};

 


 int main()
{
	 factoryclass f;
     ibank *b;
     b=f.get_object("masr");
     cout<<"u withdrwa "<<b->withdraw(500)<<endl;
     b->bankname();
     ipayments *i;
     i=f.get_pay(22);
     i->typePayments();
}
