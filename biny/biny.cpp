//file : biny.cpp
#include <iostream.h>
#include "biny.h"

class TreeNode {
public:
	TreeNode(long k, void *d);
	TreeNode*& LeftLink(void);
	TreeNode*& RightLink(void);
	long Key(void) const;
	void *Data(void) const;
	void Replace(long key, void *d);
private:
	long		fKey;
	void		*fData;
	TreeNode	*fLeft;
	TreeNode	*fRight;
};

TreeNode::TreeNode(long k,void *d)
{
	fKey = k;
	fData = d;
	fLeft = NULL;
	fRight = NULL;
}

inline long TreeNode::Key(void) const { return fKey; }
inline void *TreeNode::Data(void) const { return fData; }
inline TreeNode*& TreeNode::LeftLink(void) { return fLeft; }
inline TreeNode*& TreeNode::RightLink(void) { return fRight; }
inline void TreeNode::Replace(long key, void *d) { fKey = key; fData = d; }



BinaryTree::BinaryTree()
{
	fRoot = NULL;
	fNum = 0;
}

int BinaryTree::Add(void *nItem, long key)
{
	return AuxAdd(fRoot, nItem, key);
}

int	BinaryTree::AuxAdd(TreeNode*& c, void* nItem, long key)
{
	if(c==NULL) {
		c = new TreeNode(key, nItem);
		fNum++;
		return 1;
	}
	
	int compare = key - c->Key();
	
	if(compare == 0) {
		cout << "Sorry, duplicate keys not allowed" << endl;
		return 0;
	}
	
	if(compare < 0)
		return AuxAdd(c->LeftLink(), nItem, key);
	else
		return AuxAdd(c->RightLink(),nItem, key);
}


void *BinaryTree::Find(long key)
{
	return AuxFind(fRoot, key);
}

void *BinaryTree::AuxFind(TreeNode* c, long key)
{
	if(c == NULL)
		return NULL;

	int compare = key - c->Key();
	
	if(compare == 0)
		return c->Data();

	if(compare < 0)
		return AuxFind(c->LeftLink(), key);
	else
		return AuxFind(c->RightLink(), key);
}


void *BinaryTree::Remove(long key)
{
	return AuxRemove(fRoot, key);
}

void *BinaryTree::AuxRemove(TreeNode*& c, long key)
{
	if(c == NULL)
		return NULL;
		
	int compare = key - c->Key();
	
	if(compare == 0) 
		return Delete(c);

	if(compare < 0)
		return AuxRemove(c->LeftLink(), key);
	else
		return AuxRemove(c->RightLink(), key);
}

void *BinaryTree::Delete(TreeNode*& c)
{
	void *deaddata = c->Data(); fNum--;
	if((c->LeftLink() == NULL) && (c->RightLink() == NULL))
		 { delete c; c = NULL; }
	else
	if(c->LeftLink() == NULL) {
		TreeNode* temp = c;
		c = c->RightLink();
		delete temp;
		}
	else 
	if(c->RightLink() == NULL) {
		TreeNode* temp = c;
		c = c->LeftLink();
		delete temp;
		}
	else {
		TreeNode* temp = Successor(c->RightLink());
		c->Replace(temp->Key(), temp->Data());
		delete temp;
		}
	return deaddata;
	
}

TreeNode *BinaryTree::Successor(TreeNode*& c)
{
	if(c->LeftLink() != NULL)
		return Successor(c->LeftLink());
	else {
		TreeNode *temp = c;
		c = c->RightLink();
		return temp;
	}
}


#ifdef DEBUG
void BinaryTree::PrintOn(ostream& out) const
{
	AuxPrint(fRoot, out, 0);
}

void BinaryTree::AuxPrint(TreeNode* c, ostream& out, int depth) const
{
	if(c == NULL)
		return;
	AuxPrint(c->RightLink(), out, depth + 2);
	
	for(int i=0;i< depth; i++)
		cout << " ";
	cout << c->Key();
	cout << endl;
	
	AuxPrint(c->LeftLink(), out, depth + 2);
	
}
#endif


TreeIterator::TreeIterator(BinaryTree *tree)
{
	fTree = tree;
	fDepth = -1;
}

void TreeIterator::First(void)
{
	fDepth = -1;
	TreeNode *ptr = fTree->Root();
	while(ptr != NULL) {
		fDepth++;
		fStack[fDepth] = ptr;
		ptr = ptr->LeftLink();
		}
}
	
void TreeIterator::Next(void)
{
	if(fDepth < 0) return;
	
	TreeNode *ptr = fStack[fDepth];
	fDepth--;
	ptr = ptr->RightLink();
	while(ptr != NULL) {
		fDepth++;
		fStack[fDepth] = ptr;
		ptr = ptr->LeftLink();
		}
}
	
int	TreeIterator::IsDone(void)
{
	return (fDepth < 0);
}

void	*TreeIterator::CurrentItem(void)
{
	if(fDepth < 0) return NULL;
	else
	 return fStack[fDepth]->Data();
}