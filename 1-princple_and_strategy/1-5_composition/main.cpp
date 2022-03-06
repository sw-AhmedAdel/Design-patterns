#include <iostream>
#include <string>
using namespace std;

/*class cars {
private:
    string name;
    string color;
    int price;
    int speed;
public:
    cars(string name, string color , int price , int speed) :name{name},color{color},price{price},speed{speed} {}
    string get_name() {
        return name;
    }
    string get_color() {
        return color;
    }
    int get_price() {
        return price;
    }
    int get_speed() {
        return speed;
    }
};

class gas_cars {
private:
    int gas_galon;
    int num_of_gas_station;
    cars car;
public:
     gas_cars(int gas_galon  , int num_of_gas_station , cars c ) : gas_galon{ gas_galon} , num_of_gas_station{num_of_gas_station} 
     , car{c} {}
     void get_data()  {
         cout<<car.get_speed()<<":"<<car.get_name()<<":"<<car.get_color()<<":"<<car.get_price()<<endl;
     }
      
};

class elctritic_cars {
private:
    int min_charge;
    string ar_drive;
    int num_of_elec_charges;
    cars car;
public:
    elctritic_cars(int m, string a , int num , cars c ) : min_charge{m}, ar_drive{a} , num_of_elec_charges{num} ,car{c} {}
    void get_data()  {
         cout<<car.get_speed()<<":"<<car.get_name()<<":"<<car.get_color()<<":"<<car.get_price()<<endl;
     }
};

int main() {
   
    cars car("lam","blue",15000,15);
    gas_cars g(20,25,car);
    g.get_data();
}*/
class country {
    string name;
    string city;
public:
    country(string n, string c) : name{n} , city{c} {}
    void set_name(string n) {name = n;}
    string get_name() {
        return name;
    }
    string get_city(){
        return city;
    }
};

class emp{
    int id;
    int age;
    country c;
public:
emp(int id , int age , country cc) : id{id} , age{age} , c(cc){}
void print_country() {
    cout<<c.get_city()<<":"<<c.get_name()<<endl;
}
};
class company{
    int budget;
    country c;
public:
    company(int c , country cc) : budget{c}  , c{cc}{}
    
    void printinfo( ) {
        cout<<budget<<":"<<c.get_city()<<":"<<c.get_name()<<endl;
    }
};

int main()
{
   
      country c("usa","san jose");
      emp e(1250,25 ,c);
      e.print_country();
      company com(25000 , c);
      com.printinfo();
}
