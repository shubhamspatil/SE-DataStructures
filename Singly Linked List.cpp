#include<iostream>
#include<string>
using namespace std;
class node
{
  public :
   int prn;
   string name;
   node *next;
};
class sll 
{
   int count;
   node *head=NULL,*last;
   public :
    void create_sll();
    void display();
    void add_beg();
    void add_end();
    void add_bet();
    void del();
    void del_beg();
    void del_end();
    void reverse(node *);
    void concat(sll,sll);
    node * start()
       {
         return head;
       }
};
void sll :: create_sll()
{
  char ch;
  count=0;
  node *n1,*last_m;
  head = new node;
  last = new node;
  cout<<"Enter PRN number of president : ";
  cin>>head->prn;
  cout<<"Enter name of president : ";
  cin.ignore();
  getline(cin,head->name);
  head->next=NULL;
  cout<<"Enter PRN number of secretery : ";
  cin>>last->prn;
  cout<<"Enter name of secretery : ";
  cin.ignore();
  getline(cin,last->name);
  last->next=NULL;
  count+=2;
  do
   {
     n1=new node;
     cout<<"Enter PRN number of member : ";
     cin>>n1->prn;
     cout<<"Enter name of member : ";
     cin.ignore();
     getline(cin,n1->name);
     n1->next=NULL;
     if(head->next==NULL)
       {
         head->next=n1;
         n1->next=last;
         last_m=n1;
         count++;
       }
     else
       {
         last_m->next=n1;
         n1->next=last;
         last_m=n1;
         count++; 
       }
     cout<<"Any more members (y/n) : ";
     cin>>ch;  
     }while(ch=='y');
} 
void sll :: display()
{;
  node *temp;
  temp=head;
  cout<<"------------_PINNACALE CLUB_----------\n";
  cout<<"PRN       NAME \n";
  while(temp->next!=NULL)
    {
      if(temp==head)
        {
          cout<<temp->prn<<"    "<<temp->name<<" (President)\n";
          temp=temp->next;
        }
       else
        {
          cout<<temp->prn<<"    "<<temp->name<<"\n";
          temp=temp->next;
        }
    }
     cout<<temp->prn<<"    "<<temp->name<<" (Secretary)\n";
     cout<<"    ( Total members : "<<count<<" )\n";
   cout<<"-----------------------------------------\n";
} 
void sll :: add_beg()
{
  node *n1;
  n1=new node;
  cout<<"Enter PRN number of new president : ";
  cin>>n1->prn;
  cout<<"Enter name of new president : ";
  cin.ignore();
  getline(cin,n1->name);
  n1->next=head;
  head=n1;
  count++;
  display(); 
}
void sll :: add_end()
{
  node *n1,*temp;
  n1 = new node;
  cout<<"Enter PRN number of new secretary : ";
  cin>>n1->prn;
  cout<<"Enter name of new secretary : ";
  cin.ignore();
  getline(cin,n1->name);
  temp=head;
  while(temp->next != NULL)
    temp=temp->next;
  temp->next=n1;
  n1->next=NULL;
  count++;
  display();
}
void sll :: add_bet()
{
  node *n1,*temp;
  n1=new node;
  cout<<"Enter PRN number of new member : ";
  cin>>n1->prn;
  cout<<"Enter name of new member : ";
  cin.ignore();
  getline(cin,n1->name);
  n1->next=NULL;
  temp=head;
  while(temp->next->next != NULL)
      temp=temp->next;
   n1->next=temp->next;
   temp->next=n1;
   count++;
   display();
}
void sll :: del()
{
  node *n1,*temp,*temp1;
  int key;
  cout<<"Enter PRN number of member leaving the club : ";
  cin>>key;
  temp=head;
  while(temp->next!=NULL)
    {
       if((temp->next)->prn == key)
         {
            temp1=temp->next;
            temp->next=temp1->next;

            temp1->next=NULL;
            delete(temp1);     
         }
        else
          temp=temp->next; 
    }
    count--;
    display();
}
void sll :: del_beg()
{
  node *temp;
  temp=head;
  head=head->next;
  temp->next=NULL;
  delete(temp);
  count--;
  display();
}
void sll :: del_end()
{
    node *temp,*temp1;
    temp=head;
    while((temp->next)->next!=NULL)
      {
	temp=temp->next;
      }
    temp1=temp->next;
    temp->next=NULL;
    delete(temp1);
    count--;
    display();
}
void sll :: reverse(node *temp)
{
  if(temp==NULL)
   return;
  else
    {
      reverse(temp->next);
      cout<<temp->prn<<"    "<<temp->name<<"\n";
    }
}
void sll :: concat(sll s1,sll s2)
{
  node *temp;
  head = s1.head;
  temp=head;
  count=s1.count+s2.count;
  while(temp->next!=NULL)
     temp=temp->next;
  temp->next=s2.head;
  cout<<"New concatenated member list : \n";
  display();
}
int main()
{
  char c;
  int ch,k;
  sll s1,s2,s3;
  s1.create_sll();
  s1.display();
  do
  {
  cout<<"----------------MENU---------------\n";
  cout<<"1 : New president.\n2 : Add new member.\n3 : New secretery.\n4 : President resigned.\n5 : Member leaving.\n6 : Secretery resigned.\n7 : Reverse display(using recursion).\n8 : Concatenate operation.\n------------------------\n";
  cout<<"Enter you choice : ";  
  cin>>ch;
  switch(ch)
   {
     case 1 : s1.add_beg();
              break;
     case 2 : s1.add_bet();
              break;
     case 3 : s1.add_end();
              break;
     case 4 : s1.del_beg();
              break;
     case 5 : s1.del();
              break;
     case 6 : s1.del_end();
              break;
     case 7 : cout<<"List in reverse order :\n";
              s1.reverse(s1.start());
              break;
     case 8 : cout<<"For second list :\n";
              s2.create_sll();
              cout<<"President of new list is of division : "; 
              cin>>k;
              if(k==1)
                 s3.concat(s1,s2);
              else
                 s3.concat(s2,s1);
              break;
     default : cout<<"Wrong choice.\n";
   }
   cout<<"do you want to continue (y/n) : ";
   cin>>c;
   }while(c=='y');
  return 0;
}
