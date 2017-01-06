#include <iostream>
#include <queue>
using namespace std;
#include "binaryTree.h"

void Tree::setval(int n)
{
    value=n; //sets the value n
    left=NULL;
    right=NULL;
    return;
}

int Tree::getval()
{
    return value;
}

Tree* binaryTree::getroot()
{
    return root;
}

Tree* Tree::getleft()
{
    return left;
}

Tree* Tree::getright()
{
    return right;
}

void Tree::setleft(Tree *tmp)
{
    left=tmp;
}

void Tree::setright(Tree *tmp)
{
    right=tmp;
}

binaryTree::binaryTree()
{
    root=NULL;
}

binaryTree::binaryTree(int val)
{
    //initializes a binary tree with the root as val
    root=new Tree;
    root->setval(val);
}

void binaryTree::insertval(int val) // iserts val in binary tree
{
    Tree *tmp, *current, *tmp1;
    if(!root)  // if no root present
    {
        root=new Tree; //allocates memory
        root->setval(val); //sets value
        return;
    }
    else
    {
        for(current=root; ; )
        {
            if(current->getval()==val) return;
            //returns without doing anything if found
            if(val<current->getval())
            {
                //goes left if value is less than current-value;
                if(!current->getleft())
                {
                    //no more node to the left
                    tmp=new Tree; //allocates memory
                    tmp->setval(val); //sets value to it
                    current->setleft(tmp);
                    //makes the left pointer to tmp
                    return;
                }
                current=current->getleft();
            }
            else //goes right
            {
                if(!current->getright())
                {
                    //no more node to the left
                    tmp=new Tree; //allocates memory
                    tmp->setval(val); //sets value to it
                    current->setright(tmp);
                    //makes the left pointer to tmp
                    return;
                }
                current=current->getright();
            }
        }
    }
}

void binaryTree::printdfs(Tree *current)
{
    //this function works by going to the left most node, then it's parent and then the right node.
    int flag=0; if(!current) {cout<<"There's no root\n"<<endl; return;} //if no value in node
    if(current->getleft()==NULL && current->getright()==NULL) {cout<<current->getval()<<" "; flag=1; return;}
    if(current->getleft()!=NULL) {printdfs(current->getleft()); if(!flag) {cout<<current->getval()<<" "; flag=1;}}
    if(current->getright()!=NULL) {if(!flag) {cout<<current->getval()<<" ";} printdfs(current->getright());}
}

void binaryTree::printbfs(Tree *current)
{

    queue < Tree* > q;
    q.push(current);
    while(!q.empty())
    {
        current=q.front(); q.pop();
        cout<<current->getval();
        if(current->getleft()) q.push(current->getleft());
        if(current->getright()) q.push(current->getright());
        if(!q.empty()) cout<<" ";
    }
    cout<<endl;
}

bool binaryTree::findval(int val)
{
    Tree *current;
    current=root;
    while(1)
    {
        if(current->getval()==val) return true; //if value is present returns true.
        else if(current->getleft()==NULL && current->getright()==NULL) return false;
        //else returns false

        if(val<current->getval())
        {
            //if val is less than current-values we go left
            current=current->getleft();
        }
        else
        {
            //if val is greater than current-values we go right
            current=current->getright();
        }
    }
}

Tree* binaryTree::getnode(int val)
{
    //similar to find function but returns the pointer to node.
    Tree *current;
    current=root;
    while(1)
    {
        if(current->getval()==val) {return current;}
        else if(current->getleft()==NULL && current->getright()==NULL) return false;

        if(val<current->getval())
        {
            current=current->getleft();
        }
        else
        {
            current=current->getright();
        }
    }
}

Tree* binaryTree::getparent(Tree* tmp)
{
    //returns parent of a particular node
    Tree *current;
    current=root;
    if(tmp->getval()==root->getval()) return root;
    //there's no parent of the root
    while(1)
    {
        if(current->getright()==tmp || current->getleft()==tmp) return current;
        else if(tmp->getval()<current->getval()) current=current->getleft();
        else if(tmp->getval()>current->getval()) current=current->getright();
    }
}

void binaryTree::deleteval(int val)
{
    if(!findval(val)) return;
    //checks if the value is present in the binary tree
    int flag;
    Tree *current, *parent, *tmp;

    current=getnode(val); //gets pointer of the node of val
    parent=getparent(current); //gest parent of the node

    if(current==root) flag=0;
    else if(parent->getleft()==current) flag=1;
    else if(parent->getright()==current) flag=2;

    if(current->getleft()==NULL && current->getright()==NULL)
    {
        //its a leaf, so parent's cgorresponding pointer is changed to NULL
        if(flag==1) {parent->setleft(NULL);}
        else if(flag==2) {parent->setright(NULL);}
        delete current;
        if(!flag) root=NULL;
    }
    else if(current->getright())
    {
        //not a leaf and there is node to it's right;
        if(current->getright()->getleft()==NULL)
        {
            //the node to the right has no left nodes
            tmp=current->getright();
            tmp->setleft(current->getleft());
            *current=*tmp;
            //the current node is replaced by the right node
        }
        else
        {
            //we traverse to the left most node of the immediate
            //right node and replace the current node with that node
            Tree *tmpparent;
            for(tmp=current->getright(); tmp->getleft(); tmpparent=tmp, tmp=tmp->getleft());
            tmpparent->setleft(tmp->getright());
            tmp->setleft(current->getleft());
            tmp->setright(current->getright());
            *current=*tmp;
            delete tmp;
        }

    }
    else if(current->getleft())
    {
        //since no right, we replace the current node
        //with the immediate left node.
        *current=*(current->getleft());
    }
}
