#include <iostream>
#include <vector>

using namespace std;

vector<char> concat(vector<char>& str1, vector<char>& str2)
{
    vector<char> result;

    for (char c : str1) 
    {
        result.push_back(c);
    }
    for (char c : str2) 
    {
        result.push_back(c);
    }

    return result;
}

bool isEqual(vector<char>& str1, vector<char>& str2)
{
    if (str1.size() != str2.size()) 
    {
        return false;
    }

    for (int i = 0; i < str1.size(); i++) 
    {
        if (str1[i] != str2[i]) 
        {
            return false;
        }
    }

    return true;
}

int getSize(vector<char>& str)
{
    return str.size();
}

bool contains(vector<char>& str, char c)
{
    for (char ch : str) 
    {
        if (ch == c) 
        {
            return true;
        }
    }

    return false;
}
void insertChar(vector<char>& str, char c, int pos)
{
    str.insert(str.begin() + pos, c);
}

void replaceChar(vector<char>& str, char c, int pos)
{
    str.at(pos) = c;
}

void deleteChar(vector<char>& str, int pos)
{
    str.erase(str.begin() + pos);
}

vector<char> subString(vector<char>& str, int start, int end)
{
    vector<char> subStr;

    for (int i = start; i <= end && i < str.size(); i++) 
    {
        subStr.push_back(str[i]);
    }

    return subStr;
}

int main()
{
    const int MAX_LENGTH = 100;
    char str1[MAX_LENGTH], str2[MAX_LENGTH];

    cout << "Enter first string: ";
    cin.getline(str1, MAX_LENGTH);

    cout << "Enter second string: ";
    cin.getline(str2, MAX_LENGTH);

    vector<char> vec_str1, vec_str2;
    for (int i = 0; str1[i] != '\0'; i++) 
    {
        vec_str1.push_back(str1[i]);
    }
    for (int i = 0; str2[i] != '\0'; i++) 
    {
        vec_str2.push_back(str2[i]);
    }

    vector<char> result = concat(vec_str1, vec_str2);

    cout << "Result: ";
    for (char c : result) 
    {
        cout << c;
    }
    cout << endl;

    bool equal = isEqual(vec_str1, vec_str2);
    cout << "Strings are " << (equal ? "equal" : "not equal") << endl;

    int size = getSize(result);
    cout << "Result size is " << size << endl;

    char search_char;
    cout << "Enter a character to search for: ";
    cin >> search_char;

    bool found = contains(result, search_char);
    cout << "Character " << search_char << " is " << (found ? "" : "not ") << "found in the result." << endl;

    char ch;
    int pos;
    cout << "Enter a character to insert: ";
    cin >> ch;
    cout << "Enter the position to insert: ";
    cin >> pos;

    insertChar(result,ch,pos);
    cout << "After insertion is: ";
    for (char c : result) 
    {
        cout << c;
    }
    cout << endl;

    char newCh;
    cout << "Enter the position to replace: ";
    cin >> pos;
    cout << "Enter the new character: ";
    cin >> newCh;

    replaceChar(result,newCh,pos);
    cout << "After replacement: ";
    for (char c : result) 
    {
        cout << c;
    }
    cout << endl;

    int delPos;
    cout << "Enter the position of the character to delete: ";
    cin >> delPos;

    deleteChar(result, delPos);
    cout << "String after deletion: ";
    for (char c : result) 
    {
        cout << c;
    }
    cout << endl;

    int start, end;
    cout << "Enter the start position of the substring: ";
    cin >> start;
    cout << "Enter the end position of the substring: ";
    cin >> end;

    result = subString(result,start,end);
    cout << "Sub String is: ";
    for (char c : result) 
    {
        cout << c;
    }
    cout << endl;

    string x;
    cin >> x;

    return 0;
}