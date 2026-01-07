# Arduino Memory Game 

Um jogo da memória clássico estilo "Simon Says" desenvolvido em C++ para Arduino. O projeto apresenta sequências aleatórias de luzes que o jogador deve repetir. A dificuldade aumenta progressivamente com a velocidade e o número de sequências.

## About

Este projeto foi desenvolvido como parte dos estudos de Arduino, programação em C e integração de hardware e software.

**Principais Funcionalidades:**
* Geração de sequências aleatórias.
* Sistema de níveis: O jogo fica mais rápido a cada rodada bem-sucedida.
* Feedback Sonoro: Tones específicos para cada cor e sons de Vitória/Derrota.
* Feedback Visual: LEDs indicativos.

##  Circuito e Hardware

É importante evidenciar que, o sistema utiliza botões com resistores em configuração **Pull-Down** ao invés de pull ups nativos para treinar conhecimentos em eletrônica.

### Mapping

| Componente | Pino Arduino | Observação        |
| :--- | :--- |:------------------|
| **Botão 1** | D2 | Input (Pull-Down) |
| **Botão 2** | D3 | Input (Pull-Down) |
| **Botão 3** | D4 | Input (Pull-Down) |
| **Botão 4** | D5 | Input (Pull-Down) |
| **LED 1** | D10 | Output            |
| **LED 2** | D11 | Output            |
| **LED 3** | D12 | Output            |
| **LED 4** | D13 | Output            |
| **Buzzer** | D6* | Output            |
| **LED Vitória**| D7 | Opcional          |

> **Nota:** Recomenda-se evitar os pinos D0 e D1 (RX/TX) para não interferir no upload do código via USB.
> *\*Atenção ao código: certifique-se de que a constante `#define BUZZER` corresponda ao pino físico utilizado (ex: pino 6).*

### Lista de Materiais:

Componentes principais:
* 1x Arduino Uno R3
* 4x Botões Tácteis (Push button)
* 4x LEDs (Cores variadas)
* 1x Buzzer (Ativo)
* Resistores: 4x 10kΩ (Pull-down), 4x 220Ω (LEDs)

## Esquemático e Montagem

<img width="1528" height="635" alt="Brilliant Migelo" src="https://github.com/user-attachments/assets/ed648658-7cd6-472f-9049-535cb139f20e" />

Para detalhes técnicos e desenho do circuito eletrônico:
<img width="2200" height="1700" alt="Brilliant Migelo-1" src="https://github.com/user-attachments/assets/eba11e55-13de-480d-8467-652aeda5cbfe" />

## Como Executar

1.  Clone este repositório.
2.  Abra o arquivo `.ino` na Arduino IDE.
3.  Verifique se as definições de pinos no topo do código correspondem à sua montagem física.
4.  Conecte o Arduino via USB.
5.  Selecione a porta correta em `Ferramentas > Porta`.
6.  Clique em **Upload** .

## Como Jogar
Jogo em execução:
![WhatsApp Video 2026-01-07 at 12 49 43 PM](https://github.com/user-attachments/assets/50d53d52-054a-41f9-a78a-0c8d89d82ac0)

1.  O jogo iniciará com uma animação de luzes.
2.  Observe a sequência de cores que o Arduino piscar.
3.  Repita a sequência pressionando os botões correspondentes.
4.  **Acertou?** O jogo pisca a led verde ao lado do buffer, aumenta a velocidade e adiciona mais um passo à sequência.
5.  **Errou?** Game Over. O sistema toca um som de derrota e reinicia o jogo.

## Autor

Desenvolvido por José Claudio Sotero |
Estudante de Análise e Desenvolvimento de Sistemas.

---
*Este projeto é open-source e livre para fins educacionais.*# Arduino Memory Game 

