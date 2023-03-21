#include "Header.h"

using namespace std;

TreeNode::TreeNode()
{
    isEndOfWord = false;
    for (int i = 0; i < SIZE; i++)
    children[i] = nullptr;
}
TreeNode::~TreeNode()
{
    for (int i = 0; i < SIZE; i++)
        if (children[i])
            delete children[i];
}

Tree::Tree()
{
    root = new TreeNode();
}

Tree::~Tree()
{
    if (root)
        delete root;
}

TreeNode* Tree::getNewNode()
{
    struct TreeNode* pNode = new TreeNode;
    
    pNode->isEndOfWord = false;
    
    for (int i = 0; i < SIZE; i++)
        pNode->children[i] = nullptr;

    return pNode;
}

void Tree::insert(TreeNode* root, const string & key)
{
    TreeNode* pNode = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
                
        if (!pNode->children[index])
        {
            pNode->children[index] = getNewNode();
        }
        pNode = pNode->children[index];
    }    
    pNode->isEndOfWord = true;
}

TreeNode* Tree::search(const string &key) {
    
    TreeNode* current = root;
    
    for (size_t i = 0; i < key.size(); i++) 
    {
        int index = key[i] - 'a';
        if (current->children[index] && (index < SIZE && index>=0))
        {
            current = current->children[index];
        }
        else 
        {
            current = nullptr;
            break;
        }
    }
    return current;
}

vector<string> Tree::vectorWords(TreeNode* pNode, string str, vector<string> vec)
{
    
    if (pNode->isEndOfWord && str.size())
    {
        vec.push_back(str);
    }

    for (int i = 0; i < SIZE; i++)
    {
        std::string curr = str;
        if (pNode->children[i]) 
        {
            curr += i + 'a';
            vec = vectorWords(pNode->children[i], curr, vec);
        }
    }
    return vec;
}

void Tree::wordsPrefix(string pref)
{
    vector<string> temp;
    TreeNode* current = search(pref);
    if (current == nullptr || current == root)
    {
        cout << "No words with prefix  " << pref << endl;
        if(pref == "")
        {
            cout << "all words in the trie: " << endl;
            vector<string> vec = vectorWords(root, "", temp);

            for (auto i : vec)
            {
                cout << i << std::endl;
            }
        }
     return;
    }

    vector<string> vec = vectorWords(current, pref, temp);
    if(vec.empty())
    {
        cout << "no words with prefix  " << pref  << endl;
        return;
    }
    else
    {
        cout << "selecting words by any key.  " << endl;
        cout << "enter - completing the selection  " << endl;
        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec[i];
            int input = _getch();
            cout << "\r";
            cout << " ";
            cout << "\r";

            if (input == 13)
            {
                cout << vec[i];
                break;
            }
        }
    }
}

string Tree::enterPrefix()
{
    cout << "enter the prefix: ";
    string str;
    cin >> str;
    
    for (int i = 0; i < str.size(); i++)
        str[i] = tolower(str[i]);

    return str;
}

void Tree::constructionDictionary()
{
    insert(root, "auto");
    insert(root, "autcad");
    insert(root, "automotive");
    insert(root, "autopiter");   
   
}
