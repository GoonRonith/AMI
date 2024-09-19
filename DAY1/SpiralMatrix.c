#include<stdio.h>
const int M = 3;

void printSpriral(int row,int col,int matrix[row][col],int left,int top,int bottom,int right,int direction){
    if(left>right && top>bottom) return;
    if(direction==0){
            for(int i=left;i<=right;i++){
                printf("\t%d",matrix[top][i]);
            }
            top++;
        }
    else if (direction==1)
        {
            for(int i=top;i<=bottom;i++){
                printf("\t%d",matrix[i][right]);
            }
            right--;  
        }
    else if(direction==2){
            for(int i=right;i>=left;i--){
                printf("\t%d",matrix[bottom][i]);
            }
            bottom--; 
        }
    else{
            for(int i=bottom;i>=top;i--){
                printf("\t%d",matrix[i][left]);
            }
            left++;    
        }
        direction=(direction+1)%4;
     printSpriral(row,col,matrix,left,top,bottom,right,direction);
}

int main(){
    int matrix[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    
    int row=3;
    int col=3;
    int left=0;
    int top=0;
    int bottom=row-1;
    int right=col-1;
    int direction=0;
    //iterative approach
    // while (left<=right && top<=bottom)
    // {
    //     if(direction==0){
    //         for(int i=left;i<=right;i++){
    //             printf("\t%d",matrix[top][i]);
    //         }
    //         top++;
    //     }
    //     else if (direction==1)
    //     {
    //         for(int i=top;i<=bottom;i++){
    //             printf("\t%d",matrix[i][right]);
    //         }
    //         right--;  
    //     }
    //     else if(direction==2){
    //         for(int i=right;i>=left;i--){
    //             printf("\t%d",matrix[bottom][i]);
    //         }
    //         bottom--; 
    //     }
    //     else{
    //         for(int i=bottom;i>=top;i--){
    //             printf("\t%d",matrix[i][left]);
    //         }
    //         left++;    
    //     }
    //     direction=(direction+1)%4;
        // direction++;
        // if(direction==4) direction=0;
        // printf("\ndir->%d",direction);
    // }
    printSpriral(row,col,matrix,left,top,bottom,right,direction);

}