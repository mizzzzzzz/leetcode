#include <algorithm>
#include <cassert>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>

using std::string;
using std::queue;
using std::unordered_map;
using std::vector;

class Solution {
public:
    string minWindow(string s, string t)
    {
        // frequency array 
        unordered_map<char, int> dic;
        for (char c : t) dic[c]++;

        //double pointer 
        int i = 0, j = 0;

        // record frequency in window 
        unordered_map<char, int> record;
        // number of finded frequency-satisfied characters 
        int finded = 0;

        // result
        string res = "";

        // find solution of s[0, j]
        while (j < s.size()) {
            if (dic.find(s[j]) != dic.end()) {
                record[s[j]]++;
                // finded the window of feasible solution 
                if (record[s[j]] == dic[s[j]]) {
                    finded++;
                }
            }
            // shrink the feasible solution
            while (i < j) {
                // ignore character out of t 
                if (dic.find(s[i]) == dic.end()) { i++; continue; }
                // ignore redundant character
                if (record.find(s[i]) != record.end() && record[s[i]] > dic[s[i]]) {
                    record[s[i]]--;
                    i++;
                    continue;
                }
                // character in t and cout <= dic[s[j]]
                break;
            }
            // i == j
            //cout << s.substr(i, j-i+1) << " finded = " << finded <<endl;  
            if (finded == dic.size()) {
                //cout << s.substr(i, j - i + 1) << endl;
                if (res == "" || res.size() > j - i + 1) res = s.substr(i, j - i + 1);
            }
            j++;
        }
        return res;
    }
};

int main()
{
    Solution s;
    {
        string ss = "cabwefgewcwaefgcf";
        string tt = "cae";
        string ans = "cwae";
        assert(ans == s.minWindow(ss, tt));
    }
    {
        string ss = "aa";
        string tt = "aa";
        string ans = "aa";
        assert(ans == s.minWindow(ss, tt));
    }
    {
        string ss = "ADOBECODEBANC";
        string tt = "ABC";
        string ans = "BANC";
        assert(ans == s.minWindow(ss, tt));
    }
    {
        string ss = "a";
        string tt = "b";
        string ans = "";
        assert(ans == s.minWindow(ss, tt));
    }
    {
        string ss = "a";
        string tt = "aa";
        string ans = "";
        assert(ans == s.minWindow(ss, tt));
    }
    return 0;
}