#include <iostream>
#include <string>
#include <vector>
using namespace std;

//mediator is like tour make the all object connected with each ohter in order to achive someting

//this is chatapp
class ChatMediator ;

class user {
protected:
    string name;
    ChatMediator * mediator;
public:

    user(string name,ChatMediator * m ):name{name},mediator{m} {}
    virtual void send(string msg)=0;
    virtual void recive(string msg)=0;
    
};
 

class ChatMediator {
public:
    virtual void sendMessage(string msg, user * u)=0;
    virtual void add_user(user * u)=0;
};


class ChatMediatorUsing : public ChatMediator {
private:
    vector<user*> vecs;
public:
    virtual void sendMessage(string msg, user * users){
        for(auto * v : vecs) {
            if(v!=users){
                v->recive(msg);
            }
        }
    }
    virtual void add_user(user * u){
        vecs.push_back(u);
    }
};

 
 

class userUser : public user {
public:
    userUser(string msg, ChatMediator * mediator):user{msg,mediator} {}
    virtual void send(string msg) {
        cout<<name<<":sending message "+ msg<<endl;
        mediator->sendMessage(msg, this);
    }
    virtual void recive(string msg){
        cout<<name<<": recived message "<<msg<<endl;
    }
};
int main()
{ 
    ChatMediator *c=new ChatMediatorUsing;
    user *user1=new userUser("ahmed",c) ;
    user *user2=new userUser("ali",c) ;
    user *user3=new userUser("leo",c) ;
    user *user4=new userUser("sue",c) ;
    c->add_user(user1);
    c->add_user(user2);
    c->add_user(user3);
    c->add_user(user4);
    user1->send("hi all");
    cout<<"____________"<<endl;
    user2->send("what do u want");
    


}

 