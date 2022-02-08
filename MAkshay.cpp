/*
It's Propose day, and many couples have decided to propose to each other today. Akshay has started a matchmaking services company and N couples have a booking for the cruise where proposals will take place. Now, the  2N   people involved in the proposals come in a certain order and stand in their respective queues, one for boys and one for girls. Akshay has been given the details about both the queues.

Now, for the event to go as planned, each couple must be together when they board the cruise. In other words, there are two queues, boys and girls, and as per planning, for all 1 <= i <= N, boys[i] must be the same as girls[i].

To make the arrangements as per plan, Akshay will stand in the center of the boys’ queue and in one operation he select an integer 0 <= x <= n/2, and swap x consecutive boys in both directions from center. Now, Akshay needs your help to know what is the minimum number of operations he is required to do. If it is not possible to achieve the correct arrangement print -1.

Note, if N is odd then Akshay can’t swap the (N+1)/2th boy with anyone. Also, if he selects a value x, then he can swap only continuous subsegments on both sides of himself.

For further explanation of the swapping process, read the explanation of the test cases.
*/
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int t=0;
    cin >> t;
    for(int itr = 0; itr < t; itr++){
        int n = 0;
        cin >> n;
        vector<int> boy;
        vector<int> girl;
        for(int i=0;i<n;i++){
            int a;
            cin >> a;
            boy.push_back(a);
        }
        for(int i=0;i<n;i++){
            int a;
            cin >> a;
            girl.push_back(a);
        }
        int pos = n/2;
        int step = 0;
        int x = pos;
        int ops = 0;
        while(x >= 0){
                if(boy[x] == girl[x]) x--;
                else if((boy[x]!=girl[x]) && (boy[x] != girl[n-x-1])) {ops = -1; break;}
                else {step+=1; x--;}
            }
        int flag = 0;
        if(ops!=-1){
            for(int i=0;i<pos;i++){
                if(boy[i] != girl[i] && flag==1) continue;
                else if(boy[i] != girl[i] && flag==0) {ops+=1; flag=1;}
                else if(boy[i] == girl[i] && flag==0) continue;
                else {ops+=1; flag=0;}
            }
        }
        cout << ops << endl;
    }
}
