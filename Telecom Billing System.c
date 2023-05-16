/*
Project Title:: Telecom Billing System
Name: Sufyan Azeem
Roll # : FA20-BSE-112
Section : B
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

struct Customer
{

    char phone[100];
    char name[100];
    float amount;
    int id;
    struct Customer *next;

} *head = NULL;

void login();

void customer_login();

void admin_menu();

void insert(char *name, char *phone, float amount, int id);

void Delete(int id);

void update(int id);

void search(int id);

void display();

void check_bill();

void pay_bill();

void delete_bill(int id);

void restoreData();
void first();
void red();
void purple();
void green();
void cyan();
void yellow();
void blue();

int main()
{
    head = NULL;
    int choose;
    first();

    printf("\n");
    purple();
    printf("\n\t\t\t*********************************************************");
    printf("\n\t\t\t--- THE TELECOM BILLING MANAGEMENT SYSTEM---");
    printf("\n\t\t\t*********************************************************\n");
    getch();
    system("cls");

    do
    {
        yellow();
        printf("\n\t\t\t\t\t***********************************************\n");
        printf("\n");
        yellow();
        printf("\t\t\t\t\t|\tPress 1 For Admin Panel\t\t|\n\t\t\t\t\t|\tPress 2 For Customer Panel\t|\n\t\t\t\t\t|\tPress 3 For Exit\t\t|\n");
        yellow();
        printf("\t\t\t\t\t|\tEnter your choice:\t\t|\n");
        scanf("%d", &choose);
        yellow();
        printf("\n\t\t\t\t\t***********************************************\n");
        printf("\n");
        system("cls");

        switch (choose)
        {
        case 1:
            login();

            break;
        case 2:
            customer_login();
            break;
        case 3:
            red();
            printf("\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb Exiting Program \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n");
            red();
            printf("\t\t\t\tLOADING...\n");
            printf("\t\t\t\t\t");
            for (int i = 1; i <= 30; i++)
            {
                for (int j = 1; j <= 51000000; j++)
                    ;
                printf("%c", 177);
            }
            printf("\n\n");
            green();
            printf("\nTHANK YOU\n");
            green();
            printf("FOR USING OUR SERVICE\n");
            break;
        }
    } while (choose != 3);
}

void login()
{
    char pass[90];
    char name[90];
    printf("\n");
    yellow();
    printf("\n\t\t\t*********************************************************");
    yellow();
    printf("\n\t\t\t--------------WELCOME TO THE Admin Panel---------------");
    yellow();
    printf("\n\t\t\t*********************************************************\n");
    yellow();
    printf("\t\t=========================\n");
    blue();
    printf("\t\tEnter username::    ");
    scanf("%s", name);
    blue();
    printf("\n\t\tEnter Password::  ");
    scanf("%s", pass);
    blue();
    printf("\n\t\t=========================\n");
    blue();
    printf("\n\t\t\t\t\t***********************************************\n");
    system("cls");
    if ((strcmp(name, "Sufyan") == 0) && (strcmp(pass, "12345") == 0))
    {
        admin_menu();
    }
    else
    {
        red();
        printf("Invalid Password,Please Try Again");
    }
}

void admin_menu()
{
    struct Customer *customer;
    int choice;
    char phone[100];
    char name[100];
    float amount;
    int id;
    do
    {
        blue();
        printf("\n\t\t\t\t\t|\t1 To Add New Records\t\t|\n\t\t\t\t\t|\t2 To Search Records\t\t|\n"
               "\t\t\t\t\t|\t3 Delete Records\t\t|\n\t\t\t\t\t|\t4 To Update Records\t\t|"
               "\n\t\t\t\t\t|\t5 To Display List Of Records\t|\n\t\t\t\t\t|\t6 To Exit\t\t\t|\n");
        printf("\n");
        blue();
        printf("\t\t=========================");
        blue();
        printf("\n\t\tEnter Choice :: ");
        scanf("%d", &choice);
        blue();
        printf("\n\t\t=========================\n");
        system("cls");

        switch (choice)
        {

        case 1:
            printf("\n");
            yellow();
            printf("\n\t\t\t*********************************************************");
            yellow();
            printf("\n\t\t\t-------------WELCOME TO THE *ADD RECORD* Menu--------------");
            yellow();
            printf("\n\t\t\t*********************************************************\n");
            yellow();
            printf("***************\n");
            blue();
            printf("Enter Name :: ");
            scanf("%s", name);
            blue();
            printf("\nEnter Phone Number :: ");
            scanf("%s", phone);

            fflush(stdin);
            blue();
            printf("\nEnter Amount :: ");
            scanf("%f", &amount);
            blue();
            printf("\nEnter ID :: ");
            scanf("%d", &id);
            FILE *filepointer;
            filepointer = fopen("BilingRecord.csv", "a");
            fprintf(filepointer, "ID,NAME,PHONE,AMOUNT\n");
            fprintf(filepointer, "%d,%s,%s,%f\n", id, name, phone, amount);
            fclose(filepointer);
            insert(name, phone, amount, id);
            blue();
            printf("****************\n");

            system("cls");

            break;
        case 2:
            printf("\n");
            yellow();
            printf("\n\t\t\t*********************************************************");
            yellow();
            printf("\n\t\t\t--------------WELCOME TO THE *Search* Menu---------------");
            yellow();
            printf("\n\t\t\t*********************************************************\n");
            yellow();
            printf("****************\n");
            blue();
            printf("\nEnter ID To Search :: ");
            scanf("%d", &id);
            blue();
            printf("****************\n");
            search(id);
            cyan();
            printf("\n\t\t\t--------------Press Any Key to Continue---------------");
            getch();
            system("cls");

            break;
        case 3:
            printf("\n");
            yellow();
            printf("\n\t\t\t*********************************************************");
            yellow();
            printf("\n\t\t\t------------WELCOME TO THE *Delete RECORD* Menu-------------");
            yellow();
            printf("\n\t\t\t*********************************************************\n");
            yellow();
            printf("****************\n");
            blue();
            printf("\nEnter ID To Delete :: ");
            scanf("%d", &id);
            blue();
            printf("****************\n");
            Delete(id);
            cyan();
            printf("\n\t\t\t--------------Press Any Key to Continue---------------");
            getch();
            system("cls");
            break;
        case 4:
            printf("\n");
            yellow();
            printf("\n\t\t\t*********************************************************");
            yellow();
            printf("\n\t\t\t------------WELCOME TO THE *UPDATE RECORD* Menu--------------");
            yellow();
            printf("\n\t\t\t*********************************************************\n");
            yellow();
            printf("****************\n");
            blue();
            printf("\nEnter ID To Update :: ");
            scanf("%d", &id);
            blue();
            printf("****************\n");
            update(id);
            cyan();
            printf("\n\t\t\t--------------Press Any Key to Continue---------------");
            getch();
            system("cls");
            break;
        case 5:
            printf("\n");
            yellow();
            printf("\n\t\t\t*********************************************************");
            yellow();
            printf("\n\t\t\t------------WELCOME TO THE *DISPLAY RECORD* Menu--------------");
            yellow();
            printf("\n\t\t\t*********************************************************\n");
            display();
            cyan();
            printf("\n\t\t\t--------------Press Any Key to Continue---------------");
            getch();
            system("cls");
            break;
        }

    } while (choice != 6);
}

void customer_login()
{
    int choose;
    do
    {
        printf("\n");
        yellow();
        printf("\n\t\t\t*********************************************************");
        yellow();
        printf("\n\t\t\t--------------WELCOME TO THE Customer Panel---------------");
        yellow();
        printf("\n\t\t\t*********************************************************\n");
        blue();
        printf("\n\t\t\t\t\t|\tPress 1 to Check the bill\t\t|\n\t\t\t\t\t|\tPress 2 to Pay the bill\t\t\t\t|\n");
        blue();
        printf("Enter your Choice\n");
        scanf("%d", &choose);
        system("cls");
        switch (choose)
        {
        case 1:
            printf("\n");
            yellow();
            printf("\n\t\t\t*********************************************************");
            yellow();
            printf("\n\t\t\t-------------WELCOME TO THE *BILLING* Menu--------------");
            yellow();
            printf("\n\t\t\t*********************************************************\n");
            check_bill();
            cyan();
            printf("\n\t\t\t--------------Press Any Key to Continue---------------");
            getch();
            system("cls");
            break;
        case 2:
            pay_bill();
            break;
        }
    } while (choose != 3);
}

void insert(char *name, char *phone, float amount, int id)
{

    struct Customer *customer = (struct Customer *)malloc(sizeof(struct Customer));
    strcpy(customer->phone, phone);
    strcpy(customer->name, name);
    customer->amount = amount;
    customer->id = id;
    customer->next = NULL;

    if (head == NULL)
    {
        head = customer;
    }
    else
    {
        customer->next = head;
        head = customer;
    }
}

void Delete(int id)
{
    int found = 0;
    struct Customer *temp1 = head;
    struct Customer *temp2 = head;
    while (temp1 != NULL)
    {

        if (temp1->id == id)
        {
            cyan();
            printf("\n====================================\n");
            cyan();
            printf("Record With ID %d Is Found !!!\n", id);

            if (temp1 == temp2)
            {
                head = head->next;
                free(temp1);
            }
            else
            {
                temp2->next = temp1->next;
                free(temp1);
            }
            green();
            printf("Record Successfully Deleted !!!\n");
            found++;
            break;
        }

        temp2 = temp1;
        temp1 = temp1->next;
    }
    if (found == 0)
    {
        red();
        printf("Record With ID %d Is Not Found !!!\n", id);
    }
    cyan();
    printf("\n====================================\n");
}

void update(int id)
{

    int flag = 0;

    int choice;

    struct Customer *temp = head;
    while (temp != NULL)
    {

        if (temp->id == id)
        {
            do
            {
                cyan();
                printf("\n====================================\n");
                cyan();
                printf("Record With ID %d Is Found !!!\n", id);
                cyan();
                printf("Enter 1 To Update Phone Number \n");
                cyan();
                printf("Enter 2 To Update Name \n");
                cyan();
                printf("Enter 3 To Update Amount \n");
                scanf("%d", &choice);
                switch (choice)
                {
                case 1:
                    blue();
                    printf("Enter New Phone Number :: ");
                    scanf("%s", temp->phone);
                    cyan();
                    printf("Record Has Been Updated Successfully !!!\n");
                    break;
                case 2:
                    blue();
                    printf("Enter New Name :: ");
                    scanf("%s", temp->name);
                    cyan();
                    printf("Record Has Been Updated Successfully !!!\n");
                    break;
                case 3:
                    blue();
                    printf("Enter new Amount :: ");
                    scanf("%f", &temp->amount);
                    cyan();
                    printf("Record Has Been Updated Successfully !!!\n");
                    break;
                default:
                    break;
                }
                green();
                printf("Record Has Been Updated Successfully !!!\n");
                cyan();
                printf("\n====================================\n");
            } while (choice != 0);
            flag++;
        }
        temp = temp->next;
    }
    if (flag == 0)
    {
        red();
        printf("Record With ID %d Is Not Found !!!\n", id);
    }
}

void search(int id)
{

    struct Customer *temp = head;
    while (temp != NULL)
    {
        if (temp->id == id)
        {
            cyan();
            printf("\n====================================\n");
            cyan();
            printf("Record With ID %d Is Found !!!\n", id);
            cyan();
            printf("Phone Number :: %s\n", temp->phone);
            cyan();
            printf("Name :: %s\n", temp->name);
            fflush(stdin);
            cyan();
            printf("Amount :: %0.4f\n", temp->amount);
            cyan();
            printf("=====================================\n");
            return;
        }
        temp = temp->next;
    }
    cyan();
    printf("=====================================\n");
    red();
    printf("Record With ID %d Is Not Found !!!\n", id);
    printf("=====================================\n");
}

void display()
{

    struct Customer *temp = head;
    FILE *filepointer;
    filepointer = fopen("BilingRecord.csv", "w");
    while (temp != NULL)
    {
        purple();
        printf("\n====================================\n");
        purple();
        printf("Name :: %s\n", temp->name);
        purple();
        printf("Phone :: %s\n", temp->phone);
        purple();

        printf("Amount :: %0.3f\n\n", temp->amount);
        purple();
        printf("\n====================================\n");
        fprintf(filepointer, "ID,NAME,PHONE,AMOUNT\n");
        fprintf(filepointer, "%d,%s,%s,%f\n", temp->id, temp->name, temp->phone, temp->amount);
        temp = temp->next;
    }
    fclose(filepointer);
}
void check_bill()
{
    int id;
    int found = 0;
    struct Customer *temp = head;
    blue();
    printf("\n===============================================\n");
    blue();
    printf("Enter the id :\n");
    scanf("%d", &id);

    while (temp != NULL)
    {
        if (id == temp->id)
        {
            purple();

            printf("Dear Customer! Your Bill For Following Number Is:\n");
            purple();

            printf("Name :: %s\n", temp->name);
            purple();

            printf("Phone :: %s\n", temp->phone);
            purple();

            printf("Amount :: %0.3f\n\n", temp->amount);
            found++;
            break;
        }

        temp = temp->next;
    }
    if (found == 0)
    {
        red();
        printf("No bill found with the following id:\n");
    }

    printf("\n=============================================\n");
}
void pay_bill()
{

    int id;

    int select;
    int found = 0;

    struct Customer *temp;
    temp = head;
    blue();
    printf("Enter the ID::\n");

    scanf("%d", &id);
    while (temp != NULL)
    {

        if (id == temp->id)
        {
            purple();

            printf("The telecom bill for the following id %d is:\n", temp->id);
            purple();

            printf("Name :: %s\n", temp->name);
            purple();

            printf("Amount :: %0.3f\n\n", temp->amount);

            found++;
            cyan();
            printf("Do you want to pay the bill:\n");
            cyan();
            printf("Press 1 to Pay\nPress 2 to Exit\n");

            scanf("%d", &select);

            if (select == 1)
            {

                delete_bill(id);
                green();
                printf("Your bill has been successfully paid\n");
                break;
            }
            else
            {
                red();
                printf("Your transaction has been expired/cancelled\n");
                break;
            }
        }
        temp = temp->next;
    }
    if (found == 0)
    {
        red();
        printf("Id not found\n");
    }
}

void delete_bill(int id)
{
    struct Customer *temp1 = head;
    struct Customer *temp2 = head;
    while (temp1 != NULL)
    {

        if (temp1->id == id)
        {

            if (temp1 == temp2)
            {
                head = head->next;
                free(temp1);
            }
            else
            {
                temp2->next = temp1->next;
                free(temp1);
            }
        }

        temp2 = temp1;
        temp1 = temp1->next;
    }
}
void restoreData()
{
    FILE *filepointer;

    filepointer = fopen("BilingRecord.csv", "r");

    if (!filepointer)
    {
        red();
        printf("No Record Found !!!\n");
    }
    else
    {

        char buffer[1000];

        while (fgets(buffer, 1000, filepointer))
        {
            struct Customer *temp;

            temp = (struct Customer *)malloc(sizeof(struct Customer));

            char *value = strtok(buffer, ",");

            while (value)
            {
                temp->id = atoi(value);

                value = strtok(NULL, ",");

                strcpy(temp->name, value);

                value = strtok(NULL, ",");

                strcpy(temp->phone, value);

                value = strtok(NULL, ",");

                temp->amount = atof(value);

                value = strtok(NULL, ",");
            }

            if (head == NULL)
            {

                head = temp;

                temp->next = NULL;
            }
            else
            {

                struct Customer *temp1;

                temp1 = head;

                while (temp1->next != NULL)
                {
                    temp1 = temp1->next;
                }

                temp1->next = NULL;
            }
        }
    }
    fclose(filepointer);
}
void first()
{

    int i, j;

    cyan();
    printf("\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb DSA Project \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
    green();
    printf("\t\t\t\tLOADING...\n");
    printf("\t\t\t\t\t");
    for (i = 1; i <= 40; i++)
    {
        for (j = 1; j <= 51000000; j++)
            ;
        printf("%c", 177);
    }
    printf("\n\n");
    cyan();
    printf("\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb Presenter of this Project \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
    green();
    printf("\t\t\t\tLOADING...\n");
    printf("\t\t\t\t\t");
    for (i = 1; i <= 30; i++)
    {
        for (j = 1; j <= 51000000; j++)
            ;
        printf("%c", 177);
    }
    printf("\n\n");
    yellow();
    printf("\n\t\t\t\t\t\t*********************************");
    yellow();
    printf("\n\t\t\t\t\t\t|\t  Sufyan Azeem\t\t|");
    yellow();
    printf("\n\t\t\t\t\t\t|\t  FA20-BSE-112\t\t|");
    yellow();
    printf("\n\t\t\t\t\t\t*********************************");
    cyan();
    printf("\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb Welcome to Telecom Billling System \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n");
    green();
    printf("\t\t\t\tLOADING...\n");
    printf("\t\t\t\t\t");
    for (i = 1; i <= 50; i++)
    {
        for (j = 1; j <= 51000000; j++)
            ;
        printf("%c", 177);
    }
    printf("\n\n");
}
void cyan()
{
    printf("\033[0;36m");
}
void purple()
{
    printf("\033[0;35m");
}
void red()
{
    printf("\033[1;31m");
}

void yellow()
{
    printf("\033[1;33m");
}

void green()
{
    printf("\033[0;32m");
}

void blue()
{
    printf("\033[0;34m");
}