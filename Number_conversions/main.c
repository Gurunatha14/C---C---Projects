//Number conversion
#include <stdio.h>
#include <stdlib.h>

void getting_choice();
void bin_dec();
void dec_bin();
void dec_oct();
void oct_dec();
void bin_hx();
void hex_bin();

int main()
{
  //printf("hello\n");
  int choice=1;
  while(choice){
    int opinion;
do{
    getting_choice();

    printf("Enter your opinion :\n");
    scanf("%d",&opinion);
    switch(opinion){
     case 1:
        dec_bin();
        break;
     case 2:
        bin_dec();
        break;
     case 3:
        dec_oct();
        break;
     case 4:
        oct_dec();
        break;
    case 5:
        hex_bin();
        break;
    case 6:
        bin_hex();
        break;
    case 7:
        printf("Exiting ----- \n");
        break;
    default:
        printf("Invalid option");

    }
   // printf("Do you want to continue : 0 or 1\n");
   // scanf("%d",&choice);
  }while(opinion != 7);

  printf("Do you want to comtinue : 0 or 1\n");
  scanf("%d",&choice);
}
    return 0;
}

// to get option
void getting_choice(){
printf("\n Number base conversion \n");

printf("1.decimal to binary :\n");
printf("2.Binary to decimal :\n");
printf("3.Decimal to octal : \n");
printf("4.Octal to Decimal : \n");
printf("5.Hexadecimal to Binary :\n");
printf("6.Binary to Hexadecimal :\n");
printf("7.exit : \n");

return 0;
}

// Bin to dec
void bin_dec(){
int bin,j=1,rem,d,dec;
printf("Enter a binary no : \n");
scanf("%d",&bin);
int bin_p=bin;
while(bin>0){
    rem=bin%10;
    d=rem*j;
    dec+=d;
    j*=2;
    bin/=10;

}
printf("%d in decimal is : %d ",bin_p,dec);
return 0;
}

// dec to binary_function
void dec_bin(){
int dec,rem,bin=0,j=1;
printf("Enter decimal number : \n");
scanf("%d",&dec);
int dec_p=dec;
while (dec != 0) {
        rem = dec % 2;
        bin += rem * j;
        dec /= 2;
        j *= 10;
    }
    printf("%d in bin is %d",dec_p,bin);
    return 0;
}


// dec to octal
void dec_oct(){
    int dec,oct=0,rem,j=1;
printf("Enter decimal no : \n");
scanf("%d",&dec);
int dec_p=dec;
while(dec !=0){
    rem=dec%8;
    oct += rem*j;
    dec /=8;
    j*=10;
}
printf("%d in octal is %d :",dec_p,oct);
return 0;
}

// octal to dec
void oct_dec(){
int oct,dec=0,j=1,rem,d;
printf("enter Octal number : \n");
scanf("%d",&oct);
int oct_p=oct;
while(oct !=0){
    rem = oct % 10;
    d=rem*j;
    dec+=d;
    j*=8;
    oct/=10;
}
printf("%d in octal is %d",oct_p,dec);
return 0;
}

// Bin to hex
void bin_hex(){
   int hexConstant[] = {0, 1, 10, 11, 100, 101, 110, 111, 1000,1001, 1010, 1011, 1100, 1101, 1110, 1111};
    int bin, bin_p;
    char hex[20];
    int index, i, digit;
    printf("Enter binary number: ");
    scanf("%d", &bin);
    bin_p = bin;
    index = 0;
    while(bin_p!=0){
     digit = bin_p % 10000;
        for(i=0; i<16; i++){
            if(hexConstant[i] == digit){
                if(i<10){
                    hex[index] = (char)(i + 48);
                }
                else{
                    hex[index] = (char)((i-10) + 65);
                }
                index++;
                break;
            }
        }
        bin_p /= 10000;
    }
    hex[index] = '\0';
    //strrev(hex);
    printf("%d in Hexadecimal is %s",bin, hex);
    return 0;
}

// hex to bin
void hex_bin(){
    char  hex[50];
    int i = 0;
    printf("Enter hexadecimal no : \n");
    scanf("%s", hex);
    printf("binary val is: \n");
    while (hex[i])
    {
        switch (hex[i])
        {
        case '0':
            printf("0000"); break;
        case '1':
            printf("0001"); break;
        case '2':
            printf("0010"); break;
        case '3':
            printf("0011"); break;
        case '4':
            printf("0100"); break;
        case '5':
            printf("0101"); break;
        case '6':
            printf("0110"); break;
        case '7':
            printf("0111"); break;
        case '8':
            printf("1000"); break;
        case '9':
            printf("1001"); break;
        case 'A':
        case 'a':
            printf("1010"); break;
        case 'B':
        case 'b':
            printf("1011"); break;
        case 'C':
        case 'c':
            printf("1100"); break;
        case 'D':
        case 'd':
            printf("1101"); break;
        case 'E':
        case 'e':
            printf("1110"); break;
        case 'F':
        case 'f':
            printf("1111"); break;
        default:
            printf(" Invalid \n");
            return 0;
        }
        i++;
    }
    return 0;
}

