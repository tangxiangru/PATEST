/*#include <stdio.h>
int main()
{
  ing n,sum,num,weishu;
  scanf("%d\n", &num);
  n=num;
  while(n){
    weishu++;
    n/=10;
   }
  for (int i=0;i <weishu ;i++)
  {
    sum=num-sum%10;
  }
}
走弯路了*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char input[100];
	char pyNum[][5]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	int iSplit[5];
	int i,bitSum;
	bitSum = 0;
	gets(input);
	for( i = 0 ; i < strlen(input) ; i++)
		bitSum = bitSum + input[i]-'0'; //将字符ASCII转为Int之后位数相加
	i = 0;
	while(bitSum != 0 ){            //e.g 123 % 10 = 3 || 123 / 10 = 12
		iSplit[i++] = bitSum % 10 ; //得到每一位数
		bitSum = bitSum / 10 ;	  //排除已经得到的位数
	}
	printf("%s",pyNum[iSplit[i-1]]); //输出第一个数进行格式控制
	for(i = i - 2 ; i >= 0 ; i-- )
		printf(" %s",pyNum[iSplit[i]]);
	return 0;
}
