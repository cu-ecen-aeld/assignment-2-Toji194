#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

int main(int argc, char *argv[])
{
    openlog(NULL, 0, LOG_USER);

    if (argc != 3)
    {
        syslog(LOG_ERR, "Invalid number of arguments");
        closelog();
        return 1;
    }

    const char *writefile = argv[1];
    const char *writestr = argv[2];

    syslog(LOG_DEBUG, "Writing %s to %s", writestr, writefile);

    FILE *fp = fopen(writefile, "w");

    if (fp == NULL)
    {
        syslog(LOG_ERR, "Error opening file");
        closelog();
        return 1;
    }

    if (fprintf(fp, "%s", writestr) < 0)
    {
        syslog(LOG_ERR, "Error writing file");
        fclose(fp);
        closelog();
        return 1;
    }

    fclose(fp);
    closelog();

    return 0;
}
