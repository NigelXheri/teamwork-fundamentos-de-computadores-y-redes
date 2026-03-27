#include <cstdint>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

extern "C" bool IsValidAssembly(int a, int b, int c);

// ID used: 318641

using namespace std;

void ControlWithStrings() {
    char str1[20];
    char str2[20];

    // First string
    printf("Enter first string: ");
    scanf("%19s", str1); // fewer than 20 characters

    if (strcmp(str1, "YbTqgvPMZ") != 0) {
        printf("Intruder detected\n");
        exit(0);
    }

    // Second string
    printf("Enter second string: ");
    scanf("%19s", str2);

    int len = strlen(str2);

    int ID0 = 3; // ID[0]
    int ID2 = 8; // ID[2]

    if (len < 12 || str2[ID2] != str2[ID0]) {
        printf("There was some failure\n");
        exit(0);
    }
}

void AsmZeroBit() {
    int a, b, c;
    cout << "Give 3 integers:" << endl;
    cin >> a >> b >> c;
    if (!IsValidAssembly(a, b, c)) {
        cout << "Access denied" << endl;
        exit(1);
    }
}

void BitBasedAccess() {

    unsigned int a, b, check1, check2, check3a, check3b, power;
    unsigned short ID0 = 3, ID1 = 1, ID3 = 6, ID4 = 4, ID5 = 1;

    cout << "Give 2 unsigned integers:" << endl;

    cin >> a;
    cin >> b;

    unsigned int lower, higher;

    if (ID5 > ID3) {
        lower = ID3;
        higher = ID5;
    } else {
        lower = ID5;
        higher = ID3;
    }

    power = (pow(2, higher - lower + 1) - 1);
    check1 = b >> lower & power;

    if (check1 != 0) {
        cout << "There was some failure" << endl;
        exit(1);
    }

    check2 = a >> ID0 & 1;

    if (check2 != 0) {
        cout << "Halt!" << endl;
        exit(1);
    }

    check3a = a >> ID4 & 1;
    check3b = b >> ID1 & 1;

    if (check3a != check3b) {
        cout << "Intruder detected" << endl;
        exit(1);
    }

    return;
}

void CheckArrayBit() {

    int8_t i8arr[3];
    int tmp;
    int8_t corr = 1 * 10 + 3; // ID[1] * 10 + ID[0]

    cout << "Give 3 8-bit integers:" << endl;

    for (int i = 0; i < 3; i++) {
        cin >> tmp;
        i8arr[i] = (int8_t)tmp;
    }

    if (!(i8arr[0] ^ i8arr[1] ^ i8arr[2] ^ corr))
        return;

    cout << "These are not the droids you are looking for" << endl;
    exit(1);
}

int main() {
    ControlWithStrings();
    AsmZeroBit();
    BitBasedAccess();
    CheckArrayBit();
    cout << "Access granted" << endl;
    return 0;
}
