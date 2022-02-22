#pragma once
#include <iostream>
using namespace std;

template<class T>
class Node
{
private:
	T _data;
	Node<T>* left;
	Node<T>* right;
	Node<T>* root;
public:

	void setData(T data);
	Node();
	T getData();
	/*
	i like function chaining
	*/
	Node<T>* setLeftNode(Node<T>* left);
	Node<T>* getLeftNode();

	Node<T>* setRootNode(Node<T>* r);
	Node<T>* getRootNode();


	Node<T>* setRightNode(Node<T>* r);
	Node<T>* getRightNode();

	void infix(Node<T>* r);

};

template<class T>
void Node<T>::setData(T data)
{
	this->_data = data;
}

template<class T>
Node<T>::Node()
{
	this->left = nullptr;
	this->right = nullptr;
	this->root = nullptr;
}

template<class T>
T Node<T>::getData()
{
	return this->_data;
}

template<class T>
Node<T>* Node<T>::setLeftNode(Node<T>* left)
{
	this->left = left;
	return this->left;
}

template<class T>
Node<T>* Node<T>::getLeftNode()
{
	return this->left;
}

template<class T>
inline Node<T>* Node<T>::setRootNode(Node<T>* r)
{
	this->root = r;
	return this->getRootNode();
}

template<class T>
inline Node<T>* Node<T>::getRootNode()
{
	return this->root;
}

/*
this function right here caused a 5 hour delay because i didnt realize i wrote

this->right = right;

thanks to the nightmare inducing characteristic of c++ known as 'pointers', nullptr error was staring me in the face 

*/
template<class T>
inline Node<T>* Node<T>::setRightNode(Node<T>* r)
{
	this->right = r;
	return this->getRightNode();
}

template<class T>
inline Node<T>* Node<T>::getRightNode()
{
	return this->right;
}

template<class T>
inline void Node<T>::infix(Node<T>* r)
{
	if (r != NULL)
	{
		char x = r->getData();
		if (x == '*' || x == '/' || x == '+' || x == '-')
		{
			cout << "(";
		}
		this->infix(r->getLeftNode());
	
		cout << r->getData(); 
		this->infix(r->getRightNode());
		if (x == '*' || x == '/' || x == '+' || x == '-')
		{
			cout << ")";
		}
	}
}
