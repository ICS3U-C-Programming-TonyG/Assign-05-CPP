// Copyright (c) 2020 Tony G All rights reserved.
//
// Created by: Tony G
// Created on: 2025-03-17
// Caesar Cipher encryption.

#include <iostream>
#include <string>

std::string encrypt_text(const std::string& plaintext, int n) {
    std::string ans = "";
    for (char ch : plaintext) {
        // Compound Boolean and nested if
        if ((isalpha(ch) && !isdigit(ch)) || ch == ' ') {
            if (ch == ' ') {
                ans += ' ';
            } else {
                if (isupper(ch)) {
                    ans += static_cast<char>((((ch - 'A') + n) % 26) + 'A');
                } else {
                    ans += static_cast<char>((((ch - 'a') + n) % 26) + 'a');
                }
            }
        } else {
            ans += ch;
        }
    }
    return ans;
}

int main() {
    std::string plaintext;
    int n;

    std::cout << "Write your message: ";
    std::getline(std::cin, plaintext);

    std::cout << "What order of magnitude? ";
    std::cin >> n;

    std::cout << "Plain Text is: " << plaintext << std::endl;
    std::cout << "Shift pattern is: " << n << std::endl;
    std::cout << "Cipher Text is: " << encrypt_text(plaintext, n) << std::endl;
}
