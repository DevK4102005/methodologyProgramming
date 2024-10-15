#include <stdio.h>
#include <stdlib.h>
int NhanBanViTrung(int n,int k,int h);
int main(){
    int n,h,k;
    printf("Nhap so luong VT ban dau, so lan nhan len, so gio:");
    scanf("%d%d%d",&n,&k,&h);
    printf("%d",NhanBanViTrung(n,k,h));
    return 0;
}
int NhanBanViTrung(int n,int k,int h){
//n:So vi trung ban dau
//k:So lan vi trung nhan len
//h:So gio
    if (h==0)
    {
        return n;
    }
    //s=n*k^h
    return k*NhanBanViTrung(n,k,h-1);
}
