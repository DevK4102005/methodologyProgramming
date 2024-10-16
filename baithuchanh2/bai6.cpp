//Viet ham de quy xac dinh chieu dai chuoi
#include <stdio.h>
#include <string.h>
int ChieuDaiChuoi(char *a);

int main(){
    char a[100];
    fflush(stdin);
    printf("Nhap chuoi:");
    gets(a);
    //puts(a);
    int total=ChieuDaiChuoi(a);
    printf("Do dai chuoi la:%d",total);
    return 0;
}
int ChieuDaiChuoi(char* a){
   //Dieu kien dung: neu gap ki tu ket thuc, tra ve 0
   if (*a=='\0')
   {
        return 0;
   }
   return ChieuDaiChuoi(a+1)+1;
}
