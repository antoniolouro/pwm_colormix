# pwm_colormix

## Trabalho adicional mostrando o uso de PWM em led RGB

A Fpwm é ajustada em 5KHz - wrap=255 (valor max que o byte cor pode assumir) - level (valor do comparador para determinar o ciclo ativo) varia de 0 à 255.
Cada cor tem o seu próprio canal pwm. Cada uma é iniciada em um valor distinto (0, 127, 255) - cada uma tem o seu proprio passo (dr=1, dg=2, db=3). Isto é feito com a esperança de nunca ocorrer valores coincidentes nas três cores, o que acarretaria em um ton de cinza. As cores são incrementadas/decrementadas com seus respectivos passos.

## Vídeos demonstrativos


[![Assista no YouTube](https://img.youtube.com/vi/mN-BrQMJ8co/maxresdefault.jpg)](https://youtu.be/mN-BrQMJ8co)

[![Assista ao Shorts](https://img.youtube.com/vi/AguHtH9S1hM/hqdefault.jpg)](https://www.youtube.com/watch?v=AguHtH9S1hM)

