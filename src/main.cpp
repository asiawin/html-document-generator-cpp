#include <iostream>
#include <regex>
#include <bitset>
#include <vector>
#include <ccomplex>
#include <sys/stat.h>
#include <unistd.h>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    if (sizeof(argv[0]) != 0)
    {
        try
        {
            FILE doc = fopen(argv[0], "w+");
            if (sizeof(argv[1]) != 0 && argv[1] == "-html4")
            {
                fwrite("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\">");
            } else{
                fwrite("<!DOCTYPE html>");
            }
            fclose(doc);
        }
        catch (const std::exception &)
        {
        }
    }
    return 0;
}
