class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st;
        for (int num: nums) {
            st.push_back(num);
            while (st.size() > 1) {
                int a = st.back(); st.pop_back();
                int b = st.back(); st.pop_back();

                int g = gcd(a, b);
                if (g > 1) {
                    st.push_back(lcm(a, b));
                } 
                else {
                    st.push_back(b);
                    st.push_back(a);
                    break;
                }
            }
        }
        return st;
    }

    /* 69/71 cases passed, timeout
    bool checkForCoprime(vector<int>& nums) {
        for (size_t i = 0; i + 1 < nums.size(); i++) {
            if (gcd(nums[i], nums[i+1]) > 1) return true;
        }
        return false;
    }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        while (checkForCoprime(nums)) {
            stack<int> st;
            for (int i = nums.size()-1; i>=0; i--){
                st.push(nums[i]);
            }
            nums.clear();

            while (!st.empty()) {
                int top = st.top();
                st.pop();

                if (st.empty()) {
                    nums.push_back(top);
                    break;
                }

                int second = st.top();
                st.pop();

                if (gcd(top, second) > 1) {
                    st.push(lcm(top, second));
                }
                else {
                    st.push(second);
                    nums.push_back(top);
                }
            }
        }

        return nums;
    }
    */
};
