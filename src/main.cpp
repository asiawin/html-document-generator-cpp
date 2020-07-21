#include <iostream>
#include <string>
#include <fstream>
#include <regex>

#ifdef _WIN32
#include <windows.h>
#endif
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
string title;
char pBuf[256];
size_t len = sizeof(pBuf);
 regex reg("docgen.exe");
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
             cout << GREEN << "Enter document title" << RESET << ">> " << endl;
             cin >> title;

             outfile << dt5 << "\n<html>\t\n<head>\t\n<title>" << title << "</title>\t\n<meta name=\"generator\" content=\"HTMLDocGen 0.1.3\" \/></head>\t\n<body>\t\n<!-- Generated with HTMLDocGen 0.1.2 -->\t\n</body>\t\n</html>\t\n"
                     << endl;

             outfile.close();
#ifdef __linux__
            int bytes = MIN(readlink("/proc/self/exe", pBuf, len), len - 1);
            if (bytes >= 0)
                pBuf[bytes] = '\0';
            cout << GREEN << "Successfully created HTML Page. File location: " << pBuf << RESET << endl;
#elif _WIN32
            int bytes = GetModuleFileName(NULL, pBuf, len);
            cout << GREEN << "Successfully created HTML Page. File location: " << BOLDCYAN << regex_replace(pBuf, reg, "") << "document.html" << RESET;
#else

#endif
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
