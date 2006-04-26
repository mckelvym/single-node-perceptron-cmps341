// Class    : CMPS 341
// Section  : 001
// Problem  : Single-Node Perceptron Program
// Name     : McKelvy, James Markus
// CLID     : jmm0468

#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

// used to make rand() a decimal number
const float largevalue = 32768;

// get the input of vector p and target value t
void getInput(float p[], int &target, int elements);
// used to calculate the net input
float calculate_n(float w[], float p[], float b, int elements);
// for output of node
int transfer_function(float n);
// used to train the weights vector
void train(float w[], float p[], float b, int elements, float target_output, float actual_output); 
// helpful for debugging
void print_weights_and_bias(float w[], float b, int elements);

int main(){
  // represents the number of inputs of the input vector
  // and also the number of weight terms
  int elements = 0;
  int target;// represents the target value of an input vector
  float * w; // represents the weight vector
  float * p; // represents the p vector
  float b;   // represents the bias term
  // seed the random number generator with the time function
  srand((unsigned)time(NULL));
  int choice = 0; 
  
  cout << "Class    : CMPS 341\n";
  cout << "Section  : 001\n";
  cout << "Problem  : Single-Node Perceptron Program\n";
  cout << "Name     : McKelvy, James Markus\n";
  cout << "CLID     : jmm0468\n\n";
  cout << "Welcome to the Single-Node Perceptron Program.\n";
  // get the number of terms in the p vector
  do{
    cout << "\nHow many terms will be in the p vector? ";
    cin >> elements;
  }while(elements < 1);
  w = new float[elements];
  p = new float[elements];
  
  // assign random weights and a random bias term
  for(int x = 0; x < elements; x++)
    w[x] = rand() / largevalue;
  b = rand() / largevalue;
  
  while(choice != 4){
    cout << "\nSingle-Node Perceptron Program: Main Menu\n";
    cout << "\n1. Train Network";
    cout << "\n2. Test Network";
    cout << "\n3. Print Weights and Bias Terms";
    cout << "\n4. Exit";
    cout << "\n\nYour choice? ";
    cin >> choice;
    if(choice == 1){
      // get the input vector and target value, as well as the number of elements
      getInput(p, target, elements);
      // train the network
      train(w, p, b, elements, (float)target, calculate_n(w, p, b, elements));
    }
    else if(choice == 2){
      // get the p values
      cout << "\nYou will now be prompted for the values of the p vector.\n";
      for(int x = 0; x < elements; x++){
        cout << "p" << x + 1 << " = ";
        cin >> p[x];
      }
      
      cout << "\nOut of class 0 or 1, the network has decided that the object\n";
      cout << "that you have entered belongs to:\n\nclass ";
      
      if(transfer_function(calculate_n(w, p, b, elements)) == 1)
        cout << "1\n";
      else cout << "0\n";
    }
    else if(choice == 3){
      print_weights_and_bias(w, b, elements);
    }
  }
  
  return 0;
}

void getInput(float p[], int &target, int elements){
  // get the p values
  cout << "\nYou will now be prompted for the values of the p vector.\n";
  for(int x = 0; x < elements; x++){
    cout << "p" << x + 1 << " = ";
    cin >> p[x];
  }
  // get the target value
  do{
   cout << "\nTarget value (must be 0 or 1)? ";
   cin >> target;
  }while(target != 0 && target != 1);  
}


// used to calculate the net input
float calculate_n(float w[], float p[], float b, int elements){
  float n = 0;
  
  for(int x = 0; x < elements; x++){
    n += (w[x] * p[x]);
  }
  n += b;
  
  return n;
}

// for output of node
int transfer_function(float n){
  if(n >= 0.0)
    return 1;
  else return 0;
}

// used to train the weights vector
void train(float w[], float p[], float b, int elements, float target_output, float actual_output){
  float e = target_output - actual_output;
  
  for(int x = 0; x < elements; x++)
    w[x] = w[x] + (e * p[x]);
  b = b + e;
}

// helpful for debugging
void print_weights_and_bias(float w[], float b, int elements){
  cout << "\nThe weights are:";
  for(int x = 0; x < elements; x++)
    cout << "\nw" << x+1 << " = " << w[x];
  cout << "\n\nbias = " << b;
  cout << endl;
}
