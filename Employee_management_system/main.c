// Employee management system
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<unistd.h>

#define MAX 10

typedef struct employee{
int emp_id ;
char emp_name[20];
char emp_designation[20];
}employee;
int n,size=0;
int main()
{

    get_choice();
    return 0;
}

void get_choice(){
printf("\n Employee management System\n");
printf("0.Built the employee table:\n");
printf("1.Insert new entries :\n");
printf("2.Delete The entries : \n");
printf("3.Search a record : \n");
printf("4.Print  details: \n");
printf("5.Edit details: \n");
printf("6.exit : \n");
 int choice;
printf("Enter a choice :\n");
scanf("%d",&choice);
    switch(choice)
    {
    case 0: built_table();
            break;
    case 1: insert_new();
            break;
    case 2: delete_entries();
            break;
    case 3: search_record();
            break;
    case 4: printf("Printig details\n");
            display();
            break;
    case 5: edit_option();
            break;
    case 6: printf("Exiting ----- \n");
            break;
    default:printf("Invalid option");
    }
}

void built_table(){
printf("\n built the table\n");
printf("Maximum Entries %d :\n",MAX);
printf("How many entries you want to enter :\n");
scanf("%d",&n);
if(n > MAX){
    printf("Maximum entries can be %d:\n",MAX);
}
employee *emp;
FILE *fp;

fp=fopen("EMS_new4.txt","w");

emp=(employee *)calloc(n,sizeof(employee));

printf("Enter data: \n");
for(int i=0;i<n;i++){
    printf("Enter employee ID for EMP %d : \n",i+1);
    scanf("%d",&emp[i].emp_id);
    printf("Enter name for EMP %d :\n",i+1);
    scanf("%s",emp[i].emp_name);
    printf("Enter Designation for EMP %d : \n",i+1);
    scanf("%s",emp[i].emp_designation);

    fprintf(fp,"%d %s %s\n",emp[i].emp_id,emp[i].emp_name,emp[i].emp_designation);
   size+=1;
}
fclose(fp);
//display();
get_choice();

}

void insert_new(){
int n;
printf("Maximum Entries %d :\n",MAX);
printf("How many entries you want to insert :\n");
scanf("%d",&n);
employee *emp;
FILE *fp;

fp=fopen("EMS_new4.txt","a");

emp=(employee *)calloc(n,sizeof(employee));
printf("Enter data: \n");
for(int i=0;i<n;i++){
    printf("Enter employee ID for EMP %d : \n",i+1);
    scanf("%d",&emp[i].emp_id);
    printf("Enter name for EMP %d :\n",i+1);
    scanf("%s",emp[i].emp_name);
    printf("Enter Designation for EMP %d : \n",i+1);
    scanf("%s",emp[i].emp_designation);

    fprintf(fp,"%d %s %s\n",emp[i].emp_id,emp[i].emp_name,emp[i].emp_designation);
    size+=1;
}
fclose(fp);
//display();
get_choice();
}

// search a record
void search_record(){
printf("to search a record \n");
int id_to_find;
printf("Enter an EMPLOYEE ID to find :\n");
scanf("%d",&id_to_find);
int found=0;
 employee e1;
  FILE *fp;
  fp=fopen("EMS_new4.txt","r");
  while(!feof(fp)){
        fscanf(fp,"%d %s %s\n",&e1.emp_id,e1.emp_name,e1.emp_designation);
        if (e1.emp_id == id_to_find){
          printf("GOT IT ! Here is details--\n");
          printf("------------------------------------------------------\n");
          printf("%d\t %s\t%s\n",e1.emp_id,e1.emp_name,e1.emp_designation);
                   found=1;
        }
  }
  if(!found){
    printf(" SORRY! Record not found\n");
  }
  fclose(fp);
   get_choice();
}


void display(){
  employee e1;
  FILE *fp;
  fp=fopen("EMS_new4.txt","r");
  printf("EMP ID\t\t   EMP NAME\t\tEMP DESIGNATION: \n");
  // rewind(fp);
  //while(fscanf(fp,"%d %s %s\n",&e1.emp_id,e1.emp_name,e1.emp_designation)!=EOF){
  while(!feof(fp)){
    fscanf(fp,"%d %s %s\n",&e1.emp_id,e1.emp_name,e1.emp_designation);
    printf("------------------------------------------------------\n");
    printf("%d\t\t\t %s\t\t\t%s\n",e1.emp_id,e1.emp_name,e1.emp_designation);
  }
  fclose(fp);
  get_choice();
}

