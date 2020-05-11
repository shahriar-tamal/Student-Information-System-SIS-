/*------- HEADER FILE -------*/
#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
#include<fstream>
#include<stdio.h>
#include<cstring>
#include<iomanip>

using namespace std;

struct student
{
    char id[15];
    char name[30];
    char semester[10];
    char address[50];
    char email[30];
    char phone[15];
    int password;
    int sub1 = 0;
    int sub2 = 0;
    int sub3 = 0;
};
student vu;

/*------- Function Declaration -------*/
void Title();
void MainMenu();
void StudentPanel();
void OfficePanel();
void StudentLogin();
void OfficeLogin();
void AddStudent();
void AddMarks();
void ViewStudentInfo();
void ViewStudentResult();


/*------- Main Function -------*/
int main()
{
    SetConsoleTitle("Student Information System");
    MainMenu();
    return 0;
}


/*--------------------------------------------
-------------All Function Description---------
---------------------------------------------*/

/*------- Homepage -------*/
void MainMenu()
{
    int choice;

    Title();
    while(1)
    {
        cout << "\t\t\t1. Office Panel\n";
        cout << "\t\t\t2. Student Panel\n\n";
        cout << "\t\t\tEnter your choice: ";
        cin >> choice;
        switch(choice)
        {
        case 1:
            OfficeLogin();
            break;
        case 2:
            StudentLogin();
            break;
        default:
            system("cls");
            MainMenu();

        }
    }
}

void StudentPanel()
{
    system("cls");
    Title();
    StudentLogin();


}

void OfficePanel()
{
    system("cls");
    Title();
    int choice;
    while(1)
    {
        cout << "\t\t\t1. Add New Student\n";
        cout << "\t\t\t2. Add Student Marks\n";
        cout << "\t\t\t3. View Student Information\n";
        cout << "\t\t\t4. View Student Result\n";
        cout << "\t\t\t5. Goto Main Menu\n\n";
        cout << "\t\t\tEnter your choice: ";
        cin >> choice;
        switch(choice)
        {
        case 1:
            AddStudent();
            break;
        case 2:
            AddMarks();
            break;
        case 3:
            ViewStudentInfo();
            break;
        case 4:
            ViewStudentResult();
            break;
        default:
            system("cls");
            MainMenu();
        }
    }
}


/*------- Title -------*/
void Title()
{
    cout << "\n\n\t\t\t Student Information System (SIS)\n";
    cout << "\t\t\t\t-------------------\n";
    cout << "\t\t\t\tVarendra University\n";
    cout << "\t\t\t==================================\n\n";

}

void StudentLogin()
{
    system("cls");
    Title();
    int StudentID,StudentPassword,tempStudentPassword;
    cout << "\t\t\tEnter Student ID: ";
    cin >> StudentID;
    cout << "\t\t\tEnter Password: ";
    cin >> StudentPassword;
    if(tempStudentPassword == StudentPassword)
    {

    }
    else
    {
        cout << "\n\t\t\tWrong Student ID or Password! Try again.\n\n\n";
    }
}

void OfficeLogin()
{
    system("cls");
    Title();
    char ch;
    char OfficePassword[20] = {1234},tempOfficePassword[20];
    while(1)
    {
        cout << "\t\t\tUsername: Administrator\n";
        cout << "\t\t\tPassword: ";
        char pass[32];//to store password.
        int i = 0;
        char a;//a Temp char
        for(i=0;;)//infinite loop
        {
            a=getch();//stores char typed in a
            if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
                //check if a is numeric or alphabet
            {
                pass[i]=a;//stores a in pass
                ++i;
                cout<<"*";
            }
            if(a=='\b'&&i>=1)//if user typed backspace
                //i should be greater than 1.
            {
                cout<<"\b \b";//rub the character behind the cursor.
                --i;
            }
            if(a=='\r')//if enter is pressed
            {
                pass[i]='\0';//null means end of string.
                break;//break the loop
            }
        }
        {

            OfficePanel();
        }

    }
}

