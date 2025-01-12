#include <stdio.h>      // For input/output functions
#include <stdlib.h>     // For general utilities (malloc, free, etc.)
#include <stdbool.h>    // For boolean types (bool, true, false)
#include <math.h>       // For mathematical functions (pow, sqrt, etc.)
#include <string.h>     // For string manipulation functions (strcpy, strlen, etc.)
#include <ctype.h>      // For character handling (toupper, tolower, etc.)

#define BUFFER_SIZE 11

// 1. Input and validation functions

bool isBufferEmpty();
void clearInputBuffer();
bool getValidNumber(double *num, char *input);

// 2. Conversion functions

void volumeConversion();
void lengthConversion();
void weightConversion();

void temperatureConversion();
void energyConversion();
void powerConversion();

void areaConversion();
void speedConversion();
void timeConversion();

void pressureConversion();
void angleConversion();

// 3. Output functions

void printMenu();
void printResult(double num);
void moveCursorToColumn(int column);
void moveCursorUp();

int main() {
	int choice;
	printMenu();
	while (1) {
		printf("Enter your choice: ");
		if (scanf("%d", &choice) != 1 || !isBufferEmpty()) {
			printf("Invalid Integer!\n");
			clearInputBuffer();
			continue;
		}
		switch(choice) {
		case 1:
			volumeConversion();
			break;
		case 2:
			lengthConversion();
			break;
		case 3:
			weightConversion();
			break;
		case 4:
			temperatureConversion();
			break;
		case 5:
			energyConversion();
			break;
		case 6:
			powerConversion();
			break;
		case 7:
			areaConversion();
			break;
		case 8:
			speedConversion();
			break;
		case 9:
			timeConversion();
			break;
		case 10:
			pressureConversion();
			break;
		case 11:
			angleConversion();
			break;
		case 0:
			printf("Exiting the program.\n");
			return 0;
		default:
			printf("Invalid choice!\n");
			break;
		}
	}
	return 0;
}

// 1. Input and validation functions

bool isBufferEmpty() {
	int ch = getchar(); // Check the first character in the buffer
	if (ch != EOF && ch != '\n') {
		ungetc(ch, stdin); // Put the character back if it's not an empty buffer
		return false;
	}
	return true;
}

void clearInputBuffer() {
	while (getchar() != '\n');  // Read and discard characters until newline
}

bool getValidNumber(double *num, char *input) {
	if (fgets(input, BUFFER_SIZE, stdin) == NULL) {
		printf("Invalid input!\n");
		clearInputBuffer();
		return false;
	}
	if (input[strlen(input) - 1] != '\n' && strlen(input) == BUFFER_SIZE - 1 && !isBufferEmpty()) {
		printf("Input too long, exceeding buffer size (11)!\n");
		clearInputBuffer();
		return false;
	}
	input[strcspn(input, "\n")] = '\0';
	char *end;
	*num = strtod(input, &end);
	if (*end != '\0' && *end != '\n') {
		printf("Invalid Double!\n");
		return false;
	}
	if (strchr(input, 'e') != NULL || strchr(input, 'E') != NULL) {
		printf("Scientific notation is not allowed!\n");
		return false;
	}
	return true;
}

// 2. Conversion functions

