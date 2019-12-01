//
// Created by Ivan on 12/2/2019.
//

#ifndef FOOD_DATA_PROVIDER_PRINTOUTPUT_H
#define FOOD_DATA_PROVIDER_PRINTOUTPUT_H
#include <stdio.h>

void printingDataOnFile(FILE *fo, char **food, int *noOfSpecificFood, char ***specificFood, double** specificFoodPrices, int noOfFood, int noOfDrinks,
                        char **drinks, double* drinksPrices);
void freeMemory(char **foodTypes, char ***specificFood, char **drinks, double **foodPrices, double *drinkPrices, int *noOfSpecificFood, int noOfFoodTypes);

#endif //FOOD_DATA_PROVIDER_PRINTOUTPUT_H
