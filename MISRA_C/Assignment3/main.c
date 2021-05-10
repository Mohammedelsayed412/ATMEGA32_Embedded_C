#include <stdio.h>
#include "math.h"
#include "header.h"
#include<string.h>
#include<stdbool.h>

client_n client_arr[10] ;
int32_t counter = 0;
int32_t service_num ;
int32_t main(void)
{
    printf("\t\t\t Welcome To Data Base Program\n");
    printf("\t\t\t -----------------------------\n\n\n");
    while(1){
    counter = 0;
    get_data("data.csv");
    printf("Please Select a Service .....\n\n\n");
    printf("(1) Display Clients \t (2) Add Client \t (3) Delete Client \t (4) Edit Client \t \n\n");
    printf("(5) Search With Name \t (6) Search with phone\n\n\n");
    printf("Enter Service Number: ");
    scanf("%d",&service_num);
    printf("\n\n");
    if(service_num == 1){
        printf("Here is our data base .....\n\n\n");
        display();
    }
    else if(service_num == 2){
        client_n new_client = {"mail","phone",0,"name"};
        printf("Adding New Client.....\n");
        printf("Ender Client Name: ");
        scanf("%s",new_client.name);
        printf("\nEnder Client email: ");
        scanf("%s",new_client.mail);
        printf("\nEnder Client phone: ");
        scanf("%s",new_client.phone);
        new_client.id = counter;
        add_element(new_client);
        printf("\n\n\n Here is Our New data base.....\n\n\n");
        display();
    }
    else if(service_num == 3)
    {
        delete_element();
        printf("\n\n\n Here is Our New data base.....\n\n\n");
        display();
    }
    else if(service_num == 4)
    {
        edit_element();
        printf("\n\n\n Here is Our New data base.....\n\n\n");
        display();
    }
    else if(service_num == 5)
    {
        search_name();
    }
    else if(service_num == 6)
    {
        search_phone();
    }
    else
    {
        /*The last else statment*/
    }
    printf("****************************************************************************************************\n\n\n\n\n");
    }

}
