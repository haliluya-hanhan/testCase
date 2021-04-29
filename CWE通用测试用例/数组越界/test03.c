//check type:c/cpp
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include<ws2tcpip.h>   //定义socklen_t

typedef int curl_socket_t;
typedef struct tftp_packet {
  unsigned char *data;
} tftp_packet_t;
#define CURL_TYPEOF_CURL_SOCKLEN_T socklen_t
typedef CURL_TYPEOF_CURL_SOCKLEN_T curl_socklen_t;
typedef enum {
  TFTP_EVENT_NONE = -1,
  TFTP_EVENT_INIT = 0,
  TFTP_EVENT_RRQ = 1,
  TFTP_EVENT_WRQ = 2,
  TFTP_EVENT_DATA = 3,
  TFTP_EVENT_ACK = 4,
  TFTP_EVENT_ERROR = 5,
  TFTP_EVENT_OACK = 6,
  TFTP_EVENT_TIMEOUT
} tftp_event_t;
typedef struct tftp_state_data {
  tftp_event_t    event;
  curl_socket_t   sockfd;
  int             rbytes;
  int             blksize;
   tftp_packet_t   rpacket;
} tftp_state_data_t;
struct Curl_easy {
	int a;
};
struct Curl_sockaddr_storage {
 int b;
};
typedef enum {
  CURLE_OK = 0,

  CURLE_TFTP_ILLEGAL,            /* 71 - Illegal TFTP operation */

} CURLcode;
struct connectdata {

  struct Curl_easy *data;
    union {
     struct tftp_state_data *tftpc;
  } proto;

};
static const char *func_s_19_02_medium_NNTS_TAINTED_01_bad(const char *buf, size_t len,
                                   const char **option, const char **value)
{
  size_t loc;

*option=buf;
  *value = &buf[strlen(*option) + 1];   //not compliant漏报---*option无结束符

  return &buf[loc];
}
static CURLcode tftp_parse_option_ack(tftp_state_data_t *state,
                                      const char *ptr, int len)
{
  const char *tmp = ptr;
  while(tmp < ptr + len) {
    const char *option, *value;
    tmp = func_s_19_02_medium_NNTS_TAINTED_01_bad(tmp, ptr + len - tmp, &option, &value);
    if(tmp == NULL) {

      return CURLE_TFTP_ILLEGAL;
    }
  }
  return CURLE_OK;
}

static CURLcode tftp_receive_packet(struct connectdata *conn)
{
  struct Curl_sockaddr_storage fromaddr;
  curl_socklen_t        fromlen;
  CURLcode              result = CURLE_OK;
  struct Curl_easy  *data = conn->data;
  tftp_state_data_t     *state = (tftp_state_data_t *)conn->proto.tftpc;
  /* Receive the packet */
  fromlen = sizeof(fromaddr);
  state->rbytes = (int)recvfrom(state->sockfd,
                                (void *)state->rpacket.data,
                                state->blksize+4,
                                0,
                                (struct sockaddr *)&fromaddr,
                                &fromlen);

    /* The event is given by the TFTP packet time */
  //  state->event = (tftp_event_t)getrpacketevent(&state->rpacket);

    switch(state->event) {

    case TFTP_EVENT_OACK:
      result = tftp_parse_option_ack(state,
                                     (const char *)state->rpacket.data+2,
                                     state->rbytes-2);
      if(result)
        return result;
      break;

    default:

      break;
    }

  return result;
}

