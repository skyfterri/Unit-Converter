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
			//weightConversion();
			break;
		case 4:
			temperatureConversion();
			break;
		case 5:
			//energyConversion();
			break;
		case 6:
			//powerConversion();
			break;
		case 7:
			//areaConversion();
			break;
		case 8:
			//speedConversion();
			break;
		case 9:
			//timeConversion();
			break;
		case 10:
			//pressureConversion();
			break;
		case 11:
			//angleConversion();
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
	printf("| Liters (L)         | Gallons (gal)      | Barrels (bbl [oil])| Ounces (fl oz)     | Pints (pt)         |\n");
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
				if(kelvin >= 0.0) {
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
