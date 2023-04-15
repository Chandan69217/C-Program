/**
 * @file Bus_Reservation_System.c
 * @author @Chandan_Sharma
 * @brief This is the Simple Program to Handle Bus Ticket Booking System and more.
 * @version 0.1
 * @date 2023-03-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<windows.h>

char BusName[5][100] = {"Dazzling Tours", "Nilkamal", "Rajhansh", "Randhani Express","Rock and Roller"};
char CustomerName[32][50] = {'\0'};
char NumberOfSeat[32][2] = {'\0'};

int num1[32] = {0};
int trno;
int choice;

void bus(); // for list of bus
void name_number(int booking, char numstr[100]);
void booking();            // for booking the tickets
int read_number(int trno); // for reading the number from the file
void read_name(int trno);  // for reading the name from the file
void status();             // for printing the status by user input
void status_1(int BusNumber);   // for printing the status while booking ticket
void cancle();
void login(); //for login into Bus Reservation System.
void border(); // for Draw A Line under sentences 
void gotoxy();// for movement at any position
void menu(); // for Menu option.



int main(){

    login();
    do{ 
        menu();
        switch (choice)
        {
        case 5:
            exit(0);

        case 1:
            bus();
            printf("\n\n\t\t     <<<<<<<<<<<<<< Press Any Key To Go Back >>>>>>>>>>>>>>");
            getch();
            break;
        case 2:
            booking();
            break;
        case 3:
            cancel();
            break;
        case 4:
            status();
            break;
        default:
            printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Only Choice Above Options >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
        }

    }while(3);
    return 1;

}



void login(){

    int a=0,i=0;
    char UserName[10],c=' ';
    char Password[10],Code[10];
    char SetUserName[10]="Chandan";
    char SetPassword[10]="Sharma";

    do{
        system("cls");
        printf("\n    ======================================================== LOGIN FROM =================================================");
        printf("\n                                                             Enter UserName:- ");
        scanf("%s",&UserName);
        printf("\n                                                             Enter Password:- ");
        i=0;
        while(i<10){
            Password[i] = getche();
            c = Password[i];
            if(c==13) break;
            else printf("\b*");
            i++;
        }
        Password[i] = '\0';

        if(strcmp(SetUserName,UserName)==0&&strcmp(SetPassword,Password)==0){
            printf("\n\n\t\t\t\t Login Successful Press Any key to Continue.................");
            getch();
            break;
        }else{
            printf("\n\n\n                      SORRY LOGIN IS UNSUCCESFUL !!!");
            a++;
            getch();
        }
        
    }while(a<=2);

    if(a>2){
        printf("\nSorry You Have Entered Wrong UsernName & Password For 3 Times !!!!!!!");
        getch();
    }
   // system("cls");
}



void gotoxy(int x , int y){
    COORD crd = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crd);
}

void border(){
    printf("\n");
    for(int i=0;i<120;i++){
        printf("=");
    }
}


void menu(){
    system("cls");
    printf("    ========================================= WELCOME TO BUS RESERVATION SYSTEM ========================================");

  printf("\n\n\t\t    ##         ##   ##### #####   ####           ## ###     ### ###     ###       ###  ##### #####");
    printf("\n\t\t    ##         ##    ##      ##    ##          ##    ##   ##       ##    #  #   #  #    ##      ##");
    printf("\n\t\t    ##         ##    ##            ##          ##         ##       ##    ##  ###  ##    ##");
    printf("\n\t\t    ##   ##    ##    ### ##        ##          ##         ##       ##    ##   #   ##    ### ##   ");
    printf("\n\t\t    ##  ####   ##    ##            ##          ##         ##       ##    ##       ##    ##");
    printf("\n\t\t    ## ##   ## ##    ##      ##    ##     ##    ##   ##   ##       ##    ##       ##    ##      ##");
    printf("\n\t\t    ###       ###   ##### #####   ##### ####     ## ###     ### ###      ##       ##   ##### #####");
    border();
    // ************************************** Menu OR Options *******************************************************************
    printf("\n\n\t\t\t\t\t\t\t  [1] => View Bus List ");
    printf("\n\n\t\t\t\t\t\t\t  [2] => Book Tickets  ");
    printf("\n\n\t\t\t\t\t\t\t  [3] => Cancle Booking");
    printf("\n\n\t\t\t\t\t\t\t  [4] => Bus Status Bord ");
    printf("\n\n\t\t\t\t\t\t\t  [5] => Logout\n");

    printf("\n\n\t\t\t\t\t\t\t  Enter Your Choice:>>>>>>>>>  ");
    scanf("%d", &choice);
    border();
}


void bus(){
    system("cls");
    printf("\n\n");
    printf("====================================== BUS RESERVATION SYSTEM ====================================");
    printf("\n\n\t\t\t\t    [1] => %s", BusName[0]);
    printf("\n\n\t\t\t\t    [2] => %s", BusName[1]);
    printf("\n\n\t\t\t\t    [3] => %s", BusName[2]);
    printf("\n\n\t\t\t\t    [4] => %s", BusName[3]);
    printf("\n\n\t\t\t\t    [5] => %s", BusName[4]);
}

int read_number(int trno) // for putting the numeric value in the array
{
    char tempstr[100], tempstr2[12] = "number";
    FILE *a, *b;
    char numstr[100];
    int i = 0, j = 0, k;
    itoa(trno, numstr, 10);
    strcat(numstr, ".txt");
    strcat(tempstr2, numstr);
    a = fopen(tempstr2, "a+"); // for open the file to write the name in the file
    while (!feof(a))
    {
        NumberOfSeat[i][j] = fgetc(a);

        if (NumberOfSeat[i][j] == ' ')
        {
            j = 0;
            i++;
        }
        else
        {
            j++;
        }
    }
    k = i;
    for (i = 0; i < k; i++)
    {
        num1[i] = atoi(NumberOfSeat[i]);
    }
    fclose(a);
    return k;
}

void read_name(int trno) // for putting the numeric value in the array
{
    char tempstr1[12] = "status";
    FILE *b;
    char numstr[100];
    int i = 0, j = 0, k = 0;
    itoa(trno, numstr, 10);
    strcat(numstr, ".txt");
    strcat(tempstr1, numstr);
    b = fopen(tempstr1, "a+"); // for open the file to write the name in the file
    while (!feof(b))
    {
        CustomerName[i][j] = fgetc(b);

        if (CustomerName[i][j] == ' ')
        {
            j = 0;
            i++;
        }
        else
        {
            j++;
        }
    }
    CustomerName[i][j] = '\0';
    k = i;
    fclose(b);
}

void status()
{
    system("cls");
    printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
    int i, trno, index = 0, j;
    printf("Enter the number of bus:---->");
    scanf("%d", &trno);
    j = read_number(trno);
    read_name(trno);
    printf("____________________________________________________________________________________________________________________\n");
    printf("                                      Bus.no-->%d---->%s                                                            \n", trno, BusName[trno - 1]);
    printf("____________________________________________________________________________________________________________________\n");
    char tempname[33][10] = {"Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty "};
    for (i = 0; i < j; i++)
    {
        strcpy(tempname[num1[i]], CustomerName[i]);
    }
    for (i = 0; i < 8; i++)
    {
        printf("\t\t\t\t");
        for (j = 0; j < 4; j++)
        {
            printf("%d.%s\t", index + 1, tempname[index + 1]);
            index++;
        }
        printf("\n");
    }
}

void status_1(int BusNumber)
{
    system("cls");
    printf("========================================= Bus Reservation System ==========================================");
    printf("\n\n");
    printf("Your Bus No is %d ************** %s", trno, BusName[trno - 1]);
    int i, index = 0, j;
    j = read_number(trno);
    read_name(trno);
    char tempname[33][10] = {"Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty "};
    for (i = 0; i < j; i++)
    {
        strcpy(tempname[num1[i]], CustomerName[i]);
    }
    for (i = 0; i < 8; i++)
    {
        printf("\t\t\t\t");
        for (j = 0; j < 4; j++)
        {
            printf("%d.%s\t", index + 1, tempname[index + 1]);
            index++;
        }
        printf("\n");
    }

    void booking()
    {
        int i = 0;
        char numstr[100], ch;
        bus(); // for seeing bus number.
        printf("\n\n\t\t\t\t    Enter The Bus No ---> ");
        scanf("%d", &trno);
        system("cls");
        printf("\n\n");
        printf("========================================= Bus Reservation System ==========================================");
        printf("\n\n");
        if (trno <= 5 && trno > 0)
            printf("Your Bus No is %d ************** %s", trno, BusName[trno - 1]);
        else{
    printf("\t<<<<<<<<<< Incorrect Sellection, Please try again >>>>>>>>>>");
    getch();
    return;
    }
    printf("\n\n");
    printf("\n Are you sure to continue with this Selection(y/n): ");
    ch = getche();
    if(ch=='y'||ch=='Y'){
        status_1(trno);

        FILE *f1, *fopen(); // for reading the seats from the user.
        char str1[80] = "32", str2[4], str3[4];
        int seat1, seat2, booking = 0;
        if (trno == 1)
        {
            f1 = fopen("tr1.txt", "r+");
            fgets(str1, 80, f1);
            fclose(f1);
        }
        else if (trno == 2)
        {
            f1 = fopen("tr2.txt", "r+");
            fgets(str1, 80, f1);
            fclose(f1);
        }
        else if (trno == 3)
        {
            f1 = fopen("tr3.txt", "r+");
            fgets(str1, 80, f1);
            fclose(f1);
        }
        else if (trno == 4)
        {
            f1 = fopen("tr4.txt", "r+");
            fgets(str1, 80, f1);
            fclose(f1);
        }
        else if (trno == 5)
        {
            f1 = fopen("tr5.txt", "r+");
            fgets(str1, 80, f1);
            fclose(f1);
        }
        seat1 = atoi(str1); // covert the string into number
        if (seat1 <= 0)
        {
            printf("There is no blank seat in this bus ");
        }
        else
        {
            printf("\n\n\n\t\t\t\tAvailable Seats:------>%d\n", seat1);
            printf("\n\t\t\t\tNumber of Tickets:----->");
            scanf("%d", &booking);
            printf("\n");

            seat1 = seat1 - booking;
            itoa(trno, numstr, 10);
            name_number(booking, numstr);
            printf("\n\t\t\t\tThe Total booking amount is %d", 200 * booking);
            itoa(seat1, str1, 10);
            // for reading the seats from the user.
            if (trno == 1)
            {
                f1 = fopen("tr1.txt", "w");
                fputs(str1, f1);
                fclose(f1);
            }
            else if (trno == 2)
            {
                f1 = fopen("tr2.txt", "w");
                fputs(str1, f1);
                fclose(f1);
            }
            else if (trno == 3)
            {
                f1 = fopen("tr3.txt", "w");
                fputs(str1, f1);
                fclose(f1);
            }
            else if (trno == 4)
            {
                f1 = fopen("tr4.txt", "w");
                fputs(str1, f1);
                fclose(f1);
            }
            else if (trno == 5)
            {
                f1 = fopen("tr5.txt", "w");
                fputs(str1, f1);
                fclose(f1);
            }
        }
    }
}



    void cancle()
    {
        int seat_no, i, j;
        char numstr[100], tempstr2[15] = "number", tempstr1[15] = "status";
        printf("Enter the bus number:---->");
        scanf("%d", &trno);
        itoa(trno, numstr, 10);
        strcat(numstr, ".txt");
        strcat(tempstr1, numstr);
        strcat(tempstr2, numstr);
        read_number(trno);
        read_name(trno);
        status_1(trno);
        printf("Enter the seat number:--->");
        scanf("%d", &seat_no);
        FILE *a, *b;
        a = fopen(tempstr1, "w+");
        b = fopen(tempstr2, "w+");
        for (i = 0; i < 32; i++)
        {
            if (num1[i] == seat_no)
            {
                for (j = 0; j < 32; j++)
                {
                    if (num1[j] != seat_no && num1[j] != 0)
                    {
                        fprintf(b, "%d ", num1[j]);
                        fprintf(a, "%s", CustomerName[j]);
                    }
                    else if (num1[j] == seat_no && num1[j] != 0)
                    {
                        strcpy(CustomerName[j], "Empty ");
                    }
                }
            }
        }
        fclose(a);
        fclose(b);
        printf("\n\n");
        printf("======================================================================================================\n");
        printf("\t\t\t\tYour 200 rupees has been Returned\t\t\t\n");
        printf("======================================================================================================\n");
    }
}