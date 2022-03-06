#include <iostream>
using namespace std;

class delegation {
public:
   //the delegation means sort of actions doing together
   //group of people has opninon
    void display () {
        cout<<"represent the problems "<<endl;
    }
};

class delegate {
public:
   // this is delegate just one person will say this opnion 
    delegation d;
    void display()  {
        d.display();
    }
};
int main()
{
	delegate d;
    d.display();
}
