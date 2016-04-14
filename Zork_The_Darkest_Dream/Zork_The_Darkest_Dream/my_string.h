#ifndef __MY_STRING_H__
#define	__MY_STRING_H__

#include <string.h>

typedef unsigned int uint;

class String {
private:
	char* string;

public:
	uint capacity;

	String(){};
	String(unsigned int mem);
	String(char* c_str1);
	String(String &str);
	virtual ~String();

public:
	int size();
	const int length();
	bool empty() const;
	void clear();
	char* c_str();
	int GetnArgs();
	char* GetChoosenArg(int n_arg);
	char* toLower();


	bool String::operator==(const char* c_str) const {
		return strcmp(this->string, c_str) == 0;
	}

	bool String::operator==(const String& str) const {
		return strcmp(this->string, str.string) == 0;
	}

	const String& String::operator=(const String& str) {
		if (this->capacity != str.capacity) {
			delete[] this->string;
			capacity = strlen(str.string) + 1;
			string = new char[capacity];
		}
		strcpy_s(string, str.capacity, str.string);
		return *this;
	}

	const String& String::operator=(const char* c_str) {
		if (this->capacity != strlen(c_str) + 1) {
			delete[] this->string;
			capacity = strlen(c_str) + 1;
			string = new char[capacity];
		}
		strcpy_s(string, capacity, c_str);
		return *this;
	}

	const String& String::operator-(char* c_str) {
		char* aux = new char[capacity];
		int k = 0;
		for (int i = 0; i < capacity; i++) {
			if (string[i] != c_str[k]) {
				aux[i] = string[i];
			}
			else {
				i--;
				k++;
			}
		}
		return aux;
	}

};

#endif