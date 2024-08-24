#include <iostream>
using namespace std;

int factorila(int n){
    if(n==0){
        return 1;
    }
    return n *factorila(n-1);
}

int main(){
    int n  = 5;
    int ans = factorila(n);
    cout << "The answer is: " << ans << endl;
    return 0;


}