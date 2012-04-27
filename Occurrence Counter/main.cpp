//	Copyright (C) 2008, 2012 Vaptistis Anogeianakis <el05208@mail.ntua.gr>
/*
 *	This file is part of Occurrence Counter.
 *
 *	Occurrence Counter is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	Occurrence Counter is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with Occurrence Counter.  If not, see <http://www.gnu.org/licenses/>.
 */

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
		cout<<"Wrong usage!\nThe correct arguments are:\n"<<argv[0]<<" [(nonempty) search string] [file to search]"<<endl;
	else
	{
		cout<<"Counting occurrences of the string \""<<argv[1]<<"\" in the file \""<<argv[2]<<"\"..."<<endl;
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
						p = argv[1];	// no overlapping occurrences
						count++;
					}
				}
				else
					p = argv[1];	// may miss occurrences in some cases...
			}
			cout<<count<<" occurrences of the string \""<<argv[1]<<"\" were found in the file \""<<argv[2]<<'\"'<<endl;
			fclose(searchFile);
		}
		else
			cout<<"Error opening the file!"<<endl;
	}
	system("PAUSE");
	return 0;
}