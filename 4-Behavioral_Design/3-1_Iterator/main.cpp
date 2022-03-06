 #include <iostream>
using namespace std;

class node {
public:
    int data;
    node * next;
};


class iterators {
public:
    virtual int next()=0;
    virtual bool is_next()=0;
};

class Arrayiterators:public iterators {
private:
    int *arr;
    int size;
    int counter;
public:
    Arrayiterators(int *a,int s):arr{a},size{s} {
        counter=0;
    }
    
    virtual int next() {
        return arr[counter++];
     
    }
    virtual bool is_next(){
        if(counter<size)
            return true;
            else 
                return false;
    }
};

class linked_list_iterators:public iterators {
    node * head;
public:
  linked_list_iterators(node * a):head{a} {}
     virtual int next() {
        int v=head->data;
        head=head->next;
        return v;
    }
    virtual bool is_next(){
         if(head!=NULL)
             return true;
             else 
                 return false;
    }
};

class collection {
public:
    virtual void insert(int v)=0;
    virtual iterators * get_iteratore()=0;
};

class arr :public collection{
private:
   int *a;
   int size;
   int counter=0;
public:
      arr(int s):size{s} {
           a=new int[size];
      }
    virtual void insert(int v) {
        if(counter<size)  {
            a[counter]=v; 
            counter++;
        }
    }
    virtual iterators * get_iteratore() {
        iterators *obj=new Arrayiterators(a,counter);
        return obj;
    }
    
};



class linked_list: public collection{
private:
    node * head=NULL;
public:
    node * temp;
    node * new_node;
    virtual void insert(int val) {
        new_node=new node;
        new_node->data=val;
        new_node->next=NULL;
        if(head==NULL){
           temp=head =new_node;
        }else {
            temp->next=new_node;
            temp=new_node;
        }
    }
     virtual iterators * get_iteratore(){
         iterators *nodes =new linked_list_iterators(head);
         return nodes;
        
     }
};


 void iterator_print(iterators * it) {
      while(it->is_next()) {
          cout<<it->next()<<" "<<endl;
      }
 }


 
class print {
private:
iterators *it;
public:
print(iterators * i):it{i} {
      while(it->is_next()) {
        cout<<it->next()<<endl;
    }
}
 

};

int main(){
  collection *a=new arr(5);
 a->insert(1);   
 a->insert(2);   
 a->insert(3);   
 a->insert(4);
iterator_print(a->get_iteratore());
collection *linked=new linked_list;
linked->insert(50);
linked->insert(80);
iterator_print(linked->get_iteratore());
cout<<"_________________________"<<endl;
print p(a->get_iteratore());
print p1(linked->get_iteratore());
 
}

 