// This is a Log In System Program

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
// #include<string.h>
// #define ENTER 13
// #define TAB 9
// #define BCKSPC 8

struct user
{
    char fullname[50];
    char email[50];
    char password[50];
    char username[50];
    char phone[50];
};

void takeinput(char ch[50])
{
    fgets(ch, 50, stdin);
    ch[strlen(ch) - 1] = 0;
}

char generateUsename(char email[50], char username[50])
{
    // abs125@gmail.com
    for (int i = 0; i < strlen(email); i++)
    {
        if (email[i] == '@')
            break;
        else
            username[i] = email[i];
    }
}

void takepassword(char pwd[50])
{
    int i;
    char ch1;

    for (i = 0; i < 10; i++)
    {
        ch1 = getch();
        pwd[i] = ch1;

        if (ch1 != 13) // 13 is ASCII of Enter key
            printf("*");
        if (ch1 == 13)
            break;
    }
    pwd[i] = '\0';
    //   printf("\n%s", pwd);
}

int main()
{
    FILE *fp;
    char password2[50];
    struct user user;
    int opt, usrFound = 0;

    printf("\n***********Welcome to Authentication System****************\n");
    printf("Plese choose your operation\n");
    printf("1. Signup\n");
    printf("2. Login\n");
    printf("3. Exit\n\n");

    printf("Plese enter your choise: ");
    scanf("%d", &opt);
    fgetc(stdin);

    switch (opt)
    {
    case 1:
    system("cls");
        printf("Enter your full name: ");
        takeinput(user.fullname);
        printf("Enter your email: ");
        takeinput(user.email);
        printf("Enter your conect number: ");
        takeinput(user.phone);
        printf("Enter your password: ");
        takepassword(user.password);
        printf("\nConfirm the password: ");
        takeinput(password2);

        if (!strcmp(user.password, password2))
        {
            // printf("Password matched");
            generateUsename(user.email, user.username);
            fp = fopen("user.dat", "w");
            fwrite(&user, sizeof(struct user), 1, fp);

            if (fwrite != 0)
                printf("\n\n User registration is successfull, Your usename is %s and password is %s", user.username,user.password);
            else
                printf("\n\n Sorry ! Something went wrong ");
            fclose(fp);
        }
        else
        {
            printf("\nPassword not matched ");
            Beep(750, 300);
        }
        break;

    case 2:;
        char username[50], pword[50];
        struct user usr;

        printf("\nEnter your username: ");
        takeinput(username);
        printf("\nEnter your password: ");
        takeinput(pword);
       
        fp = fopen("user.dat", "r");
        while (fread(&usr, sizeof(struct user), 1, fp))
            ;
        {
            if (!strcmp(usr.username, username))
            {
                if (!strcmp(usr.password, pword))
                {
                     system("cls");
                    printf("\n******************Welcome %s***********************", usr.fullname);
                    printf("\n\n| Full Name:\t %s", usr.fullname);
                    printf("\n| Email:\t %s", usr.email);
                    printf("\n| Username:\t %s", usr.username);
                    printf("\n| Contact No.:\t %s", usr.phone);
                }
                else
                {
                    printf("\nInvalid Password!");
                    Beep(800, 300);
                }
                usrFound = 1;
            }            
        }
        if (!usrFound)
        {
            printf("\n\nUser is not registered");
            Beep(800, 300);
        }
        fclose(fp);
        break;

        case 3:
        printf("\t\t\tBye Bye");
        
    }

    return 0;
}