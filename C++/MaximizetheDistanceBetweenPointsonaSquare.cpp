class Solution {
public:
    bool isPossible(long long d, int k, vector<long long>& pos, int n, long long p) {
        for (int i = 0; i<n; i++) {
            long long prev = pos[i];
            long long s = pos[i];
            long long count = 1;
            int index = i;
    
            while (count < k) {
                int next = lower_bound(pos.begin() + index+1, pos.begin()+i+n, prev+d) - pos.begin();
                if (next == i+n) break;
                prev = pos[next];
                index = next;
                count++;
            }
            if (count == k && (prev-s <= p-d)) return true;
        }
        return 0;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> pos;
        long long upSide = side;
        for (vector<int> &v: points) {
            int x = v[0];
            int y = v[1];
            if (y==0) pos.push_back(x);
            else if (x==upSide) pos.push_back(upSide + y);
            else if (y==upSide) pos.push_back(2*upSide + (upSide-x));
            else pos.push_back(3*upSide + (upSide-y));
        }

        int n = pos.size();
        sort(pos.begin(),pos.end());

        for (int i = 0; i<n; i++) 
            pos.push_back(pos[i]+4*upSide);

        long long p1 = 1;
        long long p2 = 4*upSide;
        long long ret = 0;
        while (p1<=p2) {
            long long mid = (p1+p2)/2;
            if (isPossible(mid,k,pos,n,4*upSide)) {
                ret = mid;
                p1 = mid+1;
            }
            else p2 = mid-1;
        }

        return ret;
    }
};
