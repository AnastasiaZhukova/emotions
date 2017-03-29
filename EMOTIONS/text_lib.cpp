#include "text_lib.h"
#include "emotional_lib.h"
#include <iostream>
using namespace std;
char *read_file(const char filename[], bool&found, bool add_char)
{
	fstream f(filename, ios::binary | ios::in);
	if (f.is_open())
	{
		found = true;
		f.seekg(0, ios::end);
		int size = f.tellg();
		f.close();
		//cout << "SIZE: " << size << endl
		char*file;
		fstream fin(filename, ios::in);
		if (add_char)
		{
			file = new char[size + 2];
			file[0] = ' ';
			fin.getline(file + 1, size + 1, '\0');
		}
		else
		{
			file = new char[size + 1];
			fin.getline(file, size + 1, '\0');
		}
		fin.close();
		return file;
	}
	else { cout << "File not found" << endl; return 0; }
}
void write_in_file(const char filename[], association*sent, int size)
{
	fstream f(filename, ios::trunc | ios::out);
	for (int i = 0; i < size; i++)
	{
		f << sent[i].key;
		f << ", ";
		f << sent[i].value;
		f << '\n';

	}
	f << '\0';
	f.close();
}
void tolow(char*text)
{
	for (int i = 0; i < strlen(text); i++)
	{
		if (text[i] >= 65 && text[i] <= 90)
		{
			text[i] = text[i] + 32;
		}
	}
}
void search_spaces(char*text)
{
	//cout << "here search spaces";
	int size = strlen(text);
	int num;
	int j;
	for (int i = 0; i < strlen(text) - 1; i++)
	{
		num = 0;
		if (text[i] == ' ')
		{
			j = i + 1;
			while (true)
			{
				if (text[j] == ' ')
				{
					num++;
					j++;
				}
				else break;
			}
			memmove(text + i + 1, text + i + num + 1, strlen(text) - num - i);
			//text[strlen(text)-num+1] = '\0';
		}

	}
}
int search_word(char*word, char*file)
{
	bool check;
	bool first_check_digit, last_check_digit;
	int count = 0;
	char *search = file, *found_ptr;
	bool result;
	while ((found_ptr = strstr(search, word)) != NULL)
	{
		first_check_digit = (((int)(*(found_ptr - 1))) > 47) && (((int)(*(found_ptr - 1))) < 58); //returns true if symbol before is digit
		last_check_digit = ((((int)(*(found_ptr + strlen(word)))) > 47) && (((int)(*(found_ptr + strlen(word)))) < 58)); //-/-symbol after is
		check = (((int)(*(found_ptr - 1)) < 97 || (int)(*(found_ptr - 1)) > 122) && (((int)(*(found_ptr + strlen(word))) < 96 || (int)(*(found_ptr + strlen(word))) > 122) && (int)(*(found_ptr + strlen(word)) != 39))); //retruns true if symbol before and after is not a letter
		if (check && (!first_check_digit) && (!last_check_digit))
		{
			//cout << endl << "FILE BEFORE " << endl << file << endl;
			count++;
			for (int i = 0; i < strlen(word); i++)
			{
				*(found_ptr + i) = ' '; //replace word with spaces
			}
			search = found_ptr + strlen(word);
			//cout << endl << "FILE AFTER " << endl << file << endl;
			continue;
		}
		search = found_ptr + 1;
	}
	if (count != 0) cout << count << endl;
	return count;
}