void volumeConversion() {
	double liters, gallons, barrels, ounces, pints;
	char input[BUFFER_SIZE];
	printf("| Liters (L)         | Gallons (gal)      | Barrels (bbl [oil])| Fluid Ounces(fl oz)| Pints (pt)         |\n");
	printf("|--------------------|--------------------|--------------------|--------------------|--------------------|\n");
	printf("|");
	if (!getValidNumber(&liters, input)) {
		moveCursorToColumn(22);
		moveCursorUp();
		moveCursorUp();
		printf("|");
		moveCursorToColumn(43);
		printf("|");
		moveCursorToColumn(64);
		printf("|");
		moveCursorToColumn(85);
		printf("|");
		moveCursorToColumn(106);
		printf("|\n\n");
		return;
	}
	if (strcmp(input, "") == 0) {
		moveCursorToColumn(22);
		moveCursorUp();
		printf("|");
		if (!getValidNumber(&gallons, input)) {
			moveCursorToColumn(43);
			moveCursorUp();
			moveCursorUp();
			printf("|");
			moveCursorToColumn(64);
			printf("|");
			moveCursorToColumn(85);
			printf("|");
			moveCursorToColumn(106);
			printf("|\n\n");
			return;
		}
		if (strcmp(input, "") == 0) {
			moveCursorToColumn(43);
			moveCursorUp();
			printf("|");
			if (!getValidNumber(&barrels, input)) {
				moveCursorToColumn(64);
				moveCursorUp();
				moveCursorUp();
				printf("|");
				moveCursorToColumn(85);
				printf("|");
				moveCursorToColumn(106);
				printf("|\n\n");
				return;
			}
			if (strcmp(input, "") == 0) {
				moveCursorToColumn(64);
				moveCursorUp();
				printf("|");
				if (!getValidNumber(&ounces, input)) {
					moveCursorToColumn(85);
					moveCursorUp();
					moveCursorUp();
					printf("|");
					moveCursorToColumn(106);
					printf("|\n\n");
					return;
				}
				if (strcmp(input, "") == 0) {
					moveCursorToColumn(85);
					moveCursorUp();
					printf("|");
					if (!getValidNumber(&pints, input)) {
						moveCursorToColumn(106);
						moveCursorUp();
						moveCursorUp();
						printf("|\n\n");
						return;
					}
					if (strcmp(input, "") == 0) {
						moveCursorToColumn(106);
						moveCursorUp();
						printf("|\n");
						printf("No Numbers entered!\n");
						return;
					}
					else {
						if (pints < 0) {
							printf("Negative volume doesnt exist!\n");
							moveCursorToColumn(106);
							moveCursorUp();
							moveCursorUp();
							printf("|\n\n");
							return;
						}
						moveCursorToColumn(0);
						moveCursorUp();
						printResult(pints * 0.473176473);
						moveCursorToColumn(22);
						printResult(pints * 0.125);
						moveCursorToColumn(43);
						printResult(pints / 336.0);
						moveCursorToColumn(64);
						printResult(pints * 16.0);
						moveCursorToColumn(106);
						printf("|\n");
						return;
					}
				}
				else {
					if (ounces < 0) {
						printf("Negative volume doesnt exist!\n");
						moveCursorToColumn(85);
						moveCursorUp();
						moveCursorUp();
						printf("|");
						moveCursorToColumn(106);
						printf("|\n\n");
						return;
					}
					moveCursorToColumn(0);
					moveCursorUp();
					printResult(ounces * 0.0295735296);
					moveCursorToColumn(22);
					printResult(ounces * 0.0078125);
					moveCursorToColumn(43);
					printResult(ounces * 0.0001860119);
					moveCursorToColumn(85);
					printResult(ounces * 0.0625);
					moveCursorToColumn(106);
					printf("|\n");
					return;
				}
			}
			else {
				if (barrels < 0)
				{
					printf("Negative volume doesnt exist!\n");
					moveCursorToColumn(64);
					moveCursorUp();
					moveCursorUp();
					printf("|");
					moveCursorToColumn(85);
					printf("|");
					moveCursorToColumn(106);
					printf("|\n\n");
					return;
				}
				moveCursorToColumn(0);
				moveCursorUp();
				printResult(barrels * 158.987294928);
				moveCursorToColumn(22);
				printResult(barrels * 42);
				moveCursorToColumn(64);
				printResult(barrels * 5376);
				moveCursorToColumn(85);
				printResult(barrels * 336);
				moveCursorToColumn(106);
				printf("|\n");
				return;
			}
		}
		else {
			if(gallons < 0) {
				printf("Negative volume doesnt exist!\n");
				moveCursorToColumn(43);
				moveCursorUp();
				moveCursorUp();
				printf("|");
				moveCursorToColumn(64);
				printf("|");
				moveCursorToColumn(85);
				printf("|");
				moveCursorToColumn(106);
				printf("|\n\n");
				return;
			}
			moveCursorToColumn(0);
			moveCursorUp();
			printResult(gallons * 3.785411784);
			moveCursorToColumn(43);
			printResult(gallons * 0.0238095238);
			moveCursorToColumn(64);
			printResult(gallons * 128.0);
			moveCursorToColumn(85);
			printResult(gallons * 8.0);
			moveCursorToColumn(106);
			printf("|\n");
			return;
		}
	}
	else {
		if(liters < 0) {
			printf("Negative volume doesnt exist!\n");
			moveCursorToColumn(22);
			moveCursorUp();
			moveCursorUp();
			printf("|");
			moveCursorToColumn(43);
			printf("|");
			moveCursorToColumn(64);
			printf("|");
			moveCursorToColumn(85);
			printf("|");
			moveCursorToColumn(106);
			printf("|\n\n");
			return;
		}
		moveCursorToColumn(22);
		moveCursorUp();
		printResult(liters * 0.2641720524);
		moveCursorToColumn(43);
		printResult(liters * 0.0062898108);
		moveCursorToColumn(64);
		printResult(liters * 33.8140227018);
		moveCursorToColumn(85);
		printResult(liters * 2.1133764189);
		moveCursorToColumn(106);
		printf("|\n");
		return;
	}
}

void lengthConversion() {
	double meters, miles, inches, feet, yards;
	char input[BUFFER_SIZE];
	printf("| Meters (m)         | Miles (mi)         | Inches (in)        | Feet (ft)          | Yards (yd)         |\n");
	printf("|--------------------|--------------------|--------------------|--------------------|--------------------|\n");
	printf("|");
	if (!getValidNumber(&meters, input)) {
		moveCursorToColumn(22);
		moveCursorUp();
		moveCursorUp();
		printf("|");
		moveCursorToColumn(43);
		printf("|");
		moveCursorToColumn(64);
		printf("|");
		moveCursorToColumn(85);
		printf("|");
		moveCursorToColumn(106);
		printf("|\n\n");
		return;
	}
	if (strcmp(input, "") == 0) {
		moveCursorToColumn(22);
		moveCursorUp();
		printf("|");
		if (!getValidNumber(&miles, input)) {
			moveCursorToColumn(43);
			moveCursorUp();
			moveCursorUp();
			printf("|");
			moveCursorToColumn(64);
			printf("|");
			moveCursorToColumn(85);
			printf("|");
			moveCursorToColumn(106);
			printf("|\n\n");
			return;
		}
		if (strcmp(input, "") == 0) {
			moveCursorToColumn(43);
			moveCursorUp();
			printf("|");
			if (!getValidNumber(&inches, input)) {
				moveCursorToColumn(64);
				moveCursorUp();
				moveCursorUp();
				printf("|");
				moveCursorToColumn(85);
				printf("|");
				moveCursorToColumn(106);
				printf("|\n\n");
				return;
			}
			if (strcmp(input, "") == 0) {
				moveCursorToColumn(64);
				moveCursorUp();
				printf("|");
				if (!getValidNumber(&feet, input)) {
					moveCursorToColumn(85);
					moveCursorUp();
					moveCursorUp();
					printf("|");
					moveCursorToColumn(106);
					printf("|\n\n");
					return;
				}
				if (strcmp(input, "") == 0) {
					moveCursorToColumn(85);
					moveCursorUp();
					printf("|");
					if (!getValidNumber(&yards, input)) {
						moveCursorToColumn(106);
						moveCursorUp();
						moveCursorUp();
						printf("|\n\n");
						return;
					}
					if (strcmp(input, "") == 0) {
						moveCursorToColumn(106);
						moveCursorUp();
						printf("|\n");
						printf("No Numbers entered!\n");
						return;
					}
					else {
						if (yards < 0) {
							printf("Negative length doesnt exist!\n");
							moveCursorToColumn(106);
							moveCursorUp();
							moveCursorUp();
							printf("|\n\n");
							return;
						}
						moveCursorToColumn(0);
						moveCursorUp();
						printResult(yards * 0.9144);
						moveCursorToColumn(22);
						printResult(yards * 0.0005681818);
						moveCursorToColumn(43);
						printResult(yards * 36);
						moveCursorToColumn(64);
						printResult(yards * 3);
						moveCursorToColumn(106);
						printf("|\n");
						return;
					}
				}
				else {
					if (feet < 0) {
						printf("Negative length doesnt exist!\n");
						moveCursorToColumn(85);
						moveCursorUp();
						moveCursorUp();
						printf("|");
						moveCursorToColumn(106);
						printf("|\n\n");
						return;
					}
					moveCursorToColumn(0);
					moveCursorUp();
					printResult(feet * 0.3048);
					moveCursorToColumn(22);
					printResult(feet * 0.0001893939);
					moveCursorToColumn(43);
					printResult(feet * 12);
					moveCursorToColumn(85);
					printResult(feet / 3.0);
					moveCursorToColumn(106);
					printf("|\n");
					return;
				}
			}
			else {
				if (inches < 0)
				{
					printf("Negative length doesnt exist!\n");
					moveCursorToColumn(64);
					moveCursorUp();
					moveCursorUp();
					printf("|");
					moveCursorToColumn(85);
					printf("|");
					moveCursorToColumn(106);
					printf("|\n\n");
					return;
				}
				moveCursorToColumn(0);
				moveCursorUp();
				printResult(inches * 0.0254);
				moveCursorToColumn(22);
				printResult(inches * 1.57828e-5);
				moveCursorToColumn(64);
				printResult(inches * 0.0833333333);
				moveCursorToColumn(85);
				printResult(inches * 0.0277777778);
				moveCursorToColumn(106);
				printf("|\n");
				return;
			}
		}
		else {
			if(miles < 0) {
				printf("Negative length doesnt exist!\n");
				moveCursorToColumn(43);
				moveCursorUp();
				moveCursorUp();
				printf("|");
				moveCursorToColumn(64);
				printf("|");
				moveCursorToColumn(85);
				printf("|");
				moveCursorToColumn(106);
				printf("|\n\n");
				return;
			}
			moveCursorToColumn(0);
			moveCursorUp();
			printResult(miles * 1609.344);
			moveCursorToColumn(43);
			printResult(miles * 63360);
			moveCursorToColumn(64);
			printResult(miles * 5280);
			moveCursorToColumn(85);
			printResult(miles * 1760);
			moveCursorToColumn(106);
			printf("|\n");
			return;
		}
	}
	else {
		if(meters < 0) {
			printf("Negative length doesnt exist!\n");
			moveCursorToColumn(22);
			moveCursorUp();
			moveCursorUp();
			printf("|");
			moveCursorToColumn(43);
			printf("|");
			moveCursorToColumn(64);
			printf("|");
			moveCursorToColumn(85);
			printf("|");
			moveCursorToColumn(106);
			printf("|\n\n");
			return;
		}
		moveCursorToColumn(22);
		moveCursorUp();
		printResult(meters * 0.0006213712);
		moveCursorToColumn(43);
		printResult(meters * 39.3700787402);
		moveCursorToColumn(64);
		printResult(meters * 3.280839895);
		moveCursorToColumn(85);
		printResult(meters * 1.0936132983);
		moveCursorToColumn(106);
		printf("|\n");
		return;
	}
}

