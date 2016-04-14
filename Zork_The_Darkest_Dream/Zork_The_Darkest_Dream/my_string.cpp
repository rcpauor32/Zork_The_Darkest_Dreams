#include "my_string.h"
#include <ctype.h>
#include <assert.h>

String::String(unsigned int mem) {
	string = new char[mem + 1];
	string[mem] = '\0';
}

String::String(char* c_str) {
	assert(c_str != nullptr);
	this->capacity = strlen(c_str) + 1;
	this->string = new char[capacity];
	strcpy_s(this->string, capacity, c_str);
}

String::String(String& str){
	assert(str.string != nullptr);
	capacity = strlen(str.string) + 1;
	string = new char[capacity];
	strcpy_s(this->string, capacity, str.string);
}

int String::size() {
	return sizeof(string) / sizeof(string[0]);
}

const int String::length() {
	return strlen(this->string);
}

bool String::empty() const {
	return string[0] == '\0';
}

void String::clear() {
	delete[] string;
}

char* String::c_str() {
	return string;
}

String::~String() {
};

int String::GetnArgs() {
	int n_args = 1;
	int n_char = 0;
	
	while (string[n_char] != ' ') {
		n_char++;
	}

	for (int i = n_char; i < strlen(string); i++){
		if (string[i] == ' ')
			n_args++;
	}

	return n_args;
}

char* String::toLower() {
	char* ret = new char[capacity];
	for (int i = 0; i < capacity; i++) {
		if (string[i] > 'A' && string[i] < 'Z')
			ret[i] = string[i] + 32;
	}
	return ret;
}

char* String::GetChoosenArg(int n_arg) {
	char* ret = new char[capacity];
	uint i = 0;
	uint k = 0;
	uint n_ch = 0;
	n_arg--;
	if (n_arg < 1) {
		for (n_ch = 0; string[n_ch - 1] != ' ' && string[n_ch] != '\0'; n_ch++) {
			ret[n_ch] = string[n_ch];
		}
		ret[n_ch - 1] = '\0';
	}

	else {
		while(i < strlen(string) && n_arg > 0) {
			if (string[i] == ' ')
				n_arg--;
			i++;
		}

		while (string[i] != '\0' && string[i] != ' ' && i < capacity) {
			ret[k] = string[i];
			i++;
			k++;
		}
		ret[k] = '\0';
	}
	

	return ret;
}
