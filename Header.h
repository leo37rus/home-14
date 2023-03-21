#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <conio.h>

using namespace std;

const int SIZE = 26;

struct TreeNode
{
    struct TreeNode* children[SIZE];
    bool isEndOfWord;

    TreeNode();
    ~TreeNode();
};

class Tree
{
public:
    Tree();
    ~Tree();    

    TreeNode* getNewNode();
    void insert(TreeNode* root, const string &key);
    TreeNode* search(const string& key);
    void constructionDictionary();
    string enterPrefix();
    vector<string> vectorWords(TreeNode* pNode, string str, vector<string> vec);
    void wordsPrefix(string pref);

private:
    TreeNode* root;
};
