// https://leetcode.com/problems/implement-trie-prefix-tree/description/

class Node
{
    public:
    char data;
    Node** children;
    bool wordEndsHere;
    Node(char d,int childrenCount=26)
    {
        data=d;
        wordEndsHere=false;
        // left=NULL;
        // right=NULL;
        children=new Node*[childrenCount];
        for(int i=0;i<childrenCount;i++)
        {
            children[i]=NULL;
        }
    }
};


class Trie {
public:
    Node* root;
    Trie() {
        root=new Node('\0');
    }
    
    void insert(string word) {
        Node* temp=root;
        for(int i=0;i<(int)word.size();i++)
        {
            int indexOfChild=word[i]-'a';
            if(temp->children[indexOfChild]==NULL)
            {
                temp->children[indexOfChild]=new Node(word[i]);
            }
            temp=temp->children[indexOfChild];
        }
        temp->wordEndsHere=true;
    }
    Node* getLastNodeDuringSearch(string &word)
    {
        /*
            returns NULL if word is not present as a prefix
            returns address of last node during search if word is present as prefix
        */
        Node* temp=root;
        for(int i=0;i<(int)word.size();i++)
        {
            int indexOfChild=word[i]-'a';
            if(temp->children[indexOfChild]==NULL)
            {
                return NULL;
            }
            temp=temp->children[indexOfChild];
        }
        return temp;
    }

    bool search(string word) {
        Node* lastNode=getLastNodeDuringSearch(word);
        return lastNode!=NULL && lastNode->wordEndsHere;
    }
    
    bool startsWith(string prefix) {
        Node* lastNode=getLastNodeDuringSearch(prefix);
        return lastNode!=NULL;
    }

    bool doFirst5CharExist()
    {
        // handle case for when string is of len < 5
        Node* lastNode=getLastNodeDuringSearch(prefix.substr(0,5));
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */