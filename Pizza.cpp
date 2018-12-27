#include<iostream>
using namespace std;
class pizza
{
  int order[5];
  int front,rear,size;
  public :
    pizza()
      {
        size=5;
        front=rear=-1;
      }
    int insert(int val);
    int Isfull();
    int Isempty();
    int del_order();
    void display();
};
int pizza :: Isfull()
{
  if((front==-1 && rear==size-1) || ((front+1)-rear)==1 && front!=-1)
     return 1;
  else
     return 0; 
}
int pizza :: Isempty()
{
  if((rear==-1))
     return 1;
  else
     return 0;
}
int pizza :: insert(int val)
{
  if(Isfull())
    {
      cout<<"Queue is full.\n";
      return 1;
    }
  else
    {
       rear=(rear+1)%size;
       order[rear]=val;
      // cout<<"******front="<<front<<" rear="<<rear<<" order["<<rear<<"]="<<order[rear]<<"*****"<<endl;
    }
}
int pizza :: del_order()
{
  int data;
  if(Isempty())
    {
      cout<<"Queue is empty.\n";
      return 1;
    }
  else
   {
     front=(front+1)%size;
     data=order[front];
     if(front==rear)
        front=rear=-1;
    //cout<<"******front="<<front<<" rear="<<rear<<"******"<<endl;
   }
}
void pizza :: display()
{
  int i;
  if(Isempty())
      cout<<"No orders.\n";
  else
  {
    if(front+1>rear)
      {
        i=front+1;
        while(i<size)
          {
           cout<<order[i]<<" ";
           i++;
          }
        i=0;
        while(i<=rear)
          {
           cout<<order[i]<<" ";
           i++;
          }   
      }
    else
      {
        for(i=front+1;i<=rear;i++)
           {
             cout<<order[i]<<" ";
           }      
      }
    cout<<endl;
  }
}
int main()
{
  int coupon,c,i;
  char ch;
  pizza p;
  cout<<"Place your order :\n ";
  do
   {
     i=0;
     cout<<"Enter your coupon number : ";
     cin>>coupon;
     i=p.insert(coupon);
     if(i==1)
       break;
     cout<<"Any more orders (y/n) : ";
     cin>>ch;
   }while(ch=='y');
  cout<<"Current processing orders : ";
  p.display();
  do{
  cout<<"----------MENU-------\n";
  cout<<"1 : Add order.\n2 : Deliver order.\n---------------\n";
  cout<<"Enter your choice : ";
  cin>>c;
  switch(c)
    {
      case 1 : cout<<"Enter your coupon number : ";
               cin>>coupon;
               p.insert(coupon);
               cout<<"Current processing orders : ";
               p.display();
               break;
      case 2 : p.del_order();
               cout<<"Current processing orders : ";
               p.display();
               break;
      default : cout<<"Wrong Choice ! ";
    } 
  cout<<"do you want to continue (y/n) : ";
  cin>>ch;
  }while(ch=='y');
  return 0;
}
