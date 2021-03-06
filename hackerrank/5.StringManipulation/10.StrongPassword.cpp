#include <bits/stdc++.h>

using namespace std;

// Complete the minimumNumber function below.
int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong
    int result = 0;
    
    bool length = false;
    bool digit = false;
    bool lower = false;
    bool upper = false;
    bool special = false;
    
    if(n >= 6){
        length = true;
    }
    
    for(int i=0; i<password.size(); i++){
        char value = password[i];
        if(password[i] >= 'a' && password[i] <= 'z'){
            lower = true;
        }
        
        if(password[i] >= 'A' && password[i] <= 'Z'){
            upper = true;
        }
        
        if(password[i] >= '0' && password[i] <= '9'){
            digit = true;
        }
        
        if(password[i] == '!' ||
            password[i] == '@' ||
            password[i] == '#' ||
            password[i] == '$' ||
            password[i] == '%' ||
            password[i] == '^' ||
            password[i] == '&' ||
            password[i] == '*' ||
            password[i] == '(' ||
            password[i] == ')' ||
            password[i] == '-' ||
            password[i] == '+'){
                special = true;
            } 
        
        if(length && digit && lower && upper && special){
            return 0;
        }
    }
    
    int charactersToAdd = -1;
    if(!length){
        charactersToAdd = 6 - n;    
        result = result + charactersToAdd;
    }
    
    if(!digit){
        if(charactersToAdd > 0){
            charactersToAdd--;
        }
        else if (charactersToAdd == 0){
            result++;
        }
        else if(charactersToAdd == -1){
            result++;
        }
    }
    
    if(!lower){
        if(charactersToAdd > 0){
            charactersToAdd--;
        }
        else if (charactersToAdd == 0){
            result++;
        }
        else if(charactersToAdd == -1){
            result++;
        }
    }
    
    if(!upper){
        if(charactersToAdd > 0){
            charactersToAdd--;
        }
        else if (charactersToAdd == 0){
            result++;
        }
        else if(charactersToAdd == -1){
            result++;
        }
    }
    
    if(!special){
        if(charactersToAdd > 0){
            charactersToAdd--;
        }
        else if (charactersToAdd == 0){
            result++;
        }
        else if(charactersToAdd == -1){
            result++;
        }
    }
    
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

    fout.close();

    return 0;
}
