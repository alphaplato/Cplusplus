#include <iostream>
#include <queue>
#include <stack>

struct TreeNode {
    TreeNode(int data):data(data),left(nullptr),right(nullptr){}
    TreeNode* left;
    TreeNode* right;
    int data;
};

void CreateBST(int a,TreeNode* &t) {
    if (t) {
        if (t->data > a) {
            CreateBST(a,t->left);
        } else {
            CreateBST(a,t->right);
        }
    } else {
        t = new TreeNode(a);
    }
}

int WidthTravel(TreeNode* &t) {
    std::queue<TreeNode*> nodes;
    if(!t) {
        return 1;
    }
    if (nodes.empty()) {
        nodes.push(t);
    }
    while(!nodes.empty()) {
        TreeNode* p = nodes.front();
        std::cout << p->data << " ";
        if (p->left) {
            nodes.push(p->left);
        }
        if (p->right) {
            nodes.push(p->right);
        }
        nodes.pop();
    }
    return 0;
}

int PreTravel(TreeNode* t) {
    if (t) {
        std::cout << t->data << " ";
        PreTravel(t->left);
        PreTravel(t->right);
    }
    return 0;
};

int PreTravel2(TreeNode* t) {
    std::stack<TreeNode*> s;
    if(t) {
        s.push(t);
        std::cout << t->data << " ";
    }
    TreeNode* p = t;
    while(1) {
        if (p->left) {
            p = p->left;
            std::cout << p->data << " ";
            s.push(p);
        } else {
            if (p->right) {
                s.pop();
                p = p->right;
                std::cout << p->data << " ";
                s.push(p);
            } else {
                s.pop();
                if (s.empty()) {
                    break;
                } else {
                    p = (s.top())->right;
                    std::cout << p->data << " ";
                    s.pop();
                }
            }
        }
    }
    return 0;
}

int MidTravel(TreeNode* &t){
    if(t) {
        MidTravel(t->left);
        std::cout << t->data << " ";
        MidTravel(t->right);
    } else {
        return 0;
    }
    return 0;
}

int MidTravel2(TreeNode* &t){
    std::stack<TreeNode*> s;
    if (t) {
        s.push(t);
    }
    TreeNode* p = t->left;
    while(!s.empty() || p) {
        if (p) {
            if (p->left) {
                s.push(p);
                p = p->left;
            } else {
                std::cout << p->data << " ";
                p = p->right;
            }
        } else {
            p = s.top();
            std::cout << p->data << " ";
            s.pop();
            p = p->right;
        }
    }
    return 0;
}

int ListTree(TreeNode* &head) {
    if (!head) {
        return 0;
    }
    if (head->left) {
        TreeNode* node = head->left;
        head->left = node->right;
        node->right = head;
        head = node;
        ListTree(head);    
    } else if (head->right) {
        ListTree(head->right);
    }
    return 0;
}

int FindTreeNode(int a,TreeNode* &head, TreeNode* &node) {
    if (head) {
        if(head->data > a) {
            FindTreeNode(a, head->left, node);
        } else if (head->data < a) {
            FindTreeNode(a, head->right, node);
        } else {
            node = head;
            return 1;
        }
    }
    return 0;
}

int DelTreeNode(TreeNode* t) {
    if (t->left == NULL && t->right == NULL) {
        *t = NULL;
    } else if (t->left) {
        *t = *(t->left);
    } else if (t->right) {
        *t = *(t->right);
    }
    return 0;
}


bool isAVL(TreeNode *pRoot, int &height)
{
    if (pRoot == NULL) {
        height = 0;
        return true;
    }
    // 判断左子树是否是平衡树
    int  heightLeft;
    bool resultLeft = isAVL(pRoot->left, heightLeft);
 
    // 判断右子树是否是平衡树
    int heightRight;
    bool resultRight = isAVL(pRoot->right, heightRight);
    // 左右子树都为AVL，判断根节点的平衡性
    if (resultLeft && resultRight &&abs(heightLeft - heightRight) < 2) {
        height = (heightLeft > heightRight) ? (heightLeft + 1) : (heightRight + 1);
        return true;
    }
    return false;
}

int main() {
    int a[7] = {6,3,5,2,4,9,7};
    TreeNode* head = NULL;
    for(int i=0;i < 7;i++) {
        CreateBST(a[i],head);
    }
    std::cout << "广度优先遍历";
    WidthTravel(head);
    std::cout << std::endl << "前序遍历，递归：";
    PreTravel(head);
    std::cout << std::endl << "前序遍历，非递归：";
    PreTravel2(head);
    std::cout << std::endl << "中序遍历，递归：";
    MidTravel(head);
    std::cout << std::endl << "中序遍历，非递归：";
    MidTravel2(head);
    std::cout << std::endl << "将树变成一条直链：";
    ListTree(head);
    PreTravel(head);
    TreeNode* des;
    std::cout << std::endl << "查找" << 7 << "：";
    std::cout << std::endl << "是否查找到，1 或 0：" 
        << FindTreeNode(7,head,des) << std::endl;
    std::cout << "删除" << 7 << "：";
    DelTreeNode(des);
    std::cout << "mid travel：";
    MidTravel(head);
    std::cout << std::endl;
    return 0;
}