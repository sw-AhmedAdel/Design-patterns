#include <iostream>
using namespace std;
/* 
 * المبدا دا عبارة عن عندى كلاس هيورث الفانكشن بتاعتة لى كل كلاس انا عايز استخدمة 
 * زي كلاس اسمة الاشكال وهستخدم فانكشن حساب المساحة فى كلاس  مربع او مثلث او دايرة
 * فا هعمل كلاس  الاشكال واعمل كلاس مربع او مثلث واورث من كلاس الاشكال الفانكشن بتاعتة 
 * ولما اخلص كل الكلاسات انا عايز استخدم فانكشن واحدة تعرض كل نتايج  حساب المساحة فى المربع والمثلث 
 * بى اختصار استخدام فنكنشن تمشى مع كل الكلاسات اللى عايزة قياس المساحة
 * */
 /*//////////////////
  * 
  * 
  * 
  * #include <iostream>
using namespace  std;


class company {
protected:
    string name;
    int id;
    int salary;
public:
    company(string n , int i , int s) : name{n} , id{i} , salary{s} {}
    virtual ~ company()=default;
    void displayinfo() {
        cout<<name<<":"<<id<<":"<<salary<<endl;
    }
    virtual int get_bonus(int bonus) =0;
};

class emp : public company{
public:
    emp(string n , int i , int s) : company{n,i,s} {}
    virtual int get_bonus(int bonus) {
        return salary * bonus;
    }
    virtual ~emp()=default;

};

class manger : public company{
    int stock;
public:
    manger(string n , int i , int s , int st) : company{n,i,s}  , stock{st} {}
    virtual int get_bonus(int bonus) {
        return salary * bonus * stock;
    }
    virtual ~manger()=default;

};

class print{
public:
    void set_info(company * p) {
        p->displayinfo();
        cout<<"enter the bonus"<<endl;
        int b; cin >> b;
        cout<<p->get_bonus(b)<<endl;
    }
};
 
 
int main()
{
  company * m = new manger("ahmed", 25,2,2);
  print p;
  p.set_info(m);
  cout<<"________________"<<endl;
	 
}

  * 
  * 
  * 
  * 
  * 
  * ////////////////
 /*#include <iostream>
#include <string>
using namespace std;

class cars {
protected:
    string name;
    string color;
    int speed;
    public:
    cars(string name ,string color , int speed ) :name{name},color{color}, speed{speed}{}
    virtual int get_cost() const =0;
};
 

class hynda :public cars {
private:
    string name;
    string color;
    int speed;
    bool save_options;
    int price=5000;
public:
    hynda(string name , string color , int speed ,bool save_options) : cars{name,color,speed} ,  save_options{save_options} {}
   virtual int get_cost() const  override {
        if(save_options == 1) {
            return price + 5000;
        }
        else 
            return   price;
    }
};

class ferrair :public cars {
private:
    string name;
    string color;
    int speed;
    bool save_options;
    bool ai_drive;
    int price =5000;

public:
ferrair(string name , string color , int speed , bool save_options , bool ai_drive ):cars{name,color , speed},
save_options{save_options} , ai_drive{ai_drive} {}
    virtual int get_cost() const  override {
       
     if(save_options == 1 && ai_drive == 1) {
             return price + 5000 +5000;
        }
        else if(save_options == 0 && ai_drive == 1)
             return price + 5000;
             else if(save_options == 1 && ai_drive == 0)
             return price + 5000;
             else 
                 return price;
    }
};
 
int main(){
 
   cars * f= new ferrair ("roma","red", 150,1,1);
   cout<< f->get_cost()<<endl;   
   f=new hynda("s1","blue",100,0);
   cout<<f->get_cost()<<endl;
}*/
class shape {
public:
    virtual int get_area()  =0;
};

class traingle :public shape  {
private:
    int width;
    int hight;
public:
    traingle(int width , int hight) : width{width} , hight{hight} {}
    virtual int get_area()     {
        return width * hight;
    }
};

class square : public shape {
private:
    int hight;
public:
    square(int h) : hight{h} {}
    virtual int get_area()     {
        return hight * hight;
    }
};

class calculate {
public:
     int get_calculate (shape  *s) {
         return   s->get_area();
     }
    
};
int main()
{
	 calculate c;
     shape * t= new traingle(5,5);
     cout<<c.get_calculate(t)<<endl;
     t= new square(20);
     cout<<c.get_calculate(t)<<endl;
}
