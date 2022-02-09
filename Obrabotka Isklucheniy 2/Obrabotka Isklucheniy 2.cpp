#include<iostream>
using namespace std;

//void Some()
//{
//	int a;
//	int b;
//	try
//	{
//		cout << "Put digit a:\n";
//		cin >> a;
//		cout << "Put digit b:\n";
//		cin >> b;
//		if (b == 0)
//		{
//			throw "\tZero!!!!\n";
//		}
//	}
//	catch (const char* s)
//	{
//		cout << "\n Error!!!" << s << "\n\n";
//	}
//}
//void Test(int t)
//{
//	cout << "\nDeadInside!!!";
//	if (t == 2)
//	{
//		throw"\n Error-t is 2!!!\n";
//	}
//	else if(t==3)
//		throw"\n Error - t is 3!!!\n";
//}
//void Test()
//{
//	try 
//	{
//		throw"\nHello!!\n";
//	}
//	catch (const char* s)
//	{
//		cout << "\n\nException!!\n\n";
//		throw;
//	}
//}


	template<class T>
	struct Node
	{
		T data;
		Node* next = 0;
		Node* prev = 0;
	};

	template<class T>
	class List
	{
		Node<T>* Head;
		Node<T>* Tail;
		int Count;

	public:
		
			List(const List & L)
			{
				Head = Tail = NULL;
				Count = 0;
				Node<T>* temp = L.Head;
				while (temp != 0)
				{
					AddTail(temp->data);
					temp = temp->next;
				}
			}
			void AddHead(T n)
			{
				Node<T>* temp = new Node<T>;
				temp->prev = 0;
				temp->data = n;
				temp->next = Head;
				if (Head != 0)
				{
					Head->prev = temp;
				}
				if (Count == 0)
				{
					Head = Tail = temp;
				}
				else
				{
					Head = temp;
				}
				Count++;
			}
			void AddTail(T n)
			{
				Node<T>* temp = new Node<T>;
				temp->prev = 0;
				temp->data = n;
				temp->prev = Tail;
				if (Tail != 0)
				{
					Tail->next = temp;
				}
				if (Count == 0)
				{
					Head = Tail = temp;
				}
				else
				{
					Tail = temp;
				}
				Count++;
			}
			void DeleteHead()
			{
				Node<T>* temp = new Node<T>;
				temp = Head;
				Head = Head->next;
				delete temp;
				Count--;
			}
			void DeleteTail()
			{
				Node<T>* temp = new Node<T>;
				temp = Tail;
				Tail = Tail->prev;
				delete temp;
				Count--;
			}
		try
		{
			//void Insert(int pos=0);
			void Insert(int pos = 0)
			{
				if (pos == 0)
				{
					cout << "Введите позицию: ";
					cin >> pos;
				}
				if (pos < 1 || pos>Count + 1)
				{
					throw "Некорректный ввод позиции!";
				}
				if (pos == Count + 1)
				{
					T data;
					cout << "Введите значение: ";
					cin >> data;
					AddTail(data);
					return;
				}
				else if (pos == 1)
				{
					T data;
					cout << "Введите значение";
					cin >> data;
					AddHead(data);
					return;
				}
				int i = 1;
				Node<T>* Ins = Head;
				while (i < pos)
				{
					Ins = Ins->next;
					i++;
				}
				Node<T>* PrevIns = Ins->prev;
				Node<T>* temp = new Node<T>;
				cout << "Введите данные";
				cin >> temp->data;
				if (PrevIns != 0 && Count != 1)
				{
					PrevIns->next = temp;
				}
				temp->next = Ins;
				temp->prev = PrevIns;
				Ins->prev = temp;

				Count++;
			}
			void Print(int pos)
			{
				if (pos<1 || pos>Count)
				{
					throw "Некорректный ввод позиции!";
				}
				if (pos<1 || pos>Count)
				{
					cout << "Incorrect position!!!!\n";
					return;
				}
				Node<T>* temp;
				if (pos <= Count / 2)
				{
					temp = Head;
					int i = 1;
					while (i < pos)
					{
						temp = temp->next;
						i++;
					}
				}
				else
				{
					temp = Tail;
					int i = 1;
					while (i <= Count - pos)
					{
						temp = temp->prev;
						i++;
					}
				}
				cout << pos << "element";
				cout << temp->data << endl;

			}
			Node<T>* GetElement(int pos)
			{
				Node<T>* temp = Head;
				if (pos<1 || pos>Count)
				{
					throw "Некорректный ввод позиции!";
				}
				int i = 1;
				while (i < pos && temp != 0)
				{
					temp = temp->next;
					i++;
				}
				if (temp == 0)
				{
					return 0;
				}
				else
				{
					return temp;
				}
			}
			List operator +(const List & L)
			{
				List Result(*this);
				Node<T>* temp = L.Head;
				while (temp != 0)
				{
					Result.AddTail(temp->data);
					temp = temp->next;
				}
				return Result;
			}
			List operator =(const List & L)
			{
				if (this == &L)
				{
					return *this;
				}
				this->~List();
				Node<T>* temp = L.Head;
				while (temp != 0)
				{
					AddTail(temp->data);
					temp = temp->next;
				}
				return *this;
			}
			bool operator ==(const List & L)
			{
				if (Count != L.Count)
				{
					return false;
				}
				Node<T>* t1;
				Node<T>* t2;
				t1 = Head;
				t2 = L.Head;
				while (t1 != 0)
				{
					if (t1->data != t2->data)
					{
						return false;
					}
					t1 = t1->next;
					t2 = t2->next;
				}
				return true;
			}
			bool operator !=(const List & L)
			{

				return !(*this == L);
			}
			bool operator >=(const List & L)
			{
				if (Count > L.Count)
					return true;
				if (*this == L)
				{
					return true;
				}
				return false;
			}
			bool operator <=(const List & L)
			{
				if (Count < L.Count)
					return true;
				if (*this == L)
				{
					return true;
				}
				return false;
			}
			bool operator >(const List & L)
			{
				if (Count > L.Count)
					return true;
				return false;
			}
			bool operator <(const List & L)
			{
				if (Count < L.Count)
					return true;
				return false;
			}
			List operator -()
			{
				List Result;
				Node<T>* temp = Head;
				int b = Count;
				while (b != 0)
				{
					Result.AddHead(temp->data);
					temp = temp->next;
					b--;
				}
				return Result;
			}

			List()
			{
				Head = Tail = NULL;
				Count = 0;
			}
			~List()
			{
				DelAll();
			}
			int GetCount()
			{
				return Count;
			}
			void Add(T data)
			{
				Node<T>* temp = new Node<T>;
				temp->data = data;
				temp->next = NULL;
				if (Head != NULL)
				{
					Tail->next = temp;
					Tail = temp;
				}
				else
				{
					Head = Tail = temp;
				}
			}

			//void Del(int pos = 0);

			void Del(int pos = 0)
			{
				if (pos == 0)
				{
					cout << "Введите позицию ";
					cin >> pos;
				}
				if (pos <1 || pos>Count)
				{
					throw "Некорректный ввод позиции!";
				}
				int i = 1;
				Node<T>* Del = Head;
				if (Del == NULL)
				{
					throw "Пустой список";
				}
				while (i < pos)
				{
					Del = Del->next;
					i++;
				}
				Node<T>* PrevDel = Del->prev;
				Node<T>* AfterDel = Del->next;
				if (PrevDel != 0 && Count != 1)
				{
					PrevDel->next = AfterDel;
				}
				if (AfterDel != 0 && Count != 1)
				{
					AfterDel->prev = PrevDel;
				}
				if (pos == 1)
				{
					Head = AfterDel;
				}
				if (pos == Count)
				{
					Tail = PrevDel;
				}
				delete Del;
				Count--;

			}
			void DelAll()
			{
				while (Count != 0)
				{
					Del(1);
				}
			}
			void Print()
			{
				Node<T>* temp = Head;
				cout << "(";
				int t = Count;
				while (temp->next != 0 && t > 1)
				{
					cout << temp->data << " ";
					temp = temp->next;
					t--;
				}
				cout << temp->data << ")" << endl;
			}
			int Find(T dt)
			{
				Node<T>* temp = Head;
				int j = 1;
				while (j < Count)
				{
					if (temp->data == dt)
					{
						cout << "Ваш элемент: ";
						cout << temp->data;
						cout << " находиться на позиции: ";/*<< j << endl;*/
						return j;
					}
					temp = temp->next;
					j++;
				}
				return NULL;
			}
			int InsertFind(T dt, int zm)
			{
				Node<T>* temp = Head;
				int j = 1;
				int i = 0;
				bool t = false;
				while (j < Count)
				{
					if (temp->data == dt)
					{
						t = true;
						temp->data = zm;
						i++;
					}
					temp = temp->next;
					j++;
				}
				if (t == false)
				{
					return -1;
				}
				else
				{
					return i;
				}
			}
			
		}
		catch (const char* s)
		{
			cout << "Ошибка " << s << endl;
		}
		catch (...)
		{
			cout << "Ошибка " << endl;
		}
	};


