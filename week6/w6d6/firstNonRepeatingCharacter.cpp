class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    #define NO_OF_CHARS 256
 
/* Returns an array of size 256 containing count
of characters in the passed char array */
int* getCharCountArray(string str)
{
    int* count = (int*)calloc(sizeof(int), NO_OF_CHARS);
    int i;
    for (i = 0; str[i]; i++)
        count[str[i]]++;
    return count;
}
 
/* The function returns index of first
non-repeating character in a string. If all
characters are repeating then returns -1 */
char nonrepeatingCharacter(string str)
{
    int* count = getCharCountArray(str);
    int index = -1, i;
 
    for (i = 0; str[i]; i++) {
        if (count[str[i]] == 1) {
            index = i;
            break;
        }
    }
 
    // To avoid memory leak
    free(count);
    return str[index];
}
    
};
