#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define maxlen 30
typedef int MT[maxlen][maxlen];
void xuatMT(MT a, int m, int n);
void nhapMT(MT a, int &m, int &n);
float trungBinhCongMT(MT a, int m, int n);
int findMax(MT a, int m, int n);
bool checkPrime(int &a);
int countPrime(MT a, int m, int n);
int findMaxDong(MT a, int m, int n, int &i);
int findMaxCot(MT a, int m, int n, int &j);
void sapXepHangTang(MT a, int m, int n);
void swap(int &a, int &b);
void sapXep1HangTang(int row[], int n);
int main()
{
    MT a;
    int m, n;
    nhapMT(a, m, n);
    printf("Ma tran vua nhap la\n");
    xuatMT(a, m, n);
    printf("Trung binh cong cua MT:%.2f\n", trungBinhCongMT(a, m, n));
    printf("Phan tu lon nhat trong MT:%d\n", findMax(a, m, n));
    printf("Co %d phan tu la so nguyen to trong MT\n", countPrime(a, m, n));
    int i;
    do
    {
        printf("Nhap dong can tim phan tu lon nhat:");
        scanf("%d", &i);
    } while (!(0 <= i && i <= m));
    int tmpRow = findMaxDong(a, m, n, i);
    printf("PT max cua dong %d la %d\n", i, tmpRow);
    int j;
    do
    {
        printf("Nhap cot can tim phan tu lon nhat:");
        scanf("%d", &j);
    } while (!(0 <= j && j <= n));
    int tmpColumn = findMaxCot(a, m, n, j);
    printf("PT max cua cot %d la %d\n", j, tmpColumn);
    sapXepHangTang(a, m, n);
    printf("Mang sau khi sap xep cac phan tu cua hang tang dan:\n");
    xuatMT(a, m, n);
    return 0;
}
void nhapMT(MT a, int &m, int &n)
{
    printf("Nhap so dong:");
    scanf("%d", &m);
    printf("Nhap so cot:");
    scanf("%d", &n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            printf("Nhap a[%d][%d]:", i, j);
            scanf("%d", &a[i][j]);
        }
}
void xuatMT(MT a, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d\t", a[i][j]);
        printf("\n");
    }
}
float trungBinhCongMT(MT a, int m, int n)
{
    int dem = 0, tong = 0;
    float tbc;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tong += a[i][j];
            dem++;
        }
    }
    return tbc = (tong * 1.0) / dem;
}
int findMax(MT a, int m, int n)
{
    int max = a[0][0];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] > max)
                max = a[i][j];
        }
    return max;
}
bool checkPrime(int &a)
{
    for (int i = 2; i <= sqrt(a); i++)
    {
        if (a % i == 0)
            return false;
    }
    return a > 1;
}
int countPrime(MT a, int m, int n)
{
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (checkPrime(a[i][j]))
            {
                count++;
            }
        }
    }
    return count;
}
int findMaxDong(MT a, int m, int n, int &i)
{

    int max = a[i - 1][0];
    for (int j = 0; j < n; j++)
    {
        if (max < a[i - 1][j])
        {
            max = a[i - 1][j];
        }
    }
    return max;
}
int findMaxCot(MT a, int m, int n, int &j)
{
    int max = a[0][j - 1];
    for (int k = 0; k < m; k++)
    {
        if (max < a[k][j - 1])
        {
            max = a[k][j - 1];
        }
    }
    return max;
}
void sapXepHangTang(MT a, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        sapXep1HangTang(a[i], n);
    }
}
void swap(int &a, int &b)
{
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}
//Mang co kich thuoc nho, dung Bubble Sort de dang cai dat
//Viet ham sap xep 1 hang roi cho lap lai de duyet het mang
void sapXep1HangTang(int row[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (row[j] > row[j + 1])
            {
                swap(row[j], row[j + 1]);
            }
        }
    }
}
