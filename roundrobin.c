#include<stdio.h>
#include<conio.h>
struct process
{
	int bt;
	int wt;
	int id;
	int pri;
	int at;
	int rt;
	int tat;
	int exe;
	int ct;
}s[10];
struct process ready[10];
struct process p_idle;
int t=0,r,n;
struct process temp;
struct process temp1;
struct process protemp;
struct process protemp1;
main()
{
	p_idle.at=0;
	p_idle.bt=10000;
	p_idle.id=0;
	p_idle.pri=0;
	p_idle.rt=p_idle.bt;
	ready[0]=p_idle;
	int u,i,j,k,l,o,m,size=0,quant=10,istart=0;
	printf("\nEnter the number of process:");
	scanf("%d",&n);
	r=n;
	for(i=0;i<n;i++)
	{
		s[i].id=i+1;
		printf("\nEnter the arrival time of process p%d:",i+1);
		scanf("%d",&s[i].at);
		printf("\nEnter the burst time of the process p%d:",i+1);
		scanf("%d",&s[i].bt);
		s[i].rt=s[i].bt;
		printf("Enter the priority of the process p%d:",i+1);
		scanf("%d",&s[i].pri);
		s[i].exe=0;
	}
	 printf("\nGanttChart for every second is:");
	 while(r!=0)
	 {
	 	for(i=0;i<n;i++)
	 	{
	 	 if(s[i].at==t&&s[i].exe==0)
	 	 {
	 		ready[size].id=s[i].id;
	 		ready[size].at=s[i].at;
	 		ready[size].bt=s[i].bt;
	 		ready[size].pri=s[i].pri;
	 		ready[size].rt=s[i].rt;
	 		ready[size].wt=s[i].wt;
	 		s[i].exe=1;
	 		size++;
	 		istart=1;
		 }
		 for(j=0;j<size-1;j++)
		 {
		 	for(k=0;k<j-size-1;k++)
		 	{
		 		if(ready[k].pri<ready[k+1].pri)
		 		{
		 			temp=ready[k];
		 			ready[k]=ready[k+1];
		 			ready[k+1]=temp;
				}
			}
		 }
	   }
	   if(t>0&&size==0)
	   {
	   	printf("P%d  ",p_idle.id);
	   }
	   else
	   {
	    if(t%10==0&&ready[1].rt!=0)
	    {
	    	protemp=ready[0];
	    	int p;
	    	for(p=1;p<size;p++)
	    	{
	    		ready[p-1]=ready[p];
			}
			ready[size-1]=protemp;
	    }
	     if(ready[0].rt!=0)
		 {
		 	printf("P%d  ",ready[0].id);
		 	ready[0].rt--;
		 }
		 if(ready[0].rt==0&&t!=0)
		 {
		 	int y;
		 	for(y=0;y<n;y++)
		 	{
		 		if(s[y].id==ready[0].id)
		 		{
		 			s[y].ct=t+1;
		 			break;
				}
			}
		 	int q;
		 	for(q=1;q<size;q++)
		 	{
		 		ready[q-1]=ready[q];
			}
			 size--;
		 	r--;
		 }
	}
		 t++;
    }
    int z;
    for(z=0;z<n;z++)
    {
    	s[z].wt=s[z].ct-s[z].bt-s[z].at;
    	s[z].tat=s[z].wt+s[z].bt;
    	printf("\nWaiting time:%d\n",s[z].wt);
    	printf("\nTurnAroundTime:%d\n",s[z].tat);
    }
}
