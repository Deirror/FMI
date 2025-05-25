# Calculating IP Addresses, Subnets and nets


In what subnet is located the IP Address?
-

- **IP**: *[0-255].[0-255].[0-255].[0-255] (/[0-32])*
- **Subnet**: *[0-255].[0-255].[0-255].[0-255]* - which is defined by the **CIDR** => *(32 - /[0-32])* - how many 0s starting from the end
- **Count Of IP Address In Each Subnet**: *(2^(32 - /[0-32]))*
- We start from 0 in the octet, where the position of the bit *(32 - /[0-32])* is, and count one by one, by adding *(2^(32 - /[0-32]))*
- The subnet of the IP Address is the starting IP of the given subnet where the IP Address itself is located (<= the starting IP Addr and >= the end of the subnet)

- Examples: *View the first Homework.pdf*
