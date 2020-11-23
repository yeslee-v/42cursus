# Wrong

## 1. 255.255.255.0
    Class C networks use a default subnet mask of 255.255. 255.0 and have 192-223 as their first octet.

## 2. What is the maximum number of IP addresses that can be assigned to hosts on a local subnet that uses the 255.255.255.240 subnet mask?
 ```c
 2
 30 << pick
 4
 32
 14
 16
 8
 6
 10
```
- Subnet 서브넷 아이피 갯수 구하기~~~~

        240 = 1111 0000
        2^4 - 2 = 14

# Confused

## 1. Which of the following is the valid host range for the subnet on which the IP address 225.252.234.29/27 resides?
```c
225.252.234.1-225.252.234.30 << pick
225.252.233.255-225.252.234.26
225.252.234.6-225.252.234.30
225.252.234.1-225.252.234.33
```
## 2. Which of the following is the valid host range for the subnet on which the IP address 146.109.6.148/23 resides?
```c
146.109.6.1-146.109.8.3
146.109.5.252-146.109.7.254
146.109.6.1-146.109.8.0
146.109.6.1-146.109.7.254 << pick
146.109.6.1-146.109.8.1
146.109.6.6-146.109.7.254
```

## 3. What is the Network address of a host with an IP address of 148.99.74.12/12?
```c
148.99.64.0
148.98.0.0
148.96.0.0 << pick
128.0.0.0
144.0.0.0
148.99.72.0
148.99.74.0
```
## 4. Which of the following services use UDP?
1. DHCP 2. SMTP 3. FTP 4. HTTP
```c
 All of the above
 1 << pick
 3
 2
 ```
## 5. Which of the following is the valid host range for the subnet on which the IP address 76.108.90.57/23 resides?
 ```c
 76.108.90.0-76.108.91.254
 76.108.90.1-76.108.92.0
 76.108.89.253-76.108.91.254
 76.108.90.1-76.108.91.254 << pick
 76.108.90.1-76.108.91.249
 76.108.90.5-76.108.92.0
 ```
 ## 6. What is the Network address of a host with an IP address of 95.5.115.148/20?
 ```c
 95.5.112.0 << pick
 95.5.115.144
 80.0.0.0
 94.0.0.0
 95.0.0.0
 88.0.0.0
 92.0.0.0
 ```