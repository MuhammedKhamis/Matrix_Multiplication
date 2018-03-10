#include <bits/stdc++.h>
#include <sys/time.h>

using namespace std;


vector<vector<int> >
multiply(vector<vector<int> > a , vector<vector<int> > b){
	vector<vector<int> > c;
	
	int wid = b[0].size();

	int hig = a.size();
	
	for(int i = 0 ; i < hig; i++){
		vector<int> row;
		for(int j = 0 ; j < wid ; j++){
			int elem = 0;
			for(int k = 0 ; k < a[i].size() ; k++){
				elem += a[i][k]*b[k][j]; 
			}
			row.push_back(elem);
		}
		c.push_back(row);
	}

	return c;
}

void
print_mat(vector<vector<int> > mat){

	for(int i = 0 ; i < mat.size() ; i++){
		for (int j = 0; j < mat[i].size() ; j++){
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}

int
main(int argc , char *argv[]){

	int n;
	freopen(argv[1],"r",stdin);

	cin >> n;
	vector<vector<int> > mat;


	for(int i = 0 ; i < n ; i++){
		vector<int> row;
		int elem;
		for(int j = 0 ; j < n ; j++){
			cin >> elem;
			row.push_back(elem);
		}
		mat.push_back(row);

	}
	fclose(stdin);

	struct timeval start,stop ; 

	// calc time
	gettimeofday(&start, NULL); //start checking time

	vector<vector<int> > res = multiply(mat,mat);

	gettimeofday(&stop, NULL); //start checking time
	//  end calc time

	printf("Microseconds taken: %lu\n", stop.tv_usec - start.tv_usec);
    printf("Seconds taken %lu\n", stop.tv_sec - start.tv_sec);
    printf("-----------------------------------------------------\n");

	//print_mat(res);
}