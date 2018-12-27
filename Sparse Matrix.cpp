#include<iostream>
using namespace std;
class spmatrix
{
  int mat[10][10],r,c,sp[20][3];
  public :
    void get_mat();
    void put_mat();
    void create_sparse();
    void put_sparse();
    void transpose(spmatrix);
    void fast_trans(spmatrix);
    void add(spmatrix,spmatrix);
};
void spmatrix :: get_mat()
{
  int i,j;
  cout<<"Enter the number of rows and columns : ";
  cin>>r>>c;
  cout<<"Enter the elements : ";
  for(i=0;i<r;i++)
   { 
     for(j=0;j<c;j++)
       {
         cin>>mat[i][j];
       } 
   }
}
void spmatrix :: put_mat()
{
  int i,j;
  for(i=0;i<r;i++)
   { 
     for(j=0;j<c;j++)
       {
         cout<<mat[i][j]<<"  ";
       }
     cout<<"\n";   
   }
}
void spmatrix :: create_sparse()
{
  int i,j,k=1;
  for(i=0;i<r;i++)
   {
     for(j=0;j<c;j++)
       {
          if(mat[i][j]!=0)
            {
              sp[k][0]=i;
              sp[k][1]=j;
              sp[k][2]=mat[i][j];    
              k++;        
            }
       }
   }
   sp[0][0]=r;
   sp[0][1]=c;
   sp[0][2]=k-1;
}
void spmatrix :: put_sparse()
{
  int i,j;
  for(i=0;i<=sp[0][2];i++)
   { 
     for(j=0;j<3;j++)
       {
         cout<<sp[i][j]<<"  ";
       }
     cout<<"\n";   
   }
}
void spmatrix :: transpose(spmatrix m)
{
  int i,j,k=1;
  sp[0][0]=m.sp[0][1];
  sp[0][1]=m.sp[0][0];
  sp[0][2]=m.sp[0][2];                                              
  for(i=0;i<m.sp[0][1];i++)
    {
      for(j=1;j<=sp[0][2];j++)
        {
          if(m.sp[j][1]==i)
            {
              sp[k][0]=m.sp[j][1];
              sp[k][1]=m.sp[j][0];
              sp[k][2]=m.sp[j][2];
              k++;         
            }        
        }    
    }
}
void spmatrix :: fast_trans(spmatrix m)
{
  int i,j;
  int rpos[10];
  int rterm[10];
  for(i=0;i<m.sp[0][1];i++)
    {
     rterm[i]=0;
    }
  for(i=1;i<=m.sp[0][2];i++)
    {
     rterm[m.sp[i][1]]++;
    }
    rpos[0]=1;                                                                  
  for(i=1;i<m.sp[0][1];i++)
    {
    rpos[i]=rpos[i-1]+rterm[i-1];
    }
  for(i=1;i<=m.sp[0][2];i++)
   {
    j=rpos[m.sp[i][1]];
    sp[j][0]=m.sp[i][1];
    sp[j][1]=m.sp[i][0];
    sp[j][2]=m.sp[i][2];
    rpos[m.sp[i][1]]++;  
   }  
  sp[0][0]=m.sp[0][1];
  sp[0][1]=m.sp[0][0];
  sp[0][2]=m.sp[0][2];   
}
void spmatrix :: add(spmatrix s1,spmatrix s2)
{
  int i=1,j=1,k=1;
  if(s1.sp[0][0]==s2.sp[0][0] && s1.sp[0][1]==s2.sp[0][1])
    {
       while(i<=s1.sp[0][2] && j<=s2.sp[0][2])
          {
             if(s1.sp[i][0] == s2.sp[j][0])
                {
                   if(s1.sp[i][1] == s2.sp[j][1])
                      {
                         sp[k][2]=s1.sp[i][2]+s2.sp[j][2];
                         sp[k][0]=s1.sp[i][0];
                         sp[k][1]=s2.sp[j][1];
                        k++;i++;j++; 
                      }
                    else if(s1.sp[i][1]<s2.sp[j][1])
                      {
                          sp[k][2]=s1.sp[i][2];
                          sp[k][0]=s1.sp[i][0];
                          sp[k][1]=s1.sp[i][1];
                         k++;i++;
                      }
                    else
                      {
                         sp[k][2]=s2.sp[j][2];
                         sp[k][0]=s2.sp[j][0];
                         sp[k][1]=s2.sp[j][1];
                        k++;j++;  
                      } 
                }
              else if(s1.sp[i][0]>s2.sp[j][0])
                {
                   sp[k][2]=s2.sp[j][2];
                   sp[k][0]=s2.sp[j][0];
                   sp[k][1]=s2.sp[j][1];
                  k++;j++;
                }
             else
                {
                   sp[k][2]=s1.sp[i][2];
                   sp[k][0]=s1.sp[i][0];
                   sp[k][1]=s1.sp[i][1];
                  k++;i++;
                }  
          }
       while(i<=s1.sp[0][2])
         {
              sp[k][2]=s1.sp[i][2];
              sp[k][0]=s1.sp[i][0];
              sp[k][1]=s1.sp[i][1];
             k++;i++;           
         } 
      while(j<=s2.sp[0][2])
         {
            sp[k][2]=s2.sp[j][2];
            sp[k][0]=s2.sp[j][0];
            sp[k][1]=s2.sp[j][1];
           k++;j++;
         }
       sp[0][0]=s1.sp[0][0];
       sp[0][1]=s1.sp[0][1];
       sp[0][2]=k-1;
    }
   else
     cout<<"Operation cannot be performed.\n";
}
int main()
{
  int ch;
  spmatrix m1,m2,m3;
  cout<<"For first matrix : \n";
  m1.get_mat();
  cout<<"Entered matrix :\n";
  m1.put_mat();
  m1.create_sparse();
  cout<<"Sparse matrix : \n";
  m1.put_sparse();
  cout<<"--------------------MENU-------------------\n";
  cout<<"1 : Simple Transpose.\n2 : Fast transpose.\n3 : Addition of sparse matrix.\n----------------------------";
  cout<<"\nEnter your choice : ";
  cin>>ch; 
  switch(ch)
    {
       case 1 : m3.transpose(m1);
                cout<<"Transpose : \n";
                m3.put_sparse(); 
                break;
       case 2 : cout<<"Fast transpose : \n";
                m3.fast_trans(m1);
                m3.put_sparse();
                break;
       case 3 : cout<<"For second matrix : \n";
                m2.get_mat();
                cout<<"Entered matrix :\n";
                m2.put_mat();
                m2.create_sparse();
                cout<<"Sparse matrix : \n";
                m2.put_sparse(); 
                m3.add(m1,m2);
                cout<<"Addition is : \n";
                m3.put_sparse(); 
                break;
      default : cout<<"Wrong Choice ! \n";
    }  
  return 0;
}
