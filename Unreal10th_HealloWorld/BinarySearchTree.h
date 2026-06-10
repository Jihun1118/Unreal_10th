#pragma once
struct TreeNode
{

	int Key = 0;
	TreeNode* Left = nullptr;
	TreeNode* Right = nullptr;

	TreeNode() = default;
	TreeNode(int InKey) : Key(InKey) {}
};

class BinarySearchTree
{
public:
	BinarySearchTree() = default;
	~BinarySearchTree();

	void Insert(int InKey);
	void Delete(int InKey);
	TreeNode* Search(int InKey);


	void PrintPreOrder() const;
	void PrintInOrder() const;
	void PrintPostOrder() const;

	inline bool IsEmpty() const { return Root == nullptr; }

private:
	TreeNode* Root = nullptr;

	TreeNode* InsertNode(TreeNode* InNode, int InKey);
	TreeNode* DeleteNode(TreeNode* InNode, int InKey);
	TreeNode* SearchNode(TreeNode* InNode, int InKey);
	TreeNode* FindMinNode(TreeNode* InNode);		// InNode를 루트로 하는 서브 트리에서 가장 작은 키를 가지는 노드를 찾는 함수


	void PreOrderTraversal(TreeNode* InNode) const;
	void InOrderTraversal(TreeNode* InNode) const;
	void PostOrderTraversal(TreeNode* InNode) const;

	void DestroyTree(TreeNode* InNode);
};