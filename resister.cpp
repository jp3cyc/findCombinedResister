#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cmath>
using namespace std;

double E24[24] = {1,1.1,1.2,1.3,1.5,1.6,1.8,2.0,2.2,2.4,2.7,3.0,3.3,3.6,3.9,4.3,4.7,5.1,5.6,6.2,6.8,7.5,8.2,9.1};

double parallelCombinedResitance(double resister1, double resister2){

  return resister1 * resister2 /(resister1 + resister2);

}

int main(int argc, char const *argv[]) {

  double wantValue = 1500;
  double temp;
  double resi1=E24[0],resi2=E24[0];
  double value = parallelCombinedResitance(E24[0],E24[0]);

  if(argc == 1){
    printf("Input the number that you are want in argument.\n");
    return 1;
  }

  wantValue = (double) atoi(argv[1]);		// substitution variable for argument.

  for(int i=0; i<24; i++){							// value of R1
    for(int j=0; j<24; j++){						// value of R2
      for(int k=0; k<5; k++){						// exp. of R1
        for(int l=0; l<5; l++){					// exp. of R2

          temp = parallelCombinedResitance( E24[i]*(double) pow(10,k), E24[j]*(double) pow(10,l));

          if(abs(wantValue - value) > abs(wantValue - temp)){		// if the tolerance decreases, 
            value = temp;
            resi1 = E24[i]*(double) pow(10,k);
            resi2 = E24[j]*(double) pow(10,l);
          }
        }
      }


    }
  }

  printf("%f//%f=\n", resi1, resi2);		// Output calcurated value
  printf("%f\n", value);
  printf("Range of tolerance：%f~%f\n",parallelCombinedResitance(resi1*0.95,resi2*0.95),parallelCombinedResitance(resi1*1.05,resi2*1.05));

	return 0;

}

