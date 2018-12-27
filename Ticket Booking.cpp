#include<iostream>
#include<stdlib.h>
using namespace std;
class node
{
  public:
   char data;
   node *next,*prev;
};
class ticket
{
  node *head[10];
  public :
    void create();
    void display();
    void book();
    void cancel();
};
void ticket :: create()
{
  int i,j;
  node *n1,*last;
  for(j=0;j<10;j++)
    {
       for(i=0;i<7;i++)
         {
           n1=new node;
           n1->data='_';
           n1->prev=n1->next=n1;
           if(i==0)
             {
               head[j]=n1;
               last=n1;   
             }
           else 
             {
               last->next=n1;
               n1->prev=last;
               n1->next=head[j];
               head[j]->prev=n1;
               last=n1;
             }  
         }    
    }
}
void ticket :: display()
{
 int i,j;
 char C[]={' ','1','2','3','4','5','6','7'};
 char R[]={'A','B','C','D','E','F','G','H','I','J'};
 node *temp;
 cout<<C[0]<<"  ";
 for(i=1;i<8;i++)
   cout<<" "<<C[i]<<"   ";
 cout<<"\n";  
 for(i=0;i<10;i++)
   {
     temp=head[i];
     cout<<R[i]<<"  ";
     for(j=0;j<7;j++)
       {
         cout<<"["<<temp->data<<"]  ";
         temp=temp->next;
       }
      cout<<"\n";    
   } 
  cout<<"\n\t[_] : Available.\n\t[x] : Booked.\n";
  cout<<"---------Menu--------\n";
  cout<<"1 : Book tickets.\n2 : Cancel.\n3 : Exit.\n--------------\n";
}
void ticket :: book()
{
  node *temp;
  int r,c,i,j,t;
  char s[3];
  cout<<"Enter total seats to book : ";
  cin>>t;
  cout<<"Enter seat no : ";
  for(j=0;j<t;j++)
    {
      cin>>s;
      r=s[0]%65;
      c=s[1]%48;
      temp=head[r];
      for(i=0;i<c-1;i++)
        temp=temp->next;
      temp->data='x';
    }
  display();
}
void ticket :: cancel()
{
  node *temp;
  int r,c,i,j,t;
  char s[3];
  cout<<"Enter total seats to cancel : ";
  cin>>t;
  cout<<"Enter seat no : ";
  for(j=0;j<t;j++)
    {
      cin>>s;
      r=s[0]%65;
      c=s[1]%48;
      temp=head[r];
      for(i=0;i<c-1;i++)
        temp=temp->next;
      temp->data='_';
    }
  display();
}
int main()
{
  int ch,i=1;
  ticket t;
  t.create();
  cout<<"\n";
  t.display();
  do
   {
     cout<<"Enter your choice : ";
     cin>>ch;
     switch(ch)
       {
         case 1 : t.book();
                  break;
         case 2 : t.cancel();
                  break;
         case 3 : exit(1);
                  i=0; 
                  break;
       }
    }while(i==1);
  return 0;
}
