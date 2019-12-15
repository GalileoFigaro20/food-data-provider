//
// Created by Ivan on 12/2/2019.
//

#ifndef FOOD_DATA_PROVIDER_PARSEINPUT_H
#define FOOD_DATA_PROVIDER_PARSEINPUT_H

void readSpecificFood(char * specificFood);
void readDrink(char * drink);
void parseFoodName(char **foodTypes, int noOfFoodTypes);
void parseNoOfFood(int *noOfFoodTypes);
void parseNoOfSpecifficFood(char **foodTypes, int *noOfSpecificFood, int index);
void parseSpecificFoodData(char **foodTypes, int *noOfSpecificFood, char ***specificFood, double **foodPrices, int index);
void parseDrinks(char **drinks, int noOfDrinks, double *drinkPrices);
void parseDrink(char **drinks, double *drinkPrices, int noOfDrinks);
void parseFood(char **foodTypes, int noOfFoodTypes);
void parseSpecificFood(char **foodTypes, char ***specificFood, int *noOfSpecificFood, int noOfFoodTypes, double **foodPrices);
void parseNoOfDrinks(int *noOfDrinks);

#endif //FOOD_DATA_PROVIDER_PARSEINPUT_H
