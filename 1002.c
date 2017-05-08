/*
输入一个整数 n 。
计算 n 的每一位的相加的和 sum
以拼音的方式顺位输出
#include <stdio.h>
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
走弯路了,因为n范围很大.. 小于 $10^{100}，不能用int
把输入的数字当做字符串，刚好strlen可以计算长度
定义一个100位的字符数组存储输入的“数据”，然后for循环各个位置相加，得到和。先确定和的长度，再挨个输出来，我这里定义了一个字符指针数组，根据每位的值直接调取即可。程序里是采用 先‘%’ 后‘/’，所以要倒过来输出。*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char input[100];
	char Num[][5]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	int split[5];
	int i,bitSum;
	bitSum = 0;
	gets(input);
	for( i = 0 ; i < strlen(input) ; i++)
		bitSum = bitSum + input[i]-'0'; //将字符ASCII转为Int之后位数相加
	i = 0;
	while(bitSum != 0 ){            //e.g 123 % 10 = 3 || 123 / 10 = 12
		split[i++] = bitSum % 10 ; //得到每一位数
		bitSum = bitSum / 10 ;	  //排除已经得到的位数
	}



	printf("%s",Num[split[i-1]]); //输出第一个数进行格式控制
	for(i = i - 2 ; i >= 0 ; i-- )
		printf(" %s",Num[split[i]]);
	return 0;
}
