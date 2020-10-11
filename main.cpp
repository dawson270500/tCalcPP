#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

/*
	tCalc v1.5
	Written in C++ by Bailey Dawson dawson270500@gmail.com
	Orginally written in Python, V1.0 to V1.2

	A basic terminal calculator
	Report on bugs and code suggestions on the github repo page


	Code reuse allowed, but given credit.
*/

string lastAnswer = "0.0";
string mem = "0.0";
float pi = 3.14159265;

string doCalc(string Input){//Gets the string and coverts into something that is usable by the program, then works that out
	
	if(Input[3] == '('){
		string num;
		for(int i = 4; i < Input.length(); i++){
			if(Input[i] == ')'){
				break;
			} else if(isdigit(Input[i])){//Constructing numbers
				num = num + Input[i];continue;
			} else if(Input[i] == '.'){
				num = num + Input[i];continue;
			} else if(Input[i] == 'p'){
				num = to_string(pi);continue;
			} else if(Input[i] == 'r'){
				num = to_string(rand() % 9999 + -9999);continue;
			}
			else if(Input[i] == 'm'){
				num = mem;continue;
			}
			return "Error 2.5 | Invalid input";
		}
		float num1 = stof(num) * pi;
		num1 = num1 / 180;
		if(Input[0] == 's'){
			return to_string(sinf(num1));
		}
		if(Input[0] == 't'){
			return to_string(tanf(num1));
		}
		if(Input[0] == 'c'){
			return to_string(cosf(num1));
		}
	}

	if(!isdigit(Input[0]) && Input[0] != 'p' && Input[0] != 'r' && Input[0] != 'm'){
		int op;

		if(Input[0] == '+'){//Finding operator
			op = 1;
		} else if(Input[0] == '-'){
			op = 2;
		} else if(Input[0] == '*'){
			op = 3;
		} else if(Input[0] == '/'){
			op = 4;
		} else{
			return "Error 2.4 | Invalid input";
		}

		string num;
		for(int i = 1; i < Input.length(); i++){
			if(isdigit(Input[i])){//Constructing numbers
				num = num + Input[i];
			} else if(Input[i] == '.'){
				num = num + Input[i];
			} else if(Input[i] == 'p'){
				num = to_string(pi);
			} else if(Input[i] == 'r'){
				num = to_string(rand() % 9999 + -9999);
			} 
			else if(Input[i] == 'm'){
				num = mem;
			}else {
				return "Error 2.3 | Invalid input";
			}
		}

		switch(op){//Final calculations
			case 1:
				return to_string(stof(lastAnswer) + stof(num, NULL));
			case 2:
				return to_string(stof(lastAnswer) - stof(num, NULL));
			case 3:
				return to_string(stof(lastAnswer) * stof(num, NULL));
			case 4:
				return to_string(stof(lastAnswer) / stof(num, NULL));
		}
	}

	string num1 = "";
	bool num1Done = false;
	string num2 = "";
	int op = 0;

	for(int i =0; i < Input.length(); i++){//Loop through input
		if(isdigit(Input[i])){//Constructing numbers
			if(num1Done){
				num2 = num2 + Input[i];
				continue;
			}
			num1 = num1 + Input[i];

		} else{//if current character is not a number, it will be an operator
			if(Input[i] == '.'){
				if(num1Done){
					num2 = num2 + Input[i];
					continue;
				}
				num1 = num1 + Input[i];continue;
			} else if(Input[i] == 'p'){
				if(num1Done){
					num2 = to_string(pi);
					continue;
				}
				num1 = to_string(pi);continue;
			} else if(Input[i] == 'r'){
				if(num1Done){
					num2 = to_string(rand() % 9999 + -9999);
					continue;
				}
				num1 = to_string(rand() % 9999 + -9999);continue;
			}
			 else if(Input[i] == 'm'){
				if(num1Done){
					num2 = mem;
					continue;
				}
				num1 = mem;continue;
			} else if(Input[i] == '+'){
				op = 1;
			} else if(Input[i] == '-'){
				op = 2;
			} else if(Input[i] == '*'){
				op = 3;
			} else if(Input[i] == '/'){
				op = 4;
			}else{
				return "Error 2.1 | Invalid input";
			}
			num1Done = true;
		}
	}

	string out;//Final calculation
	switch(op){
		case 1:
			out = to_string(stof(num1, NULL) + stof(num2, NULL));
			break;
		case 2:
			out = to_string(stof(num1, NULL) - stof(num2, NULL));
			break;
		case 3:
			out = to_string(stof(num1, NULL) * stof(num2, NULL));
			break;
		case 4:
			out = to_string(stof(num1, NULL) / stof(num2, NULL));
			break;
		default:
			out = "Error 2.2 | Invalid Input";
	}

	return out;
}

int main(){
	//srand (time(NULL));
	cout << "-- tCalc V1.5 -- Programmed by Bailey Dawson --\n-- Type ':e' to exit | ':h' for help --\n";//Not a plug

	while (true){//Main loop
		string userInput;
		cout << "> ";
		cin >> userInput;
		if(userInput == ":e"){//Exit program
			break;
		} else if(userInput == ":h"){//Help
			cout << "You can only do one operation at once\nSupported Operators: All operations involing letters are case sensetive\n\t- Plus \t\t'<num1>+<num2>'\n\t- Minus \t'<num1>-<num2>'\n\t- Mutliply \t'<num1>*<num2>'\n\t- Divide \t'<num1>/<num2>'\n\t- Sine \t\t'sin(<num>)'\n\t- Cosine \t'cos(<num>)'\n\t- Tangent \t'tan(<num>)'\n";
			cout << "Using Memory:\n\tJust enter m after getting the answer you want in Memory\n\tTo access memory put m instead of a number in a calcuation.\n";
			cout << "Using 'constants':\n\tPi can be used in calcuation by typing 'p' instead of a number\n\tTo have a random number in a calculation type 'r' instead of a number\n";
			continue;
		} else if(userInput == "m"){
			mem = lastAnswer;
			continue;
		} else{//Proper input parsing
			string ans = doCalc(userInput);
			if(ans[0] != 'E'){
				lastAnswer = ans;
			}
			cout << ans + "\n";
			continue;
		}
		cout << "Error 1.1 | Intial if Statements";
	}

	return 0;
}