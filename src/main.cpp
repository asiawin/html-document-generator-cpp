#include <iostream>
#include <string>
#include <fstream>
//the following are UBUNTU/LINUX, and MacOS ONLY terminal color codes.
#define RESET "\033[0m"
#define BLACK "\033[30m"              /* Black */
#define RED "\033[31m"                /* Red */
#define GREEN "\033[32m"              /* Green */
#define YELLOW "\033[33m"             /* Yellow */
#define BLUE "\033[34m"               /* Blue */
#define MAGENTA "\033[35m"            /* Magenta */
#define CYAN "\033[36m"               /* Cyan */
#define WHITE "\033[37m"              /* White */
#define BOLDBLACK "\033[1m\033[30m"   /* Bold Black */
#define BOLDRED "\033[1m\033[31m"     /* Bold Red */
#define BOLDGREEN "\033[1m\033[32m"   /* Bold Green */
#define BOLDYELLOW "\033[1m\033[33m"  /* Bold Yellow */
#define BOLDBLUE "\033[1m\033[34m"    /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */
#define BOLDCYAN "\033[1m\033[36m"    /* Bold Cyan */
#define BOLDWHITE "\033[1m\033[37m"   /* Bold White */

using namespace std;

char *dt4 = "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\">";
char *dt5 = "<!DOCTYPE html>";
char data[100];
char *filename;
char *htver;
char *title;
int main(int argc, char *argv[])
{
    cout << "HTML Document Generator" << endl
         << "Version 0.1.2" << endl;
    if (argv[0] != "")
    {
        try
        {
            ofstream outfile;
            outfile.open("document.html");
            std::cout << GREEN << "Enter the HTML Version. [Defaults to HTML5]\n" << RESET << "-> ";
            cin >> htver;
            cout << GREEN << "Enter document title" << RESET << ">> " << endl;
            cin >> title;
            if (htver == "html5")
            {

                outfile << dt5 << "<html>\n<head>\n<title>" << title << "</title>\n<meta name=\"generator\" content=\"HTMLDocGen 0.1.3\" \/></head>\n<body>\n<!-- Generated with HTMLDocGen 0.1.2 --></body></html>"
                        << endl;
            }
            else if (htver == "html4.01")
            {
            }
            else if (htver == "html4")
            {
            }
            else
            {
                cout << MAGENTA << "[WARN] Unknown HTML version. Defaulting to HTML5" << RESET << endl;
            }

            cout << "[INFO] Using HTML 4.01" << endl;

            std::cout << "[WARN] No HTML Version specified. Defaulting to HTML5" << std::endl;

            outfile.close();
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
