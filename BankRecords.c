#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct info
{
    char username[20];
    char password[18];
    int id;
    float balance;
};

void loginOrSignup(struct info *user);
void signUp(struct info *user);
void login(struct info *user);
void deposit(struct info *user);
void withdraw(struct info *user);

int main()
{
    srand(time(0));

    struct info *user1 = (struct info *)malloc(sizeof(struct info));
    if (user1 == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    loginOrSignup(user1);

    free(user1);

    return 0;
}

void loginOrSignup(struct info *user)
{
    char choice;
    printf("===================================Type 'L' for Login or 'S' for Sign Up: ===================================\n");
    scanf(" %c", &choice);
    getchar();

    if (choice == 'S' || choice == 's')
    {
        signUp(user);
    }
    else if (choice == 'L' || choice == 'l')
    {
        login(user);
    }
    else
    {
        printf("====================================Invalid choice! Please restart the program.====================================\n");
    }
}

void signUp(struct info *user)
{
    printf("\n============================================ Sign Up ==============================================\n");

    printf("\t\t\t\tEnter a username: ");
    fgets(user->username, sizeof(user->username), stdin);
    user->username[strcspn(user->username, "\n")] = '\0';

    printf("\t\t\t\tEnter a password: ");
    fgets(user->password, sizeof(user->password), stdin);
    user->password[strcspn(user->password, "\n")] = '\0';

    user->id = 1100 + rand() % (1300 - 1100 + 1);
    user->balance = 0.0;

    printf("\t\t\t\tSign Up Successful! Your User ID is: %d\n", user->id);

    login(user);
}

void login(struct info *user)
{
    int enteredID;
    char enteredPassword[18];

    printf("\n================================================= Login =================================================\n");

    printf("\t\t\t\tEnter your User ID: ");
    scanf("%d", &enteredID);
    getchar();

    printf("\t\t\t\tEnter your password: ");
    fgets(enteredPassword, sizeof(enteredPassword), stdin);
    enteredPassword[strcspn(enteredPassword, "\n")] = '\0';

    if (user->id == enteredID && strcmp(user->password, enteredPassword) == 0)
    {
        printf("\t\t\t\tLogin Successful! Welcome, %s\n", user->username);

        int choice;
        do
        {
            printf("\n=========================================== Banking Menu =============================================\n");
            printf("\t\t\t\t1. Deposit Money\n");
            printf("\t\t\t\t2. Withdraw Money\n");
            printf("\t\t\t\t3. Check Balance\n");
            printf("\t\t\t\t4. Logout\n");
            printf("\t\t\t\tEnter your choice: ");
            scanf("%d", &choice);
            getchar();

            switch (choice)
            {
            case 1:
                deposit(user);
                break;
            case 2:
                withdraw(user);
                break;
            case 3:
                printf("\t\t\t\tYour current balance is: %.2f\n", user->balance);
                break;
            case 4:
                printf("\n\n\t\t\t\tThank Youuu")
                    printf("\t\t\t\tLogging out...\n");
                printf("==============================================================================================================");
                break;
            default:
                printf("\t\t\t\tInvalid choice! Please try again.\n");
            }
        } while (choice != 4);
    }
    else
    {
        printf("\t\t\t\tInvalid ID or password! Please try again.\n");
    }
}

void deposit(struct info *user)
{
    float amount;
    printf("\t\t\t\tEnter amount to deposit: ");
    scanf("%f", &amount);

    if (amount > 0)
    {
        user->balance += amount;
        printf("\t\t\t\tDeposit Successful! New Balance: %.2f\n", user->balance);
    }
    else
    {
        printf("\t\t\t\tInvalid amount! Please enter a positive value.\n");
    }
}

void withdraw(struct info *user)
{
    float amount;
    printf("\t\t\t\tEnter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount > 0 && amount <= user->balance)
    {
        user->balance -= amount;
        printf("\t\t\t\tWithdrawal Successful! New Balance: %.2f\n", user->balance);
    }
    else if (amount > user->balance)
    {
        printf("\t\t\t\tInsufficient Balance! You only have %.2f\n", user->balance);
    }
    else
    {
        printf("\t\t\t\tInvalid amount! Please enter a positive value.\n");
    }
}
