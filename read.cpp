#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include"std_lib_facilities.h"
#include<set>
#include<map>
using namespace std;

double string_to_double(string s) {
	//���ַ���ת��Ϊdouble
	double num;
	stringstream ss(s);
	ss >> num;
	return num;
}

int string_to_int(string s) {
	//���ַ���ת��Ϊ����
	int num;
	stringstream ss(s);
	ss >> num;
	return num;
}

string split(const string& s, int i, int k) {
	//ȡ�ַ���������i��k���Ӵ�
	string ans;
	for (int j = i; j < k; ++j) {
		ans += s[j];
	}
	return ans;
}

vector<string> substr1(string& s){
	//���� , ���ַ�����֣�������������
	const char ch = ',';
	vector<string> v;
	for (int i = 0; i < s.length();++i) {
		char temp = s[i];
		if (temp == ch) {
			string ans1 = split(s, 0, i);
			string ans2 = split(s, i + 1, s.length());
			s = ans2;
			v.push_back(ans1);
			i = 0;
		}
	}
	v.push_back(s);
	return v;
}

string substr2(string& s) {
	//ȥ���ַ����еķ����ֺ���ĸ�ַ��������� . - / ,��
	for (int i = 0; i < s.length(); ++i) {
		char ch = s[i];
		if (!isalnum(ch) && ch != '.' && ch != '-' && ch != '/' && ch != ',') {
			if (i == 0) {
				s = s.substr(1);
			}
			else {
				s = s.substr(0, i) + s.substr(i + 1);
			}
			i = -1;
		}
		else continue;
	}
	return s;
}

vector<vector<string>> read(string name) {
	vector<string> getread;
	ifstream in(name.c_str());
	if (!in)error("can't open this file");
	while (!in.eof()) {
		string s;
		getline(in, s);
		getread.push_back(s);
	}
	getread.erase(getread.begin());
	vector<vector<string>> getread2;
	for (int i = 0; i < getread.size(); ++i) {
		string temp = getread[i];
		getread2.push_back(substr1(temp));
	}
	return getread2;
}

set<vector<int>> readholiday() {
	//��ȡholiday�ļ��������еĽڼ��շ��뼯����
	vector<string> getread;
	string name = "D:\\C++\\Commodities\\Holiday.csv";
	ifstream in(name.c_str());
	if (!in)error("can't open this file");
	while (!in.eof()) {
		string s;
		getline(in, s);
		getread.push_back(s);
	}
	getread.erase(getread.begin());
	getread.erase(getread.begin() + getread.size() - 1);
	set<vector<int>> se;
	for (int i = 0; i < getread.size(); ++i) {
		string temp = getread[i].substr(getread[i].find(",") + 1);
		int y = string_to_int(temp.substr(0, 4));
		int m = string_to_int(temp.substr(4, 2));
		int d = string_to_int(temp.substr(6));
		vector<int> v = { y,m,d };
		se.insert(v);
	}
	return se;
}

vector<vector<string>> readdetail() {
	//��ȡExpirydetail�ļ��е���Ϣ
	vector<string> getread;
	string name = "D:\\C++\\Commodities\\ExpiryDetails.csv";
	ifstream in(name.c_str());
	if (!in)error("can't open this file");
	while (!in.eof()) {
		string s;
		getline(in, s);
		getread.push_back(s);
	}
	getread.erase(getread.begin());//ȥ���ļ��ĵ�һ��
	vector<vector<string>> getread2;
	for (int i = 0; i < getread.size(); ++i) {
		string temp = getread[i];
		getread2.push_back(substr1(temp));//csv�ļ�����","����ַ���
	}
	return getread2;
}

