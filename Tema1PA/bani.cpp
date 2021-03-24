#include <bits/stdc++.h>
#include <iostream>     
#include <algorithm>    
#include <vector>       
using namespace std;

struct gard {
	int xStart, xEnd;
};

class Task {
public:
	void solve() {
		read_input();
		print_output(get_rez());
	}

private:
	int n;
	gard g[100001];
	
	void read_input() {
		ifstream fin("gard.in");
		fin >> n;
		for(int i = 0; i < n; i++) {
			fin >> g[i].xStart >> g[i].xEnd;
		}
		fin.close();
	}
	
	static bool compare(gard lhs, gard rhs) {
		if(lhs.xStart != rhs.xStart)
			return lhs.xStart > rhs.xStart;
		else
			return lhs.xEnd < rhs.xEnd;
	}

    int get_rez() {
        int rez = 0;
		sort(g, g + n, compare);
		for(int i = 0; i < n - 1; i++) { 
			for(int j = i + 1; j < n; j++)
				if(g[i].xEnd <= g[j].xEnd) {
					rez++;
					break;
				}
		}
		return rez;
    }

	void print_output(int rez) {
		ofstream fout("gard.out");
        fout << rez << "\n";
		fout.close();
	}
};

// Please always keep this simple main function!
int main() {
	// Allocate a Task object on heap in order to be able to 
	// declare huge static-allocated data structures inside the class.
	Task *task = new Task();
	task->solve();
	delete task;
	return 0;
}
