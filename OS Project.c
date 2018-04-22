#include<stdio.h>
int main()
{
  int t,b[10],a[10],sum=0,smallest,num,i;
  int wt=0,tt=0;
  printf("Number of Processes : ");
  scanf("%d",&num);
  for(i=0;i<num;i++)
  {
    printf("Arrival time for process P%d : ",i+1);
    scanf("%d",&a[i]);
    printf("Burst time for process P%d : ",i+1);
    scanf("%d",&b[i]);
    sum+=b[i];
  }
  b[9]=9999;
  for(t=0;t<sum;)
  {
    smallest=9;
    for(i=0;i<num;i++)
    {
      if(a[i]<=t && b[i]>0 && b[i]<b[smallest])
        smallest=i;
    }
    printf("P[%d]\t|\t%d\t|\t%d\n",smallest+1,t+b[smallest]-a[smallest],t-a[smallest]);
    tt+=t+b[smallest]-a[smallest];
    wt+=t-a[smallest];
    t+=b[smallest];
    b[smallest]=0;
  }
  printf("\n\n Average waiting time = %f",wt*1.0/num);
  printf("\n\n Average turnaround time = %f",tt*1.0/num);
  return 0;
}
