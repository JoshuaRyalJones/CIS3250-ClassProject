#include "ShearInYTests.h"
#include "../main.h"

//The following are dirty test cases for group 14

void emptyYShearValue () {

    struct point *point = getPoint(0);
    point = NULL;

    setPoint(0, point);
    setYShear(NULL);
    
    if(getPoint(1) == NULL) {
        printf ("Error: The input value of the y shear is empty\n");
    }
}


//Test Two: The input is out of the range of the matrix/vector
void inputRange () { 
  if(sizeof(inputShape->shearing) > 4){
    printf ("Error: The array value of the y shear is greater than the global array\n");
  }
  else{
    return;
  }
}

//Test Three: The global struct is uninitialized 
void uninitializedStruct() { 
  if (inputShape == NULL){ 
    printf("Error: The struct is not initialized\n"); 
  } 
  else { 
    return; 
  } 
} 

//Test Four: The global function matrixMultiplication() is initialized incorrectly
void uninitializedMatrixMultiplication(){
  void resetMatrix();
  for (int i = 0; i < 4; i++){
      for (int j = 0; j < 4; j++){
          if (i == j){
              if (! (transformationMatrix[i][j] == 1) ) {
                printf ("Matrix did not reset properly.");
                return;
              }
          }
          else{
              if (! (transformationMatrix[i][j] == 0) ) {
                printf ("Matrix did not reset properly.");
                return;
              }
          }
      }
    }
    return;
  }

  //Test Five: The x or z shear values are empty
  void dependentGroupShearValues () {
   float xShear = 5;
    float zShear = 4;

    struct point *point = getPoint(0);
    point = NULL;

    setPoint(0, point);
    setXShear(xShear);
    setZShear(zShear);
    yShear();
    
    if(getPoint(0) == NULL || getPoint(2) == NULL) {
        printf ("Error: The input value of the x or z shear is empty.\n");
        //fprintf(stderr, "nullPointTest Failed: Expected point does not match test point\n");
    }

  }

  //The following is a clean test cases for group 14

  //Test Six: Giving an example vector, check to see whether or not the  yShear() function updated the coordates correctly.

  void correctTest() {

    //the following code is from the yShear() function but will be given dummy values for the purpose of this test:

    float xShearVal = 4;
    //float yShearVal = 8;
    float zShearVal = 12;

    //reset matrix
    resetMatrix();

    //change col 1, row 0
    transformationMatrix [1] [0] = xShearVal;

    //change col 1, row 2
    transformationMatrix [1] [2] =  zShearVal ;

    //multply points by matrix
    struct point* temp;

    for (int i = 0; i < inputShape->numOfPoints; i++) {
      
      temp = getPoint(i);
      
      if (temp == NULL) {
        return;
      }

      multiplyMatrix(temp, transformationMatrix);
      setPoint(i, temp);

    //the correct output should replace transformationMatrix [0] [1] to 4.
    //it should also replace transformationMatrix [2] [1] to 12.

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%f ", transformationMatrix[i][j]);
        }
        printf("\n");
    }
    
  }
}


void runYShearTests () {
  correctTest();
  dependentGroupShearValues();
  uninitializedMatrixMultiplication();
  uninitializedStruct();
  emptyYShearValue();
  inputRange();
}



