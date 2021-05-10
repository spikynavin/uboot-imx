/* IRIS Devlopment */
#ifndef __MX6QSABRE_COMMON_CONFIG_H
#define __MX6QSABRE_COMMON_CONFIG_H

/* Common Headers */
#include "mx6_common.h"
#include <linux/sizes.h>
#include <asm/arch/imx-regs.h>
#include <asm/imx-common/gpio.h>
#include <config_cmd_default.h>

/* Basic Machine Define */
#define CONFIG_MX6
#ifdef CONFIG_MX6SOLO
#define CONFIG_MX6DL
#endif

/* Devices Tree Define */
#define CONFIG_SKIP_LOWLEVEL_INIT

#define CONFIG_SYS_GENERIC_BOARD
#define CONFIG_DISPLAY_CPUINFO
#define CONFIG_DISPLAY_BOARDINFO
#define CONFIG_CMDLINE_TAG
#define CONFIG_SETUP_MEMORY_TAGS
#define CONFIG_INITRD_TAG
#define CONFIG_REVISION_TAG

/* Size of malloc() pool */
#define CONFIG_SYS_MALLOC_LEN		(10 * SZ_1M)
#define CONFIG_BOARD_EARLY_INIT_F	1
#define CONFIG_BOARD_LATE_INIT
#define CONFIG_MXC_GPIO
#define CONFIG_MXC_UART
#ifdef CONFIG_CMD_FUSE
#define CONFIG_MXC_OCOTP
#endif

/* MMC Configs */
#define CONFIG_FSL_ESDHC
#define CONFIG_FSL_USDHC
#define CONFIG_SYS_FSL_ESDHC_ADDR	0
#define CONFIG_MMC
#define CONFIG_CMD_MMC
#define CONFIG_GENERIC_MMC
#define CONFIG_BOUNCE_BUFFER
#define CONFIG_CMD_FAT
#define CONFIG_DOS_PARTITION
/*#define CONFIG_MMC_TRACE */ /* MMC & EMMC CMD Debug Configs */

/* Allow to overwrite serial console and baudrate Define */
#define CONFIG_ENV_OVERWRITE
#define CONFIG_CONS_INDEX		1
#define CONFIG_BAUDRATE			115200

/* Command definition */
#define CONFIG_CMD_BMODE
#define CONFIG_CMD_SETEXPR
#undef CONFIG_CMD_IMLS
#define CONFIG_BOOTDELAY		0
#define CONFIG_LOADADDR			0x12000000
#define CONFIG_SYS_TEXT_BASE		0x17800000
#define CONFIG_SYS_MMC_IMG_LOAD_PART	1

/* Boot time improvements */
#define CONFIG_UBI_SILENCE_MSG
#define CONFIG_SYS_L2_PL310
#define CONFIG_ZERO_BOOTDELAY_CHECK

/* Boot optimization Configs */
#undef CONFIG_CMD_NET

/* MFGTool Config for Flashing */
#define CONFIG_MFG_ENV_SETTINGS \
        "mfgtool_args=setenv bootargs console=" CONFIG_CONSOLE_DEV ",115200 " \
                "rdinit=/linuxrc " \
                "g_mass_storage.stall=0 g_mass_storage.removable=1 " \
                "g_mass_storage.idVendor=0x066F g_mass_storage.idProduct=0x37FF "\
                "g_mass_storage.iSerialNumber=\"\" "\
                "enable_wait_mode=off "\
                "\0" \
                "initrd_addr=0x12C00000\0" \
                "initrd_high=0xffffffff\0" \
                "bootcmd_mfg=run mfgtool_args;bootm ${loadaddr} ${initrd_addr} ${fdt_addr};\0" \

