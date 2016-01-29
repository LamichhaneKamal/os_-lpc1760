/******************************************************************************
 * Sample RTX project.														  *
 * Listing of the supervisor calls of the RTX								  *
 * @author Thomas Reidemeister												  *
 * @date 2011/26/11															  *
 ******************************************************************************/

#ifndef _svc_h_
#define _svc_h_

#include "lpc17xx.h"
#include "rtx.h"

/** defined constants that correspond to the supervisor call numbers 
 * Not this took me days to debug. Apparently the numbers usable are
 * limited... and conflicting with ISP traps.
 * http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.dui0203j/Bgbjhiea.html
 */
#define SVC_SEND_MESSAGE     0x30
#define SVC_RECEIVE_MESSAGE  0x31
#define SVC_REQUEST_MEMBLK   0x32
#define SVC_RELEASE_MEMBLK   0x33
#define SVC_RELEASE_PROC     0x34
#define SVC_SEND_DELAYED     0x35
#define SVC_GET_PRIORITY     0x36
#define SVC_SET_PRIORITY     0x37
#define SVC_SEND_CONSOLE     0x38
#define SVC_GET_CONSOLE      0x39

/*** ARMCC compiler abstractions for supervisor calls ************************
 * Note that the parameters are setup on PSP and can be reverse-engineerd in *
 * the SWI.                                                                  *
 * @see SVC_Handler															 *
 * http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.dui0203h/BABFGEFG.html
 *****************************************************************************/

/** @see k_send_message */
uint32_t __svc(SVC_SEND_MESSAGE) send_message(uint32_t pid, msg_t *p_msg);
/** @see k_receive_message (returns address to msg_t) */
uint32_t __svc(SVC_RECEIVE_MESSAGE) receive_message(void);
/** @see k_request_memory (returns address to msg_t)*/
uint32_t __svc(SVC_REQUEST_MEMBLK) request_memory(void);
/** @see k_release_memory */
uint32_t __svc(SVC_RELEASE_MEMBLK) release_memory(msg_t *p_msg);
/** @see k_release_processor */
uint32_t __svc(SVC_RELEASE_PROC) release_processor(void);
/** @see k_send_delayed */
uint32_t __svc(SVC_SEND_DELAYED) request_delay(msg_t *msg, uint32_t delay);
/** @see k_get_priority */
uint32_t __svc(SVC_GET_PRIORITY) get_priority(uint32_t pid);
/** @see k_set_priority */
uint32_t __svc(SVC_SET_PRIORITY) set_priority(uint32_t pid, uint32_t prio);
/** @see k_send_console_chars */
uint32_t __svc(SVC_SEND_CONSOLE) send_console_chars(msg_t * env);
/** @see k_request_console_chars */
uint32_t __svc(SVC_GET_CONSOLE) request_console_chars(msg_t * env);


#endif /* _svc_h_ */
