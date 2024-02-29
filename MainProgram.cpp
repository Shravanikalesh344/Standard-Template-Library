// MainProgram.cpp
#include "StandardTemplateLibrary.h"

int main() {
   
    StandardTemplateLibrary mySTL;

    cout<<"-----------------------------------------------------------------------------------------\n";
    cout<<"||Array||"<<"\n";
    cout<<"-----------------------------------------------------------------------------------------\n";

    mySTL.aop.Accept(5);
    mySTL.aop.Display(5);
    mySTL.aop.SearchEle(5);
    mySTL.aop.Summation(5);
     mySTL.aop.Accept(5);
    mySTL.aop.Display(5);
    mySTL.aop.Factor(5);
     mySTL.aop.Accept(5);
    mySTL.aop.Display(5);
    mySTL.aop.Factorial(5);
     mySTL.aop.Accept(5);
    mySTL.aop.Display(5);
    mySTL.aop.Mul(5);
    mySTL.aop.MaxEle(5);
    mySTL.aop.MinEle(5);
    mySTL.aop.Accept(5);
    mySTL.aop.Display(5);
    mySTL.aop.isPrime(5);
    mySTL.aop.Accept(5);
    mySTL.aop.Display(5);
    mySTL.aop.PrimeNo(5);
    mySTL.aop.Accept(5);
    mySTL.aop.Display(5);
    mySTL.aop.PerfectNo(5);
    mySTL.aop.EvenEle(5);
    mySTL.aop.OddEle(5);
    
    



    // Use linked lists, stack, and queue from mySTL
    cout<<"-----------------------------------------------------------------------------------------\n";
    cout<<"||LinkedLists||"<<"\n";
    cout<<"-----------------------------------------------------------------------------------------\n";
    mySTL.sobj.InsertFirst(41);
    mySTL.sobj.InsertLast(21);
    mySTL.sobj.InsertLast(5);
    mySTL.sobj.InsertLast(7);
    mySTL.sobj.InsertLast(88);
    mySTL.sobj.InsertLast(27);
    mySTL.sobj.InsertLast(98);

    mySTL.sobj.Display();

    cout<<"\n";

    mySTL.sobj.EvenEle();

    cout<<"\n";

    mySTL.sobj.OddEle();
    mySTL.sobj.CountEven();
    mySTL.sobj.CountOdd();
    mySTL.sobj.MaxEle();
    mySTL.sobj.MinEle();
    mySTL.sobj.Perfect();



    mySTL.cobj.InsertFirst('L');
    mySTL.cobj.InsertFirst('I');
    mySTL.cobj.InsertFirst('B');

    mySTL.cobj.Display();

    cout<<"\n\n";
    

    mySTL.dobj.InsertFirst(51.54);
    mySTL.dobj.InsertFirst(21.21);
    mySTL.dobj.InsertFirst(11.21);

    mySTL.dobj.Display();

    cout<<"\n\n";

    mySTL.dobj.InsertAtPos(6.21,2);

    mySTL.dobj.Display();

    cout<<"\n\n";

    mySTL.fobj.InsertFirst(51.542121);
    mySTL.fobj.InsertFirst(21.2131);
    mySTL.fobj.InsertFirst(11.216421);

    mySTL.fobj.Display();

    

    cout<<"\n\n";

    cout<<"-----------------------------------------------------------------------------------------\n";
    cout<<"||Stack||"<<"\n\n";
    cout<<"-----------------------------------------------------------------------------------------\n";
    mySTL.csobj.Push('K');
    mySTL.csobj.Push('C');
    mySTL.csobj.Push('A');
    mySTL.csobj.Push('T');
    mySTL.csobj.Push('S');

    mySTL.csobj.Display();

    mySTL.csobj.Pop();
    mySTL.csobj.Display();

    cout<<"\n\n";

    cout<<"-----------------------------------------------------------------------------------------\n";
    cout<<"||Queue||"<<"\n";
    cout<<"-----------------------------------------------------------------------------------------\n";
    mySTL.qobj.Enqueue(121);
    mySTL.qobj.Enqueue(101);
    mySTL.qobj.Enqueue(51);
    mySTL.qobj.Enqueue(21);
    mySTL.qobj.Enqueue(11);

    mySTL.qobj.Display();

    mySTL.qobj.Dequeue();

    mySTL.qobj.Display();

    cout<<"\n\n";

    mySTL.qobj.EvenEle();
    mySTL.qobj.Perfect();
    mySTL.qobj.MaxEle();
    mySTL.qobj.MinEle();
    mySTL.qobj.CountOdd();

    cout<<"\n\n";
    cout<<"-----------------------------------------------------------------------------------------\n";
    cout<<"||Binary Search Tree||"<<"\n\n";
    cout<<"-----------------------------------------------------------------------------------------\n";
    mySTL.bstobj.Insert(78);
    mySTL.bstobj.Insert(10);
    mySTL.bstobj.Insert(45);
    mySTL.bstobj.Insert(5);

    cout<<"Inorder Traversal Of BST"<<"\n";
    mySTL.bstobj.Inorder(mySTL.bstobj.first);

    cout<<"Preorder Traversal OF BST"<<"\n";
    mySTL.bstobj.Preorder(mySTL.bstobj.first);

    cout<<"Postorder Traversal Of BST"<<"\n";
    mySTL.bstobj.Postorder(mySTL.bstobj.first);

    mySTL.bstobj.search();
    cout<<"Even Elements Are :"<<"\n";
    mySTL.bstobj.SearchEven(mySTL.bstobj.first);
    mySTL.bstobj.LeafNode(mySTL.bstobj.first);
    mySTL.bstobj.ParentNode(mySTL.bstobj.first);
    cout<<"Odd Elements Are :"<<"\n";
    mySTL.bstobj.SearchOdd(mySTL.bstobj.first);

    cout<<"\n";
    cout<<"-----------------------------------------------------------------------------------------\n";
    cout<<"||Searching||"<<"\n";
    cout<<"-----------------------------------------------------------------------------------------\n";

    cout<<"Enter Values For Linear Search"<<"\n";
    mySTL.lobj.Accept(5);
    mySTL.lobj.Display(5);
    mySTL.lobj.LinearSearch(5);
 
    cout<<"Enter Values For Binary Search"<<"\n";
    cout<<"Please Enter the values in sorted format"<<"\n";
    mySTL.iobj.Accept(5);
    mySTL.iobj.Display(5);
    mySTL.iobj.BinarySearch(5);

    cout<<"Enter Values For Bidirectional Search"<<"\n";
    mySTL.adobj.Accept(5);
    mySTL.adobj.Display(5);
    mySTL.adobj.BiDirectionalSearch(5);

    cout<<"-----------------------------------------------------------------------------------------\n";
    cout<<"||Sorting||"<<"\n";
    cout<<"-----------------------------------------------------------------------------------------\n";

    cout<<"Enter Values For Bubble Sort"<<"\n";
    mySTL.bsobj.Accept(5);
    mySTL.bsobj.Display(5);
    mySTL.bsobj.BubbleSort(5);

    cout<<"Enter Values For Selection Sort"<<"\n";
    mySTL.isobj.Accept(5);
    mySTL.isobj.Display(5);
    mySTL.isobj.SelectionSort(5);

    cout<<"Enter Values For Insertion Sort"<<"\n";
    mySTL.dsobj.Accept(5);
    mySTL.dsobj.Display(5);
    mySTL.dsobj.InsertionSort(5);

    cout<<"-----------------------------------------------------------------------------------------\n";
    cout<<"||Thank You For Using STL||"<<"\n";
    cout<<"-----------------------------------------------------------------------------------------\n";
 
    return 0;
}
