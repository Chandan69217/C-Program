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
int Main_Choice;    // for main choice !!
float Balance = 25000.00; // for atm balance !!

/* ****************************************** Function Declaration ********************************************** */
int calculateAge(int year);
void forDelay(int j);
void newAccount();
void menu();
void close();
void see();
void forAsk();
float interest(float time,float amount,int rate);    
void view_list();
void delete();
void transactions();
void update();
void atmLogin();
void atmMainMenu();
void atmCheckBalance(float balance);
float atmDeposit(float amount);
float atmCashWithdrawal(float amount);

/* ****************************************** Structure Decleration ********************************************** */

struct date{
    int day,month,year;
};

struct details {
 char name[30];
 int age;
 double acc_no;
 char address[150];
 char citizenship[15];
 struct date deposit,dob,withdrawal;
 double phone_no;
 float balance;
 char gender[10];
 char Account_type[15];
}add,check,trans;

/* **************************************** Function Defination ************************************************* */

void forDelay(int j){
 int i;
 for (i = 0; i <= j; i++)
     ;
}

void forAsk(){
 invalid:
 printf("\n\n\t\t\t\t\t Enter 1 to go to main Menu & 0 to exit: ");
 fflush(stdin);
 scanf("%d", &Main_Choice);
 if(Main_Choice==1){
     menu();
 }else if(Main_Choice==0){
     close();
     printf("\n\n\t\t\t\t\t\t");
     system("pause");
     exit(0);
 }else{
     printf("\n\n\t\t\t\t\t Invalid Choice !!\a\a\a\a\a");
     forDelay(2000000000);
     goto invalid;
 }

}

float interest(float time, float amount, int rate){
      float SI;
      SI=(rate*time*amount)/100.0;
      return (SI);
}

void delete(){
    FILE *old,*new;
    int test=0;
    old=fopen("Customer.dat","r");
    new=fopen("temp.dat","w");
    system("cls");
    system("color 4");
    if(old==NULL || new == NULL){
        printf("\n\n\t\t\t\t\t Error while opening file....\a\a\a\a\a");
    }
    printf("\n\n\t\t\t\t\t Enter account no of customer to remove:- ");
    fflush(stdin);
    scanf("%lf",&check.acc_no);
    while(fread(&add,sizeof(add),1,old)==1){
        if(add.acc_no==check.acc_no){
            test=1;
            system("cls");
            printf("\n\n\t\t\t\t\t Account no: %ld has been removed sucessfully !!",add.acc_no);
        }else{
            fwrite(&add,sizeof(add),1,new);
        }
    }
    if(test!=1){
        printf("\n\n\t\t\t\t\t Incorrect account no / account no not found !!! \a\a\a\a\a ");
        forDelay(2000000000);
    }
    fclose(old);
    fclose(new);
    remove("Customer.dat");
    rename("temp.dat","Customer.dat");
    forAsk();
}


