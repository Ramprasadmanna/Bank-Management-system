#include <stdio.h>

struct account
{
    int ac_n;
    char name[50];
    char contact_no[12];
    char address[20];
    float acc_balance;
    float depostatement[100][100];
    float withstatement[100][100];
    float transferm[100][100];
    float receivedm[100][100];
    int j;
};
struct account details[100];
int i = 1, j = 0;

int accno(int acno)
{
    int n;
    n = acno - 19900;
    return n;
}

int printdetails(int n)
{
    printf("\nName : %s", details[n].name);
    printf("\nContact Number : %s", details[n].contact_no);
    printf("\nAddress : %s", details[n].address);
}

int menu()
{
    int option, i = 0;

    printf("\n\n 1 -> Create Account");
    printf("\n 2 -> Cash Deposit");
    printf("\n 3 -> Cash Withdrawl");
    printf("\n 4 -> Transfer Money");
    printf("\n 5 -> Check Balance");
    printf("\n 6 -> Statement");
    printf("\n 7 -> Exit");
    printf("\n\nSelect Option You Wish To Perform : ");
    scanf("%d", &option);

    return option;
}

void createacc()
{
    int accno = 19900;

    printf("\n********************************************");
    printf("\n            -> Account Creation <-");
    printf("\n********************************************");
    printf("\nName : ");
    scanf("%s", details[i].name);
    printf("Contact Number: ");
    scanf("%s", details[i].contact_no);
    printf("Address : ");
    scanf("%s", details[i].address);
    printf("Your Account No : %d", accno + i);
    details[i].ac_n = accno + i;
    printf("\nYour Opening Balance : %.2f", details[i].acc_balance + 500);
    details[i].acc_balance += 500;
    j = details[i].j;
    details[i].depostatement[i][j] = 500;
    details[i].j += 1;
    i++;
}

void deposit()
{
    int acno, n, i;
    float amt;

    printf("\n********************************************");
    printf("\n            -> Cash Deposit <-");
    printf("\n********************************************");
    printf("\nEnter Account Number : ");
    scanf("%d", &acno);

    n = accno(acno);

    if (details[n].ac_n == acno)
    {

        printdetails(n);

        printf("\n\nEnter Amount To Deposit : ");
        scanf("%f", &amt);
        if (amt > 0)
        {
            details[n].acc_balance += amt;
            j = details[n].j;
            details[n].depostatement[n][j] = amt;
            printf("\nClear Balance : %.2f", details[n].acc_balance);
            details[n].j += 1;
        }
        else
        {
            printf("\n*Enter Valid Amount!!!");
        }
    }
    else
    {
        printf("\nInvalid Account Number");
    }
}

void withdraw()
{
    int acno, n, i;
    float amt;
    printf("\n********************************************");
    printf("\n            -> Cash Withdraw <-");
    printf("\n********************************************");

    printf("\nEnter Account Number : ");
    scanf("%d", &acno);

    n = accno(acno);

    if (details[n].ac_n == acno)
    {

        printdetails(n);

        printf("\nAvailable Balance : %.2f ", details[n].acc_balance);
        printf("\n\nEnter Amount You wish To Withdraw : ");
        scanf("%f", &amt);

        if (details[n].acc_balance - amt >= 0)
        {
            if (amt > 0)
            {
                details[n].acc_balance -= amt;
                printf("\nClear Balance : %.2f", details[n].acc_balance);
                j = details[n].j;
                details[n].withstatement[n][j] = amt;
                details[n].j += 1;
            }
            else
            {
                printf("\n*Enter Valid Amount!!!");
            }
        }
        else
        {
            printf("\n*Insufficient Balance!!!");
        }
    }
    else
    {
        printf("\n*Invalid Account Number!!!");
    }
}

