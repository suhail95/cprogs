#include<stdio.h>
#include<stdlib.h>
#define v 9
int adj[v][v]={{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
int sptset[100];
int distance[100];
#define TEMP 0
#define PERM 1
#define infinity 9999
#define NIL -1
int min_temp()
{
   int i,min=infinity,min_index=NIL;
   for(i=0;i<v;i++)
      {
         if(sptset[i]==TEMP && distance[i]<min)
            {
               min=distance[i];
               min_index=i;
            }
      }
   return min_index;
}
void dijkstra(int s)
{
    int count=0,i,current;
    distance[s]=0;
    while(count<v)
       {
           current=min_temp();
           if(current==NIL)
              {
                 break;
              }
           sptset[current]=PERM;
           count++;
           for(i=0;i<v;i++)
              {
                  if(adj[current][i]!=0&&sptset[i]==TEMP&&distance[current]+adj[current][i]<distance[i])
                     {   
                         
                         distance[i]=distance[current]+adj[current][i];
                     }
              }       
       }
}
int main()
{
   int i,j;
   for(i=0;i<v;i++)
      { 
         sptset[i]=TEMP; 
      }
   for(i=0;i<v;i++)
      { 
         distance[i]=infinity; 
      }
   dijkstra(0);
   for(i=0;i<v;i++)
      {
         printf("%d ",distance[i]);
      }
}



