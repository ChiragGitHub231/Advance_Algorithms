#include<iostream>
using namespace std;

int gcd(int a, int b){
    while(b > 0){
        int result = a % b;
        a = b;
        b = result;
    }
    return a;
}

int power(long long int x, unsigned int y, long long int n){
    long long int result = 1;
    while(y > 0){
        if((y % 2) == 1){
            result = (result * x) % n;
        }
        y = y/2;
        x = (x * x) % n;
    }
    return result;
}

int isPrime(long long int n){
    int i=1, k=1;
    if((n <= 1) || (n == 4))
        return 0;
    if((n == 2) || (n == 3))
        return 1;
    
    while(i <= k){
        long long int a = 2 + rand() % (n-3);

        if(gcd(a,n) != 1)
            return 0;
        if(power(a,(n-1),n) != 1)
            return 0;
        i++;
    }
    return 1;
}

int main(){
    srand(time(0));
    long long int n = 1000000007;
    
    if(isPrime(n)){
        cout << n << " is prime.";
    }
    else{
        cout << n << " is not prime.";
    }
    return 0;
}