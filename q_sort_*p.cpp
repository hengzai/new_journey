#include<iostream>
#include<cstdio>

int partition(int *p,int low,int high){
	if(p == nullptr){
		printf("error\n");
		return -1;
	}

	int tmp = *(p + low);
	while(low < high){
		while(tmp <= *(p + high) && low < high){
			high--;
		}
		*(p + low) = *(p + high);
		while(tmp >= *(p + low) && low < high){
			low++;
		}
		*(p + high) = *(p + low);
	}
	*(p + low) = tmp;
	return low;
}

void q_sort(int *p,int low,int high){
	if(p == nullptr){
		return ;
	}

	if(low < high){
		int key = pation(p,low,high);
		q_sort(p,low,key-1);
		q_sort(p,key+1,high);
	}
	return ;
}

int main(){
	int buff[10] = {5,6,2,8,0,4,1,3,4,9};
	q_sort(buff,0,sizeof(buff)/sizeof(int)-1);
	for(auto e : buff){
		printf("%d\n",e);
	}
}
