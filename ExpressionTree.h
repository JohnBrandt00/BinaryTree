#pragma once
#include "BinaryTree.h"
#include <string>
#include <iostream>
#include "Node.h"
using namespace std;

template<class T>
class ExpressionTree :public BinaryTree<T>
{
private:
  
public:
    
    
    void expressionToTree(string s);
	void treeToExpression();
    void parseChar(char c);
};


template<class T>
void ExpressionTree<T>::expressionToTree(string s)
{
	/*
	remove spaces from the string, they'll just muck up the parsing
	iterative parsing of the expression
	*/
	s.erase(remove(s.begin(), s.end(), ' '), s.end());

	for (int i = 0; i < s.length(); i++)
	{
		
		this->parseChar(s[i]);
		
	}



}

/*
parse the current char into a method
*/
template<class T>
void ExpressionTree<T>::parseChar(char c)
{
	
	if (c == '(')
	{
		

		Node<T>* _node = new Node<T>;
		this->insertLeftNode(_node);
	
		
	}else if(c == '+' || c =='-' || c=='/' || c=='*')
	{
		
		this->getCurrentNode()->setData(c);
		Node<T>* _node = new Node<T>;
		this->insertRightNode(_node);
	}
	else if (isdigit(c))
	{
		
		this->getCurrentNode()->setData(c);
	
		this->setCurrentNode(this->getCurrentNode()->getRootNode());
		
	}
	else if (c == ')')
	{
		
		
		this->setCurrentNode(this->getCurrentNode()->getRootNode());
	}

	
}


/*
tree back to expression
*/

template<class T>
 void ExpressionTree<T>::treeToExpression()
{
	 this->getRootNode()->infix(this->getRootNode());
}