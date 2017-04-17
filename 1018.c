#include<stdio.h>
#include<stdlib.h>
int main(int atgc,char *argv[])
{
	int k;
	int JS=0,JP=0,JF=0;//甲胜，平，负的次数
	int YS=0,YP=0,YF=0;//乙胜，平，负的次数
	char J,Y;//甲乙出的手势C,J,B
	int JSCount[3]={0,0,0},YSCount[3]={0,0,0};
	//分别代表甲乙B,C,J,胜出的次数
	int i,Jmax=-1,Ymax=-1;
	int m,n;
	scanf("%d",&k);
	getchar();
	while(k--)
	{
		scanf("%c %c",&J,&Y);
		getchar();
		if(J=='C')
		{
			if(Y=='C')
			{
				JP++;
				YP++;
			}
			else if(Y=='J')
			{
				JS++;
				JSCount[1]++;
				YF++;
			}
			else
			{
				JF++;
				YS++;
				YSCount[0]++;
			}
		}
		else if(J=='J')
		{
			if(Y=='C')
			{
				JF++;
				YS++;
				YSCount[1]++;
			}
			else if(Y=='J')
			{
				JP++;
				YP++;
			}
			else
			{
				JS++;
				JSCount[2]++;
				YF++;
			}
		}
		else
		{
			if(Y=='C')
			{
				JS++;
				JSCount[0]++;
				YF++;
			}
			else if(Y=='J')
			{
				JF++;
				YS++;
				YSCount[2]++;
			}
			else
			{
				JP++;
				YP++;
			}
		}
	}
	for(i=0;i<3;i++)
	{
		if(JSCount[i]>Jmax)
		{
			Jmax=JSCount[i];
			m=i;
		}
		if(YSCount[i]>Ymax)
		{
			Ymax=YSCount[i];
			n=i;
		}
	}
	if(m==0)
		J='B';
	else if(m==1)
		J='C';
	else
		J='J';
	if(n==0)
		Y='B';
	else if(n==1)
		Y='C';
	else
		Y='J';
	printf("%d %d %d\n",JS,JP,JF);
	printf("%d %d %d\n",YS,YP,YF);
	printf("%c %c\n",J,Y);

	return 0;
}
