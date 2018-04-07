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
 * sort values by pair wise comparison
 */
void sort(string &values);

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

    int test;
    infile >> test;

    long long number;
    string values;
    char buffer;
    bool ok;

    for (int i = 0; i < test; i++)
    {
        ok = true;
        values = "";
        infile >> number;

        for (int j = 0; j < number; j++)
        {
            infile >> skipws >> buffer;
            values += buffer;
        }

        sort(values);

        if (i > 0)
        {
            outfile << endl;
        }

        for (int j = 0; j < number - 1; j++)
        {
            if (values[j] > values[j + 1])
            {
                // numbers not sorted
                outfile << "Case #" << i + 1<< ": " << j;
                ok = false;
                break;
            }
        }

        if (ok)
        {
            outfile << "Case #" << i + 1<< ": OK";
        }
    }

    infile.close();
    outfile.close();

    // success
    return 0;
}

/**
 * sort values by pair wise comparison
 */
void sort(string &values)
{
    int length = values.length();

    for (int i = length; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (j + 2 >= length)
            {
                break;
            }

            if (values[j] > values[j + 2])
            {
                char temp = values[j];
                values[j] = values[j + 2];
                values[j + 2] = temp;
            }
        }
    }
}