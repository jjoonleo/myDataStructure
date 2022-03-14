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
	vector<T*> pointers;					//부분 배열들의 주소 저장
	int length = 0, size = 1, wsize = 1;	//length : 부분 배열에서 원소 개수 size: 부분 배열 크기 wsize: 전체 크기

public:
	dynamicLinkedList() {				//생성자 크기 1짜리 메모리 할당
		T* tmp = (T*)malloc(sizeof(T));
		pointers.push_back(tmp);
	}
	void push_back(T data) {		//데이터 추가
		if (size == length) {		//배열에 공간이 없을 경우
			size = wsize;								//할당할 크기 = 기존배열의 전체 크기
			wsize *= 2;									//전체 크기는 2배가 됨
			length = 1;									//새로운 부분 배열이므로 원소개수 1
			T* tmp = (T*)malloc(sizeof(T) * size);		//기존 배열의 전체 크기의 배열 할당
			pointers.push_back(tmp);					//주소를 주소 저장 배열에 추가
			tmp[0] = data;								//데이터 추가
			
		}
		else {
			T* tmp = pointers.back();			//배열 다 안찼으면 뒤에 데이터 추가
			tmp[length] = data;
			length++;
		}
	}
	T at(unsigned int index) {				//index번째 데이터에 접근 자세한 설명은 따로 첨부한 사진에 있습니다. 
		if (index == 0) return *pointers[2];
		return pointers[32 - __lzcnt(index)][(int)(index - (1 << (31 - __lzcnt(index))))];		//lzcnt 함수는 앞에 연속되는 0개수 return 
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
	
	start = system_clock::now();		//시간 체크
	for (int j = 0; j < 100000000; j++) {
		v.push_back(j);
	}

	end = system_clock::now();

	nano = end - start;

	cout << "vector 사용 1억개 데이터 추가 경과시간(나노초 ns) : " << nano.count() << endl;
	
	 
	start = system_clock::now();
	for (int j = 0; j < 100000000; j++) {
		v.at(j);
	}
	end = system_clock::now();
	nano = end - start;

	cout << "vetcor 사용 1억개 데이터 탐색 경과시간(나노초 ns) : " << nano.count() << endl;
	v.clear();

	start = system_clock::now();
	for (int j = 0; j < 100000000; j++) {
		arr.push_back(j);
	}

	end = system_clock::now();

	nano = end - start;

	cout << "리스트 + 배열 1억개 데이터 추가 경과시간(나노초 ns) : " << nano.count() << endl;


	start = system_clock::now();
	for (int j = 0; j < 100000000; j++) {
		arr.at(j);
	}
	end = system_clock::now();
	nano = end - start;

	cout << "리스트 + 배열 1억개 데이터 탐색 경과시간(나노초 ns) : " << nano.count() << endl;
}