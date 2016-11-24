#include<stdio.h>
void restoreup(int arr[],int i)
{
   int k=arr[i];
   int par=i/2;
   while(arr[par]<k && par>0)
   {
       arr[i]=arr[par];
       i=par;
       par=i/2;
   }
   arr[i]=k;
}
void restoredown(int arr[],int i,int n)
{
     int lchild=2*i,rchild=lchild+1;
     int num=arr[i];
     while(rchild<=n)
     {
        if(num>=arr[lchild] && num>=arr[rchild])
           {
              arr[i]=num;
              return;
           }
        else if(arr[lchild]>arr[rchild])
           {
               arr[i]=arr[lchild];
               i=lchild;
           }
        else
           {
              arr[i]=arr[rchild];
              i=rchild;
           }
        lchild=2*i;
        rchild=lchild+1;
     }
     if(lchild==n&&num<arr[lchild])
         {
            arr[i]=arr[lchild];
            i=lchild;
         }
     arr[i]=num;
}
int main()
{
   int n,i;
   printf("Enter the no of elements in an array\n");
   scanf("%d",&n);
   int a[n];
   a[0]=0;
   scanf("%d",&a[1]);
   for(i=2;i<=n;i++)
       {
           scanf("%d",&a[i]);
           restoreup(a,i);
       }
   /*for(i=1;i<=n;i++)
   {
      printf("%d  ",a[i]);
   }*/
   for(i=1;i<=n;)
   {    
        
        printf("%d  ",a[1]);
        a[1]=a[n];
        n=n-1;
        restoredown(a,1,n);
   }
    
}







