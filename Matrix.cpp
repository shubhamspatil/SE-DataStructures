#include<iostream>
using namespace std;
class matrix
{
  int a[10][10],r,c;
  public:
  void getdata();
  void display();
  void upper();
  void transpose();
  void trace();
  friend matrix add(matrix , matrix);
  friend matrix sub(matrix , matrix);
  friend matrix multi(matrix , matrix);
  int check(matrix);
  int check_sq();
};
void matrix :: getdata()
{
  int i,j;
  cout<<"Enter rows and columns of matrix :";
  cin>>r>>c;
  cout<<"Enter the elemnts of matrix :";
  for(i=0;i<r;i++)
    {
      for(j=0;j<c;j++)
        {
           cin>>a[i][j];
        }
    }
}
void matrix :: display()
{
   int i,j;
   //cout<<"Given matrix is :\n";
   for(i=0;i<r;i++)
    {
      for(j=0;j<c;j++)
        {
           cout<<a[i][j]<<"\t";
        }
     cout<<endl;
    }
}
void matrix :: upper()
{
  int flag,i,j;
  for(i=0;i<r;i++)
    {
      for(j=0;j<c;j++)
        {
          if(i>j)
            {
              if(a[i][j]==0)
                 flag=1;
              else
                { 
                 flag=0;
                 break;
                }
                 
            }
        }
       if(flag==0)
         break;   
    }
  if(flag==1)
    cout<<"Matrix is upper triangular\n";
  else
    cout<<"Matrix is not upper triangular\n";   
}
void matrix :: transpose()
{
 int i,j,temp[10][10];
 cout<<"Transpose of matrix :\n";
 for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
      {
         temp[j][i]=a[i][j];
       }
  }  
  for(i=0;i<c;i++)
  {
    for(j=0;j<r;j++)
      {
         cout<<temp[i][j]<<"\t";
       }
  cout<<endl;
  } 
}
void matrix :: trace()
{
  int i,j,sum=0;
  for(i=0;i<r;i++)
    {
      for(j=0;j<c;j++)
        {
          if(i==j)
            {
              sum=sum+a[i][j];
            }
        }
    }
  cout<<"Addition of diagonal elements is : "<<sum;  
}
matrix add(matrix m1,matrix m2)
{
  int i,j;
  matrix temp;
  temp.r=m1.r;
  temp.c=m1.c;
  for(i=0;i<temp.r;i++)
    {
      for(j=0;j<temp.c;j++)
        {
          temp.a[i][j]=m1.a[i][j] + m2.a[i][j];
        }
    } 
  return temp;  
}
matrix sub(matrix m1,matrix m2)
{
  int i,j;
  matrix temp;  
  temp.r=m1.r;
  temp.c=m1.c;
  for(i=0;i<temp.r;i++)
    {
      for(j=0;j<temp.c;j++)
        {
          temp.a[i][j]=m1.a[i][j] - m2.a[i][j];
        }
    } 
  return temp;  
}
matrix multi(matrix m1,matrix m2)
{
  int i,j,sum,k;
  matrix temp;
  temp.r=m1.r;
  temp.c=m2.c;
  if(m1.c==m2.r)
  {
     for(i=0;i<m1.r;i++)
       {
         for(j=0;j<m2.c;j++)
          {
             sum=0;
             for(k=0;k<m1.c;k++)
              {
                sum = sum + m1.a[i][k] * m2.a[k][j];
              }
             temp.a[i][j]=sum;   
          }
       }
      return temp;    
   }
  else
    cout<<"Operation cant be perform"; 

}
int matrix :: check(matrix m2)
{
  if(r==m2.r && c==m2.c)
     return 1;
  else
    cout<<"Operation not possible !"; 
    return 0;  
}
int matrix :: check_sq()
{
  if(r==c)
   return 1;
  else
   {
    cout<<"Operation not possible !";
    return 0;
   }      
}
int main()
{
  int ch,i;
  matrix m1,m2,m3;
  m1.getdata();
  cout<<"Given Matrix is :\n";
  m1.display();
  cout<<"-------------------MENU--------------------------";
  cout<<"\n1.Check whether upper tringular or not ?\n2.Display transpose.\n3.Calculate trace.\n4.Perform Addition.\n5.Perform Subtraction.\n6.Perform Multiplication.\n--------------------------------------\n Enter your choice :";
  cin>>ch;
  switch(ch)
   {
     case 1 : if(m1.check_sq())
                m1.upper();
              break;
     case 2 : m1.transpose();
              break;
     case 3 : if(m1.check_sq())
                m1.trace();
              break;
     case 4 : m2.getdata();
              if(i=m1.check(m2))
                {
                  m3=add(m1,m2);
                  cout<<"Addition is :\n";
                  m3.display();
                }
               break;
     case 5 : m2.getdata();
              if(m1.check(m2))
                {
                  m3=sub(m1,m2);
                  cout<<"Subtraction is :\n";
                  m3.display();
                }
               break;
     case 6 : m2.getdata();                              
              m3=multi(m1,m2);
              cout<<"Multiplication is :\n";
              m3.display();                
              break; 
     default : cout<<"Wrong Choice !";
               break;                                                                          
   
   } 
  return 0;
} 
