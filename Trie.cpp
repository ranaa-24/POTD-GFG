void insert(struct TrieNode *root, string key)
{
    TrieNode* c=root;;
    for(int i=0;i<key.size();i++){
        if(!(c->children[key[i]-'a']))
            c->children[key[i]-'a']=getNode();
        c=c->children[key[i]-'a'];
    }
    c->isLeaf=1;
}
bool search(struct TrieNode *root, string key) 
{
    TrieNode* c=root;;
    for(int i=0;i<key.size();i++){
        if(!c->children[key[i]-'a'])
            return 0;
        c=c->children[key[i]-'a'];
    }
    return c->isLeaf;
}
