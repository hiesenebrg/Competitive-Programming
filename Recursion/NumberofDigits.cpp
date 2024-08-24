#include <iostream>
using namespace std;

int NumberofDigits(int n)
{
    if(n== 0){
        return 1;
    }
 
   int quot = n/10;
   return 1 + NumberofDigits(quot);
   
}
int sumofDigits(int n){
    if(n==0 ){
        return 0;
    }
    int quot = n/10;
    int rem = n%10;
        

    return rem  +  sumofDigits(quot);
}
int main()
{
    int n;
    cin >> n;
    int ans = NumberofDigits(n);
    int sum = sumofDigits(n);
    
    cout << "THe no. of digit  is :"<< ans-1 << endl;
    cout << "THe sum of digit is :"<< sum << endl;
    return 0;
}