vector<vector<string>> readmark() {
	//��ȡMark1.json�ļ�
	vector<string> v;
	string name = "D:\\C++\\Commodities\\Marks1.json";
	ifstream in(name.c_str());
	if (!in)error("can't open the file");
	while (!in.eof()) {
		string s;
		getline(in, s);
		v.push_back(s);
	}

	vector<vector<string>> readmark2;
	for (int i = 0; i < v.size(); ++i) {
		string temp = v[i];
		string temp2 = substr2(temp);
		readmark2.push_back(substr1(temp));//�����ŷָ��ַ���
	}
	vector<vector<string>> readmark3;
	vector<string> contain;
	for (int i = 0; i < readmark2.size(); ++i) {
		vector<string> temp = readmark2[i];
		for (int j = 0; j < temp.size(); ++j) {
			if (temp[j] != "") {
				contain.push_back(temp[j]);
			}
		}
		if (contain.size() != 0) {
			readmark3.push_back(contain);
			contain.clear();
		}
	}
	vector<int> dateline;
	for (int i = 0; i < readmark3.size(); ++i) {
		int len = readmark3[i].size();
		if (len == 1) {
			string temp = readmark3[i][0];
			if (temp.find("As-of-day") >= 0 && temp.find("As-of-day") < temp.size()) {
				dateline.push_back(i);
			}
		}
	}
	vector<vector<string>> readmark4;
	vector<string> time_goodstype;
	string date;
	string type;
	for (int i = 0; i < dateline.size() - 1; ++i) {
		date = readmark3[i][0].substr(readmark3[i][0].find("As-of-day"));
		time_goodstype.push_back(date);
		for (int j = dateline[i] + 1; j < dateline[i + 1]; ++j) {
			if (readmark3[j].size() == 1) {
				type = readmark3[j][0];
				time_goodstype.push_back(type);
			}
			else {
				for (int k = 0; k < readmark3[j].size(); ++k) {
					time_goodstype.push_back(readmark3[j][k]);
				}
			}
			if (time_goodstype.size() > 2) {
				readmark4.push_back(time_goodstype);
				time_goodstype.clear();
				time_goodstype.push_back(date);
				time_goodstype.push_back(type);
			}
		}
	}
	time_goodstype.clear();
	date = readmark3[dateline[dateline.size() - 1]][0].substr(readmark3[dateline[dateline.size() - 1]][0].find("As-of-day"));
	time_goodstype.push_back(date);
	for (int j = dateline[dateline.size() - 1] + 1; j < readmark3.size(); ++j) {
		if (readmark3[j].size() == 1) {
			type = readmark3[j][0];
			time_goodstype.push_back(type);
		}
		else {
			for (int k = 0; k < readmark3[j].size(); ++k) {
				time_goodstype.push_back(readmark3[j][k]);
			}
		}
		if (time_goodstype.size() > 2) {
			readmark4.push_back(time_goodstype);
			time_goodstype.clear();
			time_goodstype.push_back(date);
			time_goodstype.push_back(type);
		}
	}
	for (int i = 0; i < readmark4.size(); ++i) {
		if (readmark4[i].size() <= 3) {
			readmark4.erase(readmark4.begin() + i);
			i = -1;
		}
	}
	return readmark4;
}

vector<int> add_day(int n, int &y, int &m, int &d) {
	//y��m��d������n�������ڣ��������ڵ�����
	vector<int> fate;
	while (n > 0) {
		if ((y % 400 == 0 && y % 4 != 0) || y % 4 != 0) {//ƽ��ÿ������
			fate = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		}
		else {
			fate = { 31,29,31,30,31,30,31,31,30,31,30,31 };//����ÿ������
		}
		if (m == 12 && d == 31) { m = 1; d = 1; y++; }//һ�������һ��
		else if (m != 12 && d == fate[m - 1]) { m++; d = 1; }//ĳ�������һ�죨������ʮ���£�
		else { d++; }
		n--;
	}
	return{ y,m,d };
}

int daydis(vector<int> day1, vector<int> day2) {
	//���������������
	int x = 0;
	if (day1[0] > day2[0] || (day1[0] == day2[0] && day1[1] > day2[1])//���day1��day2�����󣬷���-1
		|| (day1[0] == day2[0] && day1[1] == day2[1] && day1[2] > day2[2]))return -1;
	else {
		while (day1 != day2) {
			vector<int> day = add_day(1, day1[0], day1[1], day1[2]);
			x++;
		}
		return x;
	}
}

bool is_holiday_or_weekend(vector<int> day) {
	//�ж�ĳһ���Ƿ�Ϊ��ĩ�ͽڼ���
	set<vector<int>> holiday = readholiday();
	vector<int> primaryday = { 2006,1,1 };//�趨��ʼ���ڣ������죩
	int x = daydis(primaryday, day); //����ĳһ�쵽��ʼ���ڵ�������
	if (x % 7 == 6 || x % 7 == 0 ||holiday.find(day)!=holiday.end()) {//������ģ7Ϊ6��0˵��Ϊ��ĩ��holiday�а�����һ��˵��Ϊ�ڼ���
		return true;
	}
	return false;
}

