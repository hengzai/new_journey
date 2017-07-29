#include<iostream>
#include<cstdio>
#include<stack>

class my_queue{
public:
	my_queue(){};

	int pop(){
		int num = 0;
		if(second_stack.empty() && first_stack.empty()){
			std::cout<<"队列为空"<<std::endl;
			return -1;
		}
		if(!second_stack.empty()){
			num = second_stack.top();
			second_stack.pop();
			return num;
		}
		else{
			while(!first_stack.empty()){
				num = first_stack.top();
				first_stack.pop();
				second_stack.push(num);
			}
			num = second_stack.top();
			second_stack.pop();
			return num;
		}
	}

	void push(int num){
		first_stack.push(num);
	}

private:
	std::stack<int> first_stack;
	std::stack<int> second_stack;
};

int main(){
	my_queue que;
	que.push(1);
	que.push(2);
	que.push(3);
	std::cout<<que.pop();
	que.push(4);
	que.push(5);
	std::cout<<que.pop();
	que.push(6);
	std::cout<<que.pop();
	std::cout<<que.pop();
	std::cout<<que.pop();
	std::cout<<que.pop();

	return 0;
}
