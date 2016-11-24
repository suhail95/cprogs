/*various operations on linked list as ask by a company*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
   int info;
   struct node *link;
}*start=NULL;
struct node *addatbeg(struct node *start,int data)
{
   struct node *tmp;
   tmp=(struct node *)malloc(sizeof(struct node));
   tmp->info=data;
   tmp->link=start;
   start=tmp;
   return start;
}
struct node *addatend(struct node *start,int data)
{
   struct node *p,*tmp;
   p=start;
   tmp=(struct node *)malloc(sizeof(struct node));
   tmp->info=data;
   tmp->link=NULL;
   while(p->link!=NULL)
     {
        p=p->link;
     }
   p->link=tmp;
   return start;
}
struct node *create_list(struct node * start)
{
    int i,n,data;
    printf("Enter the no of nodes you want to insert\n");
    scanf("%d",&n);
    printf("Enter the element you want to insert\n");
    scanf("%d",&data);
    start=addatbeg(start,data);
    for(i=2;i<=n;i++)
    {
       printf("Enter the element you want to insert\n");
       scanf("%d",&data); 
       start=addatend(start,data);
    }
    return start;
}
void display(struct node *start)
{
   struct node *p;
   if(start==NULL)
   {
       printf("List is Empty\n");
       return;
   }
   p=start;
   printf("List is :\n");
   while(p!=NULL)
     {
        printf("%d ",p->info);
        p=p->link;
     }
     printf("\n\n");
}
void mid_of_list(struct node *start)
{
    struct node *p,*q;
    p=start;
    q=start;
    while(p->link!=NULL)
      {
          q=q->link;
          p=p->link->link;
      }
    printf("\n%d \n",q->info);  
}
struct node *reverse(struct node *start)
{
   struct node *prev,*ptr,*next;
   prev=NULL;
   ptr=start;
   while(ptr!=NULL)
      {
          next=ptr->link;
          ptr->link=prev;
          prev=ptr;
          ptr=next;
      }
   start=prev;
   return start;
}
struct node *remove_dupl(struct node *start)
{
    struct node *ptr,*q;
    ptr=start;
    while(ptr!=NULL)
      {
         q=ptr->link;
         while(q!=NULL)
           {
              if(q->info==ptr->info)
                {
                   q=q->link;
                }
              else{
                break;
              }
           }
           ptr->link=q;
           ptr=ptr->link;
      }
    return start;
}
struct node *delete_mid(struct node *start)
{
   struct node *p,*q,*r,*tmp;
   r=NULL;
   p=start;
   q=start;
    while(p->link!=NULL)
      {
          r=q;
          q=q->link;
          p=p->link->link;
      }
    tmp=q;
    r->link=q->link;
    free(tmp);
    return start;
}
void pairwise_swap(struct node *start)
{
    struct node *ptr,*q;
    int temp;
    ptr=start;
    q=ptr->link;
    while(ptr!=NULL && q!=NULL)
       {
          temp=ptr->info;
          ptr->info=q->info;
          q->info=temp;
          ptr=q->link;
          if(ptr!=NULL)
            {
               q=ptr->link;
            }
       }
}
struct node *segregate_e_o(struct node *start)
{
   struct node *start1=NULL,*start2=NULL,*ptr,*temp1,*temp2;
   ptr=start;
   while(ptr!=NULL)
      {
          if(ptr->info%2==1)
            {
               if(start1==NULL)
                  {
                       start1=ptr;
                       temp1=ptr;
                  }
               else
                  {
                      temp1->link=ptr;
                      temp1=ptr;
                  }
            }
          if(ptr->info%2==0)
            {
               if(start2==NULL)
                  {
                       start2=ptr;
                       temp2=ptr;
                  }
               else
                  {
                      temp2->link=ptr;
                      temp2=ptr;
                  }
            }
          ptr=ptr->link;  
      }
   temp1->link=NULL;
   temp2->link=start1;
   start=start2;
   return start;
}
int main()
{
  
  int choice,data,item;
  while(1)
  {
     printf("1.Create_list\n");
     printf("2.Display\n");
     printf("3.Mid pos of linked list\n");
     printf("4.insert at beginning\n");
     printf("5.insert at End\n");
     printf("6.reverse\n");
     printf("7.remove duplicate element from sorted linke list\n");
     printf("8.delete middle element of a linked list\n");
     printf("9.pairwise swaping of elements\n");
     printf("10.segregate even and odd nodes\n");
     printf("11.exit\n");
     printf("Enter your Choice\n");
     scanf("%d",&choice);
     switch(choice)
     {
        case 1:
           start=create_list(start);
           break;
        case 2:
           display(start);
           break;
        case 3:
           mid_of_list(start);
           break;
        case 4:
           printf("Enter the element you want to insert\n");
           scanf("%d",&data);
           start=addatbeg(start,data);
           break;
        case 5:
           printf("Enter the element you want to insert\n");
           scanf("%d",&data); 
           start=addatend(start,data);
           break;
        case 6:
           start=reverse(start);
           break;
        case 7:
           start=remove_dupl(start);
           break;
        case 8:
           start=delete_mid(start);
           break;
        case 9:
           pairwise_swap(start);
           break;
        case 10:
           start=segregate_e_o(start);
           break;
        case 11:
           exit(1);
     }   
  }
  
}











