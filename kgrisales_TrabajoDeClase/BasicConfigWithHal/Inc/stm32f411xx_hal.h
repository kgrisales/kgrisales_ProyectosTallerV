/*
 * stm32f411xx_hal.h
 *
 *  Created on: Mar 6, 2023
 *      Author: kgrisales
 *
 * Este archivo contiene la información más básica del micro:
 * -Valores de reloj principal
 * -Distribución básica de la memoria (descrito en la figura 14 de la hoja de datos del micro)
 * -Posiciones de memoria de los periféricos disponibles en el micro descrito en la tabla 1
 *  (Memory map)
 * -Incluye los demás registros de los periféricos
 * -Definiciones de las constantes más básicas
 *
 * NOTA: La definición del NVIC será realizada al momento de describir el uso de las
 * interrupciones
 */

#ifndef INC_STM32F411XX_HAL_H_
#define INC_STM32F411XX_HAL_H_

#include <stdint.h>
#include <stedef.h>

#define HSI_CLOCK_SPEED  16000000   //Value for the main clock signal (HSI -> High Speed Internal)
#define HSI_CLOCK_SPEED  4000000    //Value for the main clock signal (HSI -> High Speed External)

#define NOP()  asm("NOP")
#define _weak  _attribute_((weak))

/*
 * Base addresses of Flash and SRAM memories
 * Datasheet, Memory Map, Figure 14
 * (Remember, 1KByte = 1024 bytes)
 */
#define FLASH_BASE_ADDR   0x08000000U   // Esta es la memoria del programa, 512KB
#define SRAM_BASE_ADDR    0x20000000U   // Esta es la meoria RAM, 128KB.

/* NOTA: Observar que existen unos registros específicos del Cortex M4 en la región 0xE0000000U
 * Los controladores de las interrupcione se encuentran allí, por ejemplo.
 * Esto se verá a su debido tiempo
 */

/*
 * NOTA:
 * Ahora agregamos la dirección de memoria base para cada uno de los periféricos que posee el micro
 * En el "datasheet" del micro, FIGURA 14 (Memory map) encontramos el mapa de los buses:
 * -APB1 (Advance Peripheral Bus)
 * -APB2
 * -AHB1 (Advance High-performance Bus)
 * -AHB2
 */

/**
 * AHx and APBx Bus Peripherals base addresses
 */
#define APB1_BASE_ADDR   0X40000000U
#define APB2_BASE_ADDR   0x40010000U
#define AHB1_BASE_ADDR   0x40020000U
#define AHB2_BASE_ADDR   0x50000000U

/**
 * Y ahora debemos hacer lo mismo pero cada una de las posiciones de memoria de cada uno de los
 * periféricos descritos en la Tabla 1 del manual de referencia del micro.
 * Observe que en dicha tabla está a su vez divida en cuatro segmentos, cada uno coreespondiente
 * a APB1, APB2, AHB1, AHB2.
 *
 * Comenzar de arriba hacia abajo como se muestara en la tabla. Inicia USB_OTG_FS (AHB2)
 *
 * NOTA: Solo vamos a hacer con los elementos que necesitamos en este ejercicio: RCC y GPIOx
 */

/* Posiciones de memoria para periféricos del APB2 */
#define USB_OTG_FS_BASE_ADDR   (AHB2_BASE_ADDR + 0x0000U)

/* Posiciones de memoria para periféricos del AHB1
 * Observar que NO está completa */
#define RCC_BASE_ADDR           (AHB1_BASE_ADDR + 0x3800U)
#define GPIOH_BASE_ADDR         (AHB1_BASE_ADDR + 0x1C00U)
#define GPIOE_BASE_ADDR         (AHB1_BASE_ADDR + 0x1000U)
#define GPIOD_BASE_ADDR         (AHB1_BASE_ADDR + 0x0C00U)
#define GPIOC_BASE_ADDR         (AHB1_BASE_ADDR + 0x0800U)
#define GPIOB_BASE_ADDR         (AHB1_BASE_ADDR + 0x0400U)
#define GPIOA_BASE_ADDR         (AHB1_BASE_ADDR + 0x0000U)

/* Posiciones de memoria para periféricos del APB2
 * NOTA: NO los necesitamos en este ejercicio, NO copiar
#define SPI5_BASE_ADDR          (APB2_BASE_ADDR + 0x5000U)
#define TIM11_BASE_ADDR         (APB2_BASE_ADDR + 0x4800U)
#define TIM10_BASE_ADDR         (APB2_BASE_ADDR + 0x4400U)
#define TIM9_BASE_ADDR          (APB2_BASE_ADDR + 0x4000U)
#define EXIT_BASE_ADDR          (APB2_BASE_ADDR + Ox3C00U)
#define SYSCFG_BASE_ADDR        (APB2_BASE_ADDR + 0x3800U)
 *
 */


#endif /* STM32F411XX_HAL_H_ */
