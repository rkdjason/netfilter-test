#pragma once

#include <cstdint>
#include <arpa/inet.h>

#pragma pack(push, 1)
struct IpHdr final {
    uint8_t v_hl_;         // Version (4 bits) + Header Length (4 bits)
    uint8_t tos_;          // Type of Service
    uint16_t len_;         // Total Length
    uint16_t id_;          // Identification
    uint16_t offset_;      // Flags (3 bits) + Fragment Offset (13 bits)
    uint8_t ttl_;          // Time to Live
    uint8_t protocol_;     // Protocol
    uint16_t checksum_;    // Header checksum
    uint32_t sip_;         // Source IP
    uint32_t dip_;         // Destination IP

    uint8_t v() const { return v_hl_ >> 4; }
    uint8_t hl() const { return v_hl_ & 0x0F; }
    uint16_t len() const { return ntohs(len_); }
    uint16_t id() const { return ntohs(id_); }
    uint16_t offset() const { return ntohs(offset_); }
    uint8_t ttl() const { return ttl_; }
    uint8_t protocol() const { return protocol_; }
    uint16_t checksum() const { return ntohs(checksum_); }
    uint32_t sip() const { return ntohl(sip_); }
    uint32_t dip() const { return ntohl(dip_); }

    enum : uint8_t {
        Tcp = 6,
        Udp = 17,
        Icmp = 1
    };
};
typedef IpHdr *PIpHdr;
#pragma pack(pop)
