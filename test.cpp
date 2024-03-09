#include <iostream>
#include <unordered_map>

int main() {
  std::string str = "HUFFMANCODES";
  std::unordered_map<char, int> freq;

  for (char c : str) {
    freq[c]++;
  }

  for (auto pair : freq) {
    std::cout << pair.first << ": " << pair.second << std::endl;
  }

  return 0;
}