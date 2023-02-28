//
//  main.cpp
//  hmw2
//
//  Created by Alper Bozkurt on 5.04.2022.
//

#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;
bool start = true;
long getAlgorithm1(long int a, long long int n,long int p){
    long result = a;
    long number = 1;
    
    for(long long int i = 1; i <= n ; i++){
        number = number * result;
        result = number % p;
    }
    return result;

}
long getAlgorithm2(long int a, long long int n, long int p){
    long result = a;
    long number = 1;
    for(long long int i = 1; i <= n; i++){
        number = number * result;
        result = number % p;
        if(result == 1){
            return getAlgorithm1(a, n % i, p);
        }
    }
    return result;
}
long long int getAlgorithm3(long int a, long long int n,long int p){
    long long int result;
    
    if(n == 1){
        return a % p;
    }
    if(n % 2 == 0){
        result = (getAlgorithm3(a, n/2, p) % p);
        return result * result % p;
    }
    else{
        result = (getAlgorithm3(a, (n-1)/2, p) % p);
        return a * result * result % p;
    }
}


int main() {
    //Declare necessary variables
    std::chrono::time_point< std::chrono::system_clock > startTime;
    std::chrono::duration< double, milli > elapsedTime;
    
    //store the starting time
    startTime = std::chrono::system_clock::now();
    
    // code block
    //getAlgorithm1(10005,2000000000,10000);
    //getAlgorithm2(10005,6500000000,100);
    //getAlgorithm3(10005,2000000000,100);
    
    //Compute the number of seconds that passed since the starting time
    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << "Execution took " << elapsedTime.count() << " milliseconds."
    << endl;
}
