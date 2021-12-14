#include <iostream>
#include <getopt.h>

#define no_argument 0
#define required_argument 1

using namespace std;

int main (int argc, char *argv[]) {
    bool helloparam1_flag = 0;
    bool gooddayparam2_flag = 0;
    bool watsupparam3_flag = 0;

    string valueparam4 = "";
    int index, a;
    
    opterr = 0;
    const struct option longopts[] =
    {
        {"helloparam1", no_argument, 0, 'h'},
        {"gooddayparam2", no_argument, 0, 'g'},
        {"watsupparam3", no_argument, 0, 'w'},
        {"valueparam4", required_argument, 0, 'v'},
        {0, 0, 0, 0}
    };
    
    while ((a = getopt_long(argc, argv, "hgwv:", longopts, &index)) != -1) {
    	switch (a)
    	{
    	    case 'h':
    	        helloparam1_flag = true;
    	        break;
    	    case 'g':
    	        gooddayparam2_flag = true;
    	        break;
    	    case 'w':
    	        watsupparam3_flag = true;
    	        break;
    	    case 'v':
    	        valueparam4 = optarg;
    	        break;
    	    case '?':
    	        cout << "Not an argument\n";
    	        break;
    	}
    }
    if (helloparam1_flag)
        cout << "Hello\n";
    if (gooddayparam2_flag)
        cout << "Goodday\n";
    if (watsupparam3_flag)
        cout << "Watsup\n";
    if (valueparam4 != "")
        cout << "Value=" << valueparam4 << "\n";
    
    return 0;
}
