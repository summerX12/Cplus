#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include <iostream>

using namespace std;

////important
template<typename valType>
class BTnode;

template<typename elemType>
class BinaryTree;
////important


template<typename valType>
class BTnode
{
public:
	BTnode(const valType &val);

	void insert_value(const valType &val);
	void remove_value(const valType &val,BTnode *&prev);
	static void lchild_leaf(BTnode *leaf, BTnode *subtree);
	static void preorder_val(BTnode *pt, ostream &os = cout);

private:
	friend class BinaryTree <valType>;
	valType _val;
	int _cnt;
	//不需要 template parameter list 加以限定
	BTnode *_lchild;
	BTnode *_rchild;
};


template<typename valType>
inline BTnode<valType>::BTnode(const valType &val):_val(val)
{
	_cnt = 1;
	_lchild = _rchild = 0;
}

template<typename valType>
void BTnode<valType>::insert_value(const valType &val)
{
	if (val == _val)
	{
		_cnt++;
		return;
	}

	if (val < _val)
	{
		if (!_lchild)
			_lchild = new BTnode(val);
		else
			_lchild->insert_value(val);
	}
	else
	{
		if (!_rchild)
			_rchild = new BTnode(val);
		else
			_rchild->insert_value(val);
	}

}

template<typename valType>
void BTnode<valType>::lchild_leaf(BTnode *leaf, BTnode *subtree)
{
	while (subtree->_lchild)
		subtree = subtree->_lchild;
	subtree->_lchild = leaf;
}



template<typename valType>
void BTnode<valType>::remove_value(const valType &val, BTnode *&prev)
{
	if (val < _val )
	{
		if (!_lchild)
			return;//not exist
		else
			_lchild->remove_value(val,_lchild);
	}
	else if(val > _val && _rchild)
	{
		if (!_rchild)
			return;
		else
			_rchild->remove_value(val, _rchild);
	}
	else
	{ 
		if (_rchild)//find it
		{
			prev = _rchild;
			if (_lchild)
				BTnode<valType>::lchild_leaf(_lchild, prev);
		}
		else
			prev = _lchild;
		delete this;
	}

}

template<typename valType>
void  BTnode<valType>::preorder_val(BTnode *pt, ostream &os)
{
	if (pt)
	{
		os << pt->_val << " ";
		if (pt->_lchild)
			preorder_val(pt->_lchild, os);
		if (pt->_rchild)
			preorder_val(pt->_rchild, os);
	}
}









template<typename elemType>
class BinaryTree
{
public:
	BinaryTree();
	BinaryTree(const BinaryTree &);
	~BinaryTree();
	BinaryTree& operator=(const BinaryTree &);

	bool empty() { return _root == 0; };
	void clear() { if (_root) { clear(_root); _root = 0; } };

	void insert(const elemType &elem);
	void remove(const elemType &elem);
	void remove_root();
	void preorder(ostream &os=cout) const;
	
private:
	void clear(BTnode<elemType>*);	
	BTnode<elemType> * _root;//以 template parameter list 加以限定
	void copy(BTnode<elemType>*tar, BTnode<elemType>*src);

};



template<typename elemType>
inline BinaryTree<elemType>::BinaryTree() : _root(0)
{}

template<typename elemType>
inline BinaryTree<elemType>::BinaryTree(const BinaryTree& rhs)
{
	copy(_root, rhs._root);
}

template<typename elemType>
inline BinaryTree<elemType>::~BinaryTree()
{
	clear();
}

template<typename elemType>
inline BinaryTree<elemType>& BinaryTree<elemType>::operator=(const BinaryTree &rhs)
{
	if (this != rhs)
	{
		clear();
		copy(_root, rhs._root);
	}
	return *this;
}

template<typename elemType>
void BinaryTree<elemType>::clear(BTnode<elemType>*pt)
{
	if (pt)
	{
		clear(pt->_lchild);
		clear(pt->_rchild);
		delete pt;
	}
}

template<typename elemType>
void BinaryTree<elemType>::insert(const elemType &elem)
{
	if (!_root)
		_root = new BTnode<elemType>(elem);
	else
		_root->insert_value(elem);
}

template<typename elemType>
void BinaryTree<elemType>::remove(const elemType &elem)
{
	BTnode<elemType> *prev=NULL;

	if(_root)
	{ 
		if (elem == _root->_val)
			remove_root();
		else
			_root->remove_value(elem, prev);
	}
}

template<typename elemType>
void  BinaryTree<elemType>::remove_root()
{
	if (!_root)
		return;

	BTnode<elemType> *tmp = _root;
	if (_root->_rchild)
	{
		_root = _root->_rchild;
		if (tmp->_lchild)
		{
			BTnode<elemType>::lchild_leaf(tmp->_lchild, _root);
		}
	}
	else
	{
		_root = _root->_lchild;
	}
	delete tmp;
}

template<typename elemType>
void  BinaryTree<elemType>::preorder(ostream &os) const
{
	BTnode<elemType>::preorder_val(_root,os);
	os << endl;
}


#endif
