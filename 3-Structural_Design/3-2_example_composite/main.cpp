#include <iostream>
#include <string>
#include <vector>
using namespace std;

class faculty {// component
public:
    virtual void display_details()=0;
    virtual void print()=0;
};

class professors : public faculty { // leaf
private:
    string name; 
    int id;
public:
    professors(string n , int i):name{n},id{i}{}
    virtual void display_details(){
        cout<<name<<":"<<id<<endl;
    }
        virtual void print() {
            cout<<name<<":"<<id<<endl;
        }
};

class supervisor : public faculty {//composite between  faculty and professors in tha same file or class
private:
    vector<faculty *> vec;
    string name; 
    int id;
public:
    supervisor(string n , int i):name{n},id{i}{}
    virtual void display_details(){
         for(auto * v: vec)
             v->display_details();
    }
    void add(faculty *f) {
        vec.push_back(f);
    }
    void get_supervisor_details(){
        cout<<name<<":"<<id<<endl;
    }
       virtual void print() {
            cout<<name<<":"<<id<<endl;
        }
};
int main()
{
   faculty* teachology_dean  = new supervisor ("dr mick is dean of techology  ", 5);
   faculty *chair_of_math = new supervisor("  dr jon chair of math ",2);
   faculty *chair_of_computer = new supervisor(" dr ian  chair ofcomputer " ,20);
   faculty * math1=new professors("math professor1 " , 20);
   faculty * math2=new professors("math professor2 " , 20);
   faculty * comp1=new professors("computer1 professor1 " , 20);
   faculty * comp2=new professors("computer2 professor2 " , 20);
   teachology_dean->print();
   teachology_dean->add(chair_of_computer);
   teachology_dean->add(chair_of_math);
   teachology_dean->display_details();
 
   
   

}
