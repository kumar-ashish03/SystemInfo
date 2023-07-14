#ifndef _SYSTEMINFO1IARM_H_
#define _SYSTEMINFO1IARM_H_

#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <glib.h>

extern "C" {
#include "cJSON.h"
#ifdef ENABLE_SD_NOTIFY
#include <systemd/sd-daemon.h>
#endif
}

#ifdef ENABLE_IARM
#include "irMgr.h"
#include "comcastIrKeyCodes.h"
#include "libIARM.h"
#include "libIBus.h"
#endif

/**
 * @addtogroup SYSTEMINFO1_TYPES
 * @{
 */
#define IARM_BUS_SYS_INFO1_NAME "SYSTEM_INFO1"

#define IARM_BUS_SYSTEMINFO1_API_isAvailable "issysteminfo1Available"

#endif /* _SYSTEMINFOIARM_H_ */
