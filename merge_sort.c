#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int a[MAX];
int b[MAX];
void merge(int low,int mid,int high)
{
      int l1,l2,i;
      for(l1=low,l2=mid+1,i=low;l1<=mid && l2<=high;i++)
           {
                 if(a[l1]<=a[l2])
                     b[i]=a[l1++];
                 else
                     b[i]=a[l2++];
           }
      while(l1<=mid)
         {
            b[i++]=a[l1++];
         }
      while(l2<=high)
         {
            b[i++]=a[l2++];
         }
      for(i=low;i<=high;i++)
          {
             a[i]=b[i];
          }
}
void sort(int low,int high)
{
    if(low<high)
       {
           int mid;
           mid=(low+high)/2;
           sort(low,mid);
           sort(mid+1,high);
           merge(low,mid,high);
       }
    else
       return;
}
int main()
{ 
   int i,n;
   printf("Enter the value of n\n");
   scanf("%d",&n);
   for(i=0;i<n;i++)
       {
           scanf("%d",&a[i]);
       }
   printf("List before sorting\n");
   
   for(i = 0; i < n; i++)
      printf("%d ", a[i]);

   sort(0, n-1);

   printf("\nList after sorting\n");
   
   for(i = 0; i < n; i++)
      printf("%d ", a[i]);
}



