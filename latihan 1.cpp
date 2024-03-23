#include <iostream>
using namespace std;

class Stack{
	
	public:
		int size = 0;
		int top = -1;
		char *items;
		
		Stack(int stackSize){
			size = stackSize;
			items = new char[size];	
		}
		
		void push (char item){
			if (top == size-1)
				cout << "stack Overflow" << endl;
			else {
				top++;
				items [top] = item;
			}
		}
		
		char pop(){
			char item;
			if (top==-1)
			cout << "stack is empty";
			else {
				item = item = items[top];
				top--;
			}
			
			return item;
		}
};

int main(int argc, char** argv) {
	
	Stack a(5);
	
	a.push('D');
	a.push('E');
	a.push('F');
	a.push('G');
	a.push('H');
	a.push('I');
	
	cout << a.pop() <<endl;
	cout << a.pop() <<endl;
	cout << a.pop() <<endl;
	cout << a.pop() <<endl;
	cout << a.pop() <<endl;
	cout << a.pop() <<endl;


	
	return 0;
}