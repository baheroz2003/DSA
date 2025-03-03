#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node *links[26];
    bool flag = 0;
};

class Trie{
private: 
    Node* root;
public:
    Trie(){
        root = new Node();
    }

    void insert(string word){
        Node* node = root;

        for(auto val: word){
            if(!node->links[val -'a']){
                node->links[val -'a'] = new Node();
            }
            node = node->links[val -'a'];
        }
        node->flag = 1;
    }

    bool search(string word){
        Node* node = root;

        for(auto val: word){
            if(!node->links[val -'a']) return 0;
            node = node->links[val -'a'];
        }
        return node->flag;
    }

    bool startsWith(string prefix){
        Node* node = root;

        for(auto val: prefix){
            if(!node->links[val -'a']) return 0;
            node = node->links[val - 'a'];
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */