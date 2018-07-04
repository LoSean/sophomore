#include <stdio.h>

long long countLucky(long long num, long long lucky[19][7][19][19], int *self){
	long long origin = num;
	long long sum = 0;
	int luckyIndex = 3, dIndex = 1, digits = 1;
	long long mask = 1, mSigDig = 0;
	while((num / mask)/10){
		mask *= 10;
		digits++;
	}
#ifdef DEBUG
	printf("num : %lld mask : %lld digits : %d\n", num, mask, digits);
#endif
	while(digits > luckyIndex && digits > 1){
		for(int i = 0; i < num / mask; i++){
			int luckyTmp = luckyIndex;
			int dTmp = dIndex;
			if(i == 7){
				if(luckyIndex > 0){
					luckyTmp--;
				}
				dTmp--;
			}
			if(i == 4){
				dTmp++;
			}
			long long index = ((mSigDig * 10 + i) * mask % 7)? (7 - (mSigDig * 10 + i) * mask % 7): 0;
#ifdef DEBUG
			printf("i : %d mask : %lld\n", i, mask);
			printf("msigDig * 10 + i : %lld\n", mSigDig * 10 + i);
			printf("luckyTmp : %d\n", luckyTmp);
#endif
			for(int j = luckyTmp; j <= digits-1; j++){
				int endk = ((digits-1 - j) < (j - dIndex))? (digits-1 - j): (j - dIndex);
				for(int k = 0; k <= endk; k++){
#ifdef DEBUG
					printf("(%d, %d)\n", j, k);
					printf("sum : %lld\n", sum);
#endif
					sum += lucky[digits-1][index][j][k];
				}
			}
		}
		if(num / mask == 7){
			if(luckyIndex > 0){
				luckyIndex--;
			}
			dIndex--;
		}
		else if(num / mask == 4){
			dIndex++;
		}

		mSigDig = origin / mask;
		num %= mask;
		mask /= 10;
		digits--;
	}


	if(luckyIndex == 0){
		if(origin % 7 == 0)
			*self = 1; 
		while(origin % 10 != 0){
			if(origin % 7 == 0)
				sum++;
			origin--;
		}
		if((origin % 7) == 0){
#ifdef DEBUG
			printf("[] origin : %lld\n", origin);
#endif
			sum++;
		}
	}
	int stop = 0;
	if(luckyIndex > 0 && !(origin % 7)){
		stop = 1;
		while(num >= 0 && mask > 0 && stop){
			if(num / mask != 7){
				stop = 0; 
			}
			num %= mask;
			mask /= 10;
		}
	}
	if(stop){
#ifdef DEBUG
		printf("[stop] origin : %lld\n", origin);
#endif
		sum++;
		*self = 1;
	}

	return sum;
}

int main(void){
	long long base[2][2] = {0};
	long long lucky[19][7][19][19] = {{{{0}}}};
	lucky[0][0][0][0] = 1; 
	for(int i = 0; i <= 17; i++)
		for(int j = 0; j < 7; j++)
			for(int k = 0; k < 10; k++)
				for(int l = 0; l <= i+1; l++)
					for(int m = 0; m <= i+1 - l; m++){
						if(k != 7 && k != 4)
							lucky[i+1][(j * 10 + k) % 7][l][m] += lucky[i][j][l][m];
						else if(k == 7)
							lucky[i+1][(j * 10 + k) % 7][l+1][m] += lucky[i][j][l][m];
						else
							lucky[i+1][(j * 10 + k) % 7][l][m+1] += lucky[i][j][l][m];
					}

#ifdef DEBUG
	for(int i = 0; i <= 18; i++)
		for(int j = 0; j < 7; j++){
			printf("layer(%d) mod %d\n", i, j);
			for(int l = 0; l <= i; l++)
				for(int m = 0; m <= i; m++)
					printf("%lld%c", lucky[i][j][l][m], (m == i)? '\n': ' ');
			putchar('\n');
		}
#endif

	int n;
	scanf("%d", &n);
	while(n--){
		long long low, high;
		scanf("%lld%lld", &low, &high);
		int self = 0, self2;
//		printf("low count : %lld\n", countLucky(high, lucky, &self));
//		printf("high count : %lld\n", countLucky(low, lucky, &self));
		long long sum = countLucky(high, lucky, &self2) - countLucky(low, lucky, &self);
		if(self)
			sum++;
		printf("%lld\n", sum);
	}
	return 0;
}