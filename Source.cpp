#include <iostream>
#include <ctime>
#include <chrono>

const int SIZE = 10;

using namespace std;

struct INF {
	int key;
	char info;
}A[SIZE];

int findpivot(int i, int j) {
	int firstkey;
	firstkey = A[i].key;
	for (int k = i + 1; k <= j; k++) {
		if (A[k].key > firstkey)
			return k;
		else if (A[k].key < firstkey)
			return i;
	}
	return -1;
}

int findpivot_info(int i, int j) {
	char firstkey;
	firstkey = A[i].info;
	for (int k = i + 1; k <= j; k++) {
		if (A[k].info > firstkey)
			return k;
		else if (A[k].info < firstkey)
			return i;
	}
	return -1;
}

int partition(int i, int j, int pivot) {
	int l, r;
	l = i;
	r = j;
	do {
		swap(A[l].key, A[r].key);
		while (A[l].key < pivot)
			l++;
		while (A[r].key >= pivot)
			r--;
	} while (l <= r);

	return l;
}

int partition_info(int i, int j, int pivot) {
	int l, r;
	l = i;
	r = j;
	do {
		swap(A[l].info, A[r].info);
		while (A[l].info < pivot)
			l++;
		while (A[r].info >= pivot)
			r--;
	} while (l <= r);

	return l;
}

void quicksort(int i, int j) {
	int pivot;
	int pivotindex;
	int k;
	pivotindex = findpivot(i, j);
	if (pivotindex != -1) {
		pivot = A[pivotindex].key;
		k = partition(i, j, pivot);
		quicksort(i, k - 1);
		quicksort(k, j);
	}
}

void quicksort_info(int i, int j) {
	char pivot;
	int pivotindex;
	int k;
	pivotindex = findpivot_info(i, j);
	if (pivotindex != -1) {
		pivot = A[pivotindex].info;
		k = partition_info(i, j, pivot);
		quicksort_info(i, k - 1);
		quicksort_info(k, j);
	}
}

void output()
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << A[i].key << " ";
	}
	cout << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cout << A[i].info << " ";
	}
	cout << endl;
}

void input()
{
	for (int i = 0; i < SIZE; i++)
	{
		A[i].key = rand() % 50;
		A[i].info = rand() % 26 + 65;
	}
}

int main()
{
	srand(time(NULL));

	input();
	output();

	auto begin = std::chrono::steady_clock::now();
	quicksort(0, SIZE - 1);
	auto end = std::chrono::steady_clock::now();
	auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	cout << "Time to sort: " << elapsed_ms.count() << endl;


	begin = std::chrono::steady_clock::now();
	quicksort_info(0, SIZE - 1);
	end = std::chrono::steady_clock::now();
	elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	cout << "Time to sort: " << elapsed_ms.count() << endl;


	output();

	return 0;
}
