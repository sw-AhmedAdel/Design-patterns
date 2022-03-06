#include <iostream>
using namespace std;


//command means has many concrete classes each one of them does specific action depsoneds on behavior of another class which is player
//we have long pass command and tackling class when the player thas the ball here is command decices the long pass class will do the action
//here goes to the excutes of this command which is the button will take the command order and do it without knowing the detials 
//between the command and the player
//so every thing is encapsolated in command and the button which is the executer does not need to know any thing 
class player{
private:
    bool ball ;
public:
player(bool balls ):ball{balls} {} 
    bool got_ball (){
        if(ball ==true)
            return true;
            else
                return false;
    }
    void LongPass() {
        cout<<"command long pass"<<endl;
    }
    void Tckling() {
        cout<<"command tacking to player has ball"<<endl;
    }
};

class Command {
protected:
    player p;
public:
    Command(player pp):p{pp} {} 
    virtual void execute()=0;
};

class  clickLongPass  : public Command {
    
public:
clickLongPass(player p):Command{p} {}
    virtual void execute(){
        p.LongPass();
    }
};

class clickTckling  : public Command{
public:
clickTckling(player p):Command{p} {}

    virtual void execute(){
        p.Tckling();
    }
};

class button{
private:
    Command *c;
public:
    button(Command *cc) :c{cc} {}
    void execute(){
        c->execute();
    }
};
int main()
{
  player p(false);
  Command * c;
  if(p.got_ball() ==true)
      c=new clickLongPass(p);
      else 
          c=new clickTckling(p);
  button b(c);
  b.execute();
}
