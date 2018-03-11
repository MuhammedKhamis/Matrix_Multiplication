#include <bits/stdc++.h>
#define SIZE 512
using namespace std;

int
main(int argc, char *argv[]){

	char file_num  = 0;
	char file_name[] = "a0.txt";	
	for(int i = 2 ; i < SIZE ; i*=2){
		file_name[1] = ('0'+file_num);
		file_num++;
		freopen(file_name, "w" , stdout);
		
		int counter = 0;
		
		cout << "row=" << i << " col=" << i << endl;
		
		for(int j = 0 ; j < i ; j++){
			for(int k = 0 ; k < i ; k++){
				cout << counter++ << " ";
			}
			cout << endl;
		}
		
		fclose(stdout);
	}

}