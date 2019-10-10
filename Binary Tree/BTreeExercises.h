//
// Operations on Binary Tree
//

#ifndef LAB9_BTREEEXERCISES_H
#define LAB9_BTREEEXERCISES_H

#include <iostream>
#include <queue>
#include "BtreeNode.h"

//template<class T>
//int treeHeight(BtreeNode<T> *root){
//	if (root == nullptr)
//		return 0;
//	else{
//		int l_height = treeHeight(root->get_left());
//		int r_height = treeHeight(root->get_right());
//
//		if (l_height>r_height)
//			return (1+l_height);
//		else return (1+r_height);
//	}
//}
//
//template<class T>
//int countNodes(BtreeNode<T> *root){
//	int count=1;
//
//	if (root == nullptr)
//		return 0;
//
//	if (root->get_left() != nullptr){
//		count += countNodes(root->get_left());
//	}
//	if (root->get_right() != nullptr){
//		count += countNodes(root->get_right());
//	}
//
//	return count;
//}
//
//template<class T>
//BtreeNode<T> *mirror(BtreeNode<T> *root){
////	if (root == nullptr)
////		return 0;
////	else{
////		BtreeNode<T> *tmp;
////
////		mirror(root->get_left());
////		mirror(root->get_right());
////
////		/* swap the pointers in this node */
////		tmp = root->get_left();
////		root->get_left()  = root->get_right();
////		root->get_right() = tmp;
////	}
//	return root;
//}
//
//template<class T>
//bool isComplete(BtreeNode<T> *root){
//	return true;
//}

template<class T>
int treeHeight(BtreeNode<T> *root){
	if (!root) return -1;

	    return 1 + std::max(treeHeight(root->get_left()), treeHeight(root->get_right()));
}

template<class T>
int countNodes(BtreeNode<T> *root){
	if(root == NULL)
	    return 0;
	 if(root->get_left() == NULL && root->get_right()==NULL)
	    return 1;
	  else
	    return 1+countNodes(root->get_left())+
	           countNodes(root->get_right());
}

template<class T>
BtreeNode<T> *mirror(BtreeNode<T> *root){
	if(root == NULL)
		return root;
    // Tree 1
	BtreeNode<int>* temp1 = root->get_left();
	BtreeNode<int>* temp2 = root->get_right();
    BtreeNode<int>* temp = new BtreeNode<int>(root->get_data(),mirror(temp2),mirror(temp1));
	return temp;
	}

template<class T>
bool isComplete(BtreeNode<T> *root){
	return true;
}

#endif //LAB9_BTREEEXERCISES_H


