#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#define maxlen 30
typedef int Mang[maxlen];
void nhapMang(Mang a, int &n);
void xuatMang(Mang a, int n);
bool checkPrime(int &c);
void xuatSonguyento(Mang a, int n);
void xuatSochinhphuong(Mang a, int n);
bool checkSquare(int &c);
void xuatPtLonHonTB(Mang a, int n);
int findPtMax(Mang a, int n);
bool checkSorted(Mang a, int n);
void sxTangDan(Mang a, int n);
void sxGiamDan(Mang a, int n);
int main()
{
    int n;
    Mang a;
    printf("Nhap n phan tu:");
    scanf("%d", &n);
    nhapMang(a, n);
    printf("Mang vua nhap la\n");
    xuatMang(a, n);
    printf("\n");
    printf("Cac so nguyen to la\n");
    xuatSonguyento(a, n);
    printf("\n");
    printf("Cac so chinh phuong la\n");
    xuatSochinhphuong(a, n);
    printf("\nCac phan tu lon hon phan tu trung binh la\n");
    xuatPtLonHonTB(a, n);
    printf("\nPhan tu lon nhat trong mang:%d\n", findPtMax(a, n));
    if (checkSorted(a, n) == true)
    {
        printf("Mang da duoc sap xep tang dan roi\n");
    }
    else
        printf("Mang chua duoc sap xep tang dan\n");
    sxTangDan(a, n);
    printf("Mang duoc sap xep tang dan la\n");
    xuatMang(a, n);
    printf("\nMang duoc sap xep giam dan la\n");
    sxGiamDan(a, n);
    xuatMang(a, n);
    return 0;
}
void nhapMang(Mang a, int &n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Nhap a[%d]:", i);
        scanf("%d", &a[i]);
    }
}
void xuatMang(Mang a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}
bool checkPrime(int &c)
{
    for (int i = 2; i <= sqrt(c); i++)
        if (c % i == 0)
            return false;
    return c > 1;
}
void xuatSonguyento(Mang a, int n)
{
    for (int i = 0; i < n; i++)
        if (checkPrime(a[i]))
        {
            printf("%d\t", a[i]);
        }
}
void xuatSochinhphuong(Mang a, int n)
{
    for (int i = 0; i < n; i++)
        if (checkSquare(a[i]))
        {
            printf("%d\t", a[i]);
        }
}
bool checkSquare(int &c)
{
    int temp = sqrt(c);
    if (pow(temp, 2) == c)
        return true;
    else
        return false;
}
void xuatPtLonHonTB(Mang a, int n)
{
    int tong = 0;
    float tb = 0;
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        tong += a[i];
        dem++;
        tb = (tong * 1.0) / dem;
    }
    for (int i = 0; i < n; i++)
    {
        if (tb < a[i])
        {
            printf("%d\t", a[i]);
        }
    }
}
int findPtMax(Mang a, int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (max < a[i])
        {
            max = a[i];
        }
    }
    return max;
}
bool checkSorted(Mang a, int n)
{
    for (int i = 0; i < n - 1; i++)
        if (a[i] > a[i + 1])
            return false;
    return true;
}
void sxTangDan(Mang a, int n)
{
    // su dung thuat toan Insertion Sort
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j -= 1;
        }
        a[j + 1] = key;
    }
}
void sxGiamDan(Mang a, int n)
{
    // su dung thuat toan Insertion Sort
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] < key)
        {
            a[j + 1] = a[j];
            j -= 1;
        }
        a[j + 1] = key;
    }
}