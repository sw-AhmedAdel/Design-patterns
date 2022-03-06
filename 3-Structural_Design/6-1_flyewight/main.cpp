 
#include <map>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//hint this is using factory with flywight
// flyiwight it means the object u want to create takes a lot of time to be created and u will use this object with the same data
//for many time like there is discount for 5% and u will use this discount for the entier day so insetd of for example print paper 
//that has the discount for each cusomter by this will be very cost u just print it once and it will be ready even it any custmer get
class main_bank {
protected:
    int balance;
public:
    main_bank(int b): balance{b} {}
    virtual void deposit(int amount)=0;
    virtual void withfrwaw(int amount)=0;
    virtual int  get_balance()=0;
};

class cairoBank  : public main_bank {
public:
    cairoBank(int b): main_bank{b} {}
    virtual void deposit(int amount) {
        balance+=amount;
    }
    virtual void withfrwaw(int amount){
        balance-=amount;
    }
        virtual int  get_balance(){
            return balance;
        }

};
class masrBank :public main_bank  {
public:
    masrBank(int b): main_bank{b} {}
    virtual void deposit(int amount){
        balance+=amount;
    }
    virtual void withfrwaw(int amount){
                balance-=amount;
    }
    virtual int  get_balance(){
            return balance;
        }
};

class ifactory {
protected:
    main_bank * b;
public:
    virtual main_bank * get_bank(int code)=0;
};

class implementfactory:public ifactory {
private:
    map<int,main_bank*> obj;
public:
    virtual main_bank * get_bank(int code){
        auto it =obj.find(code);
        if(it!= obj.end()) {
           cout<<"used in find "<<endl;
            return  it->second;
        }
        else {
        switch(code) {
            case 1:
            b=new cairoBank(600);
            obj.insert(pair<int , main_bank*>(code,b));
            cout<<"used"<<endl;
            break;
            case 2:
            b= new masrBank(600);
            obj.insert(pair<int , main_bank*>(code,b));
            break;
            default:
            return  b= nullptr;
            break;
        }
    return b;
     }
    }
};

int main(){
 
    int code;
    implementfactory i;
    main_bank * b;
    cout<<"enter the code"<<endl;
    cin >> code;
    b=i.get_bank(code);
    if(b!=nullptr) {
    b->withfrwaw(200);
    cout<<b->get_balance()<<endl;
    }else 
    cout<<"error"<<endl;
    cout<<"enter the code"<<endl;
    cin >> code;
    b=i.get_bank(code);
    if(b!=nullptr) {
    b->withfrwaw(200);
    cout<<b->get_balance()<<endl;
    }else 
        cout<<"error"<<endl;
  
  
}
//programme should not inpend on how the object create 
//هنا انا مهما عدلت  عمرى ما هعدل فى الكلاينت اللى هو المين فا اقدر اضيف اى بنوك تانى وهيشتغل عادى جدا بسهولة ويسر
//المشكلة ان فى الكلاينت هعمل تغيرات كل ما ازود اى كلاس فا المشكلة اتحلت لما الكلاينت الكود ثابت مبيتغيرش 
//وكل ما اضيف بنك  المسؤل عن  الاوبجيكت بتاعة هو الفاكتورى
 