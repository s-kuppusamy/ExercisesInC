#include "util.h"

int max_ttl;

Sockaddr *sasend;    /* socket addresses for various purposes */
Sockaddr *sarecv;
Sockaddr *salast;
Sockaddr *sabind;

socklen_t salen;                    /* length of a socket address */
int datalen;

typedef struct rec {                /* outgoing UDP data */
  u_short seq;          /* sequence number */
} Rec;

#define max(a,b) ((a) > (b) ? (a) : (b))

void loop_ttl ();
int send_probes (int ttl);
void send_dgram (int ttl);
void print_report ();
double time_to_double (Timeval *time);
void sub_tv (Timeval *plus, Timeval *minus, Timeval *res);
int recv_dgram ();
int process_ip (struct ip *ip, int len);
void sig_alrm (int signo);
