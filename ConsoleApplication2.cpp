#include <iostream>
using namespace std;

template < typename T >
class nodo
{
	public:
		T valor;
		nodo<T>* next;

		nodo(T v, nodo<T>* n = nullptr)
		{
			valor = v;
			next = n;
		}

};

template < typename T>
class pila
{
	public:
		nodo<T>* top = NULL;
		void push(T v);
		bool pop(T& v);
};

template < typename T>
void pila<T>::push(T v)
{
	top = new nodo<T>(v, top);
}

template < typename T>
bool pila<T>::pop(T& v) 
{
	bool res = false;
	
	if (top) {

		v = top->valor; 
		nodo<T>* tmp = top; 
		top = top->next; 
		delete tmp;
		res = true;
	}
	return res;
}

int main()
{
	
	pila<int> a;

	a.push(12);
	a.push(12);
	a.push(12);

	int x;

	bool cont = true;

	while (cont)
	{
		cont = a.pop(x);
		if (cont)
		{
			cout << x << endl;
		}
	}

}
