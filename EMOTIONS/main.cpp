#define _CRT_SECURE_NO_WARNINGS
#include"text_lib.h"
#include"emotional_lib.h"
#include <cstdlib>

using namespace std;
const char sentiments_text[] = "sentiments.txt";
const char poem_text[] = "temp_poem.txt";


int main()
{
	bool sent_found = false, poem_found = false;
	char *sentiments = read_file(sentiments_text, sent_found, false);
	if (sent_found)
	{
		if (strlen(sentiments) != 0)
		{
			char *poem = read_file(poem_text, poem_found, true);
			if (poem_found)
			{
				if (strlen(poem) != 0)
				{
					tolow(poem);
					//cout << poem;
					search_spaces(poem);
					cout << "POEM:";
					cout << endl << poem << endl;
					//cout << poem;
					if (strlen(poem) != 0)
					{
						vector<association> sent = form_map(sentiments);
						/*for (int i = 0; i < sent.size(); i++)
						{
						cout << sent[i].key << "-->" << sent[i].value << endl;
						}*/
						map_sort(&sent[0], sent.size());
						//write_in_file(temp, &sent[0],sent.size());

						cout << "EMOTIONAL COLORING: " << map_search(poem, sent) << endl;
						//cout <<"end "<< poem << endl;
					}
					else cout << "Poem is empty" << endl;
				}
				else cout << "Poem is empty" << endl;
			}
			else cout << "Poem not found" << endl;
		}
		else cout << "Sentiments is empty" << endl;
	}
	else cout << "Sentiments not found" << endl;
	cout << endl;
	system("pause");
	return 0;
}



//tests

/*,,,,,,,,,,,,,,,,,,,,,,,,,,




abandoned abandoned person


result:
1
abandoned person-->-0.375
1
abandoned-->-0.375
TOTAL 2
SUM -0.75
EMOTIONAL COLORING: -0.3755*/

/*











,
result:
TOTAL 0
SUM 0
EMOTIONAL COLORING: 0
*/

/*
attention deficit hyperactivity             disorder     immaculate conception of the virgin mary

result:
1
attention deficit hyperactivity disorder-->0.5
1
immaculate conception of the virgin mary-->-0.25
TOTAL 2
SUM 0.25
EMOTIONAL COLORING: 0.125
*/

/*
attention deficit hyperactivity disorder|||||immaculate conception of the virgin mary


result:
1
attention deficit hyperactivity disorder
1
immaculate conception of the virgin mary
TOTAL 2
SUM 0.25
EMOTIONAL COLORING: 0.125
*/

/*
result:
Poem is empty
*/

/*
ii

i

i   i

result:
3
i-->-0.25
TOTAL 3
SUM -0.75
EMOTIONAL COLORING: -0.25
*/