/**
 * @file Calendar.c
 * @author Chandan Sharma (Chandansharma69217@gmail.com)
 * @brief  Hello, This program helps in finding out the date and day you want to know about.
 *         and also some extra features like notes,Sunday Holidays,....etc.
 * @version 0.1
 * @date 2023-05-02
 *
 * @copyright Copyright (c) 2023
 *
 */

/* *********************************************** Let's begin ************************************************ */

                                            #include "stdio.h"
                                            #include "conio.h"
                                            #include "windows.h"

/* ********************************************** Global Veriables ********************************************* */

struct Date{
    int day;
    int month;
    int year;
};

struct Remainder{
    int day;
    int month;
    char notes[50];
};

struct  Date date;
struct Remainder R;

COORD xy = {0,0};

/* ****************************************** Function Declaration ******************************************** */

void gotoxy(int x, int y);
void setColor(int Fgcolor);
void clearColor();
void clearConsoleToColor(int Bground,int Fground);
void SetColorAndBackground(int Bground, int Fground);
void forDelay(int delay);
char *getDay(int dd,int mm,int yy);
int getNumberOfDays(int mm,int yy);
int getDayCode(int dd,int mm,int yy);
int getMonthCode(int mm,int yy);
int getYearCode(int rem);
char *getDayName(int rem);
void printMonth(int mm,int yy,int x,int y);
void printMonthName(int mm,int yy);
void increaseMonth(int *mm,int *yy);
void decreaseMonth(int *mm,int *yy);
int checkNotes(int dd,int mm);
void addNotes();
void showNotes(int mm);

/* ****************************************** Program start hare *********************************************** */

int main(){
  clearConsoleToColor(1,15);
  SetConsoleTitle("Calendar || Made by Chandan Sharma");
  int choice;
  char ch;
  while(2){
    system("cls");
    printf("\n\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Calendar \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t\t\t\t [1] Find out the day \n\t\t\t\t\t [2] Print all the day of month \n\t\t\t\t\t [3] Add note \n\t\t\t\t\t [4] Exit");
    printf("\n\n\t\t\t\t\t Enter your choice >>>>>>>> ");
    fflush(stdin);
    scanf("%d",&choice);
    switch(choice){
        case 1: system("cls");
                printf("\n\n\t\t\t\t\t Enter date(dd/mm/yyyy):- ");
                fflush(stdin);
                scanf("%d/%d/%d",&date.day,&date.month,&date.year);
                printf("\n\n\t\t\t\t\t Day is : %s",getDay(date.day,date.month,date.year));
                printf("\n\n\t\t\t\t\t ");
                system("pause");
        break;
        case 2: system("cls");
                printf("\n\n\t\t\t\t\t Enter month and year(mm/yyyy):- ");
                fflush(stdin);
                scanf("%d/%d",&date.month,&date.year);
                ch='a';
                while(ch!='q'|| ch=='Q'){
                system("cls");
                printMonth(date.month,date.year,49,5);
                printf("\n");
                fflush(stdin);
                ch=getch();
                if(ch=='n'||ch=='N'){
                    increaseMonth(&date.month,&date.year);
                    printMonth(date.month,date.year,49,5);
                }
                if(ch=='p'|| ch=='P'){
                    decreaseMonth(&date.month,&date.year);
                    printMonth(date.month,date.year,49,5);
                }
                if(ch=='s'|| ch=='S'){
                    showNotes(date.month);
                    system("cls");
                }
                }
        break;
        case 3:  addNotes();
        break;
        case 4:  exit(0);
        default: printf("\n\n\t\t\t\t\t please enter correct options !!! \a\a\a\a\a\a");
                 forDelay(2000000000); 
    }
  }
  return 1;
}


/* ********************************************* Functions Body ************************************************ */

void increaseMonth(int *mm,int *yy){
    ++*mm;
    if(*mm>12){
        ++*yy;
        *mm=*mm-12;
    }
}

void decreaseMonth(int *mm,int *yy){
    --*mm;
    if(*mm<1){
        --*yy;
        if(*yy<1600){
            printf("\nNo records available !!! \a\a\a\a\a");
            return;
        }
        *mm=*mm+12;
    }
}
void gotoxy(int x, int y){
    xy.X = x; xy.Y = y; // X and Y are Coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),xy);
}

