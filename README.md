# FSE - Trabalho 01
Primeiro Trabalho da Disciplina de Fundamentos de Sistemas Embarcados.

Aluno: Felipe de Oliveira Hargreaves - 15/0009313

## Compilação e Execução
### Servidor Distribuído
- Dentro da pasta `distributed_server` executar `make`.
- Para executar, rodar `./bin/bin`.
### Servidor Central
- É necessário já estar com o servidor distribuído em execução para rodar o servidor central.
- Dentro da pasta `central_server` executar `python3 main.py`.
- O log dos comandos selecionados pelo usuário, bem como das ativações de alarme é gerado no arquivo `log.txt`, também na pasta `central_server`.

## Funcionamento

O servidor central recebe atualizações de estado do servidor distribuído a cada segundo. A interface é atualizada sempre que o usuário seleciona uma ação no menu. Existe uma opção que apenas realiza essa atualização.

O servidor central também recebe notificações de alarme assim que o servidor distribuído perceber mudanças de estado nos sensores de presença/abertura. Se o alarme estiver ativo, o usuário será informado. Para ativar o alarme, é necessário que todos os sensores estejam desligados.

Inicialmente o sistema não possui temperatura de referência para o controle automático dos ares-condicionados. Esse controle só é realizado se o usuário informar um valor de temperatura.


## Outros

O áudio do alarme foi retirado de [https://freesound.org/people/o_ultimo/sounds/324394/](https://freesound.org/people/o_ultimo/sounds/324394/), licenciado através da [Creative Commons 3.0](https://creativecommons.org/licenses/by/3.0/). 