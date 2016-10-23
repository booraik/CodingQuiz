
#include <iostream>
#include <vector>

using namespace std;

unsigned long int calculate_brackets( string& brackets, const char token_end = '\0' );

int main()
{
    // 1. Input brackets list
    int brackets_list_num;
    cin >> brackets_list_num;
    if( brackets_list_num <= 0 )
    {
        cout << "brackets number must over than 0." << endl;
        return -1;
    }
    vector<string> brackets_list;
    string bracket;
    while( cin >> bracket )
    {
        brackets_list.push_back(bracket);
        if( brackets_list.size() == (unsigned int)brackets_list_num )
            break;
    }

    for( vector<string>::iterator it = brackets_list.begin();
            it != brackets_list.end();
            ++it )
    {
        // 2. Calculate Brackets and print
        cout << calculate_brackets( *it, 0 ) << endl;
    }

    return 0;
}

#define MOD_VALUE 100000000
typedef struct 
{
    int value;
    char token_open;
    char token_close;
} oper_bracket;
const static oper_bracket OPERATIONS[3] = 
{
    { 1, '(', ')' },
    { 2, '{', '}' },
    { 3, '[', ']' },
};

unsigned long int calculate_brackets( string& brackets, const char token_end )
{
    unsigned long int ret = 0;
    int oper_idx = 0;

    while( (brackets.size()!=0) && (brackets[0]!=token_end) )
    {
        char token_open = brackets[0];
        if( token_open == OPERATIONS[0].token_open )
            oper_idx = 0;
        else if( token_open == OPERATIONS[1].token_open )
            oper_idx = 1;
        else if( token_open == OPERATIONS[2].token_open )
            oper_idx = 2;
        brackets.erase( 0, 1 );

        if( brackets[0] == OPERATIONS[oper_idx].token_close )
            ret += OPERATIONS[oper_idx].value;
        else
        {
            unsigned long int ret_add 
                = calculate_brackets( brackets, OPERATIONS[oper_idx].token_close );

            if( ret_add == 0 )
                return 0;
            else if( brackets.size() == 0 )
                return 0;
            else
                ret += OPERATIONS[oper_idx].value * ret_add;
        }
        brackets.erase( 0, 1 );
    }

    if( ret > MOD_VALUE )
        ret %= MOD_VALUE;

    return ret;
}

