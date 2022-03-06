#include <iostream>
#include <string>
using namespace std;

class employee{
public:
    string name;
    int salary;
};
class cal {
public:
    virtual int cal_salary(employee e) {
        return e.salary * 2;
    }
};
class manager {
public:
    int salary;
};

class adapter_salary : public cal {
private :
    manger m;
    cal c;
public:
    adapter_salary (manger mm) : m{m} {} 
    virtual int cal_salary(employee emp) {
        emp.salary = m.salary;
        return c.cal_salary(emp);
    }
    
};
int main()
{
	  manager m;
      m.salary=1000;
      adapter_salary s(m);
      employee e;
      cout<<s.cal_salary(e)<<endl;
     
}
