#include "systeminfo1Iarm.h"

static void systeminfo1_Loop();

#ifdef ENABLE_IARM
static IARM_Result_t issysteminfo1Available(void *arg);
#endif // ifdef ENABLE_IARM

int main(int argc, char *argv[])
{
#ifdef ENABLE_IARM
    IARM_Bus_RegisterCall(IARM_BUS_SYSTEMINFO1_API_isAvailable, issysteminfo1Available);
#endif
#ifdef ENABLE_SD_NOTIFY
    sd_notifyf(0, "READY=1\n"
               "STATUS=systeminfo1 is Successfully Initialized\n"
               "MAINPID=%lu",
               (unsigned long) getpid());
#endif

    systeminfo1_Loop();

}

#ifdef ENABLE_IARM
IARM_Result_t issysteminfo1Available(void *arg)
{
    LOG_ENTRY_EXIT;
    LOG_INFO("[%s] IARM_BUS_SYSTEMINFO1_API_isAvailable is called", MODULE_NAME);
    return IARM_RESULT_SUCCESS;
}
#endif // ENABLE_IARM

void systeminfo1_Loop()
{
    time_t curr = 0;
    while(1)
    {
        time(&curr);
#if !defined(ENABLE_XCAM_SUPPORT) && !defined(XHB1) && !defined(XHC3)
        printf("I-ARM SYSTEM-INFO1: HeartBeat at %s\r\n", ctime(&curr));
#endif
        sleep(60);
    }
}
