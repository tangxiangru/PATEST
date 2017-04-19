#include<stdio.h>
int main(){
    int score[100000],check[102]={0};
    int n,k,i,sr;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&score[i]);
        check[score[i]]++;
    }
    scanf("%d",&k);
    for(i=0;i<k;i++){
        scanf("%d",&sr);
        if(i!=k-1)printf("%d ",check[sr]);
        else printf("%d",check[sr]);
    }
    return 0;
}
