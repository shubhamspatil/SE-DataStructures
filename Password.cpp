#include<iostream>
using namespace std;
class password
{
  char a[20]={'1','3','a','s','t','i'};
  public:
  void display()
  {
    int i;
    cout<<"Allowed characters : {";
   for(i=0;i<5;i++)
     {
       cout<<a[i]<<",";
     }
     cout<<a[i]<<"}\n";
  }
  void pass()
  {
     int i,j,k,l,count=0;
     for(i=0;i<6;i++)
     {
       for(j=0;j<6;j++)
         {
           for(k=0;k<6;k++)
             {
                for(l=0;l<6;l++)
                  {
                      cout<<a[i]<<a[j]<<a[k]<<a[l]<<", ";
                      count++;
                  }
             }
         }
     }
    cout<<"Total combination with repetition: "<<count<<endl;
  }
};
int main()
{
  password p1;
  p1.display();
  p1.pass();
  return 0;
}
