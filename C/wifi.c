#include <windows.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    char ssid[64] = "xanarry";
    char key[64] = "123456789";
    char tmp[64];
    char set[512];
    if (argc == 1) {
        printf("input ssid (d using default): ");
        scanf("%s", tmp);
        if (tmp[0] != 'd')
        {
            strcpy(ssid, tmp);
            printf("input password: ");
            scanf("%s", key);
            if (strlen(key) < 8)
            {
                printf("password at least 8 chars\n");
                getchar(); getchar();
                return 0;
            }
        }
    }
    else
    {
        strcpy(ssid, argv[1]);
        strcpy(key, argv[2]);
    }
    sprintf(set, "netsh wlan set hostednetwork ssid=%s key=%s", ssid, key);
    system(set);
    system("netsh wlan start hostednetwork");
    printf("SSID: %s\nPASS: %s\n", ssid, key);
    getchar(); getchar();
    return 0;
}