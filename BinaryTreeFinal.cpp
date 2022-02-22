// BinaryTreeFinal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ExpressionTree.h"

/*
John Brandt
expression/parse tree implementation 
*/
int main()
{
    ExpressionTree<char> x;
    x.expressionToTree("((2+3)*(1+(5-4)))");

    // correctly converts the tree back into an expression  )
    x.treeToExpression();

    
}

