// netshareenum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include <lm.h>
#pragma comment(lib, "Netapi32.lib")
#pragma comment(lib, "Advapi32.lib")
int wmain()
{
    PSHARE_INFO_1 BufPtr, p;
    NET_API_STATUS res = 0;
    LPTSTR   lpszServer = NULL;
    DWORD er = 0, tr = 0, resume = 0, i;
    std::cout << "starting" << std::endl;

    switch (__argc)
    {
    case 2:
        lpszServer = __wargv[1];
        
        break;
    default:
        printf("Usage: NetShareEnum <servername>\n");
        return 0;
    }
    printf("Share:              remark:                   :\n");
    printf("----------------------------------------------\n");
    do {
        res = NetShareEnum(lpszServer, 1, (LPBYTE*)&BufPtr, MAX_PREFERRED_LENGTH, &er, &tr, &resume);
        if (res == ERROR_SUCCESS || res == ERROR_MORE_DATA)
        {
            p = BufPtr;
            //
            for (i = 1; i <= er; i++)
            {
                printf("%ws,\t%ws\n", p->shi1_netname, p->shi1_remark);
                p++;
            }
        }
        else
        {
            printf("Error: %ld\n", res);
        }
    }
        while (res == ERROR_MORE_DATA);
        return 1;
    


}
  


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
