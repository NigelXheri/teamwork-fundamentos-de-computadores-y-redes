### **ControlWithStrings()**

The function uses strings, which must be declared as arrays of characters of 20 positions. When reading a string, it can be assumed to have fewer than 20 characters. Error checking will not be carried out.

The function follows these steps:

* Read a string from the terminal. Using the function strcmp(), check that the string is *YbTqgvPMZ*. If not, it should print the message "Intruder detected" and call exit().

* Read another string from the terminal. Check with strlen() that the length of the string is at least 12 and that the character at index ID\[2\] is equal to the character at index ID\[0\]. If not, it should print the message "There was some failure" and call exit().

### **BitBasedAccess()**

First, it must request two unsigned 32-bit integer numbers. Next, it has to check:

* That taking the bits between position ID\[5\] and position ID\[3\] (both included) of the second number entered by the user, the resulting bit sequence interpreted as natural binary is equal to 0\. If not, it should print the message "There was some failure" and call exit(). The range will be valid even if both positions match, in which case it will be formed by a single bit and the condition must be evaluated only with that bit.  
* That the bit at position ID\[0\] of the first number is equal to 0\. If not, it should print the message "Halt\!" and call exit().  
* That the bit at position ID\[4\] of the first number is equal to the bit at position ID\[1\] of the second number. If not, it should print the message "Intruder detected" and call exit().

### **AsmZeroBit()**

It should read three 32-bit integer numbers from the terminal and pass them to the function IsValidAssembly(). Next, it should check the result of the call, and if it's 0, it should print the message "Access denied" and call exit().

The IsValidAssembly() function should be implemented in assembly in the file Assembly-code.asm and should return 1 if these two conditions on the numbers read from the terminal are true, and 0 otherwise:

* The bit at position ID\[3\] of the first number is 0\.  
* The value of the ID\[0\] least significant bits of the second number, interpreted as an unsigned binary number, is less than the value of the (ID\[2\] \+ 1\) least significant bits of the third number, interpreted as an unsigned binary number.

### **CheckArrayBit()**

This function declares an array of 3 elements, each of 8 bits. Next, it reads the value of the three elements from the terminal. Then, it checks both that the XOR operation on a bit level is equal to (ID\[1\]\*10 \+ ID\[0\]). If not, it prints the message "These are not the droids you are looking for" and calls exit().

### **main()**

It should call the functions **ControlWithStrings()**, **BitBasedAccess()**, **AsmZeroBit()** and **CheckArrayBit()**. If all these functions execute without calling **exit()**, it should display the message "Access granted".