void delete_entries(){
int delID;
printf("size is %d\n",size);
FILE *fp;
printf("Enter EMPID to delete\n");
scanf("%d",&delID);
employee e1;
employee *e2;
e2=(employee *)calloc((size),sizeof(employee));
int found=0;
fp=fopen("EMS_new4.txt","r");
int line_no=1;
int line_status=0;
 int currpos=0,prevpos =0;
int len=0;
int i=0;
while(!feof(fp)){
        fscanf(fp,"%d %s %s\n",&e1.emp_id,e1.emp_name,e1.emp_designation);
        if(e1.emp_id == delID){
         printf("LINE No : %d\n",line_no);
         found=1;
         line_status = 1;
         int li = log10(e1.emp_id)+1;
         len =  li + strlen(e1.emp_name) + strlen(e1.emp_designation) + 4;
         printf("LENGTH : %d\n",len);
         currpos = ftell(fp);
         printf("current Position is : %ld \n",currpos);
         prevpos = ftell(fp)-len +1;
         printf("starting of line pos %d : \n",prevpos);
        // free(buffer);
        size-=1;
        }
        line_no++;
        if(line_status){
           line_status = 0;
       }
        else{
                e2[i].emp_id = e1.emp_id;
                strcpy(e2[i].emp_name,e1.emp_name);
                strcpy(e2[i].emp_designation,e1.emp_designation);
                    i++;

         }
  }
  fclose(fp);

  if(found){
      fp=fopen("EMS_new4.txt","w");
    printf("size is %d : \n",size);
        for( i=0;i<size;i++){
     fprintf(fp,"%d %s %s\n",e2[i].emp_id,e2[i].emp_name,e2[i].emp_designation);
    }
   printf("Details FOUND :\n");
  fclose(fp);
  }
  else{
    printf("NOT FOUND, NOT ABLE TO DELETE\n");
  }
 get_choice();
 return 0;
}

//Edit option
void edit_option(){
int ediID;
printf("size is :%d\n",size);
FILE *fp;
printf("Enter EMPID to edit\n");
scanf("%d",&ediID);
employee e1;
employee *e2;
e2=(employee *)calloc((size),sizeof(employee));
int found=0;
fp=fopen("EMS_new4.txt","r");
int line_no=1;
int line_status=0;
int i=0;
while(!feof(fp)){
        fscanf(fp,"%d %s %s\n",&e1.emp_id,e1.emp_name,e1.emp_designation);
        if(e1.emp_id == ediID){
         printf("LINE No : %d\n",line_no);
         found=1;
         line_status = 1;
         printf("Which details of employee %d you want to edit choose :\n ",ediID);
         printf("1.EMP ID \n 2.EMP NAME \n 3.EMP DESIGNATION \n 4.ALL \n");
         int ch;
         scanf("%d",&ch);
         switch(ch){
         case 1 : printf("Enter new employee ID:\n");
                  scanf("%d",&e1.emp_id);
                  break;
         case 2 : printf("Enter new name:\n");
                  scanf("%s",e1.emp_name);
                  break;
         case 3 : printf("Enter new designation:\n");
                  scanf("%s",e1.emp_designation);
                  break;
         case 4 : printf("Enter new employee ID:\n");
                  scanf("%d",&e1.emp_id);
                  printf("Enter new name:\n");
                  scanf("%s",e1.emp_name);
                  printf("Enter new designation:\n");
                  scanf("%s",e1.emp_designation);
                  break;
        default : printf("Invalid option\n");
         }
        //size-=1;
        }
        line_no++;
        if(line_status){
        e2[i].emp_id = e1.emp_id;
           strcpy(e2[i].emp_name,e1.emp_name);
           strcpy(e2[i].emp_designation,e1.emp_designation);
           i++;
           line_status = 0;
       }
        else{   e2[i].emp_id = e1.emp_id;
                strcpy(e2[i].emp_name,e1.emp_name);
                strcpy(e2[i].emp_designation,e1.emp_designation);
                i++;
         }
  }
  fclose(fp);

  if(found){
      fp=fopen("EMS_new4.txt","w");
      printf("size is %d : \n",size);
        for( i=0;i<size;i++){
        fprintf(fp,"%d %s %s\n",e2[i].emp_id,e2[i].emp_name,e2[i].emp_designation);
    }
  printf("Details edited successfully :\n");
  fclose(fp);
  }
  else{
    printf("NOT FOUND, NOT ABLE TO EDIT\n");
  }
 get_choice();
 return 0;
}

