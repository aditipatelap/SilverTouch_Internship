#include <stdio.h>

// Function to read and print the contents of a file
void readFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    char ch;

    if (file == NULL) {
        printf("File not found or unable to open: %s\n", filename);
        return;
    }

    printf("Contents of %s:\n", filename);
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);
}

// Function to write content to a file
void writeFile(const char *filename, const char *content) {
    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        printf("Unable to create or open the file: %s\n", filename);
        return;
    }

    fprintf(file, "%s", content);
    fclose(file);

    printf("Content written to %s successfully.\n", filename);
}

// Function to copy content from one file to another
void copyFile(const char *sourceFilename, const char *destinationFilename) {
    FILE *sourceFile = fopen(sourceFilename, "r");
    FILE *destinationFile = fopen(destinationFilename, "w");
    char ch;

    if (sourceFile == NULL) {
        printf("Source file not found or unable to open: %s\n", sourceFilename);
        return;
    }

    if (destinationFile == NULL) {
        printf("Unable to create or open the destination file: %s\n", destinationFilename);
        fclose(sourceFile);
        return;
    }

    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destinationFile);
    }

    fclose(sourceFile);
    fclose(destinationFile);

    printf("Content copied from %s to %s successfully.\n", sourceFilename, destinationFilename);
}

int main() {
    char sourceFilename[100], destinationFilename[100], content[100];

    // Reading from a file
    printf("Enter the name of the file to read: ");
    scanf("%s", sourceFilename);
    readFile(sourceFilename);

    // Writing to a file
    printf("Enter the name of the file to write: ");
    scanf("%s", destinationFilename);
    printf("Enter content to write to the file:\n");
    scanf(" %[^\n]", content);
    writeFile(destinationFilename, content);

    // Copying content from one file to another
    printf("Enter the name of the source file: ");
    scanf("%s", sourceFilename);
    printf("Enter the name of the destination file: ");
    scanf("%s", destinationFilename);
    copyFile(sourceFilename, destinationFilename);

    return 0;
}