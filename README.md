# Unit Converter

This C program provides unit conversions for a wide range of physical and mathematical quantities, including volume, length, weight, temperature, energy, power, area, speed, time, pressure, and angles. It interacts with the user to input values, validates the input, and outputs the conversion results in a structured format.

### **Compiler Compatibility**

This code is written in standard C and should work with any C compiler that supports the C99 standard or later. However, if the compiler does not support or correctly interpret ANSI escape characters, the formatting (cursor movement) may not function as intended. A recommended platform for testing the code is [OnlineGDB](https://www.onlinegdb.com/online_c_compiler#).

## Features

### **Conversion Functions**

The program supports the following conversions:

- **Volume Conversion**: Converts between Liters, Gallons, Barrels, Fluid Ounces, and Pints.
- **Length Conversion**: Converts between Meters, Miles, Inches, Feet, and Yards.
- **Weight Conversion**: Converts between Grams, Pounds, Ounces, and Stones.
- **Temperature Conversion**: Converts between Celsius, Fahrenheit, and Kelvin.
- **Energy Conversion**: Converts between Joules, Calories, Electronvolts, and British Thermal Units (BTU).
- **Power Conversion**: Converts between Watts, Horsepower, and British Thermal Units per Hour (BTU/hr).
- **Area Conversion**: Converts between Square Meters, Acres, and Square Rods.
- **Speed Conversion**: Converts between Meters per second, Knots, and Mach.
- **Time Conversion**: Converts between Seconds, Minutes, Hours, Days, and Weeks.
- **Pressure Conversion**: Converts between Pascals, Atmospheres, and Torrs.
- **Angle Conversion**: Converts between Degrees, Radians, and Gradians.

### **Input Logic**

The program validates the input in the following ways:

- When a choice is requested by the program, any input other than the listed choices will be considered **invalid**.
- When entering a number to convert:
  - If the input is not a valid number, it is considered **invalid**.
  - If the input exceeds the buffer size (10 characters), it is considered **invalid** (for aesthetic purposes).
  - If the input is a scientific number, it is considered **invalid** (for aesthetic purposes).
  
In conversions related to volume, length, weight, energy, power, area, speed, time, and pressure:
- Negative numbers are **invalid**.

In **temperature conversion**:
- Fahrenheit values less than -459.67 are **invalid**.
- Celsius values less than -273.15 are **invalid**.
- Kelvin values less than 0 are **invalid**.

For any invalid input, the respective prompt will be shown to the user.

### **Output Logic**

When printing results:
- If the number fits within the designated column width, it will be printed as an integer (if the result is an integer) or as a double (if the result is a floating-point number).
- If the number is large enough to exceed the column width, it will be printed in **scientific notation** (for aesthetic purposes).

## How to Use

1. **Start the Program**: Upon running the program, a menu will be displayed listing all available operations.
2. **Enter your Choice**: Select a conversion by typing the corresponding number.
3. **Provide Input**: A table-like format will be printed for the chosen conversion. Press Enter until you are under the column of the unit you want to convert from, then enter the number.
4. **Get the Result**: The program will calculate and display the conversions for all the other units in their respective columns.
5. **Exit the Program**: To exit, type `0`.

## License

This program is open source. Feel free to modify or distribute it under the terms of your preferred license.