void weightConversion() {
	double grams, pounds, ounces, stones;
	char input[BUFFER_SIZE];
	printf("| Grams (g)          | Pounds (lbs)       | Ounces (oz)        | Stones (st)        |\n");
	printf("|--------------------|--------------------|--------------------|--------------------|\n");
	printf("|");
	if (!getValidNumber(&grams, input)) {
		moveCursorToColumn(22);
		moveCursorUp();
		moveCursorUp();
		printf("|");
		moveCursorToColumn(43);
		printf("|");
		moveCursorToColumn(64);
		printf("|");
		moveCursorToColumn(85);
		printf("|\n\n");
		return;
	}
	if (strcmp(input, "") == 0) {
		moveCursorToColumn(22);
		moveCursorUp();
		printf("|");
		if (!getValidNumber(&pounds, input)) {
			moveCursorToColumn(43);
			moveCursorUp();
			moveCursorUp();
			printf("|");
			moveCursorToColumn(64);
			printf("|");
			moveCursorToColumn(85);
			printf("|\n\n");
			return;
		}
		if (strcmp(input, "") == 0) {
			moveCursorToColumn(43);
			moveCursorUp();
			printf("|");
			if (!getValidNumber(&ounces, input)) {
				moveCursorToColumn(64);
				moveCursorUp();
				moveCursorUp();
				printf("|");
				moveCursorToColumn(85);
				printf("|\n\n");
				return;
			}
			if (strcmp(input, "") == 0) {
				moveCursorToColumn(64);
				moveCursorUp();
				printf("|");
				if (!getValidNumber(&stones, input)) {
					moveCursorToColumn(85);
					moveCursorUp();
					moveCursorUp();
					printf("|\n\n");
					return;
				}
				if (strcmp(input, "") == 0) {
					moveCursorToColumn(85);
					moveCursorUp();
					printf("|\n");
					printf("No Numbers entered!\n");
					return;
				}
				else {
					if (stones < 0) {
						printf("Negative length doesnt exist (theoretical concept)!\n");
						moveCursorToColumn(85);
						moveCursorUp();
						moveCursorUp();
						printf("|\n\n");
						return;
					}
					moveCursorToColumn(0);
					moveCursorUp();
					printResult(stones * 5669.904625);
					moveCursorToColumn(22);
					printResult(stones * 12.5);
					moveCursorToColumn(43);
					printResult(stones * 200);
					moveCursorToColumn(85);
					printf("|\n");
					return;
				}
			}
			else {
				if (ounces < 0)
				{
					printf("Negative length doesnt exist (theoretical concept)!\n");
					moveCursorToColumn(64);
					moveCursorUp();
					moveCursorUp();
					printf("|");
					moveCursorToColumn(85);
					printf("|\n\n");
					return;
				}
				moveCursorToColumn(0);
				moveCursorUp();
				printResult(ounces * 28.349523125);
				moveCursorToColumn(22);
				printResult(ounces * 0.0625);
				moveCursorToColumn(64);
				printResult(ounces * 0.005);
				moveCursorToColumn(85);
				printf("|\n");
				return;
			}
		}
		else {
			if(pounds < 0) {
				printf("Negative length doesnt exist (theoretical concept)!\n");
				moveCursorToColumn(43);
				moveCursorUp();
				moveCursorUp();
				printf("|");
				moveCursorToColumn(64);
				printf("|");
				moveCursorToColumn(85);
				printf("|\n\n");
				return;
			}
			moveCursorToColumn(0);
			moveCursorUp();
			printResult(pounds * 453.59237);
			moveCursorToColumn(43);
			printResult(pounds * 16);
			moveCursorToColumn(64);
			printResult(pounds * 0.08);
			moveCursorToColumn(85);
			printf("|\n");
			return;
		}
	}
	else {
		if(grams < 0) {
			printf("Negative length doesnt exist (theoretical concept)!\n");
			moveCursorToColumn(22);
			moveCursorUp();
			moveCursorUp();
			printf("|");
			moveCursorToColumn(43);
			printf("|");
			moveCursorToColumn(64);
			printf("|");
			moveCursorToColumn(85);
			printf("|\n\n");
			return;
		}
		moveCursorToColumn(22);
		moveCursorUp();
		printResult(grams * 0.0022046226);
		moveCursorToColumn(43);
		printResult(grams * 0.0352739619);
		moveCursorToColumn(64);
		printResult(grams * 0.0001763698);
		moveCursorToColumn(85);
		printf("|\n");
		return;
	}
}

