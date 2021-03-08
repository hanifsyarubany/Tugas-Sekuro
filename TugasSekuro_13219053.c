//Nama : Abu Hanif Muhammad Syarubany
//NIM  : 13219053

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void calculate_riemann();
int main() 
{
    float a,b;
    double hasil;
    char operator;
    char d;
    //loop untuk tetap meminta input
    while (d != 'N'){
        //memasukkan perintah
        printf("Masukkan Perintah (kali: +, bagi: -, kali: *, bagi: / , pangkat : ^ , riemann : r) : ");
        scanf(" %c", &operator);
        //jika r maka akan terlebih dahulu memproses riemann
        if (operator == 'r'){
            calculate_riemann();
            continue;
        }
        //memasukkan angka 1
        printf("Masukkan Angka 1 : ");
        scanf("%f",&a);
        //memasukkan angka 2
        printf("Masukkan Angka 2 : ");
        scanf("%f",&b);
        //kondisi dari operator
        if (operator=='+'){
            printf("Hasil Operasi : %.2lf",a+b);
        }
        else if (operator=='-'){
            printf("Hasil Operasi : %.2lf",a-b);
        }
        else if (operator=='*'){
            hasil=a*b;
            printf("Hasil Operasi : %.2lf",hasil);
        }
        else if (operator=='/'){
            hasil=a/b;
            printf("Hasil Operasi : %.2lf",hasil);
        }
        else if (operator=='^'){
            //mendefinisikan base dan eksponen
            int base = a, exp = b;
            long long result = 1;
            //looping untuk perkalian sebanyak eksponen
            while (exp != 0) {

                result *= base;
                --exp;
            }
            printf("Hasil Operasi : %d",result);
        }
        else{
            printf("Operasi tidak dikenali");
        }
        printf("\n");
        printf("Lanjut? (Y/N) : ");
        scanf(" %c",&d);
        printf("\n\n");
    }
    
    return 0;
};

//fungsi untuk menghitung luas asli
void calculate_riemann(){
    float luas,y_1,y_2,rumus,n,b,luassegiasli;
    printf("Berikut perhitungan luas segitiga titik (0,0),(1,4),dan (4,0) dengan metode deret riemann trapesium\n");
    printf("Masukkan jumlah partisi n yang diinginkan\n");
    scanf("%f", &n);
    luas = 0;
    b = 4/n;
    //loping untuk jumlah riemannya
    for(float i = 0; i <= 4; i = i + b){
        if ((i+b) <= 1)
        {
            y_1 = 4 * i ;
            y_2 = 4 * (i+b);
            rumus = b*((y_1 + y_2)/2);
            luas = luas + rumus;
        }
        else
        {
            y_1 = (5.3333333333 - (1.3333333333 * i))  ;
            y_2 = (5.3333333333 - (1.3333333333 * (i+b)));
            rumus = b*((y_1 + y_2)/2);
            luas = luas + rumus;    
        }
        
    }
    //menghitung luas eksak atau luas asli
    luassegiasli = ((4)*4/2);
    printf("Luas segitiga tersebut dengan metode deret rieman adalah %f \n", luas);
    printf("Luas segitiga tersebut dengan metode alas x tinggi /2 =  %f \n", luassegiasli);
    printf("Sehingga luas segitiga tersebut dengan metode riemann memiliki galat %f\n\n", luas-luassegiasli);

}