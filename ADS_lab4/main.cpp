#include <queue>
#include <stack>
#include "src/stackArray.hpp"
#include "src/stackList.hpp"
#include "src/queueArray.hpp"
#include "src/queueList.hpp"
using namespace std;

int main() {
	queue<int> myQueue;
	myQueue.push(1);
    myQueue.push(2);
    cout << "Queue: ";
	while (!myQueue.empty()) {
		cout << ' ' << myQueue.front();
		myQueue.pop();
	}
	cout<<endl;

    stack<int> myStack;
    myStack.push(1);
    myStack.push(2);
    cout << "Stack: ";
	while (!myStack.empty()) {
    	cout << ' ' << myStack.top();
    	myStack.pop();
	   }
	cout<<endl;
    return 0;
}