void transfer()
{
    int n1, n2, acno1, acno2, i;
    float tamt;

    printf("\n********************************************");
    printf("\n               -> Money Transfer <-");
    printf("\n********************************************");

    printf("\n Enter Your Account Number : ");
    scanf("%d", &acno1);

    n1 = accno(acno1);

    if (details[n1].ac_n == acno1)
    {
        printdetails(n1);

        printf("\nAvailable Balance : %.2f", details[n1].acc_balance);
    }
    else
    {
        printf("\n*Invalid Account Number!!!");
    }

    printf("\n\nEnter Account Number In which You want To Transfer : ");
    scanf("%d", &acno2);

    n2 = accno(acno2);

    if (details[n2].ac_n == acno2)
    {
        printdetails(n2);

        printf("\n\nEnter Amount You Wish To Transfer : ");
        scanf("%f", &tamt);

        if (details[n1].acc_balance - tamt >= 0)
        {

            if (tamt > 0)
            {
                details[n1].acc_balance -= tamt;
                j = details[n1].j;
                details[n1].transferm[n1][j] = tamt;
                details[n1].j += 1;

                details[n2].acc_balance += tamt;
                j = details[n2].j;
                details[n2].receivedm[n2][j] = tamt;
                details[n2].j += 1;

                printf("\nYour Transfer Is Sucessful.");
                printf("\n-> Your Clear Balane : %.2f", details[n1].acc_balance);
            }
            else
            {
                printf("\n*Invalid Amount Entered!!!!");
            }
        }
        else
        {
            printf("\n*Insufficient Balance!!!");
        }
    }
    else
    {
        printf("\n*Invalid Account Number!!!");
    }
}

void checkbal()
{
    int acno, i, n;

    printf("\n********************************************");
    printf("\n               -> Check Balance <-");
    printf("\n********************************************");

    printf("\n Enter Account Number : ");
    scanf("%d", &acno);

    n = accno(acno);

    if (details[n].ac_n == acno)
    {

        printdetails(n);

        printf("\nAvailable Balance : %.2f", details[n].acc_balance);
    }
}

void statement()
{
    int i, n, acno, noft = 0;

    printf("\n********************************************");
    printf("\n               -> Statement <-");
    printf("\n********************************************");

    printf("\nEnter Account Number : ");
    scanf("%d", &acno);

    n = accno(acno);

    if (details[n].ac_n == acno)
    {

        printdetails(n);

        printf("\n\nEnter No Of Transactions : ");
        scanf("%d", &noft);

        for (i = 0; i < noft; i++)
        {
            if (details[n].depostatement[n][i] != 0)
            {
                printf("\nCredit  : + %.2f  ", details[n].depostatement[n][i]);
            }

            if (details[n].withstatement[n][i] != 0)
            {
                printf("\nDebit  : - %.2f  ", details[n].withstatement[n][i]);
            }

            if (details[n].transferm[n][i] != 0)
            {
                printf("\nTransfer : - %.2f  ", details[n].transferm[n][i]);
            }

            if (details[n].receivedm[n][i] != 0)
            {
                printf("\nReceived : + %.2f  ", details[n].receivedm[n][i]);
            }
        }
        printf("\n\n-> Clear Balance : %.2f", details[n].acc_balance);
    }
    else
    {
        printf("\n*Invalid Account Number!!!");
    }
}

void main()
{
    int j = 0, option;
    printf("\n********************************************");
    printf("\n           -+ WELCOME TO SWISS BANK +-");
    printf("\n           Copyright -Ramprasad Manna- ");
    printf("\n********************************************");

    do
    {

        option = menu();

        switch (option)
        {
        case 1:
            createacc();
            break;

        case 2:
            deposit();
            break;

        case 3:
            withdraw();
            break;

        case 4:
            transfer();
            break;

        case 5:
            checkbal();
            break;

        case 6:
            statement();
            break;

        case 7:
            break;

        default:
            printf("\n *Invalid InPut !!!");
            break;
        }
    } while (option <= 6 || option >= 8);

    printf("\n********************************************");
    printf("\n     -> Thankyou For Choosing SWISS Bank <-");
    printf("\n********************************************");
    printf("\n");
    printf("This Project Is Programmed By Ramprasad Manna");
}