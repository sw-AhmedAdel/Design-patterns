#include <iostream>
#include <string>
using namespace std;
//it means u have an a class and u want to control is is behavior of it is object the video object and using some condition
//u make ur object beahves on those conditon and this is chain of reaponsability
class video {
private:
  string links  ;
public:
  video(string s) :links{s} {}
  string get_link(){return links; }
};

class SocialMediasVidoes {
public:
    virtual void set_obj(SocialMediasVidoes *s)=0;
    virtual void set_videos(video v)=0;
};
class facebookVideo  : public SocialMediasVidoes{
private:
   SocialMediasVidoes *youtube;
public:
    virtual void set_obj(SocialMediasVidoes *s) {
        youtube=s;
    }
    virtual void set_videos(video v) {
        if(v.get_link()=="facebook"){
            cout<<"facebook video starts download"<<endl;
        }else {
            youtube->set_videos(v);
        }
    }
   
};
class youtubeVideo  : public SocialMediasVidoes{
private:
   SocialMediasVidoes *instgram;
public:
    virtual void set_obj(SocialMediasVidoes *s) {
        instgram=s;
    }
    virtual void set_videos(video v) {
        if(v.get_link()=="youtube"){
            cout<<"youtube video starts download"<<endl;
        }else {
             instgram->set_videos(v);
        }
    }
   
};

class instgramVideo  : public SocialMediasVidoes{
private:
   SocialMediasVidoes *null;
public:
    virtual void set_obj(SocialMediasVidoes *s) {
        null=s;
    }
    virtual void set_videos(video v) {
        if(v.get_link()=="instgram"){
            cout<<"instgram video starts download"<<endl;
        }else {
            cout<<"our website can not support downloding "<<v.get_link()<<" videos"<<endl;
        }
    }
   
};
int main()
{
	 SocialMediasVidoes *f=new facebookVideo;
     SocialMediasVidoes *y=new youtubeVideo;
     SocialMediasVidoes *i=new instgramVideo;
     video v("instgram");
     f->set_obj(y);
     y->set_obj(i);
     f->set_videos(v);
}