int main() {
	vector<vector<string>> detail = readdetail();
	vector<vector<string>> Marks = readmark();
	set<string> tradeday;//Mark1�ļ��п��ܵ�����
	for (int i = 0; i < Marks.size(); ++i) {
		tradeday.insert(Marks[i][0]);
	}
	ifstream in;
	string file;
	cout << "Input business type file name(Future or Swap):";
	cin >> file;
	in.open("D:\\C++\\Commodities\\" + file + ".csv");
	while (!in) {
		cout << "Unable to open that file. Try again." << endl;
		cout << "Input business type file name(Future or Swap):";
		in.close();
		cin >> file;
		in.open("D:\\C++\\Commodities\\" + file + ".csv");
	}
	if (file == "Future") {//Future case
		/*��ȡFuture�ļ�����Ϣ*/
		vector<string> getread;
		while (!in.eof()) {
			string s;
			getline(in, s);
			getread.push_back(s);
		}
		getread.erase(getread.begin());
		vector<vector<string>> getread2;
		for (int i = 0; i < getread.size(); ++i) {
			string temp = getread[i];
			getread2.push_back(substr1(temp));
		}
		/*###########################################*/
		set<string> order_id;//Future�ļ��ж�����
		for (int i = 0; i < getread2.size(); ++i) {
			order_id.insert(getread2[i][0]);
		}
		string tradedate;//���������
		cout << "Please enter the date of today(y/m/d):";
		while (cin >> tradedate) {
			set<string>::iterator it;
			it = tradeday.find("As-of-day" + tradedate);
			if (it == tradeday.end()) {
				cout << "Illegal tradeday,try again." << endl;
				cout << "Please enter the date of today(y/m/d):";
			}
			else {
				string tradenum;//������
				cout << "Please enter the orderid:";
				while (cin >> tradenum) {
					set<string>::iterator it;
					it = order_id.find(tradenum);
					if (it == order_id.end() && tradenum != "q") {//��Future�ļ���û�ҵ�����������������
						cout << "Illegal orderid,try again." << endl;
						cout << "Please enter the orderid:";
					}
					if (tradenum == "q")return 0;//����q�����˳�
					else {
						for (int i = 0; i < getread2.size(); ++i) {
							if (getread2[i][0] == tradenum) {
								string ordertype = getread2[i][1];//�����
								string goodstype = getread2[i][2];//��������
								string date = getread2[i][3];//�ö�����������
								double payprice = string_to_double(getread2[i][4]);
								double quantity = string_to_double(getread2[i][5]);
								double paymentflow = payprice * quantity;
								for (int i = 0; i < Marks.size(); ++i) {//Ѱ��Mark�ļ��ж�Ӧ�������ڵ��г��۸�
									if ("As-of-day" + tradedate == Marks[i][0] && goodstype == Marks[i][1] && "ContractMonth" + date == Marks[i][3]) {
										double physicalprice = string_to_double(Marks[i][5].substr(4));
										double physicalflow = quantity * physicalprice;
										if (ordertype == "B") {
											cout << "Exposure:" << quantity << endl;
											cout << "PV0:" << physicalflow - paymentflow << endl;
										}
										else {
											cout << "Exposure:" << quantity << endl;
											cout << "PV0:" << -1.0*(physicalflow - paymentflow) << endl;
										}
									}
								}
								cout << "Please enter the orderid:";
							}
						}
					}
				}
			}
		}
	}
	if (file == "Swap") {
		/*��ȡSwap�ļ�����Ϣ*/
		vector<string> getread;
		while (!in.eof()) {
			string s;
			getline(in, s);
			getread.push_back(s);
		}
		getread.erase(getread.begin());
		vector<vector<string>> getread2;
		for (int i = 0; i < getread.size(); ++i) {
			string temp = getread[i];
			getread2.push_back(substr1(temp));
		}
		getread2.erase(getread2.begin() + getread2.size() - 1);
		/*#############################################################*/
		set<string> order_id;
		for (int i = 0; i < getread2.size(); ++i) {
			order_id.insert(getread2[i][0]);
		}
		string tradedate;//���������
		cout << "Please enter the date of today(y/m/d):";
		while (cin >> tradedate) {
			set<string>::iterator it;
			it = tradeday.find("As-of-day" + tradedate);
			if (it == tradeday.end()) {
				cout << "Illegal tradeday,try again." << endl;
				cout << "Please enter the date of today(y/m/d):";
			}
			else {
				string tradenum;
				cout << "Please enter the orderid:";
				while (cin >> tradenum) {
					set<string>::iterator it;
					it = order_id.find(tradenum);
					if (it == order_id.end() && tradenum != "q") {
						cout << "Illegal orderid,try again." << endl;
						cout << "Please enter the orderid:";
					}
					if (tradenum == "q")return 0;
					else {
						for (int i = 0; i < getread2.size(); ++i) {
							if (getread2[i][0] == tradenum) {
								double price = 0;
								int count = 0;
								string ordertype = getread2[i][2];//B
								double fixedprice = string_to_double(getread2[i][3]);//50
								string goodstype = getread2[i][4].substr(0, getread2[i][4].find("1nb"));//WTI
								double quantity = string_to_double(getread2[i][5]);//22000
								double fixed = fixedprice * quantity;
								string startdate = getread2[i][7];// 2017.5.1
								string enddate = getread2[i][8];//2017.5.31
								int syear = string_to_int(startdate.substr(startdate.find_last_of("/") + 1));
								int smonth = string_to_int(startdate.substr(0, startdate.find("/")));
								int startday = string_to_int(startdate.substr(startdate.find("/") + 1, startdate.find_last_of("/") - startdate.find("/") - 1));
								int eyear = string_to_int(enddate.substr(enddate.find_last_of("/") + 1));
								int emonth = string_to_int(enddate.substr(0, enddate.find("/")));
								vector<int> start = { syear,smonth,startday };//������ʼ����
								int endday = string_to_int(enddate.substr(enddate.find("/") + 1, enddate.find_last_of("/") - enddate.find("/") - 1));
								vector<int> end = { eyear,emonth,endday };//������������
								int possibledays = daydis(start, end)+1;//������
								for (int k = 0; k < possibledays; ++k) {//������ʼ���ںͽ��������е�ÿһ��
									vector<int> copystart = start;
									vector<int> tempday = add_day(k, start[0], start[1], start[2]);
									start = copystart;
									for (int j = 0; j < detail.size() - 1; ++j) {
										string type = detail[j][0];
										if (type == goodstype) {
											string last_trade_date1 = detail[j][3];
											int last_year1 = string_to_int(last_trade_date1.substr(0, 4));
											int last_month1 = string_to_int(last_trade_date1.substr(4, 2));
											int last_day1 = string_to_int(last_trade_date1.substr(6));
											vector<int> last_trade_day1 = { last_year1,last_month1,last_day1 };
											int trade_y = string_to_int(tradedate.substr(0, 4));
											int trade_m = string_to_int(tradedate.substr(4, 2));
											int trade_d = string_to_int(tradedate.substr(6));
											vector<int> trade_day = { trade_y,trade_m,trade_d };
											double floatprice = 0;
											if ((!is_holiday_or_weekend(tempday)) && (daydis(tempday, trade_day) >= 0) && 
												(daydis(trade_day,last_trade_day1)<31) ) {
												//tempday���ǽڼ�����λ�ڵ�ǰ���ڻ�֮ǰ
												for (int m = 0; m < Marks.size(); ++m) {
													string da = Marks[m][4].substr(Marks[m][4].find("Date") + 4);
													int dayear = string_to_int(da.substr(0, 4));
													int damonth = string_to_int(da.substr(4, 2));
													int daday = string_to_int(da.substr(6));
													vector<int> dadate = { dayear,damonth,daday };
													if (Marks[m][0] == "As-of-day" + tradedate && Marks[m][1] == goodstype && dadate == tempday && Marks[m][2] == "TypeSettlementPrice") {
														//��Mark�л�ȡ�г���
														floatprice = string_to_double(Marks[m][5].substr(Marks[m][5].find("Mark") + 4));
														price += floatprice;
														count++;
													}
												}
											}
											else if ((!is_holiday_or_weekend(tempday)) && daydis(tempday, trade_day) < 0
												&& daydis(tempday, last_trade_day1) >= 0 && daydis(tempday, last_trade_day1) < 31) {
												//tempday���ǽڼ�����λ�ڵ�ǰ����֮��
												string trademonth = "ContractMonth" + detail[j][1].substr(detail[j][1].find("-") + 1) + "-" + detail[j][1].substr(0, detail[j][1].find("-"));
												for (int n = 0; n < Marks.size(); ++n) {
													if (Marks[n][0] == "As-of-day" + tradedate && Marks[n][1] == goodstype && trademonth == Marks[n][3] && Marks[n][2] == "TypeForward") {
														floatprice = string_to_double(Marks[n][5].substr(Marks[n][5].find("Mark") + 4));
														price += floatprice;
														count++;
													}
												}
											}
											else continue;
										}
									}
								}
								cout << "PV0:" << quantity*price / count - fixed << endl;
								price = 0;
								count = 0;
								cout << "Please enter the orderid:";
							}
						}
					}
				}
			}
		}
	}
}