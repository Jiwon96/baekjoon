from collections import defaultdict

def check():
    if ans_dict['A'] <= dict['A'] and ans_dict['C'] <= dict['C'] \
        and ans_dict['G'] <= dict['G'] and ans_dict['T'] <=dict['T']:
        return True
    return False

S, P = map(int, input().split())
str = input()

dict = defaultdict(int)
ans_dict = defaultdict(int)

ans_dict['A'], ans_dict['C'], ans_dict['G'], ans_dict['T'] = map(int, input().split())

ans=0
for i in range(P):
    dict[str[i]]+=1
if check():
    ans+=1

for i in range(S-P):
    dict[str[i]]-=1
    dict[str[i+P]]+=1
    if check():
        ans+=1
print(ans)