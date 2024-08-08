#include <stdio.h>
#include <stdarg.h>
#include<string.h>
int my_scanf( char *format_str,...);


int main()
{
    int num ;
    char str[30];
    char ch;
    double a = 2.785644;

   my_printf("Enter a number\n");
   my_scanf("%d",&num);
    my_printf("This is a number : %d\n",num);
    my_printf("Enter a string\n");
    my_scanf("%s",str);
    my_printf("This is a string : %s\n",str);
    my_printf("enter a char\n");
    my_scanf("%c",ch);
    my_printf("This is a char : %c\n",ch);
      my_printf("This is a float : %f \n",(double)a );
    my_printf("This is a percent sign: %\n");
    return 0;
}

void my_printf(const char *format,...){
va_list args;
va_start(args,format);

while(*format){
    if(*format == '%' ){
        format++;
        switch(*format){
       case 'd': printf("%d",va_arg(args,int));
                 break;
       case 's': printf("%s",va_arg(args,char *));
                 break;
       case 'c': printf("%c",va_arg(args,int));
                 break;
       case 'f' : printf("%f",va_arg(args,double));
                 break;
       default :
        putchar('%');
        break;
        }
    }else{
    putchar(*format);
    }
    format++;
}
va_end(args);
}




int my_scanf( char *format_str,...){
va_list args;
va_start(args,format_str);

char *input = malloc(1024);
fgets(input,1024,stdin);

int parsed_element = 0;
const char *fmt_ptr = format_str;
char*input_ptr = input;

while(*fmt_ptr){
    if(*fmt_ptr != '%'){
        fmt_ptr++;
        continue;
    }

    fmt_ptr++;//move to the format specifier

    switch(*fmt_ptr){
    case 'd' : parsed_element += my_scanf_int(input_ptr,va_arg(args,int *));
                break;
    case 's' : parsed_element += my_scanf_string(input_ptr,va_arg(args,char *));
               break;
    case 'c' : parsed_element += my_scanf_char(input_ptr,va_arg(args,char *));
               break;
    default : printf("unknown format specifier : %c\n", *fmt_ptr);
              break;
    }
    fmt_ptr++;// move to the next character
    input_ptr += strcspn(input_ptr," \t\n"); // skip whitespace
}
free(input);
va_end(args);
return parsed_element;
}

int my_scanf_int(char *input_ptr,int *value){
// Parse the integer from the input string and store it in value variable
*value = strtol(input_ptr, &input_ptr, 10);
if(*input_ptr == '\0'){
    // Handle insufficient input
    printf("Missing input for int :\n");
    return 0;

}
return 1;
}

int my_scanf_string(char *input_ptr,char *string){
// parse the string from the input and store it in string variable
sscanf(input_ptr,"%s",string);
return 1;
}

int my_scanf_char(char *input_ptr, char *character){
// *character = *strspn(input_ptr, " \t\n"); // Skip leading spaces
if(sscanf(input_ptr, "%c",character) != 1){
    printf("Missing input for character \n");
    return 0;
}
return 1;
}
