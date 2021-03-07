#include <iostream>
#include <vector>
using namespace std;

struct node
{
    int weight;
    int A; //weight of a maximal independent set in the tree rooted at u
    int B; //weight of a maximal independent set in the grand child tree rooted at u
    vector<node *> Child;
};

class tree
{
    node *T;

public:
    void MIS_subtree(node *u);
    int MIS(node *T);
};

void tree::MIS_subtree(node *u)
{
    if (u->Child.empty())
    {
        u->A = u->weight;
        u->B =0;
    }
    else
    {
        int childWeight = 0, grandChildWeight = 0; //weight of child, grandchild
        vector<node *>::iterator i;

        for (i = u->Child.begin(); i != u->Child.end(); i++)
        {
            MIS_subtree(*i);
            childWeight += (*i)->A;
            grandChildWeight += (*i)->B;
        }
        u->A = childWeight > (u->weight + grandChildWeight) ? childWeight : (u->weight + grandChildWeight);
        u->B = childWeight;
    }
}

int tree::MIS(node *T)
{
    MIS_subtree(T);

    return T->A;
}