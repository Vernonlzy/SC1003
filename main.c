#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char name[20];
    char company[20];
} NameCard;

void listNameCards(NameCard cards[], int *numCards);
void addNameCard(NameCard cards[], int *numCards);
void removeNameCard(NameCard cards[], int *numCards);
void getNameCard(NameCard cards[], int *numCards);

void showMenu();
void printCard(NameCard *card);
int sortCards(NameCard cards[], int size);
NameCard getCardDetails();
char *convertToUpperCase(char *str); 

int main()
{
    NameCard cards[5];
    int numCards = 0;
    int choice;

    showMenu();

    while (choice != 5)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            listNameCards(cards, &numCards);
            break;
        case 2:
            addNameCard(cards, &numCards);
            sortCards(cards, numCards);
            break;
        case 3:
            removeNameCard(cards, &numCards);
            sortCards(cards, numCards);
            break;
        case 4:
            getNameCard(cards, &numCards);
            break;
        default:
            break;
        }
    }
}

// Function implementations

void listNameCards(NameCard cards[], int *numCards)
{
    printf("listNameCards():\n");

    if (*numCards == 0)
        printf("The name card holder is empty\n");

    for (int i = 0; i < *numCards; i++)
    {
        printCard(&cards[i]);
    }
}

void addNameCard(NameCard cards[], int *numCards)
{
    printf("addNameCard():\n");

    NameCard newCard = getCardDetails();
    cards[*numCards] = newCard;

    printf("The name card has been added successfully\n");

    (*numCards)++;
}

void removeNameCard(NameCard cards[], int *numCards)
{
    printf("removeNameCard():\n");

    if (*numCards == 0)
    {
        printf("The name card holder is empty\n");
        return;
    }

    char nameToDelete[20];
    char temp;
    printf("Enter personName: ");
    scanf("%c", &temp); // To handle newline character
    fgets(nameToDelete, 20, stdin);
    strtok(nameToDelete, "\n");

    for (int i = 0; i < *numCards; i++)
    {
        char tempName[20];
        strcpy(tempName, cards[i].name);

        if (strcmp(convertToUpperCase(tempName), convertToUpperCase(nameToDelete)) == 0)
        {
            printf("The name card is removed\n");
            printCard(&cards[i]);

            for (int j = i; j < *numCards - 1; j++)
            {
                cards[j] = cards[j + 1];
            }

            (*numCards)--;

            return;
        }
    }

    printf("The target person name is not in the name card holder\n");
}

void getNameCard(NameCard cards[], int *numCards)
{
    printf("getNameCard():\n");

    if (*numCards == 0)
    {
        printf("The name card holder is empty\n");
        return;
    }

    char nameToFind[20];
    char temp;
    printf("Enter personName: ");
    scanf("%c", &temp); // To handle newline character
    fgets(nameToFind, 20, stdin);
    strtok(nameToFind, "\n");

    for (int i = 0; i < *numCards; i++)
    {
        char tempName[20];
        strcpy(tempName, cards[i].name);

        if (strcmp(convertToUpperCase(tempName), convertToUpperCase(nameToFind)) == 0)
        {
            printf("The target person name is found\n");
            printCard(&cards[i]);
            return;
        }
    }

    printf("The target person name is not found\n");
}

void showMenu()
{
    printf("NTU NAME CARD HOLDER MANAGEMENT PROGRAM:\n");
    printf("1: listNameCards()\n");
    printf("2: addNameCard()\n");
    printf("3: removeNameCard()\n");
    printf("4: getNameCard()\n");
    printf("5: quit\n");
}

void printCard(NameCard *card)
{
    printf("nameCardID: %d\n", card->id);
    printf("personName: %s\n", card->name);
    printf("companyName: %s\n", card->company);
}

int sortCards(NameCard cards[], int size)
{
    int i, j;
    NameCard temp;

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (cards[j].id > cards[j + 1].id)
            {
                temp = cards[j];
                cards[j] = cards[j + 1];
                cards[j + 1] = temp;
            }
        }
    }
    return 0;
}

NameCard getCardDetails()
{
    NameCard card;
    char temp;

    printf("Enter nameCardID: ");
    scanf("%d", &card.id);

    printf("Enter personName: ");
    scanf("%c", &temp); // To handle newline character
    fgets(card.name, 20, stdin);
    strtok(card.name, "\n");

    printf("Enter companyName: ");
    fgets(card.company, 20, stdin);
    strtok(card.company, "\n");

    return card;
}

char *convertToUpperCase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32;
        }
    }

    return str;
}
