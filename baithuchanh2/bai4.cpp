#include <stdio.h>
#include <stdlib.h>
double TienGui(double m,float a,int n);
int main(){
    long m;
    float a;
    int n;
    printf("Nhap so tien ban dau, ti le lai suat, so nam:");
    scanf("%ld%f%d",&m,&a,&n);
    double total=TienGui(m,a,n);
    printf("%.2lf",total);
return 0;
}
double TienGui(double m,float a,int n){
    if (n==0)
    {
        return m;
    }
    return TienGui(m,a,n-1)*(1+a);
}

