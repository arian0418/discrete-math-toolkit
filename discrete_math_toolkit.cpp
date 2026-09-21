#include <algorithm>
#include <bitset>
#include <cctype>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string caesarShift(const string& text, int key) {
    string result;

    for (char ch : text) {
        if (islower(static_cast<unsigned char>(ch))) {
            result += char((ch - 'a' - key + 26) % 26 + 'a');
        } else if (isupper(static_cast<unsigned char>(ch))) {
            result += char((ch - 'A' - key + 26) % 26 + 'A');
        } else {
            result += ch;
        }
    }

    return result;
}

void caesarCipherTool() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string cipher;
    cout << "\nEnter cipher text: ";
    getline(cin, cipher);

    cout << "\nPossible Caesar shifts:\n";
    for (int key = 0; key < 26; ++key) {
        cout << "Shift " << key << ": " << caesarShift(cipher, key) << "\n";
    }

    int key;
    cout << "\nEnter the shift to use: ";
    cin >> key;

    if (key < 0 || key > 25) {
        cout << "Shift must be between 0 and 25.\n";
        return;
    }

    cout << "Decrypted text: " << caesarShift(cipher, key) << "\n";
}

string toBase(int number, int base) {
    const string digits = "0123456789ABCDEF";

    if (number == 0) {
        return "0";
    }

    string result;
    while (number > 0) {
        result += digits[number % base];
        number /= base;
    }

    reverse(result.begin(), result.end());
    return result;
}

void baseConverterTool() {
    int number;
    int base;

    cout << "\nEnter a nonnegative decimal number: ";
    cin >> number;
    cout << "Enter the target base (2-16): ";
    cin >> base;

    if (number < 0 || base < 2 || base > 16) {
        cout << "Invalid input. Use a nonnegative number and a base from 2 to 16.\n";
        return;
    }

    cout << "Result: " << toBase(number, base) << "\n";
}

vector<int> encodeHamming(int decimal) {
    bitset<4> bits(decimal);

    int d1 = bits[3];
    int d2 = bits[2];
    int d3 = bits[1];
    int d4 = bits[0];

    vector<int> code(8, 0);
    code[3] = d1;
    code[5] = d2;
    code[6] = d3;
    code[7] = d4;

    code[1] = code[3] ^ code[5] ^ code[7];
    code[2] = code[3] ^ code[6] ^ code[7];
    code[4] = code[5] ^ code[6] ^ code[7];

    return code;
}

int hammingSyndrome(const vector<int>& code) {
    int p1 = code[1] ^ code[3] ^ code[5] ^ code[7];
    int p2 = code[2] ^ code[3] ^ code[6] ^ code[7];
    int p4 = code[4] ^ code[5] ^ code[6] ^ code[7];

    return p1 + (p2 * 2) + (p4 * 4);
}

void printHamming(const vector<int>& code) {
    for (int i = 1; i <= 7; ++i) {
        cout << code[i];
    }
}

void hammingTool() {
    int decimal;
    cout << "\nEnter a decimal number (0-15): ";
    cin >> decimal;

    if (decimal < 0 || decimal > 15) {
        cout << "Number must be between 0 and 15.\n";
        return;
    }

    vector<int> code = encodeHamming(decimal);

    cout << "Hamming(7,4) code: ";
    printHamming(code);
    cout << "\n";

    int flip;
    cout << "Enter a bit position to flip (1-7), or 0 for no error: ";
    cin >> flip;

    if (flip < 0 || flip > 7) {
        cout << "Invalid bit position.\n";
        return;
    }

    if (flip != 0) {
        code[flip] ^= 1;
    }

    cout << "Received code: ";
    printHamming(code);
    cout << "\n";

    int error = hammingSyndrome(code);

    if (error == 0) {
        cout << "No single-bit error detected.\n";
    } else {
        cout << "Error detected at bit position " << error << ".\n";
        code[error] ^= 1;
        cout << "Corrected code: ";
        printHamming(code);
        cout << "\n";
    }

    int decoded = code[3] * 8 + code[5] * 4 + code[6] * 2 + code[7];
    cout << "Decoded decimal value: " << decoded << "\n";
}

