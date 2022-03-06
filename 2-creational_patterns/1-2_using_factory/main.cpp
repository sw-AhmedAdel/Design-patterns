#include <iostream>
using namespace std;

 #include <iostream>
#include <string>
#include <vector>
using namespace std;
 

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
    public:
    virtual main_bank * get_bank(int code){
        switch(code) {
            case 1:
            return  b=new cairoBank(500);
            break;
            case 2:
            return b= new masrBank(500);
            break;
            default:
            return  b= nullptr;
            break;
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
    b->withfrwaw(250);
    cout<<b->get_balance()<<endl;
    }else 
        cout<<"error"<<endl;
  
}
//programme should not inpend on how the object create 
//هنا انا مهما عدلت  عمرى ما هعدل فى الكلاينت اللى هو المين فا اقدر اضيف اى بنوك تانى وهيشتغل عادى جدا بسهولة ويسر
//المشكلة ان فى الكلاينت هعمل تغيرات كل ما ازود اى كلاس فا المشكلة اتحلت لما الكلاينت الكود ثابت مبيتغيرش 
//وكل ما اضيف بنك  المسؤل عن  الاوبجيكت بتاعة هو الفاكتورى
 