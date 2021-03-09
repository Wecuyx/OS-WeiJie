#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int first_fit(int process[10]){
    //Hardcode values for the holes 
    int holes[12] = {160,350,650,80,410,50,720,905,570,130,260,830};
    //Allocation to check if the allocation is being done once found a suitable hole
    int allocation[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
    //Flag to check if the hole is already taken
    int flag[10] = {0,0,0,0,0,0,0,0,0,0};

    for(int i = 0; i < 10; i++){
        for(int h = 0; h < 12; h++){
            if(allocation[h] == 0 && process[i] <= holes[h]){
                    allocation[h] = 1;
                    flag[i] = 1;
                    holes[h] = holes[h] - process[i]; 
                    break;
            }
        }
        //Checking after looping through the holes whether the process found a hole, if not return an error notification message 
        if(flag[i] == 0){
            printf("\nThe input Process with Size %d KB cannot fit into any remaining memory partition. It has to wait for other processes' completion");
        }
    }
    for(int i = 0; i < 12; i++){
        printf("\n%d", holes[i]);
    }
    return 0;
}

int best_fit(int process[10]){
    //Not Finished
    //Hardcode values for the holes 
    int holes[12] = {160,350,650,80,410,50,720,905,570,130,260,830};
    //Allocation to check if the allocation is being done once found a suitable hole
    int allocation[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
    //Flag to check if the hole is already taken
    int flag[10] = {0,0,0,0,0,0,0,0,0,0};
    int lowest = process[9];
    int best;
    int temp;
    for(int i = 0; i < 10; i++){
        for(int h = 0; h < 12; h++){
            if(allocation[h] == 0){
                temp = holes[h] - process[h];
                    if(temp >= 0 && lowest > temp){
                        lowest = temp;
                        best = h;
                        allocation[h] = 1;
                        flag[i] = 1;
                    }
            }
        }
        holes[i] = holes[best] - process[i]; 
        //Checking after looping through the holes whether the process found a hole, if not return an error notification message 
        if(flag[i] == 0){
            printf("\nThe input Process with Size %d KB cannot fit into any remaining memory partition. It has to wait for other processes' completion", process[i]);
        }
    }
    for(int i = 0; i < 12; i++){
        printf("\n%d", holes[i]);
    }
    return 0;
}

int worst_fit(){
    return 0;

}

int main(){
    int input[10];
    char string[100];
    int count = 0;

    printf("Maximum accepted size of input Process: 905KB");
    printf("\nEnter 10 size of input process: ");
    scanf("%s", string);

    char * token = strtok(string, ",");
    while(token!=NULL){
        if(atoi(token) > 905){
            printf("One of the input process is bigger than Maximum accepted size.");
            break;
        }
        else{
            input[count] = atoi(token);
            printf("%s\n", token);
            token = strtok(NULL,",");
            count++;
        }
    }
    first_fit(input);
    best_fit(input);
    worst_fit();




}