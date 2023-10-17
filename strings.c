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
    dest[i
