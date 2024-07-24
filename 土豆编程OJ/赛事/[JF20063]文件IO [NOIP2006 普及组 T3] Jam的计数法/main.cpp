#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 获取下一个 Jam 数字
string next_jam_number(const string& jam, const vector<char>& letters, int w) {
	vector<int> jam_indices(w);
	for (int i = 0; i < w; ++i) {
		jam_indices[i] = find(letters.begin(), letters.end(), jam[i]) - letters.begin();
	}
	
	for (int i = w - 1; i >= 0; --i) {
		if (jam_indices[i] < letters.size() - w + i) {
			jam_indices[i]++;
			for (int j = i + 1; j < w; ++j) {
				jam_indices[j] = jam_indices[j - 1] + 1;
			}
			string next_jam;
			for (int k = 0; k < w; ++k) {
				next_jam += letters[jam_indices[k]];
			}
			return next_jam;
		}
	}
	return ""; // 没有更多的 Jam 数字
}

// 生成最多 5 个下一个 Jam 数字
vector<string> generate_next_jam_numbers(int s, int t, int w, const string& current_jam) {
	vector<string> results;
	vector<char> letters;
	for (int i = s - 1; i < t; ++i) {
		letters.push_back('a' + i);
	}
	
	string current = current_jam;
	for (int i = 0; i < 5; ++i) {
		current = next_jam_number(current, letters, w);
		if (current.empty()) break;
		results.push_back(current);
	}
	
	return results;
}

int main() {
	freopen("count.in", "r", stdin);
	freopen("count.out", "w", stdout);
	
	int s, t, w;
	string current_jam;
	
	cin >> s >> t >> w;
	cin >> current_jam;
	
	vector<string> next_jams = generate_next_jam_numbers(s, t, w, current_jam);
	
	for (const string& jam : next_jams) {
		cout << jam << endl;
	}
	
	return 0;
}
