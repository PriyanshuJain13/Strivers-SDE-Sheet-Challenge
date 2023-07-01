#include <bits/stdc++.h> 

class Node{
    public:
    Node* links[26];
    bool flag = false;

    bool containsKey(char c)
    {
        return links[c-'a'];
    }
    Node* get(char c)
    {
        return links[c-'a'];
    }
    void put(char c,Node* node)
    {
        links[c-'a'] = node;
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }
};

class Trie
{
    Node* root;
    public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node* node = root;
        for(int i = 0;i < word.size();i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
        }

        node->setEnd();
    }
    bool checkExist(string word)
    {
        Node* node = root;
        bool flag = true;
        for(int i = 0;i < word.size();i++)
        {
            if(node->containsKey(word[i]))
            {
                node = node->get(word[i]);
                if(node->isEnd() == false)
                {
                    return false;
                }
            }else{
                return false;
            }
            
        }

        return true;
    }

};



string completeString(int n, vector<string> &a){
    Trie* t = new Trie();
    for(auto it: a)
    {
        t->insert(it);
    }

    string longest = "";

    for(auto it: a)
    {
        if(t->checkExist(it))
        {
            if(it.length() > longest.length())
            {
                longest =it;
            }else if(it.length() == longest.length() && it < longest){
                longest = it;
            }
        }
    }

    if(longest == "")
    {
        return "None";
    }

    return longest;
}