void main()
{
	/*cout << "\nFirst!!!\n";
	Some();
	cout << "\nSecond!!!\n";*/

	/*try
	{
		Test(4);
		Test(2);
	}
	catch (const char* s)
	{
		cout << "\n\n" << s << "\n\n";
	}*/

	/*cout << "\nStart\n";
	try {
		Test();
	}
	catch (const char* p)
	{
		cout << p;
	}*/
	setlocale(0, "rus");

	List<int> L;
	const int n = 10;
	/*double*/int a[n] = { 0,3,2,3,4,5,6,7,8,9 };
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			L.AddHead(a[i]);
		}
		else
		{
			L.AddTail(a[i]);
		}
	}
	cout << "List L:\n";
	L.Print();
	L.Print(6);
	L.Print(8);
	List<int> T;
	T = L;
	cout << "List T:\n";
	T.Print();
	cout << "List Sum:\n";
	List<int> Sum = -L + T;
	Sum.Print();
	T.DeleteTail();
	T.DeleteHead();
	T.Print();
	cout << "Poisk:\n";
	cout << T.Find(6) << endl;
	cout << "Poisk i zamena:\n";
	cout << T.InsertFind(3, 8) << endl;
	T.Print();
	cout << "Perevorot:\n";
	List<int> y = -T;
	y.Print();
	y.Insert(-2);

}