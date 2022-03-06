#include <iostream>
#include <map>
using namespace std;
// use proxy like u are in resturant and u can not see the kitchen so u make an order but u will deal with the waiter he
// will take ur order and deal with the kintchen so the waiter is the proxy
// and if u go to any place u will go inside it from the door so the proxy is the door
//her example u as a client do not deal with the concrete class no there is proxy between u and the dirct class and this proxe emplemnt 
//so instructions to allow u use this class
// بمعنى هو عملية مراقبة لى الكلاينت هيستخدم كام مرة الكلاس فا هو المتحكم فعلا بعملية الارسال والمراقبة
class sms{
public:
    virtual void sendMessage(int phone_num_1, int phone_num_2 ,string msg)=0;
};

class smsService : public sms {
public:
    virtual void sendMessage(int phone_num_1, int phone_num_2 ,string msg) {
        cout<<"message has been sent"<<endl;
    }
};
class ProxySms: public sms {//لو محتاج ان البروكسى يورث من كلاس الاس ام اس سيرفس  لى اى سبب يبقى هخلية يورث من الاب
private:
    sms *s=NULL;
    int counter=1;
    map<int , int >mapes;
public:
    virtual void sendMessage(int phone_num_1, int phone_num_2 ,string msg) {
        if(s==NULL) {
            s=new smsService;
            mapes.insert(make_pair(phone_num_1,counter));
            s->sendMessage(phone_num_1,phone_num_2,msg);
        }
        else {
            if(mapes[phone_num_1] <5) {
            mapes[phone_num_1]++;
            s->sendMessage(phone_num_1,phone_num_2,msg);
            }else {
                cout<<"u have been exceeded your messages"<<endl;
            }
        }
    }

};

int main()
{
	 sms *s=new ProxySms;
     s->sendMessage(1,1,"hi");
     s->sendMessage(1,1,"hi");
     s->sendMessage(1,1,"hi");
     s->sendMessage(1,1,"hi");
     s->sendMessage(1,1,"hi");
     s->sendMessage(1,1,"hi");
     s->sendMessage(1,1,"hi");
     s->sendMessage(1,1,"hi");
}
