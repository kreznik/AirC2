#include <stdio.h>
//#include <fstream>
#include <math.h>
#define samplelenth 16384//для длины в 16кб 
#define PI 3.14



//int len;
float freq;//частота волны
float amp;//амплитуда
float dfreq;
int buff[samplelenth];// память зарезервирована
int *buffer = buff;


int sine_gen(float amp, float freq, float dfreq, int len, int *buffer);
int triagle_gen(float amp, float freq, float dfreq, int len, int *buffer);
void enterData();


int main(){


	printf("Hello!\n");
	printf("Choose a wave type you want to generate: \n");
	printf("0. sine, 1. triagle, 2. mix them \n");
	int waveType;
	scanf("%d", &waveType);
	switch(waveType){

		case 0:
		enterData(); 
		sine_gen(amp, freq, dfreq, samplelenth, buffer);
		break;

		case 1:
		enterData(); 
		triagle_gen(amp, freq, dfreq, samplelenth, buffer);
		break;

		case 2:
		printf("Nothing here yet\n");
		break;

	}
}

int sine_gen(float amp, float freq, float dfreq, int len, int *buffer){

	float temp = 2.0 * PI * freq / dfreq;
	float cos = amp;
	float sin = 0.0;
	buffer[0] = sin;

	for (int i=1; i<len; i++)
	{
		sin += temp * cos;
		cos -= temp * sin;
		buffer[i] = 0.5 + sin;

	}
	return 0;
}


int triagle_gen(float amp, float freq, float dfreq, int len, int *buffer){

	int tempf = 0.5 + dfreq/freq;
	int tempf2 = 0.5 + dfreq/(2 * freq);
	float tempa = 4 *amp * freq / dfreq;
	int counter = 0.5 + tempf / 4;
	float t;
	amp = -amp;
	buffer[0] = 0;
	t = 0;

	for (int i =1; i < len; i++, counter++){

		if(counter < tempf2){
			t += tempa;
			buffer[i] = 0.5 +t;
		}
		else{
			if(counter > tempf){
				counter = 0;
				t = 0;
				buffer[i] = amp;
			}
			else{
				t -=tempa;
				buffer[i] = 0.5 + t;
			}
		}
	}
	return 0;


}
void enterData(){

	printf("Enter amplitude: \n");
	scanf("%f", &amp);

	printf("Enter frequency: \n");
	scanf("%f", &freq);

	printf("Enter discrete frequency: \n");
	scanf("%f", &dfreq);
}
