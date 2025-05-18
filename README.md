# Installation automatique de PHP et MySQL sous Windows

Ce projet propose un outil simple pour vérifier si PHP et MySQL sont installés sur un PC Windows,  
et propose une installation automatique via Chocolatey si besoin.

---

## Contenu

- `check_php_mysql.c` : programme en C qui vérifie la présence de PHP et MySQL.  
- `install_php_mysql.ps1` : script PowerShell qui installe PHP et MySQL via Chocolatey.  
- `install.bat` : fichier batch pour lancer le programme et/ou le script.  
- `check_php_mysql.exe` : exécutable compilé du programme C.

---

## Fonctionnement

1. Lancer `check_php_mysql.exe`.  
2. Le programme vérifie si PHP et MySQL sont installés.  
3. Si un ou les deux manquent, il propose de lancer l'installation automatique via Chocolatey.  
4. L'installation se fait en quelques clics (administrateur requis).

---

## Prérequis

- Windows 10 ou supérieur.  
- Droits administrateur pour installer via Chocolatey.  
- PowerShell configuré pour exécuter des scripts (`ExecutionPolicy` en `Bypass` ou `RemoteSigned`).

---

## Installation manuelle (si nécessaire)

- [PHP](https://windows.php.net/download)  
- [MySQL](https://dev.mysql.com/downloads/mysql/)

---

## Compilation du programme C

Pour compiler `check_php_mysql.c`, vous pouvez utiliser MinGW :

```bash
gcc check_php_mysql.c -o check_php_mysql.exe
