/**
 * code jam 2018
 * task 1: Saving the universe again
 * https://codejam.withgoogle.com/2018/challenges/00000000000000cb/dashboard
 *
 * @s_egahi
 *
 * this was salvation!
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

/**
 * returns the amount of damage done by an algortithm entered as
 * as string
 */
long long int damageScore(string program);

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

    int test;
    infile >> test;

    char c;
    long long int numBuffer;
    string lineBuffer;
    bool done = false;
    long long int damage = 0, hack = 0;


    for (int i = 0; i < test; i++)
    {
        infile >> c;
        numBuffer = atoi(&c);

        getline(infile, lineBuffer);
        done = false;
        hack = 0;

        for (int j = 1, k = lineBuffer.length(); j < k; j++)
        {
            // calculate damage
            damage = damageScore(lineBuffer);

            // no hack needed
            if (damage <= numBuffer)
            {
                done = true;
                break;
            }
            else
            {
                // swap adjacent 'C' and 'S' command to reduce value of damage
                if (lineBuffer[j - 1] == 'C' && lineBuffer[j] == 'S')
                {
                    swap(lineBuffer[j - 1], lineBuffer[j]);
                    hack++;

                    // run check over new algorithm
                    j -= 2;
                }
            }
        }

        if (i > 0)
        {
            outfile << endl;
        }

        // damages bearable by sheild
        if (done)
        {
            outfile << "Case #" << i + 1 << ": " << hack;
        }

        // universe is doomed
        else
        {
            outfile << "Case #" << i + 1 << ": IMPOSSIBLE";
        }
    }

    infile.close();
    outfile.close();

    // success
    return 0;
}

/**
 * returns the amount of damage done by an algortithm entered as
 * as string
 */
long long int damageScore(string program)
{
    long long int damage = 0, value = 1;

    for (long long int i = 0, j = program.length(); i < j; i++)
    {
        if (program[i] == 'C')
        {
            value *= 2;
        }
        else if (program[i] == 'S')
        {
            damage += value;
        }
    }

    return damage;
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