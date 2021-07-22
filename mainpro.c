#include<windows.h>
#include<stdio.h>
#include<conio.h>              
#include <stdlib.h>
#include<string.h>                  
#include<ctype.h>                   
#include<dos.h>                     
#include<time.h>


#define RETURNTIME 15


// THIS PROJECT IS MADE BY AMAN YADAV(2K20/A17/44) AND DEEP ARYAN SAINI (2K20/A17/49) 

char catagories[][15]={"Computer","Electronics","Electrical","Civil","Mechanical","Architecture"};
void returnfunc(void);
void mainmenu(void);
void addbooks(void);
void deletebooks(void);
void editbooks(void);
void searchbooks(void);
void issuebooks(void);
void viewbooks(void);
void closeapplication(void);
int  getdata();
int  checkid(int);
int t(void);
void issuerecord();



FILE *fp,*ft,*fs;


COORD coord = {0, 0};

int s;
char findbook;
//char password[100]={"amandeep"};

void gotoxy (int x, int y)
{
coord.X = x; coord.Y = y; // X and Y coordinates
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct meroDate
{
int mm,dd,yy;
};
struct books
{
int id;
char stname[20];
char name[20];
char Author[20];
int quantity;
float Price;
int count;
int rackno;
char *cat;
struct meroDate issued;
struct meroDate duedate;
};
struct books a;
int main()
{
    system("Color A");
mainmenu();



getch();
return 0;

}

void mainmenu()
{
system("cls");
int i;
gotoxy(20,3);
printf("\ MAIN MENU ");
gotoxy(20,5);
printf("\ 1. Add Books   ");
gotoxy(20,7);
printf("\ 2. Delete books");
gotoxy(20,9);
printf("\ 3. Search Books");
gotoxy(20,11);
printf("\ 4. Issue Books");
gotoxy(20,13);
printf("\ 5. View Book list");
gotoxy(20,15);
printf("\ 6. Edit Book's Record");
gotoxy(20,17);
printf("\ 7. Close Application");
gotoxy(20,19);
printf("\n");
     printf("This Project is Made by:");
     printf("\n");
     printf("Aman Yadav (2K20/A17/44)");
     printf("\n");
     printf("Deep Aryan Saini (2K20/A17/49)");
     printf("\n");
     printf("In supervision Of:");
     printf("\n");
     printf("Ms. Varsha sisaudia Maam");
gotoxy(35,20);
t();
gotoxy(35,21);
printf("Enter your choice:");
switch(getch())
{
case '1':
addbooks();
break;
case '2':
deletebooks();
break;
case '3':
searchbooks();
break;
case '4':
issuebooks();
break;
case '5':
viewbooks();
break;
case '6':
editbooks();
break;
case '7':
{
system("cls");
gotoxy(16,3);
printf("\tLibrary Management System");
gotoxy(16,4);
printf("\tProject in C made by");
gotoxy(16,5);
printf("\tAman Yadav (2K20/A17/44)");
gotoxy(16,7);
printf("\tDeep Aryan Saini (2K20/A17/49)");
gotoxy(16,8);
printf("******************************************");
gotoxy(16,10);
printf("*******************************************");
gotoxy(16,11);
printf("*******************************************");
gotoxy(16,13);
printf("********************************************");
gotoxy(10,17);
printf("Exiting in 3 second...........>");
//flushall();
Sleep(3000);
exit(0);
}
default:
{
gotoxy(35,23);
printf("\aWrong Entry!!Please re-entered correct option");
if(getch())
mainmenu();
}

}
}

void addbooks(void)    
{
system("color B");
system("cls");
int i;
gotoxy(20,5);
printf("\SELECT CATEGOIES");
gotoxy(20,7);
printf("\ 1. Computer");
gotoxy(20,9);
printf("\ 2. Electronics");
gotoxy(20,11);
printf("\ 3. Electrical");
gotoxy(20,13);
printf("\ 4. Civil");
gotoxy(20,15);
printf("\ 5. Mechanical");
gotoxy(20,17);
printf("\ 6. Architecture");
gotoxy(20,19);
printf("\ 7. Back to main menu");
gotoxy(20,21);
printf("\n");
gotoxy(20,22);
printf("Enter your choice:");
scanf("%d",&s);
if(s==7)

mainmenu() ;
system("cls");
system("color D");
fp=fopen("Bibek.dat","ab+");
if(getdata()==1)
{
    system("color C");
a.cat=catagories[s-1];
fseek(fp,0,SEEK_END);
fwrite(&a,sizeof(a),1,fp);
fclose(fp);
gotoxy(21,14);
printf("The record is sucessfully saved");
gotoxy(21,15);
printf("Save any more?(Y / N):");
if(getch()=='n')
mainmenu();
else
system("cls");
addbooks();
}
}
void deletebooks()    
{
system("cls");


int d;
char another='y';
while(another=='y')  
{
system("cls");
system("color D");
gotoxy(10,5);
printf("Enter the Book ID to  delete:");
scanf("%d",&d);
fp=fopen("Bibek.dat","rb+");
system("color C");
rewind(fp);
while(fread(&a,sizeof(a),1,fp)==1)
{
if(a.id==d)
{

gotoxy(10,7);
printf("The book record is available");
gotoxy(10,8);
printf("Book name is %s",a.name);
gotoxy(10,9);
printf("Rack No. is %d",a.rackno);
findbook='t';
}
}
if(findbook!='t')
{
gotoxy(10,10);
printf("No record is found modify the search");
if(getch())
mainmenu();
}
if(findbook=='t' )
{
gotoxy(10,9);
printf("Do you want to delete it?(Y/N):");
if(getch()=='y')
{
ft=fopen("test.dat","wb+");  
rewind(fp);
while(fread(&a,sizeof(a),1,fp)==1)
{
if(a.id!=d)
{
fseek(ft,0,SEEK_CUR);
fwrite(&a,sizeof(a),1,ft); 
}                              
}
fclose(ft);
fclose(fp);
remove("Bibek.dat");
rename("test.dat","Bibek.dat");
system("color B"); 
fp=fopen("Bibek.dat","rb+");    
if(findbook=='t')
{
gotoxy(10,10);
printf("The record is successfully deleted");
gotoxy(10,11);
printf("Delete another record?(Y/N)");
}
}
else
mainmenu();
fflush(stdin);
another=getch();
}
}
gotoxy(10,15);
mainmenu();
}
void searchbooks()
{
system("color D");
system("cls");
int d;
printf("*****************************Search Books*********************************");
gotoxy(20,10);
printf(" 1. Search By ID");
gotoxy(20,14);
printf(" 2. Search By Name");
gotoxy( 15,20);
printf("Enter Your Choice");
fp=fopen("Bibek.dat","rb+"); //open file for reading 
rewind(fp);   
switch(getch())
{
case '1':
{
system("cls");
gotoxy(25,4);
printf("****Search Books By Id****");
gotoxy(20,5);
printf("Enter the book id:");
scanf("%d",&d);
gotoxy(20,7);
printf("Searching........");
while(fread(&a,sizeof(a),1,fp)==1)
{
if(a.id==d)
{
Sleep(2);
gotoxy(20,7);
printf("The Book is available");
gotoxy(20,8);
printf("\n");
gotoxy(20,9);
printf("\ ID:%d",a.id);
gotoxy(47,9);
printf("\n");
gotoxy(20,10);
printf("\ Name:%s",a.name);
gotoxy(47,10);
printf("\n");
gotoxy(20,11);
printf("\xB2 Author:%s ",a.Author);
gotoxy(47,11);
printf("\n");
gotoxy(20,12);
printf("\ Qantity:%d ",a.quantity);
gotoxy(47,12);
printf("\n");
gotoxy(47,11);
printf("\n");
gotoxy(20,13);
printf("\ Price:Rs.%.2f",a.Price);
gotoxy(47,13);
printf("\n");
gotoxy(20,14);
printf("\ Rack No:%d ",a.rackno);
gotoxy(47,14);
printf("\n");
gotoxy(20,15);
printf("\*************************************************************************************************************");
findbook='t';
}

}
if(findbook!='t')  //checks whether conditiion enters inside loop or not
{
gotoxy(20,8);
printf("\*****************************************************************************");
gotoxy(20,9);
printf("\n");
gotoxy(38,9);
printf("\n");
gotoxy(20,10);
printf("\***************************************************************************************");
gotoxy(22,9);
printf("\aNo Record Found");
}
gotoxy(20,17);
printf("Try another search?(Y/N)");
if(getch()=='y')
searchbooks();
else
mainmenu();
break;
}
case '2':
{
char s[15];
system("cls");
gotoxy(25,4);
printf("****Search Books By Name****");
gotoxy(20,5);
printf("Enter Book Name:");
scanf("%s",s);
int d=0;
while(fread(&a,sizeof(a),1,fp)==1)
{
if(strcmp(a.name,(s))==0) 
{
gotoxy(20,7);
printf("The Book is available");
gotoxy(20,8);
printf("\**********************************************************************************************************");
gotoxy(20,9);
printf("\xB2 ID:%d",a.id);
gotoxy(47,9);
printf("\n");
gotoxy(20,10);
printf("\ Name:%s",a.name);
gotoxy(47,10);
printf("\n");
gotoxy(20,11);
printf("\ Author:%s",a.Author);
gotoxy(47,11);
printf("\n");
gotoxy(20,12);
printf("\ Qantity:%d",a.quantity);
gotoxy(47,12);
printf("\n");
gotoxy(20,13);
printf("\ Price:Rs.%.2f",a.Price);
gotoxy(47,13);
printf("\n");
gotoxy(20,14);
printf("\ Rack No:%d ",a.rackno);
gotoxy(47,14);
printf("\n");
gotoxy(20,15);
printf("\***********************************************************************************************************");
d++;
}

}
if(d==0)
{
gotoxy(20,8);
printf("\***************************************************************************");
gotoxy(20,9);
printf("\n");
gotoxy(38,9);
printf("\n");
gotoxy(20,10);
printf("\***************************************************************************");
gotoxy(22,9);
printf("\aNo Record Found");
}
gotoxy(20,17);
printf("Try another search?(Y/N)");
if(getch()=='y')
searchbooks();
else
mainmenu();
break;
}
default :
getch();
searchbooks();
}
fclose(fp);
}
void issuebooks(void)  
{
system("color D");
int t;

system("cls");
printf("********************************ISSUE SECTION**************************");
gotoxy(10,5);
printf("\ 1. Issue a Book");
gotoxy(10,7);
printf("\ 2. View Issued Book");
gotoxy(10,9);
printf("\ 3. Search Issued Book");
gotoxy(10,11);
printf("\ 4. Remove Issued Book");
gotoxy(10,14);
printf("Enter a Choice:");
switch(getch())
{
case '1':  //issue book
{
system("cls");
int c=0;
char another='y';
while(another=='y')
{
system("cls");
gotoxy(15,4);
printf("***Issue Book section***");
gotoxy(10,6);
printf("Enter the Book Id:");
scanf("%d",&t);
fp=fopen("Bibek.dat","rb");
fs=fopen("Issue.dat","ab+");
if(checkid(t)==0) 
{
gotoxy(10,8);
printf("The book record is available");
gotoxy(10,9);
printf("There are %d unissued books in library ",a.quantity);
gotoxy(10,10);
printf("The name of book is %s",a.name);
gotoxy(10,11);
printf("Enter student name:");
scanf("%s",a.stname);
gotoxy(10,12);
printf("Issued date=%d-%d-%d",a.issued.dd,a.issued.mm,a.issued.yy);
gotoxy(10,13);
printf("The BOOK of ID %d is issued",a.id);
a.duedate.dd=a.issued.dd+RETURNTIME;   //for return date
a.duedate.mm=a.issued.mm;
a.duedate.yy=a.issued.yy;
if(a.duedate.dd>30)
{
a.duedate.mm+=a.duedate.dd/30;
a.duedate.dd-=30;

}
if(a.duedate.mm>12)
{
a.duedate.yy+=a.duedate.mm/12;
a.duedate.mm-=12;

}
gotoxy(10,14);
printf("To be return:%d-%d-%d",a.duedate.dd,a.duedate.mm,a.duedate.yy);
fseek(fs,sizeof(a),SEEK_END);
fwrite(&a,sizeof(a),1,fs);
fclose(fs);
c=1;
}
if(c==0)
{
gotoxy(10,11);
printf("No record found");
}
gotoxy(10,15);
printf("Issue any more(Y/N):");
fflush(stdin);
another=getche();
fclose(fp);
}

break;
}
case '2':  
{
system("cls");
int j=4;
printf("*******************************Issued book list*******************************\n");
gotoxy(2,2);
printf("STUDENT NAME    CATEGORY    ID    BOOK NAME    ISSUED DATE    RETURN DATE");
fs=fopen("Issue.dat","rb");
while(fread(&a,sizeof(a),1,fs)==1)
{

gotoxy(2,j);
printf("%s",a.stname);
gotoxy(18,j);
printf("%s",a.cat);
gotoxy(30,j);
printf("%d",a.id);
gotoxy(36,j);
printf("%s",a.name);
gotoxy(51,j);
printf("%d-%d-%d",a.issued.dd,a.issued.mm,a.issued.yy );
gotoxy(65,j);
printf("%d-%d-%d",a.duedate.dd,a.duedate.mm,a.duedate.yy);

gotoxy(50,25);
//            printf("Current date=%d-%d-%d",d.day,d.month,d.year);
j++;

}
fclose(fs);
gotoxy(1,25);
returnfunc();
}
break;
case '3':   
{
system("cls");
gotoxy(10,6);
printf("Enter Book ID:");
int p,c=0;
char another='y';
while(another=='y')
{

scanf("%d",&p);
fs=fopen("Issue.dat","rb");
while(fread(&a,sizeof(a),1,fs)==1)
{
if(a.id==p)
{
issuerecord();
gotoxy(10,12);
printf("Press any key.......");
getch();
issuerecord();
c=1;
}

}
fflush(stdin);
fclose(fs);
if(c==0)
{
gotoxy(10,8);
printf("No Record Found");
}
gotoxy(10,13);
printf("Try Another Search?(Y/N)");
another=getch();
}
}
break;
case '4':  
{
system("cls");
int b;
FILE *fg;  
char another='y';
while(another=='y')
{
gotoxy(10,5);
printf("Enter book id to remove:");
scanf("%d",&b);
fs=fopen("Issue.dat","rb+");
while(fread(&a,sizeof(a),1,fs)==1)
{
if(a.id==b)
{
issuerecord();
findbook='t';
}
if(findbook=='t')
{
gotoxy(10,12);
printf("Do You Want to Remove it?(Y/N)");
if(getch()=='y')
{
fg=fopen("record.dat","wb+");
rewind(fs);
while(fread(&a,sizeof(a),1,fs)==1)
{
if(a.id!=b)
{
fseek(fs,0,SEEK_CUR);
fwrite(&a,sizeof(a),1,fg);
}
}
fclose(fs);
fclose(fg);
remove("Issue.dat");
rename("record.dat","Issue.dat");
gotoxy(10,14);
printf("The issued book is removed from list");

}

}
if(findbook!='t')
{
gotoxy(10,15);
printf("No Record Found");
}
}
gotoxy(10,16);
printf("Delete any more?(Y/N)");
another=getch();
}
}
default:
gotoxy(10,18);
printf("\aWrong Entry!!");
getch();
issuebooks();
break;
}
gotoxy(1,30);
returnfunc();
}
void viewbooks(void)  
{
int i=0,j;
system("cls");
gotoxy(1,1);
printf("*********************************Book List*****************************");
gotoxy(2,2);
printf(" CATEGORY     ID    BOOK NAME     AUTHOR       QTY     PRICE     RackNo ");
j=4;
fp=fopen("Bibek.dat","rb");
while(fread(&a,sizeof(a),1,fp)==1)
{
gotoxy(3,j);
printf("%s",a.cat);
gotoxy(16,j);
printf("%d",a.id);
gotoxy(22,j);
printf("%s",a.name);
gotoxy(36,j);
printf("%s",a.Author);
gotoxy(50,j);
printf("%d",a.quantity);
gotoxy(57,j);
printf("%.2f",a.Price);
gotoxy(69,j);
printf("%d",a.rackno);
printf("\n\n");
j++;
i=i+a.quantity;
}
gotoxy(3,25);
printf("Total Books =%d",i);
fclose(fp);
gotoxy(35,25);
returnfunc();
}
void editbooks(void)  
{
system("cls");
int c=0;
int d,e;
gotoxy(20,4);
printf("****Edit Books Section****");
char another='y';
while(another=='y')
{
system("cls");
gotoxy(15,6);
printf("Enter Book Id to be edited:");
scanf("%d",&d);
fp=fopen("Bibek.dat","rb+");
while(fread(&a,sizeof(a),1,fp)==1)
{
if(checkid(d)==0)
{
gotoxy(15,7);
printf("The book is availble");
gotoxy(15,8);
printf("The Book ID:%d",a.id);
gotoxy(15,9);
printf("Enter new name:");
scanf("%s",a.name);
gotoxy(15,10);
printf("Enter new Author:");
scanf("%s",a.Author);
gotoxy(15,11);
printf("Enter new quantity:");
scanf("%d",&a.quantity);
gotoxy(15,12);
printf("Enter new price:");
scanf("%f",&a.Price);
gotoxy(15,13);
printf("Enter new rackno:");
scanf("%d",&a.rackno);
gotoxy(15,14);
printf("The record is modified");
fseek(fp,ftell(fp)-sizeof(a),0);
fwrite(&a,sizeof(a),1,fp);
fclose(fp);
c=1;
}
if(c==0)
{
gotoxy(15,9);
printf("No record found");
}
}
gotoxy(15,16);
printf("Modify another Record?(Y/N)");
fflush(stdin);
another=getch() ;
}
returnfunc();
}
void returnfunc(void)
{
{
printf(" Press ENTER to return to main menu");
}
a:
if(getch()==13) //allow only use of enter
mainmenu();
else
goto a;
}
int getdata()
{
int t;
gotoxy(20,3);
printf("Enter the Information Below");
gotoxy(20,4);
printf("\****************************************************************************************************************");
gotoxy(20,5);
printf("\n");
gotoxy(46,5);
printf("\n");
gotoxy(20,6);
printf("\n");
gotoxy(46,6);
printf("\n");
gotoxy(20,7);
printf("\n");
gotoxy(46,7);
printf("\n");
gotoxy(20,8);
printf("\n");
gotoxy(46,8);
printf("\n");
gotoxy(20,9);
printf("\n");
gotoxy(46,9);
printf("\n");
gotoxy(20,10);
printf("\n");
gotoxy(46,10);
printf("\n");
gotoxy(20,11);
printf("\n");
gotoxy(46,11);
printf("\n");
gotoxy(20,12);
printf("\************************************************************************************************************");
gotoxy(21,5);
printf("Category:");
gotoxy(31,5);
printf("%s",catagories[s-1]);
gotoxy(21,6);
printf("Book ID:\t");
gotoxy(30,6);
scanf("%d",&t);
if(checkid(t) == 0)
{
gotoxy(21,13);
printf("\aThe book id already exists\a");
getch();
mainmenu();
return 0;
}
a.id=t;
gotoxy(21,7);
printf("Book Name:");
gotoxy(33,7);
scanf("%s",a.name);
gotoxy(21,8);
printf("Author:");
gotoxy(30,8);
scanf("%s",a.Author);
gotoxy(21,9);
printf("Quantity:");
gotoxy(31,9);
scanf("%d",&a.quantity);
gotoxy(21,10);
printf("Price:");
gotoxy(28,10);
scanf("%f",&a.Price);
gotoxy(21,11);
printf("Rack No:");
gotoxy(30,11);
scanf("%d",&a.rackno);
return 1;
}
int checkid(int t)  
{
rewind(fp);
while(fread(&a,sizeof(a),1,fp)==1)
if(a.id==t)
return 0;  
return 1; 
}
int t(void) 
{
time_t t;
time(&t);
printf("Date and time:%s\n",ctime(&t));

return 0 ;
}

void issuerecord()  
{
system("color D");
system("cls");
gotoxy(10,8);
printf("The Book has taken by Mr. %s",a.stname);
gotoxy(10,9);
printf("Issued Date:%d-%d-%d",a.issued.dd,a.issued.mm,a.issued.yy);
gotoxy(10,10);
printf("Returning Date:%d-%d-%d",a.duedate.dd,a.duedate.mm,a.duedate.yy);
}