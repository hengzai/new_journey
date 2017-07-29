#include<iostream>
#include<cstdio>
#include<queue>

class my_stack{
public:
	my_stack(){};
	~my_stack(){};

	int pop(){
		int num = 0;
		if(!first.empty()){
			while(first.size() != 1){
				num = first.front();
				first.pop();
				second.push(num);
			}
			num = first.front();
			first.pop();
			return num;	
		}
		else{
			while(second.size() != 1){
				num = second.front();
				second.pop();
				first.push(num);
			}
			num = second.front();
			second.pop();
			return num;
		}
	}
	void push(int num){
		if(!first.empty()){
			first.push(num);
		}
		else{
			second.push(num);
		}
	}
private:
	std::queue<int> first;
	std::queue<int> second;
};

int main(){
	my_stack sta;
	sta.push(1);
	sta.push(2);
	sta.push(3);
	std::cout<<     sta.pop();
	sta.push(4);
	std::cout<<     sta.pop();
	std::cout<<     sta.pop();
	std::cout<<     sta.pop();

	return 0;
}
