#include<iostream>
#include<vector>
using namespace std;
// All variations of prime no

// prime number between range -> brute
vector<int> prime(int N){
    vector<int>ans;
    for(int n = 2; n <= N; n++){
        bool isPrime = true;
        for(int i = 2; i*i <= n; i++){ // [2 to root n]
            if(n%i == 0){
                isPrime = false;
                break;
            }
        }
        if(isPrime == true){
            ans.push_back(n);
        }

    }
    return ans;
}

// optimized-> 
/* Sieve of Eratosthenes -> count primes b/w range
1. assume all no as prime
2. discard all multiples of current prime
3. repeat until range N
*/
int primeCount(int N){ 
    int count = 0;
    vector<bool>isPrime(N+1, true); //assume all are prime 
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i <= N; i++){
        if(isPrime[i]){
            count++;
            for(int j = i*i; j <= N; j = j+i){
                isPrime[j] = false;
            }
        }
        
    }
    return count;
}

// return as all prime
vector<int> allPrime(int N){ 
    vector<bool>isPrime(N+1, true); //assume all are prime 
    vector<int>ans;
    for(int i = 2; i <= N; i++){
        if(isPrime[i]){
            ans.push_back(i);
            for(int j = i*i; j <= N; j = j+i){
                isPrime[j] = false;
            }
        }
        
    }
    return ans;
}

// prime between L to R - using cumalative sum
int primeLtoR(int L, int R){
    vector<int>prime(R+1, 1);
    prime[0] = prime[1] = 0;
    for(int i = 2; i*i <= R; i++){
        if(prime[i]){
            for(int j = i*i; j <= R; j+=i){
                prime[j] = 0;
            }
        }
    }
    // cumalative sum
    int count = 0, idx = 0; //idx to iterate over prime array
    for(auto val : prime){
        count += val;
        prime[idx++] = count;
    }
    return prime[R]-prime[L-1];
}

// prime between LtoR -> using prime count
int primeLtoR1(int L, int R){
    return primeCount(R) - primeCount(L-1);
}
int main(){
    int N = 10;
    vector<int>v = prime(N);

    for(auto val : v){
        cout<<val<<" ";
    }
    cout<<endl;
    cout<<primeCount(N);
    cout<<primeLtoR(5, 20);
    return 0;
}