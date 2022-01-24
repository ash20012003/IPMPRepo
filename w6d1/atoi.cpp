int atoi(string str) {
    int result = 0;
    for (int i = 0; i < str.size(); i++) {
        result = result * 10 + (str[i] - '0');
    }
    return result;
}

int myAtoi(char* str)
{
    // Initialize result
    int res = 0;
 
    // Initialize sign as positive
    int sign = 1;
 
    // Initialize index of first digit
    int i = 0;
 
    // If number is negative,
    // then update sign
    if (str[0] == '-') {
        sign = -1;
 
        // Also update index of first digit
        i++;
    }
 
    // Iterate through all digits
    // and update the result
    for (; str[i] != '\0'; i++)
        res = res * 10 + str[i] - '0';
 
    // Return result with sign
    return sign * res;
}
