#include <iostream>
#include <queue>
#include <stack>

struct TreeNode{
    TreeNode(int key):key(key),left(nullptr),right(nullptr){}
    TreeNode* left;
    TreeNode* right;
    int key;
};

void CreateBST(int a,TreeNode* &t){
    if(t){
        if(t->key > a){
            CreateBST(a,t->left);
        }else{
            CreateBST(a,t->right);
        }
    }else{
        t = new TreeNode(a);
    }
}

int MidTravel(TreeNode* &t){
    if(t){
        MidTravel(t->left);
        std::cout << t->key << " ";
        MidTravel(t->right);
    }else{
        return 0;
    }
    return 0;
}


int WidthTravel(TreeNode* &t){
    std::queue<TreeNode*> nodes;
    if(!t){
        return 1;
    }
    if(nodes.empty()){
        nodes.push(t);
    }
    while(!nodes.empty()){
        TreeNode* p = nodes.front();
        std::cout << p->key << " ";
        if(p->left){
            nodes.push(p->left);
        }
        if(p->right){
            nodes.push(p->right);
        }
        nodes.pop();
    }
    return 0;
}

int PreTravel(TreeNode* t){
    if(t){
        std::cout << t->key << " ";
        PreTravel(t->left);
        PreTravel(t->right);
    }
    return 0;
};

int PreTravel2(TreeNode* t){
    std::stack<TreeNode*> s;
    if(t){
        s.push(t);
        std::cout << t->key << " ";
    }
    TreeNode* p = t;
    while(1){
        if(p->left){
            p = p->left;
            std::cout << p->key << " ";
            s.push(p);
        }else{
            if(p->right){
                s.pop();
                p = p->right;
                std::cout << p->key << " ";
                s.push(p);
            }else{
                s.pop();
                if(s.empty()){
                    break;
                }else{
                    p = (s.top())->right;
                    std::cout << p->key << " ";
                    s.pop();
                }
            }
        }
    }
    return 0;
}


int ListTree(TreeNode* &bitree){
    if(!bitree){
        return 0;
    }
    if(bitree->left){
        TreeNode* node = bitree->left;
        bitree->left = node->right;
        node->right = bitree;
        bitree = node;
        ListTree(bitree);    
    }else if(bitree->right){
        ListTree(bitree->right);
    }
    return 0;
}

int FindTreeNode(int a,TreeNode* &head, TreeNode* &node){
    if(head){
        if(head->key > a){
            FindTreeNode(a, head->left, node);
        }else if(head->key < a){
            FindTreeNode(a, head->right, node);
        }else{
            node = head;
            return 1;
        }
    }
    return 0;
}

int DelTreeNode(TreeNode* t){
    if(t->left == NULL && t->right == NULL){
        *t = NULL;
    }else if(t->left){
        *t = *(t->left);
    }else if(t->right){
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
    int  heightLeft;
    bool resultLeft = isAVL(pRoot->left, heightLeft);
 
    // 判断右子树是否是平衡树
    int heightRight;
    bool resultRight = isAVL(pRoot->right, heightRight);
    // 左右子树都为AVL，判断根节点的平衡性
    if (resultLeft && resultRight &&abs(heightLeft - heightRight) < 2)
    {
        height = (heightLeft > heightRight) ? (heightLeft + 1) : (heightRight + 1);
        return true;
    }
    return false;
}

int main(){
    int a[7] = {6,3,5,2,4,9,7};
    TreeNode* bitree = NULL;
    for(int i=0;i < 7;i++){
        CreateBST(a[i],bitree);
    }
    std::cout << "中序遍历：";
    MidTravel(bitree);
    std::cout << std::endl << "广度优先遍历";
    WidthTravel(bitree);
    std::cout << std::endl << "前序遍历，递归:";
    PreTravel(bitree);
    std::cout << std::endl << "前序遍历，非递归:";
    PreTravel2(bitree);
    std::cout << std::endl << "List:";
    ListTree(bitree);
    PreTravel(bitree);
    TreeNode* des;
    std::cout << std::endl << "查找" << 7 << ":";
    std::cout << std::endl << "是否查找到，1 或 0：" 
        << FindTreeNode(7,bitree,des) << std::endl;
    std::cout << std::endl << "删除" << 7 << ":";
    //DelTreeNode(des);
    //std::cout << "mid travel:";
    MidTravel(bitree);
    std::cout << std::endl;
    return 0;
}