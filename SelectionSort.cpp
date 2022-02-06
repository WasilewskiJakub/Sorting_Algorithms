#include<iostream>
using namespace std;

// sortowanie Selection Sort, na tablicy. Zakładamy że pierwszy element nietykalny!
// zlozoność:
// przestawienia: O(n) - najlepszy nie da się mniej!
// porownan: O(n^2).
// nie stabilny!!!! - dla tablic, dla list już stabilny!
void SelectionSortTab(int* tab, int n)
{
	for (int i = 1; i < n; i++)
	{
		int iMin = i;
		for (int j = i + 1; j < n; j++)
		{
			if (tab[iMin] > tab[j])
				iMin = j;
		}
		swap(tab[i], tab[iMin]);
	}
}
void TT(int* tab, int n, void (*f)(int& x))
{
	for (int i = 1; i < n; i++)
		f(tab[i]);
}

// Selection Sort dla List:
//takie same zlozonosci. 
// tworzymy nowa pomocna liste do ktorej zapisujemy dane!

class node
{
public:
	int val;
	node* next;
	node(int val) :val(val), next(nullptr) {}
};
void SelectionSortList(node*& head) // tworzymy nowa lista i dodajemy!
{
	node* head2 = nullptr;
	
	while (head)
	{
		node* p = head, *pp = nullptr, *pMax = head;
		while (p->next)
		{
			if (pMax->val < p->next->val)
			{
				pMax = p->next;
				pp = p;
			}
			p = p->next;
		}
		if (!pp)
		{
			head = head->next;
		}
		else
		{
			pp->next = pMax->next;
		}
		pMax->next = head2;
		head2 = pMax;
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
	srand(12);
	TT(tab1, 15, [](int& x) {x = 1 + rand() % 15; });
	TT(tab1, 15, [](int& x) {cout << x << " "; });
	cout << endl;
	SelectionSortTab(tab1, 15);
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
	SelectionSortList(head);
	cout << "Posortowana Lista:\n";
	printList(head);
	return EXIT_SUCCESS;
}