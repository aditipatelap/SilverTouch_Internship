#include <stdio.h>

// Function to convert distance units
double convertDistance(double value, char sourceUnit, char targetUnit) {
    const double metersPerKilometer = 1000.0;
    const double inchesPerFoot = 12.0;
    const double centimetersPerInch = 2.54;

    if (sourceUnit == 'm' && targetUnit == 'km') {
        return value / metersPerKilometer;
    } else if (sourceUnit == 'km' && targetUnit == 'm') {
        return value * metersPerKilometer;
    } else if (sourceUnit == 'in' && targetUnit == 'cm') {
        return value * centimetersPerInch;
    } else if (sourceUnit == 'cm' && targetUnit == 'in') {
        return value / centimetersPerInch;
    } else if (sourceUnit == 'ft' && targetUnit == 'm') {
        return value * inchesPerFoot * centimetersPerInch / metersPerKilometer;
    } else if (sourceUnit == 'm' && targetUnit == 'ft') {
        return value * metersPerKilometer / (inchesPerFoot * centimetersPerInch);
    }

    // Return the original value if no conversion is needed
    return value;
}

// Function to convert weight units
double convertWeight(double value, char sourceUnit, char targetUnit) {
    const double kilogramsPerPound = 0.453592;

    if (sourceUnit == 'kg' && targetUnit == 'lb') {
        return value / kilogramsPerPound;
    } else if (sourceUnit == 'lb' && targetUnit == 'kg') {
        return value * kilogramsPerPound;
    }

    // Return the original value if no conversion is needed
    return value;
}

int main() {
    double inputValue;
    char sourceUnit, targetUnit;

    printf("Enter the value: ");
    scanf("%lf", &inputValue);

    printf("Enter the source unit (e.g., m, km, in, cm, ft, kg, lb): ");
    scanf(" %c", &sourceUnit);  // Using a space before %c to consume the newline character

    printf("Enter the target unit (e.g., m, km, in, cm, ft, kg, lb): ");
    scanf(" %c", &targetUnit);

    // Perform the conversion based on the input units
    double result;

    if (sourceUnit == 'm' || sourceUnit == 'km' || sourceUnit == 'in' || sourceUnit == 'cm' || sourceUnit == 'ft') {
        result = convertDistance(inputValue, sourceUnit, targetUnit);
        printf("%.2f %c is equal to %.2f %c\n", inputValue, sourceUnit, result, targetUnit);
    } else if (sourceUnit == 'kg' || sourceUnit == 'lb') {
        result = convertWeight(inputValue, sourceUnit, targetUnit);
        printf("%.2f %c is equal to %.2f %c\n", inputValue, sourceUnit, result, targetUnit);
    } else {
        printf("Invalid unit(s) entered.\n");
    }

    return 0;
}