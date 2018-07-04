#include <cstdio>
#include <cstring>
#define MAXLEN 10000

void print(char sum[MAXLEN]){
	for(int i = strlen(sum)-1; i >= 0; i--)
		putchar(sum[i]);
	return;
}

void bigger(char curSum[MAXLEN], char lastSum[MAXLEN], int curNum){
	int lastLen = strlen(lastSum);
	strcpy(curSum, lastSum);
	int i;
	int addEnd = 0;
	for(i = 0; i < lastLen; i++)
		curNum -= (lastSum[i] - '0');
	for(i = 0; curNum > 0; i++){
		if (i < lastLen){
			if (curNum - (9 - (lastSum[i] - '0')) >= 0){
				curSum[i] = '9';
				curNum -= (9 - (lastSum[i] - '0'));
			}
			else{
				curSum[i] += curNum;
				curNum = 0;
			}
		}
		else{
			if (curNum - 9 >= 0){
				curSum[i] = '9';
				curNum -= 9;
			}
			else{
				curSum[i] = curNum + '0';
				curNum = 0;
			}
			addEnd = 1;
		}
	}
	if(addEnd)
		curSum[i] = '\0';
	print(curSum);
	return;
}

void smaller(char curSum[MAXLEN], char lastSum[MAXLEN], int curNum){
	int lastLen = strlen(lastSum);
	int i;
	for(i = lastLen - 1; i >= 0; i--){
		if (curNum - (lastSum[i] - '0') > 0){
			curSum[i] = lastSum[i];
			curNum -= (lastSum[i] - '0');
		}
		else{
			if (i == lastLen - 1){
				curSum[i+1] = '1';
				curSum[i+2] = '\0';
				lastLen++;
			}
			else{
				curSum[i+1]++;
			}/*need to be modified*/
			curNum--; 
			break;
		}
	}
	while(i >= 0){
		curSum[i] = '0';
		i--;
	}
	
	for(i = 0; curSum[i] != '\0'; i++){
		if(curSum[i] == ':'){
			curSum[i] = '0';
			curNum += 9;
			if (i == lastLen-1){
				curSum[i+1] = '1';
				curSum[i+2] = '\0';
			}
			else{
				curSum[i+1]++;

			}
		}
	}

	for(i = 0; curNum > 0; i++){
		if (curNum - 9 >= 0){
			curSum[i] = '9';
			curNum -= 9;
		}
		else{
			curSum[i] = curNum + '0';
			curNum = 0;
		}
	}
	

	print(curSum);
	return;
}

int main(void){
	int T;
	scanf("%d", &T);
	
	while(T--){
		char lastSum[MAXLEN], curSum[MAXLEN];
		strcpy(lastSum, "0");
		int lastNum = 0, curNum, n;
		scanf("%d", &n);
		while(n--){
			scanf("%d", &curNum);
			if (curNum > lastNum){
				bigger(curSum, lastSum, curNum);
			}
			else{
				smaller(curSum, lastSum, curNum);
			}
			printf("%c", (n == 0)? '\n': ' ');
			strcpy(lastSum, curSum);
			lastNum = curNum;
		}
	}
	return 0;
}
