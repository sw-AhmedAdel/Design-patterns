#include <iostream>
#include <string>
using namespace std;

 class  animal {
public:
     virtual void talk()const  =0;
     virtual ~ animal()=default;
     virtual string eat ()const   =0;
     
 };

 class tiger : public animal {
     virtual void talk()const override {
         cout<<"tiger says haum haum"<<endl;
     }
     virtual  string eat ()const override {
         return "buffalo";
     }
     virtual ~ tiger()=default;
 };

class duck : public animal {
     virtual void talk()const override {
         cout<<"duck says pack pack"<<endl;
     }
     virtual string eat ()const override {
         return "weed";
     }
     virtual ~ duck()=default;
 };
 
 class animal_factory {
protected:
     animal *a;
     animal * get_animal(string animaltype);
 };
 
  class animal_factory_concrete : public animal_factory{
    public:
    animal * get_animal(string animaltype) {
        if(animaltype=="tiger")
           return a=new tiger;
            else if(animaltype=="duck")
              return a=new duck;
                  else 
                       return NULL;  
    }
 };
 
 
int main()
{
   string animaltype;
   cout<<"enter the animaltype"<<endl;
   cin >> animaltype;
   animal_factory_concrete f;
   animal *a;
   a=f.get_animal(animaltype);
   a->talk();
   cout<<a->eat()<<endl;
}
