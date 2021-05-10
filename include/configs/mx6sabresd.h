/* IRIS Devlopment */
#ifndef __MX6QSABRESD_CONFIG_H
#define __MX6QSABRESD_CONFIG_H

/* Common Headers */
#include <asm/arch/imx-regs.h>
#include <asm/imx-common/gpio.h>
#include "mx6sabre_common.h"

/* Basic Machine Settings */
#define CONFIG_MACH_TYPE		3980
#define CONFIG_MXC_UART_BASE		UART1_BASE
#define CONFIG_CONSOLE_DEV		"ttymxc0" /* ttymxc0 serical console*/
#define CONFIG_MMCROOT			"/dev/mmcblk1p2" /* SDHC4 EMMC*/

/* Silent Serial console */
/*#define CONFIG_DISABLE_CONSOLE*/ // silent argument not needed */
#define CONFIG_SILENT_CONSOLE
#define CONFIG_SYS_DEVICE_NULLDEV
#define CONFIG_SILENT_CONSOLE_UPDATE_ON_RELOC

/* Memory Controller */
#define CONFIG_SYS_FSL_USDHC_NUM        1
#define CONFIG_SYS_MMC_ENV_DEV          0 /* SDHC4 */
#define CONFIG_SYS_MMC_ENV_PART         0 /* user partition */

/* NOR Flash Chipselect */
#ifdef CONFIG_SYS_USE_SPINOR
#define CONFIG_SF_DEFAULT_CS		(0|(IMX_GPIO_NR(3, 19)<<8))
#endif

#endif                         /* __MX6QSABRESD_CONFIG_H */
