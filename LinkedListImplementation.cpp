#include <iostream>
#include <string>
#include <stack> 

using namespace std;
template <class T>
class Node
{
    public:
    T info;
    Node<T>* next;
    Node(){};
    Node(T x,Node<T>* y)
    {
        info=x;
        next=y;
    }
};

template <class T>
class LinkedList
{
  public:
    Node<T>* head;
    LinkedList(){head=NULL; }

    void insert(T data,int i)
    {
      
      Node<T>* pre=new Node<T>();
      Node<T>* cur=new Node<T>();
      Node<T>* temp=new Node<T>();
      temp->info=data;
      temp->next=NULL;
      int tempi=0;
      cur=head;
      while(tempi<i && cur->next!=NULL)
      {
        pre=cur;
        cur=cur->next;
        tempi++;
      }
      if(i==0)
        {
          head=temp;
          head->next=cur;
        }
      else if(tempi+1==i && cur->next==NULL)
      {
        cur->next=temp;
      }
      else{
        pre->next=temp; 
        temp->next=cur;
      }
    }

    T get(int i)
    {
      Node<T>* cur;
      cur=head;
        while(i>0)
        {
            cur=cur->next;
            i--;
        }
        return cur->info;
    }

    void print()
    {
     Node<T>* cur;
     cur=head;
      while(cur)
      {
        cout<<cur->info<<endl;
        cur=cur->next;
      }
      cout<<endl;
    }

    void remove(T data)
    {
      Node<T>* cur=new Node<T>();
      Node<T>* pre=new Node<T>();
      if(head->info==data)
      {  
        head=head->next;
        return;
      }
      cur=head->next;
      pre=head;
      while(cur!=NULL)
      {
        if(cur->info==data)
        {
          pre->next=cur->next;
          return;
        }
          cur=cur->next;
          pre=pre->next;
      }
    }

    void removeIndex(int i)
    {
      Node<T>* cur=new Node<T>();
      cur=head;
      if(i==0)
        {
          head=head->next;
          return;
        }
      while(i>1)
      {
        cur=cur->next;
        i--;
      }
      cur->next=cur->next->next;
    }

    void set(int i,T data)
    {
      Node<T>* cur=new Node<T>();      Node<T>* temp=new Node<T>();
      temp->info=data;
      Node<T>* con=new Node<T>(); 
      cur=head;
      if(i==0)
       { head->info=data;
        return;}
      while(i>1)
      {
        cur=cur->next;
        i--;
      }
      if(cur->next==NULL)
      {
        cur->next=temp;
      }
      else
      {
        con=cur->next->next;
        cur->next=temp;
        temp->next=con;
      }     
    }

    Node<T>* find(T data)
    {
      Node<T>* cur=new Node<T>();
      cur=head;
      while(cur!=NULL)
      {
        if(cur->info==data)
          return cur;
        else cur=cur->next;
      }
      cout<<"Not found"<<endl;
      return NULL;
    }

    void reverse()
    {
      stack<Node<T>*> s;
      Node<T> *cur = head;
      while(cur!=NULL)
      {
        s.push(cur);
        cur = cur->next;
      }
      Node<T> *temp = s.top();
      head = temp;
      s.pop();
      while(!s.empty())
      {
        temp->next = s.top();
        s.pop();  
        temp = temp->next;
      }
      temp->next = NULL;        
    }
  int getLength()
  {
    Node<T>* cur = head;
    int i=0;
    for(;cur!=NULL;cur=cur->next){
      i++;
    }
    return i;
  }

  void sort()
  {
    mergesort(&head);
  }
  static void mergesort(Node<T>** headref)
  {
    Node<T>* head=*headref;
    Node<T>* head1; 
    Node<T>* head2;  
    if(head==NULL || head->next==NULL)
    {return;} 
    split(head,&head1,&head2);
    mergesort(&head1);
    mergesort(&head2);
    *headref=merge(head1,head2);
  }

  static Node<T>* merge(Node<T>* head1,Node<T>* head2)
  {
    Node<T>* newHead=NULL;
    if(head1==NULL) return head2;
    else if(head2 ==NULL) return head1;
    if(head1->info<head2->info)
    {
      newHead = head1;
      newHead->next = merge(head1->next,head2);
    }
    else
    {
      newHead = head2;
      newHead->next = merge(head1,head2->next);
    }
    return newHead;
  }
  static void split(Node<T>* head,Node<T>** head1,Node<T>** head2)
  {
    Node<T>* first=head;
    Node<T>* second=head->next;
    while(second!=NULL)
    {
      second=second->next;
      if(second!=NULL)
      {
        first=first->next;
        second=second->next;
      }
    }
    *head1=head;
    *head2=first->next;
    first->next=NULL;
  }
};

int main()
{
  LinkedList<int>* a=new LinkedList<int>();
  a->insert(15,0);
  a->insert(14,1);
  a->insert(7,2);
  a->insert(5,3);
  cout<<a->get(0)<<endl; 
  cout<<a->get(1)<<endl;
  cout<<a->get(2)<<endl;
  cout<<a->get(3)<<endl;
  a->print();
  a->remove(15);
  a->removeIndex(2);
  a->print();
  a->set(2,17);
  a->set(3,4);
  a->set(4,96);
  a->set(2,18);
  a->set(0,100);
  a->set(1,90);
  a->print();
  cout<<a->find(96)<<endl;
  cout<<a->find(100)<<endl;
  cout<<a->head<<endl;
  a->reverse();  
  a->print();
  a->sort();
  a->print();

  return 0;
}


