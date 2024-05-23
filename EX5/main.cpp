#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
using namespace std;

class myString {
private:
    string m_str;
public:
    myString(string str) {
        m_str = str;
    }
};

class ReadClass {
private:
    vector<string> classNames;

    void readFile(const string &filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Failed to open file: " << filename << endl;
            return;
        }

        string line;
        string fileContent;
        while (getline(file, line)) {
            fileContent += line + "\n";
        }

        file.close();
        findClassNames(fileContent);
    }

    void findClassNames(const string &content) {
        regex classRegex("\\bclass\\s+([a-zA-Z_]\\w*)\\s*\\{");
        smatch match;
        string::const_iterator searchStart(content.cbegin());

        while (regex_search(searchStart, content.cend(), match, classRegex)) {
            classNames.push_back(match[1]);
            searchStart = match.suffix().first;
        }
    }

public:
    ReadClass(const string &filename) {
        readFile(filename);
    }

    void showClass() const {
        cout << classNames.size() << " class in main.cpp" << endl;
        for (const string &className : classNames) {
            cout << className << endl;
        }
    }
};

int main() {
    ReadClass rfile("main.cpp");
    rfile.showClass();
    return 0;
}
