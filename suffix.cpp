#include<vector>
#include<fstream>
#include<sstream>
#include<iostream>
#include<string>
using namespace std;
vector<string> read() {
	vector<string> getvec;
	string name = "D:\\C++\\dictionary.txt";
	ifstream in(name.c_str());
	while (!in.eof()) {
		string s;
		getline(in, s);
		getvec.push_back(s);
	}
	return getvec;
}

string split(const string& s, int i,int k) {
	string ans;
	for (int j = i; j < k; ++j)
		ans += s[j];
	return ans;
}

bool istrue(vector<string>v1, vector<string>v2) {
	if (v1.size() != v2.size())return false;
	else {
		for (int i = 1; i < v1.size(); ++i) {
			if (v1[i] != v2[i])return false;
			else continue;
		}
	}
	return true;
}

int main() {
	int number;
	string suffix;
	cout << "Please input the number of letters of suffix:";
	cin >>number;
	cout << endl;
	cout << "Please input the suffix:";
	cin >> suffix;
	cout << endl;
	vector<string>word;
	vector<string> strsuffix;
	for (int i = 0; i < suffix.length(); ++i) {
		string s = split(suffix, i, i + 1);
		strsuffix.push_back(s);
	}

	vector<string> v = read();
	int lenth = v.size();
	int count = 0;
	for (int i = 0; i < lenth; ++i) {
		string temp = v[i];
		int strlen = temp.length();
		if (strlen < number)continue;
		else {
			vector<string> tempvec;
			for (int i = strlen - suffix.length(); i < strlen; ++i) {
				string s = split(temp, i, i + 1);
				tempvec.push_back(s);
			}
			while (istrue(strsuffix, tempvec)) {
				count++;
				word.push_back(temp);
			}
		}
	}
	cout << "The number of words of suffix"<<" "
		<<suffix<<"is "<<count << endl;
	for (int i = word.size()-1; i >= 0; --i) {
		cout << word[i] << endl;
	}
	return 0;
}