#pragma once

#include <cstdint>
#include <arpa/inet.h>

#pragma pack(push, 1)
struct TcpHdr final {
    uint16_t sport_;     // Source port
    uint16_t dport_;     // Destination port
    uint32_t seq_;       // Sequence number
    uint32_t ack_;       // Acknowledgment number
    uint8_t off_rsvd_;   // Data offset (4 bits), Reserved (4 bits)
    uint8_t flags_;      // Flags
    uint16_t win_;       // Window size
    uint16_t sum_;       // Checksum
    uint16_t urp_;       // Urgent pointer

    uint16_t sport() const { return ntohs(sport_); }
    uint16_t dport() const { return ntohs(dport_); }
    uint8_t offset() const { return (off_rsvd_ >> 4) * 4; }

    enum : uint16_t {
        Http = 80,
        Https = 443
    };
};
typedef TcpHdr* PTcpHdr;
#pragma pack(pop)
