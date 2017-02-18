#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char Input[100];
	int pos_T,pos_P,count_P,count_A,count_T;
	int i,j,n;
	scanf("%d\n",&n);
	for( i = 0 ; i < n ; i++ ){
		gets(Input);
		pos_T = 0;
		pos_P = 0;
		count_P = 0;
		count_A = 0;
		count_T = 0;
		for( j = 0 ; j < strlen(Input) ; j++ ){
			if( Input[j] == 'P' ){
				count_P++;
				pos_P = j ;
			}
			if( Input[j] == 'A' ){
				count_A++;
			}
			if( Input[j] == 'T' ){
				count_T++;
				pos_T = j ;
			}
		}
		if( //判断这个字符串是否只有P，A，T3个字母组成，条件1
			count_P + count_A + count_T != strlen(Input) ||
			//中间如果没有字符就不符合条件3
			pos_T-pos_P <= 1 ||
			//字符串中只能有一个P,T字符多出就不符合条件
			count_P > 1 || count_T > 1 ||
			// T右边的字符数是P左边的整数倍，倍数是和中间添加的A的数量和P左边的字符数量有关，条件3
			pos_P*(pos_T-pos_P-1) != strlen(Input)-pos_T-1
		 ){
		 	printf("NO\n");
		 }else{
		 	printf("YES\n");
		 }
	}
	return 0;
}
