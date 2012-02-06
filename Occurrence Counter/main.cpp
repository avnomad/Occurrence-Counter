#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;



int main(int argc, char **argv)
{
	FILE *searchFile;
	int c;
	char *p;
	unsigned int count = 0;

	if(argc!=3 || !*argv[1])
		cout<<"Wrong usage!\nThe correct argumants are:\n"<<argv[0]<<" [(nonempty) search string] [file to search]"<<endl;
	else
	{
		cout<<"Counting occurances of the string \""<<argv[1]<<"\" in the file \""<<argv[2]<<"\"..."<<endl;
		if(searchFile = fopen(argv[2],"r"))
		{
			p = argv[1];
			while((c = fgetc(searchFile)) != EOF)
			{
				if(*p == c)
				{
					p++;
					if(!*p)
					{
						p = argv[1];
						count++;
					}
				}
				else
					p = argv[1];
			}
			cout<<count<<" occurances of the string \""<<argv[1]<<"\" were found in the file \""<<argv[2]<<'\"'<<endl;
			fclose(searchFile);
		}
		else
			cout<<"Error opening the file!"<<endl;
	}
	system("PAUSE");
	return 0;
}