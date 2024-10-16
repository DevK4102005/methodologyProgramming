#include <stdio.h>
int BinarySearch(int a[],int left,int right,int x);
int main(){
    int a[]={-1,0,1,2,3,4,5,6,7,8,9,10};
    int n=sizeof(a)/sizeof(a[0]);
    int x=0;
    int result=BinarySearch(a,0,n-1,x);
    if (result!=-1)
    {
        printf("Phan tu %d co vi tri la %d",x,result);
    }
    else printf("Phan tu %d khong nam trong mang!",x);

}
int BinarySearch(int a[],int left,int right,int x){
    //Dieu kien dung: right<left
    if (right>=left)
    {
        //mid: vi tri giua cua mang
        int mid=left+(right-left)/2;
        //Neu phan tu x nam giua mang
        if (x==a[mid])
        {
        return mid;
        }
        //Neu phan tu x lon hon mid
        if (a[mid]<x)
        {
            return BinarySearch(a,mid+1,right,x);
        }
        //Neu phan tu x nho hon mid
        if (a[mid]>x)
        {
            return BinarySearch(a,left,mid-1,x);
        }
        //Neu tim khong thay phan tu x
    }
    return -1;
}
