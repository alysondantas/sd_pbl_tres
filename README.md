# Problema 3 – Pong

Repositório contendo os arquivos referentes ao desenvolvimento do Problema 3 da disciplina TEC499 MI Sistemas Digitais.

## Desenvolvido com:
1. [Altera Quartus II 18.1.0](https://fpgasoftware.intel.com/18.1/?edition=lite).
2. Placa FPGA da Familia [Cyclone IV](https://www.intel.com/content/dam/www/programmable/us/en/pdfs/literature/hb/cyclone-iv/cyiv-51001.pdf) com o Chip EP4CE6E22C8.

## Objetivos:

O sistema desenvolvido possui como objetivo reutilizar componentes da IHM desenvolvida dos projetos anteriores, e desenvolver um jogo PONG.

## Procedimentos:

1. Abrir o Altera Quartus II 18.1;
2. Em File -> Open Project;
3. Selecionar a pasta sd_pbl_tres;
4. Abrir o arquivo pbl3.qpf;
5. Executar a compilação do Projeto;
6. Descarregar na FPGA;
7. Abrir o NIOS II Software Build Tools for Eclipse;
8. Em File -> Import -> Existing projects into workspace;
9. Selecionar a pasta sd_pbl_tres;
10. Abrir a pasta software;
11. Importar projetos;
12. Descaregar software.

## Informações Adicionais:

Veja a lista de [contribuidores](https://github.com/alysondantas/sd_pbl_tres/contributors) que participaram nesse projeto.
Necessario um conversor AD, caso uso de arduino o codigo fonte encontrasse na pasta /software/arduino/conversorad/conversorad.ino para arduinos e ESP.
