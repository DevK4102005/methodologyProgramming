/*2.2. Viết hàm tìm số hạng thứ n của dãy Fibonacci bằng phương pháp đệ quy và không đệ quy. Biết dãy số Fibonacci được định nghĩa như sau:
𝑓1=𝑓2=1
𝑓𝑛=𝑓𝑛−1+𝑓𝑛−2,𝑛≥2*/
#include <stdio.h>
#include <stdio.h>
int TimFibo(int a[],int n);
int TimFiboDeQuy(int n);
int main(){
    int n;
    int a[100];
    printf("Nhap n:");
    scanf("%d",&n);
printf("%d",TimFibo(a,n));
return 0;
}
int TimFibo(int a[100],int n){
    if (n==1||n==2)
    {
        return 1;
    }
    a[0]=0;
    a[1]=1;
    for (int i = 2; i<=n; i++){
    a[i]=a[i-1]+a[i-2];
    }
    return a[n];
}
int TimFiboDeQuy(int n){
    if (n==1||n==2)
    {
        return 1;
    }
    else{
        return TimFiboDeQuy(n-1)+TimFiboDeQuy(n-2);
    }
}
