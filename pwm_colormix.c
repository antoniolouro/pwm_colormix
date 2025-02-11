// Código para misturar cores RGB usando PWM
// Evitou-se ajustar as cores com valores iguais para evitar os níveis de cinza
//--------------------------------------------------------------------------------------------
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define RED_PIN   13 // Pino PWM para o vermelho
#define GREEN_PIN 11 // Pino PWM para o verde
#define BLUE_PIN  12 // Pino PWM para o azul

#define PWM_FREQ 5000 // Frequência do PWM (5 kHz)
#define MAX_DUTY 255  // Máximo duty cycle (8 bits)

void setup_pwm(uint gpio) {
    gpio_set_function(gpio, GPIO_FUNC_PWM);
    uint slice = pwm_gpio_to_slice_num(gpio);
    pwm_set_wrap(slice, MAX_DUTY);                              // Define o valor máximo do contador (255)
    pwm_set_clkdiv(slice, (125000000 / (PWM_FREQ * MAX_DUTY))); // Ajusta o divisor de clock (98)
    pwm_set_enabled(slice, true);
}

int main() {
    stdio_init_all();
    setup_pwm(RED_PIN);
    setup_pwm(GREEN_PIN);
    setup_pwm(BLUE_PIN);
    
    uint8_t r = 0, g = 127, b = 255;    // Valores iniciais diferentes para cada cor
    int dr = 1, dg = 2, db = 3;         // Passos diferentes para cada cor

    while (true) {
        pwm_set_gpio_level(RED_PIN, r);
        pwm_set_gpio_level(GREEN_PIN, g);
        pwm_set_gpio_level(BLUE_PIN, b);
        
        r += dr;
        g += dg;
        b += db;
        // Inverte a direção quando atinge o máximo ou mínimo
        if (r == 0 || r == MAX_DUTY) dr = -dr;
        if (g == 0 || g == MAX_DUTY) dg = -dg;
        if (b == 0 || b == MAX_DUTY) db = -db;
        
        sleep_ms(10); // Ajuste o tempo para suavizar a transição
    }
}
