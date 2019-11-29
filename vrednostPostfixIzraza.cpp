#include <iostream>
#include <stack>

using namespace std;

int primeniOp(int op1, int op2, char c)
{
	int v;
	if(c=='+') v=op1+op2;
	if(c=='*') v=op1*op2;
	
	return v;
}

int main()
{
	string izraz;
	cin >> izraz;
	
	stack<int> br;
	
	for(char c : izraz){
		if(isdigit(c))
			br.push(c-'0');
		else if(c=='+' || c=='*'){
			int op1 = br.top(); br.pop();
			int op2 = br.top();	br.pop();
			
			br.push(primeniOp(op1, op2, c));
		}
	}
	
	cout << br.top() << endl;
	
	return 0;
}
