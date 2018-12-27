#include<iostream>
using namespace std;
class queue
{
  int job[10],front,rear;
  public :
    queue()
      {
        front=rear=-1;
      }
    int Isfull();
    int Isempty();
    void insert(int); 
    int del_job();
    void display();
};
int queue :: Isfull()  
{
  if(rear==9)  
    return 1;
  else
    return 0;
}
int queue :: Isempty()  
{
  if(front==rear)
    return 1;
  else
    return 0;
}
void queue :: insert(int id)  
{
  if(Isfull())
    cout<<"Queue is full.\n";
  else
   {
     rear++;
     job[rear]=id;
   }  
}
int queue :: del_job()   
{
  if(Isempty())
   {
     cout<<"Queue is empty.\n";
   }
  else
   { 
     front++;
     return(job[front]); 
   }  
}
void queue :: display()  
{
  int i;
  for(i=front+1;i<=rear;i++)
    cout<<job[i]<<" ";
  cout<<endl;  
}
int main()
{
  char ch;
  int c,id;
  queue q;
  do
   {
     cout<<"Enter your job ID : ";
     cin>>id;
     q.insert(id);
     cout<<"Do you want to continue (y/n) : ";
     cin>>ch;
   }while(ch=='y');
  cout<<"The queue of job application : ";
  q.display();
  do
  {
    cout<<"-----------Menu---------\n";
    cout<<"1 : Add your ID for job application.\n2 : Remove job application.\n----------------------\n";
    cout<<"Enter your choice : ";
    cin>>c;
    switch(c)
      {
        case 1 : cout<<"Enter your ID : ";
                 cin>>id;
                 q.insert(id);
                 cout<<"The queue of job application : ";
                 q.display();
                 break;
        case 2 : id=q.del_job();
                 cout<<"ID of removed application is : "<<id<<endl;
                 cout<<"New job application queue is : ";
                 q.display();
                 break;
       default : cout<<"Wrong choice ! \n";                  
     }
    cout<<"Do you want to continue (y/n) : ";
    cin>>ch;
   }while(ch=='y'); 
  return 0;
}
