# Confused

## 1. Which of the following is the valid host range for the subnet on which the IP address 150.44.83.104/19 resides?
     150.44.64.3-150.44.96.0
     150.44.64.5-150.44.96.1
     150.44.64.1-150.44.95.254 << pick
     150.44.64.5-150.44.95.254
     150.44.64.0-150.44.95.254
     150.44.64.3-150.44.96.3

## 2. Which of the following is the valid host range for the subnet on which the IP address 161.131.211.166/28 resides?
     161.131.211.160-161.131.211.171
     161.131.211.161-161.131.211.173
     161.131.211.156-161.131.211.169
     161.131.211.161-161.131.211.174 << pick
     161.131.211.159-161.131.211.171
     161.131.211.164-161.131.211.174

- **subnet 범위 구하기**
    - **최소**: 전체(32) - subnetmask로 왼쪽부터 1로 채운 2진수 값 && subnetmask가 걸치는 값
    - **최대**: 1110을 10진수로 변환한 값 - subnetmask가 걸치는 값