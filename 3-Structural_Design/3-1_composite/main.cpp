#include <iostream>
#include <vector>
using namespace std;
// بمعنى فولدر جواة 3  ملفات اول وتانى ملف مفهمش حاجة  اما تالت ملف لما افتحة بيكون جواة حجتين
//هنا فى 3 ملفات المدير والمطور و الجمع ..ملف المدير فاضي وملف المطور فاضى اما الجمع لو فتحتة  هلاقي فية مدير ومطور
//الملخص ان فية كذا ملف او كذا كلاس هما الاتنين هيشتغلوا بنفس الطريقة زي العرض والادخال
//بمعنى ان الكمبوزيت بيجمع بين كذا كلاس استحدامهم واحد
class employee {//component بمعنى ان دي العنصر
public:
    virtual void display_employee_info()=0;
};

class develpoer : public employee {//leaf بمعنى انة مش هيحتوى على حاجة ه
private:
    string name;
    int id;
public:
    develpoer(string n , int i) : name{n} ,id{i} {}
    virtual void display_employee_info() {
        cout<<"name is "<<name<<": id is "<<id<<endl;
    }
};
class manger : public employee {//leaf بمعنى انة مش هيحتوى على حاجة ه
private:
    string name;
    int id;
public:
    manger(string n , int i) : name{n} ,id{i} {}
    virtual void display_employee_info() {
        cout<<"name is "<<name<<": id is "<<id<<endl;
    }
};

class directer: public employee {// composite will has the 2 leaf and treat them at the same way
      vector<employee* > vec;
public:
      void add(employee * e) {
          vec.push_back(e);
      }
      void pop(){
          vec.pop_back();
      }
         virtual void display_employee_info() {
          for(auto * v : vec)
              v->display_employee_info();
              //هنا الفانكشن دي هتلف على كل الاوبجيكت وتعرض ليا النتيجة لكل واحد 
      }
};
                                          /// here the component is employee
                              ////the leaf is manger and dec                //the cmposite is hrer 
                                                                     //left is manger obj    right is dev obj
int main()
{
   employee * dev1=new develpoer("sue",5);
   employee * dev2=new develpoer("leo", 10);
    
   directer d1;
   d1.add(dev1);
   d1.add(dev2);
   
   employee * m1=new manger("meo",20);
   employee *m2=new manger("sam",30);
   directer d2;
   d2.add(m1);
   d2.add(m2);
   
   directer d3;
   cout<<&d3<<endl;
   d3.add(&d1);// & coz vecore gets address why coz it using pointers so send the address of the d3 object
   d3.add(&d2);
   d3.display_employee_info();
   d3.pop();
   cout<<"_______"<<endl;
   d3.display_employee_info();
 }
