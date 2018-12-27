#include<iostream>
#include<string>
using namespace std;
class string_op
{
   char s[30];
   public:
    void getdata();
    void display();
    int strlength();
    void copy(string_op);
    void str_con(string_op,string_op);
    void reverse(string_op);
    void substring();
    void compare(string_op);
    void icompare(string_op);
};
void string_op :: getdata()
{
  cin.getline(s,30);
}
void string_op :: display()
{
  cout<<s;
}
int string_op :: strlength()
{
  int i=0;
  while(s[i] != '\0')
     i++;
  return i;   
}
void string_op :: copy(string_op temp)
{
   int i=0;
   while(temp.s[i] != '\0')
    {
      s[i]=temp.s[i];
      i++;
    }
    s[i]='\0';   
}
void string_op :: str_con(string_op s1,string_op s2)
{
  int l1,l2,i,j;
  l1=s1.strlength();
  l2=s2.strlength();
  for(i=0;i<l1;i++)
    s[i]=s1.s[i];
  for(j=0;j<l2;j++)
   {
     s[i]=s2.s[j];
     i++;
   }  
  s[i]='\0'; 
}
void string_op :: reverse(string_op s1)
{
 int i,j=0; 
 for(i=s1.strlength()-1;i>=0;i--)
   {
     s[j]=s1.s[i];
     j++;
   } 
 s[j]='\0';
}
void string_op :: substring()
{
  string_op sub;
  int i=0,j=0,flag=0;
  cout<<"Enter the substring to check :";
  cin.ignore();
  sub.getdata();
  while(s[i] != '\0')
    {
      if(s[i]==sub.s[j])
        {
          i++;
          j++;
        }
      else
        {
          i++;
          j=0;
        }
       if(sub.s[j]=='\0')
        {
          cout<<"Substring exists at index : "<<i-sub.strlength()<<endl;
          j=0;
          flag=1;        
        } 
    }
  if(flag==0)
    cout<<"Substring does not exists.\n";   
}
void string_op :: compare(string_op s1)
{
  int i=0,flag;
  if(strlength()==s1.strlength())
   {
      for(i=0;i<strlength();i++)
        {
          if(s[i]==s1.s[i])
             flag=1;
          else
           {
             flag=0;   
             break;
           }          
        }
      if(flag==1)
        cout<<"String are equal.\n";
      else
        cout<<"String are not equal.\n";       
   }
  else
    cout<<"String are not equal.\n"; 
}
void string_op :: icompare(string_op s1)
{
  int i=0,flag;   
  if(strlength()==s1.strlength())
   {
        for(i=0;i<strlength();i++)  //converting all in one case.
          {
              if(s[i]>=65 && s[i]<=90)
                  s[i]=s[i]+32;
              if(s1.s[i]>=65 && s1.s[i]<=90)
                  s1.s[i]=s1.s[i]+32;                  
         } 
      for(i=0;i<strlength();i++)
        {
          if(s[i]==s1.s[i])
             flag=1;
          else
           {
             flag=0;   
             break;
           }          
        }
      if(flag==1)
        cout<<"String are equal.\n";
      else
        cout<<"String are not equal.\n";       
   }
  else
    cout<<"String are not equal.\n"; 

}
int main()
{
  int len,ch;
  string_op s1,s2,s3;
  cout<<"Enter the string :";
  s1.getdata();
  cout<<"------------------MENU--------------------";
  cout<<endl<<"1.Calculate length of string.\n2.Copy string.\n3.Concatinate strings.\n4.Reverse string.\n5.Check substring.\n6.Compare string.\n7.Case insensitive compare.\n-------------------------------\n";
  cout<<"Enter the choice :";
  cin>>ch;
  switch(ch)
  {
    case 1 :len=s1.strlength();
            cout<<"Length of string is : "<<len;
            break;
    case 2 :s2.copy(s1);
            cout<<"Copied string :";
            s2.display();
            break;
    case 3 :cout<<"Enter another string to concatinate :";
            cin.ignore();
            s2.getdata();
            s3.str_con(s1,s2);
            cout<<"Concatinated string is : ";
            s3.display();
            break;
    case 4 :s2.reverse(s1);
            cout<<"Reverse string is :";
            s2.display();
            break;
    case 5 :s1.substring();
            break;
    case 6 :cout<<"Enter another string to compare :";
            cin.ignore();
            s2.getdata();
            s2.compare(s1); 
            break;
    case 7 :cout<<"Enter another string to compare :";
            cin.ignore();
            s2.getdata();
            s2.icompare(s1); 
            break;            
    default : cout<<"Wrong choice.";
              break;                               
  }
  return 0;
}
