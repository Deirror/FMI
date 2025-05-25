# Calculating IP Addresses, Subnets and nets


In what subnet is located the IP Address?
-

- **IP**: *[0-255].[0-255].[0-255].[0-255] (/[0-32])*
- **Mask**: *[0-255].[0-255].[0-255].[0-255]* - which is defined by the **CIDR** => *(32 - /[0-32])* - how many 0s starting from the end
- **Count Of IP Address In Each Subnet**: *(2^(32 - /[0-32]))*
- We start from 0 in the octet, where the position of the bit *(32 - /[0-32])* is, and count one by one, by adding *(2^(32 - /[0-32]))*
- The subnet of the IP Address is the starting IP of the given subnet where the IP Address itself is located (<= the starting IP Addr and >= the end of the subnet)

Examples: [*View HW1.pdf*](https://github.com/Deirror/FMI/blob/main/CN/Solving%20IP%20Addresses/Homeworks/HW1.pdf)

How to devide a net into subnets based on how many IPs each router needs?
-

- **Net IP Address**: *[0-255].[0-255].[0-255].[0-255] (/[0-32])*
- **Nr1, Nr2 and etc**: natural numbers
- **Count Of IP Address In Each Subnet**: *(2^(32 - /[0-32]))*
- First, we sort the routers in **DESC** order and start rounding **Nri** to the nearest power of 2
- After that, we have made the subnets with the rounded IP Addresses and that's the result itself (we have some unused IP Addresses also)

Examples: [*View HW1.pdf*](https://github.com/Deirror/FMI/blob/main/CN/Solving%20IP%20Addresses/Homeworks/HW1.pdf)

How to devide a net into N equally separated subnets?
-

- **Net IP Address**: *[0-255].[0-255].[0-255].[0-255] (/[0-32])*
- **N**: a natural number
- First, we solve (2^X) = N, and get X
- Then we do (/[0-32]) += X and *(32 - /[0-32])* is the result
- Based on the result we get how many IP addresses will be there for each N subnet (the count of the zeros converted into a decimal number)
- The final result is the N subnets with the corresponding equally set IP Addresses

> [!WARNING]
> The *(32 - /[0-32])* bits from the end to the start must be all zeros.
> If not, then we changed the Net IP Address by substracting by 1, until we get a valid number in binary format 

Examples: [*View HW2.pdf*](https://github.com/Deirror/FMI/blob/main/CN/Solving%20IP%20Addresses/Homeworks/HW2.pdf)

How to calculate the number of subnets and Host Addresses based on an IP Class and a given mask?
-

- **IP Class**: *[A-C]*
- 
