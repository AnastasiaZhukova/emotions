#include "emotional_lib.h"
#include "text_lib.h"

vector<association> form_map(char*sentiments)
{
	cout << "HERE FORM MAP" << endl;
	vector<association> sent;
	association temporary;
	char *token = strtok(sentiments, ",\n");
	int flag = 0;
	while (token != NULL)
	{
		if (flag == 0)
		{
			temporary.key = token;
			flag = 1;
			token = strtok(NULL, ",\n");
			continue;

		}

		if (flag == 1)
		{
			temporary.value = atof(token);
			sent.push_back(temporary);
			flag = 0;
			token = strtok(NULL, ",\n");
			continue;
		}

	}

	return sent;
}

void map_sort(association*sent, int size)
{
	cout << "Map sort:" << endl;

	bool sorted = false;
	while (!sorted)
	{
		sorted = true;
		for (int i = 0; i < size - 1; i++)
		{
			if (strlen(sent[i].key) < strlen(sent[i + 1].key))
			{
				swap(sent[i], sent[i + 1]);
				sorted = false;
			}
		}
	}

	/*Quick sort: stack overflow*/

	//int i = left;
	//int j = right;
	//int middle = (i + j) / 2;
	//int midlen = strlen(sent[middle].key);
	//while (i < j)
	//{
	//	while (strlen(sent[i].key) >= midlen) i++;
	//	while (strlen(sent[j].key) <= midlen) j--;
	//	if (i < j)
	//	{
	//		if (strlen(sent[i].key) < strlen(sent[j].key))
	//		{
	//			swap(sent[i], sent[j]);
	//			i++; j--;
	//		}
	//	}
	//}
	//if (i < right)
	//{
	//	map_sort(sent, i, right);
	//}
	//if (j > left)
	//{
	//	map_sort(sent, left, j);
	//}

}

double map_search(char*file, vector <association> sent)
{
	cout << "HERE MAP SEARCH" << endl;
	double sum = 0;
	int count;
	int total = 0;
	for (int i = 0; i<sent.size(); i++)
	{
		count = 0;
		count = search_word(sent[i].key, file);
		if (count != 0) { cout << sent[i].key << "-->" << sent[i].value << endl; sum += (sent[i].value)*count; total += count; }

	}
	cout << "TOTAL " << total << endl;
	cout << "SUM " << sum << endl;
	if (total != 0)	return sum / total;
	else return 0;
}