void setColor(int Fgcolor){
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(hStdOut,&csbi)){
        wColor = (csbi.wAttributes & 0xF0) + (Fgcolor & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}

void clearColor(){
    setColor(15);
}

void clearConsoleToColor(int Bground,int Fground){
    WORD wColor = ((Bground & 0x0F)<<4) + (Fground & 0x0F);
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {0,0};
    DWORD count;
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    SetConsoleTextAttribute(hStdOut,wColor);
    if (GetConsoleScreenBufferInfo(hStdOut, &csbi)){
        FillConsoleOutputCharacter(hStdOut, (TCHAR)32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
        FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
        SetConsoleCursorPosition(hStdOut, coord);
    }
    return;
}
void SetColorAndBackground(int Bground, int Fground){
    WORD wColor = ((Bground & 0x0F) << 4) + (Fground & 0x0F);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
    return;
}

void forDelay(int delay){
    for(int i=0;i<delay;i++);
}

char *getDay(int dd,int mm, int yy){
    if(!(mm>=1&&mm<=12)){
        return("Invalid Month Value !!");
    }
    if(!(dd>=1&&dd<=getNumberOfDays(mm,yy))){
        return("Invalid Day Value !!");
    }
    if(yy>=1600){
        return(getDayName(getDayCode(dd,mm,yy)));
    }else{
        return("Please give year more than or equal 1600");
    }
}

int getNumberOfDays(int mm, int yy){
    switch(mm){
        case 1: return(31);
        case 2: if(yy%4==0) return(29);
                else return(28);
        case 3: return(31);
        case 4: return(30);
        case 5: return(31);
        case 6: return(30);
        case 7: return(31);
        case 8: return(31);
        case 9: return(30);
        case 10:return(31);
        case 11:return(30);
        case 12:return(31);
    }
}

int getMonthCode(int mm, int yy){
    int remainder;
    remainder = yy%4;
    switch(mm){
        case 1: if(remainder==0) return(0);
                else return(1);
        case 2: if(remainder==0) return(3);
                else return(4);
        case 3: return(4);
        case 4: return(0);
        case 5: return(2);
        case 6: return(5);
        case 7: return(0);
        case 8: return(3);
        case 9: return(6);
        case 10:return(1);
        case 11:return(4);
        case 12:return(6);
    }
}

int getYearCode(int rem){
    switch(rem){
        case 100: return(4);
        case 200: return(2);
        case 300: return(0);
        case 0:   return(6);
    }
}

char *getDayName(int rem){
    switch(rem){
        case 0: return("Saturday");
        case 1: return("Sunday");
        case 2: return("Monday");
        case 3: return("Tuesday");
        case 4: return("Wednesday");
        case 5: return("Thursday");
        case 6: return("Friday");
    }
}

int  getDayCode(int dd, int mm, int yy){
    int sum=0,rem,y1,y2,y1rem;
    y1=yy%100; y1rem=y1/4; y2=(yy/100)*100;y2=y2%400;
    sum = (dd+getMonthCode(mm,yy)+getYearCode(y2)+y1+y1rem)%7;
    return(sum);
}

void printMonthName(int mm,int yy){
    printf("-------------------------------------------\n");
    gotoxy(35,6);
    switch(mm){
        case 1: printf("\t\t\t January"); break;
        case 2: printf("\t\t\t February"); break;
        case 3: printf("\t\t\t March"); break;
        case 4: printf("\t\t\t April"); break;
        case 5: printf("\t\t\t May"); break;
        case 6: printf("\t\t\t June"); break;
        case 7: printf("\t\t\t July"); break;
        case 8: printf("\t\t\t August"); break;
        case 9: printf("\t\t\t September"); break;
        case 10:printf("\t\t\t October"); break;
        case 11:printf("\t\t\t November"); break;
        case 12:printf("\t\t\t December"); break;
    }
    printf(",%d",yy);
    gotoxy(40,7);
    printf("-------------------------------------------\n");
}

void printMonth(int mm,int yy,int x,int y){
    int nod,day,d=1,isNote=0,x1=x,y1=y,cnt;
    if(!(mm>=1&&mm<=12)){
        printf("\n\n\t\t\t\t\t Invalid Month Value !! \a\a\a\a\a");
        printf("\n\t\t\t\t\t ");
        printf("Press q to exit !!!\a\a\a\a");
        return;
    }
    if(!(yy>=1600)){
        printf("\n\n\t\t\t\t\t Invalid Year Value !! \a\a\a\a\a");
        printf("\n\t\t\t\t\t ");
        printf("Press q to exit !!! \a\a\a\a\a");
        return;
    }
    gotoxy(40,y);
    printMonthName(mm,yy);
    y+=3;
    gotoxy(x,y);
    printf("S   M   T   W   T   F   S   ");
    y++;
    nod=getNumberOfDays(mm,yy);
    day=getDayCode(d,mm,yy);
    switch(day){
        case 0: x=x+24;
                cnt=7;
                break;
        case 1: x=x;
                cnt=1;
                break;
        case 2: x=x+4;
                cnt=2;
                break;
        case 3: x=x+8;
                cnt=3;
                break;
        case 4: x=x+12;
                cnt=4;
                break;
        case 5: x=x+16;
                cnt=5;
                break;
        case 6: x=x+20;
                cnt=6;
                break;
        default: printf("INVALID DATA FROM THE getOddNumber()MODULE");
                  return;
    }
    gotoxy(x,y);
    if(cnt==1){
        setColor(12);
    }
    if(checkNotes(d,mm))
    SetColorAndBackground(12,15);
    printf("%02d",d);
    SetColorAndBackground(1,15);
    for(d=2;d<=nod;d++){
        if(cnt%7==0){
            y++;
            cnt=0;
            x=x1-4;
        }
        x = x+4;
        cnt++;
        gotoxy(x,y);
        if(cnt==1){
            setColor(12);
        }else{
            clearColor();
        }
        if(checkNotes(d,mm)==1){
            SetColorAndBackground(12,15);
        }
        printf("%02d",d);
        SetColorAndBackground(1,15);
    }
    gotoxy(38,y+2);
    setColor(14);
    printf("Press 'n'  to Next, Press 'p' to Previous and 'q' to Quit");
    gotoxy(38,y+3);
    printf("Red Background indicates the NOTE, Press 's' to see note: ");
    clearColor();
}

int checkNotes(int dd,int mm){

    FILE *fp;
    fp = fopen("Notes.dat","rb");
    while(fread(&R,sizeof(R),1,fp)==1){
        if(R.day==dd&&R.month==mm){
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

void addNotes(){
    FILE *fp;
    fp=fopen("Notes.dat","ab+");
    system("cls");
    gotoxy(40, 5);
    if(fp==NULL){
        printf("\a\a\a\aError while opening file !!\a\a\a\a");
        return;
    }
    printf("Enter the day & month to save notes | (dd/mm): ");
    fflush(stdin);
    scanf("%d/%d",&R.day,&R.month);
    gotoxy(40,7);
    printf("Enter the notes(50 character max)>>>>>>>> ");
    fflush(stdin);
    scanf("%[^\n]",R.notes);
    if(fwrite(&R,sizeof(R),1,fp)){
        gotoxy(40,9);
        printf("Note save Succesfully ");
        fclose(fp);
    }else{
        gotoxy(40,9);
        puts("\a\a\aFail to save notes !!! \a\a\a\a");
        fclose(fp);
    }
    gotoxy(40,11);
    fclose(fp);
    system("cls");
}

void showNotes(int mm){
    FILE *fp;
    fp=fopen("Notes.dat","rb");
    if(fp==NULL){
        system("cls");
        gotoxy(40,6);
        printf("You have not saved any notes yet !!! \a\a\a\a\a");
        forDelay(2000000000);
        goto showNotes;
    }
    while(fread(&R,sizeof(R),1,fp)==1){
        if(R.month==mm){
        printf("\n\n\t\t\t\t\t ");
        printf("Day: %d,Month: %d || Note>>> %s",R.day,R.month,R.notes);
        }
    }
    showNotes:
    if(R.month!=mm)
    printf("\n\n\t\t\t\t\t No any notes are saved !!!");
    printf("\n\n\t\t\t\t\t ");
    system("pause");
}