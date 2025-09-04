from collections import deque

def f(n):
    if n == 1:
        return 1
    if n == 2:
        return 2
    
    # 初始化队列和访问集合
    queue = deque()
    visited = set()
    
    # 起始状态：数字 "1" 和 "2"
    r1 = 1 % n
    queue.append(("1", r1))
    visited.add(r1)
    
    r2 = 2 % n
    if r2 not in visited:  # 避免重复（如 n=1 时 r1=r2）
        queue.append(("2", r2))
        visited.add(r2)
    
    while queue:
        s, r = queue.popleft()
        if r == 0:
            return int(s)  # 找到解
        
        # 尝试添加新位：0,1,2
        for d in ['0', '1', '2']:
            new_s = s + d
            new_r = (r * 10 + int(d)) % n
            
            if new_r not in visited:
                visited.add(new_r)
                queue.append((new_s, new_r))
    
    return -1  # 理论不会执行（解必存在）

print(sum([f(n) / n for n in range(1, 101)]))
print(sum([f(n) / n for n in range(1, 10001)]))
