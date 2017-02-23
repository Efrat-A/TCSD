#include <stdio.h>

#include <stdlib.h>
#include <stdbool.h>
#define N 1000

bool check(int x){
	return x>=1 && x<=N;
}
/*
// check FULL row !
bool validate(int arr[][9],int row, int n){
	for (int i=0; i < n; ++i){
		int num = arr[row][i];
         	for(int j=0; j<n; ++j ) { // check if num apear in col 
			 if (num == arr[j][i] && j!=row && arr[j][i] != 0){
//				printf("****(%d,%d) %d==%d \n", i,j, arr[j][i],num);
			 	return false;
		 	}
	 	}
        	for(int j=i+1; j<n; ++j ) {
			if (num == arr[row][j]) {
				return false;
	        	}   	
	        }
	  }
   	return true;
}
*/
void printboard(char arr[][5], int r, int c){
	printf("~~~~ Board ~~~~~~\n");
	for (int i=0; i <r; ++i){
	   for(int j=0; j<c; ++j )
	   	printf("%c ",arr[i][j]);
	   printf("\n");
	}
	printf("~~~~~~~~~~~~~~~~~\n");
}

int getn(char arr[][5],int rs,int cs, int* tomatos, int* mushrooms) {
	if (!tomatos|| !mushrooms) return 0;
	*tomatos =0; *mushrooms =0;
	for( int i=0; i < rs; ++i ){
		for( int j=0; j < cs; ++j ){
			if(arr[i][j] == 'T') *tomatos +=1;
			if(arr[i][j] == 'M') *mushrooms +=1;
	}}
	return *mushrooms + *tomatos ;
}

bool solve(char arr[][5],int row,int col, int least, int h) {
	if (

/*	if ( row == n) {
		return validate( arr, row-1, n );
	}
	if( col== n ){
		if(validate( arr, row, n))
	 		return solve(arr,row+1,0,n);
	 	return false;
	}
	if ( arr[row][col] != 0 )
			return solve(arr,row,col+1,n);
	for( int i=1; i <= n; ++i ){
		if (check(arr,row,i) ) {
			arr[row][col] = i;
			if ( solve (arr,row,col+1,n) == true ){
				return true;
			}
		}
	}
	arr[row][col]=0;*/
	return false;
}

int getCombinations(int least, int h , int* ndown[2]){
	int n=0;
	for( int i=1; i < h ; ++i )
		for (int j=1; i*j <=h ; ++j )
			if( 2*least <= i*j ){
				if( ndown ) { ndown[0][n]=i; ndown[1][n]=j; }
	  			printf(" %d X %d \n",i,j );
	  			n++;
	  		}
	return n;
}

void main (){
	int r,c,l,h;
	r=3; // rows
	c=5; //colums
	l=1; //min l in each slice
	h=6; // max cells in slice
	if( check(h) && check(r) && check(c) && check(l) ){
	char piza[3][5] = {
                        {'T','T','T','T','T'},
                        {'T','M','M','M','T'},
                        {'T','T','T','T','T'}
                    };
	int* steps[2];
//	printf (" -/-*/-*/-*/   %s   -**/--" , validate( board, 0, 9 ) ? "true" :"false" );
	printboard(piza,3,5);
	
//	printf(" %s \n\n",solve(board,0,0,9) ? "Solution Found":"No solution" );
	int tomatos, mushrooms;
	getn(piza,r,c, &tomatos, &mushrooms) ;
	printf("tomatos %d, mushrooms %d\n" ,  tomatos, mushrooms);

	int n = getCombinations(l,h ,0);
	steps[0] = malloc(sizeof(int)*n); //step[0] -step right / step[1] - step down
	steps[1] = malloc(sizeof(int)*n);
	getCombinations(l,h ,steps);
//	for( int i=0;i<n;++i) printf("(%dx%d)",steps[0][i],steps[1][i]);

	solve(piza,r,c,l,h);



	}
}
