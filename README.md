### DNS Resolver - Subdomain Scanner
Este é um DNS Resolver desenvolvido em C, que realiza a varredura de subdomínios de um domínio alvo utilizando uma wordlist.
A ferramenta faz a resolução DNS para descobrir se os subdomínios existem e exibe o IP correspondente.

#### Funcionalidades
Varredura de subdomínios: Utiliza uma wordlist para identificar subdomínios válidos em um domínio específico.
Resolução de IP: Realiza a resolução DNS para obter o endereço IP dos subdomínios encontrados.

##### Obs: Junto com o codigo estou deixando uma wordlist com subdominios em PTBR :)

#### Uso:

git clone https://github.com/rnglx/DNS-RESOLVER.git

cd DNS-RESOLVER

gcc DNS-RESOLVER.c -o DNS-RESOLVER

chmod +x DNS-RESOLVER

./DNS-RESOLVER <dominio> <wordlist>

ex: ./DNS-RESOLVER example.com subd.txt
