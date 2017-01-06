#include <iostream>
using namespace std;
#include "binaryTree.h"
#include <conio.h>
int main()
{
    binaryTree A;
    for(int i=0; i<6; i++)
    {
        int n;
        cin>>n;
        A.insertval(n);
    }
    A.deleteval(2); //deletes a value;
    A.printdfs(A.getroot()); //prints in dfs format
    cout<<endl;
    A.printbfs(A.getroot()); //prints tree in bfs format
    cout<<endl;
    getche();

}
