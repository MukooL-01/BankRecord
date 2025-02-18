#include <stdio.h>
#include <stdlib.h>

struct info
{
    int id;
    char name[20];
    char user[20];
    char pass[15];
};

int main()
{
    struct info u1;
    printf("Enter id");
    scanf("%d", &u1.id);

    printf("Enter name");
    for (int i = 0; i < 20; i++)
    {
        scanf("%c", &u1.name[i]);
    }
    printf("Enter Username");
    for (int i = 0; i < 20; i++)
    {
        scanf("%c", &u1.user[i]);
    }
    printf("Enter Password");
    for (int i = 0; i < 15; i++)
    {
        scanf("%c", &u1.pass[i]);
    }

    return 0;
}