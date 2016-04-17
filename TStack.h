	#include "stdafx.h"
#ifndef __TSTACK_H__
#define __TSTACK_H__
# define MemSize 30 
class TStack 
{ 
int top;
int *pMem; 
int Size; 
public: 
TStack(const TStack &s); 

TStack();

TStack(int n); 

int IsEmpty(void)const; 

int IsFull(void)const; 

void Put(const int Val); 

int Get(void); 

int Peek(void) const; 

~TStack(void); 
};
#endif