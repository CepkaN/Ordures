
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<vector>
#include<ctime>
#include<queue>


void Trouver(std::string& str, std::string& sous) {
	int strs = str.size();
	int ss = sous.size();
	std::vector<int>indice;
	int cou = 0; int y = 0;
	for (int i = 0; i <= strs - ss; ++i) {
		int j;
		for (j = 0; j < ss; ++j) {
			if (str[i + j] != sous[j]) { break; }
		}
		if (j == ss) { indice.push_back(i); y = i; }
	}
	std::cout << "\n Êîëè÷åñòâî " << indice.size() << '\n';
	for (auto& u : indice) {
		std::cout << u << ' ';
	}std::cout << '\n';
}

int Interpolation(std::vector<int>& mass, int n, int tr) {
	int b = 0; int h = n - 1; int mid = 0; bool bo = false;
	for (bo = false; (mass[b] < tr) && (mass[h] > tr) && !bo;) {
		mid = b + ((tr - mass[b]) * (h - b)) / (mass[h] - mass[b]);
		if (mass[mid] == tr)return mid;
		if (mass[mid] < tr) {
			b = mid + 1;
		}
		else if (mass[mid] > tr) { h = mid - 1; }
		else bo = true;
	}
	if (mass[b] == tr)return b;
	else if (mass[h] == tr) { return h; }
	else return -1;
}
void Sundaram(bool* mass, int n) {
	int i, j;
	for (i = 1; i <= n; ++i)mass[i] = true;
	i = 1; j = 1;
	while ((2 * i * j + i + j) <= n) {
		while (j <= (n - 1) / (2 * i + 1)) {
			mass[2 * i * j + i + j] = false; ++j;
		}
		++i; j = i;
	}
	for (i = 1; i <= n; ++i) { if (mass[i])std::cout << 2 * i + 1 << ' '; }
	std::cout << '\n';
}
float Puissance(float x, int n) {
	float cou = 1;
	while (n) {
		if (n % 2 == 0) { n /= 2; x *= x; }
		else {
			--n; cou *= x;
		}
	}return cou;
}
int main() {

	setlocale(LC_ALL, "Ru");

	// ÏÎÈÑÊ ÏÎÄÑÒĞÎÊÈ Â ÑÒĞÎÊÅ

	/*std::string str;
	std::getline(std::cin,str);
	std::string s;
	std::cin >> s;

	Trouver(str, s);*/

	//std::vector<int>mass(10);
	//srand(time(NULL));
	//for (int i = 0; i < 10; ++i) {
	//	mass[i] = 20 + rand() % 125;
	//}
	//for (auto& t : mass) { std::cout << t << ' '; }
	//std::cout << '\n';
	//std::ranges::sort(mass);
	//for (auto& t : mass) { std::cout << t << ' '; }
	//std::cout << '\n';
	//int y = 10;
	//while (y--) {
	//	int r; std::cin >> r;

	//	// ÈÍÒÅĞÏÎËßÖÈÎÍÍÛÉ ÏÎÈÑÊ

	//	std::cout << Interpolation(mass, 10, r) << '\n';

	//}

	//// ĞÅØÅÒÎ ÑÓÍÄÀĞÀÌÀ

	//bool mass1[1000];
	//int n = 30; //ğàçìåğ
	//std::cout << "\n Ïğîñòûå ÷èñëà : 2 ";
	//Sundaram(mass1, n);

	// ÂÎÇÂÅÄÅÍÈÅ Â ÑÒÅÏÅÍÜ

	float x; int n;
	std::cin >> x >> n;
	std::cout << "\n " << x << "^" << n << ' ' << Puissance(x, n) << '\n';

	return 0;

}