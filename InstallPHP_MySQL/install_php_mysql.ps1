# Vérifie si Chocolatey est installé, sinon l'installe
if (-not (Get-Command choco -ErrorAction SilentlyContinue)) {
    Write-Host "Chocolatey n'est pas installé. Installation en cours..."
    Set-ExecutionPolicy Bypass -Scope Process -Force
    [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.SecurityProtocolType]::Tls12
    iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))
} else {
    Write-Host "Chocolatey est déjà installé."
}

# Mise à jour de Chocolatey
choco upgrade chocolatey -y

# Installation ou mise à jour de PHP
if (-not (Get-Command php -ErrorAction SilentlyContinue)) {
    Write-Host "Installation de PHP..."
    choco install php -y
} else {
    Write-Host "PHP est déjà installé."
}

# Installation ou mise à jour de MySQL
if (-not (Get-Command mysql -ErrorAction SilentlyContinue)) {
    Write-Host "Installation de MySQL..."
    choco install mysql -y
} else {
    Write-Host "MySQL est déjà installé."
}

# Installation ou mise à jour de Git
if (-not (Get-Command git -ErrorAction SilentlyContinue)) {
    Write-Host "Installation de Git..."
    choco install git -y
} else {
    Write-Host "Git est déjà installé."
}
