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
			//lengthConversion();
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
	double liter, gallon, barrel, ounce, pint;
	char input[BUFFER_SIZE];
	printf("| Liters (L)         | Gallons (gal)      | Barrel (bbl [oil]) | Fluid Ounce (fl oz)| Pint (pt)          |\n");
	printf("|--------------------|--------------------|--------------------|--------------------|--------------------|\n");
	printf("|");
	if (!getValidNumber(&liter, input)) {
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
		if (!getValidNumber(&gallon, input)) {
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
			if (!getValidNumber(&barrel, input)) {
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
				if (!getValidNumber(&ounce, input)) {
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
					if (!getValidNumber(&pint, input)) {
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
						if (pint < 0) {
							printf("Negative volume doesnt exist!\n");
							moveCursorToColumn(106);
							moveCursorUp();
							moveCursorUp();
							printf("|\n\n");
							return;
						}
						moveCursorToColumn(0);
						moveCursorUp();
						printResult(pint * 0.473176473);
						moveCursorToColumn(22);
						printResult(pint * 0.125);
						moveCursorToColumn(43);
						printResult(pint / 336.0);
						moveCursorToColumn(64);
						printResult(pint * 16.0);
						moveCursorToColumn(106);
						printf("|\n");
						return;
					}
				}
				else {
					if (ounce < 0) {
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
					printResult(ounce * 0.0295735296);
					moveCursorToColumn(22);
					printResult(ounce * 0.0078125);
					moveCursorToColumn(43);
					printResult(ounce * 0.0001860119);
					moveCursorToColumn(85);
					printResult(ounce * 0.0625);
					moveCursorToColumn(106);
					printf("|\n");
					return;
				}
			}
			else {
				if (barrel < 0)
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
				printResult(barrel * 158.987294928);
				moveCursorToColumn(22);
				printResult(barrel * 42);
				moveCursorToColumn(64);
				printResult(barrel * 5376);
				moveCursorToColumn(85);
				printResult(barrel * 336);
				moveCursorToColumn(106);
				printf("|\n");
				return;
			}
		}
		else {
			if(gallon < 0) {
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
			printResult(gallon * 3.785411784);
			moveCursorToColumn(43);
			printResult(gallon * 0.0238095238);
			moveCursorToColumn(64);
			printResult(gallon * 128.0);
			moveCursorToColumn(85);
			printResult(gallon * 8.0);
			moveCursorToColumn(106);
			printf("|\n");
			return;
		}
	}
	else {
		if(liter < 0) {
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
		printResult(liter * 0.2641720524);
		moveCursorToColumn(43);
		printResult(liter * 0.0062898108);
		moveCursorToColumn(64);
		printResult(liter * 33.8140227018);
		moveCursorToColumn(85);
		printResult(liter * 2.1133764189);
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