void temperatureConversion() {
	double celsius, fahrenheit, kelvin;
	char input[BUFFER_SIZE];
	printf("| Celsius (°C)       | Fahrenheit (°F)    | Kelvin (K)         |\n");
	printf("|--------------------|--------------------|--------------------|\n");
	printf("|");
	if (!getValidNumber(&celsius, input)) {
		moveCursorToColumn(22);
		moveCursorUp();
		moveCursorUp();
		printf("|");
		moveCursorToColumn(43);
		printf("|");
		moveCursorToColumn(64);
		printf("|\n\n");
		return;
	}
	if (strcmp(input, "") == 0) {
		moveCursorToColumn(22);
		moveCursorUp();
		printf("|");
		if (!getValidNumber(&fahrenheit, input)) {
			moveCursorToColumn(43);
			moveCursorUp();
			moveCursorUp();
			printf("|");
			moveCursorToColumn(64);
			printf("|\n\n");
			return;
		}
		if (strcmp(input, "") == 0) {
			moveCursorToColumn(43);
			moveCursorUp();
			printf("|");
			if (!getValidNumber(&kelvin, input)) {
				moveCursorToColumn(64);
				moveCursorUp();
				moveCursorUp();
				printf("|\n\n");
				return;
			}
			if (strcmp(input, "") == 0) {
				moveCursorToColumn(64);
				moveCursorUp();
				printf("|\n");
				printf("No Numbers entered!\n");
				return;
			}
			else {
				if(kelvin >= 0) {
					moveCursorToColumn(0);
					moveCursorUp();
					printResult(kelvin - 273.15);
					moveCursorToColumn(22);
					printResult(((kelvin-273.15)*1.8)+32);
					moveCursorToColumn(64);
					printf("|\n");
					return;
				}
				printf ("The lowest temperature on the Kelvin scale is 0K. \n");
				moveCursorToColumn(64);
				moveCursorUp();
				moveCursorUp();
				printf("|\n\n");
			}
		}
		else {
			if(fahrenheit >= -459.67) {
				moveCursorToColumn(0);
				moveCursorUp();
				printResult((fahrenheit-32)*5/9);
				moveCursorToColumn(43);
				printResult(((fahrenheit-32)*5/9)+273.15);
				moveCursorToColumn(64);
				printf("|\n");
				return;
			}
			printf ("The lowest temperature on the Fahrenheit scale is -459.67°F. \n");
			moveCursorToColumn(43);
			moveCursorUp();
			moveCursorUp();
			printf("|");
			moveCursorToColumn(64);
			printf("|\n\n");
		}
	}
	else {
		if (celsius >= -273.15) {
			moveCursorToColumn(22);
			moveCursorUp();
			printResult((celsius * 1.8) + 32);
			moveCursorToColumn(43);
			printResult(celsius + 273.15);
			moveCursorToColumn(64);
			printf("|\n");
			return;
		}
		printf ("The lowest temperature on the Celsius scale is -273.15°C. \n");
		moveCursorToColumn(22);
		moveCursorUp();
		moveCursorUp();
		printf("|");
		moveCursorToColumn(43);
		printf("|");
		moveCursorToColumn(64);
		printf("|\n\n");
	}
}

