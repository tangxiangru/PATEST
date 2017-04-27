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
