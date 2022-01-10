void stockBuySell(int price[], int n) {
    int imin = 0;
    for (int i = 0; i < n; i++) {
        if (price[i] >= price[i - 1] && i!=n-1) continue;
        else if (price[i] < price[i - 1]) {
      //      max += price[i - 1] - price[imin];
            if(imin!=i-1)
            {cout<<"("<<imin<<" "<<i-1<<")"<<" ";
            imin = i;}
            else{
                imin=i;
            }
            
        }
        else if (i == n - 1)
            cout<<"("<<imin<<" "<<i<<")"<<" ";
    }
 
}
