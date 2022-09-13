#pragma once

#include <string>
#include <vector>

using namespace std;

string GetStringWithoutExtension(const string& str);
vector<string> GetFileLines(const string& path, const string& section = string());
string GetFileKeyValue(const vector<string>& lines, const string& key);
int GetFileKeyValueInt(const vector<string>& lines, const string& key, int defaultValue = 0);
vector<string> Tokennize(const string& str);
vector<vector<string>> GetFileListValues(const vector<string>& lines);
vector<int> GetFileListIntValues(const vector<string>& lines);
vector<unsigned short> GetFileListUnsignedShortValues(const vector<string>& lines);