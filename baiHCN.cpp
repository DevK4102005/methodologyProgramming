/*Bai HCN, co 2 diem trai tren, phai duoi. Biet moi diem duoc xac dinh bang (x,y)
a) Hay nhap danh sach HCN
b) Hay in danh sach HCN vua nhap
c) Hay in ra HCN co dien tich lon nhat
d) Hay sap xep danh sach HCN giam dan theo dien tich*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct
{
    int x,y;
}Diem;
typedef struct
{
    Diem TraiTren,PhaiDuoi;
}HCN;
void NhapHCN(HCN *hcn);
void InHCN(HCN hcn);
void NhapDSHCN(HCN *hcn,int n);
void InDSHCN(HCN *hcn,int n);
int DienTichHCN(HCN hcn);
void DienTichHCNMax(HCN *hcn,int n);
void SapXepHCN(HCN *hcn,int n);
void Swap(HCN &a,HCN &b);
int main(){
//HCN hcn[100];//Cach nay su dung mang de cap phat bo nho
    HCN *hcn=(HCN*)malloc(sizeof(HCN));//Cach nay su dung cap phat dong tang dung luong luu tru phan tu
    int n;
    printf("Nhap n:");
    scanf("%d",&n);
    NhapDSHCN(hcn,n);
    printf("Danh sach HCN vua nhap la\n");
    printf("------------------------------------------------\n");
    InDSHCN(hcn,n);
    printf("\n");
    DienTichHCNMax(hcn,n);
    printf("Danh sach HCN vua nhap sap xep giam theo dien tich giam dan la\n");
    printf("-----------------------------------------------------------------\n");
    printf("\n");
    SapXepHCN(hcn,n);
    InDSHCN(hcn,n);
    free(hcn);
    return 0;
}
void NhapHCN(HCN *hcn){
    do{
    printf("Chu y: diem nhap vao phai thoa man: TraiTren.x>PhaiDuoi.x va TraiTren.y<PhaiDuoi.y\n");
    printf("Nhap diem trai tren(x,y):");
    scanf("%d%d",&hcn->TraiTren.x,&hcn->TraiTren.y);
    printf("Nhap diem phai duoi(x,y):");
    scanf("%d%d",&hcn->PhaiDuoi.x,&hcn->PhaiDuoi.y);
    }while(!(hcn->TraiTren.x>hcn->PhaiDuoi.x&&hcn->TraiTren.y<hcn->PhaiDuoi.y));
}
void InHCN(HCN hcn){
    printf("HCN co diem trai tren(%d,%d) va diem phai duoi(%d,%d)\n",hcn.TraiTren.x,hcn.TraiTren.y,
    hcn.PhaiDuoi.x,hcn.PhaiDuoi.y);
}
void NhapDSHCN(HCN *hcn,int n){
    for (int i = 0; i < n; i++)
    {
        printf("Nhap HCN thu %d\n",i+1);
        NhapHCN(&hcn[i]);
        printf("\n");
    }
}
void InDSHCN(HCN *hcn,int n){
    for (int i = 0; i < n; i++)
    {
        printf("HCN thu %d\n",i+1);
        InHCN(hcn[i]);
        printf("\n");
    }
}
int DienTichHCN(HCN hcn){
    return (hcn.TraiTren.x-hcn.PhaiDuoi.x)*(hcn.PhaiDuoi.y-hcn.TraiTren.y);
}
void DienTichHCNMax(HCN *hcn,int n){
    HCN max=hcn[0];
    for (int i = 0; i < n; i++)
    {
        if(DienTichHCN(max)<DienTichHCN(hcn[i]))
        {
            max=hcn[i];
        }
    }
    printf("HCN dien tich max co trai tren(%d,%d)va phai duoi(%d,%d), dien tich la:%d\n",
            max.TraiTren.x,max.TraiTren.y,max.PhaiDuoi.x,max.PhaiDuoi.y,DienTichHCN(max));
}
void SapXepHCN(HCN *hcn,int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (DienTichHCN(hcn[j])<DienTichHCN(hcn[j+1]))
            {
                Swap(hcn[j],hcn[j+1]);
            }
        }
    }
}
void Swap(HCN &a,HCN &b){
    HCN temp;
    temp=a;
    a=b;
    b=temp;
}