#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

time_t t;
// create an array for each food item 
double prices [] = { 9.95 , 4.55 , 13.25, 22.35};
// create another array to hold string names
    char foods [4][15] = {"salad", "soup", "sandwich", "pizza"};
// random time
srand((unsigned) time(&t));
// declare sales taxes
 double salesTaxPercentage; 
    printf("What is the percentage sale tax?");
// request sales tax percentage from user
    scanf("%lf", &salesTaxPercentage); 
// declare tip percent
    double tipPercentage; 
    printf("What is the percentage tip?");
    scanf("%lf", &tipPercentage);
// select a random integer from 0-3
    int i = rand() % 4; 
// multiply price of food item by sales tax percentage
    double taxCost = prices[i] * salesTaxPercentage/100;
// multiply price of the food item by sales tax percentage
    double taxTotal = (prices[i] * (1+(salesTaxPercentage/100)));
//multiply tax total by tip percentage
    double tipCost = (taxTotal * tipPercentage/100); 
//taxtotal + tipcost 
    double actualTotal = (taxTotal) * (1+(tipPercentage/100));
    // print tax cost 
    printf("The tax cost will be $%.2f\n", taxCost);
    // print tip cost
    printf("The tip cost will be $%.2f\n", tipCost); 
//print food type, price, and total including tax, and tip 
    printf("The total cost for %s, at $%.2f, including tax and tip will be %.2f", foods[i], prices[i], actualTotal); 
    return 0; 



}