#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder2(const vector<vector <int> > &A) {
    vector<int> result;
    int rows = A.size();
    int cols = A[0].size();

    if(rows==0 || cols==0) {
        return vector<int> ();
    }

    int row=0, col=0, layer=0;
    int dir=0;

    result.push_back(A[0][0]);

    for(int step=1; step<rows*cols; step++) {
        switch(dir) {
            case 0: 
                if(col != cols-layer-1) {
                    col++;
                } else {
                    row++;
                    dir++;
                }
                break;
            case 1:
                if(row != rows-layer-1) {
                    row++;
                } else {
                    col--;
                    dir++;
                }
                break;
            case 2:
                if(col != layer) {
                    col--;
                } else {
                    row--;
                    dir++;
                }
                break;
            case 3:
                if(row != layer+1) {
                    row--;
                } else {
                    col++;
                    dir = 0;
                    layer++;
                }
                break;
        }
        result.push_back(A[row][col]);
    }
    return result;
}


vector<int> spiralOrder1(const vector<vector<int> > &A) {
	vector<int> result;
    int m = A.size();
    int n = A[0].size();
    
    int top = 0;
    int bottom = m-1;
    int left = 0;
    int right = n-1;
    
    int dir = 0;

    while(top<=bottom && left<=right) {
        if(dir==0) {
            for(int i=left; i<=right;i++) {
                result.push_back(A[top][i]);
            }
            top++;
            dir = 1;
        } else if (dir==1) {
            for(int j=top;j<=bottom;j++) {
                result.push_back(A[j][right]);
            }
            right--;
            dir = 2;
        } else if(dir==2) {
            for(int i=right;i>=left;i--) {
                result.push_back(A[bottom][i]);
            }
            bottom--;
            dir = 3;
        } else if(dir==3) {
            for(int j=bottom;j>=top;j--) {
                result.push_back(A[j][left]);
            }
            left++;
            dir = 0;
        }
    }
	return result;
}


int main () {
    vector <vector <int> > V {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector <int> result;

    result = spiralOrder1(V);

    for (int i=0; i<result.size();i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    result = spiralOrder2(V);

    for (int i=0; i<result.size();i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
