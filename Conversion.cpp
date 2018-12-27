#include<iostream>
#include<string.h>
using namespace std;
class stack
{
  int TOP;
  char st[20],exp[20];
  public :
    stack()
      {
       TOP=-1;
      }        
    void push(char);
    char pop();
    void infix_to_postfix();
    void infix_to_prefix();
    int precedence(char);
};
class to_infix
{
   char stack[20][10],exp[20];
   int TOP;
   public : 
     to_infix()
       {
         TOP=-1;
       }
     void postfix_to_infix();
     void prefix_to_infix();
     void postfix_to_prefix();
     void prefix_to_postfix();
};
void stack :: push(char a)
{ 
  if(TOP<19)
   {
     TOP++;
     st[TOP]=a;
   }
  else
    cout<<"Stack is Full.";   
}
char stack :: pop()
{
  if(TOP>=0)
    {
      char d;
      d=st[TOP];
      TOP--;
      return d;
    }
  else
    cout<<"Stack is empty.";
}
void stack :: infix_to_postfix()
{
  int i,k=0;
  char post[20],ch;
  cout<<"Enter the infix expression : ";
  cin>>exp;
  for(i=0;exp[i]!='\0';i++)
    {
      if(isalpha(exp[i])==1 || isdigit(exp[i]))   
        {
          post[k]=exp[i];
          k++;
        }
      else if(exp[i]=='(')
        push('(');
      else if(exp[i]==')')
        {
          while((ch=pop())!='(')
           {
             post[k]=ch;
             k++;
           }
        } 
      else
       {
         while(precedence(st[TOP])>= precedence(exp[i])) 
          {
            post[k]=pop();
            k++;
          }  
          push(exp[i]);
       }     
    }  
	while(TOP>=0)
	{
	  post[k]=pop();
	  k++;
	}
	post[k]='\0';
	cout<<"Postfix conversion : "<<post<<"\n";
}
int stack :: precedence(char c)
{
   if(c == '(')
      return 0;
   if(c == '+' || c == '-')
      return 1;
   if(c == '*' || c == '/')
      return 2;
   if(c == '^') 
      return 3;
}
void stack :: infix_to_prefix()
{
  int i,k;
  char pre[20],ch;
  cout<<"Enter the infix expression : ";
  cin>>exp;
  k=strlen(exp)-1;
  pre[k+1]='\0';
  for(i=strlen(exp)-1;i>=0;i--)
   {
      if(isalpha(exp[i])==1 || isdigit(exp[i]))  
        {
          pre[k]=exp[i];
          k--;
        }
      else if(exp[i]=='(')
        push('(');
      else if(exp[i]==')')
        {
          while((ch=pop())!='(')
           {
             pre[k]=ch;
             k--;
           }
        } 
      else
       {
         while(precedence(st[TOP])>=precedence(exp[i]))   
          {
            pre[k]=pop();
            k--;
          }  
          push(exp[i]);
       }     
    }  
	while(TOP>=0)
	{
	  pre[k]=pop();
	  k--;
	}
	cout<<"Prefix conversion : "<<pre<<"\n";
}
void to_infix :: postfix_to_infix()
{
  int l,i;
  char st[20],str1[20];
  cout<<"Enter the postfix expression : ";
  cin>>exp;
  for(i=0;exp[i]!='\0';i++)
    {
      if(isalpha(exp[i]) || isdigit(exp[i]))  
        {
          st[0]=exp[i];
          st[1]='\0';
          TOP++;
          strcpy(stack[TOP],st);
        }
      else
        {
          str1[0]='(';
          str1[1]='\0';
          strcat(str1,stack[TOP-1]);
          l=strlen(str1);
          str1[l]=exp[i];
          str1[l+1]='\0';
          strcat(str1,stack[TOP]);
          l=strlen(str1);
          str1[l]=')';
          str1[l+1]='\0';
          TOP--;
          TOP--;
          TOP++;
          strcpy(stack[TOP],str1);
        }
    }
  cout<<"Infix expression is : "<<stack[TOP]<<endl;
}
void to_infix :: prefix_to_infix()
{
  int l,i,k=0;
  char st[20],str1[20],temp[20];
  cout<<"Enter the prefix expression : ";
  cin>>temp;
  for(i=strlen(temp)-1;i>=0;i--)
    {
      exp[k]=temp[i];
      k++;
    }
   exp[k]='\0';
  for(i=0;exp[i]!='\0';i++)
    {
      if(isalpha(exp[i]) || isdigit(exp[i]))  
        {
          st[0]=exp[i];
          st[1]='\0';
          TOP++;
          strcpy(stack[TOP],st);
        }
      else
        {
          str1[0]='(';
          str1[1]='\0';
          strcat(str1,stack[TOP]);
          l=strlen(str1);
          str1[l]=exp[i];
          str1[l+1]='\0';
          strcat(str1,stack[TOP-1]);
          l=strlen(str1);
          str1[l]=')';
          str1[l+1]='\0';
          TOP--;
          TOP--;
          TOP++;
          strcpy(stack[TOP],str1);
        }
    }
  cout<<"Infix expression is : "<<stack[TOP]<<endl;
}
void to_infix :: postfix_to_prefix()
{
  int l,i;
  char st[20],str1[20],temp[20];
  cout<<"Enter the postfix expression : ";
  cin>>exp;
  for(i=0;exp[i]!='\0';i++)
    {
      if(isalpha(exp[i]) || isdigit(exp[i]))  
        {
          st[0]=exp[i];
          st[1]='\0';
          TOP++;
          strcpy(stack[TOP],st);
        }
      else
        {
          str1[0]='\0';
          strcat(str1,stack[TOP-1]);
          strcat(str1,stack[TOP]);
          temp[0]=exp[i];
          temp[1]='\0';
          strcat(temp,str1);
          TOP--;
          TOP--;
          TOP++;
          strcpy(stack[TOP],temp);
        }
    }
  cout<<"Prefix expression is : "<<stack[TOP]<<endl;
}
void to_infix :: prefix_to_postfix()
{
  int l,i,k=0;
  char st[20],str1[20],temp[20],temp1[20];
  cout<<"Enter the prefix expression : ";
  cin>>temp;
  for(i=strlen(temp)-1;i>=0;i--)
    {
      exp[k]=temp[i];
      k++;
    }
   exp[k]='\0'; 
  for(i=0;exp[i]!='\0';i++)
    {
      if(isalpha(exp[i]) || isdigit(exp[i]))  
        {
          st[0]=exp[i];
          st[1]='\0';
          TOP++;
          strcpy(stack[TOP],st);
        }
      else
        {
          str1[0]='\0';
          strcat(str1,stack[TOP]);
          strcat(str1,stack[TOP-1]);
          temp1[0]=exp[i];
          temp1[1]='\0';
          strcat(str1,temp1);
          TOP--;
          TOP--;
          TOP++;
          strcpy(stack[TOP],str1);
        }
    }
  cout<<"Postfix expression is : "<<stack[TOP]<<endl;
}
int main()
{
  stack s;
  to_infix p;
 // s.infix_to_postfix();
  //s.infix_to_prefix();
 // p.postfix_to_infix();
  p.prefix_to_infix();
//  p.postfix_to_prefix();
  p.prefix_to_postfix();
  return 0;
}
