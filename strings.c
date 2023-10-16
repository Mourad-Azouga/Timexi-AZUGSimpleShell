#include "shell.h"

**
 * _strlen - function to calculates the length of string
 * @s: string to be calculated
 * Return: length
 */

int stringLength(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

/**
 * _strcp - function to copy a string from source to destination
*@s: strrings to copy 
*Return: copying
*/

void stringCopy(char *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

/**
 * _strcat- function to concatenate two strings
*@s: strings to concatenate 
*Return: concatenate
*/

void stringConcat(char *dest, const char *src) {
    int destLength = stringLength(dest);
    int i = 0;
    while (src[i] != '\0') {
        dest[destLength + i] = src[i];
        i++;
    }
    dest[destLength + i] = '\0';
}

/Function to compare two strings, returns 0 if equal, <0 if str1 < str2, and >0 if str1 > str2
int stringCompare(const char *str1, const char *str2) {
    return strcmp(str1, str2);
}
