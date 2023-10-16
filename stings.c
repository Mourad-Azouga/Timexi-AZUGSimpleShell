#include "shell.h"

// Function to calculate the length of a string
int stringLength(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Function to copy a string from source to destination
void stringCopy(char *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// Function to concatenate two strings
void stringConcat(char *dest, const char *src) {
    int destLength = stringLength(dest);
    int i = 0;
    while (src[i] != '\0') {
        dest[destLength + i] = src[i];
        i++;
    }
    dest[destLength + i] = '\0';
}

// Function to compare two strings, returns 0 if equal, <0 if str1 < str2, and >0 if str1 > str2
int stringCompare(const char *str1, const char *str2) {
    return strcmp(str1, str2);
}

// Function to reverse a string
void stringReverse(char *str) {
    int length = stringLength(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

int main() {
    char string1[100] = "Hello, ";
    char string2[] = "world!";
    
    // Test the string functions
    printf("String Length: %d\n", stringLength(string1));
    
    char copyString[100];
    stringCopy(copyString, string1);
    printf("String Copy: %s\n", copyString);
    
    stringConcat(string1, string2);
    printf("String Concatenation: %s\n", string1);
    
    int compareResult = stringCompare(string1, "Hello, world!");
    printf("String Comparison: %d\n", compareResult);
    
    stringReverse(string1);
    printf("String Reverse: %s\n", string1);
    
    return 0;
}
