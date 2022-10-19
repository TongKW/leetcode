#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct WordCount {
  string word;
  int count;
  WordCount(string word, int count) : word(word), count(count) {}
};

struct CompareWordCount {
  bool operator()(WordCount const &wc1, WordCount const &wc2) {
    if (wc1.count == wc2.count) {
      return lexicographical_compare(wc1.word.begin(), wc1.word.end(),
                                     wc2.word.begin(), wc2.word.end());
    }
    return wc1.count > wc2.count;
  }
};

class Solution {
public:
  vector<string> topKFrequent(vector<string> &words, int k) {
    // Step 1: Create word -> frequency count map
    unordered_map<string, int> freq_map;
    vector<string> unique_words;

    for (string s : words) {
      // If s doesn't exist in freq_map
      if (!freq_map.count(s)) {
        freq_map[s] = 1;
        unique_words.push_back(s);
      } else {
        freq_map[s] += 1;
      }
    }

    // Step 2: for each key in freq_map, consistute a priority queue of size k
    priority_queue<WordCount, vector<WordCount>, CompareWordCount> pq;
    int pq_size = 0;
    for (string word : unique_words) {
      pq.push(WordCount(word, freq_map[word]));
      pq_size += 1;
      if (pq_size > k) {
        pq.pop();
      }
    }

    // Step 3: Pop all elements in priority queue and return ans
    vector<string> ans_words;
    while (!pq.empty()) {
      WordCount wordc = pq.top();
      ans_words.push_back(wordc.word);
      pq.pop();
    }
    reverse(ans_words.begin(), ans_words.end());
    return ans_words;
  }
};
