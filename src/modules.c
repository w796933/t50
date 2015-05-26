/** @file modules.c */
/*
 *  T50 - Experimental Mixed Packet Injector
 *
 *  Copyright (C) 2010 - 2015 - T50 developers
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <common.h>

// Valid options tables for specific protocols.
VALID_OPTIONS_TABLE(tcp, \
                      OPTION_ENCAPSULATED, \
                      OPTION_BOGUSCSUM, \
                      OPTION_SOURCE, \
                      OPTION_DESTINATION, \
                      OPTION_IP_TOS, \
                      OPTION_IP_ID, \
                      OPTION_IP_OFFSET, \
                      OPTION_IP_TTL, \
                      OPTION_IP_PROTOCOL, \
                      OPTION_IP_SOURCE, \
                      OPTION_GRE_SEQUENCE_PRESENT, \
                      OPTION_GRE_KEY_PRESENT, \
                      OPTION_GRE_CHECKSUM_PRESENT, \
                      OPTION_GRE_KEY, \
                      OPTION_GRE_SEQUENCE, \
                      OPTION_GRE_SADDR, \
                      OPTION_GRE_DADDR, \
                      OPTION_TCP_ACKNOWLEDGE, \
                      OPTION_TCP_SEQUENCE, \
                      OPTION_TCP_OFFSET, \
                      OPTION_TCP_FIN, \
                      OPTION_TCP_SYN, \
                      OPTION_TCP_RST, \
                      OPTION_TCP_PSH, \
                      OPTION_TCP_ACK, \
                      OPTION_TCP_URG, \
                      OPTION_TCP_ECE, \
                      OPTION_TCP_CWR, \
                      OPTION_TCP_WINDOW, \
                      OPTION_TCP_URGENT_POINTER, \
                      OPTION_TCP_MSS, \
                      OPTION_TCP_WSOPT, \
                      OPTION_TCP_TSOPT, \
                      OPTION_TCP_SACK_OK, \
                      OPTION_TCP_CC, \
                      OPTION_TCP_CC_NEW, \
                      OPTION_TCP_CC_ECHO, \
                      OPTION_TCP_SACK_EDGE, \
                      OPTION_TCP_MD5_SIGNATURE, \
                      OPTION_TCP_AUTHENTICATION, \
                      OPTION_TCP_AUTH_KEY_ID, \
                      OPTION_TCP_AUTH_NEXT_KEY, \
                      OPTION_TCP_NOP);

VALID_OPTIONS_TABLE(udp, \
                      OPTION_ENCAPSULATED, \
                      OPTION_BOGUSCSUM, \
                      OPTION_SOURCE, \
                      OPTION_DESTINATION, \
                      OPTION_IP_TOS, \
                      OPTION_IP_ID, \
                      OPTION_IP_OFFSET, \
                      OPTION_IP_TTL, \
                      OPTION_IP_PROTOCOL, \
                      OPTION_IP_SOURCE, \
                      OPTION_GRE_SEQUENCE_PRESENT, \
                      OPTION_GRE_KEY_PRESENT, \
                      OPTION_GRE_CHECKSUM_PRESENT, \
                      OPTION_GRE_KEY, \
                      OPTION_GRE_SEQUENCE, \
                      OPTION_GRE_SADDR, \
                      OPTION_GRE_DADDR);

VALID_OPTIONS_TABLE(icmp, \
                      OPTION_ENCAPSULATED, \
                      OPTION_BOGUSCSUM, \
                      OPTION_SOURCE, \
                      OPTION_DESTINATION, \
                      OPTION_IP_TOS, \
                      OPTION_IP_ID, \
                      OPTION_IP_OFFSET, \
                      OPTION_IP_TTL, \
                      OPTION_IP_PROTOCOL, \
                      OPTION_IP_SOURCE, \
                      OPTION_GRE_SEQUENCE_PRESENT, \
                      OPTION_GRE_KEY_PRESENT, \
                      OPTION_GRE_CHECKSUM_PRESENT, \
                      OPTION_GRE_KEY, \
                      OPTION_GRE_SEQUENCE, \
                      OPTION_GRE_SADDR, \
                      OPTION_GRE_DADDR, \
                      OPTION_ICMP_TYPE, \
                      OPTION_ICMP_CODE, \
                      OPTION_ICMP_GATEWAY, \
                      OPTION_ICMP_ID, \
                      OPTION_ICMP_SEQUENCE);

VALID_OPTIONS_TABLE(igmpv1, \
                      OPTION_ENCAPSULATED, \
                      OPTION_BOGUSCSUM, \
                      OPTION_SOURCE, \
                      OPTION_DESTINATION, \
                      OPTION_IP_TOS, \
                      OPTION_IP_ID, \
                      OPTION_IP_OFFSET, \
                      OPTION_IP_TTL, \
                      OPTION_IP_PROTOCOL, \
                      OPTION_IP_SOURCE, \
                      OPTION_GRE_SEQUENCE_PRESENT, \
                      OPTION_GRE_KEY_PRESENT, \
                      OPTION_GRE_CHECKSUM_PRESENT, \
                      OPTION_GRE_KEY, \
                      OPTION_GRE_SEQUENCE, \
                      OPTION_GRE_SADDR, \
                      OPTION_GRE_DADDR, \
                      OPTION_IGMP_TYPE, \
                      OPTION_IGMP_CODE, \
                      OPTION_IGMP_GROUP);

VALID_OPTIONS_TABLE(igmpv3, \
                      OPTION_ENCAPSULATED, \
                      OPTION_BOGUSCSUM, \
                      OPTION_SOURCE, \
                      OPTION_DESTINATION, \
                      OPTION_IP_TOS, \
                      OPTION_IP_ID, \
                      OPTION_IP_OFFSET, \
                      OPTION_IP_TTL, \
                      OPTION_IP_PROTOCOL, \
                      OPTION_IP_SOURCE, \
                      OPTION_GRE_SEQUENCE_PRESENT, \
                      OPTION_GRE_KEY_PRESENT, \
                      OPTION_GRE_CHECKSUM_PRESENT, \
                      OPTION_GRE_KEY, \
                      OPTION_GRE_SEQUENCE, \
                      OPTION_GRE_SADDR, \
                      OPTION_GRE_DADDR, \
                      OPTION_IGMP_TYPE, \
                      OPTION_IGMP_CODE, \
                      OPTION_IGMP_GROUP, \
                      OPTION_IGMP_QRV, \
                      OPTION_IGMP_SUPPRESS, \
                      OPTION_IGMP_QQIC, \
                      OPTION_IGMP_GREC_TYPE, \
                      OPTION_IGMP_SOURCES, \
                      OPTION_IGMP_GREC_MULTICAST, \
                      OPTION_IGMP_ADDRESS);

VALID_OPTIONS_TABLE(egp, \
                      OPTION_ENCAPSULATED, \
                      OPTION_BOGUSCSUM, \
                      OPTION_SOURCE, \
                      OPTION_DESTINATION, \
                      OPTION_IP_TOS, \
                      OPTION_IP_ID, \
                      OPTION_IP_OFFSET, \
                      OPTION_IP_TTL, \
                      OPTION_IP_PROTOCOL, \
                      OPTION_IP_SOURCE, \
                      OPTION_GRE_SEQUENCE_PRESENT, \
                      OPTION_GRE_KEY_PRESENT, \
                      OPTION_GRE_CHECKSUM_PRESENT, \
                      OPTION_GRE_KEY, \
                      OPTION_GRE_SEQUENCE, \
                      OPTION_GRE_SADDR, \
                      OPTION_GRE_DADDR, \
                      OPTION_EGP_TYPE, \
                      OPTION_EGP_CODE, \
                      OPTION_EGP_STATUS, \
                      OPTION_EGP_AS, \
                      OPTION_EGP_SEQUENCE, \
                      OPTION_EGP_HELLO, \
                      OPTION_EGP_POLL);

VALID_OPTIONS_TABLE(ripv1, \
                      OPTION_ENCAPSULATED, \
                      OPTION_BOGUSCSUM, \
                      OPTION_SOURCE, \
                      OPTION_DESTINATION, \
                      OPTION_IP_TOS, \
                      OPTION_IP_ID, \
                      OPTION_IP_OFFSET, \
                      OPTION_IP_TTL, \
                      OPTION_IP_PROTOCOL, \
                      OPTION_IP_SOURCE, \
                      OPTION_GRE_SEQUENCE_PRESENT, \
                      OPTION_GRE_KEY_PRESENT, \
                      OPTION_GRE_CHECKSUM_PRESENT, \
                      OPTION_GRE_KEY, \
                      OPTION_GRE_SEQUENCE, \
                      OPTION_GRE_SADDR, \
                      OPTION_GRE_DADDR, \
                      OPTION_RIP_COMMAND, \
                      OPTION_RIP_FAMILY, \
                      OPTION_RIP_ADDRESS, \
                      OPTION_RIP_METRIC);

VALID_OPTIONS_TABLE(ripv2, \
                      OPTION_ENCAPSULATED, \
                      OPTION_BOGUSCSUM, \
                      OPTION_SOURCE, \
                      OPTION_DESTINATION, \
                      OPTION_IP_TOS, \
                      OPTION_IP_ID, \
                      OPTION_IP_OFFSET, \
                      OPTION_IP_TTL, \
                      OPTION_IP_PROTOCOL, \
                      OPTION_IP_SOURCE, \
                      OPTION_GRE_SEQUENCE_PRESENT, \
                      OPTION_GRE_KEY_PRESENT, \
                      OPTION_GRE_CHECKSUM_PRESENT, \
                      OPTION_GRE_KEY, \
                      OPTION_GRE_SEQUENCE, \
                      OPTION_GRE_SADDR, \
                      OPTION_GRE_DADDR, \
                      OPTION_RIP_COMMAND, \
                      OPTION_RIP_FAMILY, \
                      OPTION_RIP_ADDRESS, \
                      OPTION_RIP_METRIC, \
                      OPTION_RIP_DOMAIN, \
                      OPTION_RIP_TAG, \
                      OPTION_RIP_NETMASK, \
                      OPTION_RIP_NEXTHOP, \
                      OPTION_RIP_AUTHENTICATION, \
                      OPTION_RIP_AUTH_KEY_ID, \
                      OPTION_RIP_AUTH_SEQUENCE);

VALID_OPTIONS_TABLE(dccp, \
                      OPTION_ENCAPSULATED, \
                      OPTION_BOGUSCSUM, \
                      OPTION_SOURCE, \
                      OPTION_DESTINATION, \
                      OPTION_IP_TOS, \
                      OPTION_IP_ID, \
                      OPTION_IP_OFFSET, \
                      OPTION_IP_TTL, \
                      OPTION_IP_PROTOCOL, \
                      OPTION_IP_SOURCE, \
                      OPTION_GRE_SEQUENCE_PRESENT, \
                      OPTION_GRE_KEY_PRESENT, \
                      OPTION_GRE_CHECKSUM_PRESENT, \
                      OPTION_GRE_KEY, \
                      OPTION_GRE_SEQUENCE, \
                      OPTION_GRE_SADDR, \
                      OPTION_GRE_DADDR, \
                      OPTION_DCCP_OFFSET, \
                      OPTION_DCCP_CSCOV, \
                      OPTION_DCCP_CCVAL, \
                      OPTION_DCCP_TYPE, \
                      OPTION_DCCP_EXTEND, \
                      OPTION_DCCP_SEQUENCE_01, \
                      OPTION_DCCP_SEQUENCE_02, \
                      OPTION_DCCP_SEQUENCE_03, \
                      OPTION_DCCP_SERVICE, \
                      OPTION_DCCP_ACKNOWLEDGE_01, \
                      OPTION_DCCP_ACKNOWLEDGE_02, \
                      OPTION_DCCP_RESET_CODE);

VALID_OPTIONS_TABLE(rsvp, \
                      OPTION_ENCAPSULATED, \
                      OPTION_BOGUSCSUM, \
                      OPTION_SOURCE, \
                      OPTION_DESTINATION, \
                      OPTION_IP_TOS, \
                      OPTION_IP_ID, \
                      OPTION_IP_OFFSET, \
                      OPTION_IP_TTL, \
                      OPTION_IP_PROTOCOL, \
                      OPTION_IP_SOURCE, \
                      OPTION_GRE_SEQUENCE_PRESENT, \
                      OPTION_GRE_KEY_PRESENT, \
                      OPTION_GRE_CHECKSUM_PRESENT, \
                      OPTION_GRE_KEY, \
                      OPTION_GRE_SEQUENCE, \
                      OPTION_GRE_SADDR, \
                      OPTION_GRE_DADDR, \
                      OPTION_RSVP_FLAGS, \
                      OPTION_RSVP_TYPE, \
                      OPTION_RSVP_TTL, \
                      OPTION_RSVP_SESSION_ADDRESS, \
                      OPTION_RSVP_SESSION_PROTOCOL, \
                      OPTION_RSVP_SESSION_FLAGS, \
                      OPTION_RSVP_SESSION_PORT, \
                      OPTION_RSVP_HOP_ADDRESS, \
                      OPTION_RSVP_HOP_IFACE, \
                      OPTION_RSVP_TIME_REFRESH, \
                      OPTION_RSVP_ERROR_ADDRESS, \
                      OPTION_RSVP_ERROR_FLAGS, \
                      OPTION_RSVP_ERROR_CODE, \
                      OPTION_RSVP_ERROR_VALUE, \
                      OPTION_RSVP_SCOPE, \
                      OPTION_RSVP_SCOPE_ADDRESS, \
                      OPTION_RSVP_STYLE_OPTION, \
                      OPTION_RSVP_SENDER_ADDRESS, \
                      OPTION_RSVP_SENDER_PORT, \
                      OPTION_RSVP_TSPEC_TRAFFIC, \
                      OPTION_RSVP_TSPEC_GUARANTEED, \
                      OPTION_RSVP_TSPEC_TOKEN_R, \
                      OPTION_RSVP_TSPEC_TOKEN_B, \
                      OPTION_RSVP_TSPEC_DATA_P, \
                      OPTION_RSVP_TSPEC_MINIMUM, \
                      OPTION_RSVP_TSPEC_MAXIMUM, \
                      OPTION_RSVP_ADSPEC_ISHOP, \
                      OPTION_RSVP_ADSPEC_PATH, \
                      OPTION_RSVP_ADSPEC_MINIMUM, \
                      OPTION_RSVP_ADSPEC_MTU, \
                      OPTION_RSVP_ADSPEC_GUARANTEED, \
                      OPTION_RSVP_ADSPEC_CONTROLLED, \
                      OPTION_RSVP_ADSPEC_CTOT, \
                      OPTION_RSVP_ADSPEC_DTOT, \
                      OPTION_RSVP_ADSPEC_CSUM, \
                      OPTION_RSVP_ADSPEC_DSUM, \
                      OPTION_RSVP_CONFIRM_ADDR);

VALID_OPTIONS_TABLE(ipsec, \
                      OPTION_ENCAPSULATED, \
                      OPTION_BOGUSCSUM, \
                      OPTION_SOURCE, \
                      OPTION_DESTINATION, \
                      OPTION_IP_TOS, \
                      OPTION_IP_ID, \
                      OPTION_IP_OFFSET, \
                      OPTION_IP_TTL, \
                      OPTION_IP_PROTOCOL, \
                      OPTION_IP_SOURCE, \
                      OPTION_GRE_SEQUENCE_PRESENT, \
                      OPTION_GRE_KEY_PRESENT, \
                      OPTION_GRE_CHECKSUM_PRESENT, \
                      OPTION_GRE_KEY, \
                      OPTION_GRE_SEQUENCE, \
                      OPTION_GRE_SADDR, \
                      OPTION_GRE_DADDR, \
                      OPTION_IPSEC_AH_LENGTH, \
                      OPTION_IPSEC_AH_SPI, \
                      OPTION_IPSEC_AH_SEQUENCE, \
                      OPTION_IPSEC_ESP_SPI, \
                      OPTION_IPSEC_ESP_SEQUENCE);

VALID_OPTIONS_TABLE(eigrp, \
                      OPTION_ENCAPSULATED, \
                      OPTION_BOGUSCSUM, \
                      OPTION_SOURCE, \
                      OPTION_DESTINATION, \
                      OPTION_IP_TOS, \
                      OPTION_IP_ID, \
                      OPTION_IP_OFFSET, \
                      OPTION_IP_TTL, \
                      OPTION_IP_PROTOCOL, \
                      OPTION_IP_SOURCE, \
                      OPTION_GRE_SEQUENCE_PRESENT, \
                      OPTION_GRE_KEY_PRESENT, \
                      OPTION_GRE_CHECKSUM_PRESENT, \
                      OPTION_GRE_KEY, \
                      OPTION_GRE_SEQUENCE, \
                      OPTION_GRE_SADDR, \
                      OPTION_GRE_DADDR, \
                      OPTION_EIGRP_OPCODE, \
                      OPTION_EIGRP_FLAGS, \
                      OPTION_EIGRP_SEQUENCE, \
                      OPTION_EIGRP_ACKNOWLEDGE, \
                      OPTION_EIGRP_AS, \
                      OPTION_EIGRP_TYPE, \
                      OPTION_EIGRP_LENGTH, \
                      OPTION_EIGRP_K1, \
                      OPTION_EIGRP_K2, \
                      OPTION_EIGRP_K3, \
                      OPTION_EIGRP_K4, \
                      OPTION_EIGRP_K5, \
                      OPTION_EIGRP_HOLD, \
                      OPTION_EIGRP_IOS_VERSION, \
                      OPTION_EIGRP_PROTO_VERSION, \
                      OPTION_EIGRP_NEXTHOP, \
                      OPTION_EIGRP_DELAY, \
                      OPTION_EIGRP_BANDWIDTH, \
                      OPTION_EIGRP_MTU, \
                      OPTION_EIGRP_HOP_COUNT, \
                      OPTION_EIGRP_LOAD, \
                      OPTION_EIGRP_RELIABILITY, \
                      OPTION_EIGRP_DESINATION, \
                      OPTION_EIGRP_SOURCE_ROUTER, \
                      OPTION_EIGRP_SOURCE_AS, \
                      OPTION_EIGRP_TAG, \
                      OPTION_EIGRP_METRIC, \
                      OPTION_EIGRP_ID, \
                      OPTION_EIGRP_EXTERNAL_FLAGS, \
                      OPTION_EIGRP_ADDRESS, \
                      OPTION_EIGRP_MULTICAST, \
                      OPTION_EIGRP_AUTHENTICATION, \
                      OPTION_EIGRP_AUTH_KEY_ID);

VALID_OPTIONS_TABLE(ospf, \
                      OPTION_ENCAPSULATED, \
                      OPTION_BOGUSCSUM, \
                      OPTION_SOURCE, \
                      OPTION_DESTINATION, \
                      OPTION_IP_TOS, \
                      OPTION_IP_ID, \
                      OPTION_IP_OFFSET, \
                      OPTION_IP_TTL, \
                      OPTION_IP_PROTOCOL, \
                      OPTION_IP_SOURCE, \
                      OPTION_GRE_SEQUENCE_PRESENT, \
                      OPTION_GRE_KEY_PRESENT, \
                      OPTION_GRE_CHECKSUM_PRESENT, \
                      OPTION_GRE_KEY, \
                      OPTION_GRE_SEQUENCE, \
                      OPTION_GRE_SADDR, \
                      OPTION_GRE_DADDR, \
                      OPTION_EIGRP_OPCODE, \
                      OPTION_EIGRP_FLAGS, \
                      OPTION_EIGRP_SEQUENCE, \
                      OPTION_EIGRP_ACKNOWLEDGE, \
                      OPTION_EIGRP_AS, \
                      OPTION_EIGRP_TYPE, \
                      OPTION_EIGRP_LENGTH, \
                      OPTION_EIGRP_K1, \
                      OPTION_EIGRP_K2, \
                      OPTION_EIGRP_K3, \
                      OPTION_EIGRP_K4, \
                      OPTION_EIGRP_K5, \
                      OPTION_EIGRP_HOLD, \
                      OPTION_EIGRP_IOS_VERSION, \
                      OPTION_EIGRP_PROTO_VERSION, \
                      OPTION_EIGRP_NEXTHOP, \
                      OPTION_EIGRP_DELAY, \
                      OPTION_EIGRP_BANDWIDTH, \
                      OPTION_EIGRP_MTU, \
                      OPTION_EIGRP_HOP_COUNT, \
                      OPTION_EIGRP_LOAD, \
                      OPTION_EIGRP_RELIABILITY, \
                      OPTION_EIGRP_DESINATION, \
                      OPTION_EIGRP_SOURCE_ROUTER, \
                      OPTION_EIGRP_SOURCE_AS, \
                      OPTION_EIGRP_TAG, \
                      OPTION_EIGRP_METRIC, \
                      OPTION_EIGRP_ID, \
                      OPTION_EIGRP_EXTERNAL_FLAGS, \
                      OPTION_EIGRP_ADDRESS, \
                      OPTION_EIGRP_MULTICAST, \
                      OPTION_EIGRP_AUTHENTICATION, \
                      OPTION_EIGRP_AUTH_KEY_ID, \
                      OPTION_OSPF_TYPE, \
                      OPTION_OSPF_LENGTH, \
                      OPTION_OSPF_ROUTER_ID, \
                      OPTION_OSPF_AREA_ID, \
                      OPTION_OSPF_NETMASK, \
                      OPTION_OSPF_MT, \
                      OPTION_OSPF_E, \
                      OPTION_OSPF_MC, \
                      OPTION_OSPF_NP, \
                      OPTION_OSPF_L, \
                      OPTION_OSPF_DC, \
                      OPTION_OSPF_O, \
                      OPTION_OSPF_DN, \
                      OPTION_OSPF_HELLO_INTERVAL, \
                      OPTION_OSPF_HELLO_PRIORITY, \
                      OPTION_OSPF_HELLO_DEAD, \
                      OPTION_OSPF_HELLO_DESIGN, \
                      OPTION_OSPF_HELLO_BACKUP, \
                      OPTION_OSPF_HELLO_NEIGHBOR, \
                      OPTION_OSPF_HELLO_ADDRESS, \
                      OPTION_OSPF_DD_MTU, \
                      OPTION_OSPF_DD_MASTER_SLAVE, \
                      OPTION_OSPF_DD_MORE, \
                      OPTION_OSPF_DD_INIT, \
                      OPTION_OSPF_DD_OOBRESYNC, \
                      OPTION_OSPF_DD_SEQUENCE, \
                      OPTION_OSPF_DD_INCLUDE_LSA, \
                      OPTION_OSPF_LSA_AGE, \
                      OPTION_OSPF_LSA_DO_NOT_AGE, \
                      OPTION_OSPF_LSA_TYPE, \
                      OPTION_OSPF_LSA_LSID, \
                      OPTION_OSPF_LSA_ROUTER, \
                      OPTION_OSPF_LSA_SEQUENCE, \
                      OPTION_OSPF_LSA_METRIC, \
                      OPTION_OSPF_LSA_FLAG_BORDER, \
                      OPTION_OSPF_LSA_FLAG_EXTERNAL, \
                      OPTION_OSPF_LSA_FLAG_VIRTUAL, \
                      OPTION_OSPF_LSA_FLAG_WILD, \
                      OPTION_OSPF_LSA_FLAG_NSSA_TR, \
                      OPTION_OSPF_LSA_LINK_ID, \
                      OPTION_OSPF_LSA_LINK_DATA, \
                      OPTION_OSPF_LSA_LINK_TYPE, \
                      OPTION_OSPF_LSA_ATTACHED, \
                      OPTION_OSPF_LSA_LARGER, \
                      OPTION_OSPF_LSA_FORWARD, \
                      OPTION_OSPF_LSA_EXTERNAL, \
                      OPTION_OSPF_VERTEX_ROUTER, \
                      OPTION_OSPF_VERTEX_NETWORK, \
                      OPTION_OSPF_VERTEX_ID, \
                      OPTION_OSPF_LLS_OPTION_LR, \
                      OPTION_OSPF_LLS_OPTION_RS, \
                      OPTION_OSPF_AUTHENTICATION, \
                      OPTION_OSPF_AUTH_KEY_ID, \
                      OPTION_OSPF_AUTH_SEQUENCE);

/* NOTE: A simple way to define the protocols table!

  To add a procotol, insert the proper header file on common.h (ex: protocol/xpto.h),
  change the Makefile, add a MODULE_ENTRY, modify config.c and usage.c and compile. That's it! */
