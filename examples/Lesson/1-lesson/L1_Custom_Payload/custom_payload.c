// Contiki specific includes
#include "contiki.h"
#include "net/netstack.h"
#include "lib/random.h"
#include "dev/leds.h"

// standard C includes:
#include "stdio.h"
#include "stdint.h"

#define BROADCAST_RIME_CHANNEL 129
#define BROADCAST_INTERVAL 5
#define CHANNEL 14
#define POWER 3
#define MY_ADDR 2
#define MAX_PAYLOAD 80
#define MAX_N 20

typedef struct{
    char name[MAX_N];
    char surname[MAX_N];
    uint8_t tel[MAX_N];
}

static contact tx_contacts;
const struct contax *contact_adr = &tx_contacts;

PROCESS(custom_payload_process, "Lesson 2: Custom Payload");
// Create an instance of a broadcast connection

static struct broadcast_conn broadcast;

static void broadcast_recv(struct broadcast_conn *c, const linkaddr_t *from){
    leds_on(LEDS_GREEN);

    printf("Broadcast Routing message received from 0x%x%x: \n\r [RSSI %d]\n\r",
			from->u8[0], from->u8[1],
			packetbuf_attr(PACKETBUF_ATTR_RSSI));

    static contact rx_contacts;
    struct contact *rx_adr = &rx_contacts;
    packetbuf_copyto(rx_adr);
}