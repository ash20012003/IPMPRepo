// Check if permutation of a string is a palindrome.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool method1(string s) {
    unordered_map<char, int> m;
    int l = s.size();
    for (int i = 0; i < l; i++) {
        m[s[i]] += 1;
    }
    int c=0;
    for (int i = 0; i < l; i++) {
        if (m[s[i]] % 2 != 0) c += 1;
    }
    if (c > 1) return false;
    else return true;
}

/*
•	If you think more deeply about this problem, you might notice that we don’t actually need to know the counts. We just need to 
    know if the count is even or odd. Think about flipping a light on/off (that is initially off).
•	If the light winds up in the off state, we don’t know how many times we flipped it, but we do know it was an even count.
•	Given this, we can use a single integer (as a bit vector). When we see a letter, we map it to an integer between O and 26 
    (assuming an English alphabet). Then we toggle the bit at that value. At the end of the iteration, we check that at most one 
    bit in the integer is set to 1.
•	We can easily check that no bits in the integer are 1: just compare the integer to 0. There is actually a very elegant way to 
    check that an integer has exactly one bit set to 1.
•	Picture an integer like 00010000. We could of course shift the integer repeatedly to check that there’s only a single 1.
•	Alternatively, if we subtract 1 from the number, we’ll get 00001111. What’s notable about this is that there is no overlap 
    between the numbers (as opposed to say 00101000, which, when we subtract 1 from, we get 00100111.)
•	So, we can check to see that a number has exactly one 1 because if we subtract 1 from it and then AND it with the new number, 
    we should get 0.
o	00010000 – 1 = 00001111
o	00010000 & 00001111 = 0
*/



int main()
{
     cout << method1("mdama");
}
