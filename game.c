#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

void displayMenu();
void startGame(int interval);
void changeInterval(int *interval);

int main()
{
    //only 3 choices in the game menu
    int menu=3;
    int interval=10;

    do
    {
        displayMenu();
        scanf("%d", &menu);

        switch(menu){
            case 1:
                startGame(interval);
                break;
            case 2:
                changeInterval(&interval);
                break;
        }
    }while(menu!=3);

    printf("Thank you for playing.");

    return 0;
}

//menu display
void displayMenu()
{
    printf("Press 1 to play a game\n");
    printf("Press 2 to change the max number\n");
    printf("Press 3 to quit\n");
    printf("Choice: ");
}

//case 1 game initiation
void startGame(int interval)
{
    int answer = (rand() * time(NULL) % interval + 1);
    char choice[5] = "";
    int select = 0;

    //shows answer to speed up grading
    printf("%d\n", answer);
    do
    {
        printf("Guess the number:");
        scanf("%s", choice);

        //checks for the letter q or Q to quit game
        if (strcmp(choice, "q") == 0 || strcmp(choice, "Q") == 0)
            break;
        //checks for digit, and enter into choice to see if guess is correct
        else if (isdigit(choice[0]))
            select = atoi(choice);

        if (select < answer)
            printf("You are too low\n");
        if (select > answer)
            printf("You are too high\n");

    } while (select != answer);

    if (select == answer)
        printf("You Won.\n\n");
}

//changes to check for the interval fo the game with the limit for 1-10
void changeInterval(int *interval)
{
    int temp='0';
    do
    {
        printf("Enter the max value for the guessing game(Max:10): ");
        scanf("%d", &temp);

        if(temp>10||temp<0)
            printf("Invalid input, please try again.\n");

    } while (temp>10||temp<1);

    *interval = temp;
}