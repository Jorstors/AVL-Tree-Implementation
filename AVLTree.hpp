#pragma once
#include <iostream>
#include <algorithm>
#include <exception>

template <typename TYPE>
class AVLTree
{
private:
  // Node structure
  struct Node
  {
    TYPE data;
    Node *left;
    Node *right;
    int height;

    Node(TYPE data)
    {
      this->data = data;
      left = nullptr;
      right = nullptr;
      height = 1;
    }
  };

  // Caller defined compare function
  int (*compare)(TYPE, TYPE);
  // Real time element count
  int elementCount = 0;
  // Root node
  Node *root = nullptr;

  // Helper functions for pointer safety
  int getHeight(Node *node) { return node ? node->height : 0; }
  int getBalance(Node *node) { return getHeight(node->left) - getHeight(node->right); }

  Node *rotateRight(Node *y)
  {
    // set x and z
    Node *x = y->left;
    Node *z = x->right;
    // rotate
    x->right = y;
    y->left = z;
    // update heights
    y->height = 1 + std::max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + std::max(getHeight(x->left), getHeight(x->right));

    return x; // return new root
  }

  Node *rotateLeft(Node *y)
  {
    // set x and z
    Node *x = y->right;
    Node *z = x->left;
    // rotate
    x->left = y;
    y->right = z;
    // update heights
    y->height = 1 + std::max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + std::max(getHeight(x->left), getHeight(x->right));

    return x; // return new root
  }

  Node *insertPrivate(Node *node, TYPE data)
  {
    if (!node)
    {
      elementCount++;
      return new Node(data);
    }

    if (compare(data, node->data) < 0) // left (data < node->data)
      node->left = insertPrivate(node->left, data);
    else if (compare(data, node->data) > 0) // right (data > node->data)
      node->right = insertPrivate(node->right, data);
    else
      throw std::runtime_error("Data already exists!");

    // update height
    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

    // get balance factor
    int balance = getBalance(node);

    // if unbalanced, there are 4 cases

    // left left
    if (balance > 1 && getBalance(node->left) > 0)
      return rotateRight(node);
    // right right
    if (balance < -1 && getBalance(node->right) < 0)
      return rotateLeft(node);
    // left right
    if (balance > 1 && getBalance(node->left) < 0)
    {
      node->left = rotateLeft(node->left);
      return rotateRight(node);
    }
    // right left
    if (balance < -1 && getBalance(node->right) > 0)
    {
      node->right = rotateRight(node->right);
      return rotateLeft(node);
    }

    return node;
  }

  Node *searchPrivate(Node *node, TYPE data)
  {
    if (!node)
      throw std::runtime_error("Data not found!");
    if (compare(data, node->data) < 0) // left (data < node->data)
      return searchPrivate(node->left, data);
    else if (compare(data, node->data) > 0) // right (data > node->data)
      return searchPrivate(node->right, data);
    else
      return node;
  }

  Node *removePrivate(Node *node, TYPE data)
  {
    if (!node)
      throw std::runtime_error("Data not found!");
    if (compare(data, node->data) < 0) // left (data < node->data)
      node->left = removePrivate(node->left, data);
    else if (compare(data, node->data) > 0) // right (data > node->data)
      node->right = removePrivate(node->right, data);
    else // data == node->data
    {
      // no child
      if (!node->left && !node->right)
      {
        delete node;
        elementCount--;
        return nullptr;
      }
      // only right child (skip current node)
      else if (!node->left)
      {
        Node *temp = node->right;
        delete node;
        elementCount--;
        return temp;
      }
      // only left child (skip current node)
      else if (!node->right)
      {
        Node *temp = node->left;
        delete node;
        elementCount--;
        return temp;
      }
      // two children (replace current node with min value in right subtree, then remove min value in right subtree)
      else
      {
        Node *temp = node->right;
        while (temp->left)
          temp = temp->left;
        node->data = temp->data;
        node->right = removePrivate(node->right, temp->data);
      }
    }

    // update height
    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

    // get balance factor
    int balance = getBalance(node);

    // if unbalanced, there are 4 cases

    // left left
    if (balance > 1 && getBalance(node->left) >= 0)
      return rotateRight(node);
    // right right
    if (balance < -1 && getBalance(node->right) <= 0)
      return rotateLeft(node);
    // left right
    if (balance > 1 && getBalance(node->left) < 0)
    {
      node->left = rotateLeft(node->left);
      return rotateRight(node);
    }
    // right left
    if (balance < -1 && getBalance(node->right) > 0)
    {
      node->right = rotateRight(node->right);
      return rotateLeft(node);
    }

    return node;
  }

  // Prints the tree in order
  void printPrivate(Node *node)
  {
    if (!node)
      return;
    printPrivate(node->left);
    std::cout << node->data << " ";
    printPrivate(node->right);
  }

public:
  // Constructors
  AVLTree()
  {
    compare = [](TYPE a, TYPE b)
    {
      if (a < b)
        return -1;
      else if (a > b)
        return 1;
      else
        return 0;
    };
  }
  AVLTree(int (*compare)(TYPE a, TYPE b)) { this->compare = compare; }

  // Destructor
  ~AVLTree() {}
  // Public functions
  void insert(TYPE data) { root = insertPrivate(root, data); }
  TYPE search(TYPE data) { return searchPrivate(root, data)->data; }
  void remove(TYPE data) { root = removePrivate(root, data); }
  int count() { return elementCount; }
  void print()
  {
    if (!root)
      return;
    std::cout << std::endl;
    printPrivate(root);
    std::cout << std::endl;
  }
};