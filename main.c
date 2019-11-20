#include <stdio.h>
#include <stdlib.h>

#define MAX_FOOD_NAME 10
#define MAX_SPECIFIC_FOOD_NAME 20
#define MAX_LINE 30
#define MAX_DRINK_NAME 20

void readSpecificFood(char * specificFood);
void readDrink(char * drink);

int main() {

    printf("Please input number of food types\n>");
    int noOfFoodTypes;
    scanf("%d", &noOfFoodTypes);
    int c;
    while((c= getchar()) != '\n' && c != EOF);

    printf("Please food types (each on a new line, may contain spaces)\n");
    char **foodTypes = (char**)malloc(noOfFoodTypes* sizeof(char*));
    for(int i = 0; i < noOfFoodTypes; i++)
    {
        foodTypes[i] = (char*)malloc(MAX_FOOD_NAME* sizeof(char));
        gets(foodTypes[i]);
    }

    int *noOfSpecificFood = (int*)malloc(noOfFoodTypes* sizeof(int));
    double **foodPrices = (double**)malloc(noOfFoodTypes * sizeof(double*));
    char ***specificFood = (char***)malloc(noOfFoodTypes * sizeof(char**));
    for(int i = 0; i < noOfFoodTypes; i++)
    {
        printf("Please input no of specific foods for food %s\n", foodTypes[i]);
        scanf("%d", &noOfSpecificFood[i]);
        getchar();

        foodPrices[i] = (double*)malloc(noOfSpecificFood[i] * sizeof(double));
        specificFood[i] = (char**)malloc(noOfSpecificFood[i] * sizeof(char*));

        printf("Please input %s specific foods &prices: each line in the format <specific food> (price):\n", foodTypes[i]);
        for(int j = 0; j < noOfSpecificFood[i]; j++)
        {
            printf(">");
            specificFood[i][j] = (char*)malloc(MAX_SPECIFIC_FOOD_NAME * sizeof(char));
            readSpecificFood(specificFood[i][j]);
            char line[MAX_LINE];
            gets(line);
            sscanf(line, "%lf", &foodPrices[i][j]);
        }
    }

    int noOfDrinks;
    printf("Please input no of drinks\n>");
    scanf("%d", &noOfDrinks);
    char **drinks = (char**)malloc(noOfDrinks* sizeof(char*));
    double *drinkPrices = (double*)malloc(noOfDrinks* sizeof(double));
    printf("Please input the drinks: each line in the format <drink> (price):\n");
    for(int i = 0; i < noOfDrinks; i++)
    {
        drinks[i] = (char*)malloc(MAX_DRINK_NAME* sizeof(char));
        printf(">");
        readDrink(drinks[i]);
        char line[MAX_LINE];
        gets(line);
        sscanf(line, "%lf", &drinkPrices[i]);
    }

    printf("\nThe food data is:\n");
    for(int i = 0; i < noOfFoodTypes; i++)
    {
        printf("%s : ", foodTypes[i]);
        for(int j = 0; j < noOfSpecificFood[i]; j++)
        {
            printf("(%s - %.2f) ", specificFood[i][j], foodPrices[i][j]);
        }
        if(i < noOfFoodTypes - 1)
            printf("\n");
    }

    printf("\nThe drink data is:\ndrinks: ");
    for(int i = 0; i < noOfDrinks; i++)
    {
        printf(" %s", drinks[i]);
        if(i < noOfDrinks - 1) printf(",");
    }

    printf("\nprices: ");
    for(int i = 0; i < noOfDrinks; i++)
    {
        printf("%.0f", drinkPrices[i]);
        if(i < noOfDrinks - 1) printf(",");
    }

    for(int i=0;i<noOfFoodTypes;i++) {
        for(int j=0;j<noOfSpecificFood;j++) {
            free(specificFood[i][j]);
        }
        free(foodTypes[i]);
        free(foodPrices[i]);
        free(specificFood[i]);
    }
    free(foodTypes);
    free(drinks);
    free(foodPrices);
    free(specificFood);
    free(noOfSpecificFood);
}

void readSpecificFood(char * specificFood) {
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