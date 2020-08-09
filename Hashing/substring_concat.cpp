#include<bits/stdc++.h>
using namespace std;

vector<int> findSubstring(string A, const vector<string> &B) {
    unordered_map<string, int> words;
    int wordSize = B[0].size();
    int wordsCount = B.size();
    vector<int> ans;
    if(A.size()<wordSize*wordsCount)
    return ans;
    for(auto el:B){
        words[el]++;
    }
    for(int i=0; i<A.size(); i++) {
        unordered_map<string, int> temp_hash_map(words);
        int count = wordsCount;
        int j = i;
        string sub = A.substr(j, wordSize);
        while(temp_hash_map[sub] != 0 && count > 0) {
            count--;temp_hash_map[sub]--;
            j += wordSize;
            sub = A.substr(j, wordSize);
        }
        if(count == 0) {
            ans.push_back(i);
        }
    }
    return ans;
}

vector<int> findSubstring1(string S, const vector<string> &L) {
    int size_word = L[0].size(); 
  
    // Number of words present inside list L. 
    int word_count = L.size(); 
  
    // Total characters present in list L. 
    int size_L = size_word * word_count; 
  
    // Resultant vector which stores indices. 
    vector<int> res; 
  
    // If the total number of characters in list L 
    // is more than length of string S itself. 
    if (size_L > S.size()) 
        return res; 
  
    // Map stores the words present in list L 
    // against it's occurrences inside list L 
    unordered_map<string, int> hash_map; 
  
    for (int i = 0; i < word_count; i++)  
        hash_map[L[i]]++;     
  
    for (int i = 0; i <= S.size() - size_L; i++) { 
        unordered_map<string, int> temp_hash_map(hash_map); 
  
        int j = i,count=word_count; 
  
        // Traverse the substring 
        while (j < i + size_L) { 
  
            // Extract the word 
            string word = S.substr(j, size_word); 
  
  
            // If word not found or if frequency of current word is more than required simply break. 
            if (hash_map.find(word) == hash_map.end()||temp_hash_map[word]==0) 
                break; 
  
            // Else decrement the count of word from hash_map 
            else
               { temp_hash_map[word]--;count--;}  
  
  
            j += size_word; 
        } 
       
        // Store the starting index of that substring when all the words in the list are in substring 
        if (count == 0) 
            res.push_back(i); 
    } 
  
    return res; 
}


int main (){
    //code
    string A = "abbaccaaabcabbbccbabbccabbacabcacbbaabbbbbaaabaccaacbccabcbababbbabccabacbbcabbaacaccccbaabcabaabaaaabcaabcacabaa";
    vector<string> B{"cac", "aaa", "aba", "aab", "abc"};
    vector<int> ans;
    ans = findSubstring(A, B);
    for(auto el: ans) {
        cout<<el<<" ";
    }
    return 0;
}
