#include <stdio.h>

int main() {
    FILE *file;
    char text[] = "This is the content that will be written to the file.\n";

    // Open a file for writing (create if it doesn't exist or truncate if it does)
    file = fopen("output.txt", "w");

    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    // Write the text to the file
    fputs(text, file);

    // Close the file
    fclose(file);

    printf("Content has been written to the file.\n");
    return 0;
}
