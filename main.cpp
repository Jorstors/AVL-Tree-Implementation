#include "AVLTree.hpp"

int compare(int a, int b)
{
  if (a < b)
    return -1;
  else if (a > b)
    return 1;
  else
    return 0;
}

int main()
{
  try
  {
    AVLTree<int> tree(compare);
    tree.insert(10);
    tree.insert(20);
    tree.insert(30); // RR case
    tree.insert(5);
    tree.insert(1); // LL case
    tree.insert(7); // RL case
    tree.insert(40);
    tree.insert(35);
    tree.insert(37); // LR case
    tree.insert(25);
    tree.insert(38);
    // uncomment to test exceptions (duplicate data)
    // tree.insert(38);

    tree.print();
    std::cout << "Tree elements: " << tree.count() << std::endl;

    tree.remove(40); // left child
    tree.remove(20); // right child
    tree.remove(37); // left and right children
    tree.remove(1);  // no children
    // uncomment to test exceptions (data not found)
    // tree.remove(1000);

    tree.print();
    std::cout << "Tree elements: " << tree.count() << std::endl;

    std::cout << std::endl;
    std::cout << "Search for 30: " << (tree.search(30) == 30 ? "Found" : "Exception") << std::endl;
    std::cout << "Search for 1: " << (tree.search(1) == 1 ? "Found" : "Exception") << std::endl;
  }
  catch (const std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }
  return 0;
}