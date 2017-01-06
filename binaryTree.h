#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

class Tree
{
    private:
        int value;
        Tree *left; //pointer to left node
        Tree *right; //pointer to right node
    public:
        Tree* getleft(); //returns pointer to left node
        Tree* getright(); //return pointer to right node
        void setval(int n); //sets the value of the node
        void setleft(Tree *tmp); //assigns node to the left pointer
        void setright(Tree *tmp); //assigns node to the right pointer
        int getval(); //returns value of the node
};


class binaryTree
{
    private:
        Tree *root;

    public:
        binaryTree(); //constructor;
        binaryTree(int val); //constructor
        ~binaryTree(){;}; //destructor

        void insertval(int val); //inserts value in the tree
        void printdfs(Tree *current); //function to print in dfs format
        void printbfs(Tree *current); //function to print in bfs format
        void deleteval(int val); //funtion to delete a value in the binary tree
        bool findval(int val); //function to detect if an element is in the tree
        Tree* getroot(); //returns pointer to root of the tree
        Tree* getnode(int val); //returns pointer to the node of val
        Tree* getparent(Tree* node); //returns parent of the node
};

#endif // BINARYTREE_H_INCLUDED