BEGIN_MODULES_TABLE
           /* ( proto,        acronym,  description,                                  function ) */
  MODULE_ENTRY(IPPROTO_ICMP,  "ICMP",   "Internet Control Message Protocol",          icmp)
  MODULE_ENTRY(IPPROTO_IGMP,  "IGMPv1", "Internet Group Message Protocol v1",         igmpv1)
  MODULE_ENTRY(IPPROTO_IGMP,  "IGMPv3", "Internet Group Message Protocol v3",         igmpv3)
  MODULE_ENTRY(IPPROTO_TCP,   "TCP",    "Transmission Control Protocol",              tcp)
  MODULE_ENTRY(IPPROTO_EGP,   "EGP",    "Exterior Gateway Protocol",                  egp)
  MODULE_ENTRY(IPPROTO_UDP,   "UDP",    "User Datagram Protocol",                     udp)
  MODULE_ENTRY(IPPROTO_UDP,   "RIPv1",  "Routing Internet Protocol v1",               ripv1)
  MODULE_ENTRY(IPPROTO_UDP,   "RIPv2",  "Routing Internet Protocol v2",               ripv2)
  MODULE_ENTRY(IPPROTO_DCCP,  "DCCP",   "Datagram Congestion Control Protocol",       dccp)
  MODULE_ENTRY(IPPROTO_RSVP,  "RSVP",   "Resource Reservation Protocol",              rsvp)
  MODULE_ENTRY(IPPROTO_AH,    "IPSEC",  "Internet Security Protocl (AH/ESP)",         ipsec)
  MODULE_ENTRY(IPPROTO_EIGRP, "EIGRP",  "Enhanced Interior Gateway Routing Protocol", eigrp)
  MODULE_ENTRY(IPPROTO_OSPF,  "OSPF",   "Open Shortest Path First",                   ospf)
END_MODULES_TABLE

