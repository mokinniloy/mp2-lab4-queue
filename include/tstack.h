#pragma once
#include "tdataroot.h"
#include <iostream>
using namespace std;

class TStack :public TDataRoot
{
private:
	int top; 
public:
    TStack(int Size = DefMemSize);
    ~TStack() { cout << "Destructor TStack" << endl; };
	void Put(const TData &Val); 
	TData Get();
	virtual TData TopElem(); 

	int IsValid();
    void Print();
};