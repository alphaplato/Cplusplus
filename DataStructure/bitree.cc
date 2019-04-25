#include <iostream>
#include <queue>
#include <stack>

struct TreeNode
{
    TreeNode(int key) : key(key), left(nullptr), right(nullptr) {}
    TreeNode *left;
    TreeNode *right;
    int key;
};

void CreateBST(int a, TreeNode *&t)
{
    if (t)
    {
        if (t->key > a)
        {
            CreateBST(a, t->left);
        }
        else
        {
            CreateBST(a, t->right);
        }
    }
    else
    {
        t = new TreeNode(a);
    }
}

int midTravel(TreeNode *&t)
{
    if (t)
    {
        midTravel(t->left);
        std::cout << t->key << " ";
        midTravel(t->right);
    }
    else
    {
        return 0;
    }
    return 0;
}

int widthTravel(TreeNode *&t)
{
    std::queue<TreeNode *> nodes;
    if (!t)
    {
        return 1;
    }
    if (nodes.empty())
    {
        nodes.push(t);
    }
    while (!nodes.empty())
    {
        TreeNode *p = nodes.front();
        std::cout << p->key << " ";
        if (p->left)
        {
            nodes.push(p->left);
        }
        if (p->right)
        {
            nodes.push(p->right);
        }
        nodes.pop();
    }
    return 0;
}

int preTravel(TreeNode *t)
{
    if (t)
    {
        std::cout << t->key << " ";
        preTravel(t->left);
        preTravel(t->right);
    }
    return 0;
};

int preTravel2(TreeNode *t)
{
    std::stack<TreeNode *> s;
    if (t)
    {
        s.push(t);
    }
    while (!s.empty())
    {
        TreeNode *p = s.top();
        std::cout << p->key << " ";
        s.pop();
        if (p->right)
        {
            s.push(p->right);
        }
        if (p->left)
        {
            s.push(p->left);
        }
    }
    return 0;
}

int listTree(TreeNode *&head)
{
    if (!head)
    {
        return 0;
    }
    if (head->left)
    {
        TreeNode *node = head->left;
        head->left = node->right;
        node->right = head;
        head = node;
        listTree(head);
    }
    else if (head->right)
    {
        listTree(head->right);
    }
    return 0;
}

int findTreeNode(int a, TreeNode *&head, TreeNode *&node)
{
    if (head)
    {
        if (head->key > a)
        {
            findTreeNode(a, head->left, node);
        }
        else if (head->key < a)
        {
            findTreeNode(a, head->right, node);
        }
        else
        {
            node = head;
            return 1;
        }
    }
    return 0;
}

int delTreeNode(TreeNode *t)
{
    if (t->left == NULL && t->right == NULL)
    {
        *t = NULL;
    }
    else if (t->left)
    {
        *t = *(t->left);
    }
    else if (t->right)
    {
        *t = *(t->right);
    }
    return 0;
}

bool isAVL(TreeNode *pRoot, int &height)
{
    if (pRoot == NULL)
    {
        height = 0;
        return true;
    }
    // 判断左子树是否是平衡树
    int heightLeft;
    bool resultLeft = isAVL(pRoot->left, heightLeft);

    // 判断右子树是否是平衡树
    int heightRight;
    bool resultRight = isAVL(pRoot->right, heightRight);
    // 左右子树都为AVL，判断根节点的平衡性
    if (resultLeft && resultRight && abs(heightLeft - heightRight) < 2)
    {
        height = (heightLeft > heightRight) ? (heightLeft + 1) : (heightRight + 1);
        return true;
    }
    return false;
}

int main()
{
    int a[7] = {6, 3, 5, 2, 4, 9, 7};
    TreeNode *head = NULL;
    for (int i = 0; i < 7; i++)
    {
        CreateBST(a[i], head);
    }
    std::cout << "中序遍历：";
    midTravel(head);
    std::cout << std::endl
              << "广度优先遍历";
    widthTravel(head);
    std::cout << std::endl
              << "前序遍历，递归:";
    preTravel(head);
    std::cout << std::endl
              << "前序遍历，非递归:";
    preTravel2(head);
    std::cout << std::endl
              << "将树变成一条直链:";
    listTree(head);
    preTravel(head);
    TreeNode *des;
    std::cout << std::endl
              << "查找" << 7 << ":";
    std::cout << std::endl
              << "是否查找到，1 或 0："
              << findTreeNode(7, head, des) << std::endl;
    std::cout << "删除" << 7 << ":";
    delTreeNode(des);
    std::cout << "mid travel:";
    midTravel(head);
    std::cout << std::endl;
    return 0;
}