class Solution {
public:
    set<string> validBusiness {"electronics", "grocery", "pharmacy", "restaurant"};

    bool isValidBusiness(string business) {
        return validBusiness.contains(business);
    }

    bool isValidCode(string code) {
        for (int i = 0; code[i]!='\0'; i++) {
            if (!isalnum(code[i]) && code[i] != '_') return false;
        }
        return true;
    }

    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        priority_queue<pair<string, string>, vector<pair<string, string>>, greater<>> sorted; //<businessLine, code> both fields should be sorted by lexicographical order
        vector<string> ret;

        for (int i = 0; i<code.size(); i++) {
            if (code[i][0] == '\0') continue;
            if (isActive[i] && isValidBusiness(businessLine[i]) && isValidCode(code[i])) sorted.push({businessLine[i], code[i]});
        }

        while (!sorted.empty()) {
            ret.push_back(sorted.top().second);
            sorted.pop();
        }

        return ret;
    }
};
