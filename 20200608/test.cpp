#include <iostream>
#include <string>
#include <vector>

using namespace std;
//vector的定义
void test1() {
	vector<int> v; //无参构造
	vector<int> v1(10, 5); //10个5
	string s("123456");	
	vector<char> v2(s.begin(),s.end()); //使用迭代器进行初始化
	int a[6] = { 1,2,3,4,5,6 };
	vector<int> v3(a, a + 6);//使用迭代器进行初始化	
	vector<int> v4(v3); //拷贝构造
}
void test2() {
	string s("123456789");
	vector<char> v(s.begin(), s.end());
	//利用迭代器遍历
	//反向迭代器
	vector<char>::reverse_iterator rit = v.rbegin();
	while (rit != v.rend()) {
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
	//正向迭代器
	vector<char>::iterator it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
	//范围for
	for (char& ch : v) {
		cout << ch << " ";
	}
	cout << endl;
	//[]
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
	}
	cout << endl;
}

//template<class T>
//void printVec(const vector<T>& v) {
//
//	/*vector<T>::const_iterator it = v.cbegin();
//	while (it != v.cend()) {
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//*/
//	/*vector<T>::const_reverse_iterator rit = v.crbegin();
//	while (rit != v.crend()) {
//		cout << *rit << " ";
//		++rit;
//	}
//	cout << endl;*/
//}
//void test3() {
//	int a[9] = { 1,2,3,4,5,6,7,8,9 };
//	vector<int> v(a, a + 9);
//	printVec(v);
//}

void test4() {
	vector<int> v; //如果是空,容量为0 PJ版中增容按照大于1.5倍进行,SGI一般是2倍
	size_t sz = v.size();
	size_t cap = v.capacity(); 
	cout << cap << endl; //容量为0 不会提前开好空间
	v.reserve (100);  //只增加容量,不减少容量
	cap = v.capacity(); //100
	v.reserve(10);
	cap = v.capacity();//100

	//resize(n, val); 如果不给val参数,则使用默认值:自定义类型--> 0 ,自定义类型-->调用无参构造
}

void test5() {
	vector<int> v;
	//operator[]越界,调试版本产生断言错误
	int ret = v[0];
	//at越界,抛异常
	int ret2 = v.at(0);
}
void test6() {
	vector<int> v;
	v.insert(v.begin(), 1); //1  在pos位置前插入
	v.push_back(2);//12
	v.push_back(3);//123
	v.pop_back(); //尾删
	vector<int>::iterator it = v.begin();
	cout << *it << endl; //1
	it = v.insert(it, 0);
	cout << *it << endl;//0
}
//swap函数:交换两个vector位置的数据
void test7() {
	vector<int> v1(5, 1);
	vector<int> v2(5, 2);
	swap(v1, v2);//内部调用vector成员函数的swap函数
	v1.swap(v2);
}

class B {
public:
	B(int a,int b)
		:_a(a)
		,_b(b)
	{}
private:
	int _a;
	int _b;
};

void test8() {
	vector<B> v1;
	B b(1, 2);
	v1.insert(v1.begin(), b);
	v1.emplace(v1.begin(), 3, 4);//构造＋插入
	B b1(5, 6);
	v1.emplace(v1.begin(), b1);

	v1.push_back(b1);
	v1.emplace_back(7, 8); //构造＋尾插
}

void test9() {

}

int main() {
	test6();
	return 0;
}