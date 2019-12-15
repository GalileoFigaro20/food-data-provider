#include <stdio.h>
#include <stdlib.h>
#include "parseInput.h"
#include "printOutput.h"

int main() {

    int noOfFoodTypes;
    printf("Please input number of food types\n>");
    parseNoOfFood(&noOfFoodTypes);

    ///Variables
    char **foodTypes = (char**)malloc(noOfFoodTypes* sizeof(char*));
    int *noOfSpecificFood = (int*)malloc(noOfFoodTypes* sizeof(int));
    double **foodPrices = (double**)malloc(noOfFoodTypes * sizeof(double*));
    char ***specificFood = (char***)malloc(noOfFoodTypes * sizeof(char**));

    ///parsing the data
    parseFood(foodTypes, noOfFoodTypes);
    parseSpecificFood(foodTypes, specificFood, noOfSpecificFood, noOfFoodTypes, foodPrices);

    int noOfDrinks;
    parseNoOfDrinks(&noOfDrinks);
    char **drinks = (char**)malloc(noOfDrinks* sizeof(char*));
    double *drinkPrices = (double*)malloc(noOfDrinks* sizeof(double));
    parseDrinks(drinks, noOfDrinks, drinkPrices);

    ///opening the output file
    FILE* fout;
    fout = fopen("E:\\UTCN- CTI- 2019\\Computer Programming\\Laboratory Projects\\food-data-provider\\data.txt", "w");

    ///Printing the data and freeing the memory
    printingDataOnFile(fout, foodTypes, noOfSpecificFood, specificFood, foodPrices, noOfFoodTypes, noOfDrinks, drinks, drinkPrices);
    freeMemory(foodTypes, specificFood, drinks, foodPrices, drinkPrices, noOfSpecificFood, noOfFoodTypes);
}
