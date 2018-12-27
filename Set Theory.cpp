#include<iostream>

using namespace std;

class student

{

  int setA[50],setB[50],m,countA,countB,uni_count;

  public:

  void getdata();

  void display();

  void intersection();

  void uni();
  void only_cricket();
  void only_badmintion();
  void no_play();
  int remove_dub(int *,int);

};

void student :: getdata()
{
  int i;

  cout<<"Enter the total no of the students :";

  cin>>m;

  cout<<"Enter no of students playing cricket :";

  cin>>countA;

  cout<<"Enter roll no of the students playing cricket :";

  for(i=0;i<countA;i++)

   {

    cin>>setA[i];
   }

  cout<<"Enter no of students playing badminton :";

  cin>>countB;

  
cout<<"Enter roll no of the students playing badminton :";

  for(i=0;i<countB;i++)

   {

    cin>>setB[i];

   }

}

void student :: display()

{

  int i;

  cout<<endl<<"----------------Solution---------------------"<<endl;

  cout<<"Total no of the students :"<<m<<endl;

  cout<<"Roll no. of students playing cricket : {";

  for(i=0;i<countA-1;i++)

   {

    cout<<setA[i]<<",";

   }

  cout<<setA[i]<<"}\n";

  cout<<" Total students playing cricket :"<<countA<<endl;

  cout<<"Roll no. of the students playing badminton : {";

  for(i=0;i<countB-1;i++)

   {

    cout<<setB[i]<<",";

   }

  cout<<setB[i]<<"}\n";

  cout<<" Total students playing badminton :"<<countB<<endl;

}

void student :: intersection()

{

  int temp[20],k=0,i,j,g,flag;

  for(i=0;i<countA;i++)

   {

     for(j=0;j<countB;j++)

       {

          if(setA[i]==setB[j])

            {

              flag=1;

              break;

            }

          else

            flag=0;
 
      }

     if(flag==1)

       {

         temp[k]=setA[i];

         k++;
    
   }
    }

  cout<<"Student playing both cricket & badmintion : {";

  remove_dub(&temp[0],k);
}

void student :: uni()

{

  int temp[20],k=0,i,j,g,flag;

  for(i=0;i<countA;i++)
    {
      temp[k]=setA[i];
      k++;
    }
  for(i=0;i<countB;i++)

   {

     for(j=0;j<countA;j++)

       {

          if(setB[i]==setA[j])

            {

              flag=1;

              break;

            }

          else

            flag=0;
 
      }

     if(flag==0)

       {

         temp[k]=setB[i];

         k++;
    
   }
    }

  cout<<"Students playing either cricket or badmintion : {";

  uni_count=remove_dub(&temp[0],k);
}
void student :: only_cricket()

{

  int temp[20],k=0,i,j,g,flag;

  for(i=0;i<countA;i++)

   {

     for(j=0;j<countB;j++)

       {

          if(setA[i]==setB[j])

            {

              flag=1;

              break;

            }

          else

            flag=0;
 
      }

     if(flag==0)

       {

         temp[k]=setA[i];

         k++;
    
   }
    }

  cout<<"Students playing only cricket : {";

  remove_dub(&temp[0],k);
}


void student :: only_badmintion()

{

  int temp[20],k=0,i,j,g,flag;

  for(i=0;i<countB;i++)

   {

     for(j=0;j<countA;j++)

       {

          if(setB[i]==setA[j])

            {

              flag=1;

              break;

            }

          else

            flag=0;
 
      }

     if(flag==0)

       {

         temp[k]=setB[i];

         k++;
    
   }
    }

  cout<<"Students playing only badmintion : {";

  remove_dub(&temp[0],k);
}
void student :: no_play()
{
  cout<<"Number of students not playing any game : "<<(m-uni_count)<<endl;
}
int student :: remove_dub(int *p,int size)
{
   int temp[size],temp1[size],i,k=0,j;
   for(i=0;i<size;i++)
     {
       temp[i]=*p;
       p++;
     }
   for(i=0;i<size;i++)
     {
        for(j=i+1;j<size;j++)
           {
             if(temp[i]==temp[j])
                temp[j]=0; 
           }
     }
   for(i=0;i<size;i++)
     {
       if(temp[i]!=0)
          {
            temp1[k]=temp[i];
            k++;
          }
     }
   for(i=0;i<k-1;i++)
    {
       cout<<temp1[i]<<",";
    }
   cout<<temp1[i]<<"}\n";
   return k;
}



























int main()

{
 
student s;

 s.getdata();

 s.display();

 cout<<endl;
 s.intersection();

 s.uni();
 s.only_cricket();
 s.only_badmintion();
 s.no_play();
 return 0;

}
