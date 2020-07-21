#include <iostream>
#include <string>
#include <fstream>

using namespace std;

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
            FILE *doc = fopen(argv[0], "w+");
            std::cout << "[INFO] Generating HTML Document..." << std::endl;
            if (argv[1] == "-html4")
            {
                fwrite(dt4, sizeof(dt4), sizeof(dt4), doc);
                cout << "[INFO] Using HTML 4.01" << endl;
            }
            else
            {
                fwrite(dt5, sizeof(dt5), sizeof(dt5), doc);
                std::cout << "[WARN] No HTML Version specified. Defaulting to HTML5" << std::endl;
            }
            //fclose(doc);
        }
        catch (const std::exception &)
        {
        }
    }
    else
    {
        std::cout << "Usage: htgen <output.html> [-html4|-xhtml]" << std::endl;
    }
    return 0;
}
