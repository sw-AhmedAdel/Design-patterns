#include <iostream>
#include <string>
using namespace std;

class mediaPlayer{
public:
    virtual void play(string audioType, string filename)=0;
};

class audioPlayer: public mediaPlayer {
public:
    virtual void play(string audioType, string filename){
        if(audioType=="mp3")
            cout<<"playing mp3 "<<filename<<endl;
            else 
                cout<<"invalied media "<<audioType<<" is not soport"<<endl;
    }        
};

class advancedMediaPlyaer {
public:
   virtual void loadFilename(string filename)=0;
   virtual void listen()=0; 
};

class Vlcplayer :public advancedMediaPlyaer {
public:
string myfile;
   virtual void loadFilename(string filename){
       myfile=filename;
   }
   virtual void listen(){
       cout<<"listen to  Vlcplayer "<<myfile<<endl;
   }
};

class MP4player:public advancedMediaPlyaer {
public:
   string myfile;
   virtual void loadFilename(string filename){
       myfile=filename;
   }
   virtual void listen(){
       cout<<"listen to  MP4player "<<myfile<<endl;
   }
};

//want to adapt advanced to the media means i want mb4 and vlc to play as mdial player wich is mb3
class adapter_music :public mediaPlayer{
private:
    advancedMediaPlyaer * music;
    //in the adapter class u put a pointer to the class u want to convert
public:
    adapter_music(advancedMediaPlyaer * a) :music{a} {}
    
 
    virtual void play(string audioType, string filename) {
        music->loadFilename(filename);
        music->listen();
    }
};
int main()
{
	  
      advancedMediaPlyaer *mp4= new MP4player;
      adapter_music a(mp4);
      a.play("mp4","alone mp4");
      cout<<"_________________"<<endl;
      advancedMediaPlyaer *v= new Vlcplayer;
      adapter_music a1(v);
      a1.play("vlc","far far away");
      
}