void energyConversion() {
	double joules, calories, electronvolts, btus;
	char input[BUFFER_SIZE];
	printf("| Joules (J)         | Calories (cal)     | Electronvolts (eV) | BTUs (btu)         |\n");
	printf("|--------------------|--------------------|--------------------|--------------------|\n");
	printf("|");
	if (!getValidNumber(&joules, input)) {
		moveCursorToColumn(22);
		moveCursorUp();
		moveCursorUp();
		printf("|");
		moveCursorToColumn(43);
		printf("|");
		moveCursorToColumn(64);
		printf("|");
		moveCursorToColumn(85);
		printf("|\n\n");
		return;
	}
	if (strcmp(input, "") == 0) {
		moveCursorToColumn(22);
		moveCursorUp();
		printf("|");
		if (!getValidNumber(&calories, input)) {
			moveCursorToColumn(43);
			moveCursorUp();
			moveCursorUp();
			printf("|");
			moveCursorToColumn(64);
			printf("|");
			moveCursorToColumn(85);
			printf("|\n\n");
			return;
		}
		if (strcmp(input, "") == 0) {
			moveCursorToColumn(43);
			moveCursorUp();
			printf("|");
			if (!getValidNumber(&electronvolts, input)) {
				moveCursorToColumn(64);
				moveCursorUp();
				moveCursorUp();
				printf("|");
				moveCursorToColumn(85);
				printf("|\n\n");
				return;
			}
			if (strcmp(input, "") == 0) {
				moveCursorToColumn(64);
				moveCursorUp();
				printf("|");
				if (!getValidNumber(&btus, input)) {
					moveCursorToColumn(85);
					moveCursorUp();
					moveCursorUp();
					printf("|\n\n");
					return;
				}
				if (strcmp(input, "") == 0) {
					moveCursorToColumn(85);
					moveCursorUp();
					printf("|\n");
					printf("No Numbers entered!\n");
					return;
				}
				else {
					if (btus < 0) {
						printf("Negative energy doesnt exist (theoretically real)!\n");
						moveCursorToColumn(85);
						moveCursorUp();
						moveCursorUp();
						printf("|\n\n");
						return;
					}
					moveCursorToColumn(0);
					moveCursorUp();
					printResult(btus * 1054.3499999744);
					moveCursorToColumn(22);
					printResult(btus * 251.9956978906);
					moveCursorToColumn(43);
					printResult(btus * 6.5807350924984e+21);
					moveCursorToColumn(85);
					printf("|\n");
					return;
				}
			}
			else {
				if (electronvolts < 0)
				{
					printf("Negative energy doesnt exist (theoretically real)!\n");
					moveCursorToColumn(64);
					moveCursorUp();
					moveCursorUp();
					printf("|");
					moveCursorToColumn(85);
					printf("|\n\n");
					return;
				}
				moveCursorToColumn(0);
				moveCursorUp();
				printResult(electronvolts * 1.6021766339999e-19);
				moveCursorToColumn(22);
				printResult(electronvolts * 3.8292940583172e-20);
				moveCursorToColumn(64);
				printResult(electronvolts * 1.5195870764346e-22);
				moveCursorToColumn(85);
				printf("|\n");
				return;
			}
		}
		else {
			if(calories < 0) {
				printf("Negative energy doesnt exist (theoretically real)!\n");
				moveCursorToColumn(43);
				moveCursorUp();
				moveCursorUp();
				printf("|");
				moveCursorToColumn(64);
				printf("|");
				moveCursorToColumn(85);
				printf("|\n\n");
				return;
			}
			moveCursorToColumn(0);
			moveCursorUp();
			printResult(calories * 4.184);
			moveCursorToColumn(43);
			printResult(calories * 2.6114473967545e+19);
			moveCursorToColumn(64);
			printResult(calories * 0.0039683217);
			moveCursorToColumn(85);
			printf("|\n");
			return;
		}
	}
	else {
		if(joules < 0) {
			printf("Negative energy doesnt exist (theoretically real)!\n");
			moveCursorToColumn(22);
			moveCursorUp();
			moveCursorUp();
			printf("|");
			moveCursorToColumn(43);
			printf("|");
			moveCursorToColumn(64);
			printf("|");
			moveCursorToColumn(85);
			printf("|\n\n");
			return;
		}
		moveCursorToColumn(22);
		moveCursorUp();
		printResult(joules * 0.2390057361);
		moveCursorToColumn(43);
		printResult(joules * 6.241509074461e+18);
		moveCursorToColumn(64);
		printResult(joules * 0.0009484517);
		moveCursorToColumn(85);
		printf("|\n");
		return;
	}
}

void powerConversion() {
	double watts, horsepower, btu_hour;
	char input[BUFFER_SIZE];
	printf("| Watts (W)          | Horsepower (hp)    | BTUs/hour (btu/h)  |\n");
	printf("|--------------------|--------------------|--------------------|\n");
	printf("|");
	if (!getValidNumber(&watts, input)) {
		moveCursorToColumn(22);
		moveCursorUp();
		moveCursorUp();
		printf("|");
		moveCursorToColumn(43);
		printf("|");
		moveCursorToColumn(64);
		printf("|\n\n");
		return;
	}
	if (strcmp(input, "") == 0) {
		moveCursorToColumn(22);
		moveCursorUp();
		printf("|");
		if (!getValidNumber(&horsepower, input)) {
			moveCursorToColumn(43);
			moveCursorUp();
			moveCursorUp();
			printf("|");
			moveCursorToColumn(64);
			printf("|\n\n");
			return;
		}
		if (strcmp(input, "") == 0) {
			moveCursorToColumn(43);
			moveCursorUp();
			printf("|");
			if (!getValidNumber(&btu_hour, input)) {
				moveCursorToColumn(64);
				moveCursorUp();
				moveCursorUp();
				printf("|\n\n");
				return;
			}
			if (strcmp(input, "") == 0) {
				moveCursorToColumn(64);
				moveCursorUp();
				printf("|\n");
				printf("No Numbers entered!\n");
				return;
			}
			else {
				if(btu_hour < 0) {
					printf ("Negative power doesnt exist (theoretically real)!\n");
				    moveCursorToColumn(64);
				    moveCursorUp();
				    moveCursorUp();
				    printf("|\n\n");
					return;
				}
				moveCursorToColumn(0);
				moveCursorUp();
				printResult(btu_hour * 0.292875);
				moveCursorToColumn(22);
				printResult(btu_hour * 0.0003981992);
				moveCursorToColumn(64);
				printf("|\n");
			}
		}
		else {
			if(horsepower < 0) {
				printf ("Negative power doesnt exist (theoretically real)!\n");
			    moveCursorToColumn(43);
			    moveCursorUp();
			    moveCursorUp();
			    printf("|");
			    moveCursorToColumn(64);
			    printf("|\n\n");
				return;
			}
			
			moveCursorToColumn(0);
			moveCursorUp();
			printResult(horsepower * 735.49875);
			moveCursorToColumn(43);
			printResult(horsepower * 2511.3060179866);
			moveCursorToColumn(64);
			printf("|\n");
		}
	}
	else {
		if (watts < 0) {
			printf ("Negative power doesnt exist (theoretically real)!\n");
		    moveCursorToColumn(22);
		    moveCursorUp();
	    	moveCursorUp();
	    	printf("|");
	    	moveCursorToColumn(43);
	    	printf("|");
	    	moveCursorToColumn(64);
	    	printf("|\n\n");
			return;
		}
		moveCursorToColumn(22);
		moveCursorUp();
		printResult(watts * 0.0013596216);
		moveCursorToColumn(43);
		printResult(watts * 3.4144259497);
		moveCursorToColumn(64);
		printf("|\n");
	}
}

