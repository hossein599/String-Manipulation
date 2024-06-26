#include <iostream>

using namespace std;

int strLength(const char* str) 
{
    int len = 0;
    while (str[len] != '\0') 
    {
        len++;
    }
    return len;
}

char* concat(const char* str1, const char* str2) 
{
    int len1 = strLength(str1);
    int len2 = strLength(str2);
    char* result = new char[len1 + len2 + 1];
    int i, j;
    for (i = 0; i < len1; i++) 
    {
        result[i] = str1[i];
    }
    for (j = 0; j < len2; j++) 
    {
        result[i + j] = str2[j];
    }
    result[i + j] = '\0';
    return result;
}

bool isEqual(const char* str1, const char* str2) 
{
    int i = 0;
    while (str1[i] == str2[i]) 
    {
        if (str1[i] == '\0') 
        {
            return true;
        }
        i++;
    }
    return false;
}

void insert(char* str, char ch, int pos) 
{
    int len = strLength(str);
    for (int i = len; i >= pos; i--) 
    {
        str[i+1] = str[i];
    }
    str[pos] = ch;
}

void replace(char* str, int pos, char ch) 
{
    str[pos] = ch;
}

void deleteChar(char* str, int pos) 
{
    int len = strLength(str);
    for (int i = pos; i < len - 1; i++) 
    {
        str[i] = str[i+1];
    }
    str[len - 1] = '\0';
}

char* substring(const char* str, int start, int end) 
{
    int len = strLength(str);
    int subLen = end - start + 1;
    char* subStr = new char[subLen + 1];
    for (int i = 0; i < subLen; i++) 
    {
        subStr[i] = str[start + i];
    }
    subStr[subLen] = '\0';
    return subStr;
}

int main() 
{
    char str1[100], str2[100];

    cout << "Enter string 1: ";
    cin.getline(str1, 100);

    cout << "Enter string 2: ";
    cin.getline(str2, 100);

    char* concatStr = concat(str1, str2);
    cout << "Concatenation: " << concatStr << endl;

    bool cmp = isEqual(str1, str2);
    if (cmp) 
    {
        cout << "Strings are equal\n";
    }
    else 
    {
        cout << "they are not equal\n";
    }

    char ch;
    int pos;
    cout << "Enter a character to insert: ";
    cin >> ch;
    cout << "Enter the position to insert: ";
    cin >> pos;

    insert(concatStr, ch, pos);
    cout << "String after insertion: " << concatStr << endl;

    char newCh;
    cout << "Enter the new character: ";
    cin >> newCh;
    cout << "Enter the position to insert: ";
    cin >> pos;


    replace(concatStr, pos, newCh);
    cout << "String after replacement: " << concatStr << endl;

    int delPos;
    cout << "Enter the position of the character to delete: ";
    cin >> delPos;

    deleteChar(concatStr, delPos);
    cout << "String after deletion: " << concatStr << endl;

    int start, end;
    cout << "Enter the start position of the substring: ";
    cin >> start;
    cout << "Enter the end position of the substring: ";
    cin >> end;

    char* substr = substring(concatStr, start, end);
    cout << "String Substring: " << substr << endl;

    string x;
    cin >> x;

    return 0;
}