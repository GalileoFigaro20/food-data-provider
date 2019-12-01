//
// Created by Ivan on 12/2/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include "defines.h"

void readSpecificFood(char * specificFood)
{
    char c = getchar();
    int i=0;
    while(c!='(') {
        specificFood[i] = c;
        c = getchar();
        i++;
    }
    specificFood[i-1] = '\0';
}

void readDrink(char * drink)
{
    char c = getchar();
    int i=0;
    while(c!= '(')
    {
        drink[i] = c;
        c = getchar();
        i++;
    }
    drink[i-1] = '\0';
}

void parseFoodName(char **foodTypes, int noOfFoodTypes)
{
    for(int i = 0; i < noOfFoodTypes; i++)
    {
        foodTypes[i] = (char*)malloc(MAX_FOOD_NAME* sizeof(char));
        gets(foodTypes[i]);
    }
}

void parseNoOfFood(int *noOfFoodTypes)
{
    scanf("%d", &(*noOfFoodTypes));
    int c;
    while((c= getchar()) != '\n' && c != EOF);
}

void parseNoOfDrinks(int *noOfDrinks)
{
    printf("Please input number of drinks:\n");
    scanf("%d", &(*noOfDrinks));
    getchar();
}

void parseNoOfSpecifficFood(char **foodTypes, int *noOfSpecificFood, int index)
{
    printf("Please input no of specific foods for food %s\n", foodTypes[index]);
    scanf("%d", &noOfSpecificFood[index]);
    getchar();
}

void parseSpecificFoodData(char **foodTypes, int *noOfSpecificFood, char ***specificFood, double **foodPrices, int index)
{
    printf("Please input %s specific foods &prices: each line in the format <specific food> (price):\n", foodTypes[index]);
    for(int j = 0; j < noOfSpecificFood[index]; j++)
    {
        printf(">");
        specificFood[index][j] = (char*)malloc(MAX_SPECIFIC_FOOD_NAME * sizeof(char));
        readSpecificFood(specificFood[index][j]);
        char line[MAX_LINE];
        gets(line);
        sscanf(line, "%lf", &foodPrices[index][j]);
    }
}

void parseDrink(char **drinks, double *drinkPrices, int noOfDrinks)
{
    for(int i = 0; i < noOfDrinks; i++)
    {
        drinks[i] = (char*)malloc(MAX_DRINK_NAME* sizeof(char));
        printf(">");
        readDrink(drinks[i]);
        char line[MAX_LINE];
        gets(line);
        sscanf(line, "%lf", &drinkPrices[i]);
    }
}

void parseFood(char **foodTypes, int noOfFoodTypes)
{
    printf("Please food types (each on a new line, may contain spaces)\n");
    parseFoodName(foodTypes, noOfFoodTypes);
}

void parseSpecificFood(char **foodTypes, char ***specificFood, int *noOfSpecificFood, int noOfFoodTypes, double **foodPrices)
{
    for(int i = 0; i < noOfFoodTypes; i++)
    {
        parseNoOfSpecifficFood(foodTypes, noOfSpecificFood, i);

        foodPrices[i] = (double*)malloc(noOfSpecificFood[i] * sizeof(double));
        specificFood[i] = (char**)malloc(noOfSpecificFood[i] * sizeof(char*));

        parseSpecificFoodData(foodTypes, noOfSpecificFood, specificFood, foodPrices, i);
    }
}

void parseDrinks(char **drinks, int noOfDrinks, double *drinkPrices)
{
    printf("Please input the drinks: each line in the format <drink> (price):\n");
    parseDrink(drinks, drinkPrices, noOfDrinks);
}