void areaConversion() {
	double m², acres, rod²;
	char input[BUFFER_SIZE];
	printf("| Square meters (m²) | Acres (ac)         | Square rods (rod²) |\n");
	printf("|--------------------|--------------------|--------------------|\n");
	printf("|");
	if (!getValidNumber(&m², input)) {
		moveCursorToColumn(22);
		moveCursorUp();
		moveCursorUp();
		printf("|");
		moveCursorToColumn(43);
		printf("|");
		moveCursorToColumn(64);
		printf("|\n\n");
		return;
	}
	if (strcmp(input, "") == 0) {
		moveCursorToColumn(22);
		moveCursorUp();
		printf("|");
		if (!getValidNumber(&acres, input)) {
			moveCursorToColumn(43);
			moveCursorUp();
			moveCursorUp();
			printf("|");
			moveCursorToColumn(64);
			printf("|\n\n");
			return;
		}
		if (strcmp(input, "") == 0) {
			moveCursorToColumn(43);
			moveCursorUp();
			printf("|");
			if (!getValidNumber(&rod², input)) {
				moveCursorToColumn(64);
				moveCursorUp();
				moveCursorUp();
				printf("|\n\n");
				return;
			}
			if (strcmp(input, "") == 0) {
				moveCursorToColumn(64);
				moveCursorUp();
				printf("|\n");
				printf("No Numbers entered!\n");
				return;
			}
			else {
				if(rod² < 0) {
					printf ("Negative area doesnt exist!\n");
				    moveCursorToColumn(64);
				    moveCursorUp();
				    moveCursorUp();
				    printf("|\n\n");
					return;
				}
				moveCursorToColumn(0);
				moveCursorUp();
				printResult(rod² * 25.29285264);
				moveCursorToColumn(22);
				printResult(rod² * 0.00625);
				moveCursorToColumn(64);
				printf("|\n");
			}
		}
		else {
			if(acres < 0) {
				printf ("Negative area doesnt exist!\n");
			    moveCursorToColumn(43);
			    moveCursorUp();
			    moveCursorUp();
			    printf("|");
			    moveCursorToColumn(64);
			    printf("|\n\n");
				return;
			}
			
			moveCursorToColumn(0);
			moveCursorUp();
			printResult(acres * 4046.8564224);
			moveCursorToColumn(43);
			printResult(acres * 160);
			moveCursorToColumn(64);
			printf("|\n");
		}
	}
	else {
		if (m² < 0) {
			printf ("Negative area doesnt exist!\n");
		    moveCursorToColumn(22);
		    moveCursorUp();
	    	moveCursorUp();
	    	printf("|");
	    	moveCursorToColumn(43);
	    	printf("|");
	    	moveCursorToColumn(64);
	    	printf("|\n\n");
			return;
		}
		moveCursorToColumn(22);
		moveCursorUp();
		printResult(m² * 0.0002471054);
		moveCursorToColumn(43);
		printResult(m² * 0.039536861);
		moveCursorToColumn(64);
		printf("|\n");
	}
}

void speedConversion() {
	double mps, knots, mach;
	char input[BUFFER_SIZE];
	printf("| Meters per second  | Knots (kt, kn)     | Mach (SI standard) |\n");
	printf("|--------------------|--------------------|--------------------|\n");
	printf("|");
	if (!getValidNumber(&mps, input)) {
		moveCursorToColumn(22);
		moveCursorUp();
		moveCursorUp();
		printf("|");
		moveCursorToColumn(43);
		printf("|");
		moveCursorToColumn(64);
		printf("|\n\n");
		return;
	}
	if (strcmp(input, "") == 0) {
		moveCursorToColumn(22);
		moveCursorUp();
		printf("|");
		if (!getValidNumber(&knots, input)) {
			moveCursorToColumn(43);
			moveCursorUp();
			moveCursorUp();
			printf("|");
			moveCursorToColumn(64);
			printf("|\n\n");
			return;
		}
		if (strcmp(input, "") == 0) {
			moveCursorToColumn(43);
			moveCursorUp();
			printf("|");
			if (!getValidNumber(&mach, input)) {
				moveCursorToColumn(64);
				moveCursorUp();
				moveCursorUp();
				printf("|\n\n");
				return;
			}
			if (strcmp(input, "") == 0) {
				moveCursorToColumn(64);
				moveCursorUp();
				printf("|\n");
				printf("No Numbers entered!\n");
				return;
			}
			else {
				if(mach < 0) {
					printf ("Negative speed doesnt exist!\n");
				    moveCursorToColumn(64);
				    moveCursorUp();
				    moveCursorUp();
				    printf("|\n\n");
					return;
				}
				moveCursorToColumn(0);
				moveCursorUp();
				printResult(mach * 295.0464000003);
				moveCursorToColumn(22);
				printResult(mach * 573.524319655);
				moveCursorToColumn(64);
				printf("|\n");
			}
		}
		else {
			if(knots < 0) {
				printf ("Negative speed doesnt exist!\n");
			    moveCursorToColumn(43);
			    moveCursorUp();
			    moveCursorUp();
			    printf("|");
			    moveCursorToColumn(64);
			    printf("|\n\n");
				return;
			}
			
			moveCursorToColumn(0);
			moveCursorUp();
			printResult(knots * 0.5144444444);
			moveCursorToColumn(43);
			printResult(knots * 0.0017436052);
			moveCursorToColumn(64);
			printf("|\n");
		}
	}
	else {
		if (mps < 0) {
			printf ("Negative speed doesnt exist!\n");
		    moveCursorToColumn(22);
		    moveCursorUp();
	    	moveCursorUp();
	    	printf("|");
	    	moveCursorToColumn(43);
	    	printf("|");
	    	moveCursorToColumn(64);
	    	printf("|\n\n");
			return;
		}
		moveCursorToColumn(22);
		moveCursorUp();
		printResult(mps * 1.9438444924);
		moveCursorToColumn(43);
		printResult(mps * 0.0033892974);
		moveCursorToColumn(64);
		printf("|\n");
	}
}

