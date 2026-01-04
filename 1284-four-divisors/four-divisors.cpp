class Solution {
public:
    // Check if a number is prime
    bool primeCheck(int a) {
        if(a < 2) return false;
        for(int i = 2; i*i <= a; i++){
            if(a % i == 0) return false;
        }
        return true;
    }
    
    // Return smallest factor > 1
    int ff(int a){
        for(int i = 2; i*i <= a; i++){
            if(a % i == 0) return i;
        }
        return a; // prime
    }
    
    // Cube
    int cube(int a){
        return a*a*a;
    }
    
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(int i: nums){
            if(i == 1) continue;
            
            int factor = ff(i);
            int other = i / factor;
            
            if(factor == i || factor == other) continue; // skip primes or squares of primes
            
            // Case 1: product of two distinct primes
            if(primeCheck(factor) && primeCheck(other)){
                ans += 1 + factor + other + i;
            }
            // Case 2: cube of a prime
            else if(cube(factor) == i){
                ans += 1 + factor + factor*factor + i;
            }
        }
        return ans;
    }
};