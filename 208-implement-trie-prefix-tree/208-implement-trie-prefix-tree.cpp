struct Node{
    Node *links[26];
    bool flag;
    bool containsKey(char c){
        return (links[c-'a']!=NULL);
    }
    void putKey(char c, Node* newNode){
        links[c-'a']=newNode;
    }
    
    Node* getNext(char c){
        return links[c-'a'];
    }
    
    void setEnd(){
        flag=true;
    }
    
    bool isEnd(){
        return flag;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node*cur=root;
        for(int i=0;i<word.length();i++){
            if(!cur->containsKey(word[i])){
                cur->putKey(word[i],new Node());
            }
            cur=cur->getNext(word[i]);
        }
        cur->setEnd();
    }
    
    bool search(string word) {
        Node*cur=root;
        
        for(int i=0;i<word.length();i++){
            if(!cur->containsKey(word[i])){
                return false;
            }
            cur=cur->getNext(word[i]);
        }
        return cur->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node*cur = root;
        for(int i=0;i<prefix.length();i++){
            if(!cur->containsKey(prefix[i])){
                return false;
            }
            cur=cur->getNext(prefix[i]);
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