int low(int n) {
    return (n * (n - 1) / 2) + 1;
}

int high(int n) {
    return n*(n + 1) / 2;
}
void waterLevel(int x, int j) {
    int i = 0;
    int n = 0;
    while (i < j) {
        if ((j >= low(i)) && (j <= high(i)))
        {
            n = i;
            break;
        }
        i++;
    }
    double l = (x - (n * (n - 1) / 2))/(double)n;
    if (l > 0)  cout << "Water level is : " <<fixed <<l;
    else  cout << "Water level is : " << 0;
}
