//https://www.interviewbit.com/problems/min-steps-in-infinite-grid/
#include <iostream>
#include <vector>

using namespace std;

int minimumStep(int X1, int Y1, int X2, int Y2) {
    int diffX = abs(X1 - X2);
    int diffY = abs(Y1 - Y2);
    return max(diffY, diffX);
}

class Solution {
	public:
		int coverPoints(vector <int> &, vector<int> &);	
};

int Solution::coverPoints(vector<int> &X, vector<int> &Y) {
    int points = X.size();
    int i;
    int steps = 0;
    for(i=0;i<points-1;i++) {
        steps += minimumStep(X[i], Y[i], X[i+1], Y[i+1]);
    }
    return steps;
}

int main() {
	Solution s;
	vector <int> X {4, 8};
	vector <int> Y {4, -15};
	cout << "Number of steps = " << s.coverPoints(X, Y) << endl;
	return 0;
}

