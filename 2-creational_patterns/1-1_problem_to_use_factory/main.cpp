#include <iostream>
using namespace std;

class bank1 {
public:
    void get_bank() {
        cout<<"deal with bank 1"<<endl;
    }
};
class bank2 {
public:
    void get_bank() {
        cout<<"deal with bank 2"<<endl;
    }
};

// if i want to add another bank i will go to the main which means as a client and create another abject for the new class bank
//but using factory allows me not use the main which is cleint to get any object and use factory to generates the object
int main()
{
	 bank1 b1;
     bank2 b2;
     int code;
     cout<<"enter the code"<<endl;
     cin>> code ;
     switch(code) {
         case 122:
         b1.get_bank();
         break;
         case 123:
         b2.get_bank();
         break;
         default:
         cout<<"wrong"<<endl;
     }
}
