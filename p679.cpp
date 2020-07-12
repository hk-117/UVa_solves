#include<bits/stdc++.h>
using namespace std;
int mx;
int findLeaf (int at, int th){
    int lft = 2 * at;
    int rgt = lft + 1;
    if ( lft <= mx && rgt <= mx ) {
        if ( th % 2 ) return findLeaf(lft, th / 2 + 1);
        else return findLeaf(rgt, th / 2);
    } 
    else {
        return at;
    }
}
 
int main (){
    int testCases; 
    scanf ("%d", &testCases);
    while ( testCases-- ) {
        int d, i; 
        scanf ("%d %d", &d, &i);
        mx = pow(2, d) - 1;
        printf ("%d\n", findLeaf(1, i));
    }
    int minusOne; scanf ("%d", &minusOne);
    return 0;
}
