#include <fstream>
#include "readwrite.h"

bool file_exists(const string &file_name)
{
    ifstream file(file_name);

    if (!file)
    {
        return false;
    }
    else
        return true;
}

