#include <bits/stdc++.h>
#define SIZE 128
using namespace std;

int
main(int argc, char *argv[]){

	freopen(argv[1] , "w" , stdout);

	int counter = 0;
	cout << SIZE << endl;
	for(int i = 0 ; i < SIZE ; i++){
		for(int j = 0 ; j < SIZE ; j++){
			cout << counter++ << " ";
		}
		cout << endl;
	}

	fclose(stdout);

}