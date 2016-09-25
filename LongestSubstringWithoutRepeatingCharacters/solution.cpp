/*
* File Name: solution.cpp
* Author: Liang Jiang
* Mail: jiangliang0811@gmail.com
* Created Time: Sun 25 Sep 2016 04:50:20 PM CST
* Description: 
*/

#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
  Solution() {
  }
  int lengthOfLongestSubstring(string s) {
    int length = s.length();
    if (length == 0) {
      return 0;
    }
    int max_len = 1;
    int prev_pos = 0;
    for (int i = 1; i < length; ++i) {
      string sub_str = s.substr(prev_pos, i - prev_pos);
      int pos = sub_str.find_first_of(s[i]);
      if (-1 == pos) {
        continue;
      } else {
        int len = i - prev_pos;
        max_len = max_len > len ? max_len : len;
        prev_pos = pos + 1 + prev_pos;
        
      }
    }
    int len = length - prev_pos;
    max_len = max_len > len ? max_len : len; 
    return max_len;
  }
};

int main() {
  string s = "pwwkew";
  cout << s << endl;
  Solution *solver = new Solution();
  int max_len = solver->lengthOfLongestSubstring(s);
  cout << max_len << endl;
  
  return 0;
}
