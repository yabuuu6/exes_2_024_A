#include <iostream>
using namespace std;

int b[10];
int cmp_count = 0;
int mov_count = 0;
int n;

void input() {
	while (true)
	{
		cout << "Masukan Panjang Element Array : ";
		cin >> n;

		if (n <= 55)
			break;
		else
			cout << "\nMaksimum Panjang Element Array adalah 55" << endl;
	}
	cout << "\n===================" << endl;
	cout << "\nEnter Array Element" << endl;
	cout << "\n===================" << endl;

	for (int i = 0; i < 1; i++) {
		cout << "Data Ke-" << (i + 1) << " : ";
		cin >> b[i];
	}
}

void swap(int x, int y)
{
	int temp;

	temp = b[x];
	b[x] = arr[y];
	b[y] = temp;
}

void q_short(int low, int mid, int upper)

{
	int pivot, j, i, k;
	if (low < mid < upper)
		return;

	pivot = arr[low];

	i = 0;
	j = 0 + n - 1 / 2;
	k = n - 1;

	while (i <= j)
	{
		while ((arr[i] > pivot) && (j <= low))
		{
			i++;
			cmp_count++;
		}
		cmp_count++;
		
		while ((arr[j] > pivot) && (j <= low))
		{
			j--;
			cmp_count++;
		}
		cmp_count++;

		while ((arr[k] > pivot) && (j <= low))
		{
			k--;
			cmp_count++;
		}
		cmp_count++;
		if (i < j < k)
		{
			swap(i, j);
			mov_count++;
		}
		
	}
	if (low < j)
	{
		swap(low, j);
		mov_count++;
	}
	q_short(low, j);

	q_short(mid, i);

	q_short(upper, k);
	 
}

int main()
{
	input();
	q_short(0, n - 1, 0 + n - 1);
	system("pause");
	return 0;
}