set<int> readSet(const string& name) {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string line;
    cout << "Enter Set " << name << " as comma-separated integers: ";
    getline(cin, line);

    set<int> values;
    string token;
    stringstream input(line);

    while (getline(input, token, ',')) {
        stringstream valueStream(token);
        int value;
        if (valueStream >> value) {
            values.insert(value);
        }
    }

    return values;
}

void printSet(const set<int>& values) {
    cout << "{ ";
    for (int value : values) {
        cout << value << " ";
    }
    cout << "}";
}

void setOperationsTool() {
    cout << "\n";
    set<int> A = readSet("A");

    cin.clear();
    string line;
    cout << "Enter Set B as comma-separated integers: ";
    getline(cin, line);
    set<int> B;
    string token;
    stringstream inputB(line);
    while (getline(inputB, token, ',')) {
        stringstream valueStream(token);
        int value;
        if (valueStream >> value) B.insert(value);
    }

    set<int> unionSet;
    set<int> intersectionSet;
    set<int> differenceAB;
    set<int> differenceBA;

    set_union(A.begin(), A.end(), B.begin(), B.end(),
              inserter(unionSet, unionSet.begin()));
    set_intersection(A.begin(), A.end(), B.begin(), B.end(),
                     inserter(intersectionSet, intersectionSet.begin()));
    set_difference(A.begin(), A.end(), B.begin(), B.end(),
                   inserter(differenceAB, differenceAB.begin()));
    set_difference(B.begin(), B.end(), A.begin(), A.end(),
                   inserter(differenceBA, differenceBA.begin()));

    cout << "\nA union B = ";
    printSet(unionSet);
    cout << "\nA intersection B = ";
    printSet(intersectionSet);
    cout << "\nA - B = ";
    printSet(differenceAB);
    cout << "\nB - A = ";
    printSet(differenceBA);
    cout << "\n";
}

bool logicalXor(bool a, bool b) {
    return a != b;
}

bool implies(bool a, bool b) {
    return !a || b;
}

bool nandOp(bool a, bool b) {
    return !(a && b);
}

bool norOp(bool a, bool b) {
    return !(a || b);
}

bool xnorOp(bool a, bool b) {
    return a == b;
}

void truthTableTool() {
    cout << "\nTruth Table\n";
    cout << "A B C | XOR(!(A OR C), B) | NAND(B -> C, !(A OR B)) | (A XOR B) -> (B XNOR C) | (A -> B) -> !C\n";
    cout << "------------------------------------------------------------------------------------------------------\n";

    for (int A = 0; A <= 1; ++A) {
        for (int B = 0; B <= 1; ++B) {
            for (int C = 0; C <= 1; ++C) {
                bool expr1 = logicalXor(norOp(A, C), B);
                bool expr2 = nandOp(implies(B, C), norOp(A, B));
                bool expr3 = implies(logicalXor(A, B), xnorOp(B, C));
                bool expr4 = implies(implies(A, B), !C);

                cout << A << " " << B << " " << C << " | "
                     << expr1 << "                  | "
                     << expr2 << "                         | "
                     << expr3 << "                          | "
                     << expr4 << "\n";
            }
        }
    }
}

void showMenu() {
    cout << "\n========== Discrete Math Toolkit ==========\n";
    cout << "1. Caesar Cipher Decoder\n";
    cout << "2. Number Base Converter\n";
    cout << "3. Hamming(7,4) Encoder & Error Corrector\n";
    cout << "4. Set Operations\n";
    cout << "5. Truth Table Generator\n";
    cout << "0. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    int choice;

    do {
        showMenu();

        if (!(cin >> choice)) {
            cout << "Invalid input.\n";
            return 1;
        }

        switch (choice) {
            case 1:
                caesarCipherTool();
                break;
            case 2:
                baseConverterTool();
                break;
            case 3:
                hammingTool();
                break;
            case 4:
                setOperationsTool();
                break;
            case 5:
                truthTableTool();
                break;
            case 0:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid option.\n";
        }
    } while (choice != 0);

    return 0;
}
