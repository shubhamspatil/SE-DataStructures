#include<iostream>
using namespace std;
class workshop
{
  int roll[7],size;
  public : 
    void getdata();
    void display();
    void linear_search();
    void sentinal_search();
};
void workshop :: getdata()
{
  int i;
  size=5;
  cout<<"Enter five the roll number : ";
  for(i=0;i<size;i++)
    cin>>roll[i];
}
void workshop :: display()
{
  int i;
  for(i=0;i<5;i++)
   cout<<roll[i]<<" ";
  cout<<endl; 
}
void workshop :: linear_search()
{
  int flag=0,i,key;
  cout<<"Enter the roll number to search : ";
  cin>>key;
  for(i=0;i<5;i++)
    {
      if(roll[i]==key)
       {
         cout<<"Student was present for training program.\n";
         flag=1;
         break;
       }
    }
   if(flag==0)
     cout<<"Student was not present for training program.\n"; 
}
void workshop :: sentinal_search()
{
  int i=0,key;
  cout<<"Enter the roll number to search : ";
  cin>>key;
  roll[size]=key;
  while(roll[i]!=key)
   i++;
  if(i<size)
    cout<<"Student was present for training program.\n";
  else
    cout<<"Student was not present for training program.\n"; 
}
int main()
{
  int ch;
  workshop w;
  w.getdata();
  cout<<"Roll numbers : ";
  w.display();
  cout<<"-------------MENU-------------\n";
  cout<<"1 : Search by linear search.\n2 : Search by sentinal search.\n----------------\n";
  cout<<"Enter your choice : ";
  cin>>ch;
  switch(ch)
    {
      case 1 : w.linear_search();
               break;
      case 2 : w.sentinal_search();
               break;
      default : cout<<"Wrong choice ! ";         
    }
  return 0;
}
