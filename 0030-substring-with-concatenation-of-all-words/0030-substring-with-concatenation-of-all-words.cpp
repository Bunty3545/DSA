#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
    public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if(s.empty()|| words.empty()){
            return result;
        }
        int word_len = words[0].length();
        int num_words = words.size();
        int substring_len = word_len * num_words;
        int s_len = s.length();
        if(s_len < substring_len){
            return result;
        }
        unordered_map<string,int>word_count;
        for(const string& word : words){
            word_count[word]++;
        }
        for(int i =0;i<word_len;++i){
            int left = i;
            int right = i;
            unordered_map<string, int>seen_count;
            int count = 0;
            while(right + word_len <= s_len){
                string word = s.substr(right,word_len);
                right += word_len;
                if(word_count.find(word) != word_count.end()){
                    seen_count[word]++;
                    count++;
                    while(seen_count[word]>word_count[word]){
                        string left_word = s.substr(left, word_len);
                        seen_count[left_word]--;
                        count--;
                        left += word_len;
                    }
                    if(count == num_words){
                        result.push_back(left);
                    }
                }else{
                    seen_count.clear();
                    count = 0;
                    left = right;
                }
            }
        }
        return result;
    }
};
