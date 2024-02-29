// StandardTemplateLibrary.h
#pragma once

#include "DataStructures.h"


class StandardTemplateLibrary {
public:

    ArrayOps <int> aop;

    SinglyLL <int> sobj;

    SinglyCL <char> cobj;

    DoublyLL <double> dobj;

    DoublyCL <float> fobj;

    Stack <char> csobj;

    Queue <int> qobj;

    BST <int> bstobj;

    Array <float> lobj;
    Array <int> iobj;
    Array <double> adobj;

    ArraySorting <float> bsobj;
    ArraySorting <int>  isobj;
    ArraySorting <double> dsobj;
   

    // You can add more functions or data members as needed.
};
