//复数乘法：（R1*e的（p1*i）次方）*（R2*e的（p2*i）次方=（R1*R2）*e的（i*（p1+p2））次方
//实部=r1*r2*(cos(p1+p2)),虚部=r1*r2*sin(p1+p2);注意应注实部虚部有理数部分<0.01的情况。因为比如-0.002保留两位是-0.0而不是0.0
#define PI 3.14159
#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double r1, p1, r2, p2;
    scanf("%lf %lf %lf %lf", &r1, &p1, &r2, &p2);
    double a = r1 * r2 * cos(p1 + p2);
    double b = r1 * r2 * sin(p1 + p2);
    if(a > -0.005 && a < 0.005){ //a = 0
        printf("0.00");
    }
    else{
        printf("%.2f", a);
    }
    if(b > -0.005 && b < 0.005){ //b = 0
        printf("+0.00i\n"); //这里别忘记+0.00i好坑
    }
    else if(b > 0){
        printf("+%.2fi\n", b);
    }
    else if(b < 0){
        printf("%.2fi\n", b);
    }
    return 0;
}
