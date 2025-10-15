#include <iostream>
#include <vector>
using namespace std;

struct BiTree {
    char data;
    BiTree *lchild, *rchild;
};

void PreOrder(BiTree* T)
{
    if (T == nullptr)
        return;
    cout << T->data << " ";
    PreOrder(T->lchild);
    PreOrder(T->rchild);
}

int main()
{
    
    return 0;
}
