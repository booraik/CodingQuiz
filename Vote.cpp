
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
using std::string;
using std::map;
using std::vector;

int main()
{
    // 1. Input candidates
    map<string,int> votes;
    string name;
    while( cin >> name )
    {
        map<string,int>::iterator it = votes.find(name);
        if( it != votes.end() )
            it->second += 1;
        else
            votes.insert( std::pair<string,int>(name,1) );
    }

    // 2. Get max vote number
    int max_num = 0;
    for( map<string,int>::iterator it=votes.begin(); it!=votes.end(); ++it )
        if( max_num < it->second )
            max_num = it->second;

    // 3. Get elected list
    vector<string> elected;
    for( map<string,int>::iterator it=votes.begin(); it!=votes.end(); ++it )
        if( it->second == max_num )
            elected.push_back( it->first );
    
    // 4. Sort elected list by ascending order
    sort( elected.begin(), elected.end() );
    
    // 5. Print fo head the pool
    for( unsigned int i=0; i < elected.size(); i++ )
        cout << elected[i] << endl;
    
    return 0;
}

