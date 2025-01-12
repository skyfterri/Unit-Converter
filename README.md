# Unit Converter Program Overview

This C program provides unit conversions for a wide range of physical and mathematical quantities, including volume, length, weight, temperature, energy, power, area, speed, time, pressure, and angles. It interacts with the user to input values, validates the input, and outputs the conversion results in a structured format.

## Key Features
- **Input Validation**: Ensures the user inputs valid numeric values for conversions.
- **Multiple Unit Conversions**: Supports conversions between various units like Liters to Gallons, Degrees to Radians, etc.
- **Real-Time User Interaction**: Outputs conversion results dynamically based on user input.
- **Table Layout Output**: Uses a table-like format for clear visualization of conversions.

## Main Components

### 1. Input and Validation Functions
- **`getValidNumber`**: Accepts user input and ensures the value is a valid number, rejecting non-numeric or excessive inputs.
- **`clearInputBuffer`**: Clears the input buffer to ensure there are no leftover characters.
- **`isBufferEmpty`**: Verifies that the input buffer is empty before proceeding.

### 2. Conversion Functions
The program has dedicated conversion functions for various measurement categories:
- **Volume Conversion**: Converts between Liters, Gallons, Barrels, Fluid Ounces, and Pints.
- **Length Conversion**: Converts between meters, kilometers, miles, etc.
- **Weight Conversion**: Converts between kilograms, grams, pounds, etc.
- **Temperature Conversion**: Handles conversions between Celsius, Fahrenheit, and Kelvin.
- **Energy Conversion**: Converts between joules, calories, and other energy units.
- **Power Conversion**: Converts between watts, horsepower, and other power units.
- **Area Conversion**: Converts between square meters, acres, square miles, etc.
- **Speed Conversion**: Converts between kilometers per hour, meters per second, etc.
- **Time Conversion**: Converts between hours, minutes, seconds, etc.
- **Pressure Conversion**: Converts between Pascals, atmospheres, and other pressure units.
- **Angle Conversion**: Converts between degrees, radians, and gradians.

### 3. Output Functions
- **`printResult`**: Formats the conversion result and displays it in a structured manner.
- **`printMenu`**: Displays the main menu of available conversions.
- **`moveCursorToColumn`**: Moves the cursor to a specific column in the terminal for formatting.
- **`moveCursorUp`**: Moves the cursor up to print results in a tabular format.

### 4. Main Program Flow
- **User Menu**: Displays options to choose from various conversion categories.
- **User Interaction**: Continuously prompts the user for input, performs the conversion, and displays the result.
- **Exit Option**: The user can exit the program by selecting option `0`.

## Error Handling
- **Negative Values**: Many functions, especially for physical quantities like volume, weight, and temperature, do not accept negative values.
- **Input Validation**: Handles invalid input gracefully and prompts the user to re-enter valid data.

## Example Usage
1. **User Input**: The program prompts the user to enter a value for the selected conversion.
2. **Conversion Results**: The program calculates and displays the corresponding values in different units, formatted in a table-like structure.
3. **Exit**: The user can exit the program by selecting the exit option (`0`).

## Conclusion
This unit converter program offers a versatile tool for converting between multiple measurement units. The interactive interface and real-time results provide a simple and efficient way to perform conversions for various applications.