void AddStudent()
{
    system("cls");
    Title();
    FILE *data;
    data = fopen("StudentDatabase.txt","a+");
    if(data == NULL)
    {
        MessageBox(0,"Error in Opening file\nMake sure your file is not write protected","Warning",0);
    }
    else
    {

        cout << "\t\t\tStudent ID: ";
        fflush(stdin);
        gets(vu.id);

        cout << "\t\t\tStudent Name: ";
        fflush(stdin);
        gets(vu.name);

        cout << "\t\t\tSemester: ";
        fflush(stdin);
        gets(vu.semester);

        cout << "\t\t\tAddress: ";
        fflush(stdin);
        gets(vu.address);

        cout << "\t\t\tEmail: ";
        fflush(stdin);
        gets(vu.email);

        cout << "\t\t\tPhone: ";
        fflush(stdin);
        gets(vu.phone);

        cout << "\t\t\tTemporary Password: ";
        fflush(stdin);
        cin >> vu.password;

        fflush(stdin);
        vu.sub1 = 0;

        fflush(stdin);
        vu.sub2 = 0;

        fflush(stdin);
        vu.sub3 = 0;

        fwrite(&vu,sizeof(vu),1,data);
        fflush(stdin);
        fputs("\n",data);
        cout << "\n\t\t\tNew Student is successfully added.\n\n\n";
    }
    fclose(data);
}

void ViewStudentInfo()
{
    system("cls");
    Title();
    char tempID[15];
    int isFound = 0;
    cout << "\t\t\tEnter ID to View Information: ";
    fflush(stdin);
    gets(tempID);
    FILE *data;
    data = fopen("StudentDatabase.txt","r");
    while(fread(&vu,sizeof(vu),1,data) == 1)
    {
        if(strcmp(vu.id,tempID) == 0)
        {
            isFound = 1;
            break;
        }
    }
    if(isFound == 1)
    {
        cout << "\n\t\t\tStudent Information is Found.\n\n";
        cout << "\n\t\t\tID: " << vu.id;
        cout << "\n\t\t\tName: " << vu.name;
        cout << "\n\t\t\tSemester: " << vu.semester;
        cout << "\n\t\t\tAddress: " << vu.address;
        cout << "\n\t\t\tEmail: " << vu.email;
        cout << "\n\t\t\tPhone: " << vu.phone;
        cout << "\n\t\t\tPassword: " << vu.password;
        cout << "\n\n\n";
    }
    else
    {
        cout << "\n\t\t\tSorry, No information found in the database\n\n\n";
    }
    fclose(data);
}

void AddMarks()
{
    system("cls");
    Title();
    char tempID[15];
    int isFound = 0;
    cout << "\t\t\tEnter ID to Add Student Marks: ";
    fflush(stdin);
    gets(tempID);
    FILE *data;
    data = fopen("StudentDatabase.txt","r+");
    while(fread(&vu, sizeof(vu),1,data) == 1)
    {
        if(strcmp(tempID,vu.id) == 0)
        {
            fflush(stdin);

            cout << "\t\t\tEnter Marks:\n";
            cout << "\t\t\t\tCSE 101: ";
            fflush(stdin);
            cin >> vu.sub1;

            cout << "\t\t\t\tCSE 102: ";
            fflush(stdin);
            cin >> vu.sub2;

            cout << "\t\t\t\tCSE 103: ";
            fflush(stdin);
            cin >> vu.sub3;

            fseek(data,-sizeof(vu), SEEK_CUR);
            fwrite(&vu,sizeof(vu), 1, data);

            cout << "\n\t\t\tResult is successfully Updated.\n\n";
            isFound = 1;
            break;
        }
    }
    if(!isFound)
    {
        cout << "\n\t\t\tStudent Not Found.\n\n";
    }
    fclose(data);
}

void ViewStudentResult()
{
    system("cls");
    Title();
    char tempID[15];
    int isFound = 0;
    cout << "\t\t\tEnter ID to View Result: ";
    fflush(stdin);
    gets(tempID);
    FILE *data;
    data = fopen("StudentDatabase.txt","r");
    while(fread(&vu,sizeof(vu),1,data) == 1)
    {
        if(strcmp(vu.id,tempID) == 0)
        {
            isFound = 1;
            break;
        }
    }
    if(isFound == 1)
    {
        cout << "\n\t\t\tResult is Found.\n\n";
        cout << "\n\t\t\tID: " << vu.id;
        cout << "\n\n\t\t\tMarks: ";
        cout << "\n\t\t\tCSE 101 = " << vu.sub1;
        cout << "\n\t\t\tCSE 102 = " << vu.sub2;
        cout << "\n\t\t\tCSE 103 = " << vu.sub3;
        cout << "\n\n\t\t\tResult = " << vu.sub1 + vu.sub2 + vu.sub3 <<" out of 300";
        cout << "\n\n\n";
    }
    else
    {
        cout << "\n\t\t\tSorry, No result found in the database\n\n\n";
    }
    fclose(data);
}
