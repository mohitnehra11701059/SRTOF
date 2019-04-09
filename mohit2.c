// SjF preemption made by mohit nehra 11701059

#include<stdio.h>
int n;
struct process
{

int p_no;

int at,bt,ct,wt,tat,p;                           // arrivat time .burst time,waiting time,turn around time,process

int flag;
 }p_list[100];
 void Sorting()                                 //function for sorting shortest job 
 {
struct process p;

int i, j;

for(i=0;i<n-1;i++)

{

for(j=i+1;j<n;j++)

{

if(p_list[i].at > p_list[j].at)

{

p = p_list[i];

p_list[i] = p_list[j];

p_list[j] = p;

}

}

}
 }
 int main()
 {

int i,t=0,b_t=0,peak;

int a[10];

float wt = 0, tat = 0, avg_wt=0, avg_tat=0;

printf("enter the no. of processes: ");

scanf("%d",&n);

for(i = 0; i < n; i++)                                                              //assigning the values of at and bt for no of process then checking through sorting funtion

{

p_list[i].p_no = i+1;

printf("\nEnter Details For P%d process:-\n", p_list[i].p_no);
printf("Enter Arrival Time: ");
scanf("%d", &p_list[i].at );
printf("Enter Burst Time: ");
scanf("%d", &p_list[i].bt);
p_list[i].flag = 0;
b_t = b_t + p_list[i].bt;
}
Sorting();
for( i=0;i<n;i++)
{
a[i]=p_list[i].bt;
}
p_list[9].bt = 9999;
for(t = p_list[0].at; t <= b_t+1;)
{
peak = 9;
for(i=0;i<n;i++)
{
if(p_list[i].at <= t && p_list[i].bt < p_list[peak].bt && p_list[i].flag != 1)
{
peak = i;
}
if(p_list[peak].bt==0 && p_list[i].flag != 1)
{
p_list[i].flag = 1;
p_list[peak].ct=t;p_list[peak].bt=9999;
printf("P%d completes in %d\n",p_list[i].p_no,p_list[peak].ct);
}
}
t++;
(p_list[peak].bt)--;
}
for(i=0;i<n;i++)
{
p_list[i].tat=(p_list[i].ct)-(p_list[i].at);                                            //calculating tat and wat and avg wat and avg tat
avg_tat=avg_tat+p_list[i].tat;
p_list[i].wt=((p_list[i].tat)-a[i]);
avg_wt=avg_wt+p_list[i].wt;
}
printf("PNO\tAT\tCT\tTA\tWTt\n");
for(i=0;i<n;i++)
{
printf("P%d\t%d\t%d\t%d\t%d\n",p_list[i].p_no,p_list[i].at,p_list[i].ct,p_list[i].tat                      //printing all the calculated values of time......
,p_list[i].wt);
 }
printf("Average Turn around Time: %f\t\n\n",avg_tat);
printf("Average Waiting Time :\t %f\t\n",avg_wt);
}
