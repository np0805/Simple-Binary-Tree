//
// Binary Search Tree Class
//

#ifndef LAB9_BINARYSEARCHTREE_H
#define LAB9_BINARYSEARCHTREE_H

#include <iostream>
#include <iomanip>
using namespace std;

template<typename T1, typename T2>
class BinarySearchTree {
private:
    class BinaryNode;

public:
    BinarySearchTree() : root(NULL) {

    }

    // (Deep) Copy constructor
    BinarySearchTree(const BinarySearchTree &src) : root(src.clone(src.root)) {}

    ~BinarySearchTree() {
        makeEmpty();
    };

    bool isEmpty() const {
        return !root;
    }

    bool contains(const T1 &x, const T2 &y) const {
        return contains(x, y, root);
    }

    void printMin() const;

    void printTree() const {
        printTree(root, 0);
    };

    void makeEmpty() {
        makeEmpty(root);
    }

    void insert(const T1 &x, const T2 &y) {
        insert(x, y, root);
    }

private:
    class BinaryNode {
    public:
        T1 x;
        T2 y;
        BinaryNode *left;
        BinaryNode *right;

        BinaryNode() :
                left(NULL), right(NULL) {}

        BinaryNode(const T1 &x, const T2 &y, BinaryNode *lt = NULL, BinaryNode *rt = NULL)
                : x(x), y(y), left(lt), right(rt) {}

    };

    BinaryNode *root;

    void insert(const T1 &x, const T2 &y, BinaryNode *&t);

    bool contains(const T1 &x, const T2 &y, BinaryNode *t) const;

    void makeEmpty(BinaryNode *t);

    void printTree(BinaryNode *t, int depth) const;

    BinaryNode *clone(BinaryNode *t) const {
        return !t ? NULL :
               new BinaryNode(t->x, t->y, clone(t->left), clone(t->right));
    };
};

// Print the BST out, the output is rotated -90 degrees.
template<typename T1, typename T2>
void BinarySearchTree<T1, T2>::printTree(typename BinarySearchTree<T1, T2>::BinaryNode *t, int depth) const {
    if (t == NULL)
        return;
    const int offset = 6;
    printTree(t->right, depth + 1);
    std::cout << std::setw(depth * offset);
    std::cout << "(" << t->x << "," << t->y << ")" << std::endl;
    printTree(t->left, depth + 1);
}

template<typename T1, typename T2>
void BinarySearchTree<T1, T2>::insert(const T1 &x, const T2 &y, BinarySearchTree<T1, T2>::BinaryNode *&t){
	  BinaryNode* curPtr = root;
	  BinaryNode* parent = root;
	  // First find the element
	  // After find function is called
	  // - If item is not found
	  //   (1) curPtr should point at NULL, and
	  //   (2) parent should point at the leave node that the new node should attach to
	  //   (3) return false
	  // - Otherwise
	  //   return true
	 bool found=contains(x,y,t);
	 if(!found){
	    BinaryNode* newPtr = new BinaryNode(x,y);   // Construct node containing item
	    if(t == NULL)  {          // Empty tree
	      t = newPtr;
	    return;}

        int i = -1;
        while (curPtr != NULL)
        {
            if (x < curPtr->x)
            {
                parent = curPtr;
                i = 0;
                curPtr = curPtr->left;
            }
            else if (curPtr->x < x)
            {
                parent = curPtr;
                i = 1;
                curPtr = curPtr->right;
            }
            else if (curPtr->x == x)
            {
                if (y < curPtr->y)
                {
                    parent = curPtr;
                    i = 0;
                    curPtr = curPtr->left;
                }
                else if (curPtr->y < y)
                {
                    parent = curPtr;
                    i = 1;
                    curPtr = curPtr->right;
                }
            }
        }

        if (i == 0)
        {
            parent->left = newPtr;
            return;
        }
        else if (i == 1)
        {
            parent->right = newPtr;
            return;
        }
    }
    else
        return;
}


//  Check if the BST contains the value (x,y).
template<typename T1, typename T2>
bool BinarySearchTree<T1, T2>::contains(const T1 &x, const T2 &y, BinarySearchTree<T1, T2>::BinaryNode *t) const{	  BinaryNode* curPtr = root;
	  bool found = false;
	  // Item is not found and haven't yet reached the bottom of the tree
	  while(!found && curPtr != NULL) {
	    if(x < curPtr->x ) {        // Find in the left subtree
	      t = curPtr;
	      curPtr = curPtr->left;
	    }
	    else if(curPtr->x < x) {   // Find in the right subtree
	      t = curPtr;
	      curPtr = curPtr->right;
	    }
	    else if (curPtr->x == x)
	            {if (y < curPtr->y){
	                    t = curPtr;
	                    curPtr = curPtr->left;
	                }
	                else if (curPtr->y < y){
	                    t = curPtr;
	                    curPtr = curPtr->right;}
	    else
	    	{found = true;}               // Found
	  }
	     // Start from root
}
	  return found;
}


// Make Empty
template<typename T1, typename T2>
void BinarySearchTree<T1, T2>::makeEmpty(BinarySearchTree<T1, T2>::BinaryNode *t){
	if(t) {
	makeEmpty(t->left); // Recursion on the left subtree
	makeEmpty(t->right); // Recursion on the right subtree
	delete t; // Delete current node
	}
}

// Print minimum key
// If the tree is empty, you should print "Empty tree"
template<typename T1, typename T2>
void BinarySearchTree<T1, T2>::printMin() const{
	const BinaryNode* node = root;
	if( node == NULL){
		cout<<"Empty tree"<<endl;
		return;
	}
	while(node->left != NULL){
		node = node->left;
	}
	std::cout << " minimum key= (" << node->x << "," << node->y << ")" << std::endl;
}

#endif //LAB9_BINARYSEARCHTREE_H
