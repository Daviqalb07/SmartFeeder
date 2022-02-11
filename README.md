# SmartFeeder
**Um sistema eficiente para evitar que o seu pet não se alimente por longos períodos!**

Link do vídeo:

## Equipe:
- **Catherine Bezerra Markert**
- **Davi Queiroz Albuquerque**
- **Helena Oliveira Cunha**
- **Yago Costa de Oliveira**

## Objetivos
Como objetivo principal, temos o de conciliar a rotina do pet com a do seu tutor, visando uma alimentação mais regrada do pet mesmo na ausência de seu tutor.

## Features
- **Timer configurável** para abrir o comedouro.
- **Alertas visuais** para eventos (comida liberada) e problemas (estoque de ração vazio, por exemplo).
- **Fácil** comunicação com o usuário através de **display LCD**.

## Equipamentos
- Microcontrolador STM32F103C6
- LEDs: 1x verde e 1x azul
- Teclado matricial
- Display LCD 20x4

## Diagrama de funcionamento
<p align="center">
  <img src="https://github.com/Daviqalb07/SmartFeeder/blob/master/Schematics/Diagrama-de-funcionamento.png" width="70%" />
</p>

## Adversidades
Devido à pandemia de covid-19, o projeto teve que ser realizado remotamente, através de simulador, o qual requisitava muito dos recursos do computador, limitando o tempo de testes de funcionamento e ocasionando alguns erros temporários. Além disso, não foi possível simular uma balança real nesse formato.

## Schematics
- Tela inicial
<p float="left">
  <img src="https://github.com/Daviqalb07/SmartFeeder/blob/master/Schematics/Esquematico-tela-inicial.jpg" width="500" />
</p>
- Home
<p float="left">
  <img src="https://github.com/Daviqalb07/SmartFeeder/blob/master/Schematics/Esquematico-tela-ativa.jpg" width="500"/> 
</p>
- Configuração dos pinos
<p float="left">
  <img src="https://github.com/Daviqalb07/SmartFeeder/blob/master/Schematics/Configuracoes-dos-pinos.png" width="500"/> 
</p>

## Referências
[Biblioteca para comunicação de display LCD com STM32](https://github.com/delpitec/C_STM32_LibLiquidCrystal) (Adaptada durante o projeto).
