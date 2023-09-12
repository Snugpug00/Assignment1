/*
Data Structures
Sarah Miller
Assignment 1
source that I used to help me with the assignment: https://www.chegg.com/homework-help/questions-and-answers/write-c-program-read-data-let-s-say-file-10-lines-line-contains-10-integers-file-array-per-q101793627
*/
#include <iostream> // standard input - output stream. This declares objects that control reading from and writing to the standard streams.
#include <fstream> //
using namespace std;

//function to check if a certain integer exists in the array
bool check(int arr[], int size, int num){
  for(int i = 0; i < size; i++){ // initialize for loop and then adding.
    if(arr[i] == num){ // If the number exists then the return statement will be true.
      return true; // returns true if the condition of the for loop is met
    }
  }
  return false; // returns false if the condition is not met
}

//function to modify the value of an integer when called with the index of the integer in the array and return the new value and old value back to the user
void modify(int arr[], int index, int &num, int &old){ // this function is a void function therefore there will be no return value. We have some pointers in here as well.
  old = arr[index]; // old int equals
  arr[index] = num; 
}

//function that adds a new integer to the end of the array
void add(int arr[], int &size, int num){ // void func therefore no return value.
  arr[size++] = num;
}

//function which intakes an index of an array and remove the integer corresponding to that index
void remove(int arr[], int &size, int index){
  for(int i = index; i < size; i++){
    arr[i] = arr[i+1];
  }
  size--;
}

int main(){
  // File name
  string fileName = "data.txt"; // text file that contains array
  int arr[1000]; // Array
  int size = 0; // initializes

  ifstream inputFile; // How we open File
  inputFile.open(fileName.c_str());
  if (!inputFile) // If File cannot open then the following if statement will be executed.
  {
    cout << "Unable to open file" << endl;
    exit(1);
  }
  int num;
  while (inputFile >> num)
  {
    arr[size++] = num;
  }
  inputFile.close();

  //check if a certain integer exists in the array if the number is present return the index where the number is present
  cout<<"Enter a number to check if it exists in the array: ";
  cin >> num;
  if(check(arr, size, num)){ // If statement that checks the array, how large the size is and the number
    cout<<"The number exists in the array"<<endl;
  }else{
    cout<<"The number does not exist in the array"<<endl;
  }

  //A function to modify the value of an integer when called with the index of the integer in the array and return the new value and old value back to the user
  int index, newNum, oldNum;
  cout<<"Enter the index of the number you want to modify: ";
  cin >> index; // user enters in number they want to modify
  cout<<"Enter the new number: ";
  cin >> newNum; // user input 
  modify(arr, index, newNum, oldNum); // function that modifies the array, index, swaps the old with new num.
  cout<<"The old number was "<<oldNum<<" and the new number is "<<newNum<<endl;

  //A function that adds a new integer to the end of the array
  cout<<"Enter a number to add to the array: ";
  cin >> num; // user inputs new number
  add(arr, size, num); // function that adds number to array
  cout<<"The new array is: ";
  for(int i = 0; i < size; i++){ // for loop that adds new number to array
    cout<<arr[i]<<" "; // displays the array with new number.
  }
  cout<<endl;

  //A function which intakes an index of an array and remove the integer corresponding to that index
  cout<<"Enter the index of the number you want to remove: ";
  cin >> index; // user input of what they want to remove.
  remove(arr, size, index); // fucntion that removes integer from array and index.
  cout<<"The new array is: ";
  for(int i = 0; i < size; i++){ // for loop displays new array with the removed index.
    cout<<arr[i]<<" ";
  }
  return 0;
}