#include<stdio.h> 
#include<stdlib.h> 
#include <unistd.h>

int main() {
int i,j,noframes,x,x1=10,x2; 
for(i=0;i<200;i++) 
rand(); 
noframes=rand()/200; 
i=1; 
j=1; 
noframes=noframes/8; 
printf("\n number of frames is %d",noframes); 
while(noframes>0) 
{  
printf("\n sending frame %d",i); 
srand(x1++); 
x=rand()%10; 
if(x%2==0) 
{ 
for(x2=1;x2<2;x2++) 
{printf("waiting for %d seconds\n",x2); 
sleep(x2); 
} 
printf("\nack for frame %d",j); 
noframes-=1;
i++; 
j++; 
printf("\nend of stop and wait protocol"); 
return 0;
}}}