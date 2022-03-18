#include <iostream>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
	pair<string, int> p;
	p.first = "one";
	p.second = 1;
	pair<string, int> p2("two", 2);
	pair<string, int> p3{ "two", 2 };
	pair<string, int> p4 = { "two", 2 };
	p = p2;
	p = pair<string, int>("three", 3);
	p = make_pair("three", 3);
	// auto p5 = { "three", 3 }; // так нельзя
	auto p5 = make_pair(string("three"), 3); //а так можно

	vector<pair<string, int>> v;
	v.emplace_back("five", 5);
	v.emplace_back("second", 6);
	unordered_map<string, int> u_mp(v.begin(), v.end());
	map<string, int> mp;
	mp["one"] = 1;
	mp.insert(p2);
	mp.insert({ "three", 0 });
	mp.emplace("four", 4);

	for (auto e : mp) // e - pair<string, int>
		cout << e.first << " " << e.second << endl;
	cout << endl;

	mp["three"] = 3;
	for (auto e : mp) // e - pair<string, int>
		cout << e.first << " " << e.second << endl;
	cout << endl;

	mp.insert({ "three", 100 });
	for (auto &e : mp) // проход по ссылке, теперь имеет смысл
		// даже при небольших объектах в структуре,
		// так как теперь можно изменять second
		// ключ по прежнему неизменяем, так как как и в сете
		// по нему строится структура данных, но если ключ
		// или значение могут быть большими, тоже стоит использовать
		// проход по ссылке
		cout << e.first << " " << e.second << endl;
	cout << endl;

	// mp.erase(4); нельзя удалять по значению
	mp.erase("four");

	for (auto e : mp) // e - pair<string, int>
		cout << e.first << " " << e.second << endl;
	cout << endl;

	for (auto it = mp.begin(); it != mp.end();)
		if (it->second == 2)
			it = mp.erase(it);
		else
			it++;
	// Также присутсвуют find и cout по ключу,
	// size, clear, swap и т.п.
	// Они действуют также как и их аналоги из set
}
