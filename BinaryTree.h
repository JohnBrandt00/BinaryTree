#pragma once
#include "Node.h"
#include <iostream>
using namespace std;

template <class T>
class BinaryTree
{
private: 
	Node<T>* _rootNode;
	Node<T>* _currentNode;
public: 
	BinaryTree();
	/*
	FUNCTION CHAINING
	*/
	Node<T>* getRootNode();
	Node<T>* setRootNode(Node<T>* n);

	Node<T>* getCurrentNode();
	Node<T>* setCurrentNode(Node<T>* n);

	void insertLeftNode(Node<T>* l);
	void insertRightNode(Node<T>* r);
	

};

/*
every binary tree must start with a single root node
*/

template<class T>
inline BinaryTree<T>::BinaryTree()
{
	Node<T>* roo = new Node<T>;

	this->setRootNode(roo);
	this->setCurrentNode(this->getRootNode());

	// debug, these should be the same 
	cout << "Tree Root and Current" << endl;
	cout << this->getRootNode() << endl;
	cout << this->getCurrentNode() << endl;


}

template<class T>
inline Node<T>* BinaryTree<T>::getRootNode()
{
	return this->_rootNode;
}

template<class T>
inline Node<T>* BinaryTree<T>::setRootNode(Node<T>* n)
{
	this->_rootNode = n;
	return this->getRootNode();
}

template<class T>
inline Node<T>* BinaryTree<T>::getCurrentNode()
{
	return this->_currentNode;
}

template<class T>
inline Node<T>* BinaryTree<T>::setCurrentNode(Node<T>* n)
{
	this->_currentNode = n;
	return this->getCurrentNode();
}


/*
function chaining the left node insert

*/
template<class T>
inline void BinaryTree<T>::insertLeftNode(Node<T>* l)
{


	this->getCurrentNode()->setLeftNode(l)->setRootNode(this->getCurrentNode());
	this->setCurrentNode(this->getCurrentNode()->getLeftNode());
	

}

/*

function chaining right insert

*/

template<class T>
inline void BinaryTree<T>::insertRightNode(Node<T>* r)
{
	

	this->getCurrentNode()->setRightNode(r)->setRootNode(this->getCurrentNode());
	this->setCurrentNode(this->getCurrentNode()->getRightNode());
}
