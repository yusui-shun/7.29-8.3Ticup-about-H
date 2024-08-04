/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ============ ti_msp_dl_config.h =============
 *  Configured MSPM0 DriverLib module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */
#ifndef ti_msp_dl_config_h
#define ti_msp_dl_config_h

#define CONFIG_MSPM0G350X

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define SYSCONFIG_WEAK __attribute__((weak))
#elif defined(__IAR_SYSTEMS_ICC__)
#define SYSCONFIG_WEAK __weak
#elif defined(__GNUC__)
#define SYSCONFIG_WEAK __attribute__((weak))
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform all required MSP DL initialization
 *
 *  This function should be called once at a point before any use of
 *  MSP DL.
 */


/* clang-format off */

#define POWER_STARTUP_DELAY                                                (16)



#define CPUCLK_FREQ                                                     32000000



/* Defines for TIMER_0 */
#define TIMER_0_INST                                                     (TIMG0)
#define TIMER_0_INST_IRQHandler                                 TIMG0_IRQHandler
#define TIMER_0_INST_INT_IRQN                                   (TIMG0_INT_IRQn)
#define TIMER_0_INST_LOAD_VALUE                                            (39U)




/* Defines for I2C_0 */
#define I2C_0_INST                                                          I2C1
#define I2C_0_INST_IRQHandler                                    I2C1_IRQHandler
#define I2C_0_INST_INT_IRQN                                        I2C1_INT_IRQn
#define I2C_0_BUS_SPEED_HZ                                                100000
#define GPIO_I2C_0_SDA_PORT                                                GPIOB
#define GPIO_I2C_0_SDA_PIN                                         DL_GPIO_PIN_3
#define GPIO_I2C_0_IOMUX_SDA                                     (IOMUX_PINCM16)
#define GPIO_I2C_0_IOMUX_SDA_FUNC                      IOMUX_PINCM16_PF_I2C1_SDA
#define GPIO_I2C_0_SCL_PORT                                                GPIOB
#define GPIO_I2C_0_SCL_PIN                                         DL_GPIO_PIN_2
#define GPIO_I2C_0_IOMUX_SCL                                     (IOMUX_PINCM15)
#define GPIO_I2C_0_IOMUX_SCL_FUNC                      IOMUX_PINCM15_PF_I2C1_SCL



/* Port definition for Pin Group Right_Motor */
#define Right_Motor_PORT                                                 (GPIOA)

/* Defines for Driver_R: GPIOA.13 with pinCMx 35 on package pin 6 */
#define Right_Motor_Driver_R_PIN                                (DL_GPIO_PIN_13)
#define Right_Motor_Driver_R_IOMUX                               (IOMUX_PINCM35)
/* Port definition for Pin Group Left_Motor */
#define Left_Motor_PORT                                                  (GPIOA)

/* Defines for Dirver_L: GPIOA.12 with pinCMx 34 on package pin 5 */
#define Left_Motor_Dirver_L_PIN                                 (DL_GPIO_PIN_12)
#define Left_Motor_Dirver_L_IOMUX                                (IOMUX_PINCM34)
/* Port definition for Pin Group LED */
#define LED_PORT                                                         (GPIOA)

/* Defines for LED_1: GPIOA.0 with pinCMx 1 on package pin 33 */
#define LED_LED_1_PIN                                            (DL_GPIO_PIN_0)
#define LED_LED_1_IOMUX                                           (IOMUX_PINCM1)
/* Port definition for Pin Group BUZZER */
#define BUZZER_PORT                                                      (GPIOB)

/* Defines for buzzer: GPIOB.18 with pinCMx 44 on package pin 15 */
#define BUZZER_buzzer_PIN                                       (DL_GPIO_PIN_18)
#define BUZZER_buzzer_IOMUX                                      (IOMUX_PINCM44)
/* Defines for KEY1: GPIOA.17 with pinCMx 39 on package pin 10 */
#define KEY_KEY1_PORT                                                    (GPIOA)
#define KEY_KEY1_PIN                                            (DL_GPIO_PIN_17)
#define KEY_KEY1_IOMUX                                           (IOMUX_PINCM39)
/* Defines for KEY2: GPIOA.24 with pinCMx 54 on package pin 25 */
#define KEY_KEY2_PORT                                                    (GPIOA)
#define KEY_KEY2_PIN                                            (DL_GPIO_PIN_24)
#define KEY_KEY2_IOMUX                                           (IOMUX_PINCM54)
/* Defines for KEY3: GPIOA.15 with pinCMx 37 on package pin 8 */
#define KEY_KEY3_PORT                                                    (GPIOA)
#define KEY_KEY3_PIN                                            (DL_GPIO_PIN_15)
#define KEY_KEY3_IOMUX                                           (IOMUX_PINCM37)
/* Defines for KEY4: GPIOB.15 with pinCMx 32 on package pin 3 */
#define KEY_KEY4_PORT                                                    (GPIOB)
#define KEY_KEY4_PIN                                            (DL_GPIO_PIN_15)
#define KEY_KEY4_IOMUX                                           (IOMUX_PINCM32)

/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_TIMER_0_init(void);
void SYSCFG_DL_I2C_0_init(void);


bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */