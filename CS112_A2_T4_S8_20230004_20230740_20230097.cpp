// File: CS112_A2_T4_S8_20230004_20230097_20230740
// Purpose: This program encrypts and decrypts the string.

// Author: Ahmad Ibrahim Ahmad Mohammed
// ID: 20230004
// His email: ahmad2005717@gmail.com

// Author: Belal Mohamed Omar
// ID: 20230097
// His email: belalmohamed2020s@gmail.com


// Author: Osama Mohammed Pay
// ID: 20230740
// His email: Osamaa14444@gmail.com


#include <iostream>
#include <string>
#include <cctype>
#include <limits>
#include<iomanip>
#include <map>
#include <sstream>
#include <cctype>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// This part is function to Ahmad Ibrahim Ahmad Mohammed_20230004
// This function makes sure that the input is True
bool check_input_cipher(string tex) {
    int n = 0, x = 0;
    string nums[] = { "th","st","nd","rd" };
    // The first part makes sure that input letters is only a or b. and refers to the letter position
    for (auto i : tex) {
        i = tolower(i);
        ++x;
        if (isalpha(i) && (i != 'a' && i != 'b')) {
            cout << "\n Your input \"" << tex << "\" is not valid.\n This \"" << tex << "\" does not fit to be a cipher by a, b. Because, the input cipher must not include '" << i << "'.\n You will find it at " << x << nums[x * (x < 4)] << " character.\n \"" << tex << "\"\n";
            cout << setw(x + 3) << "^\n";
            return true;
        }
        if (i == 'a' || i == 'b')++n;
    }// The second part makes sure that letters number doubles for five
    if (n % 5) {
        cout << " Your input \"" << tex << "\" is not valid.\n Please, enter 5 characters from a or b only for each character which you want to solve its chiper.\n You can add " << 5 - n % 5 << " or remove " << n % 5 << " characters from the a or b.\n";
        return true;
    }
    // and now we come to a difficult part which makes sure that the letters is fives on respectively
    n = 0, x = -1;
    for (auto i : tex) {
        ++x;
        if (n % 5 && !(isalpha(i))) {
            cout << "\n Your input \"" << tex << "\" is not valid.\n Please, enter 5 characters from a or b respectively.\n You can write " << 5 - n % 5 << " characters from a or b after " << x << nums[x * (x < 4)] << " character.\n \"" << tex << "\"\n";
            cout << setw(x + 3) << "^";
            for (int j = 0; j < (5 - n % 5) - 1; ++j) {
                cout << "^";
            }
            return true;
        }
        if (isalpha(i)) { ++n; }
        else { n = 0; }
    }return false;
}
// This function counts the characters number
int stringlength(string tex) {
    int n = 0;
    for (auto i : tex)++n;
    return n;
}
//This function take each letter and encrypt it
void encryption20230004(string tex) {
    string s2 = "";
    for (auto i : tex) {
        switch (i) {
        case 'A':case 'a':
            s2 += "aaaaa ";
            break;
        case 'B':case 'b':
            s2 += "aaaab ";
            break;
        case 'C':case 'c':
            s2 += "aaaba ";
            break;
        case 'D':case 'd':
            s2 += "aaabb ";
            break;
        case 'E':case 'e':
            s2 += "aabaa ";
            break;
        case 'F':case 'f':
            s2 += "aabab ";
            break;
        case 'G':case 'g':
            s2 += "aabba ";
            break;
        case 'H':case 'h':
            s2 += "aabbb ";
            break;
        case 'I':case 'i':
            s2 += "abaaa ";
            break;
        case 'J':case 'j':
            s2 += "abaab ";
            break;
        case 'K':case 'k':
            s2 += "ababa ";
            break;
        case 'L':case 'l':
            s2 += "ababb ";
            break;
        case 'M':case 'm':
            s2 += "abbaa ";
            break;
        case 'N':case 'n':
            s2 += "abbab ";
            break;
        case 'O':case 'o':
            s2 += "abbba ";
            break;
        case 'P':case 'p':
            s2 += "abbbb ";
            break;
        case 'Q':case 'q':
            s2 += "baaaa ";
            break;
        case 'R':case 'r':
            s2 += "baaab ";
            break;
        case 'S':case 's':
            s2 += "baaba ";
            break;
        case 'T':case 't':
            s2 += "baabb ";
            break;
        case 'U':case 'u':
            s2 += "babaa ";
            break;
        case 'V':case 'v':
            s2 += "babab ";
            break;
        case 'W':case 'w':
            s2 += "babba ";
            break;
        case 'X':case 'x':
            s2 += "babbb ";
            break;
        case 'Y':case 'y':
            s2 += "bbaaa ";
            break;
        case 'Z':case 'z':
            s2 += "bbaab ";
            break;
            // We will store three scapes to easily reading
        case ' ':
            s2 += "   ";
            break;
        default:
            s2 += i;
        }
    }
    cout << "\n The encryption is " << s2 << "\n";
}

