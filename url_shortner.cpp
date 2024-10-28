// BASE62 encoded URL Shortner 

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

const string BASE62_CHARS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

string toBase62(int num) {
    string encoded = "";
    while (num > 0) {
        encoded = BASE62_CHARS[num % 62] + encoded;
        num /= 62;
    }
    return encoded;
}

string encodeString(const string& input, int& counter) {
    string result = input;

    srand(counter);

    for (int i = 0; i < result.length(); i++) {
        result[i] = result[i] + (counter % 26);  
        result[i] += (rand() % 5); 
    }

    result += toBase62(counter);

    counter++;

    return result;
}

int main() {
    string input = "hello";
    int counter = 1;

    for (int i = 0; i < 10; i++) {
        string encoded = encodeString(input, counter);
        cout << "Encoded output " << i + 1 << ": " << encoded << endl;
    }

    return 0;
}


// Input: "hello"

// Output: 
// Encoded output 1: jhqmt1
// Encoded output 2: jhqnu2
// Encoded output 3: nisps3
// Encoded output 4: mitqs4
// Encoded output 5: qmqut5
// Encoded output 6: qnvrv6
// Encoded output 7: pnssw7
// Encoded output 8: tmuww8
// Encoded output 9: touxz9
// Encoded output 10: ssxz{A
