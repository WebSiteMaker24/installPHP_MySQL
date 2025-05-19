#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

int command_exists(const char *cmd)
{
    char command[256];
    snprintf(command, sizeof(command), "where %s > nul 2>&1", cmd);
    return (system(command) == 0);
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    int php_installed = command_exists("php.exe");
    int mysql_installed = command_exists("mysql.exe");
    int git_installed = command_exists("git.exe");

    if (php_installed && mysql_installed && git_installed)
    {
        printf("PHP, MySQL et Git sont installés.\n");
    }
    else
    {
        if (!php_installed)
            printf("PHP n'est pas installé.\n");
        if (!mysql_installed)
            printf("MySQL n'est pas installé.\n");
        if (!git_installed)
            printf("Git n'est pas installé.\n");

        printf("Voulez-vous lancer l'installation automatique via Chocolatey ? (o/n) : ");
        int answer = getchar();
        while (getchar() != '\n' && !feof(stdin))
            ;

        if (answer == 'o' || answer == 'O')
        {
            // Récupérer le dossier du .exe actuel
            char exePath[MAX_PATH];
            GetModuleFileNameA(NULL, exePath, MAX_PATH);
            char *lastSlash = strrchr(exePath, '\\');
            if (lastSlash)
                *lastSlash = '\0';

            char command[512];
            snprintf(command, sizeof(command),
                     "powershell -ExecutionPolicy Bypass -File \"%s\\install_php_mysql.ps1\"", exePath);

            system(command);
        }
        else
        {
            printf("Installation annulée.\n");
            printf("PHP: https://windows.php.net/download\n");
            printf("MySQL: https://dev.mysql.com/downloads/mysql/\n");
            printf("Git: https://git-scm.com/download/win\n");
        }
    }

    return 0;
}
