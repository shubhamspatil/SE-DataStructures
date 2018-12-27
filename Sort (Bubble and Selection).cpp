#include<iostream>
using namespace std;
class marks
{
  float percent[10];
  int size;
  public : 
    void getdata();
    void display();
    void top();
    void bubble();
    void selection();
    void swap(float&,float&);
    int rsize()
     {
       return size;
     }
    float* rarray()
     {
       return (percent);
     } 
};
void marks :: getdata()
{
  int i;
  size=10;
  cout<<"Enter FE percentage of ten students : ";
  for(i=0;i<size;i++)
    cin>>percent[i];
}
void marks :: display()
{
  int i;
  for(i=0;i<size;i++)
   cout<<"("<<percent[i]<<"%) ";
  cout<<endl; 
}
void marks :: bubble()
{
  int i,j;
  for(i=0;i<size-1;i++)
   {
     for(j=0;j<size-1;j++)
      {
         if(percent[j]>percent[j+1])
           {
              swap(percent[j],percent[j+1]);
           }
      }
   }
}
void marks :: swap(float &a,float &b)
{
  float temp;
  temp=a;
  a=b;
  b=temp;
}
void marks :: selection()
{
  int i,j;
  for(i=0;i<size;i++)
   {
     for(j=0;j<size;j++)
      {
         if(percent[i]<percent[j])
           {
              swap(percent[i],percent[j]);
           }
      }
   }
}
void marks :: top()
{
  int i;
  for(i=size-1;i>=5;i--)
   {
      cout<<" Rank "<<i%10<<" : "<<percent[i]<<"%"<<endl;
   }
}
int main()
{
  int ch;
  marks m;
  m.getdata();
  cout<<"Percentage of students are : \n";
  m.display();
  cout<<"-------------MENU-------------\n";
  cout<<"1 : Sort using bubble sort.\n2 : Sort using selection sort.\n--------------------------\n";
  cout<<"Enter your choice : ";
  cin>>ch;
  switch(ch)
   {
     case 1 : m.bubble();
             cout<<"Sorted percentage of students are : \n";
             m.display();
             cout<<"Top five ranks : \n";
             m.top();
             break;
     case 2 : m.selection();
             cout<<"Sorted percentage of students are : \n";
             m.display();
             cout<<"Top five ranks : \n";
             m.top();
             break;
     default : cout<<"Wrong choice !\n";
   }
  return 0;
}
