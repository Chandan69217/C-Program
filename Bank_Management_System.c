/**
 * @file Bank_Management_System.c
 * @author Chandan Sharma (Chandansharma69217@gmail.com)
 * @brief This Program is About Bank Management. Such As a Customer's Can Access Own Account 
 *        and Check All Feature Provided by the Banks. (View records,Withdraw and deposit & ATM Feature).
 * @version 0.1
 * @date 2023-04-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include"stdio.h"
#include"conio.h"
#include"windows.h"

/* ******************************************* Global Veriables ************************************************** */
int Main_Choice;

/* ****************************************** Function Declaration ********************************************** */
int calculateAge(int year);
void forDelay(int j);
void newAccount();
void menu();
void close();
void see();

/* ****************************************** Structure Decleration ********************************************** */

struct date{
    int day,month,year;
};

struct details {
 char name[50];
 int age;
 double acc_no;
 char address[200];
 char citizenship[15];
 struct date deposit,dob,withdrawal;
 double phone_no;
 float balance;
 char gender[10];
 char Account_type[15];
}add,check,transaction,update,reminder;

/* **************************************** Function Defination ************************************************* */

void forDelay(int j){
 int i;
 for (i = 0; i <= j; i++)
     ;
}


void newAccount(){
    
    FILE *fp;
    fp = fopen("Customer.txt","a+");
    account_no:
    system("cls");
    system("color 7");
    printf("\n\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ADD CUSTOMER'S RECORDS \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t\t\t\t Enter today's date(dd/mm/yyyy):- ");
    fflush(stdin);
    scanf("%d/%d/%d",&add.deposit.day,&add.deposit.month,&add.deposit.year);
    printf("\n\t\t\t\t\t Enter Account Number:- ");
    fflush(stdin);
    scanf("%.0lf",&check.acc_no);
    while(fscanf(fp,"%s %s %d/%d/%d %d %s %lf %.0lf %s %f %s",add.name,add.gender,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,add.citizenship,&add.phone_no,&add.acc_no,add.Account_type,&add.balance,add.address)!=EOF){
        if(check.acc_no==add.acc_no){
            printf("\n\n\t\t\t\t\t Account number already in use !!");
            forDelay(2000000000);
            goto account_no;
        }
    }
    add.acc_no = check.acc_no;
    printf("\n\n\t\t\t\t\t Enter Customer's name:- ");
    fflush(stdin);
    gets(add.name);
    printf("\n\t\t\t\t\t Enter your gender:- ");
    fflush(stdin);
    scanf("%s",add.gender);
    printf("\n\t\t\t\t\t Enter date of birth(dd/mm/yy):- ");
    scanf("%d/%d/%d",&add.dob.day,&add.dob.month,&add.dob.year);
    add.age = calculateAge(add.dob.year);
    printf("\n\t\t\t\t\t Enter citizenship:- ");
    scanf("%s",add.citizenship);
    printf("\n\t\t\t\t\t Enter phone no:- ");
    scanf("%lf",&add.phone_no);
    printf("\n\t\t\t\t\t Account Type: \n\t\t\t\t\t  # Saving \n\t\t\t\t\t  # Current \n\t\t\t\t\t  # Fixed1(for 1 year) \n\t\t\t\t\t  # Fixed2(for 2 year) \n\t\t\t\t\t  # Fixed3(for 3 year)");
    printf("\n\n\t\t\t\t\t Enter account type:- ");
    scanf("%s",add.Account_type);
    printf("\n\t\t\t\t\t Enter your deposit amount:- $");
    scanf("%f",&add.balance);
    printf("\n\t\t\t\t\t Enter your address:- ");
    fflush(stdin);
    gets(add.address);

    fprintf(fp,"%s %s %d/%d/%d %d %s %.0lf %.0lf %s %.2f %s",add.name,add.gender,add.dob.day,add.dob.month,add.dob.year,add.age,add.citizenship,add.phone_no,add.acc_no,add.Account_type,add.balance,add.address);
    fclose(fp);

    printf("\n\n\t\t\t\t\t Account Created Successfully !!");
    invalid:
    printf("\n\n\t\t\t\t\t Enter 1 to go to main Menu & 0 to exit: ");
    scanf("%d",&Main_Choice);
    if(Main_Choice==1){
        menu();
    }else if(Main_Choice==0){
        close();
        printf("\n");
        system("pause");
    }else{
        printf("\n\n\t\t\t\t\t Invalid Choice !!\a");
        forDelay(2000000000);
        goto invalid;
    }
}


