class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        int MOD = 1e9 + 7;
        if(n){
            for(long long bt = 1LL<<(n-1) ; bt > 0 ; bt = bt>>1){
                if((min(a,b) & bt) == 0){
                    a = a^bt;
                    b = b^bt;
                }
            }
        }
        return ((a%MOD) * (b%MOD)) % MOD;
    }
};