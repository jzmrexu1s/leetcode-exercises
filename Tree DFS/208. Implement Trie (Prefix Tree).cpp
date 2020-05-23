//
// Created by Chengwei Zhang on 5/23/20.
//

class Trie {
private:
    bool last = false;
    unordered_map<int, Trie*> children;
public:
    /** Initialize your data structure here. */
    Trie() {}

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* p = this;
        for (int i = 0; i < word.size(); i ++) {
            if (p -> children.find(word[i] - 'a') == p -> children.end()) p -> children[word[i] - 'a'] = new Trie();
            p = p -> children[word[i] - 'a'];
        }
        p -> last = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* p = this;
        for (int i = 0; i < word.size(); i ++) {
            if (p -> children.find(word[i] - 'a') == p -> children.end()) return false;
            p = p -> children[word[i] - 'a'];
        }
        return p -> last;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* p = this;
        for (int i = 0; i < prefix.size(); i ++) {
            if (p -> children.find(prefix[i] - 'a') == p -> children.end()) return false;
            p = p -> children[prefix[i] - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */