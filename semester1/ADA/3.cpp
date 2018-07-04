#include <stdio.h>

long long compare(long long n, long long e, long long p){
	long long k = 1;
	n %= p;
	if(e == 0)
		return(1);
	while(e > 0 && e != 1){
		if((e & 1) == 1)
			k = (k * n) % p;
		n = (n * n) % p;
		e >>= 1;
	}
	return ((k * n) % p);
}

void merge(long long array[200010], int start, int mid, int end, long long c, long long p,
		long long power[400010], long long minus[200000]){
	int tmp[end-start+2];
	int i = start, j = mid+1, k = 1;
	while(i < mid + 1 && j < end + 1){
		long long m = array[i] - array[j];
		if(array[i] < array[j])
			m = minus[-m];
		if(((c * m) % p * (power[array[i]+array[j]])) % p > p/2){
			tmp[k] = array[i];
			i++;
		}
		else{
			tmp[k] = array[j];
			j++;
		}
		k++;
	}
	while(i < mid + 1){
		tmp[k] = array[i];
		i++; k++;
	}
	while(j < end + 1){
		tmp[k] = array[j];
		j++; k++;
	}
	for(int l = 1; l < k; l++)
		array[start - 1 + l] = tmp[l];
}

void sort(long long array[200010], int start, int end, long long c, long long p,
		long long power[400010], long long minus[200000]){	
	if(start != end){
		int mid = (start + end) / 2;
		sort(array, start, mid, c, p, power, minus);
		sort(array, mid+1, end, c, p, power, minus);
		merge(array, start, mid, end, c, p, power, minus);
	}
	return;
}

int main(void){
	int T;
	scanf("%d", &T);

	while(T--){
		long long e, c, p;
		int n;
		long long array[200010];
		scanf("%d%lld%lld%lld", &n, &c, &e, &p);
		for(int i = 1; i <= n; i++)
			array[i] = i;
		long long power[400010];
		long long minus[200000];
		int prime[100000];
		int count = 0;
		minus[1] = p - 1;
		for(int i = 2; i < 2*n; i++){
			if(i < n)
				minus[i] = p + (-i) % p;
			int flag = 0;
			for(int j = 0; j < count && prime[j] * prime[j] <= i; j++){
				if(i % prime[j] == 0){		
					power[i] = (power[prime[j]] * power[i/prime[j]]) % p;
					flag = 1;
					break;
				}
			}
			if(!flag){
				power[i] = compare(i, e, p);
				if(i < 440){
					prime[count] = i;
					count++;
				}
			}	
		}
		sort(array, 1, n, c, p, power, minus);
		for(int i = 1; i < n; i++)
			printf("%lld ", array[i]);
		printf("%lld\n", array[n]);
	}
	return 0;
}
