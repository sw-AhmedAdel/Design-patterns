#include <iostream>
#include <string>
#include <vector>
using namespace std;
//means if u have some class and u want to add some function to them without changing there code us visitor 
// means i have 2 classes food and fruits so i want to add some function to them but this function wiil be behave in diff way
//in each class so use visitor to do it
/* first u need to make class will have visit method that has object to the class that i want to add the function to like visit(food f)
 * and make a class to have function that include the pointer to class visitor and make food and fruits inherets it
 * so implement this function if food which is accept(visistor * v) so it receives visitor pointer and use this pointer
 * to call visit method which is takes food object so like this(*this)
 * and this v object that i used to sed food obj whill make the opertion on this food object 
 
class food;
class fruits;

 
class shoppingCartVisitor {
public:
    virtual int visit(food fo )=0;
    virtual int visit(fruits fr )=0;
 
}; 

 
class Products {
public:
  virtual int Accept(shoppingCartVisitor * visitor)=0;  
};

class food : public Products {
    string name;
    int price;
public:
    food(string n , int p):name{n},price{p} {}
    string get_name(){
        return name;
    }
    int get_price(){
        return price;
    }
        virtual int Accept(shoppingCartVisitor * visitor) {
            return visitor->visit(*this);// used * coz the object in visit functions is not by dynamic so put * to show it is 
            //like p*n=4; >> cout<<*n<<endl; to get the 4 
        }

};
class fruits : public Products {
    string name;
    int price;
public:
    fruits(string n , int p):name{n},price{p} {}
    string get_name(){
        return name;
    }
    int get_price(){
        return price;
    }
     virtual int Accept(shoppingCartVisitor * visitor) {
            return visitor->visit(*this);
        }
};

 

class visitorImplement : public shoppingCartVisitor{
public:
    virtual int visit(food fo ) {
        int cost=0;
        if(fo.get_price() > 50)
            cost= fo.get_price()+5;
            else if(fo.get_price() > 100)
                cost= fo.get_price()+10;
            else 
               cost= fo.get_price()+5;
        cout<<"food is "<<fo.get_name()<<":"<<"price is "<<cost<<endl;
        return cost;
    }
    
    virtual int visit(fruits fr ){
        int cost=0;
        if(fr.get_price() > 10)
            cost= fr.get_price()+2;
            else if(fr.get_price() > 20)
                cost= fr.get_price()+4;
            else 
               cost= fr.get_price()+5;
        cout<<"fruit is "<<fr.get_name()<<":"<<"price is "<<cost<<endl;
        return cost;
    }
};
 
int main()
{
	 fruits f1("banana",15);
     fruits f2("orange",20);
     fruits f3("apple",18);
     food f4("pizza",30);
     food f5("burgerking",150);
     vector<Products *> items;
     items.push_back(&f1);
     items.push_back(&f2);
     items.push_back(&f3);
     items.push_back(&f4);
     items.push_back(&f5);
     shoppingCartVisitor *v=new visitorImplement;
     int sum=0;
     for(auto *s: items) {
         sum+=s->Accept(v);
     }
     cout<<"total is "<<sum<<endl;
     
     
     
}
