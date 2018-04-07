/**
 * code jam 2018
 * task 2: trouble sort
 * https://codejam.withgoogle.com/2018/challenges/00000000000000cb/dashboard
 *
 * @s_egahi
 *
 * this was trouble sort!
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

/**
 * swaps characters
 */
void swap(char &first, char &second);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "USAGE: ./salvation infile\n";
        return 1;
    }

    ifstream infile (argv[1]);
    if(!infile)
    {
        cout << "Couldn't open " << argv[1] << endl;
        return 2;
    }

    ofstream outfile ("output.txt");
    if(!outfile)
    {
        cout << "Couldn't open outfile\n";
        return 3;
    }

    infile.close();
    outfile.close();

    // success
    return 0;
}

/**
 * swaps characters
 */
void swap(char &first, char &second)
{
    char temp = first;
    first = second;
    second = temp;
}