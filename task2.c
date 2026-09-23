/*
 * EECS 348 Lab 4
 * Task 2 - Temperature Conversion
 * Author: Conor Rothe
 *
 * This program converts temperatures between Celsius,
 * Fahrenheit, and Kelvin. It also determines the temperature
 * category and displays a weather advisory.
 */

#include <stdio.h>
#include <ctype.h>

int main()
{
    // Stores the temperature entered by the user
    double temperature;

    // Stores the converted temperature
    double convertedTemp;

    // Stores the temperature in Celsius for determining the category
    double celsiusTemp;

    // Stores the original and target temperature scales
    char originalScale;
    char targetScale;

    // Ask the user for the temperature
    printf("Enter the temperature value: ");

    // Make sure the user entered a valid number
    if (scanf("%lf", &temperature) != 1)
    {
        printf("Invalid temperature.\n");
        return 1;
    }

    // Ask for the original temperature scale
    printf("Enter the original scale (C, F, or K): ");
    scanf(" %c", &originalScale);

    // Convert lowercase input to uppercase
    originalScale = toupper(originalScale);

    // Make sure the original scale is valid
    if (originalScale != 'C' &&
        originalScale != 'F' &&
        originalScale != 'K')
    {
        printf("Invalid original scale.\n");
        return 1;
    }
    // Ask for the scale the user wants to convert to
    printf("Enter the scale to convert to (C, F, or K): ");
    scanf(" %c", &targetScale);

    // Convert lowercase input to uppercase
    targetScale = toupper(targetScale);

    // Make sure the target scale is valid
    if (targetScale != 'C' &&
        targetScale != 'F' &&
        targetScale != 'K')
    {
        printf("Invalid target scale.\n");
        return 1;
    }
    // First convert the original temperature to Celsius
    if (originalScale == 'C')
    {
        celsiusTemp = temperature;
    }
    else if (originalScale == 'F')
    {
        celsiusTemp = (temperature - 32) * 5.0 / 9.0;
    }
    else
    {
        celsiusTemp = temperature - 273.15;
    }
    // Kelvin cannot be below absolute zero
    if (celsiusTemp < -273.15)
    {
        printf("Invalid temperature: below absolute zero.\n");
        return 1;
    }
    // Convert from Celsius to the target scale
    if (targetScale == 'C')
    {
        convertedTemp = celsiusTemp;
    }
    else if (targetScale == 'F')
    {
        convertedTemp = (celsiusTemp * 9.0 / 5.0) + 32;
    }
    else
    {
        convertedTemp = celsiusTemp + 273.15;
    }

    // Display the converted temperature
    printf("Converted temperature: %.2f %c\n",
           convertedTemp, targetScale);

    // Determine the temperature category using Celsius
    if (celsiusTemp < 0)
    {
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: Wear a heavy coat!\n");
    }
    else if (celsiusTemp < 10)
    {
        printf("Temperature category: Cold\n");
        printf("Weather advisory: Wear a jacket!\n");
    }
    else if (celsiusTemp < 25)
    {
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: Enjoy the weather!\n");
    }
    else if (celsiusTemp < 35)
    {
        printf("Temperature category: Hot\n");
        printf("Weather advisory: Drink lots of water!\n");
    }
    else
    {
        printf("Temperature category: Extreme Heat\n");
        printf("Weather advisory: Stay indoors!\n");
    }
    // End the program successfully
    return 0;
}