void timeConversion() {
	double seconds, minutes, hours, days, weeks;
	char input[BUFFER_SIZE];
	printf("| Seconds (s)        | Minutes (min)      | Hours (h)          | Days (d)           | Weeks              |\n");
	printf("|--------------------|--------------------|--------------------|--------------------|--------------------|\n");
	printf("|");
	if (!getValidNumber(&seconds, input)) {
		moveCursorToColumn(22);
		moveCursorUp();
		moveCursorUp();
		printf("|");
		moveCursorToColumn(43);
		printf("|");
		moveCursorToColumn(64);
		printf("|");
		moveCursorToColumn(85);
		printf("|");
		moveCursorToColumn(106);
		printf("|\n\n");
		return;
	}
	if (strcmp(input, "") == 0) {
		moveCursorToColumn(22);
		moveCursorUp();
		printf("|");
		if (!getValidNumber(&minutes, input)) {
			moveCursorToColumn(43);
			moveCursorUp();
			moveCursorUp();
			printf("|");
			moveCursorToColumn(64);
			printf("|");
			moveCursorToColumn(85);
			printf("|");
			moveCursorToColumn(106);
			printf("|\n\n");
			return;
		}
		if (strcmp(input, "") == 0) {
			moveCursorToColumn(43);
			moveCursorUp();
			printf("|");
			if (!getValidNumber(&hours, input)) {
				moveCursorToColumn(64);
				moveCursorUp();
				moveCursorUp();
				printf("|");
				moveCursorToColumn(85);
				printf("|");
				moveCursorToColumn(106);
				printf("|\n\n");
				return;
			}
			if (strcmp(input, "") == 0) {
				moveCursorToColumn(64);
				moveCursorUp();
				printf("|");
				if (!getValidNumber(&days, input)) {
					moveCursorToColumn(85);
					moveCursorUp();
					moveCursorUp();
					printf("|");
					moveCursorToColumn(106);
					printf("|\n\n");
					return;
				}
				if (strcmp(input, "") == 0) {
					moveCursorToColumn(85);
					moveCursorUp();
					printf("|");
					if (!getValidNumber(&weeks, input)) {
						moveCursorToColumn(106);
						moveCursorUp();
						moveCursorUp();
						printf("|\n\n");
						return;
					}
					if (strcmp(input, "") == 0) {
						moveCursorToColumn(106);
						moveCursorUp();
						printf("|\n");
						printf("No Numbers entered!\n");
						return;
					}
					else {
						if (weeks < 0) {
							printf("Negative time doesnt exist!\n");
							moveCursorToColumn(106);
							moveCursorUp();
							moveCursorUp();
							printf("|\n\n");
							return;
						}
						moveCursorToColumn(0);
						moveCursorUp();
						printResult(weeks * 604800);
						moveCursorToColumn(22);
						printResult(weeks * 10080);
						moveCursorToColumn(43);
						printResult(weeks * 168);
						moveCursorToColumn(64);
						printResult(weeks * 7);
						moveCursorToColumn(106);
						printf("|\n");
						return;
					}
				}
				else {
					if (days < 0) {
						printf("Negative time doesnt exist!\n");
						moveCursorToColumn(85);
						moveCursorUp();
						moveCursorUp();
						printf("|");
						moveCursorToColumn(106);
						printf("|\n\n");
						return;
					}
					moveCursorToColumn(0);
					moveCursorUp();
					printResult(days * 86400);
					moveCursorToColumn(22);
					printResult(days * 1440);
					moveCursorToColumn(43);
					printResult(days * 24);
					moveCursorToColumn(85);
					printResult(days / 7.0);
					moveCursorToColumn(106);
					printf("|\n");
					return;
				}
			}
			else {
				if (hours < 0)
				{
					printf("Negative time doesnt exist!\n");
					moveCursorToColumn(64);
					moveCursorUp();
					moveCursorUp();
					printf("|");
					moveCursorToColumn(85);
					printf("|");
					moveCursorToColumn(106);
					printf("|\n\n");
					return;
				}
				moveCursorToColumn(0);
				moveCursorUp();
				printResult(hours * 3600);
				moveCursorToColumn(22);
				printResult(hours * 60);
				moveCursorToColumn(64);
				printResult(hours / 24.0);
				moveCursorToColumn(85);
				printResult(hours / 168.0);
				moveCursorToColumn(106);
				printf("|\n");
				return;
			}
		}
		else {
			if(minutes < 0) {
				printf("Negative time doesnt exist!\n");
				moveCursorToColumn(43);
				moveCursorUp();
				moveCursorUp();
				printf("|");
				moveCursorToColumn(64);
				printf("|");
				moveCursorToColumn(85);
				printf("|");
				moveCursorToColumn(106);
				printf("|\n\n");
				return;
			}
			moveCursorToColumn(0);
			moveCursorUp();
			printResult(minutes * 60);
			moveCursorToColumn(43);
			printResult(minutes / 60.0);
			moveCursorToColumn(64);
			printResult(minutes / 1440.0);
			moveCursorToColumn(85);
			printResult(minutes / 10080.0);
			moveCursorToColumn(106);
			printf("|\n");
			return;
		}
	}
	else {
		if(seconds < 0) {
			printf("Negative time doesnt exist!\n");
			moveCursorToColumn(22);
			moveCursorUp();
			moveCursorUp();
			printf("|");
			moveCursorToColumn(43);
			printf("|");
			moveCursorToColumn(64);
			printf("|");
			moveCursorToColumn(85);
			printf("|");
			moveCursorToColumn(106);
			printf("|\n\n");
			return;
		}
		moveCursorToColumn(22);
		moveCursorUp();
		printResult(seconds / 60.0);
		moveCursorToColumn(43);
		printResult(seconds / 3600.0);
		moveCursorToColumn(64);
		printResult(seconds / 86400.0);
		moveCursorToColumn(85);
		printResult(seconds / 604800.0);
		moveCursorToColumn(106);
		printf("|\n");
		return;
	}
}

