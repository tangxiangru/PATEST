/*use一个指针数组保存各个数据，why指针数组？因为单个元素的长度以及数据类型都不确定，输入的时候要先分配内存空间，然后输入各个元素，对每一个元素进行判断. 
判断有以下几点注意： 
1、首先是小数点后不能超过两位 
2、-号只能在第一位且只能有一个 
3、大小只能在[-1000,1000]之间 
算平均数的时候若只有一位数字，则要注意输出字符串的格式*/
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
    char *num[105];
    int N,count=0;
    double average=0;
    cin>>N;
    for(int i=0;i<N;i++){
            bool isNumber=true;     //判断是否为合法数字
            int point=0;            //监视小数点的个数
            int point_=0;           //监视小数点之后的位数
            num[i] = (char *)malloc(10*sizeof(char)); //申请空间
            cin>>num[i];
            int len=strlen(num[i]);
            double temp=atof(num[i]);//将字符串转换成数字，具体用法自行百度
            if(temp<-1000||temp>1000)   isNumber=false;
            for(int j=0;j<len;j++){  //对每一个元素的各个字符进行判断
                        if(point==1) point_++;  
                        if(num[i][j]=='-'&&j!=0){//如果含有-，则-只有一个且在第一位
                                        isNumber=false;
                                        break;
                                    }
                        if(num[i][j]!='.'){     
                                        if((num[i][j]<'0'||num[i][j]>'9')&&(num[i][j]!='-')){
                                                            isNumber=false;
                                                            break;
                                                        }       
                                    }else {             //如果是小数点
                                                    point++;
                                                }
                        if(point_>2||point>1){//如果小数点大于一个或者小数位数多余2
                                        isNumber=false;
                                        break;
                                    }
                    }
            if(!isNumber)
                cout<<"ERROR: "<<num[i]<<" is not a legal number"<<endl;
            else {
                        count++;
                        average+=temp;
                    }
        }
    if(count==1)
        printf("The average of 1 number is %.2lf",average);
    else if(count==0)
        printf("The average of 0 numbers is Undefined");
    else
        printf("The average of %d numbers is %.2lf",count,average/count);
    return 0;
}
