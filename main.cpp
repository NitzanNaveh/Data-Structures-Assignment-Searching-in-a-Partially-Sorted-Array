#include<iostream>
#include<random>
#include <ctime>
using namespace std;

/***********************
Ofek Amirav 318798907
Nitzan Naveh 318670502
************************/

class Result 
{
	int counter, index;
public:
	Result() { this->counter = 0, this->index = 0; }
	int GetCounter() { return this->counter; }
	int GetIndex() { return this->index; }
	void SetCounter(int counter) { this->counter = counter; }
	void SetIndex(int index) { this->index = index; }
};


Result* Search1(int V[],int m,int x)/*Running time: O(n)*/
{
	Result* search1=new Result();
	int counter = search1->GetCounter();
	int i = search1->GetIndex();
	while(V[i]!=0 && i<m)
	{	
		counter++;
		if (V[i] == x)
		{
			search1->SetCounter(counter);
			search1->SetIndex(i);
			return search1;
		}	
		else
			i++;
	}
	search1->SetCounter(counter);
	search1->SetIndex(-1);
	return search1;
}


Result* Search2(int V[], int m, int x)/*Running time: O(logm)*/
{
	Result* search2 = new Result();
	int start = 0, end = m - 1;
	int mid, counter = search2->GetCounter();
	while (start <= end)
	{
		counter++;
		mid = (start + end) / 2;
		if (V[mid] == x)
		{
			search2->SetCounter(counter);
			search2->SetIndex(mid);
			return search2;
		}
		if (V[mid] > x||v[mid]==0)
		{
			end = mid - 1;
		}
		if (V[mid] < x)
		{
			start = mid + 1;
		}
	} 
	search2->SetCounter(counter);
	search2->SetIndex(-1);
	return search2;

}

Result* Search3(int V[], int m, int x)/*Running time: O(logn)*/
{
	Result* search3 = new Result();
	int start = 0, end = m-1;
	int mid, counter = search3->GetCounter();
	int n;
	while (start <= end) /*search the n*/
	{
		mid = (start + end) / 2;
		if (V[mid] == 0)
		{
			end = mid - 1;
		}
		else
		{
			n = mid;
			start = mid + 1;
		}
	}
	start = 0, end = n-1;
	while (start <= end)
	{
		counter++;
		mid = (start + end) / 2;
		if (V[mid] == x)
		{
			search3->SetCounter(counter);
			search3->SetIndex(mid);
			return search3;
		}
		if (V[mid] > x)
		{
			end = mid-1;
		}
		if (V[mid] < x)
		{
			start = mid+1;
		}
	}
	search3->SetCounter(counter);
	search3->SetIndex(-1);
	return search3;
}




void BubbleSort(int arr[], int size)
{
	int temp = 0;
	for (int i = 0; i < size-1; i++)
	{
		for (int j = 0; j < size- i- 1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}


void main()
{
	srand(time(NULL)); /*fix the rand problem*/
	int avgSearch1 = 0, avgSearch2 = 0, avgSearch3 = 0;
	int m = 1000;
	int n, x;
	for (int i = 0; i < 500; i++)
	{
		int arr[1000];
		x = rand();
		n = 200 + (rand() % 101);
		for (int j = 0; j < n; j++)
		{
			arr[j] = rand();
		}
		BubbleSort(arr, n);
		for (int k = n; k < m; k++)
		{
			arr[k] = 0;
		}
		avgSearch1 += Search1(arr, m, x)->GetCounter();
		avgSearch2 += Search2(arr, m, x)->GetCounter();
		avgSearch3 += Search3(arr, m, x)->GetCounter();
	}
	cout << "200<=n<=300" << endl;
	cout << "Search1 average iterations:" << (float)avgSearch1 / 500 << endl;
	cout << "Search2 average iterations:" << (float)avgSearch2 / 500 << endl;
	cout << "Search3 average iterations:" << (float)avgSearch3 / 500 << endl;


}