void pressureConversion() {
	double pascals, atmospheres, torrs;
	char input[BUFFER_SIZE];
	printf("| Pascals (Pa)       | Atmospheres (atm)  | Torrs (Torr)       |\n");
	printf("|--------------------|--------------------|--------------------|\n");
	printf("|");
	if (!getValidNumber(&pascals, input)) {
		moveCursorToColumn(22);
		moveCursorUp();
		moveCursorUp();
		printf("|");
		moveCursorToColumn(43);
		printf("|");
		moveCursorToColumn(64);
		printf("|\n\n");
		return;
	}
	if (strcmp(input, "") == 0) {
		moveCursorToColumn(22);
		moveCursorUp();
		printf("|");
		if (!getValidNumber(&atmospheres, input)) {
			moveCursorToColumn(43);
			moveCursorUp();
			moveCursorUp();
			printf("|");
			moveCursorToColumn(64);
			printf("|\n\n");
			return;
		}
		if (strcmp(input, "") == 0) {
			moveCursorToColumn(43);
			moveCursorUp();
			printf("|");
			if (!getValidNumber(&torrs, input)) {
				moveCursorToColumn(64);
				moveCursorUp();
				moveCursorUp();
				printf("|\n\n");
				return;
			}
			if (strcmp(input, "") == 0) {
				moveCursorToColumn(64);
				moveCursorUp();
				printf("|\n");
				printf("No Numbers entered!\n");
				return;
			}
			else {
				if(torrs < 0) {
					printf ("Negative pressure doesnt exist!\n");
				    moveCursorToColumn(64);
				    moveCursorUp();
				    moveCursorUp();
				    printf("|\n\n");
					return;
				}
				moveCursorToColumn(0);
				moveCursorUp();
				printResult(torrs * 133.3223684211);
				moveCursorToColumn(22);
				printResult(torrs / 760.0);
				moveCursorToColumn(64);
				printf("|\n");
			}
		}
		else {
			if(atmospheres < 0) {
				printf ("Negative pressure doesnt exist!\n");
			    moveCursorToColumn(43);
			    moveCursorUp();
			    moveCursorUp();
			    printf("|");
			    moveCursorToColumn(64);
			    printf("|\n\n");
				return;
			}
			
			moveCursorToColumn(0);
			moveCursorUp();
			printResult(atmospheres * 101325);
			moveCursorToColumn(43);
			printResult(atmospheres * 760);
			moveCursorToColumn(64);
			printf("|\n");
		}
	}
	else {
		if (pascals < 0) {
			printf ("Negative pressure doesnt exist!\n");
		    moveCursorToColumn(22);
		    moveCursorUp();
	    	moveCursorUp();
	    	printf("|");
	    	moveCursorToColumn(43);
	    	printf("|");
	    	moveCursorToColumn(64);
	    	printf("|\n\n");
			return;
		}
		moveCursorToColumn(22);
		moveCursorUp();
		printResult(pascals / 101325.0);
		moveCursorToColumn(43);
		printResult(pascals * 0.0075006168);
		moveCursorToColumn(64);
		printf("|\n");
	}
}

void angleConversion() {
	double degrees, radians, gradians;
	char input[BUFFER_SIZE];
	printf("| Degrees (°)        | Radians (rad)      | Gradians (gon)     |\n");
	printf("|--------------------|--------------------|--------------------|\n");
	printf("|");
	if (!getValidNumber(&degrees, input)) {
		moveCursorToColumn(22);
		moveCursorUp();
		moveCursorUp();
		printf("|");
		moveCursorToColumn(43);
		printf("|");
		moveCursorToColumn(64);
		printf("|\n\n");
		return;
	}
	if (strcmp(input, "") == 0) {
		moveCursorToColumn(22);
		moveCursorUp();
		printf("|");
		if (!getValidNumber(&radians, input)) {
			moveCursorToColumn(43);
			moveCursorUp();
			moveCursorUp();
			printf("|");
			moveCursorToColumn(64);
			printf("|\n\n");
			return;
		}
		if (strcmp(input, "") == 0) {
			moveCursorToColumn(43);
			moveCursorUp();
			printf("|");
			if (!getValidNumber(&gradians, input)) {
				moveCursorToColumn(64);
				moveCursorUp();
				moveCursorUp();
				printf("|\n\n");
				return;
			}
			if (strcmp(input, "") == 0) {
				moveCursorToColumn(64);
				moveCursorUp();
				printf("|\n");
				printf("No Numbers entered!\n");
				return;
			}
			else {
				moveCursorToColumn(0);
				moveCursorUp();
				printResult(gradians * 0.9);
				moveCursorToColumn(22);
				printResult(gradians * 0.0157079633);
				moveCursorToColumn(64);
				printf("|\n");
			}
		}
		else {
			moveCursorToColumn(0);
			moveCursorUp();
			printResult(radians * 57.2957795131);
			moveCursorToColumn(43);
			printResult(radians * 63.6619772368);
			moveCursorToColumn(64);
			printf("|\n");
		}
	}
	else {
		moveCursorToColumn(22);
		moveCursorUp();
		printResult(degrees * 0.0174532925);
		moveCursorToColumn(43);
		printResult(degrees * 1.1111111111);
		moveCursorToColumn(64);
		printf("|\n");
	}
}

// 3. Output and cursor functions

void printMenu() {
	printf("\nUnit Converter\n");
	// Group 1: Physical dimensions/measurements
	printf("1 -> Volume        2 -> Length        3 -> Weight\n");
	// Group 2: Thermal and energy-related measurements
	printf("4 -> Temperature   5 -> Energy        6 -> Power\n");
	// Group 3: Space, motion, and temporal concepts
	printf("7 -> Area          8 -> Speed         9 -> Time\n");
	// Group 4: Pressure and angular measurements
	printf("10 -> Pressure     11 -> Angle        0 -> Exit\n");
}

void printResult(double num) {
	char buffer[50];
	// Format the number without trailing zeros and left-aligned
	if (floor(num) == num) {
		// It's an integer
		if (snprintf(buffer, sizeof(buffer), "%-20.0f", num) > 20) {
			// If the formatted number exceeds 20 characters, print in scientific notation
			snprintf(buffer, sizeof(buffer), "%-20.0e", num);
		}
	} else {
		// It's a floating-point number, print it in full width (20 characters) without trailing zeroes
		if (snprintf(buffer, sizeof(buffer), "%-20.10g", num) > 20) {
			// If the formatted number exceeds 20 characters, print in scientific notation
			snprintf(buffer, sizeof(buffer), "%-20.10e", num);
		}
	}
	// Print the result
	printf("|%s", buffer);
}

void moveCursorToColumn(int column) {
	printf("\033[%dG", column);
}

void moveCursorUp() {
	printf("\033[A");
}
