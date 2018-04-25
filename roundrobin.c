#include<stdio.h>
#include<conio.h>
struct process
{
	int btime;
	int wtime;
	int id;
	int pri;
	int atime;
	int rtime;
	int tatime;
	int exe;
	int ctime;
}s[10];
struct gant
{
	int t;
	int ids;
}w1[200];
struct process readyq[10];
struct process p_idle;
int t=0,rem,g=0,n;
struct process temp;
struct process temp1;
struct process protemp;
struct process protemp1;
int g1=0;
main()
{
	p_idle.atime=0;
	p_idle.btime=0;
	p_idle.id=0;
	p_idle.pri=0;
	p_idle.rtime=p_idle.btime;
	readyq[0]=p_idle;
	int u,i,j,k,l,o,m,size=0,quant,istart=0;
	printf("\nEnter the Total number of process:");
	scanf("%d",&n);
	printf("\nEnter the time quantum:");
	scanf("%d",&quant);
	rem=n;
	for(i=0;i<n;i++)
	{
		s[i].id=i+1;
		printf("\nEnter arrival time of p%d:",i+1);
		scanf("%d",&s[i].atime);
		printf("\nEnter burst time of p%d:",i+1);
		scanf("%d",&s[i].btime);
		s[i].rtime=s[i].btime;
		printf("Enter the priority of the process p%d:",i+1);
		scanf("%d",&s[i].pri);
		s[i].exe=0;
	}
	 printf("\nGanttChart:");
	 while(rem!=0)
	 {
	 	for(i=0;i<n;i++)
	 	{
	 	 if(s[i].atime==t&&s[i].exe==0)
	 	 {
	 		readyq[size]=s[i];
	 		s[i].exe=1;
	 		size++;
	 		for(j=0;j<size-1;j++)
		   {
		    for(k=0;k<size-j-1;k++)
		 	{
		 		if(readyq[k].pri<readyq[k+1].pri)
		 		{
		 			temp=readyq[k];
		 			readyq[k]=readyq[k+1];
		 			readyq[k+1]=temp;
				}
			}
		   }
		 }
	   }
	   if(t>0&&size==0)
	   {
	   	w1[g1].ids=p_idle.id;
	   	w1[g1].t=t;
	   	//printf("P%d  ",p_idle.id);
	   	p_idle.btime++;
		g1++;
	   }
	   else
	   {
	    if(t%quant==0&&readyq[1].rtime!=0&&t!=0)
	    {
	    	protemp=readyq[0];
	    	int p;
	    	for(p=1;p<size;p++)
	    	{
	    		readyq[p-1]=readyq[p];
			}
			readyq[size-1]=protemp;
	    }
	     if(readyq[0].rtime!=0)
		 {
		 	w1[g1].ids=readyq[0].id;
		 	w1[g1].t=t;
		 	//printf("P%d  ",readyq[0].id);
		 	readyq[0].rtime--;
		 	g1++;
		 }
		 if(readyq[0].rtime==0&&t!=0)
		 {
		 	int y;
		 	for(y=0;y<n;y++)
		 	{
		 		if(s[y].id==readyq[0].id)
		 		{
		 			s[y].ctime=t+1;
		 			break;
				}
			}
		 	int q;
		 	for(q=1;q<size;q++)
		 	{
		 		readyq[q-1]=readyq[q];
			}
			 size--;
		 	rem--;
		 }
	}
		 t++;
    }
    int i1;
    int j1;
    	i1=0;
    	for(j1=0;j1<g1;j1++)
    	{
    		if(w1[i1].ids!=w1[j1].ids)
    		{
    			printf("%d\t",w1[i1].t);
    			printf("P%d ",w1[i1].ids);
    			i1=j1;
			}
		}
		printf("%d",t);
    int z;
    for(z=0;z<n;z++)
    {
    	printf("\nProcess P%d:\n",s[z].id);
    	s[z].wtime=s[z].ctime-s[z].btime-s[z].atime;
    	s[z].tatime=s[z].wtime+s[z].btime;
    	printf("\n\t\tWaiting time:%d\n",s[z].wtime);
    	printf("\n\t\tTurnAroundTime:%d\n",s[z].tatime);
    }
    float cpur;
    float time=(float)t;
    float jk=(float)p_idle.btime;
    cpur=((time-jk)/time*100);
    printf("\nCPU Utilisation rate is:");
    printf("%f",cpur);
}
