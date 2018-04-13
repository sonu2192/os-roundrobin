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
}s[10];
struct process ready[10];
int t=0,r,n;
struct process temp;
struct process protemp;
main()
{
	int i,j,k,l,o,m,size=0,quant=10,istart=0;
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
		 	printf("%d",ready[0].id);
		 	ready[0].rt--;
		 }
		 if(ready[0].rt==0&&t!=0)
		 {
		 	r--;
		 }
		 t++;
    }
    int z;
    for(z=0;z<n;z++)
    {
    	printf("\n%d\n",t);
    }
}
