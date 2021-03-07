#include <iostream>
#include <list>
#include <vector>
#include <math.h>
using namespace std;

struct Node
{
    int key;
    pair<char, Node> *left = nullptr;
    pair<char, Node> *right = nullptr;
};

class Huffman
{
public:
    Huffman();
    list<pair<char, Node>> nodes;
    pair<char, Node> *make_Huffman();
    void printHuffman(pair<char, Node> *root);
};

pair<char, Node> *Huffman::make_Huffman()
{
    vector<pair<char, Node> *> Current;
    list<pair<char, Node>>::iterator i;
    for (i = nodes.begin(); i != nodes.end(); i++)
        Current.push_back(&(*i));

    while (Current.size() > 1)
    {
        int minkey = 101, nextminkey = 101;
        vector<pair<char, Node> *>::iterator j, Mini, nextMini;

        for (j = Current.begin(); j != Current.end(); j++)
        {
            if ((*(*j)).second.key < minkey)
            {
                nextminkey = minkey;
                minkey = (*(*j)).second.key;
                nextMini = Mini;
                Mini = j;
            }
            else if ((*(*j)).second.key < nextminkey)
            {
                nextminkey = (*(*j)).second.key;
                nextMini = j;
            }
        }
        pair<char, Node> *X = (*Mini);
        pair<char, Node> *Y = (*nextMini);
        Mini > nextMini ? (Current.erase(Mini), Current.erase(nextMini)) : (Current.erase(nextMini), Current.erase(Mini));

        pair<char, Node> *Z = (pair<char, Node> *)malloc(sizeof(pair<char, Node>));
        Z->first = NULL;
        Z->second = {(X->second.key + Y->second.key), X, Y};

        Current.push_back(Z);
    }

    return Current.front();
}

void printHuffman(pair<char, Node> *root, unsigned long long int result = 1, int depth = 0)
{
    if (root->second.left != NULL)
    {
        result = result * 10 + 0;
        depth++;
        printHuffman(root->second.left, result, depth);
        depth--;
        result = result / 10;
    }
    if (root->second.right != NULL)
    {
        result = result * 10 + 1;
        depth++;
        printHuffman(root->second.right, result, depth);
        depth--;
        result = result / 10;
    }
    if (root->second.right == NULL && root->second.left == NULL)
    {
        printf("%c %lld\n", root->first, result%(unsigned long long int)pow(10, depth));
    }
}

Huffman::Huffman()
{
    pair<char, Node> A, B, C, D, E, F;
    A.first = 'A';
    A.second = {45, NULL, NULL};
    B.first = 'B';
    B.second = {13, NULL, NULL};
    C.first = 'C';
    C.second = {12, NULL, NULL};
    D.first = 'D';
    D.second = {16, NULL, NULL};
    E.first = 'E';
    E.second = {9, NULL, NULL};
    F.first = 'F';
    F.second = {5, NULL, NULL};

    nodes.push_back(A);
    nodes.push_back(B);
    nodes.push_back(C);
    nodes.push_back(D);
    nodes.push_back(E);
    nodes.push_back(F);
}

int main()
{
    Huffman H = Huffman();
    printHuffman(H.make_Huffman());

    return 0;
}