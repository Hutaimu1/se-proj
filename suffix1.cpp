#include<iostream>
#include<fstream>
#include<set>
#include<map>
#include<string>

using namespace std; 
string filename = "D:\\C++\\dictionary.txt";

int main() {
	ifstream inword;
	string str;
	set<string> dict;
	map<string, int> suffixmap;
	map<int, string> suffixmap2;
	int number;

	inword.open(filename);
	if (!inword)
		cout << "Can't open the file" << endl;;
	while (getline(inword, str)) {
		//to add all words to a set;
		dict.insert(str);
	}
	inword.close();

	cout << "Please enter the number of suffix of the words:";
	cin >> number;
	string word;
	set<string>::iterator it;
	for (it = dict.begin(); it != dict.end(); ++it) {
		word = *it;
		if (word.length() < number)continue;
		else {
			string suffix = word.substr(word.length() - number, number);
			suffixmap[suffix]++;
		}
	}

	map<string, int>::iterator it2;
	for (it2 = suffixmap.begin(); it2 != suffixmap.end(); ++it2) {
		suffixmap2.insert(pair<int, string>(it2->second, it2->first));
	}
	cout << "The top ten" << " " << number << "-" << "suffix are:" << endl;
	map<int, string>::iterator it3 = suffixmap2.end();
	it3--;
	for (int i = 0; i < 10; ++i) {
		cout << it3->second << "   " << it3->first << endl;
		it3--;
	}

	cout << "Please enter the suffix you want to query:";
	string suffix;
	string word2;
	cin >> suffix;
	map<string, string> suffixmap3;
	set<string>::iterator it4;
	for (it4 = dict.begin(); it4 != dict.end(); ++it4) {
		word2 = *it4;
		if (word2.length() < suffix.length())continue;
		else {
			if (word2.substr(word2.length() - suffix.length(), suffix.length()) == suffix) {
				suffixmap3.insert(pair<string, string>(word2, suffix));
			}
		}
	}

	map<string, string>::iterator it5 = suffixmap3.end();
	it5--;
	cout << "The number of words with suffix " << "'" << suffix << "' "
		<< "is: " << suffixmap3.size() << endl;;
	for (it5; it5 != suffixmap3.begin();--it5) {
		cout << it5->first << endl;
	}
}