void decryption20230004(string tex) {
    int m = 0, z = 0, c = 0;
    // we declare c till it isn't printed more than space at the first
    // we declare z till it isn't printed more than space
    // we declare m until the location of desired letter is known its index. this will become after the decryption
    string cipher1 = "", cipher2 = " ";
    // cipher1 we will store inside it 5 letters respectively till done then they convert to letter at cipher2
    // We declare cipher2 by space to easily dealing in converting to upper
    for (auto i : tex) {
        if (i == ' ')++z;
        else z = 0;
        if (z > 1 && c == 1) {
            cipher2 += " ";
            c = 0;
        }
        // if the letter is capital must convert to small
        i = tolower(i);
        if (i == 'a' || i == 'b') {
            c = 1;
            cipher1 += i;
            // if cipher1 stored five letters the it will convert and restore the letters
            if (stringlength(cipher1) == 5) {
                if (cipher1 == "aaaaa") {
                    cipher2 += "a";
                }
                else if (cipher1 == "aaaab") {
                    cipher2 += "b";
                }
                else if (cipher1 == "aaaba") {
                    cipher2 += "c";
                }
                else if (cipher1 == "aaabb") {
                    cipher2 += "d";
                }
                else if (cipher1 == "aabaa") {
                    cipher2 += "e";
                }
                else if (cipher1 == "aabab") {
                    cipher2 += "f";
                }
                else if (cipher1 == "aabba") {
                    cipher2 += "g";
                }
                else if (cipher1 == "aabbb") {
                    cipher2 += "h";
                }
                else if (cipher1 == "abaaa") {
                    cipher2 += "i";
                }
                else if (cipher1 == "abaab") {
                    cipher2 += "j";
                }
                else if (cipher1 == "ababa") {
                    cipher2 += "k";
                }
                else if (cipher1 == "ababb") {
                    cipher2 += "l";
                }
                else if (cipher1 == "abbaa") {
                    cipher2 += "m";
                }
                else if (cipher1 == "abbab") {
                    cipher2 += "n";
                }
                else if (cipher1 == "abbba") {
                    cipher2 += "o";
                }
                else if (cipher1 == "abbbb") {
                    cipher2 += "p";
                }
                else if (cipher1 == "baaaa") {
                    cipher2 += "q";
                }
                else if (cipher1 == "baaab") {
                    cipher2 += "r";
                }
                else if (cipher1 == "baaba") {
                    cipher2 += "s";
                }
                else if (cipher1 == "baabb") {
                    cipher2 += "t";
                }
                else if (cipher1 == "babaa") {
                    cipher2 += "u";
                }
                else if (cipher1 == "babab") {
                    cipher2 += "v";
                }
                else if (cipher1 == "babba") {
                    cipher2 += "w";
                }
                else if (cipher1 == "babbb") {
                    cipher2 += "x";
                }
                else if (cipher1 == "bbaaa") {
                    cipher2 += "y";
                }
                else if (cipher1 == "bbaab") {
                    cipher2 += "z";
                }
                cipher1 = "";
            }
        }
        // to add each character is not a or b or space such as ++
        if (i != ' ' && i != 'a' && i != 'b')cipher2 += i;
    }
    // To convert the first letter is string to upper
    cipher2[1] = toupper(cipher2[1]);
    cipher2 += " ";
    // m is index for the desired letter
    for (char s : cipher2) {
        // This to treat with ' i love c++ '
        if (isalpha(s)) {
            if ((!isalpha(cipher2[m - 1])) && !isalpha(cipher2[m + 1]) || cipher2[m - 1] == '.')cipher2[m] = toupper(cipher2[m]);
        }++m;
    }
    cout << "\n The decryption is" << cipher2 << "\n";
}
//this part for encryption and decryption for Vignere Cipher
void encryption2(string x, string y) {
    int n = 0;
    string cipher = "";

    for (char i : x) {
        if (isalpha(i)) {
            i = toupper(i);
            cipher += ((i - 'A' + toupper(y[n % y.size()]) - 'A') % 26 + 'A');
            ++n;
        }
        else cipher += i;
    }cout << "\n The encryption is :" << cipher;
}

