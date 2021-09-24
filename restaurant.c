// This program will compute the tax and tip on a restauront for a customer
// Will have switch cases for the type of meal and would display the cost, tax, tips, and total.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const float salad = 9.95;
const float soup = 4.55;
const float sandwich = 13.25;
const float pizza = 22.35;


void getTaxAndTip(float* tax,float* tip);
void displayCost(float choice, float tax, float tip);

int main()
{
    //choice is assigned a random number by using random function times the time to get a more consistency of randomness
    //4 was chosen since modules of 4 allows 4 different integers to be chosen on the menu.
    int choice = (rand()*time(NULL)%4);
    float price;
    float tip = 0 , tax = 0;

    //switch statement to randomly select the meal from choice, and assigning price.
    switch (choice){
        case 0:
            printf("You have chosen the salad.\n");
            price = salad;
            break;
        case 1:
            printf("You have chosen the soup.\n");
            price = soup;
            break;
        case 2:
            printf("You have chosen the sandwich.\n");
            price = sandwich;
            break;
        case 3:
            printf("You have chosen the pizza.\n");
            price = pizza;
            break;
    }
    getTaxAndTip(&tax,&tip);
    displayCost(price, tax, tip);

    return 0;
}

void getTaxAndTip(float* tax,float* tip)
{
    float temp=0;
    do
    {
        printf("What is the tax amount in percentage(%%): ");
        scanf(" %f", &temp);
        *tax = temp;

        //check statement for tax. Tax must be greater than 0 since it feels obligatory.
        if(temp<=0)
            printf("Invalid input, please try again.\n");

    }while(temp <=0);

    do
    {
        printf("What is the tip amount in percentage(%%): ");
        scanf(" %f", &temp);
        *tip = temp;

        //check statement so that you would not add a negative number to the cost of the meal.
        if(temp<0)
            printf("Invalid input, please try again.\n");

    } while (temp <0);
}

void displayCost(float price, float tax, float tip)
{
    float tax_price = price*(tax/100);
    float tip_price = price*(tip/100);
    float total = tax_price + tip_price + price;

    printf("The cost of the meal is: $%.2f\n", price);
    printf("The tax is: $%.2f (%.2f%%)\n", tax_price, tax);
    printf("The tip is: $%.2f (%.2f%%)\n", tip_price, tip);
    printf("Your total is $%.2f\n", total);
}