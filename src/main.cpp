#include <iostream>
#include <string>
#include <fstream>

using namespace std;
using namespace ios;

static char *dt4 = "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\">";
static char *dt5 = "<!DOCTYPE html>";

int main(int argc, char *argv[])
{
    cout << "HTML Document Generator" << endl
         << "Version 0.1.2" << endl;
    if (argv[0] != "")
    {
        try
        {
            fstream doc;
            std::cout << "[INFO] Generating HTML Document..." << std::endl;
            if (argv[1] == "-html4")
            {
                doc.open(argv[0], ios::out | ios::in)
                cout << "[INFO] Using HTML 4.01" << endl;
            }
            else
            {
                fwrite(dt5, sizeof(dt5), sizeof(dt5), doc);
                std::cout << "[WARN] No HTML Version specified. Defaulting to HTML5" << std::endl;
            }
            close();
        }
        catch (const std::exception &e)
        {
            cout << "[ERR] HTML Document Creation failed." << endl;
        }
    }
    else
    {
        std::cout << "Usage: htgen <output.html> [-html4|-xhtml]" << std::endl;
    }
    return 0;
}
