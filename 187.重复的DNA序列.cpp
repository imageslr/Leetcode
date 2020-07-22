class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string, int> res;
        map<string, int> m;
        for (int i = 0; i+10 <= s.length(); i++) { // 不能 i<=s.length()-10，后者无符号数，溢出为大正数
            string ss = s.substr(i, 10);
            if (m[ss]) {
                res[ss] = 1;
            } else {
                m[ss] = 1;
            }
        }
        vector<string> resv;
        for( map<string, int>::iterator it = res.begin(); it != res.end(); ++it ) {
            resv.push_back( it->first );
        }
        return resv;
    }
};
