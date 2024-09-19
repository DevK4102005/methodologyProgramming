#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct
{
    char MSSV[20];
    char HoTen[30];
    float dtb;
} SinhVien;
void NhapTTsv(SinhVien *sv);
void NhapDSsv(SinhVien *ds, int *n);
void XuatTTsv(SinhVien *sv);
void XuatDSsv(SinhVien *ds, int n);
void TimSV(SinhVien *sv, int n, SinhVien *temp);
void SapXep(SinhVien *sv, int n, int choice);
void Swap(SinhVien &a, SinhVien &b);
int main()
{
    SinhVien sv, temp;
    int n;
    do
    {
        printf("Nhap n:");
        scanf("%d", &n);
    } while (!(0 < n && n < 100));
    NhapDSsv(&sv, &n);
    XuatDSsv(&sv, n);
    TimSV(&sv, n, &temp);
    printf("\n");
    char choice;
    SapXep(&sv, n, choice);
    XuatDSsv(&sv, n);
    return 0;
}
void NhapTTsv(SinhVien *sv)
{
    fflush(stdin);
    printf("Nhap MSSV:");
    gets(sv->MSSV);
    printf("Nhap ho va ten:");
    gets(sv->HoTen);
    printf("Nhap diem trung binh:");
    scanf("%f", &sv->dtb);
}
void XuatTTsv(SinhVien *sv)
{
    printf("MSSV:%s\n", sv->MSSV);
    printf("HoTen sinh vien:%s\n", sv->HoTen);
    printf("Diem trung binh:%.2f\n", sv->dtb);
}
void NhapDSsv(SinhVien *ds, int *n)
{
    for (int i = 0; i < *n; i++)
    {
        printf("Nhap thong tin sinh vien thu %d\n", i + 1);
        NhapTTsv(&ds[i]);
    }
}
void XuatDSsv(SinhVien *ds, int n)
{
    printf("------------------------------------\n");
    printf("Danh sach cac sinh vien vua nhap\n");
    for (int i = 0; i < n; i++)
    {
        printf("Sinh vien thu %d\n", i + 1);
        XuatTTsv(&ds[i]);
        printf("\n");
    }
}
void TimSV(SinhVien *sv, int n, SinhVien *temp)
{
    fflush(stdin);
    // temp la bien de nhap vao mssv can tim sau do so sanh voi tung ma so sinh vien trong danh sach
    printf("------------------------------------\n");
    printf("Nhap MSSV can tim:");
    gets(temp->MSSV);
    for (int i = 0; i < n; i++)
    {
        if (strcmp(sv[i].MSSV, temp->MSSV) == 0)
        {
            XuatTTsv(sv);
        }
    }
    printf("Khong tim thay sinh vien");
}
void SapXep(SinhVien *sv, int n, int choice)
{//Su dung giai thuat Bubble Sort 
    do
    {
        printf("Nhap lua chon sap xep danh sach tang dan(1)/giam dan(-1):");
        scanf("%d", &choice);
    } while (!(choice == 1 || choice == -1));
    if (choice == 1)
    {
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - i - 1; j++)
            {
                if (sv[j].dtb > sv[j + 1].dtb)
                {
                    Swap(sv[j], sv[j + 1]);
                }
            }
    }
    else
    {
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - i - 1; j++)
            {
                if (sv[j].dtb < sv[j + 1].dtb)
                {
                    Swap(sv[j], sv[j + 1]);
                }
            }
    }
}
void Swap(SinhVien &a, SinhVien &b)
{
    SinhVien tmp;
    tmp = a;
    a = b;
    b = tmp;
}