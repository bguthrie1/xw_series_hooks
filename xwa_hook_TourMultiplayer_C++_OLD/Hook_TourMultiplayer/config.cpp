#include "config.h"
#include <fstream>
#include <algorithm>
#include <cctype>

using namespace std;

string GetStringWithoutExtension(const string& str)
{
	auto b = str.find_last_of('.');

	return str.substr(0, b);
}

vector<string> GetFileLines(const string& path, const string& section)
{
	vector<string> values;

	ifstream file(path);

	if (file)
	{
		string line;
		bool readSection = section.empty();

		while (getline(file, line))
		{
			line.erase(remove_if(line.begin(), line.end(), isspace), line.end());

			if (!line.length())
			{
				continue;
			}

			if (line[0] == '#' || line[0] == ';' || (line[0] == '/' && line[1] == '/'))
			{
				continue;
			}

			if (line[0] == '[' && line[line.length() - 1] == ']')
			{
				string name = line.substr(1, line.length() - 2);

				if (_stricmp(name.c_str(), section.c_str()) == 0)
				{
					readSection = true;
				}
				else
				{
					readSection = false;
				}
			}
			else
			{
				if (readSection)
				{
					values.push_back(line);
				}
			}
		}
	}

	return values;
}

string GetFileKeyValue(const vector<string>& lines, const string& key)
{
	for (const auto& line : lines)
	{
		int pos = line.find("=");

		if (pos == -1)
		{
			continue;
		}

		string name = line.substr(0, pos);

		if (!name.length())
		{
			continue;
		}

		if (_stricmp(name.c_str(), key.c_str()) == 0)
		{
			string value = line.substr(pos + 1);
			return value;
		}
	}

	return string();
}

int GetFileKeyValueInt(const vector<string>& lines, const string& key, int defaultValue)
{
	string value = GetFileKeyValue(lines, key);

	if (value.empty())
	{
		return defaultValue;
	}

	return stoi(value, 0, 0);
}

vector<string> Tokennize(const string& str)
{
	const string delimiters = ",;";

	vector<string> tokens;

	string::size_type lastPos = str.find_first_not_of(delimiters, 0);
	string::size_type pos = str.find_first_of(delimiters, lastPos);

	while (string::npos != pos || string::npos != lastPos)
	{
		string value = str.substr(lastPos, pos - lastPos);
		tokens.push_back(value);

		lastPos = str.find_first_not_of(delimiters, pos);
		pos = str.find_first_of(delimiters, lastPos);
	}

	return tokens;
}

vector<vector<string>> GetFileListValues(const vector<string>& lines)
{
	vector<vector<string>> values;

	for (const string& line : lines)
	{
		values.push_back(Tokennize(line));
	}

	return values;
}

vector<int> GetFileListIntValues(const vector<string>& lines)
{
	vector<int> values;

	for (const string& line : lines)
	{
		int value = stoi(line);
		values.push_back(value);
	}

	return values;
}

vector<unsigned short> GetFileListUnsignedShortValues(const vector<string>& lines)
{
	vector<unsigned short> values;

	for (const string& line : lines)
	{
		unsigned short value = (unsigned short)stoi(line);
		values.push_back(value);
	}

	return values;
}