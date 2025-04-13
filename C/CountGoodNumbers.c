int countGoodNumbers(long long n) {
    int mod = 1000000007;
    long long int x = n/2;
    long long int ans = 1;
    long long int val = 20;

    while(x>0){
        if(x%2){
            ans = ((long long)ans*((long long)val%mod))%mod;
        }
        val = (((long long)val)*((long long)val))%mod;
        x>>=1;
    }

    if(n%2!=0){
        ans =(ans*(5))%mod;
    }
    
    return ans;
}
