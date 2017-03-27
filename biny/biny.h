//file : biny.h
#ifndef __MYBINY__
#define __MYBINY__

#define DEBUG

#define kITMAXDEPTH 100

class TreeNode;

class BinaryTree
{
public:
	BinaryTree();
	
	int		NumItems() const;
	
	int		Add(void* nItem, long key);
	void	*Find(long key);
	void	*Remove(long key);
#ifdef DEBUG
	void	PrintOn(ostream& out) const;
#endif
	friend class TreeIterator;
private:
	TreeNode	*Root(void);
	
	int		AuxAdd(TreeNode*& c, void* nItem, long key);
	void	*AuxFind(TreeNode* c, long key);
	void	*AuxRemove(TreeNode*& c, long key);
	
	void	*Delete(TreeNode*&c);
	TreeNode *Successor(TreeNode*& c);
	
#ifdef DEBUG
	void 	AuxPrint(TreeNode* c, ostream& out, int depth) const;
#endif
	TreeNode		*fRoot;
	int			fNum;
};


class TreeIterator {
public:
	TreeIterator(BinaryTree *tree);
	void	First(void);
	void	Next(void);
	int	IsDone(void);
	void	*CurrentItem(void);
private:
	int			fDepth;
	TreeNode	*fStack[kITMAXDEPTH];
	BinaryTree	*fTree;
};

inline int BinaryTree::NumItems(void) const { return fNum; }
inline TreeNode *BinaryTree::Root(void)  { return fRoot; }

#endif