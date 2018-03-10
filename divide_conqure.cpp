#include <bits/stdc++.h>
#include <sys/time.h>

using namespace std;


vector<vector<int> >
multiply(vector<vector<int> > a , vector<vector<int> > b){
	vector<vector<int> > c;
	
	int wid = 2;

	int hig = 2;
	
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

vector<vector<int> >
add(vector<vector<int> > a, vector<vector<int> > b){
	vector<vector<int> > c;

	for(int i = 0 ; i < a.size() ; i++){
		vector<int> row;
		for(int j = 0 ; j < a[i].size() ; j++){
			row.push_back(a[i][j]+b[i][j]);
		}
		c.push_back(row);
	}
	return c;
}

vector<vector<int> >
subtract(vector<vector<int> > a, vector<vector<int> > b){
	vector<vector<int> > c;

	for(int i = 0 ; i < a.size() ; i++){
		vector<int> row;
		for(int j = 0 ; j < a[i].size() ; j++){
			row.push_back(a[i][j]-b[i][j]);
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

vector<vector<int> >
dvide_conqure(int size, vector<vector<int> > a, vector<vector<int> > b){
	vector<vector<int> > c;

	if(size == 2){
		return multiply(a,b);
	}
	vector<vector<int > > a11,a12,a21,a22,b11,b12,b21,b22;

	for(int i = 0 ; i < size/2 ; i++){
		vector<int> row_a1,row_a2,row_a3,row_a4,row_b1,row_b2,row_b3,row_b4;
		for(int j = 0 ; j < size/2 ; j++){
			row_a1.push_back(a[i][j]);
			row_a2.push_back(a[i][j+size/2]);
			row_a3.push_back(a[i+size/2][j]);
			row_a4.push_back(a[i+size/2][j+size/2]);

			row_b1.push_back(b[i][j]);
			row_b2.push_back(b[i][j+size/2]);
			row_b3.push_back(b[i+size/2][j]);
			row_b4.push_back(b[i+size/2][j+size/2]);
		}
		a11.push_back(row_a1);
		a12.push_back(row_a2);
		a21.push_back(row_a3);
		a22.push_back(row_a4);

		b11.push_back(row_b1);
		b12.push_back(row_b2);
		b21.push_back(row_b3);
		b22.push_back(row_b4);
	}

	vector<vector<int> > p1,p2,p3,p4,p5,p6,p7;

	p1 = dvide_conqure(size/2,a11,subtract(b12,b22));
	p2 = dvide_conqure(size/2,add(a11,a12),b22);
	p3 = dvide_conqure(size/2,add(a21,a22),b11);
	p4 = dvide_conqure(size/2,a22,subtract(b21,b11));
	p5 = dvide_conqure(size/2,add(a11,a22),add(b11,b22));
	p6 = dvide_conqure(size/2,subtract(a12,a22),add(b21,b22));
	p7 = dvide_conqure(size/2,subtract(a11,a21),add(b11,b12));

	for(int i = 0 ; i < size ; i++){
		c.push_back(vector<int>());
		c[c.size()-1].resize(size);
	}
	vector<vector<int> > m1,m2,m3,m4;

	m1 = add(subtract(add(p5,p4),p2),p6);
	m2 = add(p1,p2);
	m3 = add(p3,p4);
	m4 = subtract(subtract(add(p1,p5),p3),p7);

	for(int i = 0 ; i < size/2 ; i++){
		for(int j = 0 ; j < size/2 ; j++){
			c[i][j] = m1[i][j];
			c[i][j+size/2] = m2[i][j];
			c[i+size/2][j] = m3[i][j];
			c[i+size/2][j+size/2] = m4[i][j];
		}
	}
	return c;
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

	vector<vector<int> > res = dvide_conqure(mat.size(),mat,mat);

	gettimeofday(&stop, NULL); //start checking time
	//  end calc time

	
	printf("Microseconds taken: %lu\n", stop.tv_usec - start.tv_usec);
    printf("Seconds taken %lu\n", stop.tv_sec - start.tv_sec);
    printf("-----------------------------------------------------\n");

	//print_mat(res);
}