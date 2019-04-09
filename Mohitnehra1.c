// made by mohit nehra   11701059  btech. 2nd year
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
int main()
{
int at[10],bt[10],rt[10],endTime,i,smallest;                                                    // TAKING ALL THE INPUTS SUCH AS ARRIVAL TIME ,BURST TIME,COMPLETION TIME....
int remain=0,n,time,sum_wait=0,sum_turnaround=0;
printf("===================Welcome To The Scheduler Design Software================\n");
printf("Please Read the following Details and Enter The Details Carefully \n\n");
printf("Enter no of Processes : ");
scanf("%d",&n);
for(i=0;i<n;i++)                                                                               //LOOP FOR THE EXCUTION OF NO OF PROCESS
{	
printf("Enter Arrival time for Process P%d : ",i+1);
scanf("%d",&at[i]);
printf("Enter Burst time for Process P%d : ",i+1);
scanf("%d",&bt[i]);
rt[i]=bt[i];
}
printf("\n\nProcess\t|Turnaround Time| Waiting Time\n\n");
rt[9]=9999;
for(time=0;remain!=n;time++)
{
smallest=9;
for(i=0;i<n;i++)
{
if(at[i]<=time && rt[i]<rt[smallest] && rt[i]>0)                                             // CONDITION FOR THE SHORTEST REMANING JOB
{
smallest=i;
}}
        
rt[smallest]--;
if(rt[smallest]==0)
{
remain++;
endTime=time+1;
printf("\nP[%d]\t|\t%d\t|\t%d",smallest+1,endTime-at[smallest],endTime-bt[smallest]-at[smallest]);                 //PRINTING ALL THE PROCESS WITH THEIR RESPECTIVE TIMES IN A FORM OF TABLE
sum_wait+=endTime-bt[smallest]-at[smallest];                                                                       //WAITING TIME
sum_turnaround+=endTime-at[smallest];                                                                              //TURNAROUN TIME
}
}
printf("\n\nAverage waiting time = %f\n",sum_wait*1.0/n);                                                         //AVG WAITING TIME.....
printf("Average Turnaround time = %f",sum_turnaround*1.0/5);                                                      //AVG TURNAROUN TIME....
return 0;
}


