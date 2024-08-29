#include <iostream>
#include <string>

using namespace std;

void FBI(string s);

int main() 
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	FBI(s);
	return 0;
}

void FBI(string s) 
{
	if (s.length() > 1)
	{
		FBI(s.substr(0, s.length()/2));
		FBI(s.substr(s.length()/2, s.length()/2));
	}
	if (s == string(s.length(), '0')) 
    {
        cout <<'B';
        return;
    }
	if (s == string(s.length(), '1'))
    {
        cout <<'I';
        return;
    }
	cout <<'F';
    return;
}