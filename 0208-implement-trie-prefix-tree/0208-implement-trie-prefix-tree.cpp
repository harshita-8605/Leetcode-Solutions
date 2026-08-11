class TrieNode{
    public:
    char val;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char data){
        val = data;
        for(int i=0; i<26;i++){
            children[i] = nullptr;
        }
        isTerminal = false;
    }
};

class Trie {
public:

    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    void insertword(TrieNode* root, string word){
        // base case
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'a';

        // if present
        if(root->children[index]){
            insertword(root->children[index], word.substr(1));
        }
        else{
            TrieNode* child = new TrieNode(word[0]);
            root->children[index] = child;
            insertword(root->children[index], word.substr(1));
        }
    }
    
    void insert(string word) {
        insertword(root, word);
    }
    
    bool searchword(TrieNode* root, string word){
        if(word.length() == 0){
            return root->isTerminal;
        }
        int index = word[0] - 'a';
        if(root->children[index]){
            return searchword(root->children[index], word.substr(1));
        }
        return false;
    }

    bool search(string word) {
        return searchword(root, word);
    }

    bool startWithUtil(TrieNode* root, string word){
        if(word.length()==0) return true;
        int index = word[0] - 'a';
        if(root->children[index]) return startWithUtil(root->children[index], word.substr(1));
        return false;
    }
    
    bool startsWith(string prefix) {
        return startWithUtil(root, prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */