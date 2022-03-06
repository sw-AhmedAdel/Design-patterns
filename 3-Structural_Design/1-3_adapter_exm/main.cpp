#include <iostream>
using namespace std;
class rectangle {
public:
    int width;
    int length;
};
class triangle {
private:
    int base;
    int hight;
public:
    triangle(int b , int h) :base{b} ,hight{h} {}
    int get_base(){
        return base;
    }
    int get_hight(){
        return hight;
    }
};

class interface_cla{
public:
    virtual int get_area(rectangle r) =0;
};

class calculater : public interface_cla {
   
public:
    virtual int get_area(rectangle r){
        return r.length * r.width;
   }
};
//convert trignale to rectangel to use the method that has rectange

class calculater_adapter: public interface_cla {
    calculater c;
    triangle t;
    public:
    calculater_adapter(triangle tt) :t{tt} {}
    virtual int get_area(rectangle r) {
        r.length= t.get_base();
        r.width=  t.get_hight() * t.get_hight();
        return c.get_area(r);
    }
};
int main()
{
    triangle t(5,5);
    interface_cla * c= new calculater_adapter(t);
    rectangle r;
    cout<<c->get_area(r)<<endl;
    
}

