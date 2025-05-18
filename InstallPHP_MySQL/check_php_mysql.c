#include <stdio.h>
#include <stdlib.h>
#include <windows.h> // pour SetConsoleOutputCP

int command_exists(const char *cmd)
{
    char command[256];
    snprintf(command, sizeof(command), "where %s > nul 2>&1", cmd);
    int result = system(command);
    return (result == 0);
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    int php_installed = command_exists("php.exe");
    int mysql_installed = command_exists("mysql.exe");

    if (php_installed && mysql_installed)
    {
        printf("PHP et MySQL sont installés.\n");
    }
    else
    {
        if (!php_installed)
            printf("PHP n'est pas installé.\n");
        if (!mysql_installed)
            printf("MySQL n'est pas installé.\n");

        printf("Voulez-vous lancer l'installation automatique via Chocolatey ? (o/n) : ");
        int answer = getchar();
        // nettoyer le buffer au cas où
        while (getchar() != '\n' && !feof(stdin))
            ;

        if (answer == 'o' || answer == 'O')
        {
            system("powershell -ExecutionPolicy Bypass -File install_php_mysql.ps1");
        }
        else
        {
            printf("Installation annulée.\n");
            printf("PHP: https://windows.php.net/download\n");
            printf("MySQL: https://dev.mysql.com/downloads/mysql/\n");
        }
    }

    return 0;
}
