#include <bits/stdc++.h>
#include <sys/time.h>

using namespace std;


void
multiply(vector<vector<long long> > a, vector<vector<long long> > b, vector<vector<long long> > &c){
	
	long long wid = 2;

	long long hig = 2;
	
	for(long long i = 0 ; i < hig; i++){
		for(long long j = 0 ; j < wid ; j++){
			for(long long k = 0 ; k < wid ; k++){
				c[i][j] += a[i][k]*b[k][j]; 
			}
		}	
	}

}

void
add(vector<vector<long long> > a, vector<vector<long long> > b, vector<vector<long long> > &c){

	for(long long i = 0 ; i < a.size() ; i++){
		for(long long j = 0 ; j < a[i].size() ; j++){
			c[i][j] = a[i][j]+b[i][j];
		}
	}
}

void
subtract(vector<vector<long long> > a, vector<vector<long long> > b, vector<vector<long long> > &c){

	for(long long i = 0 ; i < a.size() ; i++){
		for(long long j = 0 ; j < a[i].size() ; j++){
			c[i][j] = a[i][j]-b[i][j];
		}
	}
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

void
dvide_conqure(long long size, vector<vector<long long> > a, vector<vector<long long> > b , vector<vector<long long> > &c){

	if(size == 2){
		multiply(a,b,c);
		return;
	}
	long long new_size = size/2;
	vector<long long> inner (new_size);
	vector< vector<long long > > a11(new_size,inner),
	a12(new_size,inner),a21(new_size,inner),a22(new_size,inner),
	b11(new_size,inner),b12(new_size,inner),b21(new_size,inner),
	b22(new_size,inner),p1(new_size,inner),p2(new_size,inner),
	p3(new_size,inner),p4(new_size,inner),p5(new_size,inner),
	p6(new_size,inner),p7(new_size,inner),temp_left(new_size,inner),
	temp_right(new_size,inner);

	for(long long i = 0 ; i < new_size ; i++){
		for(long long j = 0 ; j < new_size ; j++){

                a11[i][j] = a[i][j];
                a12[i][j] = a[i][j + new_size];
                a21[i][j] = a[i + new_size][j];
                a22[i][j] = a[i + new_size][j + new_size];

                b11[i][j] = b[i][j];
                b12[i][j] = b[i][j + new_size];
                b21[i][j] = b[i + new_size][j];
                b22[i][j] = b[i + new_size][j + new_size];
		}
	}

	 // p1 = a*(f-h)
	 subtract(b12,b22,temp_right);
	 dvide_conqure(new_size,a11,temp_right,p1);
	 
	 // p2 = (a+b)h
	 add(a11,a12,temp_left);
	 dvide_conqure(new_size,temp_left,b22,p2);
	 
	 // p3 = (c+d)e
	 add(a21,a22,temp_left);
	 dvide_conqure(new_size,temp_left,b11,p3);
	 
	 // p4 = d(g-e)
	 subtract(b21,b11,temp_right);
	 dvide_conqure(new_size,a22,temp_right,p4);

	 // p5 = (a+d)(e+h)
	 add(a11,a22,temp_left);
	 add(b11,b22,temp_right);
	 dvide_conqure(new_size,temp_left,temp_right,p5);

	 // p6 = (b-d)(g+h)
	 subtract(a12,a22,temp_left);
	 add(b21,b22,temp_right);
	 dvide_conqure(new_size,temp_left,temp_right,p6);
	 
	 // p7 = (a-c)(e+f)
	 subtract(a11,a21,temp_left);
	 add(b11,b12,temp_right);
	 dvide_conqure(new_size,temp_left,temp_right,p7);

	vector<vector<long long> > m1(new_size,inner),m2(new_size,inner),
	m3(new_size,inner),m4(new_size,inner);

	
	// m1 = p5+p4-p2+p6
	add(p5,p4,temp_left);
	subtract(temp_left,p2,temp_right);
	add(temp_right,p6,m1);

	// m2 = p1+p2
	add(p1,p2,m2);
	
	//m3 = p3+p4
	add(p3,p4,m3);

	//m4 = p1+p5-p3-p7
	add(p1,p5,temp_left);
	subtract(temp_left,p3,temp_right);
	subtract(temp_right,p7,m4);
	 

	for(long long i = 0 ; i < size/2 ; i++){
		for(long long j = 0 ; j < size/2 ; j++){
			c[i][j] = m1[i][j];
			c[i][j+size/2] = m2[i][j];
			c[i+size/2][j] = m3[i][j];
			c[i+size/2][j+size/2] = m4[i][j];
		}
	}
}


int
main(int argc , char *argv[]){

	long long n;
	for(int k = 1 ; k  < argc ; k++){
		
		freopen(argv[k],"r",stdin);

		cin >> n;
		vector<vector<long long> > mat(n, vector<long long> (n));
		for(long long i = 0 ; i < n ; i++){
			for(long long j = 0 ; j < n ; j++){
				cin >> mat[i][j];
			}


		}
		fclose(stdin);

		struct timeval start,stop ; 

		vector<vector<long long> > res(n,vector<long long> (n));

		// calc time
		gettimeofday(&start, NULL); //start checking time

		dvide_conqure(n,mat,mat,res);

		gettimeofday(&stop, NULL); //start checking time
		//  end calc time

		
		printf("Microseconds taken: %lu\n", stop.tv_usec - start.tv_usec);
	    printf("Seconds taken %lu\n", stop.tv_sec - start.tv_sec);
	    printf("-----------------------------------------------------\n");
	}
	//print_mat(res);
}