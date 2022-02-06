#include<iostream>
#include<limits.h>
using namespace std;

//Insertion Sort dla tablicy,dzialamy na lewej częci tablic, na tej uporządkowanej.
// bardzo dobry dla ciagow krotkich i prawie uporzadkowanych.

void InsertionSortTab(int* tab, int n)
{
	tab[0] = INT_MIN;
	for (int i = 2; i < n; i++)
	{
		int v = tab[i];
		int j = i - 1;
		while (tab[j] > v)
		{
			tab[j+1] = tab[j];
			j--;
		}
		tab[j + 1] = v;
	}
}

void TT(int* tab, int n, void (*f)(int& x))
{
	for (int i = 1; i < n; i++)
		f(tab[i]);
}

//Insertion Sort dla List:
class node
{
public:
	int val;
	node* next;
	node(int val) :val(val), next(nullptr) {}
};

void InsertionSortList(node*& head)
{
	node* head2 = nullptr;
	//wyjecie pierwszego elemntu z listy glownej i wlozenie do 2!
	node* p = head;
	head = head->next;
	p->next = nullptr;
	head2 = p;
	while (head)
	{
		p = head;
		head = head->next;
		p->next = nullptr;
		node* p2 = head2;
		while (p2->next && p2->next->val < p->val)
		{
			p2 = p2->next;
		}
		if (p2 == head2)
		{
			if (p2->val >= p->val)
			{
				p->next = head2;
				head2 = p;
			}
			else
			{
				p->next = head2->next;
				head2->next = p;
			}
		}
		else
		{
			p->next = p2->next;
			p2->next = p;
		}
	}
	head = head2;
}


void printList(node* head)
{
	while (head)
	{
		cout << head->val << " -> ";
		head = head->next;
	}
	cout << endl;
}
int main()
{
	int tab1[15];
	srand(1);
	TT(tab1, 15, [](int& x) {x = 1 + rand() % 15; });
	TT(tab1, 15, [](int& x) {cout << x << " "; });
	cout << endl;
	InsertionSortTab(tab1, 15);
	cout << "Posortowana tablica:\n";
	TT(tab1, 15, [](int& x) {cout << x << " "; });
	cout << endl;
	node* head = nullptr;
	for (int i = 0; i < 15; i++)
	{
		node* x = new node(1 + rand() % 20);
		x->next = head;
		head = x;
	}
	printList(head);
	InsertionSortList(head);
	cout << "Posortowana Lista:\n";
	printList(head);
	return EXIT_SUCCESS;
}