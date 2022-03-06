#include <iostream>
using namespace std;
class color {
public:
  virtual void fillwithcolor(int border )=0;
};

class red  : public color {
public:
  virtual void fillwithcolor(int border) {
      cout<<"red color with "<<border<<" innc border"<<endl;
  }
};

class green : public color {
public:
  virtual void fillwithcolor(int border){
     cout<<"green color with "<<border<<" innc border"<<endl;
  }
};


class shape {
protected:
    color * col;
    int border;
public:
    shape(color * cc , int b) : col{cc} , border{b}{}
    virtual void draw ()=0;
    virtual void modifymorder(int increment)=0;
};

class triangle : public shape {
public:
    triangle(color * cc , int b) : shape{cc , b} {}
    virtual void draw () {
        cout<<"traingle is colored with  ";
        col->fillwithcolor(border);
    }
    virtual void modifymorder( int increment) {
        cout<<"now we are changing the border in triangle"<<endl;
        border=border * increment;
        draw();
    }
};

class sqaure : public shape {
public:
    sqaure(color * cc , int b) : shape{cc , b} {}
    virtual void draw () {
        cout<<"sqaure is colored with  ";
        col->fillwithcolor(border);
    }
    virtual void modifymorder( int increment) {
        cout<<"now we are changing the border in sqaure"<<endl;
        border=border * increment;
        draw();
    }
};

int main()
{

    color *r = new red;
    shape * t=new triangle(r,20);
    t->draw();
    t->modifymorder(3);
    cout<<"________________"<<endl;
    color *g = new green;
    shape * s=new sqaure(g,10);
    s->draw();
    s->modifymorder(3);
    cout<<"________________"<<endl;
    
    
}
