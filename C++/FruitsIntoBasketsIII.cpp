class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        vector<int> sect_mx;
        int m = baskets.size();
        int a = sqrt(m);

        int cnt=0, mx=0;
        for(int i=0;i<m;i++){
            if(cnt==a){
                sect_mx.push_back(mx);
                mx=baskets[i], cnt=1; 
            }
            else{
                cnt++;
                mx = max(mx, baskets[i]);
            }
        }

        sect_mx.push_back(mx);

        int remain = 0;

        for(int i=0;i<fruits.size();i++){
            
            int k = 0, set = 1;
            for(int j=0;j<m;j+=a){
                if(sect_mx[k] < fruits[i]){
                    k++;
                    continue;
                }

                for(int r=j;r<min(j+a, m);r++){
                    if(baskets[r] >= fruits[i]){
                        set = 0;
                        baskets[r] = 0;
                        break;
                    }
                }

                if(set==0){
                    sect_mx[k] = 0;
                    for(int r=j;r<min(j+a, m);r++){
                        sect_mx[k] = max(baskets[r], sect_mx[k]);
                    }
                    break;
                }
            }

            remain += set;
        }

        return remain;
    }
};