#define CONFIG_EXTRA_ENV_SETTINGS \
		CONFIG_MFG_ENV_SETTINGS \
                "fdt_file=" CONFIG_DEFAULT_FDT_FILE "\0" \
                "fdt_addr=0x18000000\0" \
                "fdt_high=0xffffffff\0"   \
                "mmcroot=" CONFIG_MMCROOT " rootwait rw\0" \
                "mmcautodetect=yes\0" \
                "fdtforce=0\0" \
                "kernel=uImage\0" \
                "smp=" CONFIG_SYS_NOSMP "\0" \
                "bootargs_base=console=" CONFIG_CONSOLE_DEV "\0" \
                "bootargs_usb=setenv bootargs ${bootargs_base} ${smp}\0" \
                "bootcmd_usb=run bootargs_usb;usb start;" \
                        "fatload usb 0 ${loadaddr} ${kernel};fatload usb 0 ${fdt_addr} ${fdt_file};bootm ${loadaddr} - ${fdt_addr}\0" \
                "bootcmd=run bootcmd_usb\0" \
        "\0"

#define CONFIG_ARP_TIMEOUT		100UL

/* Miscellaneous configurable options */
#undef CONFIG_SYS_HUSH_PARSER
#define CONFIG_SYS_PROMPT_HUSH_PS2	"> "
#define CONFIG_SYS_PROMPT		"u-boot > "
#define CONFIG_AUTO_COMPLETE
#define CONFIG_SYS_CBSIZE		512 /* 1024 */

/* Print Buffer Size*/
#define CONFIG_SYS_PBSIZE (CONFIG_SYS_CBSIZE + sizeof(CONFIG_SYS_PROMPT) + 16)
#define CONFIG_SYS_MAXARGS		32 /* 16 */
#define CONFIG_SYS_BARGSIZE CONFIG_SYS_CBSIZE
#define CONFIG_SYS_LOAD_ADDR           CONFIG_LOADADDR
#define CONFIG_CMDLINE_EDITING
#define CONFIG_STACKSIZE               (64 * 1024) /* 128 */

/* Physical Memory Map */
#define CONFIG_NR_DRAM_BANKS		2
#define PHYS_SDRAM                     MMDC0_ARB_BASE_ADDR
#define PHYS_SDRAM_SIZE_512MB          (1u * 512 * 1024 * 1024)
#define CONFIG_SYS_SDRAM_BASE          PHYS_SDRAM
#define CONFIG_SYS_INIT_RAM_ADDR       IRAM_BASE_ADDR
#define CONFIG_SYS_INIT_RAM_SIZE       IRAM_SIZE
#define CONFIG_SYS_INIT_SP_OFFSET \
	(CONFIG_SYS_INIT_RAM_SIZE - GENERATED_GBL_DATA_SIZE)
#define CONFIG_SYS_INIT_SP_ADDR \
	(CONFIG_SYS_INIT_RAM_ADDR + CONFIG_SYS_INIT_SP_OFFSET)

/* FLASH and environment organization */
#define CONFIG_SYS_NO_FLASH
#define CONFIG_ENV_SIZE			(1 * 1536) /* 8*1024=8MB */
#ifndef CONFIG_SYS_NOSMP
#define CONFIG_SYS_NOSMP		"nosmp"
#endif

/* BOOT Media Configs */
#if defined CONFIG_SYS_BOOT_SPINOR
#define CONFIG_SYS_USE_SPINOR
#define CONFIG_ENV_IS_IN_SPI_FLASH
#else
#define CONFIG_ENV_IS_IN_MMC
#endif

/* SPI NOR FLASH Configs */
#ifdef CONFIG_SYS_USE_SPINOR
#define CONFIG_CMD_SF
#define CONFIG_SPI_FLASH
#define CONFIG_SPI_FLASH_ISSI
#define CONFIG_MXC_SPI
#define CONFIG_SF_DEFAULT_BUS  		0
#define CONFIG_SF_DEFAULT_SPEED 	20000000
#define CONFIG_SF_DEFAULT_MODE (SPI_MODE_0)
#endif

/* System Cache */
#define CONFIG_OF_LIBFDT
#ifndef CONFIG_SYS_DCACHE_OFF
#define CONFIG_CMD_CACHE
#endif

#endif                         /* __MX6QSABRE_COMMON_CONFIG_H */
