#include <iostream>
#include <cstring>
using namespace std;
class String {
private:
    static int count;
    char* str;
    int length;
public:
    String() : String(80) {}
    String(int size) {
        str = new char[size + 1];
        length = size;
        count++;
    }
    String(const char* s) {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
        count++;
    }
    ~String() {
        delete[] str;
        count--; 
    }
    void input() {
        cout << "Enter a string: ";
        cin.getline(str, length);
    }
    void output() {
        cout << "String: " << str << endl;
    }
    static int getCount() {
        return count;
    }
};
int String::count = 0; 
int main() {
    String s1;
    String s2(50); 
    String s3("Hello");
    s1.input(); 
    s1.output(); 
    cout << "Number of String objects created: " << String::getCount() << endl;
    return 0;
}