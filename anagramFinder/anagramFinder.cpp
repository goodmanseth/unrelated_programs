#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;
typedef unordered_map<string, vector<string> > Dict;

int main (int argc, char **argv) {
	Dict dictionary;

	// file input
	ifstream in_file("words.txt");
	if (!in_file) {
		cerr << "input file not found" << endl;
		exit(1);
	}

	string s, sorted_s;
	while (in_file >> s) {
		sorted_s = s;
		sort(sorted_s.begin(), sorted_s.end());
		dictionary[sorted_s].push_back(s);
	}

	Dict::iterator it;
	for (it = dictionary.begin(); it != dictionary.end(); ++it) {
		if (it->second.size() > 1) {
			for (int j = 0; j < it->second.size(); ++j) {
				cout << it->second[j] << " ";
			}
            cout << endl;
	    }
    }
}
