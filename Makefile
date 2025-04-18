DEVICE = STM32F103x8
FLASH  = 0x08000000

USE_ST_CMSIS = true


# ---- Archivos fuente ----
SRC += src/main.c
SRC += src/librerias/usart.c
SRC += src/librerias/gpio.c


# ---- Directorios de headers ----
INC_DIRS += src/librerias

# ---- Linker script (usa ruta relativa) ----
LDFLAGS += -TSTM32-base/linker/STM32F1xx/STM32F103x8.ld

# Incluye el makefile común (después de definir CFLAGS/LDFLAGS)
include ./STM32-base/make/common.mk