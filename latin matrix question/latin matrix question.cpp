// latin matrix question.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
using namespace std;

static int n, m, count;
static vector<vector<int>> Board;

bool OK(int r,int c) { 
	//当前c列中有无和元素k重复的元素
	for (size_t i = 0; i < r; i++)
	{
		if(Board[i][c] == Board[r][c]) return   0 ;
	}
	return 1;
}
void Swap(int r, int c, int i) {
	//交换第r行中的第c个和第i个元素
	int temp = Board[r][c];
	Board[r][c] = Board[r][i];
	Board[r][i] = temp;
}
void Backtrace(int r,int c) {
	// 从上到下,从左到右依次递归
	// 对每一列元素进行交换排序递归,再检测是否能成功,成功了再往下一行递归
	for (int i = c; i < n; i++) {
		Swap(r, c, i);
		if (OK(r, c)) {
			if(r == m - 1)//最后一行时,判断y是否达到最后
				if (c == n - 1) { //最后一列时,count ++
					::count = ::count + 1;
				}
				else {
					Backtrace(r, c + 1);
				}
			else
				if (c == n - 1) {
					Backtrace(r + 1, 0);
				}
				else {
					Backtrace(r, c + 1);
				}
		}
		Swap(r, c, i);
	}
}
int main()
{
	// Board[m][n]作为排序的对象;
	ifstream fread;
	ofstream out;
	fread.open("input.txt");
	out.open("output.txt");
	fread >> m;
	fread >> n;
	Board.resize(m);
	for (int i = 0; i < m; i++) {
		Board[i].resize(n);
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			Board[i][j] = j + 1;
		}
	}
	::count = 0;
	Backtrace(0, 0);
	cout << "there are " << ::count <<" ways to build this matrix" << endl;
	out << ::count;
	system("pause");
	return 0;
}

