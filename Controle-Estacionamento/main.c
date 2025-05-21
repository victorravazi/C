/*A Uniara deseja controla o acesso dos carros ao seu estacionamento de professores e funcionários. Para isso, ela implantará um sistema que fará o controle de entrada e saída dos veículos. O sistema deve possuir os seguintes requisitos:
- Uma tela principal que mostra a capacidade do estacionamento x a ocupação das vagas (por exemplo 10 vagas/2 disponíveis)
- Uma tela que permita cadastrar os veículos com Marca, Modelo, Cor e Placa (formato antigo e formato novo), além do nome de seu proprietário e se ele é professor (P) ou funcionário (F).
- Uma tela para controlar a entrada e saída de veículos.
* O sistema deve alternar entre as telas utilizando um menu ou botões individuais para cada tela.

- Sempre que um veículo entrar o sistema deve gerar um novo ticket (arquivo individual em formato texto) com os dados do veículo, nome do proprietário e a HORA e MINUTO de entrada.
- Sempre que um veículo sair, o último ticket de entrada deve ser alterado, adicionando a HORA e MINUTO de saída e exibindo o TEMPO DE PERMANENCIA (em minutos).

*/

#include <stdio.h>
