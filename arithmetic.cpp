// arithmetic.cpp: определяет точку входа для консольного приложения.
//

	#include "stdafx.h"
#include "TStack.h" 
#include <iostream> 
#include <cstring> 
#include<ctype.h> 
using namespace std; 

const int Max_Size_String = 100; 

int prior(char s); 
double calc(char * str); 
int perform(char, int, int); 
int bracket(char * str); 

 void poland(char * str, char * result)
{
	TStack stack;
	int stri = 0, i = 0;
	while (str[i] != NULL) 
	{
		while ((str[i] <= '9') && (str[i] >= '0'))
		{
			result[stri++] = str[i++];
			if ((str[i] > '9') || (str[i] < '0')) result[stri++] = ' ';
		}
		if ((str[i] == '(') || (str[i] == '*') || (str[i] == '/') || (str[i] == '-') || (str[i] == '+') || (str[i] == '^'))
		{
			if ((stack.IsEmpty()) || (str[i] == '(') || (prior(str[i]) > prior(stack.Peek())))
			{
				stack.Put(str[i]);
			}
			else
			{
				while ((!stack.IsEmpty()) && (prior(str[i]) <= prior(stack.Peek())))
					result[stri++] = stack.Get();
				stack.Put(str[i]);
			}
			i++;
		}
		if (str[i] == ')')
		{
			while (stack.Peek() != '(')
				result[stri++] = stack.Get();
			stack.Get();
			i++;
		}

	}
	while (! stack.IsEmpty())
		result[stri++] = stack.Get();



while (!stack.IsEmpty())
result[stri++] = stack.Get();

} 

 int check (char * str)
{
	int q = 0;
	int i = 0;
	if (bracket(str) != 0)
		return 0;
	while (str[i] != '\0') // проверка на отсутствие лишних символов в строке
	{
		if ((str[i] == '*') || (str[i] == '/') || (str[i] == '-') || (str[i] == '+') ||  (str[i] == '(') || (str[i] == ')'))
			q++;
		i++;
	}
	if (q==0) 
	{
		printf("Wrong simbol\n");
		return 0;
	}
	i = 0;
	while (str[i] != '\0') // проверка на отсутствие лишних символов в строке
	{
		if ((str[i] < 40) || (str[i] > 57) && (str[i] != '^') )
		{
			printf("My mind is overburdened  computer yet grasped the depth of thinking\n");
			return 0;
		}
		i++;
	}
	i = 0;
	while (str[i] != '\0') // проверка на несколько знаков подряд
	{
		if ((str[i] >= 42) && (str[i] <= 47) && (str[i + 1] >= 42) && (str[i + 1] <= 47))
		{
			printf("My mind is overburdened  computer yet grasped the depth of thinking\n");
			return 0;
		}
		i++;
	}
	if ((str[0] > '9') || (str[0] < '0') && (str[0] != '-') && (str[0] != '('))  //проверка на правильность ввода первого символа
	{
		printf("%c\n", str[0]);
		printf("Wrong simbols\n");
		return 0;
	}
	if ((str[strlen(str) - 1] > '9') || (str[strlen(str) - 1] < '0') && (str[strlen(str) - 1] != ')'))  //проверка на правильность ввода последнего символа
	{
		printf("Wrong simbolss\n");
		return 0;
	}
	return 1;
}


int main()
{
double res = 0.0;
char str[Max_Size_String],arm[Max_Size_String] = " ";
cout << "Enter your formula : ";
cin >> str;

if ((bracket(str) == 0)&&(check(str)))
{
poland(str, arm);
cout<<arm<<endl;
res = calc(str);
cout << "Result is: " << res << endl;
}

return 0;
} 

int prior(char s) 
{ 
if (s == '(') 
return 0; 
if (s == ')') 
return 1; 
if ((s == '+')||(s=='-')) 
return 2; 
if ((s == '*') || (s == '/')) 
return 3; 
else 
{ 
return -1; 
} 
} 

double calc(char * str)
{
TStack A;//числа
TStack B;//операции

int result = 0, elem;
int LastOp;

int i = 0;

while (str[i] != '\0')
{
while ((str[i] != '*') && (str[i] != '/') && (str[i] != '-') && (str[i] != '+')&&(str[i]!='(') && (str[i] != ')'))
{
elem = 0;
while (isdigit (str[i]))
elem = elem * 10 + (str[i++] - 48);
cout << elem<<endl;
A.Put(elem);

if (str[i] == '\0')
break;
}
if (str[i] == '\0')
break;

if (str[i] == '(')
{
B.Put(str[i]);
i++;
continue;
}
if (str[i] == ')')
{
if (B.IsEmpty())
{
cout << "Warning";
return 0;
}

LastOp = B.Get();
while (LastOp!='(')
{
int Op2 = A.Get();
int Op1 = A.Get();
int result = perform(LastOp, Op1, Op2);
A.Put(result);

if (B.IsEmpty())
{
cout << "Warning";
return 0;
}
LastOp = B.Get();
}
i++;
continue;
}

if (B.IsEmpty())
B.Put(str[i]);
else
{
LastOp = B.Peek();
if (prior((char)LastOp) < prior(str[i]))
{
B.Put(str[i]);
}
else
{
LastOp = B.Get();
int Op2 = A.Get();
int Op1 = A.Get();
int result = perform(LastOp, Op1, Op2);
A.Put(result);
B.Put(str[i]);
}
}
i++;
}

while (!B.IsEmpty())
{
LastOp = B.Get();
int Op2 = A.Get();
int Op1 = A.Get();
int result = perform(LastOp, Op1, Op2);
A.Put(result);
}

return A.Get();
}

int perform(char str, int Op1, int Op2)
{
int result=0;

if (str == '*')
{
result = Op1*Op2;
}

if (str == '/')

{  if (Op2==0)

cout<<"Divide by 0"<<endl;

else 
result = Op1/Op2;
}
if (str == '+')
{
result = Op1+Op2;
}


if (str == '-')
{
result = Op1-Op2;

}
return result;
}

int bracket(char * str) 
{ 
TStack s; 
int array[Max_Size_String][2]; 
int n = 0;
int j = 0;
int m = 1;
int errors = 0; 
int size = strlen(str); 

for (int i = 0; i < size; i++) 
{ 
if (str[i] == '(') 
{ 
s.Put(m++);
} 
if (str[i] == ')') 
if (!s.IsEmpty()) 
{ 
n++; 
array[j][0] = s.Get();
array[j++][1] = m++;
} 
else 
{ 
n++; 
array[j][0] = 0; 
array[j++][1] = m++; 
++errors; 
} 
} 
while (!s.IsEmpty()) 
{ 
n++; 
array[j][0] = s.Get();
array[j++][1] = 0; 
errors++; 
} 
for (int i = 0; i < n; i++) 
{ 
cout<< array[i][0]; 
cout<<" "<< array[i][1]<<"\n"; 
}
	
return errors; 
}