int calculateAge(int year){
    int YourAge=0;
    if(add.deposit.year>=year){
        YourAge = add.deposit.year - year;
    }else{
        YourAge = 0;
    }
    return YourAge;
}

void close(){
    
   printf("\n\n\t\t\t\t  ## ##   ###  ##    ##     ###  ##  ### ##     ##     ###  ##");
     printf("\n\t\t\t\t ##   ##   ##  ##     ##      ## ##   ##  ##     ##      ## ##");
     printf("\n\t\t\t\t ##        ##  ##   ## ##    # ## #   ##  ##   ## ##    # ## #");
     printf("\n\t\t\t\t ##        ## ###   ##  ##   ## ##    ##  ##   ##  ##   ## ##");
     printf("\n\t\t\t\t ##        ##  ##   ## ###   ##  ##   ##  ##   ## ###   ##  ##");
     printf("\n\t\t\t\t ##   ##   ##  ##   ##  ##   ##  ##   ##  ##   ##  ##   ##  ##");
     printf("\n\t\t\t\t  ## ##   ###  ##  ###  ##  ###  ##  ### ##   ###  ##  ###  ##");
}

void see(){
    FILE *View;
    float time,interest;
    int rate,test=0,choice;
    View = fopen("Customer.txt","r");
    system("cls");
    printf("\n\n\t\t\t\t\t Do you want to check by\n\t\t\t\t\t 1.Account number \n\t\t\t\t\t 2. Account holder name \n\n\t\t\t\t\t Choice your option:-  ");
    scanf("%d",&choice);
    if(choice==1){
        printf("\n\n\t\t\t\t\t Enter account number:- ");
        scanf("%.0lf",&check.acc_no);
        while (fscanf(View, "%s %s %d/%d/%d %d %s %lf %.0lf %s %f %s", add.name, add.gender, &add.dob.day, &add.dob.month, &add.dob.year, &add.age, add.citizenship, &add.phone_no, &add.acc_no, add.Account_type, &add.balance, add.address) != EOF){
            if(add.acc_no==check.acc_no){
                test++;
                system("cls");
            }
        }
    }
}
void menu(){
    int Choice;
    system("cls");
    system("color 2");
                                  printf("\n\n\t\t\t\t\t           BANKING MANAGEMENT SYSTEM");
    printf("\n\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t\t\t\t [1] Create a new account \n\t\t\t\t\t [2] Update information \n\t\t\t\t\t [3] Transactions ");
    printf("\n\t\t\t\t\t [4] Check the details of existing account \n\t\t\t\t\t [5] Remove existing account \n\t\t\t\t\t [6] View customer's list ");
    printf("\n\t\t\t\t\t [7] ATM Feature \n\t\t\t\t\t [8] Logout \n\n\n\t\t\t\t\t Enter your choice >>>>>> ");
    scanf("%d",&Choice);

    switch(Choice){
        case 1: newAccount();
        break;
        case 2: 
        break;
        case 3:
        break;
        case 4: see();
        break;
        case 5:
        break;
        case 6:
        break;
        case 7:
        break;
        case 8: close(); printf("\n"); system("pause");
        break;
        default:
        printf("\n\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 INVALID CHOICE !! \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    }
}


int main(){

    char SavePassword[10] = "Chandan",GetPassword[10];
    int i=0;
    Login_try:
    system("cls");
    printf("\n\n\t\t\t\t\t Bank Management System\n\n\t\t\t\t\t\tUser Login");
    printf("\n\n\n\t\t\t\t\t Enter Password to Login:- ");
    scanf("%s",&GetPassword);
    
        if(strcmp(SavePassword,GetPassword)==0){
            printf("\n\t\t\t\t\t\t Password Match!\n\nLOADING");

            for(i=1;i<=10;i++){
                forDelay(200000000);
                printf(". ");
            }
            printf("\n");
            system("pause");
            system("cls");
            menu();

    }else{
        printf("\n\nWrong Password!!\a\a\a\a");
        printf("\n\nEnter 1 to try again and 0 to Exit:");
        scanf("%d",&Main_Choice);
        if(Main_Choice==1){
            system("cls");
            main();
        }else if(Main_Choice==0){
            system("cls");
            close();
            printf("\n");
            system("pause");
        }else{
            printf("\nInvalid!!");
            forDelay(1000000000);
            system("cls");
            goto Login_try;
        }
    }
    return 1;
}