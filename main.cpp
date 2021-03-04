#include <iostream>

int* findX(int list[], int length, int x);

int main() {
    int x = 4, length = 8;
    int listOne[] = {1,3,7,4,2,0,6,5};
    int* returnList = findX(listOne, length, x);
    if(returnList[0] == x) {
        std::cout << x << " was found in list ";
        for(int z = 0; z < length; z++){
            std::cout << listOne[z] << ' ';
        }
        std::cout << '\n';
    }

    //Trying findX on a longer list
    length = 16;
    int listTwo[] = {8,6,7,5,3,0,9,11,13,17,4,2,15,10,12,1};
    returnList = findX(listTwo, length, x);
    if(returnList[0] == x) {
        std::cout << x << " was found in list ";
        for(int z = 0; z < length; z++){
            std::cout << listTwo[z] << ' ';
        }
    }

    return 0;
}

//This function finds a "mystery number" x in a list
//If the number is not found, the very last number of the list will be returned
int* findX(int list[], int length, int x){
    //If the list has 1 or 0 elements, simply return the list
    if(length < 2){
        return list;
    } else {
        //Otherwise, split the list in half
        int half = length/2;
        int L1[half];
        int L2[length-half];
        int* resL1;
        //Fill L1
        for(int x = 0; x < half; x++) {
            L1[x] = list[x];
        }

        //Fill L2
        for(int y = half; y < length; y++){
            L2[y-half] = list[y];
        }

        //Check if x is in L1
        resL1 = findX(L1, half, x);
        if(resL1[0] == x){
            //If it is, simply return the one element list returned by L1
            return resL1;
        } else {
            //Otherwise, check L2 for the element
            return findX(L2, length-half,x);
        }
    }
    return list;
}