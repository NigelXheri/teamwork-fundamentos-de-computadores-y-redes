#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ID used: 318641

void ControlWithStrings() {
    char str1[20];
    char str2[20];

    //First string
    printf("Enter first string: ");
    scanf("%19s", str1); // fewer than 20 characters

    if (strcmp(str1, "YbTqgvPMZ") != 0) {
        printf("Intruder detected\n");
        exit(0);
    }

    //Second string
    printf("Enter first string: ");
    scanf("%19s", str2);
    
    int len = strlen(str2);

    
    int ID0 = 3;  // ID[0]
    int ID2 = 8;  // ID[2]
    
    if (len < 12 || str2[ID2] != str2[ID0]) {
        printf("There was some failure\n");
        exit(0);
    }
}

int main() {
    ControlWithStrings();
    printf("ControlWithStrings passed!\n");
    return 0;
}