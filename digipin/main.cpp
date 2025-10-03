#include <iostream>
#include <iomanip>
#include <string>
#include <array>
#include <cmath>
#include <limits>
#include "digipin.h"
using namespace std;

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        freopen(argv[1], "r", stdin);
    }

    int op;
    cin >> op;

    if (op == 0)
    {
        // Encode operation
        double lat, lon;
        cin >> lat >> lon;

        try
        {
            string code = Digipin::encode(lat, lon);
            cout << "Encoded DIGIPIN: " << code << '\n';
        }
        catch (const exception &e)
        {
            cerr << "Error: " << e.what() << '\n';
        }
    }
    else if (op == 1)
    {
        // Decode operation
        string code;
        cin >> code;

        try
        {
            auto box = Digipin::decode(code);
            cout << fixed << setprecision(6);
            cout << "Bounding Box Center: "
                 << box.first << " " << box.second;
        }
        catch (const exception &e)
        {
            cerr << "Error: " << e.what() << '\n';
        }
    }
    else
    {
        cerr << "Invalid operation number. Use 0 for encode, 1 for decode.\n";
    }

    return 0;
}
