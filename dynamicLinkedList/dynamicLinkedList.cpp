#include<iostream>
#include<cmath>
#include<stdio.h>
#include<intrin.h>
#include<list>
#include<chrono>
#include<vector>

using namespace std;
using namespace chrono;

template<typename T>
class dynamicLinkedList {
private:
	vector<T*> pointers;					//�κ� �迭���� �ּ� ����
	int length = 0, size = 1, wsize = 1;	//length : �κ� �迭���� ���� ���� size: �κ� �迭 ũ�� wsize: ��ü ũ��

public:
	dynamicLinkedList() {				//������ ũ�� 1¥�� �޸� �Ҵ�
		T* tmp = (T*)malloc(sizeof(T));
		pointers.push_back(tmp);
	}
	void push_back(T data) {		//������ �߰�
		if (size == length) {		//�迭�� ������ ���� ���
			size = wsize;								//�Ҵ��� ũ�� = �����迭�� ��ü ũ��
			wsize *= 2;									//��ü ũ��� 2�谡 ��
			length = 1;									//���ο� �κ� �迭�̹Ƿ� ���Ұ��� 1
			T* tmp = (T*)malloc(sizeof(T) * size);		//���� �迭�� ��ü ũ���� �迭 �Ҵ�
			pointers.push_back(tmp);					//�ּҸ� �ּ� ���� �迭�� �߰�
			tmp[0] = data;								//������ �߰�
			
		}
		else {
			T* tmp = pointers.back();			//�迭 �� ��á���� �ڿ� ������ �߰�
			tmp[length] = data;
			length++;
		}
	}
	T at(unsigned int index) {				//index��° �����Ϳ� ���� �ڼ��� ������ ���� ÷���� ������ �ֽ��ϴ�. 
		if (index == 0) return *pointers[2];
		return pointers[32 - __lzcnt(index)][(int)(index - (1 << (31 - __lzcnt(index))))];		//lzcnt �Լ��� �տ� ���ӵǴ� 0���� return 
	}

};

/*template<typename T>
class list {
private:
	T* l;
	int length = 0, size = 1;

public:
	list() {
		l = (T*)malloc(sizeof(T));
	}
	void push_back(T data) {
		if (size == length) {
			size *= 2;
			T* tmp = (T*)malloc(sizeof(T) * size);
			for (int i = 0; i < length; i++) {
				tmp[i] = l[i];
			}
			tmp[length] = data;
			free(l);
			l = tmp;
			length++;
		}
		else {
			l[length] = data;
			length++;
		}
	}
	T at(unsigned int index) {
		return l[index];
	}
};*/

int main() {
	dynamicLinkedList<int> arr;  
	vector<int> v;
	system_clock::time_point start;
	system_clock::time_point end;
	nanoseconds nano;
	
	start = system_clock::now();		//�ð� üũ
	for (int j = 0; j < 100000000; j++) {
		v.push_back(j);
	}

	end = system_clock::now();

	nano = end - start;

	cout << "vector ��� 1�ﰳ ������ �߰� ����ð�(������ ns) : " << nano.count() << endl;
	
	 
	start = system_clock::now();
	for (int j = 0; j < 100000000; j++) {
		v.at(j);
	}
	end = system_clock::now();
	nano = end - start;

	cout << "vetcor ��� 1�ﰳ ������ Ž�� ����ð�(������ ns) : " << nano.count() << endl;
	v.clear();

	start = system_clock::now();
	for (int j = 0; j < 100000000; j++) {
		arr.push_back(j);
	}

	end = system_clock::now();

	nano = end - start;

	cout << "����Ʈ + �迭 1�ﰳ ������ �߰� ����ð�(������ ns) : " << nano.count() << endl;


	start = system_clock::now();
	for (int j = 0; j < 100000000; j++) {
		arr.at(j);
	}
	end = system_clock::now();
	nano = end - start;

	cout << "����Ʈ + �迭 1�ﰳ ������ Ž�� ����ð�(������ ns) : " << nano.count() << endl;
}