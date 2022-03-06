#include <iostream>
#include <string>
using namespace std;

class hollywood{
public:
    virtual void displaymovies() const   =0;
     virtual ~hollywood()=default;
};


class hollywood_action_movies :public hollywood {
    public:
    virtual void displaymovies()const override {
         cout<<"hollywood action movies "<<endl;
         cout<<"The Dark Knight"<<endl;
         cout<<"Minority Report"<<endl;
         cout<<"Mad Max: Fury Road"<<endl;
    }
    virtual ~hollywood_action_movies()=default;
};
class hollywood_comedy_movies :public hollywood {
    public:
    virtual void displaymovies()const override {
         cout<<"hollywood comedy movies "<<endl;
         cout<<"The spy "<<endl;
         cout<<"This Is the End"<<endl;
         cout<<"Neighbors"<<endl;
    }
    virtual ~hollywood_comedy_movies()=default;
};
class bollywood   {
    public:
    virtual void displaymovies()const=0 ;
    virtual ~bollywood()=default;
};

class bollywood_action_movies :public bollywood {
    public:
    virtual void displaymovies()const override {
         cout<<"bollywood action movies "<<endl;
         cout<<"Kung Fu Yoga"<<endl;
         cout<<"Baaghi"<<endl;
         cout<<"Raees "<<endl;
    }
    virtual ~bollywood_action_movies()=default;
};
  
class bollywood_comedy_movies :public bollywood {
    public:
    virtual void displaymovies()const override {
         cout<<"bollywood comedy movies "<<endl;
         cout<<"Kung Fu Yoga "<<endl;
         cout<<"Jawaani Jaaneman"<<endl;
         cout<<"pk"<<endl;
    }
    virtual ~bollywood_comedy_movies()=default;
};
  
class ifactory{
protected:
    hollywood * h;
    bollywood * b;
    virtual hollywood * get_hollywood_movies(string name) =0;
    virtual bollywood * get_bollywood_movies(string name) =0;
    virtual ~ifactory()=default;
};
class factory  : public ifactory{
public:
        virtual hollywood * get_hollywood_movies(string name)  {
            if(name=="action")
                return h=new hollywood_action_movies;
                else if(name=="comedy")
                    return h=new hollywood_comedy_movies;
                    else return NULL;
        }
          virtual bollywood * get_bollywood_movies(string name)  {
            if(name=="action")
                return b=new bollywood_action_movies;
                else if(name=="comedy")
                    return b=new bollywood_comedy_movies;
                    else return NULL;
        }
        
};
   

int main()
{
    factory f;
    hollywood * h;
    bollywood * b;
	 int choice;
     int c;
     do {
         cout<<"1- hollywood movies"<<endl;
         cout<<"2- bollywood movies"<<endl;
         cout<<"0 - exit"<<endl;
         cin >> choice;
         while(choice != 1 && choice != 2 && choice != 0) {
             cout<<"enter 1 or 2 "<<endl;
             cin >> choice;
         }
         if(choice ==1) 
         {
             cout<<"1- action"<<endl;
             cout<<"2- comedy"<<endl;
             cin >> c;
             if(c==1) {
                 h=f.get_hollywood_movies("action");
                 h->displaymovies();
             }
                 else {
                 h=f.get_hollywood_movies("comedy");
                 h->displaymovies(); 
                 }
         }
         else if(choice ==2) {
             cout<<"1- action"<<endl;
             cout<<"2- comedy"<<endl;
             cin >> c;
             if(c==1) {
                 b=f.get_bollywood_movies("action");
                 b->displaymovies();
             }
                 else {
                 b=f.get_bollywood_movies("comedy");
                 b->displaymovies(); 
                 }
         }else if(choice ==0) 
             cout<<"exit"<<endl;
             else 
                 cout<<"valied pelase try again"<<endl;
         
         
     }while(choice !=0);
}
