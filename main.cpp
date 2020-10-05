#include <iostream>
#include <string>

using namespace std;

string doCalc(string Input, float mem, string lastAnswer){//Gets the string and coverts into something that is usable by the program, then works that out
	
	if(!isdigit(Input[0])){
		int op;

		if(Input[0] == '+'){
			op = 1;
		} else if(Input[0] == '-'){
			op = 2;
		} else if(Input[0] == '*'){
			op = 3;
		} else if(Input[0] == '/'){
			op = 4;
		} else{
			return "Error | Invalid input";
		}

		string num;
		for(int i = 1; i < Input.length(); i++){
			if(isdigit(Input[i])){//Constructing numbers
				num = num + Input[i];

			} else if(Input[i] == '.'){
				num = num + Input[i];
			} else {
				return "Error | Invalid input";
			}
		}


		switch(op){
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
			} else if(Input[i] == '+'){
				op = 1;
			} else if(Input[i] == '-'){
				op = 2;
			} else if(Input[i] == '*'){
				op = 3;
			} else if(Input[i] == '/'){
				op = 4;
			}else{
				return "Error | Invalid input";
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
			out = "Error | Invalid Input";
	}

	return out;
}

int main(){
	cout << "-- tCalc V1.3 -- Programmed by Bailey Dawson --\n-- Type ':e' to exit | ':h' for help--\n";//Not a plug
	float mem;
	string lastAnswer;

	while (true){//Main loop
		string userInput;
		cout << "> ";
		cin >> userInput;

		if(userInput == ":e"){//Exit program
			break;
		} else if(userInput == ":h"){//Help
			cout << "Will add soon";
			continue;
		} else if(userInput == "m"){
			mem = stof(lastAnswer);
		} else{//Proper input parsing
			string ans = doCalc(userInput, mem, lastAnswer);
			if(ans[0] != 'E'){
				lastAnswer = ans;
			}
			cout << ans + "\n";
			continue;
		}
		cout << "Error | Intial if Statements";
	}

	return 0;
}