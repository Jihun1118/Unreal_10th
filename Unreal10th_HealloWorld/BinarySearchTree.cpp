#include "BinarySearchTree.h"
#include <iostream>
BinarySearchTree::~BinarySearchTree()
{
}

void BinarySearchTree::Insert(int InKey)
{
    Root = InsertNode(Root, InKey);
}

void BinarySearchTree::Delete(int InKey)
{
    Root = DeleteNode(Root, InKey);
}

TreeNode* BinarySearchTree::Search(int InKey)
{
    return SearchNode(Root, InKey);
}

void BinarySearchTree::PrintPreOrder() const
{
    printf("PreOrder : ");
    PreOrderTraversal(Root);
    printf("\n");
}

void BinarySearchTree::PrintInOrder() const
{
    printf("InOrder : ");
    InOrderTraversal(Root);
    printf("\n");
}

void BinarySearchTree::PrintPostOrder() const
{
    printf("PostOrder : ");
    PostOrderTraversal(Root);
    printf("\n");
}

TreeNode* BinarySearchTree::InsertNode(TreeNode* InNode, int InKey)
{
    if (InNode == nullptr)
    {
        return new TreeNode(InKey); //서브 루트가 null이면 그 곳에 새 노드를 만들어서 연결시킨다.
    }

    if (InKey < InNode->Key)
    {
        InNode->Left = InsertNode(InNode->Left, InKey);
    }
    else if (InKey >InNode->Key)
    {
        InNode->Right = InsertNode(InNode->Right, InKey);
    }
    //else
    //{
    //    // 2진 트리에서는 키가 중복되면 안됨.
    //    // 중복된 키는 무시
    //}
    return InNode;
}

TreeNode* BinarySearchTree::DeleteNode(TreeNode* InNode, int InKey)
{
    if (InNode == nullptr)
    {
        return InNode;
    }

    if (InKey < InNode->Key)
    {
        InNode->Left = DeleteNode(InNode->Left, InKey);
    }
    else if (InKey > InNode->Key)
    {
        InNode->Right = DeleteNode(InNode->Right, InKey);
    }
    else      // 삭제할 노드를 찾았을 때
    {
        if (InNode->Left == nullptr)        // 왼쪽 자식이 없을 때 / 자식이 둘 다 없을 때
        {
            TreeNode* Temp = InNode->Right;
            delete InNode;
            return Temp;
        }
        else if (InNode->Right == nullptr)  // 오른쪽 자식이 없을 때
        {
            TreeNode* Temp = InNode->Left;
            delete InNode;
            return Temp;
        }

        // 두 자식이 모두 있는 경우, 오른쪽 서브 트리의 최소 값으로 대체한다
        TreeNode* Temp = FindMinNode(InNode -> Right);
        InNode->Key = Temp->Key;
        InNode->Right = DeleteNode(InNode->Right, Temp->Key);
    }
        return InNode;
}

TreeNode* BinarySearchTree::SearchNode(TreeNode* InNode, int InKey)
{
    if (InNode == nullptr)
    {
        return nullptr;
    }

    if (InKey < InNode->Key)
    {
        return SearchNode(InNode->Left, InKey);
    }
    else if (InKey < InNode->Key)
    {
        return SearchNode(InNode->Right, InKey);
    }
    else
    {
        return InNode;
    }
}

TreeNode* BinarySearchTree::FindMinNode(TreeNode* InNode)
{
    while (InNode != nullptr && InNode->Left != nullptr)
    {
        InNode = InNode->Left;
    }
    return InNode;
}

void BinarySearchTree::PreOrderTraversal(TreeNode* InNode) const
{
    if (InNode != nullptr)
    {
        printf("%d ", InNode->Key);
        PreOrderTraversal(InNode->Left);
        PreOrderTraversal(InNode->Right);
    }
}

void BinarySearchTree::InOrderTraversal(TreeNode* InNode) const
{
    if (InNode != nullptr) 
    {
        InOrderTraversal(InNode->Left);
        printf("%d ", InNode->Key);
        InOrderTraversal(InNode->Right);
    }
}

void BinarySearchTree::PostOrderTraversal(TreeNode* InNode) const
{
    if (InNode != nullptr) 
    {
        PostOrderTraversal(InNode->Left);
        PostOrderTraversal(InNode->Right);
        printf("%d ", InNode->Key);
    }
}

void BinarySearchTree::DestroyTree(TreeNode* InNode)
{
    if (InNode != nullptr)
    {
        DestroyTree(InNode->Left);      // 왼쪽 서브트리를 삭제하고
        DestroyTree(InNode->Right);     // 오른쪽 서브트리를 삭제한 뒤
        delete InNode;                  // 나를 지운다 (후위순회하며 삭제)
    }
}


