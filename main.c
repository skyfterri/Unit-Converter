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
	printf("| Liters (L)         | Gallons (gal)      | Barrel (bbl)       | Fluid Ounce (fl oz)| Pint (pt)          |\n");
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
						moveCursorToColumn(0);
						moveCursorUp();
						printf("|%lf",pint * 0.473176);
						moveCursorToColumn(22);
						printf("|%lf",pint / 8.0);
						moveCursorToColumn(43);
						printf("|%lf",pint / 336.0);
						moveCursorToColumn(64);
						printf("|%lf",pint * 16.0);
						moveCursorToColumn(106);
						printf("|\n");
						return;
					}
				}
				else {
					moveCursorToColumn(0);
					moveCursorUp();
					printf("|%lf",ounce * 0.0295735);
					moveCursorToColumn(22);
					printf("|%lf",ounce * 0.0078125);
					moveCursorToColumn(43);
					printf("|%lf",ounce * 0.000186);
					moveCursorToColumn(85);
					printf("|%lf",ounce / 16.0);
					moveCursorToColumn(106);
					printf("|\n");
					return;
				}
			}
			else {
				moveCursorToColumn(0);
				moveCursorUp();
				printf("|%lf",barrel * 159);
				moveCursorToColumn(22);
				printf("|%lf",barrel * 42);
				moveCursorToColumn(64);
				printf("|%lf",barrel * 42 * 128);
				moveCursorToColumn(85);
				printf("|%lf",barrel * 42 * 8);
				moveCursorToColumn(106);
				printf("|\n");
				return;
			}
		}
		else {
			moveCursorToColumn(0);
			moveCursorUp();
			printf("|%lf",gallon * 3.78541);
			moveCursorToColumn(43);
			printf("|%lf",gallon / 42.0);
			moveCursorToColumn(64);
			printf("|%lf",gallon * 128.0);
			moveCursorToColumn(85);
			printf("|%lf",gallon * 8.0);
			moveCursorToColumn(106);
			printf("|\n");
			return;
		}
	}
	else {
		moveCursorToColumn(22);
		moveCursorUp();
		printf("|%lf",liter * 0.264172);
		moveCursorToColumn(43);
		printf("|%lf",liter / 158.987);
		moveCursorToColumn(64);
		printf("|%lf",liter * 33.814);
		moveCursorToColumn(85);
		printf("|%lf",liter * 2.11338);
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
					printf("|%lf",kelvin - 273.15);
					moveCursorToColumn(22);
					printf("|%lf",((kelvin-273.15)*1.8)+32);
					moveCursorToColumn(64);
					printf("|\n");
					return;
				}
				printf ("The lowest temperature on the Kelvin scale is 0K. \n");
			}
		}
		else {
			if(fahrenheit >= -459.67) {
				moveCursorToColumn(0);
				moveCursorUp();
				printf("|%lf",(fahrenheit-32)*5/9);
				moveCursorToColumn(43);
				printf("|%lf",((fahrenheit-32)*5/9)+273.15);
				moveCursorToColumn(64);
				printf("|\n");
				return;
			}
			printf ("The lowest temperature on the Fahrenheit scale is -459.67°F. \n");
		}
	}
	else {
		if (celsius >= -273.15) {
			moveCursorToColumn(22);
			moveCursorUp();
			printf("|%lf",(celsius * 1.8) + 32);
			moveCursorToColumn(43);
			printf("|%lf",celsius + 273.15);
			moveCursorToColumn(64);
			printf("|\n");
			return;
		}
		printf ("The lowest temperature on the Celsius scale is -273.15°C. \n");
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

void moveCursorToColumn(int column) {
	printf("\033[%dG", column);
}

void moveCursorUp() {
	printf("\033[A");
}
