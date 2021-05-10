#include <stdio.h>
#include "math.h"
#include "header.h"
#include<string.h>
#include<stdbool.h>
#include <stdlib.h>

extern client_n client_arr[10];
extern counter;

void search_name(void)
{   char user_search_name[10];
    printf("Searching with name....\n");
    printf("Enter Name: ");
    scanf("%s",&user_search_name);
    int i;
    for(i=1;i<counter-1;i++){
        if(!(strcmp(client_arr[i].name, user_search_name))){
            printf("This is client %s\n",client_arr[i].name);
            printf("\t Email: %s\t Phone: %s\n\n",client_arr[i].mail,client_arr[i].phone);
        }
    }
}
void search_phone(void)
{   char user_search_phone[11];
    printf("Searching with Phone....\n");
    printf("Enter Phone: ");
    scanf("%s",&user_search_phone);
    int i;
    for(i=1;i<counter-1;i++){
        if(!(strcmp(client_arr[i].phone, user_search_phone))){
            printf("This is client %s\n",client_arr[i].name);
            printf("\t Email: %s\t Phone: %s\n\n",client_arr[i].mail,client_arr[i].phone);
        }
    }
}

void delete_element(void)
{
    int i ;
    int index ;
    char delete_name[10];
    printf("Enter Name to be deleted: ");
    scanf("%s",&delete_name);
    printf("\n");
    for(i=0;i<=counter-1;i++)
        {
        if(!(strcmp(client_arr[i].name, delete_name)))
        {
            printf("Client %s is deleted from data base successfully \n\n",client_arr[i].name);
            index=i ;
        for(i=index;i<=counter-1;i++)
            {
            client_arr[i]=client_arr[i+1];
            client_arr[i].id = client_arr[i].id-1;
            }
            }
        }
    counter--;
}


void edit_element(void)
{
    int i;
    char edited_name[10];
    printf("Enter Name to be edited: ");
    scanf("%s",&edited_name);
    printf("\n");
    for(i=0;i<counter-1;i++){
        if(!(strcmp(client_arr[i].name, edited_name))){
            printf("This is client %s\n",client_arr[i].name);
            printf("\t Email: %s\t Phone: %s\n\n",client_arr[i].mail,client_arr[i].phone);
            printf("Edit This Client\n Enter Client Name: ");
            scanf("%s",&client_arr[i].name);
            printf("\n Enter Client Mail: ");
            scanf("%s",&client_arr[i].mail);
            printf("\n Enter Client Phone: ");
            scanf("%s",&client_arr[i].phone);
            printf("\n Client Edited Successfully \n Here is your New Client Data");
            printf("\tName: %s\t Email: %s\t Phone: %s\n\n",client_arr[i].name,client_arr[i].mail,client_arr[i].phone);
        }
    }
}

void add_element(client_n new_client)
{
    client_arr[counter-1] = new_client;
    printf("\n\nYou added %s To Data base \n",client_arr[counter-1].name);
    printf("\t Email: %s\t Phone: %s\n\n",client_arr[counter-1].mail,client_arr[counter-1].phone);
    counter++;
}

void display(void)
{
    unsigned int i;
    for(i=0;i<counter-1;i++){
        printf("Client %u:\n\n",i+1);
        printf("\t Name: %s\t Email: %s\t Phone: %s\n\n",client_arr[i].name,client_arr[i].mail,client_arr[i].phone);
    }
}

void save(void)
{
    FILE *fpt;
    fpt = fopen("save.csv", "w");
    int i;
    for(i=0;i<counter;i++)
    {
        fprintf(fpt,"%d, %s, %s, %s", client_arr[i].id, client_arr[i].name, client_arr[i].mail, client_arr[i].phone);
    }
    fclose(fpt);
}

void get_data(char* file_name)
{
    int i = 0;
    int j = 0;
    char *token;
    FILE *fp;
    char row[50];
   fp = fopen(file_name,"r");
   while(1) {
      if( feof(fp) ) {
         break ;
      }
      fgets(row, 50, fp);
      token = strtok(row, ",");
      counter++;
        while(token != NULL)
        {
            if(i == 0){
            client_arr[j].id = atoi(token);
            //strcpy(client_arr[j].id,token);
          }
          else if (i == 1){
            strcpy(client_arr[j].name,token);
          }
          else if (i == 2){
            strcpy(client_arr[j].mail,token);
          }
          else if (i == 3){
            strcpy(client_arr[j].phone,token);
          }
          i++;
          if(i == 4){
            i = 0;
            j++;
          }
            token = strtok(NULL, ",");
        }
   }
   fclose(fp);
}


