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
    void quicksort(float a[10],int low,int high);
    int partition(float a[10],int low,int high);
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
   cout<<percent[i]<<"% ";
  cout<<endl; 
}
void marks :: quicksort(float a[10],int low,int high)
{
   int j;
   if(low<high)
     {
       j = partition(a,low,high);
       quicksort(a,low,j-1);
       quicksort(a,j+1,high); 
     }
}
int  marks :: partition(float a[10],int low,int high)
{
  float pivot;
  int i,j;
  pivot=a[low];
  i=low+1;
  j=high;
  while(i<j)
   {
      while(i<high && a[i]<pivot)
        i++;
      while(j>low && a[i]>=pivot)
        j--;
      if(i<j)
        swap(a[i],a[j]);            
   }
   swap(a[low],a[j]); 
   return j;
}
void marks :: swap(float &a,float &b)
{
  float temp;
  temp=a;
  a=b;
  b=temp;
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
  marks m;
  m.getdata();
  cout<<"Percentage of students are : \n";
  m.display();
  m.quicksort(m.rarray(),0,m.rsize()-1);
  cout<<"Sorted percentage of students are : \n";
  m.display();
  cout<<"Top five ranks : \n";
  m.top();
  return 0;
}
