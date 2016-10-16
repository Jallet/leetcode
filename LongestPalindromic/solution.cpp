/*
* File Name: solution.cpp
* Author: Liang Jiang
* Mail: jiangliang0811@gmail.com
* Created Time: Sun 16 Oct 2016 09:40:00 AM CST
* Description: 
*/

#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
      char incremented[s.length() * 2 + 2];
      char incremented_char = '#';
      int i = 0;
      incremented[0] = incremented_char;
      for (i = 0; i < (int)(s.length()); ++i) {
        incremented[2 * i + 1] = s[i];
        incremented[2 * (i + 1)] =  incremented_char;
      }
      incremented[s.length() * 2 + 1] = '\0';
      string in_s = string(incremented);
      int length = (int)in_s.length();
      int max_len = 1;
      int longset_palindrome_index = 0;
      for (i = 0; i < length; ++i) {
        int len = longestPalindromeCentered(in_s, i);
        if (len > max_len) {
          longset_palindrome_index = i;
          max_len = len;
        }
      }
      int or_max_len = max_len / 2;
      int or_index = (longset_palindrome_index - (max_len - 3) / 2 - 1) / 2;
      string longest_palindrome = s.substr(or_index, or_max_len);
      return longest_palindrome;
    }
    
private:
    int longestPalindromeCentered(string s, int index) {
      int length = (int)(s.length());
      int distance = index > length - index ? length - 1 - index : index;
      int max_len = 1;
      int i = 0;
      for (i = 1; i <= distance; ++i) {
        if (s[index - i] == s[index + i]) {
          max_len += 2;
        }
        else {
          break;
        }
      }
      return max_len;
    }
};

int main(int argc, char* argv[]) {
  Solution solver = Solution(); 
  string str = "abb";
  string in = solver.longestPalindrome(str);
  cout << "in: " << in << endl;
  return 0;
}
