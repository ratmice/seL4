/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * This software may be distributed and modified according to the terms of
 * the GNU General Public License version 2. Note that NO WARRANTY is provided.
 * See "LICENSE_GPLv2.txt" for details.
 *
 * @TAG(GD_GPL)
 */

#ifndef __ARCH_MODEL_STATEDATA_32_H
#define __ARCH_MODEL_STATEDATA_32_H

#include <config.h>
#include <types.h>
#include <arch/types.h>
#include <util.h>
#include <object/structures.h>
#include <model/smp.h>

extern word_t armKSGlobalsFrame[BIT(ARMSmallPageBits) / sizeof(word_t)] VISIBLE;
extern asid_pool_t *armKSASIDTable[BIT(asidHighBits)] VISIBLE;
extern asid_t armKSHWASIDTable[BIT(hwASIDBits)] VISIBLE;
extern hw_asid_t armKSNextASID VISIBLE;

#ifndef CONFIG_ARM_HYPERVISOR_SUPPORT
extern pde_t armKSGlobalPD[BIT(PD_INDEX_BITS)] VISIBLE;
extern pte_t armKSGlobalPT[BIT(PT_INDEX_BITS)] VISIBLE;

#ifdef CONFIG_BENCHMARK_USE_KERNEL_LOG_BUFFER
extern pte_t armKSGlobalLogPT[BIT(PT_INDEX_BITS)] VISIBLE;
#endif /* CONFIG_BENCHMARK_USE_KERNEL_LOG_BUFFER */

#else
extern pdeS1_t armHSGlobalPGD[BIT(PGD_INDEX_BITS)] VISIBLE;
extern pdeS1_t armHSGlobalPD[BIT(PT_INDEX_BITS)]   VISIBLE;
extern pteS1_t armHSGlobalPT[BIT(PT_INDEX_BITS)]   VISIBLE;
/* Stage 2 translations have a slightly different encoding to Stage 1
 * So we need to build a User global PT for global mappings */
extern pte_t   armUSGlobalPT[BIT(PT_INDEX_BITS)]   VISIBLE;
extern vcpu_t *armHSCurVCPU;
extern bool_t armHSVCPUActive;
#endif /* CONFIG_ARM_HYPERVISOR_SUPPORT */

#endif /* __ARCH_MODEL_STATEDATA_32_H */