void decryption2(string x, string y) {
    int n = 0;
    string cipher = "";

    for (char i : x) {
        if (isalpha(i)) {
            i = toupper(i);
            cipher += ((i - 64 - (toupper(y[n % y.size()]) - 65)) % 26 + 64);
            ++n;
        }
        else cipher += i;
    }cout << "\n The encryption is :" << cipher;
}




// This part is functions to Belal Mohamed Omar_20230097
// Map to associate characters with their Morse code representation
map<char, string> morse_code = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."},
    {'F', "..-."}, {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"},
    {'K', "-.-"}, {'L', ".-.."}, {'M', "--"}, {'N', "-."}, {'O', "---"},
    {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
    {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"}, {'Y', "-.--"},
    {'Z', "--.."}, {'0', "-----"}, {'1', ".----"}, {'2', "..---"},
    {'3', "...--"}, {'4', "....-"}, {'5', "....."}, {'6', "-...."}, {'7', "--..."},
    {'8', "---.."}, {'9', "----."}, {'.', ".-.-.-"}, {',', "--..--"}, {'?', "..--.."},
    {'!', "-.-.--"}, {'/', "-..-."}, {'(', "-.--."}, {')', "-.--.-"}, {'&', ".-..."},
    {':', "---..."}, {';', "-.-.-."}, {'=', "-...-"}, {'+', ".-.-."}, {'-', "-....-"},
    {'_', "..--.-"}, {'\"', ".-..-."}, {'$', "...-..-"}, {'@', ".--.-."}
};
string text_to_morse(string text) {
    string morse_text;
    for (char c : text) {
        if (isalpha(c)) {
            morse_text += morse_code[toupper(c)] + " ";
        }
        else if (c == ' ') {
            morse_text += "/ ";
        }
    }
    return morse_text;
}
string morse_to_text(string morse_text) {
    stringstream ss(morse_text);
    string word;
    string decoded_text;
    while (ss >> word) {
        if (word == "/") {
            decoded_text += " ";
        }
        else {
            for (auto const& it : morse_code) {
                if (it.second == word) {
                    decoded_text += it.first;
                    break;
                }
            }
        }
    }
    return decoded_text;
}
//Rail-fenceCipher
string rail_fence_encrypt(string plaintext, int key) {
    if (key <= 0) {
        throw invalid_argument("Key must be positive");
    }

    vector<string> fence(key);
    int n = plaintext.length();
    int row = 0;
    bool down = true;

    for (int i = 0; i < n; i++) {
        fence[row].push_back(plaintext[i]);
        if (row == key - 1) {
            down = false;
        }
        else if (row == 0) {
            down = true;
        }
        row += down ? 1 : -1;
    }

    string encrypted_text;
    for (const string& part : fence) {
        encrypted_text += part;
    }
    return encrypted_text;
}

string rail_fence_decrypt(string ciphertext, int key) {
    if (key <= 0) {
        throw invalid_argument("Key must be positive");
    }

    vector<int> fence_pattern;
    int row = 0;
    bool down = true;
    for (int i = 0; i < ciphertext.length(); i++) {
        fence_pattern.push_back(row);
        if (row == key - 1) {
            down = false;
        }
        else if (row == 0) {
            down = true;
        }
        row += down ? 1 : -1;
    }

    vector<char> decrypted_text(ciphertext.length());
    int index = 0;
    for (int r = 0; r < key; r++) {
        for (int i = 0; i < fence_pattern.size(); i++) {
            if (fence_pattern[i] == r) {
                decrypted_text[i] = ciphertext[index++];
            }
        }
    }

    return string(decrypted_text.begin(), decrypted_text.end());
}



// This part is functions to Osama Mohammed Pay_20230740
//this equation is applied to encode speech according
// to the given numbers E(x) = (ax+b) mod26.

char Message_encryption(char ch, int a, int b) {
    if (isalpha(ch)) {
        char base = isupper(ch) ? 'A' : 'a';
        return (char)(((a * (ch - base) + b) % 26 + 26) % 26 + base);


    }
    // The distance is returned without any encryption.
    else if (isspace(ch)) {
        return ch;

    }
    return ch;
}

//This equation is applied to encode speech according to the given numbers for
// decrypt message using D(y) = c (y - b) mod 26.

char Decrypt_the_message(char ch, int c, int b) {
    if (isalpha(ch)) {
        char base = isupper(ch) ? 'A' : 'a';
        return (char)((((c * ((ch - base) - b)) + (8 * 26)) % 26) + base);
    }
    //The distance is returned witout any enctyoion.
    else if (isspace(ch)) {
        return ch;
    }
    return ch;
}
/* name : osama mohammed bay
   ID :   20230740           */
   // Function to build the cipher alphabet based on the provided key
string Cipher_Alphabet(const string& key) {
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string cipher = key;
    // Add the remaining letters after the key in alphabetical order
    for (char c : alphabet) {
        if (key.find(c) == string::npos) {
            cipher += c;
        }
    }
    return cipher;
}
// Function to encrypt the plain text using the provided key and cipher alphabet
string encrypt_massege(const string& plainText, const string& key) {
    string Alphabet = Cipher_Alphabet(key);
    string encrypted;
    // Encrypt each character in the plain text
    for (char c : plainText) {
        if (isalpha(c)) {
            if (isupper(c)) {
                encrypted += toupper(Alphabet[tolower(c) - 'a']);
            }
            else {
                encrypted += Alphabet[c - 'a'];
            }
        }
        else {
            encrypted += c;
        }
    }
    return encrypted;
}
// Function to decrypt the cipher text using the provided key and cipher alphabet
string decrypt_massege(const string& cipherText, const string& key) {
    string cipher = Cipher_Alphabet(key);
    string decrypted;
    // Decrypt each character in the cipher text
    for (char c : cipherText) {
        if (isalpha(c)) {
            if (isupper(c)) {
                decrypted += toupper('a' + cipher.find(tolower(c)));
            }
            else {
                decrypted += 'a' + cipher.find(c);
            }
        }
        else {
            decrypted += c;
        }
    }
    return decrypted;
}
/*name : osama mohammed bay
 ID :   20230740           */
 // Function to perform encryption/decryption
string encrypt_decrypt(const string& message, const string& key) {
    string result;
    // Loop through each character of the message
    for (int i = 0; i < message.length(); ++i) {
        // Perform XOR operation between the current character of the message and the corresponding character of the key
        result += message[i] ^ key[i % key.length()];
    }
    return result;
}

// Function to convert text to hexadecimal
string text_to_hex(const string& text) {
    stringstream x;
    // Loop through each character of the text
    for (char c : text) {
        // Convert each character to its hexadecimal representation and append it to the stringstream
        x << hex << static_cast<int>(c) << " ";
    }
    return x.str();
}

// Function to convert hexadecimal to text
string hex_to_text(const string& hex_string) {
    stringstream x(hex_string);
    stringstream result;
    string hex_pair;
    // Read each pair of hexadecimal characters from the input stringstream
    while (x >> hex_pair) {
        int hex_value;
        // Convert the hexadecimal pair to its integer value
        stringstream(hex_pair) >> hex >> hex_value;
        // Append the character corresponding to the integer value to the result stringstream
        result << static_cast<char>(hex_value);
    }
    return result.str();
}

std::unordered_map<char, std::pair<char, char>> create_polybius_square(const std::vector<char>& key) {
    std::string alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ"; // I and J are combined
    std::unordered_map<char, std::pair<char, char>> square;
    for (int i = 0; i < alphabet.length(); ++i) {
        square[alphabet[i]] = { key[i / 5], key[i % 5] };
    }
    return square;
}

std::string encrypt(const std::string& message, const std::vector<char>& key) {
    auto square = create_polybius_square(key);
    std::string cipher_text;
    for (char ch : message) {
        ch = toupper(ch);
        if (square.find(ch) != square.end()) {
            cipher_text.push_back(square[ch].first);
            cipher_text.push_back(square[ch].second);
        }
    }
    return cipher_text;
}

std::string decrypt(const std::string& cipher_text, const std::vector<char>& key) {
    auto square = create_polybius_square(key);
    std::unordered_map<std::string, char> inverse_square;
    for (const auto& pair : square) {
        inverse_square[{pair.second.first, pair.second.second}] = pair.first;
    }
    std::string plain_text;
    for (size_t i = 0; i < cipher_text.length(); i += 2) {
        std::string pair = { cipher_text[i], cipher_text[i + 1] };
        if (inverse_square.find(pair) != inverse_square.end()) {
            plain_text += inverse_square[pair];
        }
    }
    return plain_text;
}

std::unordered_map<char, char> create_atbash_cipher() {
    std::string first_half = "ABCDEFGHIJKLM";
    std::string second_half = "NOPQRSTUVWXYZ";
    std::unordered_map<char, char> cipher_map;

    for (size_t i = 0; i < first_half.length(); ++i) {
        cipher_map[first_half[i]] = first_half[first_half.length() - 1 - i];
    }

    for (size_t i = 0; i < second_half.length(); ++i) {
        cipher_map[second_half[i]] = second_half[second_half.length() - 1 - i];
    }

    return cipher_map;
}

std::string apply_atbash_cipher(const std::string& message, const std::unordered_map<char, char>& cipher_map) {
    std::string result;
    for (char ch : message) {
        if (isalpha(ch)) {
            char upper_ch = toupper(ch);
            result += cipher_map.count(upper_ch) ? cipher_map.at(upper_ch) : ch;
        }
        else {
            result += ch;
        }
    }
    return result;
}




//The main program
int main() {

    string chc;
    while (true) {
        cout << "\n what is the Cipher Way which you want it?\n  1)  Affine Cipher?\n  2)  Route Cipher?\n  3)  Atbash Cipher?\n  4)  Vignere Cipher?\n  5)  Baconian_Cipher?\n  6)  Simple Substitution Cipher?\n  7)  Polybius Square Cipher?\n  8)  Morse Code?\n  9)  XOR Cipher?\n  10) Rail-fence Cipher?\n  11) End?\n Please, enter 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, or 11 : "; getline(cin, chc);
        while (chc != "1" && chc != "2" && chc != "3" && chc != "4" && chc != "5" && chc != "6" && chc != "7" && chc != "8" && chc != "9" && chc != "10" && chc != "11") {
            cout << "\n '" << chc << "' is not among the options. please, follow the instructions.\n what is the Cipher Way which you want it?\n  1)  Affine Cipher?\n  2)  Route Cipher?\n  3)  Atbash Cipher?\n  4)  Vignere Cipher?\n  5)  Baconian_Cipher?\n  6)  Simple Substitution Cipher?\n  7)  Polybius Square Cipher?\n  8)  Morse Code?\n  9)  XOR Cipher?\n  10) Rail-fence Cipher?\n  11) End?\n Please, enter 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, or 11 : "; getline(cin, chc);
        }
        if (chc == "11")return 0;
        else if (chc == "5") {
            //Welcome message
            cout << "\n\t\t\t\t*****************************\n\t\t\t\t Welcome_to_Baconian_Cipher!\n\t\t\t\t*****************************\n" << endl;
            string string_input;
            string choice;

            //Read encryption or decryption
            while (true) {
                cout << " Do you want encryption or decryption?\n   A) Encryption.\n   B) Decryption.\n   C) End.\n Please, enter one character A, B, or C : "; getline(cin, choice);

                while (choice != "A" && choice != "a" && choice != "B" && choice != "b" && choice != "C" && choice != "c") {
                    cout << "\n '" << choice << "' is not among the options. please, follow the instructions.\n Do you want Encryption or Decryption?\n   A) encryption.\n   B) decryption.\n   C) End.\n Please, enter one character A, B, or C : "; getline(cin, choice);
                }
                cin.ignore();

                if (choice == "A" || choice == "a") {
                    //Read text from the user
                    cout << "\n Please, enter a string to decoded by a,b only: ";
                    getline(cin, string_input);
                    encryption20230004(string_input); continue;
                }
                else if (choice == "B" || choice == "b") {
                    //Read text from the user
                    cout << "\n Please, enter the Cipher like:\n\n abaaa    ababb abbba babab aabaa  aaaba++.\n I love C++.\n\n You have to add more than space before each letter's pattern which is at the first word. As explained in the previous example.\n "; getline(cin, string_input);
                    while (check_input_cipher(string_input)) {
                        cout << "\n Please, follow the instructions.\n Please, enter the Cipher like:\n\n abaaa    ababb abbba babab aabaa  aaaba++.\n I love C++.\n\n You have to add more than space before each letter's pattern which is at the first word. As explained in the previous example.\n "; getline(cin, string_input);
                    }
                    decryption20230004(string_input); continue;
                }
                else {
                    break;
                }
            }
            continue;
        }



        else if (chc == "10") {
            string text;
            cout << "Enter the text to encrypt: ";
            getline(cin, text);

            string plaintext = "";
            for (char c : text) {
                if (isalpha(c)) {
                    plaintext += tolower(c);
                }
            }

            int key;
            cout << "Enter the key value (a positive integer): ";
            cin >> key;

            try {
                string encrypted_text = rail_fence_encrypt(plaintext, key);
                cout << "Encrypted message: " << encrypted_text << endl;

                string decrypted_text = rail_fence_decrypt(encrypted_text, key);
                cout << "Decrypted message: " << decrypted_text << endl;
            }
            catch (const invalid_argument& e) {
                cerr << "Error: " << e.what() << endl;
            }
        }
        else if (chc == "4") {
            string x, y;
            cout << "\n Please, enter a string to encrypt: "; getline(cin, x);
            cout << "\n Please, enter the keyword: "; getline(cin, y);
            encryption2(x, y);
            cout << "\n Please, enter a string to decrypt: "; getline(cin, x);
            cout << "\n Please, enter the keyword: "; getline(cin, y);
            decryption2(x, y);
        }


        else if (chc == "9") {
            //I used it to colorize the output.
            const string RESET = "\033[0m";
            const string RED = "\033[91m";
            const string GREEN = "\033[92m";
            const string ANSI_YELLOW = "\033[93m";
            const string BLUE = "\033[94m";
            const string MAGENTA = "\033[95m";
            const string CYAN = "\033[96m";
            const string WHITE = "\033[97m";

            cout << "\t\t\t\t   *********************************************\n";
            cout << "\t\t\t\t   *                                           *\n";
            cout << "\t\t\t\t   *" << GREEN << "           Welcome to XOR Cipher" << RESET << "           *\n";
            cout << "\t\t\t\t   *                                           *\n";
            cout << "\t\t\t\t   *********************************************\n\n\n";

            string secret_key;
            cout << MAGENTA << "\aEnter the secret key: " << RESET;
            getline(cin, secret_key);

            string message;
            cout << BLUE << "Enter the message to encrypt: " << RESET;
            getline(cin, message);

            // Encrypt the message using the XOR cipher
            string encrypted_message = encrypt_decrypt(message, secret_key);
            // Convert the encrypted message to hexadecimal
            string encrypted_hex = text_to_hex(encrypted_message);

            cout << RED << "Cipher text: " << encrypted_message << endl;
            cout << "Hexa: " << RESET << encrypted_hex << endl;

            char decrypt_choice;
            cout << MAGENTA << "\nDo you want to decrypt the message? (yes/no): " << RESET;
            cin >> decrypt_choice;

            // Check if the user wants to decrypt the message
            if (tolower(decrypt_choice) == 'y') {
                cin.ignore();  // Ignore the newline character
                string encrypted_hex_input;
                cout << BLUE << "Enter the ciphered text in hexa: " << RESET;
                getline(cin, encrypted_hex_input);
                // Decrypt the message using the XOR cipher
                string decrypted_message = encrypt_decrypt(hex_to_text(encrypted_hex_input), secret_key);
                cout << RED << "Decrypted text: " << decrypted_message << RESET << endl;
            }
        }


        else if (chc == "6") {
            //I used it to colorize the output.
            const string RESET = "\033[0m";
            const string RED = "\033[91m";
            const string GREEN = "\033[92m";
            const string ANSI_YELLOW = "\033[93m";
            const string BLUE = "\033[94m";
            const string MAGENTA = "\033[95m";
            const string CYAN = "\033[96m";
            const string WHITE = "\033[97m";


            cout << "\t\t\t\t\t  ***********************************************\n";
            cout << "\t\t\t\t\t  *                                             *\n";
            cout << "\t\t\t\t\t  *" << GREEN << "    Welcome to Simple Substitution Cipher    " << RESET << "*\n";
            cout << "\t\t\t\t\t  *                                             *\n";
            cout << "\t\t\t\t\t  ***********************************************\n\n\n";

            string key, plainText;

            cout << MAGENTA << "Enter the key (5 unique letters): " << RESET;
            cin >> key;
            transform(key.begin(), key.end(), key.begin(), ::tolower);// Convert the key to lowercase

            cin.ignore();  // Clear input buffer
            cout << BLUE << "Enter the plain text: " << RESET;
            getline(cin, plainText);
            // Encrypt the plain text using the provided key and print the cipher text
            string cipher_Text = encrypt_massege(plainText, key);
            cout << CYAN << "\n=====================================================================================================================\n";
            cout << RED << "\nCipher text: " << RESET << cipher_Text << endl;
            // Decrypt the cipher text using the provided key and print the decrypted text
            string decrypted_Text = decrypt_massege(cipher_Text, key);
            cout << RED << "Decrypted text: " << RESET << decrypted_Text << endl;

        }

        else if (chc == "8") {
            // This part is to Belal Mohamed Omar_20230097
            int choice2;
            cout << "\nEncryption by Morse Code.";
            cout << "Choose an option:\n";
            cout << "1. Convert text to Morse code\n";
            cout << "2. Decode Morse code to text\n";
            cout << "Enter your choice (1 or 2): ";
            cin >> choice2;
            cin.ignore();
            if (choice2 == 1) {
                string input_text;
                cout << "Enter the text to convert to Morse code: ";
                getline(cin, input_text);
                cout << "Plain text: " << input_text << endl;
                string morse_text = text_to_morse(input_text);
                cout << "Morse text: " << morse_text << endl;
            }
            else if (choice2 == 2) {
                string input_morse;
                cout << "Enter the Morse code to decode: ";
                getline(cin, input_morse);
                cout << "Morse text: " << input_morse << endl;
                string decoded_text = morse_to_text(input_morse);
                cout << "Decoded text: " << decoded_text << endl;
            }
            else {
                cout << "Invalid choice. Please choose 1 or 2." << endl;
            }
        }

        else if (chc == "1") {
            // This part is to Osama Mohammed Pay_20230740
            int a{}, b, c;
            string choice3;
            // i used to colorize the out put.
            const string reset = "\033[0m";
            const string red = "\033[91m";
            const string green = "\033[92";
            const string blue = "\033[94m";
            const string magenta = "\033[95m";
            const string cyan = "\033[96m";
            const string white = "\033[97m";
            cout << blue << "\n---------------------------Welcome to the world of encryption You can sand your data securely--------------------------\n";
            cout << blue << "\nEncryption by Affine Cipher.";
            cout << magenta << "\nDo you want to encrypt it through the system, or do you want to add the encryption scope ? (y/n) : ";
            cin >> choice3;
            if (choice3 == "n" || choice3 == "N") {
                cout << "\nEnter the value of 'a' (must be coprime with 26):";
                cin >> a;
                cout << "\nEnter the value of 'b' :";
                cin >> b;
                // calculate 'c' to satisfy the condition (a * c) mod 26 = 1.
                for (c = 1; c < 26; c++) {
                    if ((a * c) % 26 == 1) {
                        break;
                    }
                }
            }
            else {
                cout << cyan << "\nUsing default values for 'a' and 'b' . " << endl;
                a = 5; // Default value for 'a'
                b = 8; // Default valre for 'b'
                // Calculate 'c' to satisfy the condition ( a * c) mod 26 = 1
                for (c = 1; c < 26; c++) {
                    if ((a * c) % 26 == 1) {
                        break;
                    }

                }
            }
            cin.ignore(numeric_limits < streamsize > ::max(), '\n');
            string text;
            cout << red << "\nEnter the text : ";
            getline(cin, text);
            string encryption_text;
            for (char ch : text) {
                encryption_text += Message_encryption(ch, a, b);
            }
            cout << "\nEncrypted text : " << encryption_text << endl;
            cout << blue << "\n========================================================================================================================";
            cout << magenta << "\n\nDo you want to decrypt the message ? (Y/N) : ";
            cin >> choice3;
            if (choice3 == "Y" || choice3 == "y") {
                string Decrypt;
                for (char ch : encryption_text) {
                    Decrypt += Decrypt_the_message(ch, c, b);
                }
                cout << red << "\nDecrypted taxt :" << Decrypt << "\n\n" << reset;
            }
            else {
                cout << "\n\n <<<<<<<<<<<<<<<< Program ends >>>>>>>>>>>>>>>>>\n\n\n\n\n\n\n" << reset;
            }
        }

        else if (chc == "2") {


            /*Route Cipher*/


        }
        else if (chc == "3") {


            unordered_map<char, char> atbash_cipher = create_atbash_cipher();
            string message;
            int choice;

            cout << "Enter 1 to encrypt, 2 to decrypt: ";
            cin >> choice;
            cin.ignore(); // Ignore the newline remaining in the buffer

            cout << "Enter the message: ";
            getline(std::cin, message);

            if (choice == 1) {
                string ciphered_message = apply_atbash_cipher(message, atbash_cipher);
                cout << "Ciphered message: " << ciphered_message << endl;
            }
            else if (choice == 2) {
                string deciphered_message = apply_atbash_cipher(message, atbash_cipher);
                cout << "Deciphered message: " << deciphered_message << endl;
            }
            else {
                cout << "Invalid choice." << endl;
            }

           // return 0;


        }

        else if (chc == "7") {


            vector<char> key(5);
            string message;

            // Prompt the user for the key
            cout << "Enter the key (5 unique numbers between 1 and 5): ";
            for (char& k : key) {
                cin >> k;
            }

            // Prompt the user for the message
            cout << "Enter the message: ";
            cin.ignore(); // Ignore the newline remaining in the buffer
            getline(cin, message);

            // Encrypt the message
            string ciphered = encrypt(message, key);
            cout << "Cipher text: " << ciphered << endl;

            // Decrypt the message
            string deciphered = decrypt(ciphered, key);
            cout << "Plain text: " << deciphered << endl;

            //return 0;


        }





        continue;

    }return 0;
}
