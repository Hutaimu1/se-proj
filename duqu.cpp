#include"list1.h"
#include<fstream>
#include<vector>
#include<string>
#include<sstream>

vector<string>read() {
	vector<string>getanswer;
	string name = "D:\\C++\\test.txt";
	ifstream in(name.c_str());
	while (!in.eof()) {
		string s;
		getline(in, s);
		getanswer.push_back(s);
    }
	return getanswer;
}

string split1(const string& s, int i,int k) {
	string ans;
	for (int j = i; j < k; ++j)
		ans += s[j];
	return ans;
}
vector<string> deal(const vector<string>& v) {
	const char ch = ' ';
	vector<string> v1;
	for (auto i : v) {
		for (int pos = 0; pos < i.string::size(); ++pos) {
			if (i[pos] = ch) {
				string ans1;
				string ans2;
				ans1 = split1(i, 0, pos);
				ans2 = split1(i, pos + 1, i.string::size());
				i = ans2;
				v1.push_back(ans1);
			}
	   }
	}
	return v1;
}
int main() {
	vector<string> out;
	out = read();
	for (int i = 0; i < out.size(); ++i)
		cout << out[i] << endl;
	List list1(out);
	list1.printAll();
	return 0;
}