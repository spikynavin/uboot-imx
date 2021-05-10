################# u-boot 2014.04 #################

/* Toolchain setup environmental file */
1. source ~/iwave-cc

/* Clean the old build */
2. make distclean

/* Choose the board file and configured in make */
3. make mx6solosabresd_config

/* Start to build the u-boot */
4. make -j8
5. sync

6. Flash the u-boot.imx by using the MFG-Tool

################# Available option ################

1. UART1 is initialized as main serial console and framebuffer console
2. Optimized size reduction is used
3. Uneeded configuration are removed
4. No Ethernet,USB,TFTP,NFS,EMMC Booting are supported
5. Silent console are added.
6. NOR Flash Booting is added as default booting media

