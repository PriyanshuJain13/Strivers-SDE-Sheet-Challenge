#include <bits/stdc++.h> 

class Node{
    public:
    Node* link[26];
    int cp = 0;
    int end = 0;

    bool containsKey(char c)
    {
        return (link[c - 'a'] != NULL);
    }

    Node* get(char ch)
    {
        return (link[ch-'a']);
    }

    void put(char c,Node* node)
    {
        link[c-'a'] = node;
    }

    void increaseEnd()
    {
        end++;
    }

    void increaseCp()
    {
        cp++;
    }
    void deleteEnd()
    {
        end--;
    }

    void decreaseCp()
    {
        cp--;
    }
};

class Trie{
    Node* root;
    public:

    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node* node = root;
        for(int i = 0;i < word.size();i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
            node->increaseCp();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word){
        Node* node = root;
        for(int i = 0;i < word.size();i++)
        {
            if(node->containsKey(word[i]))
            {
                node = node->get(word[i]);
            }else{
                return 0;
            }
        }

        return node->end;
    }

    int countWordsStartingWith(string &word){
        Node* node = root;
        for(int i = 0;i < word.size();i++)
        {
            if(node->containsKey(word[i]))
            {
                node = node->get(word[i]);
            }else{
                return 0;
            }
        }

        return node->cp;
    }

    void erase(string &word){
        Node* node = root;
        for(int i = 0;i < word.size();i++)
        {
            if(node->containsKey(word[i]))
            {
                node = node->get(word[i]);
                node->decreaseCp();
            }else{
                return ;
            }
        }

        node->deleteEnd();
    }
};
