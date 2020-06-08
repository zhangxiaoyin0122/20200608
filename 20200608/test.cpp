#include <iostream>
#include <string>
#include <vector>

using namespace std;
//vector�Ķ���
void test1() {
	vector<int> v; //�޲ι���
	vector<int> v1(10, 5); //10��5
	string s("123456");	
	vector<char> v2(s.begin(),s.end()); //ʹ�õ��������г�ʼ��
	int a[6] = { 1,2,3,4,5,6 };
	vector<int> v3(a, a + 6);//ʹ�õ��������г�ʼ��	
	vector<int> v4(v3); //��������
}
void test2() {
	string s("123456789");
	vector<char> v(s.begin(), s.end());
	//���õ���������
	//���������
	vector<char>::reverse_iterator rit = v.rbegin();
	while (rit != v.rend()) {
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
	//���������
	vector<char>::iterator it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
	//��Χfor
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
	vector<int> v; //����ǿ�,����Ϊ0 PJ�������ݰ��մ���1.5������,SGIһ����2��
	size_t sz = v.size();
	size_t cap = v.capacity(); 
	cout << cap << endl; //����Ϊ0 ������ǰ���ÿռ�
	v.reserve (100);  //ֻ��������,����������
	cap = v.capacity(); //100
	v.reserve(10);
	cap = v.capacity();//100

	//resize(n, val); �������val����,��ʹ��Ĭ��ֵ:�Զ�������--> 0 ,�Զ�������-->�����޲ι���
}

void test5() {
	vector<int> v;
	//operator[]Խ��,���԰汾�������Դ���
	int ret = v[0];
	//atԽ��,���쳣
	int ret2 = v.at(0);
}
void test6() {
	vector<int> v;
	v.insert(v.begin(), 1); //1  ��posλ��ǰ����
	v.push_back(2);//12
	v.push_back(3);//123
	v.pop_back(); //βɾ
	vector<int>::iterator it = v.begin();
	cout << *it << endl; //1
	it = v.insert(it, 0);
	cout << *it << endl;//0
}
//swap����:��������vectorλ�õ�����
void test7() {
	vector<int> v1(5, 1);
	vector<int> v2(5, 2);
	swap(v1, v2);//�ڲ�����vector��Ա������swap����
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
	v1.emplace(v1.begin(), 3, 4);//���죫����
	B b1(5, 6);
	v1.emplace(v1.begin(), b1);

	v1.push_back(b1);
	v1.emplace_back(7, 8); //���죫β��
}

void test9() {

}

int main() {
	test6();
	return 0;
}