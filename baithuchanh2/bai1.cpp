/*Viết các hàm tính giá trị các biểu thức sau bằng cả hai cách: không đệ quy và đệ quy*/
/*
  a. f(x, n) = xn, với x là số thực, n là số nguyên.
  b. f(n) = n!, với n ≥ 0.
  c. s(n) = 1 + 2 + ... + n, với n ≥ 0.
  d. s(n) =  1 + 3 + 5 + ... + (2n - 1), với n ≥ 0.
  e. s(n) =  2 + 4 + 6 + ... + (2n), với n ≥ 0.
  f. Tính tổng các số nguyên tố <= n, với n là số nguyên dương.
  g. Đếm số nguyên tố <= n, với n là số nguyên dương.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float F_a(float x, int n);
float F_aDeQuy(float x, int n);
long F_b(int n);
long F_bDeQuy(int n);
long S_c(int n);
long S_cDeQuy(int n);
long S_d(int n);
long S_dDeQuy(int n);
long S_e(int n);
long S_eDeQuy(int n);
long S_f(int n);
long S_fDeQuy(int n);
int S_g(int n);
int S_gDeQuy(int n);
bool CheckPrime(int &n);
int main()
{
    int n;
    printf("Nhap n:");
    scanf("%d", &n);
    printf("%.d\n", S_gDeQuy(n));

    return 0;
}
float F_a(float x, int n)
{
    return x * n;
}
float F_aDeQuy(float x, int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n > 0)
    {
        return x + F_aDeQuy(x, n - 1);
    }
    else
        return -F_aDeQuy(x, -n);
}
long F_b(int n)
{
    long total = 1;
    if (n == 0)
        return 0;
    else
        for (int i = 1; i <= n; i++)
        {
            total *= i;
        }
    return total;
}
long F_bDeQuy(int n)
{
    if (n == 1)
        return n;
    else
    {
        return n * F_bDeQuy(n - 1);
    }
}
long S_c(int n)
{
    long s = 0;
    for (int i = 1; i <= n; i++)
    {
        s += i;
    }
    return s;
}
long S_cDeQuy(int n)
{
    if (n == 1)
    {
        return n;
    }
    else
        return S_cDeQuy(n - 1) + n;
}
long S_d(int n)
{
    long total = 0;
    for (int i = 1; i <= n; i += 2)
    {
        total += i;
    }
    return total;
}
long S_dDeQuy(int n)
{
    if (n == 1)
    {
        return n;
    }
    else
        return 2 * n - 1 + S_dDeQuy(n - 1);
}
long S_e(int n)
{
    int total = 0;
    for (int i = 2; i <= n; i += 2)
    {
        total += i;
    }
    return total;
}
long S_eDeQuy(int n)
{
    if (n == 0)
    {
        return n;
    }
    else
        return S_eDeQuy(n - 1) + 2 * n;
}
long S_f(int n)
{
    int total = 0;
    if (n <= 1)
        return -1;
    for (int i = 2; i <= n; i++)
    {
        if (CheckPrime(i))
        {
            total += i;
        }
    }
    return total;
}
long S_fDeQuy(int n)
{
    if (n <= 1)
        return 0;
    else if (CheckPrime(n))
        return S_fDeQuy(n - 1) + n;
    else
        return S_fDeQuy(n - 1);
}
int S_g(int n)
{
    int dem = 0;
    if (n <= 1)
        return -1;
    for (int i = 2; i <= n; i++)
    {
        if (CheckPrime(i))
        {
            dem++;
        }
    }
    return dem;
}
int S_gDeQuy(int n)
{
    if (n <= 1)
    {
        return 0;
    }
    else
    {
        int dem = CheckPrime(n) ? 1 : 0;
        // Gọi đệ quy với n-1 và cộng dồn kêt quả nếu n là số nguyên tố
        return dem + S_gDeQuy(n - 1);
    }
}
bool CheckPrime(int &n)
{
    if (n < 2)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return n > 1;
}