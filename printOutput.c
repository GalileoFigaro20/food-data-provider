//
// Created by Ivan on 12/2/2019.
//

#include <stdio.h>
#include <stdlib.h>

void printingDataOnFile(FILE *fo, char **food, int *noOfSpecificFood, char ***specificFood, double** specificFoodPrices, int noOfFood, int noOfDrinks,
                        char **drinks, double* drinksPrices)
{
    for(int i = 0; i < noOfFood; i++)
    {
        fprintf(fo, "%s %d: ", food[i], noOfSpecificFood[i]);
        for(int j = 0; j < noOfSpecificFood[i]; j++)
        {
            fprintf(fo, " (%s - %.2f)", specificFood[i][j], specificFoodPrices[i][j]);
        }
        fprintf(fo, "\n");
    }

    fprintf(fo, "%d:\n", noOfDrinks);
    for(int i = 0; i < noOfDrinks; i++)
    {
        fprintf(fo,"(%s - %.2f) ", drinks[i], drinksPrices[i]);
    }
}

void freeMemory(char **foodTypes, char ***specificFood, char **drinks, double **foodPrices, double *drinkPrices, int *noOfSpecificFood, int noOfFoodTypes)
{
    for(int i=0;i<noOfFoodTypes;i++) {
        for(int j=0;j<noOfSpecificFood[i];j++) {
            free(specificFood[i][j]);
        }
        free(foodTypes[i]);
        free(foodPrices[i]);
        free(specificFood[i]);
    }
    free(foodTypes);
    free(drinks);
    free(drinkPrices);
    free(foodPrices);
    free(specificFood);
    free(noOfSpecificFood);
}