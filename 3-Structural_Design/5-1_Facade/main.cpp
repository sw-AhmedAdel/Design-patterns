#include <iostream>
#include <vector>
using namespace std;
//it means using i that for expamle i am calling the customer service to check some product in the stock
// and make the payment and make the order to me so this customer care is just facade class it does all this process
//for me insted i am doing all of that by myself no i have class and if i want to make order just call it
class Manue{
public:
    virtual void showManue()=0;
};

class Macdonald : public Manue{
    virtual void showManue()=0;
};

class MacdonaldBeef : public Macdonald{
private:
    vector<string>items ={"Big Tasty","Big Mac","McRoyale","Grand Share Box","Double Big Tasty"};
public:
MacdonaldBeef() {
    cout<<"creating Macdonald Beef manue"<<endl;
}
    virtual void showManue(){
        for(auto i: items)
            cout<<i<<" ";
        cout<<endl;
    }
};

class MacdonalChicken : public Macdonald{
private:
    vector<string>items ={"Chicken Mac","McNuggets® 6 Pieces","Spicy Chicken Fillet","Grand Chicken Spicy","Chicken MACDO® Deluxe"};
public:
MacdonalChicken() {
    cout<<"creating Macdonal Chicken manue"<<endl;
}
    virtual void showManue(){
        for(auto i: items)
            cout<<i<<" ";
        cout<<endl;
    }
};
 

class burgerking : public Manue{
    virtual void showManue()=0;
};

class burgerkingBeef : public burgerking{
private:
    vector<string>items ={"Double Bacon Sourdough Breakfast King","Bacon, Egg, & Cheese Biscuit","Sausage Biscuit "};
public:
burgerkingBeef() {
    cout<<"creating burgerking Beef manue"<<endl;
}
    virtual void showManue(){
        for(auto i: items)
            cout<<i<<" ";
        cout<<endl;
    }
};

class burgerkingChicken : public burgerking{
private:
    vector<string>items ={"Original Chicken Sandwich","Crispy Chicken Sandwich","BLT Chicken Jr. "};
public:
burgerkingChicken() {
    cout<<"creating burgerking Chicken manue"<<endl;
}
    virtual void showManue(){
        for(auto i: items)
            cout<<i<<" ";
        cout<<endl;
    }
};
/*class facade {
private:
 Manue *  MacdonalC ,* MacdonaldB, *burgerkingC, * burgerkingB;
public:
 facade(Manue * Macdonalc,  Manue * Macdonaldb ,  Manue * burgerkingc , Manue *  burgerkingb)
 :MacdonalC{Macdonalc},MacdonaldB{Macdonaldb},burgerkingC{burgerkingc},burgerkingB{burgerkingb}{}
 virtual void print_manues() {
     MacdonalC->showManue();
     cout<<"___________"<<endl;
     MacdonaldB->showManue();
     cout<<"___________"<<endl;
     burgerkingC->showManue();
     cout<<"___________"<<endl;
     burgerkingB->showManue();
 }
};
int main()
{ 
    Manue *s1=new MacdonalChicken;
    Manue *s2=new MacdonaldBeef;
    Manue* s3=new burgerkingChicken;
    Manue*s4=new burgerkingBeef;
    facade f(s1,s2,s3,s4);
    f.print_manues();
}*/
class Hotel {
public:
    virtual Manue * get_manues()=0;
};

  class MacBeef: public Hotel {
public:
    virtual Manue * get_manues() {
        Manue * mac=new MacdonaldBeef;
        return mac;
    }
};

class Macchicken : public Hotel {
public:
    virtual Manue * get_manues() {
        Manue * mac=new MacdonalChicken;
        return mac;
    }
};
class burgerbeef : public Hotel {
public:
    virtual Manue * get_manues() {
        Manue * mac=new burgerkingBeef;
        return mac;
    }
};
class burgechicken : public Hotel {
public:
    virtual Manue * get_manues() {
        Manue * mac=new burgerkingChicken;
        return mac;
    }
};

class facade{
private:
    Hotel * mb1,* mc1, *bb1, *bc1 ;
public:
    facade(Hotel *mb,Hotel *mc,Hotel *bb,Hotel *bc) :
    mb1{mb},mc1{mc},bb1{bb},bc1{bc} {}
    Manue * get_MacdonaldBeef(){
      return  mb1->get_manues();
    }
    Manue * get_MacdonalChicken (){
      return  mc1->get_manues();
    }
    Manue *  get_burgerkingBeef(){
      return  bb1->get_manues();
    }
    Manue * get_burgerkingChicken (){
      return  bc1->get_manues();
    }
    
};

int main(){
    
    Hotel *s1=new MacBeef;
    Hotel *s2=new Macchicken;
    Hotel *s3=new burgerbeef;
    Hotel *s4=new burgechicken;
    facade f(s1,s2,s3,s4);
    Manue * macc=f.get_burgerkingChicken();
    macc->showManue();
    cout<<"______________"<<endl;
    macc=f.get_burgerkingBeef();
    macc->showManue();
    
}
/*
class facade{
private:
    Hotel * mb1,* mc1, *bb1, *bc1 ;
    Manue *b;
public:
    facade(Hotel *mb,Hotel *mc,Hotel *bb,Hotel *bc) :
    mb1{mb},mc1{mc},bb1{bb},bc1{bc} {}
    void print() {
      b=  mb1->get_manues();
      b->showManue();
      b=  mc1->get_manues();
     b->showManue();
      b=  bb1->get_manues();
     b->showManue();
      b=  bc1->get_manues();
     b->showManue();
}
    
};

int main(){
    
    Hotel *s1=new MacBeef;
    Hotel *s2=new Macchicken;
    Hotel *s3=new burgerbeef;
    Hotel *s4=new burgechicken;
    facade f(s1,s2,s3,s4);
    f.print();
 */