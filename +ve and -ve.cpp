#include<iostream>
using namespace std;
class node
{
  public :
   int data;
   node *next;
};
class list
{
  node *head=NULL;
  public :
   void create();
   void insert();
   void display();
   void neg_del();
   void separate(list &,list &);
   void sort_create();
   void sort();
   void merge(list ,list );
};
void list :: create()
{
  char ch;
  node *n1,*last;
  do
   {
     n1=new node;
     cout<<"Enter the data : ";
     cin>>n1->data;
     n1->next=NULL;
     if(head==NULL)
       {
          head = n1;
          last=n1;   
       }
     else
       {
         last->next=n1;
         last=n1;
       }
     cout<<"Do you want to continue (y/n) : ";
     cin>>ch;
   }while(ch=='y'); 
}
void list :: insert()
{ 
    int key;
	node *n1,*temp,*temp1;
	n1=new node();
	cout<<"Enter the data which u want to add in bet :";
	cin>>n1->data;
	cout<<"Enter the data after which you want to add a new node :";
	cin>>key;
	temp=head;
	while(temp!=NULL)
	{
		if(temp->data==key)
		{
			temp1=temp->next;
			n1->next=temp1;
			temp->next=n1;
	    }
   	 temp=temp->next;
   	} 
}
void list :: display()
{
  node *temp;
  temp=head;
  while(temp->next !=NULL)
   {
     cout<<"("<<temp->data<<") -> ";
     temp=temp->next;
   }  
    cout<<"("<<temp->data<<")"<<endl;
}
void list :: neg_del()
{
  node *t1,*t2,*t3,*temp;
  t1=head;
  while(t1->next!=NULL)
    {
      if(head->data<0)
       {
         temp=head;
         head=head->next;
         temp->next=NULL;
         delete(temp);
         t1=head;
       }
     else if(t1->next->data<0)
       {
         t2=t1->next;
         t1->next=t1->next->next;
         t2->next=NULL;
         delete(t2); 
       }
      else 
        t1=t1->next;
   } 
}
void list :: separate(list &pl,list &nl)
{
  node *nhead=NULL,*phead=NULL,*plast,*nlast,*temp;
  temp=head;
  while(temp!=NULL)
   {
     if(temp->data<0)
       {
           if(nhead==NULL)
             {
               nhead=temp;
               nlast=temp;        
             }
           else
             {
               nlast->next=temp;
               nlast=temp;
             }   
       }
     else
       {
           if(phead==NULL)
             {
               phead=temp;
               plast=temp;        
             }
           else
             {
               plast->next=temp;
               plast=temp;
             }           
       }
      temp=temp->next; 
   }
   plast->next=nlast->next=NULL;
   pl.head=phead;
   nl.head=nhead;
}
void list :: sort_create()
{
  char ch;
  node *n1,*prev,*last,*temp;
  do
   {
     n1=new node;
     cout<<"Enter data : ";
     cin>>n1->data;
     n1->next=NULL;
     if(head==NULL)
      {
        head=n1;
        last=n1;
      }
     else if(n1->data<head->data)
      {
        n1->next=head;
        head=n1;                                              
      } 
     else
      {
        temp=head;
        while(temp!=NULL && temp->data<=n1->data)
         {
           prev=temp;
           temp=temp->next;
         }
        prev->next=n1;
        n1->next=temp; 
      } 
     cout<<"Do you want to continue (y/n) : ";
     cin>>ch; 
   }while(ch=='y');
}
void list :: sort()
{
  int tdata;
  node *temp,*temp1;
  for(temp=head;temp->next!=NULL;temp=temp->next)
    {
      for(temp1=temp->next;temp1!=NULL;temp1=temp1->next)
        {
           if(temp->data > temp1->data)
             {
               tdata=temp->data;
               temp->data=temp1->data;
               temp1->data=tdata; 
             }
        }
    }
}
void list :: merge(list l1,list l2)
{
   node *temp,*temp1,*last;
   temp=l1.head;
   temp1=l2.head;
   while(temp!=NULL && temp1!=NULL)
    {
       if(temp->data < temp1->data)
         {
            if(head==NULL)
              {
                 head=temp;
                 last=temp;
              } 
            else
              {
                 last->next=temp;
                 last=temp;
              }
            temp=temp->next;
         }
       else
         {
            if(head==NULL)
              {
                 head=temp1;
                 last=temp1;
              } 
            else
              {
                 last->next=temp1;
                 last=temp1;
              }
            temp1=temp1->next;           
         }
    }
   while(temp!=NULL)
     {
       last->next=temp;
       last=temp;
       temp=temp->next;
     } 
   while(temp1!=NULL)
     {
       last->next=temp1;
       last=temp1;
       temp1=temp1->next; 
     }
     
}
int main()
{
  char c;
  int ch;
  list l1,l2,l3,l4;
  cout<<"For first linked list : \n";
  l1.create();
  cout<<"First linked list : ";
  l1.display();
  do
  {
    cout<<"-------------MENU-----------\n";
    cout<<"1 : Insert number in linked list.\n2 : Delete negative numbers.\n3 : Separate positive and negative numbers.\n4 : Merge two list.\n----------------\n";
    cout<<"Enter your choice : ";
    cin>>ch;
    switch(ch)
      {
         case 1 : l1.insert();
                  cout<<"New list : ";
                  l1.display();
                  break;
         case 2 : l1.neg_del();
                  cout<<"List without negative numbers : ";
                  l1.display();
                  break;
         case 3 : l1.separate(l2,l3);
                  cout<<"Positive linked list  : ";
                  l2.display();
                  cout<<"Negative linnked list : ";
                  l3.display();
                  break;
         case 4 : l1.sort();
                  l1.display();
                  cout<<"For second list : \n";
                  l2.sort_create();
                  cout<<"Second linked list : ";
                  l2.display();
                  l4.merge(l1,l2);
                  cout<<"New merged linked list : ";
                  l4.display();
                  break;
      }
     cout<<"Do you want to continue (y/n) : ";
     cin>>c;
   }while(c=='y');
  return 0;
}

