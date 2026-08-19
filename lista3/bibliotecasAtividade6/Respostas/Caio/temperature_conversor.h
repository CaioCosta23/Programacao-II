#ifndef _temperature_conversor
#define _temperature_conversor


/**
 * @brief Converte uma temperatura de Celsius para Kelvin;
 * 
 * @param temperature Temperatura a ser convertida;
 * @return float Temperatura convertida de uma escala de temperatura (Celsius) para outra (Kelvin);
 */
float convert_celsius_to_kelvin(float temperature);

/**
 * @brief Converte uma temperatura de Celsius para Fahrenheit;
 * 
 * @param temperature Temperatura a ser convertida;
 * @return float Temperatura convertida de uma escala de temperatura (Celsius) para outra (Fahrenheit);
 */
float convert_celsius_to_fahrenheit(float temperature);

/**
 * @brief Converte uma temperatura de Kelvin para Celsius;
 * 
 * @param temperature Temperatura a ser convertida;
 * @return float Temperatura convertida de uma escala de temperatura (Kelvin) para outra (Celsius);
 */
float convert_kelvin_to_celsius(float temperature);

/**
 * @brief Converte uma temperatura de Kelvin para Fahreinheit;
 * 
 * @param temperature Temperatura a ser convertida;
 * @return float Temperatura convertida de uma escala de temperatura (Kelvin) para outra (Fahrenheit);
 */
float convert_kelvin_to_fahrenheit(float temperature);


/**
 * @brief Converte uma temperatura de Fahreinheit para Celsius;
 * 
 * @param temperature Temperatura a ser convertida;
 * @return float Temperatura convertida de uma escala de temperatura (Fahrenheit) para outra (Celsius);
 */
float convert_fahrenheit_to_celsius(float temperature);

/**
 * @brief Converte uma temperatura de Fahreinheit para Kelvin;
 * 
 * @param temperature Temperatura a ser convertida;
 * @return float Temperatura convertida de uma escala de temperatura (Fahrenheit) para outra (Kelvin);
 */
float convert_fahrenheit_to_kelvin(float temperature);

float convert_temperature(float temperature, float convert_func(float temperature));

#endif