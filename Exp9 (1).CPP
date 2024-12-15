/* A palindrome is a string of character that‘s the same forward and backward. Typically, punctuation, capitalization,
and spaces are ignored. For example, "Poor Dan is in a droop" is a palindrome, as can be seen by examining the characters
"poor danisina droop" and observing that they are the same forward and backward. One way to check for a palindrome is to reverse
the characters in the string and then compare with them the original-in a palindrome, the sequence will be identical. Write C++ program
with functions-
a) To print original string followed by reversed string using stack
b) To check whether given string is palindrome or not  */
#include <iostream>
#include <string>
#include <cctype> // For tolower and isalpha
#define MAX 50

class STACK {
private:
    char a[MAX]; // Array to hold the stack elements
    int top;     // Top index of the stack

public:
    STACK() : top(-1) {}

    // Push character onto the stack
    void push(char c) {
        if (top >= MAX - 1) {
            std::cout << "Stack overflow. Cannot push more characters.\n";
            return;
        }
        a[++top] = c;
    }

    // Reverse the stack content
    std::string reverse() {
        std::string reversed;
        for (int i = top; i >= 0; i--) {
            reversed += a[i];
        }
        return reversed;
    }

    // Clean and normalize the input string
    void convert(std::string &str) {
        std::string clean;
        for (size_t i = 0; i < str.length(); i++) {
            if (std::isalpha(str[i])) { // Check if the character is alphabetic
                clean += (char)std::tolower(str[i]);
            }
        }
        str = clean; // Update the string with the cleaned version
    }

    // Check if the string is a palindrome
    bool isPalindrome() {
        std::string original(a, top + 1); // Get the original string from the stack
        std::string reversed = reverse(); // Get the reversed string
        return original == reversed;
    }
};

int main() {
    STACK stack;
    std::string str;

    std::cout << "Enter a string to check if it is a palindrome:\n";
    std::getline(std::cin, str);

    // Convert the input string: remove non-alphabetic characters and convert to lowercase
    stack.convert(str);

    // Push each character of the cleaned string onto the stack
    for (size_t i = 0; i < str.length(); i++) {
        stack.push(str[i]);
    }

    // Check if the string is a palindrome
    if (stack.isPalindrome()) {
        std::cout << "The string is a palindrome.\n";
    } else {
        std::cout << "The string is not a palindrome.\n";
    }

    // Display the reversed string
    std::cout << "Reversed string is: " << stack.reverse() << "\n";

    return 0;
}
