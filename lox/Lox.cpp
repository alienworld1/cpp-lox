#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void runFile(const string& path);
void runPrompt();
void run(const string& source);
void error(int line, const string& message);
void report(int line, const string& where, const string& message);

static bool hadError = false;

int main(int argc, const char** argv) {
    if (argc > 2) {
      cout << "Usage: cpplox [script]\n";
      exit(64); 
    } else if (argc == 2) {
      runFile(string(argv[1]));
    } else {
      runPrompt();
    }

    return 0;
}

void runFile(const string& path) {
  ifstream file(path, ios::binary);
  if (!file) {
    throw runtime_error("Unable to open file!");
  }

  stringstream buffer;
  buffer << file.rdbuf();
  string content = buffer.str();

  run(content);

  if (hadError) {
    exit(65);
  }
}

void runPrompt() {
  string line;

  while (true) {
    cout << "> ";
    if (!getline(cin, line)) {
      break;
    }
    run(line);
    hadError = false;
  }
  
}

void run(const string& source) {
  cout << "code = " << source << endl;
}

void error(int line, const string& message) {
  report(line, "", message);
}

void report(int line, const string& where, const string& message) {
  cerr << "[line " << line << "] Error" << where << ": " << message << endl;
  hadError = true; 
}
