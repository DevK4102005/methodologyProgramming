#include <stdio.h>
#include <stdlib.h>
typedef int Mang[30];
void nhapMang(Mang e, int &n);
void xuatMang(Mang e, int n);
void sapXepMang(Mang e, int &n);
void gopMang(Mang a, int &n1,
             Mang b, int &n2, Mang c, int &n3);
int main()
{
    Mang a, b, c;
    int n1, n2, n3;
    printf("Nhap so luong phan tu cho mang a:");
    scanf("%d", &n1);
    nhapMang(a, n1);
    sapXepMang(a, n1);
    printf("Mang a sau khi sap xep tang dan\n");
    xuatMang(a, n1);
    printf("\n");
    printf("Nhap so luong phan tu cho mang b:");
    scanf("%d", &n2);
    nhapMang(b, n2);
    sapXepMang(b, n2);
    printf("Mang b sau khi sap xep tang dan\n");
    xuatMang(b, n2);
    printf("\n");
    gopMang(a, n1, b, n2, c, n3);
    printf("Mang sau khi gop la:\n");
    xuatMang(c, n3);
}
void gopMang(Mang a, int &n1,
             Mang b, int &n2, Mang c, int &n3)
{
    n3 = 0;
    for (int i = 0; i < n1; i++)
    {
        c[n3] = a[i];
        n3++;
    }
    for (int i = 0; i < n2; i++)
    {
        c[n3] = b[i];
        n3++;
    }
}
void nhapMang(Mang e, int &n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Nhap array[%d]:", i);
        scanf("%d", &e[i]);
    }
}
void xuatMang(Mang e, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", e[i]);
    }
}
void sapXepMang(Mang e, int &n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (e[j + 1] < e[j])
            {
                temp = e[j];
                e[j] = e[j + 1];
                e[j + 1] = temp;
            }
        }
    }
}
