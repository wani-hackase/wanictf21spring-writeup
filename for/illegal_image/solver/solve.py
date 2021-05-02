from scapy.all import *

packets = rdpcap("captured.pcap")

data = ""
for p in packets:
    if p.haslayer(ICMP):
        if p[IP].src == "192.168.0.133":
            data += p[Raw].load

with open("flag.jpg", "wb") as f:
    f.write(data)
