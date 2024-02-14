# Genius Game com Arduino

Este é um repositório para o jogo Genius, um jogo de memória eletrônico que foi popular na década de 1980, agora implementado usando um Arduino.

## Componentes Necessários

Para montar o jogo Genius com Arduino, você precisará dos seguintes componentes:

- Arduino Uno
- 4 LEDs de cores diferentes
- 4 botões
- 1 buzzer
- Resistores
- Jumpers
- Protoboard

## Como Funciona o Jogo

O jogo Genius é um jogo de memória. Ele acende um LED aleatório e toca uma nota correspondente no buzzer. O jogador deve então pressionar o botão correspondente ao LED que acendeu. Se o jogador acertar, o jogo repete a sequência e adiciona mais um LED aleatório no final. O jogo continua até que o jogador erre a sequência ou atinja a pontuação de 5 acertos (pontuação máxima).

## Frequências de Sons

Cada LED/botão tem uma nota correspondente que é tocada no buzzer. As frequências das notas são:

- LED Vermelho: 261 Hz (Nota C)
- LED Verde: 329 Hz (Nota E)
- LED Azul: 392 Hz (Nota G)
- LED Amarelo: 523 Hz (Nota C')

## Como Executar o Jogo

1. Conecte todos os componentes conforme o esquema de circuito.
2. Carregue o código do jogo para o Arduino usando a IDE do Arduino.
3. Uma vez que o Arduino é alimentado, o jogo começará automaticamente.

## Créditos

Este projeto foi baseado e adaptado do tutorial disponível em [UsinaInfo](https://www.usinainfo.com.br/blog/jogos-com-arduino-genius-snake-e-jump-boy/). Agradeço a eles por fornecerem uma excelente base para este projeto.

Espero que você se divirta jogando Genius com Arduino tanto quanto eu me diverti construindo! Se você tiver alguma dúvida ou sugestão, sinta-se à vontade para abrir uma issue. Boa diversão!
