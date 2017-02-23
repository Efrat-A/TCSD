#include <stdio.h>

#include <stdlib.h>
#include <stdbool.h>

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

void printboard(int arr[][9], int n){
	printf("~~~~ Board ~~~~~~\n");
	for (int i=0; i <9; ++i){
	   for(int j=0; j<9; ++j )
	   	printf("%d ",arr[i][j]);
	   printf("\n");
	}
	printf("~~~~~~~~~~~~~~~~~\n");
}


int check(int a[][9],int row, int number){
	for (int i=0; i < 9; ++i){
		if(a[row][i] == number ){
			return false;
	}	}
	return true;
}
bool solve(int arr[][9],int row,int col, int n) {
	if ( row == n) {
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
	arr[row][col]=0;
	return false;
}




void main (){
	printf("~~~~ Game On ~~~~\n");
	int board[9][9] = {
                        {7,1,0,0,0,0,6,0,9},
                        {2,0,0,0,0,3,0,0,0},
                        {0,0,0,1,5,0,0,0,8},
                        {0,0,7,0,0,0,0,9,0},
                        {0,0,6,0,0,0,7,0,0},
                        {0,2,0,0,0,0,4,0,0},
                        {1,0,0,0,2,9,0,0,0},
                        {0,0,0,3,0,0,0,0,4},
                        {9,0,5,0,0,0,0,8,6}
                    };

//	printf (" -/-*/-*/-*/   %s   -**/--" , validate( board, 0, 9 ) ? "true" :"false" );
	printboard(board,0);
	printf(" %s \n\n",solve(board,0,0,9) ? "Solution Found":"No solution" );
	printboard(board,0);
}
