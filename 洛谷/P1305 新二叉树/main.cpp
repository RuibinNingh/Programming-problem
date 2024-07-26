#include <iostream>
#include <map>
using namespace std;

void find(char jd, map<char, string>& tree) {
	if (jd == '*') return;
	
	cout << jd;
	
	if (tree[jd][0] != '*') { 
		find(tree[jd][0], tree);
	}
	
	if (tree[jd][1] != '*') { 
		find(tree[jd][1], tree);
	}
}

int main() {
	int n;
	cin >> n;
	map<char, string> tree;
	char first;
	for (int i = 0; i < n; i++) {
		string into;
		cin >> into;
		if (i == 0) {
			first = into[0]; 
		}
		tree[into[0]] = into.substr(1, 2);
	}
	find(first, tree);
	return 0;
}

