#include <bits/stdc++.h>
#include <sys/time.h>

using namespace std;



vector<vector<long long> >
multiply(vector<vector<long long> > a , vector<vector<long long> > b){
	vector<vector<long long> > c;
	
	long long wid = b[0].size();

	long long hig = a.size();
	
	for(long long i = 0 ; i < hig; i++){
		vector<long long> row;
		for(long long j = 0 ; j < wid ; j++){
			long long elem = 0;
			for(long long k = 0 ; k < a[i].size() ; k++){
				elem += a[i][k]*b[k][j]; 
			}
			row.push_back(elem);
		}
		c.push_back(row);
	}

	return c;
}

void
print_mat(vector<vector<long long> > mat){

	for(long long i = 0 ; i < mat.size() ; i++){
		for (long long j = 0; j < mat[i].size() ; j++){
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}

int
main(int argc , char *argv[]){

	long long n;

	
	for(int k = 1 ; k < argc ; k++){

		freopen(argv[k],"r",stdin);

		cin >> n;
		
		vector<vector<long long> > mat;


		for(long long i = 0 ; i < n ; i++){
			vector<long long> row;
			long long elem;
			for(long long j = 0 ; j < n ; j++){
				cin >> elem;
				row.push_back(elem);
			}
			mat.push_back(row);

		}

		fclose(stdin);


		struct timeval start,stop ; 

		// calc time
		gettimeofday(&start, NULL); //start checking time

		vector<vector<long long> > res = multiply(mat,mat);

		gettimeofday(&stop, NULL); //start checking time
		//  end calc time

		printf("Microseconds taken: %lu\n", stop.tv_usec - start.tv_usec);
	    printf("Seconds taken %lu\n", stop.tv_sec - start.tv_sec);
	    printf("-----------------------------------------------------\n");
	}
	//print_mat(res);
}