// контейнер <list> двозвязний список
// forward list 
// функтор
// предикат (тру чи фолс)
// сортування
// лямбда функція
#include <iostream>
#include <list>
using namespace std;

template <class T>
ostream& operator << (ostream& os, list<T>& d) {
	for (auto el : d)
		cout << el << '\t'; cout << endl;
	return os;
}
void test() {
	list <int> s1{ 5,3,2,10,1 };
	list <int> s2{ 5,6,7,4,9 };
	s1.sort(); // сортування
	cout << s1; cout << endl;
	s2.sort(); // сортування
	cout << s2; cout << endl;

	s1.merge(s2);//склеюэмо двы множини
	cout << s1; cout << endl;
	cout << s2; cout << endl; //відсортовані зклеєні елементи
}
void test1() {
	list <int> s1{ 5,3,2,10,1 };
	list <int> s2{ 5,6,7,4,9 };
	cout << s1; cout << endl;
	cout << s2; cout << endl;
	auto it = s2.begin(); ++it; ++it;
	cout << *it << endl; // ітератор
	s1.splice(s1.begin(), s2, s2.begin(), it);//вирізаємо з одного і вставляємо в інший список 2 значення
	cout << s1; cout << endl;
	cout << s2; cout << endl;
}
//bool CompRev(int a, int b) {
//	return a > b;
//}
void test2() {
	list <int> s1{ 5,3,2,10,1 };
	list <int> s2{ 5,6,7,4,9 };
	cout << s1; cout << endl;
	cout << s2; cout << endl;
	//s1.sort(CompRev); //сортуємо за спаданням. 
	s1.sort([](int a, int b) {return a > b; }); //сортуємо за спаданням. Лямбда функція
	cout << s1; cout << endl;
}
void test3() {
	list <int> s1{ 5,3,2,10,1,5,6,2,8,0 };
	list <int> s2{ 5,6,7,4,9,-2,0,6,8,9 };
	cout << s1; cout << endl;
	cout << s2; cout << endl;
	s1.sort([](int a, int b) {return (abs(a) % 2) < (abs(b) % 2); }); //парні та не парні. Лямбда функція
	cout << s1; cout << endl;
}
void test4() {
	list <int> s1{ 5,3,2,10,1,5,6,2,8,0 };
	cout << s1; cout << endl;
	int k = 0;
	s1.sort([&k](int a, int b) {k++; return (abs(a) % 2) < (abs(b) % 2); }); //= захоплюємо константну змінну
	cout << s1; cout << endl;
	cout << k << endl;
	// [] лямбда не бачить зовнішніх змінних
	// = люба зовнішня змінна неявно захоплюється лямбдою по значенню
	// & захоплюємо змінну за посиланням
	// [&, k] к буде забрано неявно за значенням, всі інші змінні можна захопити і змінювати
	// [=, &k] все захопити за значенням а к за ссилкою
	// [x, &y] х за значенням, у за посиланням
}
void test5() {
	list <int> s1{ 5,3,2,10,1,5,6,2,8,0 };
	cout << s1; cout << endl;
	int k = 0;
	s1.sort([&k](int a, int b)->bool {k++; return (abs(a) % 2) < (abs(b) % 2); }); // результат функції перетворую в тип бул чи інший
	cout << s1; cout << endl;
	cout << k << endl;
}
void test6() {
	list <int> s1{ 2,3,1,5,1,5,3 };
	s1.sort();
	s1.unique(); // видає унікальні значення (лише після сортування)
	cout << s1; cout << endl;
}
void test7() {
	list <int> s1{ 2,3,1,5,1,5,3 };
	s1.sort();
	s1.unique([](int a, int b) {return abs(a - b) < 2; });
	cout << s1; cout << endl;
}
class SortReverse {
public:
	bool operator () (int a, int b) { return a > b; }
};
void test8() { // сортування функтор
	list <int> s1{ 2,3,1,5,1,5,3 };
	s1.sort(SortReverse());
	cout << s1; cout << endl;
}
bool IfBiggerThan(int k) { return k > 5; }

void test9() { 
	list <int> s1{ 2,3,1,5,1,5,3 };
	s1.remove_if(IfBiggerThan);
	cout << s1; cout << endl;
}

int main()
{
	//test();
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	//test7();
	//test8();
	test9();
	//test();
	//test();


}