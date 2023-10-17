#include <stdio.h>
#include <string.h>

// Function to calculate the length of a string
int stringLength(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
// Function to copy a string from source to destination
void stringCopy(char *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
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
    return strcmp(str1C;
}}}
