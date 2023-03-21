#include"Header.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    Tree tree;
    tree.constructionDictionary();
    cout << endl;

    
    tree.wordsPrefix("6");
    tree.wordsPrefix("hjkhjk");
    tree.wordsPrefix("trter");
    tree.wordsPrefix("");
    tree.wordsPrefix("vbnvb");

    
    string pref = tree.enterPrefix();
    tree.wordsPrefix(pref);

    return 0;
}