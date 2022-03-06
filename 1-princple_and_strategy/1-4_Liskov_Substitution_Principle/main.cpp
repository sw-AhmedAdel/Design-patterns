#include <iostream>
#include <string>
using namespace std;

/*#include <iostream>
#include <string>
using namespace std;
 * 
/*class database {
public:
    void normal_post(string post) {
        cout<<"original post"<<" "<<post<<endl;
    }
      void tagepost(string post) {
        cout<<"tage post  "<<" "<<post<<endl;
    }
    
    void men_post(string post) {
        cout<<"menshion post  "<<" "<<post<<endl;
    }
};

class posts {
public:
    virtual void create_post(database db , string post) const   =0;
    virtual ~posts() =default;
}; 
 
class normal : public posts {
public:
    virtual void create_post(database db , string post) const override {
        db.normal_post(post);
    }
    virtual ~normal() =default;
}; 
class tage :public posts  {
public:
    virtual void create_post(database db , string post)const override{
        db.tagepost(post);
    }
    virtual ~tage() =default;
}; 
class menshion :public posts  {
public:
    virtual void create_post(database db , string post) const override{
        db.men_post(post);
    }
    virtual ~menshion() =default;
}; 
int main()
{
   database d;
   list<string> listpost;
   listpost.emplace_back("originalpost");
   listpost.emplace_back("#post");
   listpost.emplace_back("@post");
      posts * p ;
   for(auto pos : listpost) {
       if(pos[0] =='#')
           p=new tage;
           else if(pos[0]=='@')
               p= new menshion;
               else 
                   p=new normal;
     p->create_post(d,pos);
   }
   
   
  
}*/
class machine {
public:
    virtual void display() const =0;
};
class coffe : public machine {
public:
    virtual void display() const override {
        cout<<"order my coffe"<<endl;
    }
};
class espresso : public machine {
    virtual void display() const override {
        cout<<"order my espresso"<<endl;
    }
};
class moka :  public machine {
public:
    virtual void display() const override {
        cout<<"order my moka"<<endl;
    }
};

class orders {
public:
    void make_the_order(machine * m) {
     
     m->display();
    }
     
};

int main()
{
      int  ord_num;
      orders ord;
      machine * p;
   
	 do {
         cout<<"1- coffe"<<endl;
         cout<<"2- espresso"<<endl;
         cout<<"3- moka"<<endl;
         cout<<"4 exit"<<endl;
         cin >> ord_num;
         switch(ord_num) {
             case 1 :
             p=new coffe;
             ord.make_the_order(p);
             break;
             case 2 :
             p = new espresso;
             ord.make_the_order(p);
             break;
             case 3 :
             p = new moka;
             ord.make_the_order(p);
             break;
             case 4 :
             cout<<"exit"<<endl;
             break;
             default:
             cout<<"wrong orders"<<endl;
             cin >> ord_num;
         }
     }while(ord_num != 4);
}
*/
class vehicle {
   friend ostream&operator<<(ostream & os ,    vehicle & v)  {
      v.print(os);
      return os;
  }
protected:
  string name;
  int price;
public:
  vehicle(string name , int price) : name{name} , price{price} {}
  virtual void print(ostream & os) =0;
     
   
   virtual ~vehicle()=default;
  
};

 class cars :public vehicle {
public:
    cars(string name , int price): vehicle{name,price} {}
    virtual void print(ostream & os) {
        os<<name<<":"<<price<<endl;
    }
    virtual ~cars()=default;

};

 class plane :public vehicle {
public:
   plane  (string name , int price): vehicle{name,price} {}
    virtual void print(ostream & os) {
        os<<name<<":"<<price<<endl;
    }
    virtual ~plane()=default;

};
int main()
{
    vehicle * v=new cars("lambrgeni urs" , 50000);
    cout<<*v<<endl;
    v=new plane("ghost_1",25000);
    cout<<*v<<endl;
}