void update(){
    FILE *old,*new;
    int test=0,ch;
    
    old=fopen("Customer.dat","r");
    new=fopen("temp.dat","w");
    system("cls");
    system("color 7");
    printf("\n\n\t\t\t\t\t Enter account no:- ");
    fflush(stdin);
    scanf("%lf",&check.acc_no);
    while(fread(&add,sizeof(add),1,old)==1){
        if(add.acc_no==check.acc_no){
            test=1;
            updateInvalid:
            system("cls");
            printf("\n\n\t\t\t\t\t Which information do you want to change? \n\n\t\t\t\t\t [1] Name \n\t\t\t\t\t [2] D.O.B \n\t\t\t\t\t [3] Phone no \n\t\t\t\t\t [4] Address \n\n\t\t\t\t\t Enter your choice >>>>>> ");
            fflush(stdin);
            scanf("%d",&ch);
            if(ch==1){
                system("cls");
                printf("\n\n\t\t\t\t\t Enter new Name:- ");
                fflush(stdin);
                gets(add.name);
                fwrite(&add,sizeof(add),1,new);
                printf("\n\n\t\t\t\t\t Please wait");
                for(int i=1;i<8;i++){
                    printf(" .");
                    forDelay(1000000000);
                }
                printf("\n\n\t\t\t\t\t     Changes Saved !!");
            }else if(ch==2){ 
                system("cls");
                printf("\n\n\t\t\t\t\t Enter new date of birth(dd/mm/yy):- ");
                fflush(stdin);
                scanf("%d/%d/%d",&add.dob.day,&add.dob.month,&add.dob.year);
                add.age=calculateAge(add.dob.year);
                fwrite(&add,sizeof(add),1,new);
                printf("\n\n\t\t\t\t\t Please wait");
                for(int i=1;i<8;i++){
                    printf(" .");
                    forDelay(1000000000);
                }
                printf("\n\n\t\t\t\t\t     Changes Saved !!");
            }else if(ch==3){
                system("cls");
                printf("\n\n\t\t\t\t\t Enter new Phone no:- ");
                fflush(stdin);
                scanf("%lf",&add.phone_no);
                fwrite(&add,sizeof(add),1,new);
                printf("\n\n\t\t\t\t\t Please wait");
                for(int i=1;i<8;i++){
                    printf(" .");
                    forDelay(1000000000);
                }
                printf("\n\n\t\t\t\t\t     Changes Saved !!");
            }else if(ch==4){
                system("cls");
                fflush(stdin);
                printf("\n\n\t\t\t\t\t Enter new address:- ");
                fflush(stdin);
                gets(add.address);
                fwrite(&add,sizeof(add),1,new);
                printf("\n\n\t\t\t\t\t Please wait");
                for(int i=1;i<8;i++){
                    printf(" .");
                    forDelay(1000000000);
                }
                printf("\n\n\t\t\t\t\t     Changes Saved !!");
            }else if(ch<1||ch>4){
                printf("\n\n\t\t\t\t\t Invalid Choice !!\a\a\a\a\a");
                forDelay(2000000000);
                goto updateInvalid;
            }
        }else{
            fwrite(&add,sizeof(add),1,new);
        }
    }
    if(test!=1){
        printf("\n\n\t\t\t\t\t Incorrect account no / account no not found !!! \a\a\a\a\a");
        forDelay(2000000000);
    }
    fclose(old);
    fclose(new);
    remove("Customer.dat");
    rename("temp.dat","Customer.dat");
    forAsk();
}
void newAccount(){
    
    FILE *fp;
    fp = fopen("Customer.dat","a+");
    if(fp==NULL){
        system("cls");
        printf("\n\n\t\t\t\t\t Error while opening file....\a\a\a\a\a");
        close();
        system("pause");
        return;
    }
    account_no:
    rewind(fp);
    system("cls");
    system("color 7");
    printf("\n\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ADD CUSTOMER'S RECORDS \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t\t\t\t Enter today's date(dd/mm/yyyy):- ");
    fflush(stdin);
    scanf("%d/%d/%d",&add.deposit.day,&add.deposit.month,&add.deposit.year);
    printf("\n\t\t\t\t\t Enter Account Number:- ");
    fflush(stdin);
    scanf("%lf",&check.acc_no);

    while (fread(&add,sizeof(add),1,fp)==1)
    {
     if (check.acc_no == add.acc_no)
     {
         printf("\n\n\t\t\t\t\t Account number already in use !! \a\a\a\a\a");
         forDelay(2000000000);
         goto account_no;
     }
    }
    add.acc_no = check.acc_no;
    printf("\n\n\t\t\t\t\t Enter Customer's name:- ");
    fflush(stdin);
    gets(add.name);
    //scanf("%s",add.name);
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
    printf("\n\t\t\t\t\t Account Type: \n\t\t\t\t\t  # Saving \n\t\t\t\t\t  # Current \n\t\t\t\t\t  # Fixed1 (for 1 year) \n\t\t\t\t\t  # Fixed2 (for 2 year) \n\t\t\t\t\t  # Fixed3 (for 3 year)");
    printf("\n\n\t\t\t\t\t Enter account type:- ");
    scanf("%s",add.Account_type);
    printf("\n\t\t\t\t\t Enter your deposit amount:- $");
    fflush(stdin);
    scanf("%f",&add.balance);
    printf("\n\t\t\t\t\t Enter your address:- ");
    fflush(stdin);
    gets(add.address);
    fwrite(&add,sizeof(add),1,fp);
    fclose(fp);
    printf("\n\n\t\t\t\t\t Account Created Successfully !!");
    forAsk();
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

void view_list(){
    int test;
    FILE *View;
    View = fopen("Customer.dat","r");
    if(View==NULL){
        printf("\n\n\t\t\t\t\t Error while opening file...!!\a\a\a\a\a");
        forDelay(2000000000);
        return;
    }
    system("cls");
    system("color 7");
    printf("\n\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 List of Customers \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\xB2\xB2 Account no \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Name  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Phone  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Address  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    while(fread(&add,sizeof(add),1,View)==1){
        printf("\n\n   %.0lf\t\t%s\t\t%.0lf\t%s",add.acc_no,add.name,add.phone_no,add.address);
        test++;
    }
    fclose(View);
    if(test==0){
        printf("\n\n\t\t\t\t\t No Records Found !!");
    }
    forAsk();
}

void transactions(){
    int test=0, ch;
    FILE *old,*new;
    old = fopen("Customer.dat","r");
    new = fopen("temp.dat","w");
    if (old == NULL || new == NULL)
    {
        printf("\n\n\t\t\t\t\t Error while opening file... !!!\a\a\a\a\a");
        forDelay(2000000000);
        return;
    }
    system("cls");
    system("color 7");
    printf("\n\n\t\t\t\t\t Enter Account no:- ");
    fflush(stdin);
    scanf("%lf", &trans.acc_no);
    while (fread(&add,sizeof(add),1,old)==1){
        if(trans.acc_no==add.acc_no){
            test=1;
            if(strcmpi(add.Account_type,"Fixed1")==0||strcmpi(add.Account_type,"Fixed2")==0||strcmpi(add.Account_type,"Fixed3")==0){
                printf("\n\n\t\t\t\t\t YOU CANNOT DEPOSIT OR WITHDRAWAL CASH IN FIXED ACCOUNTS !!!");
                forDelay(2000000000);
                forAsk();
            }else{
                transaction_invalid:
                system("cls");
                printf("\n\n\t\t\t\t\t\t Do you want to \n\n\t\t\t\t\t [1] Deposit \n\t\t\t\t\t [2] Withdrawal \n\n\t\t\t\t\t Enter Your Choice >>>>>>>> ");
                fflush(stdin);
                scanf("%d",&ch);
                if(ch==1){
                    printf("\n\n\t\t\t\t\t Enter to deposit $ ");
                    fflush(stdin);
                    scanf("%f",&trans.balance);
                    add.balance+=trans.balance;
                    fwrite(&add,sizeof(add),1,new);
                    system("cls");
                    printf("\n\n\t\t\t\t\t Transaction Under Process !! \n\t\t\t\t\t please wait");
                    for(int i =0;i<10;i++){
                        printf(". ");
                        forDelay(200000000);
                    }
                    printf("\n\n\t\t\t\t\t Deposit sucessfully to your account !!! \n");
                }else if(ch==2){
                    printf("\n\n\t\t\t\t\t Enter withdrawal amount $ ");
                    fflush(stdin);
                    scanf("%f", &trans.balance);
                    add.balance -= trans.balance;
                    fwrite(&add, sizeof(add), 1, new);
                    system("cls");
                    printf("\n\n\t\t\t\t\t Transaction Under Process !! \n\t\t\t\t\t please wait");
                    for (int i = 0; i < 10; i++)
                    {
                        printf(". ");
                        forDelay(200000000);
                    }
                    printf("\n\n\t\t\t\t\t %.2f Withdrawal sucessfully from your account !!! \n\t\t\t\t\t Available Balance $ %.2f \n",trans.balance,add.balance);
                }else{
                    printf("\n\n\t\t\t\t\t        Invalid Choice !!\a\a\a\a\a");
                    forDelay(2000000000);
                    goto transaction_invalid;
                }
            }
        }else{
              fwrite(&add,sizeof(add),1,new);
        }
    }
    fclose(old);
    fclose(new);
    remove("Customer.dat");
    rename("temp.dat","Customer.dat");
    if(test==0){
        printf("\n\n\t\t\t\t\t Incorrect account no / account no not found !!! ");
        forDelay(1000000000);
    }
    forAsk();
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
    system("color 7");
    FILE *View;
    float time,intest;
    int rate,test=0,choice;
    View = fopen("Customer.dat","r");
    if(View == NULL){
        system("cls");
        printf("\n\n\t\t\t\t\t Error while opening file....\a\a\a\a\a");
        close();
        system("pause");
        return;
    }
    InvalidSearch:
    system("cls");
    printf("\n\n\t\t\t\t\t Do you want to check by\n\t\t\t\t\t 1.Account number \n\t\t\t\t\t 2.Account holder name \n\n\t\t\t\t\t Choice your option:-  ");
    fflush(stdin);
    scanf("%d",&choice);
    if(choice<1||choice>2){
        printf("\n\n\t\t\t\t\t Invalid Choice!!\a\a\a\a\a");
        forDelay(2000000000);
        goto InvalidSearch;

    }
    if(choice==1){
        printf("\n\n\t\t\t\t\t Enter account number:- ");
        fflush(stdin);
        scanf("%lf",&check.acc_no);
        while (fread(&add,sizeof(add),1,View)==1)
        {
         if (add.acc_no == check.acc_no)
         {
             test = 1;
             system("cls");
             printf("\n\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Customers Details \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
             printf("\n\n\t\t\t\t\t Name:- %s \n\t\t\t\t\t Gender:- %s \n\t\t\t\t\t Date of birth:- %d/%d/%d \n\t\t\t\t\t Age:- %d \n\t\t\t\t\t Citizenship:- %s \n\t\t\t\t\t Account number:- %.0lf \n\t\t\t\t\t Account Type:- %s \n\t\t\t\t\t Available Balance :- %.2f \n\t\t\t\t\t Deposit Date:- %d/%d/%d \n\t\t\t\t\t Address:- %s", add.name, add.gender, add.dob.day, add.dob.month, add.dob.year, add.age, add.citizenship, add.acc_no, add.Account_type, add.balance, add.deposit.day, add.deposit.month, add.deposit.year, add.address);

             if(strcmpi(add.Account_type,"Fixed1")==0){
                time=1.0;
                rate=9;
                intest=interest(time,add.balance,rate);
                printf("\n\n\t\t\t\t\t You will get $%.2f as interest on %d/%d/%d",intest,add.deposit.day,add.deposit.month,add.deposit.year+1);
             }else if(strcmpi(add.Account_type,"Fixed2")==0){
                time=2.0;
                rate=11;
                intest=interest(time,add.balance,rate);
                printf("\n\n\t\t\t\t\t You will get $%.2f as interest on %d/%d/%d",intest,add.deposit.day,add.deposit.month,add.deposit.year+2);
             }else if(strcmpi(add.Account_type,"Fixed3")==0){
                time=3.0;
                rate=13;
                intest=interest(time,add.balance,rate);
                printf("\n\n\t\t\t\t\t You will get $%.2f as interest on %d/%d/%d",intest,add.deposit.day,add.deposit.month,add.deposit.year+3);
             }else if(strcmpi(add.Account_type,"Saving")==0){
                time=1.0/12.0;
                rate=8;
                intest=interest(time,add.balance,rate);
                printf("\n\n\t\t\t\t\t You will get $%.2f as interest on %d of every month",intest,add.deposit.day);
             }else if(strcmpi(add.Account_type,"Current")==0){
                printf("\n\n\t\t\t\t\t You will get no interest\a\a");
             }
             fclose(View);
             forAsk();
         }
        }
    }else if(choice == 2){
        printf("\n\n\t\t\t\t\t Enter Customer Name:- ");
        fflush(stdin);
        gets(check.name);
        while(fread(&add,sizeof(add),1,View)==1){
         if (strcmpi(add.name,check.name)==0)
         {
             if(test==0){
             system("cls");
             printf("\n\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Customers Details \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
             }
             test=1;
             printf("\n\n\t\t\t\t\t Name:- %s \n\t\t\t\t\t Gender:- %s \n\t\t\t\t\t Date of birth:- %d/%d/%d \n\t\t\t\t\t Age:- %d \n\t\t\t\t\t Citizenship:- %s \n\t\t\t\t\t Account number:- %.0lf \n\t\t\t\t\t Account Type:- %s \n\t\t\t\t\t Available Balance :- %.2f \n\t\t\t\t\t Deposit Date:- %d/%d/%d \n\t\t\t\t\t Address:- %s", add.name, add.gender, add.dob.day, add.dob.month, add.dob.year, add.age, add.citizenship, add.acc_no, add.Account_type, add.balance, add.deposit.day, add.deposit.month, add.deposit.year, add.address);

             if(strcmpi(add.Account_type,"Fixed1")==0){
                time=1.0;
                rate=9;
                intest=interest(time,add.balance,rate);
                printf("\n\n\t\t\t\t\t You will get $%.2f as interest on %d/%d/%d",intest,add.deposit.day,add.deposit.month,add.deposit.year + 1);
             }else if(strcmpi(add.Account_type,"Fixed2")==0){
                time=2.0;
                rate=11;
                intest=interest(time,add.balance,rate);
                printf("\n\n\t\t\t\t\t You will get $%.2f as interest on %d/%d/%d",intest,add.deposit.day,add.deposit.month,add.deposit.year + 2);
             }else if(strcmpi(add.Account_type,"Fixed3")==0){
                time=3.0;
                rate=13;
                intest=interest(time, add.balance, rate);
                printf("\n\n\t\t\t\t\t You will get $%.2f as interest on %d/%d/%d",intest,add.deposit.day,add.deposit.month,add.deposit.year + 3);
             }else if(strcmpi(add.Account_type,"Saving")==0){
                time=1.0/12.0;
                rate=8;
                intest=interest(time,add.balance,rate);
                printf("\n\n\t\t\t\t\t You will get $%.2f as interest on %d of every month",intest,add.deposit.day);
             }else if(strcmpi(add.Account_type,"Current")==0){
                printf("\n\n\t\t\t\t\t You will get no interest\a\a");
             }
         }
        }
        fclose(View);
        if(test==1)
        forAsk();
    }
    if(test==0)
    {
        printf("\n\n\t\t\t\t\t No record matched!!");z
        fclose(View);
        forAsk();
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
    fflush(stdin);
    scanf("%d",&Choice);

    switch(Choice){
        case 1: newAccount();
        break;
        case 2: update();
        break;
        case 3: transactions();
        break;
        case 4: see();
        break;
        case 5: delete();
        break;
        case 6: view_list();
        break;
        case 7: atmLogin();
        break;
        case 8: close(); printf("\n\n\t\t\t\t\t\t"); system("pause");
        break;
        default:
        printf("\n\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 INVALID CHOICE !! \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\a\a\a\a");
        forDelay(2000000000);
        menu();
    }
}

/* *********************************************** Main **************************************************** */
int main(){

    char SavePassword[10] = "Chandan",GetPassword[10];
    int i=0;
    Login_try:
    system("cls");
    printf("\n\n\t\t\t\t\t Bank Management System\n\n\t\t\t\t\t\tUser Login");
    printf("\n\n\n\t\t\t\t\t Enter Password to Login:- ");
    fflush(stdin);
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
        printf("\n\nEnter 1 to try again and 0 to Exit: ");
        scanf("%d",&Main_Choice);
        if(Main_Choice==1){
            system("cls");
            main();
        }else if(Main_Choice==0){
            system("cls");
            close();
            printf("\n");
            system("pause");
            exit(0);
        }else{
            printf("\nInvalid!!");
            forDelay(1000000000);
            system("cls");
            goto Login_try;
        }
    }
    return 1;
}

/* ****************************************** ATM Features ************************************************* */

void atmLogin(){
    
    int setPassword=69217,getPass;
    system("cls");
    system("color 9");
    printf("\n\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ATM FEATURES \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t\t\t\t       Enter your pin:- ");
    fflush(stdin);
    scanf("%d",&getPass);
    if(setPassword==getPass){
        printf("\n\n\t\t\t\t\t\t   Pin matched !!");
        printf("\n\t\t\t\t\t\t   Loading");
        for(int i=1;i<9;i++){
            printf(" .");
            forDelay(1000000000);
        }
        atmMainMenu();
    }else{
        printf("\n\n\t\t\t\t\t\t    Worng pin !!\a\a\a\a\a\a\a");
        forDelay(2000000000);
        atmInvalid:
        printf("\n\n\t\t\t\t\t Enter 1 to try again & 0 to Cancel: ");
        fflush(stdin);
        scanf("%d",&Main_Choice);
        if(Main_Choice==1){
            atmLogin();
        }else if(Main_Choice==0){
            menu();
        }else{
            printf("\n\n\t\t\t\t\t\t   Invalid Choice !!\a\a\a\a\a\a\a");
            forDelay(1000000000);
            goto atmInvalid;
        }
    }
}


void atmMainMenu(){
    int choice,ch;
    system("cls");
    printf("\n\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO ATM FEATURES \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\n\t\t\t\t\t -------------- Please choose one of the option below: --------------");
    printf("\n\n\t\t\t\t\t\t\t     <1> Check Balance \n\t\t\t\t\t\t\t     <2> Deposit \n\t\t\t\t\t\t\t     <3> Cash withdrawal \n\t\t\t\t\t\t\t     <4> Exit \n\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n\n\t\t\t\t\t     Here enter your option:- ");
    fflush(stdin);
    scanf("%d",&choice);
    switch(choice){
        case 1: atmCheckBalance(Balance);
        break;
        case 2: Balance=atmDeposit(Balance);
        break;
        case 3: Balance=atmCashWithdrawal(Balance);
        break;
        case 4: menu();
        break;
        default: printf("\n\n\t\t\t\t\t   Please choose correct options !!\a\a\a\a\a\a\a ");
        forDelay(2000000000);
        atmMainMenu();
    }
    atmMain:
    printf("\n\t\t\t\t\t Would you like to do another transaction \n\t\t\t\t\t <1> YES \n\t\t\t\t\t <2> NO\n");
    printf("\t\t\t\t\t ");
    fflush(stdin);
    scanf("%d",&ch);
    if(ch==1){
        atmMainMenu();
    }
    else if(ch==2){
        menu();
    }
    else{
        printf("\n\n\t\t\t\t\t Please enter correct option !! \a\a\a\a\a\a\a");
        forDelay(2000000000);
        goto atmMain;;
    }
}

void atmCheckBalance(float balance){
    system("cls");
    printf("\n\n\t\t\t\t\t ***** You choose to see your Balance *****\n\n\t\t\t\t\t $$$$ Your Available Balance is:- $ %.2f",balance);
    printf("\n\n\t\t\t\t\t =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
}

float atmDeposit(float amount){
    float depositAmount;
    system("cls");
    printf("\n\n\t\t\t\t\t ***** You choose to deposit money *****\n\n\t\t\t\t\t $$$$ Your Balance is:- $ %.2f", amount);
    printf("\n\n\t\t\t\t\t $$$$ Enter your amount to deposit:- $ ");
    fflush(stdin);
    scanf("%f",&depositAmount);
    amount +=depositAmount;
    printf("\n\n\t\t\t\t\t $$$$ Your new Balance is:- $ %.2f",amount);
    printf("\n\n\t\t\t\t\t =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    return amount;
}

float atmCashWithdrawal(float amount){
    float cashWithdrawalAmount;
    system("cls");
    printf("\n\n\t\t\t\t\t ***** You choose to cash withdrawal ***** \n\n\t\t\t\t\t $$$$ Your Balance is:- $ %.2f",amount);
    printf("\n\n\t\t\t\t\t $$$$ Enter amount to withdrawal:- $ ");
    fflush(stdin);
    scanf("%f",&cashWithdrawalAmount);
    amount -=cashWithdrawalAmount;
    printf("\n\n\t\t\t\t\t $$$$ Your new Balance is:- $ %.2f",amount);
    printf("\n\n\t\t\t\t\t =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    return amount;
}
