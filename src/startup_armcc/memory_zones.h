#ifndef MEMORY_ZONES_H
#define MEMORY_ZONES_H

/*
 * Code memory zones
 * Please note that MPS2 on Fast Models do not implemented persistent flash memory.
 * The FLASH memory can be simulated via 4MB ZBT_SRAM1 block
 * only to keep the same name than in the CMSDK RTL and Fast Models Reference
 * Guide.
 */
#define ZBT_SRAM1_START 0x00000000
#define ZBT_SRAM1_SIZE 0x00400000 /* 4 MiB */

/* Data memory zones */
#define ZBT_SRAM2_START 0x20000000
#define ZBT_SRAM2_SIZE 0x00400000 /* 4 MiB */

#endif /* MEMORY_ZONES_H */
