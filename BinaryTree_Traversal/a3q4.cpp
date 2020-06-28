/*
 * Name: Kevin Vo
 * ID: 006316930
 * Professor: Dr. Yan Zhang
 * Assignment: Assignment#3 - Problem 4
 * Purpose: This program will construct the given binary tree as it prints the
 *          binary tree in preorder, inorder, and level-order traversal 
 *          non-recursively with the use for stacks with pre- and in- while
 *          level-order uses a queue.
 * Date: 5/19/19
*/

// a3q4.cpp
#include "funcs.cpp"

/*Purpose: Constructs a binary tree by using the struct BinaryNode w/in func.cpp
 *         This function does so by first creating a new node from BinaryNode,
 *         then links them using pointers left & right to have a binary tree 
 *         structure
 * 
 *Return: This function returns the root node as a  pointer after the binary 
 *        tree is completed
 */          
BinaryNode<char>* create_binary_tree()
{
  	BinaryNode<char>* node_A = new BinaryNode<char>('A');
  	BinaryNode<char>* node_B = new BinaryNode<char>('B');
  	BinaryNode<char>* node_C = new BinaryNode<char>('C');
  	BinaryNode<char>* node_D = new BinaryNode<char>('D');
  	BinaryNode<char>* node_E = new BinaryNode<char>('E');
        BinaryNode<char>* node_F = new BinaryNode<char>('F');
        BinaryNode<char>* node_G = new BinaryNode<char>('G');
        BinaryNode<char>* node_H = new BinaryNode<char>('H');
        BinaryNode<char>* node_I = new BinaryNode<char>('I');
        BinaryNode<char>* node_J = new BinaryNode<char>('J');
        BinaryNode<char>* node_K = new BinaryNode<char>('K');

  	node_A->left = node_B;
        node_A->right = node_C;
        node_B->right = node_D;
        node_D->left = node_G;
        node_G->left = node_I;
        
        node_C->left = node_E;
        node_C->right = node_F;
        node_E->right = node_H;
        node_H->left = node_J;
        node_H->right = node_K;

  	return node_A;
}



int main()
{
    //Declaring setting root for the two trees as pointers
    BinaryNode<char>* root = create_binary_tree();


    // call three traversal functions to print elements for char values
    cout<<"The preorder:\n";
    preorder(root);   //calling function to display elements in preorder
    cout<<endl;

    cout<<"The inorder:\n";
    inorder(root);  //calling function to display elements in inorder
    cout<<endl;

    cout<<"The level order:\n";
    levelorder(root);  //calling function to display elements in postorder
    cout<<endl<<endl;




}
