#include <bitset>
#include <cstdint>
#include <iostream>
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

void BitBasedAccess() {

    unsigned int a, b;

    cout << "Give 2 unsigned integers:" << endl;

    cin >> a;
    cin >> b;

    unsigned short ID1 = 1, ID3 = 6, ID4 = 4, ID5 = 1;

    bitset<32> bits_a(a);
    bitset<32> bits_b(b);

    int lower, higher;

    if (ID5 > ID3) {
        lower = ID3;
        higher = ID5;
    } else {
        lower = ID5;
        higher = ID3;
    }

    int j = 0;

    bitset<10> check(0);
    for (int i = lower; i <= higher; i++) {
        check[j] = bits_b[i];
        j++;
    }

    if (check.any()) {
        cout << "There was some failure" << endl;
        exit(1);
    }
    if (bits_a[0] != 0) {
        cout << "Halt!" << endl;
        exit(1);
    }

    if (bits_a[ID4] != bits_b[ID1]) {
        cout << "Intruder detected" << endl;
        exit(1);
    }

    cout << "Access granted";
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

    if (!(i8arr[0] ^ i8arr[1] ^ i8arr[2] ^ corr)) {
        cout << "Access granted";
        return;
    }

    cout << "These are not the droids you are looking for";
    exit(1);
}

int main() {
    ControlWithStrings();
    BitBasedAccess();
    CheckArrayBit();
    return 0;
}
